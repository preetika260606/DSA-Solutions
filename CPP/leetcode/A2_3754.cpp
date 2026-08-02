#include<iostream>
#include<string>
using namespace std;
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        int len=s.length();
        long long sum=0;
        long long nonZero=0;
        for(int i=0;i<len;i++){
            if(s[i]!='0'){
                nonZero=nonZero*10+(s[i]-'0');
                sum+=s[i]-'0';
            }

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