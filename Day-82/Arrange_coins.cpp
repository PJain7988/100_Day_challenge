#include<bits/stdc++.h>
using namespace std;
int arrangeCoins(int n) {
    int i;
    for(i=0;i<n;i++){
        if(n>=i){
            n = n-(i+1);
        }
        else{
            break;
        }
    }
    return i;
}
int main(){
    int n;
    cin>>n;
    cout<<arrangeCoins(n);
    return 0;
}