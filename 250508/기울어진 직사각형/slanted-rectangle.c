#include <stdio.h>

int n;
int grid[21][21];

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);
    
    // Please write your code here.
    int global_sum=0, a_sum=0, b_sum=0,c_sum=0,d_sum=0;
    int x=0,y=0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            for (int a=1; a<n; a++) {
                if (a<0 || a>=n) break;
                a_sum+=grid[++y][--x];

                for (int b=1;b<n;b++) {
                    if (b<0 || b>=n) break;
                    b_sum+=grid[++y][++x];

                    for (int c=1;b<n;b++) {
                        if (c<0 || c>=n) break;
                        int x_diff = (x-j)
                        if (y-i == x_diff ) break;
                        c_sum+=grid[--y][++x];

                        for (int d=1;b<n;b++) { 
                            if (d<0 || d>=n) break;
                            if (x==j && y==i) {
                                if (a_sum + b_sum +c_sum + d_sum > global_sum) global_sum = a_sum + b_sum +c_sum + d_sum;
                                break;
                            }
                            d_sum+=grid[--y][--x];

                        }
                    }
                }
            }

        }
    }
    
    return 0;
}