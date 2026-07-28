#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//tc:O(n log n)
    string smallestPalindrome(string s) {
        int n=s.length();

         int mid=n/2;

        sort(begin(s),begin(s)+mid);

        for(int i=0;i<mid;i++){
            s[n-i-1]=s[i];
        }
        return s;
    }
int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;
    cout<<smallestPalindrome(s);

    return 0;
}