#include<iostream>
#include<stack>
using namespace std;


    int precedence(char ch) {
        if (ch == '^')
            return 3;
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If operand
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9')) {
                ans += ch;
            }

            // If '('
            else if (ch == '(') {
                st.push(ch);
            }

            // If ')'
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Remove '('
            }

            // If operator
            else {
                while (!st.empty() && st.top() != '(' &&
                       (precedence(st.top()) > precedence(ch) ||
                       (precedence(st.top()) == precedence(ch) && ch != '^'))) {
                    ans += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
    return 0;
}
