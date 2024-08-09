#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
        node(int val){
            this->val = val;
            left = NULL;
            right = NULL;
        }
};
node * InsertBST(node* root , int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data < root->val){
        root->left = InsertBST(root->left , data);
    }
    if(data > root->val){
        root->right = InsertBST(root->right , data);
    }
    return root;
}
node* createBST(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    node* root = NULL;
    while(data!= -1){
        root = InsertBST(root , data);
        cin>>data;
    }
    return root;
}
void convert(node* root, vector<int>& ans) {
    if (!root) return;
    convert(root->left, ans);
    ans.push_back(root->val);
    convert(root->right, ans);
}
node* buildBalancedBST(vector<int>& ans, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    node* root = new node(ans[mid]);
    root->left = buildBalancedBST(ans, start, mid - 1);
    root->right = buildBalancedBST(ans, mid + 1, end);
    return root;
}
node* balanceBST(node* root) {
    vector<int> ans;
    convert(root, ans);
    return buildBalancedBST(ans, 0, ans.size() - 1);
}
void print(node* root){
    if(!root)   return;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}
int main(){
    node* root1 = createBST();
    node* root2 = balanceBST(root1);
    cout<<"Binary Search Tree : ";
    print(root1);
    cout<<endl<<"Another Binary Search Tree with same data : ";
    print(root2);
}