#include <stdio.h>

int n, m, ans;
int grid[100][100];

int main(){
    scanf("%d %d", &n, &m);

    // if (m==1) {printf("%d", n*2); return 0;}
    for (int i = 0; i < n; i++){
        for (int j=0; j < n; j++){
            scanf("%d", &grid[i][j]);
        }
    }


    // for (int i = 0;  i< n; i++){
    //     int sameCount=1;
    //     for (int j=0; j<n-1; j++) {
    //         if (grid[i][j]==grid[i][j+1]) sameCount++;
    //         else if (sameCount>=m) {
    //             break;
    //         }
    //         else sameCount=1;
    //     }
    //     if (sameCount>=m) ans++;
    // }

    // for (int i = 0;  i< n; i++){
    //     int sameCount=1;
    //     for (int j=0; j<n-1; j++) {
    //         if (grid[j][i]==grid[j+1][i]) sameCount++;
    //         else if (sameCount>=m) {
    //             break;
    //         }
    //         else sameCount=1;
    //     }
    //     if (sameCount>=m) ans++;
    // }

     for (int i = 0;  i< n; i++){
        int sameCountRow=1, sameCountColumn=1, rowFlag=0, colFlag=0;
        for (int j=0; j<n-1; j++) {
            if (sameCountRow>=m) rowFlag=1;
            else if (grid[i][j]==grid[i][j+1]) {
                sameCountRow++;
            }
            else sameCountRow=1;

            if (sameCountColumn>=m) colFlag=1;
            else if (grid[j][i]==grid[j+1][i]) {
                sameCountColumn++;
            }
            else sameCountColumn=1;

            if (rowFlag && colFlag) break;
        }
        if (sameCountRow>=m) ans++;
        if (sameCountColumn>=m) ans++;
    }


    // Please write your code here.
    printf("%d", ans);
    return 0;
}