#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n) {
    int size = arr.size();
    if(size != n*m) return {};
    vector<vector<int>>ans(m);
    vector<int>ar(n);
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ar[j]=arr[k];
            k++;
        }
        ans[i]=ar;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int m , k;
    cin >> m >> k;
    vector<vector<int>>ans = construct2DArray(arr,m,k);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}