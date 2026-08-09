#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

//tle tc:O(n^2) sc:O(1)
bool validPalindrome(string s,string t){

    if(s.length()!=t.length()) return false;

    for(int i=0;i<s.length();i++){
        bool valid=false;

        for(int j=0;j<s.length();j++){
            if(i==j) continue;

            if(s[j]!=t[j]){
                valid=false;
                t[j]='#';
                break;
            }

            if(!valid) return false;
        }
    }
    return true;
}
int main(){
    string s="cat";
    string t="atc";

    if(validPalindrome(s,t)){
        cout<<"true";
    }else{
        cout<<"false";
    }

}

//method 2->

    //tc":O(nlogn) sc:O(1)
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t) return true;

        return false;
    }


//method 3->

//tc:(n) ,sc:o(k)
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,int>res;

        for(char ch:s){
            res[ch]++;
        }
        for(char ch:t){
            res[ch]--;
        }

        for(auto it:res){
            if((it.second)!=0) 
            return false;
        }
        return true;
    }
