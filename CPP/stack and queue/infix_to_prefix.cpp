#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

    int precedence(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPrefix(string &s) {

        // Step 1: Reverse the infix expression
        reverse(s.begin(), s.end());

        // Step 2: Swap '(' and ')'
        for (char &ch : s) {
            if (ch == '(')
                ch = ')';
            else if (ch == ')')
                ch = '(';
        }

        stack<char> st;
        string postfix = "";

        // Step 3: Convert reversed infix to postfix
        for (char ch : s) {

            if (isalnum(ch)) {
                postfix += ch;
            }
            else if (ch == '(') {
                st.push(ch);
            }
            else if (ch == ')') {

                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }

                if (!st.empty())
                    st.pop();
            }
            else {

                while (!st.empty() && st.top() != '(' &&
                       (precedence(st.top()) > precedence(ch) ||
                        (precedence(st.top()) == precedence(ch) && ch == '^'))) {

                    postfix += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix to get prefix
        reverse(postfix.begin(), postfix.end());

        return postfix;
    }

    
int main (){

    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string prefix = infixToPrefix(infix);
    cout << prefix << endl;
    return 0;

}