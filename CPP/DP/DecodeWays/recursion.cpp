#include<iostream>
#include<vector>
using namespace std;

///Time: O(2ⁿ)
//Space: O(n) (recursion stack)
    int rec(string &s,int n,int index){
        if(index==n){
            return 1; //one valid split done
        }

        if(s[index]=='0'){
            return 0; //not possible to split
        }

        int only1_char=rec(s,n,index+1);
        int ith_i1_char=0;

        if(index+1<n){
        if(s[index] == '1' || (s[index] == '2' &&s[index+1] <='6') )
        ith_i1_char=rec(s,n,index+2);
        }

        return only1_char + ith_i1_char;
    }
    int numDecodings(string s) {
        int n=s.length();
        return rec(s,n,0);
    }

    int main(){
        string s;
        cin>>s;
        cout<<numDecodings(s);
        return 0;
    }