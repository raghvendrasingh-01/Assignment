#include <stdio.h>

// Simple recursive function: P(N) = Σ(k=1 to N-1)[P(k) * P(N-k)]
int P(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int result = 0;
    
    // Summation from k=1 to N-1
    for (int k = 1; k <= n - 1; k++) {
        result += P(k) * P(n - k);
    }
    
    return result;
}

int main() {
    int n;
    
    printf("Enter value of N: ");
    scanf("%d", &n);
    
    printf("\nP(%d) = %d\n", n, P(n));
    return 0;
}