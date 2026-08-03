import java.util.Arrays;
import java.util.Scanner;

public class Memoization {

    public static int solve(int amount, int[] coins, int i, int[][] dp) {

        if (amount == 0)
            return 1;

        if (i == coins.length)
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = 0;
        if (coins[i] <= amount) {
            take = solve(amount - coins[i], coins, i, dp);
        }

        int notTake = solve(amount, coins, i + 1, dp);

        return dp[i][amount] = take + notTake;
    }

    public static int change(int amount, int[] coins) {

        int n = coins.length;

        int[][] dp = new int[n][amount + 1];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(amount, coins, 0, dp);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of coins: ");
        int n = sc.nextInt();

        int[] coins = new int[n];

        System.out.print("Enter the coins: ");
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        System.out.print("Enter amount: ");
        int amount = sc.nextInt();

        System.out.println("Number of ways = " + change(amount, coins));

        sc.close();
    }
}