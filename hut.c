#include <stdio.h>

void roof()
{
    int roof_height = 5;
    int base_width = 33;
    
    for (int i = 1; i <= roof_height; i++) {
        // Left padding
        for (int j = 1; j <=roof_height - i; j++) {
            printf(" ");
        }
        
        printf("*");
        
        // Middle content
        int middle = base_width + (2 * i);
        for (int j = 1; j <= middle; j++) {
            printf(i == 1 || i == roof_height ? "*" : " ");
        }
        
        printf("*");
        printf("\n");
    }
    
}
void body() {
     int height = 9;
    int width = 33;
    
    // Draw the hut body
    for (int i = 1; i <= height; i++) {
        for (int k = 0; k < 6; k++) {
            printf(" ");
        }
        for (int j = 1; j <= width; j++) {
            // Left and right walls
            if (j == 1 || j == width) {
                printf("*");
            }
            // Bottom floor
            else if (i == height ) {
                printf("*");
            }
            // Left window (rows 2-5, columns 7-10)
            else if (i > 1 && i <= 5 && j > 6 && j <= 10) {
                printf("*");
            }
            // Right window (rows 2-5, columns 24-28)
            else if (i > 1 && i <= 5 && j > 24 && j <= 28) {
                printf("*");
            }
            // Door top (row 2, columns 13-21)
            else if (i == 3 && j > 12 && j <= 21) {
                printf("*");  // Top of door frame
            }
            // Door sides (rows 4-8, columns 13 and 21)
            else if (i > 3 && i < height  && j > 12 && j <= 21) {
                if (j == 13 || j == 21) {
                    printf("*");  // Door frame sides
                } else {
                    printf(" ");  // Door opening
                }
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
}
int main(void) {
    roof();
    body();
    return 0;
}
