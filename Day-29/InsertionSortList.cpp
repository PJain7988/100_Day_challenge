#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int value){
        val=value;
        next=NULL;
    }
};
node* buildlist(){
    node* head = NULL;
    node* tail = NULL;
    int val;
    cin>>val;
    while(val>0){
        if(head == NULL){
            node * n = new node(val);
            head = n;
            tail = n;
        }else{
            node * n = new node(val);
            tail->next = n;
            tail = n;
        }cin>>val;
    }
    return head;
}
node* insertionSortList(node* head) {
    if (!head || !head->next) return head;
    node* temp = new node(0);
    temp->next = head;
    node* curr = head->next;
    head->next = NULL;
    while (curr) {
        node* prev = temp;
        node* next = curr->next;
        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }
    node* result = temp->next;
    return result;
}
void print(node* head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main(){
    node* head = buildlist();
    head = insertionSortList(head);
    print(head);
    return 0;
}