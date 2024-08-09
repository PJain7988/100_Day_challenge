#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<char>>& board, string word,int i,int j, int index){
    if(index == word.size())    return true;
    if(i<0 || i>=board.size())   return false;
    if(j<0 || j>=board[0].size())   return false;
    if(board[i][j] != word[index])   return false;
    char temp = board[i][j];
    board[i][j] = '*';
    bool row = check(board,word,i+1,j,index+1) || check(board,word,i-1,j,index+1);
    bool col = check(board,word,i,j+1,index+1) || check(board,word,i,j-1,index+1);
    board[i][j]= temp;
    return row || col;
}
bool exist(vector<vector<char>>& board, string word) {
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(check(board,word,i,j,0))
                return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> board(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    string word;
    cin>>word;
    if(exist(board,word)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}