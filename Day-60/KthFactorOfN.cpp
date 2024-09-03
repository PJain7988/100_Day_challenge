#include<bits/stdc++.h>
using namespace std;
int kthFactor(int n, int k) {
    vector<int>arr;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            arr.push_back(i);
        }
    } 
    if(arr.size()<k){
        return -1;
    } 
    return arr[k-1]; 
}
int main(){
    int n , k;
    cin >> n >> k;
    cout << kthFactor(n,k);
    return 0;
}