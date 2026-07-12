#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

    string postToPre(string s) {
        // code here
        stack<string>st;
        
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                st.push(string(1,s[i]));
            }
            
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string prefix=s[i]+t2+t1;
                
                st.push(prefix);
            }
        }
        return st.top();
    }
int main(){
    string s;
    cin>>s;

    string result=postToPre(s);
    cout<<result<<endl;

    return 0;

}