#include<bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> size;
int _find(int i){
    if(par[i] == -1) return i;
    return par[i] = _find(par[i]);
}  
void _union(int i, int j){
    int p1 = _find(i);
    int p2 = _find(j);
    if(p1 != p2){
        if(size[p1]>size[p2]){
            par[p2] = p1;
            size[p1] += size[p2];
        }
        else{
            par[p1] = p2;
            size[p2] += size[p1];
        }
    }
}   
int n;
int num(int i, int j){
    return n*(i) + j + 1;
}   
int regionsBySlashes(vector<string>& grid) {
    n = grid.size();
    n++;
    par.assign((n)*(n) + 1, -1);
    size.assign((n)*(n) + 1, 1);
    for(int i = 0; i<n; i++){
        _union(0, num(i, 0));
        _union(0, num(i, n-1));
        _union(0, num(0, i));
        _union(0, num(n-1, i));
    }
    int cnt = 1;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<grid[i].size();j++){
            if(grid[i][j] == '/'){
                int p1 = _find(num(i,j+1));
                int p2 = _find(num(i+1, j));
                if(p1 == p2){
                    cnt++;
                }
                else{
                    _union(p1, p2);
                }
            }
            else if(grid[i][j] == '\\'){
                int p1 = _find(num(i,j));
                int p2 = _find(num(i+1, j+1));
                if(p1 == p2){
                    cnt++;
                }
                else{
                    _union(p1, p2);
                }
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i<n; i++){
        cin >> grid[i];
    }
    cout<<regionsBySlashes(grid);
    return 0;
}