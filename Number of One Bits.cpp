#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n){
    int ones=0;
    while(n>0){
        ones += n & 1;
        n >>= 1;
    }
    return ones;
}

int main(){
    uint32_t n;
    cin>>n;
    cout<<hammingWeight(n)<<endl;
    return 0;
}

/**

2
1 3
6 9
2 5

*/