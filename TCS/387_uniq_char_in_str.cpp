//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int uniqueString(string s){
    unordered_map<char,int>res;

    for(char i:s){
        res[i]++;
    }
    for(int i=0;i<s.length();i++){
        if(res[s[i]]==1){
            return i;
        }
    }
    return -1;
}
int main(){
    string s;
    cin>>s;
    cout<<uniqueString(s);
}