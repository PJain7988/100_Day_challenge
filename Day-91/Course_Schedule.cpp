#include<bits/stdc++.h>
using namespace std;
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    vector<int> ans;
    for(auto x: prerequisites){
        adj[x[0]].push_back(x[1]);
        indegree[x[1]]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        auto t = q.front();
        ans.push_back(t);
        q.pop();
        for(auto x: adj[t]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }
    return ans.size() == n;
}
int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int num;
    cin >> num;
    if(canFinish(num,arr)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}