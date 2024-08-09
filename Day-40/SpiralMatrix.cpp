#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart){
    vector<vector<int>> result;
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int r = rStart, c = cStart, direction = 0;
    int steps = 1;
    for (int i = 0; i < rows * cols; ) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < steps; k++) {
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result.push_back({r, c});
                    i++;
                }
                r += dr[direction];
                c += dc[direction];
            }
            direction = (direction + 1) % 4;
        }
        steps++;
    }
    return result;
}
int main(){
    int row,col;
    cin>>row>>col;
    int rstart,cstart;
    cin>>rstart>>cstart;
    vector<vector<int>> res = spiralMatrixIII(row,col,rstart,cstart);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
    }
    cout<<endl;
    }
    return 0;
}