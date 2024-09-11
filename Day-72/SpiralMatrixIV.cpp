#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int val;
        node* next;
        node(int val){
            this->val = val;
            this -> next = NULL;
        }
};

node* buildLinkedlist(){
    node* head = NULL;
    node* tail = NULL;

    int data;
    cin>>data;
    while(data!=-1){
        if(head == NULL){
            node* n = new node(data);
            head = n;
            tail = n;
        }else{
            node* n = new node(data);
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}
vector<vector<int>> spiralMatrix(int m, int n, node* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int topRow = 0, bottomRow = m - 1, leftColumn = 0, rightColumn = n - 1;
        
        while (head) {
            for (int col = leftColumn; col <= rightColumn && head; ++col) {
                matrix[topRow][col] = head->val;
                head = head->next;
            }
            topRow++;
            
            for (int row = topRow; row <= bottomRow && head; ++row) {
                matrix[row][rightColumn] = head->val;
                head = head->next;
            }
            rightColumn--;
            
            for (int col = rightColumn; col >= leftColumn && head; --col) {
                matrix[bottomRow][col] = head->val;
                head = head->next;
            }
            bottomRow--;
            
            for (int row = bottomRow; row >= topRow && head; --row) {
                matrix[row][leftColumn] = head->val;
                head = head->next;
            }
            leftColumn++;
        }
        
        return matrix;
    }
int main(){
    int n , m;
    cin >> n >> m;
    node* head = buildLinkedlist();
    vector<vector<int>> matrix = spiralMatrix(m, n, head);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}