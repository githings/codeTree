import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        // Please write your code here.
        int ans = 0;
        int s = 3;
        for (int i=0; i<n-s+1; i++) {
            for (int j=0; j<n-s+1; j++) {
                int local = 0;
                for (int a=i; a<i+s; a++) {
                    for (int b=j; b<j+s; b++) {
                        local += grid[a][b];
                    }
                }
                ans = Math.max(local, ans);
            }
        } 

        System.out.println(ans);
    }
}