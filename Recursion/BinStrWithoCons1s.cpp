#include<iostream>
#include<vector>
using namespace std;

void generate(int n, string curr, vector<string>& ans) {

    // Base case
    if(curr.length() == n) {
        ans.push_back(curr);
        return;
    }

    // Add 0
    generate(n, curr + '0', ans);

    // Add 1 only if previous char is not 1
    if(curr.empty() || curr.back() != '1') {
        generate(n, curr + '1', ans);
    }
}

void generateString(int n) {

    vector<string> ans;
    string curr = "";

    generate(n, curr, ans);

    // Print answer
    for(string str : ans) {
        cout << str << endl;
    }
}

int main() {

    int n;
    cin >> n;

    generateString(n);
}