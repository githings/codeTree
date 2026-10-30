import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        // Please write your code here.
    int maxSum = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < n; j++) {
            
            for (int a = 1; a < n; a++) {
                for (int b = 1; b < n; b++) {
                    int val = grid[i][j];
                    // 좌측 침범
                    if (0>i-a || j+a >= n) continue;
                    // 상측
                    if (0>i-a-b || j+a-b < 0) continue;
                    // 우측
                    if (0>i-b || j-b < 0 ) continue;

                    int nr = i;
                    int nc = j;
                    for (int k=0; k<a; k++) {
                        nr--;
                        nc++;
                        val += grid[nr][nc];
                    }

                    for (int k=0; k<b; k++) {
                        nr--;
                        nc--;
                        val += grid[nr][nc];
                    }

                    for (int k=0; k<a; k++) {
                        nr++;
                        nc--;
                        val += grid[nr][nc];
                    }

                    
                    for (int k=0; k<b; k++) {
                        nr++;
                        nc++;
                        val += grid[nr][nc];
                    }

                    maxSum = Math.max(maxSum, val-grid[i][j]);
                }
            }



        }
    }

    System.out.println(maxSum);
    }
    
}