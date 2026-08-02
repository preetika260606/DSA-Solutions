#include<iostream>
#include<stack>
using namespace std;
class MinStack {
    public:
    
    stack<pair<int,int>>st;

    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
        st.push({value,value});
        }

        else{
            st.push({value,min(value,st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {

    MinStack minStack;

    minStack.push(5);
    minStack.push(2);
    minStack.push(8);

    cout << "Minimum = " << minStack.getMin() << endl;

    minStack.pop();

    cout << "Minimum = " << minStack.getMin() << endl;

    cout << "Top = " << minStack.top() << endl;

    return 0;
}


//TC: O(1) for all operations (push, pop, top, getMin)
//SC: O(2n) for the stack

