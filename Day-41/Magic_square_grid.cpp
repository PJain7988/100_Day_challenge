#include<bits/stdc++.h>
using namespace std;
int findRowSum(vector<vector<int>>& grid,int r,int c){
    bool v[10] = {false};
    int sum = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            int val = grid[r+i][c+j];
            if(val == 0 || val>=10 || v[val]){
                return false;
            }
            v[val] = true;
            sum += val;
        }
    }
        for (int i = 0; i < 3; i++) {
            int rowSum = 0;
            int colSum = 0;
            for (int j = 0; j < 3; j++) {
                rowSum += grid[r + i][c + j];
                colSum += grid[r + j][c + i];
            }
            if (rowSum != sum / 3 || colSum != sum / 3) {
                return false;
            }
        }
        int diagonalSum1 = 0;
        int diagonalSum2 = 0;
        for (int i = 0; i < 3; i++) {
            diagonalSum1 += grid[r + i][c + i];
            diagonalSum2 += grid[r + i][c + 2 - i];
        }
        if (diagonalSum1 != sum / 3 || diagonalSum2 != sum / 3) {
            return false;
        }
        return true;
}
int numMagicSquaresInside(vector<vector<int>>& grid) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < cols - 2; j++) {
            if (findRowSum(grid, i, j)) {
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    return 0;
}