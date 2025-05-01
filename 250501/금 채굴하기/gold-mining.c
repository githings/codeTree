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
            for (int s=0; s<n; s++) {
                int x=j, y=i-s;
                //first plane
                // while(0<=y && y<n && 0<=x && x<n) { y+=1; x+=1;}
                while(y!=i) {
                    if (!(0<=y && y<n && 0<=x && x<n)) {
                        y += 1;
                        x += 1;
                        continue;
                    }
                    y += 1;
                    x += 1;
                    step_sum += g[y][x];
                }
                //second plane
                x=j+s, y=i;
                // while(0<=y && y<n && 0<=x && x<n) { y+=1; x-=1;}
                while(y!=i) {
                    if (!(0<=y && y<n && 0<=x && x<n)) {
                        y += 1;
                        x -= 1;
                        continue;
                    }
                    y += 1;
                    x -= 1;
                    step_sum += g[y][x];
                }
                //third plane
                x=j, y=i+s;
                // while(0<=y && y<n && 0<=x && x<n) { y-=1; x-=1;}
                while(y!=i) {
                    if (!(0<=y && y<n && 0<=x && x<n)) {
                        y -= 1;
                        x -= 1;
                        continue;
                    }
                    y -= 1;
                    x -= 1;
                    step_sum += g[y][x];
                }
                //forth plane
                x=j-s, y=i;
                // while(0<=y && y<n && 0<=x && x<n) { y-=1; x+=1;}
                while(y!=i) {
                    if (!(0<=y && y<n && 0<=x && x<n)) {
                        y -= 1;
                        x += 1;
                        continue;
                    }
                    y -= 1;
                    x += 1;
                    step_sum += g[y][x];
                }
                int cost = s*s + (s+1)*(s+1);
                // 이득이라면 
                // printf("[%d][%d]%d=%d\n", i,j,s,step_sum);
                if ((step_sum*m - cost>=0) && global_sum<step_sum) global_sum = step_sum;
                // if (global_sum<step_sum) global_sum = step_sum;
            }
        }
    }

    printf("%d", global_sum);


    
    return 0;
}