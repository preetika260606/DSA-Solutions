#include <iostream>
#include <vector>
using namespace std;

void printS(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {

    if (ind == n) {
        if (s == sum) {
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // Pick the element
    ds.push_back(arr[ind]);
    s += arr[ind];
    printS(ind + 1, ds, s, sum, arr, n);

    // Backtrack
    s -= arr[ind];
    ds.pop_back();

    // Not pick the element
    printS(ind + 1, ds, s, sum, arr, n);
}

int main() {

    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 2;
    vector<int> ds;

    printS(0, ds, 0, sum, arr, n);

    return 0;
}