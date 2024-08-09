#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();  
      int m = matrix[0].size();
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(matrix[i][j]==target){
            return true;
           }
        }
      }
      return false;
    }
int main(){
    int  n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,10));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    bool result = searchMatrix(arr,target);
    if(result == true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}