#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i=0;
        int j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target)
            return true;
            if(target>matrix[i][j])
            i++;
            else
            j--;
        }
        return false;
    }
int main(){
    int n , m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int target;
    cin>>target;
    cout<<searchMatrix(matrix,target);
    return 0;
}