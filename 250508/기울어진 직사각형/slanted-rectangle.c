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

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //         printf("%d ", &grid[i][j]);
    //     printf("\n");
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x=j, y=i;

            int ax=x, ay=y;
            for (int a=1; a<n; a++) {
                // printf("%d %d %d.. %d %d\n", i,j, a, ay,ax);
                if (x-a<0 || y+a>=n) break;
                
                a_sum+=grid[++ay][--ax];
                // printf("a[%d][%d] %d [%d, %d]==%d\n",i,j, a_sum,  ay,ax, grid[ay][ax] );

                int bx=ax, by=ay;
                for (int b=1;b<n;b++) {
                    if (ax+b>=n || ay+b>=n) break;
                    b_sum+=grid[++by][++bx];
                    // printf("b[%d][%d] %d [%d, %d]==%d\n",i,j, b_sum,  by,bx, grid[by][bx] );

                    int cx=bx, cy=by;
                    for (int c=1;c<n;c++) {
                        if (bx+c>=n || by-c<0) break;
                        c_sum+=grid[--cy][++cx];
                        // printf("[%d %d] %d %d %d ___ %d %d %d %d\n", i,j, a,b,c, x,y, x-j, y-i);

                        if (y-i == x-j ) {
                            //  printf("!![%d %d] %d %d %d\n", i,j, a,b,c);
                            
                            int dx=cx, dy=cy;
                            for (int d=1;d<n;d++) { 
                                if (cx-d<0 || cy-d<0) break;
                                d_sum+=grid[--dy][--dx];
                                if (dx==j && dy==i) {
                                    if (a_sum + b_sum +c_sum + d_sum > global_sum) {
                                        global_sum = a_sum + b_sum +c_sum + d_sum;
                                        // printf("%d %d :  %d %d %d %d == %d(%d %d %d %d)\n", i,j,a,b,c,d, global_sum, a_sum, b_sum, c_sum, d_sum);
                                        }
                                    break;
                                }
                            }
                            d_sum=0;
                            // x=cx; y=cy;
                        }

                    }
                    c_sum=0;
                    // x=bx; y=by;
                }
                b_sum=0;
                // x=ax; y=ay;
            }
            a_sum=0;
        }
    }


    printf("%d", global_sum);
    
    return 0;
}