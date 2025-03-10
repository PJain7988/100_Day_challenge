#include<bits/stdc++.h>
using namespace std;
bool judgeSquareSum(int c) {
        long long a = 0;
        long long b = (int) sqrt(c);
        while (a <= b) {
            long long sum = a * a + b * b;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                a++;
            } else {
                b--;
            }
        }
        return false;
    }
int main(){
    int n;
    cin >> n;
    if(judgeSquareSum(n)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}