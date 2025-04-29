#include <stdio.h>

int n, m, ans;
int grid[101][101];

int main(){
    scanf("%d %d", &n, &m);

    if (m==1) {printf("%d", n*2); return 0;}
    for (int i = 0; i < n; i++){
        int j;
        for (j=0; j < n; j++){
            scanf("%d", &grid[i][j]);
        }

        // int sameCount=0;
        // for (; j < n; j++){
        //     scanf("%d", &grid[i][j]);
        //     while ((grid[i][j-1] != grid[i][j]) ||
        //             ( j-1 >0) ||
        //             (sameCount <m)) {
        //                 sameCount++;
        //             }
        //     if (sameCount>=m){
        //         ans++;
        //         while(getchar()!='\n');
        //         continue;
        //     }
        // }
    }


    for (int i = 0;  i< n; i++){
        int sameCount=1, j=0;
        for (int j=0; j<n-1; j++) {
            // while (n-j>=m)
            if (grid[i][j]==grid[i][j+1]) sameCount++;
            else sameCount=1;
        }
        if (sameCount>=m) ans++;
    }

    for (int j = 0;  j< n; j++){
        int sameCount=1, i=0;
        for (int i=0;i <n-1; i++) {
            // while (n-j>=m)
            if (grid[i][j]==grid[i+1][j]) sameCount++;
            else sameCount=1;
        }
        if (sameCount>=m) ans++;
    }


    // Please write your code here.
    printf("%d", ans);
    return 0;
}