#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
        node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};
node * InsertBST(node* root , int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }
    if(data < root->data){
        root->left = InsertBST(root->left , data);
    }else{
        root->right = InsertBST(root->right , data);
    }
    return root;
}
node* CreateBST(){
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
void convert(node* root, vector<int>& ans){
    if(root == NULL)    return;
    convert(root->left,ans);
    ans.push_back(root->data);
    convert(root->right,ans);
}
node* createBST(vector<int>& ans,int start,int end){
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    node* root = new node(ans[mid]);
    root->left = createBST(ans, start, mid - 1);
    root->right = createBST(ans, mid + 1, end);
    return root;
}
node* deleteNode(node* root, int key) {
    vector<int>ans;
    convert(root,ans);
    vector<int>arr;
    for(int i=0;i<ans.size();i++){
        if(ans[i] != key){
            arr.push_back(ans[i]);
        }
    }
    return createBST(arr,0,arr.size()-1);
}
void print(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* f = q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
    }
}
int main(){
    node* root = CreateBST();
    int key;
    cin>>key;
    node* root1 = deleteNode(root,key);
    print(root1);
    return 0;
}