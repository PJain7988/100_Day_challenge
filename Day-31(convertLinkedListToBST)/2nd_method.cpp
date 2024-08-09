#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};
class node{
    public:
    int val;
    node* left;
    node* right;
        node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* BuildLinkedList(){
    Node* head = NULL;
    Node* tail = NULL;

    int data;
    cin>>data;
    while(data!=-1){
        if(head == NULL){
            Node* n = new Node(data);
            head = n;
            tail = n;
        }else{
            Node* n = new Node(data);
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}
node* createBST(vector<int>& ans, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    node* root = new node(ans[mid]);
    root->left = createBST(ans, start, mid - 1);
    root->right = createBST(ans, mid + 1, end);
    return root;
}
node* sortedListToBST(Node* head) {
    vector<int>arr;
    while(head != NULL){
        arr.push_back(head->val);
        head = head->next;
    }
    return createBST(arr,0,arr.size()-1);
}
void print(node* root){
    if (!root) return ;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            node* node = q.front();
            q.pop();
            cout<<node->val<<" ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }     
        cout<<endl;
    }
}
int main(){
    Node* head = BuildLinkedList();
    node* root = sortedListToBST(head);
    print(root);
    return 0;
}