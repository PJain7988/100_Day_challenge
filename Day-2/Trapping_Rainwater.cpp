#include<bits/stdc++.h>
using  namespace std;
    int trap(vector<int>& heights) {
        int n = heights.size();
         int leftmax[n];
        int rightmax[n];
        leftmax[0]=heights[0];
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],heights[i]);
        }
        rightmax[n-1]=heights[n-1];
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],heights[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int height=min(leftmax[i],rightmax[i])-heights[i];
            if(height>0){
                ans=ans+height*1;
            }
        }
        return ans;
    }
int main(){
        int n;
        cin>>n;
        vector<int>heights(n,0);
        for(int i=0;i<n;i++){
            cin>>heights[i];
        }
        cout<<trap(heights)<<endl;
   return 0;
}