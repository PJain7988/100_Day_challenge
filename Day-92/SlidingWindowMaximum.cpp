#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& h, int k) {
    vector<int> ans;
    int n=h.size();
    deque<int> q;
    for(int i=0;i<n;i++){
        while(!q.empty() && h[q.back()]<=h[i]){
            q.pop_back();
        }
    if(!q.empty()&&q.front()==i-k){
            q.pop_front();
        }
    q.push_back(i);
    if(i>=k-1){
        ans.push_back(h[q.front()]);
    }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int k;
    cin>>k;
    vector<int> ans=maxSlidingWindow(h,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}