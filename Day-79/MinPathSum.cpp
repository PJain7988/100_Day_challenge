#include<bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;
                if (i == m - 1) {
                    grid[i][j] += grid[i][j + 1];
                } else if (j == n - 1) {
                    grid[i][j] += grid[i + 1][j];
                } else {
                    grid[i][j] += min(grid[i][j + 1], grid[i + 1][j]);
                }
            }
        }
        return grid[0][0];
    }
int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    cout<<minPathSum(grid);
    return 0;
}