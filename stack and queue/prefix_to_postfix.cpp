#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

    string preToPost(string &s) {

        stack<string> st;

        for (int i = s.length() - 1; i >= 0; i--) {

            if (isalnum(s[i])) {
                st.push(string(1, s[i]));
            }
            else {

                string op1 = st.top();
                st.pop();

                string op2 = st.top();
                st.pop();

                string postfix = op1 + op2 + s[i];

                st.push(postfix);
            }
        }

        return st.top();
    }

int main(){
    string s;
    cin>>s;

    string res=preToPost(s);
    cout<<res<<endl;
    return 0;
    
}