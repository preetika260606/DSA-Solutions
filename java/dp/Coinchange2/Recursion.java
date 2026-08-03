// package java.dp.Coinchange2;
import java.util.Scanner;
import java.util.Arrays;

public class Recursion {
    
   public static int rec(int amount, int[] coins, int i) {

    if (amount == 0)
        return 1;

    if (i == coins.length)
        return 0;

    int take = 0;

    if (coins[i] <= amount) {
        take = rec(amount - coins[i], coins, i);
    }

    int not_take = rec(amount, coins, i + 1);

    return take + not_take;
}

    public static int change(int amount,int[]coins){

        int n=coins.length;

        return rec(amount,coins,0);
    }

    public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    System.out.print("Enter number of Coins: ");
    int n = sc.nextInt();

    int[] coins = new int[n];

    System.out.print("Enter the Coins: ");
    for (int i = 0; i < n; i++) {
        coins[i] = sc.nextInt();
    }

    System.out.print("Enter Amount: ");
    int amount = sc.nextInt();

    System.out.println("The number of ways are " + change(amount, coins));

    sc.close();
}
}
