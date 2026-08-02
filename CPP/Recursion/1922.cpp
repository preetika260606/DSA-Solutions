//count good number

#include <iostream>
using namespace std;

const long long mod=1e9+7;
long long findPower(long long a, long long b){

    if(b==0) return 1;

    long long half=findPower(a,b/2);
    long long res=half*half;

    if(b%2==1)
        res=res*a;

    return res % mod;
}
int countGoodNumber(long long n){
    return findPower(5,(n+1)/2)*findPower(4,n/2) % mod;
}
int main(){
    long long n;
    cin>>n;

    cout<<countGoodNumber(n)<<endl;

    return 0;
}