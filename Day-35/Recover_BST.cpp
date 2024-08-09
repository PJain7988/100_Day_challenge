#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
        node(int data){
            val=data;
            left=NULL;
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
    }else{
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
void recoverTree(node* root) {
    node* first = NULL;
    node* second = NULL;
    node* prev = NULL;
    node* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            if (prev != NULL && curr->val < prev->val) {
                if (first == NULL) {
                    first = prev;
                }
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        } else {
            node* temp = curr->left;
            while (temp->right != NULL && temp->right != curr) {
                temp = temp->right;
            }
            if (temp->right == NULL) {
                temp->right = curr;
                curr = curr->left;
            } else {
                temp->right = NULL;
                if (prev != NULL && curr->val < prev->val) {
                    if (first == NULL) {
                        first = prev;
                    }
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }
    if (first != NULL && second != NULL) {
        swap(first->val, second->val);
    }
}
void print(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* f = q.front();
        q.pop();

        cout<<f->val<<" ";
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);
    }
}
int main(){
    node* root = createBST();
    recoverTree(root);
    print(root);
    return 0;
}