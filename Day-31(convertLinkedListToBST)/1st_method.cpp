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
int length(Node* head){
    int l = 0 ;
    while(head != NULL){
        l++;
        head = head->next;
    }
    return l;
}
node* createBST(Node* head,int s,int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;
    Node* temp = head;
    for(int i=0;i<mid;i++){
        temp = temp->next;
    }
    node* root = new node(temp->val);
    root->left = createBST(head,s,mid-1);
    root->right = createBST(head,mid+1,e);

    return root;
}
node* sortedListToBST(Node* head) {
    if(head == NULL){
        return NULL;
    }
    int n = length(head);
    return createBST(head,0,n-1);
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