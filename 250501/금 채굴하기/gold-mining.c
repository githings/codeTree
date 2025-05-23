#include <stdio.h>

// 사이즈, 금가격
int n, m;
int g[20][20];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    
    // Please write your code here.
    int global_sum=0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int step_sum=0;
            step_sum += g[i][j];
            for (int s=0; s<=n; s++) {
                int x=j, y=i-s;
                //first plane
                while(y!=i) {
                    y += 1;
                    x += 1;
                    if (!(0<=y && y<n && 0<=x && x<n)) continue;
                    step_sum += g[y][x];
                }
                //second plane
                while(x!=j) {
                    y += 1;
                    x -= 1;
                    if (!(0<=y && y<n && 0<=x && x<n)) continue;
                    step_sum += g[y][x];
                }
                //third plane
                while(y!=i) {
                    y -= 1;
                    x -= 1;
                    if (!(0<=y && y<n && 0<=x && x<n)) continue;
                    step_sum += g[y][x];
                }
                //forth plane
                while(x!=j) {
                    y -= 1;
                    x += 1;
                    if (!(0<=y && y<n && 0<=x && x<n)) continue;
                    step_sum += g[y][x];
                }
                // int cost = s*s + (s+1)*(s+1);
                // 이득이라면 
                // printf("[%d][%d]%d=%d\n", i,j,s,step_sum);
                if ((step_sum*m - (s*s + (s+1)*(s+1))>=0) && global_sum<step_sum) global_sum = step_sum;
            }
        }
    }

    printf("%d", global_sum);


    
    return 0;
}