#include <stdio.h>

int grid[20][20];
int n,k;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
            k=grid[i][j];
        }
    }
    
    // Please write your code here.
    printf("%d", k);    
    return 0;
}