//using max heap

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
    void deleteRoot() {
    if (arr.size() == 0) {
        cout << "nothing is printed\n";
        return;
    }

    // replace root with last
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();    // delete last

    int n = arr.size();   // heapify root 
    int i = 0;            // heapify root

    while (true) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < n && arr[leftChild] > arr[largest])
            largest = leftChild;

        if (rightChild < n && arr[rightChild] > arr[largest])
            largest = rightChild;

        if (largest == i)
            break;

        swap(arr[i], arr[largest]);
        i = largest;
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
        b.insert(30);
        b.insert(25);
        b.print();

        b.deleteRoot();
        b.print();
        
};