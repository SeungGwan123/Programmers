import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

    private static final int END_TIME = 22 * 60;

    public int solution(int n, int m, int[][] timetable) {

        int customerCount = getMaxCustomerCount(timetable);
        if (customerCount <= 1) {
            return 0;
        }

        for (int dist = 2 * (n - 1); dist > 0; dist --) {
            for (int y = 0; y < n; y ++) {
                List<Rocker> rockers = findOtherRockers(y, n, dist);
                if (rockers.size() >= customerCount) {
                    return dist;
                }
            }
        }

        return 0;
    }

    private List<Rocker> findOtherRockers(int y, int n, int dist) {
        List<Rocker> rockers = new ArrayList<>();
        rockers.add(new Rocker(0, y));

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 && j <= y) {
                    continue;
                }
                if (isTargetDiffRocker(dist, rockers, i, j)) {
                    rockers.add(new Rocker(i, j));
                }
            }
        }

        return rockers;
    }

    private boolean isTargetDiffRocker(int dist, List<Rocker> rockers, int i, int j) {
        for (Rocker rocker : rockers) {
            if (getDiff(rocker, i, j) < dist) {
                return false;
            }
        }
        return true;
    }

    private int getDiff(Rocker rocker, int i, int j) {
        return Math.abs(rocker.x - i) + Math.abs(rocker.y - j);
    }

    private int getMaxCustomerCount(int[][] timetable) {
        int[] dp = new int[END_TIME + 1];

        for (int[] time : timetable) {
            dp[time[0]] ++;
            dp[time[1] + 1] --;
        }

        for (int i = 1; i <= END_TIME; i ++) {
            dp[i] += dp[i - 1];
        }

        return Arrays.stream(dp)
                .max()
                .orElse(0);
    }

    private static class Rocker {
        int x;
        int y;

        Rocker(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}