#include<bits/stdc++.h>
using namespace std;
int getWinner(vector<int>& arr, int k) {
    int winner = arr[0];
    int cnt = 0;
    for(int i=1;i<arr.size();i++){
        if(winner > arr[i])
            cnt++;
        else{
            winner = arr[i];
            cnt=1;
        }
        if(cnt==k)
            return winner;
    }
    return winner;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<getWinner(arr,k)<<endl;
    return 0;
}