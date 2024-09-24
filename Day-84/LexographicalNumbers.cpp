#include<bits/stdc++.h>
using namespace std;
vector<int> lexicalOrder(int n) {
    vector<int> result;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        result.push_back(cur);
        if (cur * 10 <= n) { 
            cur *= 10; 
        }else {
            if (cur >= n) { cur /= 10; }
            cur++; 
            while (cur % 10 == 0) { 
                cur /= 10;
            }
        }
    }
    return result;
}
int main(){
    int n ;
    cin >> n ;
    vector<int> v = lexicalOrder(n);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}