#include <stdio.h>  
#define MAX_SIZE 210

int n, m;
int g[MAX_SIZE][MAX_SIZE];
int globalSum;
int localSum;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    
    // // Please write your code here.

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //수평선 하나 
            if (j+2<=m) localSum = g[i][j] + g[i][j+1] + g[i][j+2];
            if (globalSum<localSum) globalSum = localSum;
            //수직선 하나
            if (i+2<=n) localSum = g[i][j] + g[i+1][j] + g[i+2][j];
            if (globalSum<localSum) globalSum = localSum;
            
            // 기본 방향
            if (i>=1 && j+1<=m) localSum = g[i][j] + g[i-1][j] + g[i][j+1];
            if (globalSum<localSum) globalSum = localSum;
            // 90도
            if (i+1<=n && j+1<=m) localSum = g[i][j] + g[i][j+1] + g[i+1][j];
            if (globalSum<localSum) globalSum = localSum;
            //180도
            if (i+1<=n && j>=1) localSum = g[i][j] + g[i][j-1] + g[i+1][j];
            if (globalSum<localSum) globalSum = localSum;
            //270도
            if (i>=1 && j>=1) localSum = g[i][j] + g[i][j-1] + g[i-1][j];
            if (globalSum<localSum) globalSum = localSum;
        }
    }

    printf("%d", globalSum);
    
    
    return 0;
}