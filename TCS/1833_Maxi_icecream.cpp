#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {

        int n = costs.size();

        int size = 0;
        int equi = 0;

        sort(costs.begin(), costs.end());

        for(int i = 0; i < n; i++) {

            if(equi + costs[i] > coins) {
                break;
            }

            equi += costs[i];
            size++;
        }

        return size;
    }

int main() {
    int n;
    cin>>n;

    vector<int>costs(n);

    for(int i=0;i<n;i++){
        cin>>costs[i];
    }

    int coins;

    cin>>coins;

    cout<<maxIceCream(costs,coins);
}