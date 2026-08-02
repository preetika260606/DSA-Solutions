#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string>st;
        
        for(int i=pre_exp.length()-1;i>=0;i--){
            
            if(isalnum(pre_exp[i])){
                st.push(string(1,pre_exp[i]));
            }
            
            else {
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string infix="("+t1+pre_exp[i]+t2+")";
                
                st.push(infix);
            }
            
        }
        return st.top();
    }

int main(){

    string pre_exp;
    cin >> pre_exp;

    string result = preToInfix(pre_exp);
    cout << result << endl;

    return 0;
}
