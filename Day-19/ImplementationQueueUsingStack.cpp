#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
         while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int a = s1.top();
        s1.pop();
        return a;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.size()==0;
    }
};
int main(){
    MyQueue q;
    int n ;
    cin>>n;
    vector<string>operation(n),result(n);
    for(int i=0;i<n;i++){
        cin>>operation[i];
        if(operation[i] == "push"){
            int val;
            cin>>val;
            q.push(val);
            result[i]= "null";
        }else if(operation[i] == "pop"){
            result[i] = to_string(q.pop());
        }else if(operation[i] == "empty"){
            if(q.empty()==false)
            result[i] = "false";
            else
            result[i] = "true";
        }else{
            result[i] = to_string(q.peek());
        }
    }
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<result[i];
        if(i<n-1){
            cout<<", ";
        }
    }
    cout<<"]";
    return 0;
}