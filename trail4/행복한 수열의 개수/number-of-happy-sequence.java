import java.util.Scanner;
  
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        
        // Please write your code here.
        int ans = 0;

        // 가로
        for (int i = 0; i < n; i++) {
            int cur = grid[i][0];
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                while (j < n && cur==grid[i][j]) {cnt++; j++;}
                // System.out.println(i+"_"+j+"__"+(cnt >= m));
                if (cnt >= m) {ans++; break; }
                if (j < n) cur = grid[i][j];
                cnt=1;
            }
        }

        for (int j = 0; j < n; j++) {
            int cur = grid[0][j];
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                while (i < n && cur==grid[i][j]) {cnt++; i++;}
                if (cnt >= m) {ans++; break;}
                // System.out.println(i+"__"+j);
                if (i < n) cur = grid[i][j];
                cnt=1;
            }
        }


        System.out.println(ans);
    }
}