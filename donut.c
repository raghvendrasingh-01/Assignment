#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main() {
    float A = 0, B = 0;  // Rotation angles
    float i, j;
    int k;
    float z[1760];  // Z-buffer for depth
    char b[1760];   // Character buffer for display
    
    printf("\x1b[2J");  // Clear screen
    
    for(;;) {  // Infinite loop for animation
        memset(b, 32, 1760);  // Fill buffer with spaces (ASCII 32)
        memset(z, 0, 7040);   // Clear Z-buffer (1760 * 4 bytes)
        
        // Loop through donut surface points
        for(j = 0; j < 6.28; j += 0.07) {  // Theta: 0 to 2π (circle around tube)
            for(i = 0; i < 6.28; i += 0.02) {  // Phi: 0 to 2π (circle of tube)
                
                // Pre-calculate sine and cosine values
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;  // R2 + R1*cos(theta)
                float D = 1 / (c * h * e + f * g + 5);  // Depth (reciprocal of Z)
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;  // Intermediate calculation
                
                // Project 3D coordinates to 2D screen coordinates
                int x = 40 + 30 * D * (l * h * m - t * n);  // X position (0-80)
                int y = 12 + 15 * D * (l * h * n + t * m);  // Y position (0-22)
                int o = x + 80 * y;  // Buffer index (flattened 2D array)
                
                // Calculate luminance (which character to display)
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                
                // Only draw if point is in front and closer than previous
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;  // Update Z-buffer
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];  // Choose character based on luminance
                }
            }
        }
        
        // Display the frame
        printf("\x1b[H");  // Move cursor to home position
        for(k = 0; k < 1760; k++) {
            putchar(k % 80 ? b[k] : 10);  // Print character or newline every 80 chars
        }
        
        // Increment rotation angles
        A += 0.04;
        B += 0.02;
        
        usleep(30000);  // 30ms delay (33 FPS)
    }
    
    return 0;
}
