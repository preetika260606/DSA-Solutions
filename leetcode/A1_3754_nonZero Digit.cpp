#include<iostream>
using namespace std;


long long sumAndMultiply(int n) {
        long long sum = 0;
        long long rev = 0;

        if (n == 0)
            return 0;
        
        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                sum += digit;
                rev = rev * 10 + digit;
            }
            n /= 10;
        }
        long long nonZero = 0;
        while (rev > 0) {
            nonZero = nonZero * 10 + (rev % 10);
            rev /= 10;
        }
        return nonZero * sum;
    }

int main(){
    
    int n;
    cin >> n;

    long long result = sumAndMultiply(n);
    cout << result << endl;

    return 0;
}