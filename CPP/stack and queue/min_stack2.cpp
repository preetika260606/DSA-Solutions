#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if (st.top() >= mini) {
            st.pop();
        } else {
            mini = 2LL * mini - st.top();
            st.pop();
        }
    }

    int top() {
        if (st.top() >= mini)
            return (int)st.top();

        return (int)mini;
    }

    int getMin() {
        return (int)mini;
    }
};

int main() {
    MinStack ms;

    ms.push(-2);
    ms.push(0);
    ms.push(-3);

    cout << "Minimum: " << ms.getMin() << endl; // -3

    ms.pop();

    cout << "Top: " << ms.top() << endl;        // 0
    cout << "Minimum: " << ms.getMin() << endl; // -2

    return 0;
}