#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
 class Node {
    public:
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
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
Node traverse(node* root, int& maxSum) {
        if (root == NULL) {
            return {true, 0, INT_MAX, INT_MIN};
        }
        Node lh = traverse(root->left, maxSum);
        Node rh = traverse(root->right, maxSum);
        if (lh.isBST && rh.isBST && root->data > lh.maxVal && root->data < rh.minVal) {
            int currentSum = root->data + lh.sum + rh.sum;
            maxSum = max(maxSum, currentSum);

            return {true, currentSum, min(root->data, lh.minVal), max(root->data, rh.maxVal)};
        } else {
            return {false, 0, 0, 0};
        }
    }

    int maxSumBST(node* root) {
        int maxSum = 0;
        traverse(root, maxSum);
        return maxSum;
    }

int main(){
    node* root = BuildTree();
    cout<<maxSumBST(root);
    return 0;
} 