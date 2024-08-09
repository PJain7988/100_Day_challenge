#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int n = rowSum.size();
    int m = colSum.size();
    vector<vector<int>>matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val = min(rowSum[i],colSum[j]);
            matrix[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;
        }
    }
    return matrix;
}
int main(){
    int n,m;
    cin >> n>>m;
    vector<int>rowSum(n);
    for(int i=0;i<n;i++){
        cin >> rowSum[i];
    }
    vector<int>colSum(m);
    for(int i=0;i<m;i++){
        cin >> colSum[i];
    }
    vector<vector<int>>result = restoreMatrix(rowSum,colSum);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}