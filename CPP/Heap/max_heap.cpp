#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    vector<int>arr;

    public:
    void insert(int x){
        arr.push_back(x);   //insert at end
        int i=arr.size()-1;   //bubble up (heapify)

        while(i!=0 && arr[i]>arr[(i-1)/2]){
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
    }

    void print(){
        for(int x:arr) 
        cout<<x<<" ";
        cout<<endl;
    }
};

int main(){
        MaxHeap b;
        b.insert(10);
        b.insert(5);
        b.insert(20);
        b.insert(2);
        b.print();
        
}