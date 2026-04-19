#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
public:
    vector<int> arr;

    void insert(int x) {
        arr.push_back(x);
        int i = arr.size() - 1;

        while (i != 0 && arr[i] > arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Time Complexity: O(log n)
    void deleteRoot() {
        if (arr.size() == 0) {
            cout << "Heap empty\n";
            return;
        }

        arr[0] = arr[arr.size() - 1];
        arr.pop_back();

        int n = arr.size();
        int i = 0;

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && arr[left] > arr[largest])
                largest = left;

            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    // FIXED heapify (BUILD HEAP version)

    //Time Complexity: O(log n)
    void heapify(int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(n, largest);
        }
    }

// Time Complexity: O(n log n)
    void heapSort() {
    int n = arr.size();

    // Step 1: Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }

    // Step 2: Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // move max to end

        // heapify reduced heap
        heapify(i, 0);
    }
}

    void print() {
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap b;

    b.insert(50);
    b.insert(55);
    b.insert(53);
    b.insert(54);
    b.insert(30);
    b.insert(25);

    cout << "Before delete: ";
    b.print();

    b.deleteRoot();

    cout << "After delete: ";
    b.print();

    // BUILD HEAP (O(n)) example
    int n = b.arr.size();

    //heap creation
    for (int i = n / 2 - 1; i >= 0; i--) {
        b.heapify(n, i);
    }

    cout << "After heapify build: ";
    b.print();

cout << "Heap sort result: ";
b.heapSort();
b.print();
    return 0;
}