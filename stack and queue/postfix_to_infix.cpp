#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

    string postToInfix(string &exp) {

        stack<string> st;

        for (int i = 0; i < exp.length(); i++) {

            if (isalnum(exp[i])) {
                st.push(string(1, exp[i]));
            }
            else {

                string t1 = st.top();
                st.pop();

                string t2 = st.top();
                st.pop();

                string infix = "(" + t2 + exp[i] + t1 + ")";

                st.push(infix);
            }
        }

        return st.top();
    }

int main(){
    
    string exp;
    cin >> exp;

    string result = postToInfix(exp);
    cout << result << endl;

    return 0;

}