#include<bits/stdc++.h>
using namespace std;
int chalkReplacer(vector<int>& chalk, int k) {
    long long totalChalk = 0;
    for (int amount : chalk) {
        totalChalk += amount;
    }
    k = k % totalChalk;
    for (int i = 0; i < chalk.size(); i++) {
        if (chalk[i] > k) {
            return i;
        }
        k -= chalk[i];
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> chalk(n);
    for(int i=0;i<n;i++){
        cin >> chalk[i];
    }
    int k;
    cin >> k;
    cout << chalkReplacer(chalk, k) << endl;
    return 0;
}