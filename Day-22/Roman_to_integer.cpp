#include<bits/stdc++.h>
using namespace std;
int check(char c){
    switch(c){
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }
    return 0;
}
int romanToInt(string s) {
    int n = s.size();
    int num = 0;
    for(int i=0;i<n;i++){
        int val = check(s[i]);
        if(i<n-1 && val < check(s[i+1]))
        num = num - val;
        else
        num = num + val;
    }
    return num;
}
int main(){
    string s;
    cin>>s;
    cout<<s<<" = "<<romanToInt(s)<<endl;
    return 0;
}