#include <stdio.h>

int grid[20][20];
int n,m;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    // Please write your code here.


    for (int i=0;i<=n-3;i++) {
        for (int j=0;j<=n-3;j++) {
            int s=0;
            for (int k=i; k<i+3; k++) {
                for (int l=j; l<j+3; l++){
                    s+=grid[k][l];
                    // printf("%d#", grid[k][l]);
                }
            }
            if (s>m) m=s;
        }
    }

    //         s += grid
    //         grid[i][j] +
    //         grid[i][j+1] +
    //         grid[i][j+2] +

    //         grid[i+1][j] +
    //         grid[i+1][j+1] +
    //         grid[i+1][j+2] +

    //         grid[i+2][j] +
    //         grid[i+2][j+1] +
    //         grid[i+2][j+2] +
    //     }
    // }


    // for (;i<n-3;i++) {
    //     for (;j<n-3;j++) {
    //         for (int k=i; k<i+3; k++) {
    //             for (int l=j)
    //         }
    //     }
    // }


    
    // Please write your code here.
    printf("%d", m);    
    
    return 0;
}