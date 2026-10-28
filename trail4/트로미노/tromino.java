import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        // Please write your code here.
        int answer = 0;
        
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < m-1; j++) {
                // int total = 0;
                int sum1 = grid[i][j] + grid[i+1][j] + grid[i][j+1];
                int sum2 = grid[i][j] + grid[i+1][j] + grid[i+1][j+1];
                int sum3 = grid[i][j] + grid[i][j+1] + grid[i+1][j+1];
                int sum4 = grid[i+1][j] + grid[i][j+1] + grid[i+1][j+1];
                answer = Math.max(answer, sum1);
                answer = Math.max(answer, sum2);
                answer = Math.max(answer, sum3);
                answer = Math.max(answer, sum4);

                // System.out.println(answer + " " + i +" "+ j);
            }
        }

        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < m-2; j++) {
                int sum1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                int sum2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                int sum3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

                int sum4 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                int sum5 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                int sum6 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

                // System.out.println(answer + "_ " + i +" "+ j);
                answer = Math.max(answer, sum1);
                answer = Math.max(answer, sum2);
                answer = Math.max(answer, sum3);
                answer = Math.max(answer, sum4);
                answer = Math.max(answer, sum5);
                answer = Math.max(answer, sum6);
            }
        }


        System.out.println(answer);
    }
}