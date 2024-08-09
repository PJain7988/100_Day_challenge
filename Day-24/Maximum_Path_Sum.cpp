#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
        node(int val){
            this->val=val;
            left=NULL;
            right=NULL;
        }
};
node* BuildTree(){
    int val;
    cin>>val;
    if(val == -1)   return NULL;
    node* root=new node(val);
    root->left=BuildTree();
    root->right=BuildTree();

    return root;
}
int maxGain(node* root, int& max_sum) {
    if (!root) return 0;
    int left = max(maxGain(root->left, max_sum), 0);
    int right = max(maxGain(root->right, max_sum), 0);
    int newPath = root->val + left + right;
    max_sum = max(max_sum, newPath);
    return root->val + max(left, right);
}
int maxPathSum(node* root) {
    int max_sum = INT_MIN;
    maxGain(root, max_sum);
    return max_sum;
}
int main(){
    node* root=BuildTree();
    cout<<maxPathSum(root);
    return 0;
}