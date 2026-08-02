import java.util.Scanner;

public class Recursion {
    public static int rec(String s,int n,int index){
        if (index == n) {
            return 1;
        }

        if (s.charAt(index) == '0') {
            return 0;
        }

        int oneDigit = rec(s, n, index + 1);

        int twoDigit = 0;

        if (index + 1 < n) {
            if (s.charAt(index) == '1' ||
                (s.charAt(index) == '2' && s.charAt(index + 1) <= '6')) {

                twoDigit = rec(s, n, index + 2);
            }
        }

        return oneDigit + twoDigit;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the string: ");
        String s = sc.next();

        int ans = rec(s, s.length(), 0);

        System.out.println("Number of Decodings = " + ans);

        sc.close();
    }
}
