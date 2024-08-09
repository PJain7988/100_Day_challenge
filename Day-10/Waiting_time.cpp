#include<bits/stdc++.h>
using namespace std;
double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double sum = 0 , time = 1 , s;
        for(int i=0;i<n;i++){
            if(time < customers[i][0]){
                time = customers[i][0];
            }
            time += customers[i][1];
            s = time - customers[i][0];
            sum += s;
        }
    return (sum/n);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> customers(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>customers[i][j];
        }
    }
    cout<<averageWaitingTime(customers);
    return 0;
}