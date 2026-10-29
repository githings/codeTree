import java.util.Scanner;
import java.util.*;

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
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int centerR = i;
                int centerC = j;
                // System.out.println(i+"센터"+j);

                for (int k = 0; k < 2*n; k++) {
                    // System.out.println(k);
                    int gold = 0;
                    for (int r = 0; r < n; r++) {
                        for (int c= 0; c < n; c++) {
                            int rDist = Math.abs(centerR - r);
                            int cDist = Math.abs(centerC - c);
                            int dist = rDist + cDist;
                            if (dist <= k && grid[r][c]==1) gold++;
                        }
                    }
                    int cost = k*k + (k+1)*(k+1);
                    // System.out.println("케이"+k + " " + gold + " "+ cost);
                    int gain = gold *m;
                    if (cost <= gain) answer = Math.max(answer, gold);
                }

            }
        }


        System.out.println(answer);


    }
}