import java.util.Scanner;
import java.util.*;

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
        int answer = Integer.MIN_VALUE;
        int max1 = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;
        List<int[]> rects = new LinkedList<>();

        for (int h = 1; h <= n; h++) {
            for (int w = 1; w <= m; w++) {
                for (int i = 0; i + w <= m; i++) {
                    for (int j = 0; j + h <= n; j++) {

                        rects.add(new int[] {i, j, i+w-1, j+h-1});
                        // int local = 0;
                        // for (int a=i; a<i+w; a++) {
                        //     for (int b=j; b<j+h; b++) {
                        //         local += grid[b][a];
                        //     }
                        // }

                        
                        // int small = Math.min(max1, max2);
                        // System.out.println(w +"_"+ h +"_"+ i +"_"+ j +"_"+ local);
                        // if (small >= local) continue;

                        // if (max1 < local) {
                        //     max1 = local;
                        // }
                        // else if (max2 < local) {
                        //     max2 = local;
                        // }
                    }
                }
            }
        }

        // 
        for (int[] a : rects) {
            for (int[] b: rects) {
                boolean disjoint =
                    a[3] < b[1] ||  // A가 B보다 위
                    b[3] < a[1] ||  // B가 A보다 위
                    a[2] < b[0] ||  // A가 B보다 왼쪽
                    b[2] < a[0];    // B가 A보다 왼쪽
                if (!disjoint) continue;

                int total = sum(grid, a) + sum(grid, b);
            answer = Math.max(answer, total);
            }
        }

        System.out.println(answer);

    }

    static int sum(int[][] grid, int[] r) {
    int result = 0;

    for (int row = r[1]; row <= r[3]; row++) {
        for (int col = r[0]; col <= r[2]; col++) {
            result += grid[row][col];
        }
    }

    return result;
}
}