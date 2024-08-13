#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* BuildTree(){
    cout<<"Enter root node data : ";
    queue<node*> q;
    int data,LD,Rd;
    cin>>data;
    if(data == -1)
    return NULL;
    node* root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* f = q.front();
        q.pop();
        cout<<"Enter left node data of "<<f->data<<" : ";
        cin>>LD;
        if(LD != -1){
        node* ld = new node(LD);
        f->left = ld;
        q.push(ld);
        }
        cout<<"Enter right node data of "<<f->data<<" : ";
        cin>>Rd;
        if(Rd != -1){
        node* rd = new node(Rd);
        f->right = rd;
        q.push(rd);
        }
    }

    return root;
}
void solve(node* root , vector<int>& ans){
    if(root == NULL)
    return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        while(size--){
            node* f = q.front();
            q.pop();
            if(flag == 0){
            ans.push_back(f->data);
            flag = 1;
            }
            if(f->right)
            q.push(f->right);
            if(f->left)
            q.push(f->left);
        }
    }
}
vector<int> rightSideView(node *root){
    vector<int> ans;
    solve(root,ans);
    return ans;
}
int main(){
    node* root = BuildTree();
    vector<int> ans = rightSideView(root);
    for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
    }
    return 0;
}