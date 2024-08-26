#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
   int val;
   TreeNode* left;
   TreeNode* right; 
            TreeNode(int val){
                this->val = val;
                left = NULL;
                right = NULL;
            }
};
TreeNode* BuildTree(){
    queue<TreeNode*> q;
    int data,LD,Rd;
    cin>>data;
    if(data == -1)
    return NULL;
    TreeNode* root = new TreeNode(data);
    q.push(root);
    while(!q.empty()){
        TreeNode* f = q.front();
        q.pop();
        cin>>LD;
        if(LD != -1){
        TreeNode* ld = new TreeNode(LD);
        f->left = ld;
        q.push(ld);
        }
        cin>>Rd;
        if(Rd != -1){
        TreeNode* rd = new TreeNode(Rd);
        f->right = rd;
        q.push(rd);
        }
    }

    return root;
}
void print(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* f = q.front();
        q.pop();

        cout<<f->val<<" ";
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
    }

}
void flatten(TreeNode* root) {
    if(!root) return;
    vector<TreeNode*> preorder;
    preOrder(root, preorder);
    for(int i = 1; i < preorder.size(); i++) {
        root->left = NULL;
        root->right = preorder[i];
        root = root->right;
    }
}
void preOrder(TreeNode* root, vector<TreeNode*>& vec) {
    if(!root) {
        return;
    }
    vec.push_back(root);
    preOrder(root->left, vec);
    preOrder(root->right, vec);     
}
int main(){
    TreeNode* root = BuildTree();
    flatten(root);
    print(root);
    return 0;
}