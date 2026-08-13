#include<iostream>
#include<vector>
using namespace std;

// vector<vector<int>> construct2d(vector<int>& original, int m, int n) {
//     vector<vector<int>> result(m, vector<int>(n));

//     if(original.size() != m * n) {
//         return {};
//     }

//     int ind = 0;

//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             result[i][j] = original[ind];
//             ind++;
//         }
//     }

//     return result;
// }




            //   OR



vector<vector<int>> construct2d(vector<int>& original, int m, int n) {
    if(original.size() != m * n) {
        return {};
    }

    vector<vector<int>> result(m, vector<int>(n));

    for(int i=0;i<original.size();i++){
        int row=i/n;
        int col=i%n;
        
        result[row][col]=original[i];
    }

    return result;
}
int main() {
    int n;
    cin >> n;

    vector<int> original(n);

    for(int i = 0; i < n; i++) {
        cin >> original[i];
    }

    int m, n1;
    cin >> m >> n1;

    vector<vector<int>> result = construct2d(original, m, n1);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n1; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}