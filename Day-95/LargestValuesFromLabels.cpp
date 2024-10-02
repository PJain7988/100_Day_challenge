#include<bits/stdc++.h>
using namespace std;
int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
    vector<pair<int, int>> items;
    for (int i = 0; i < values.size(); i++) {
        items.push_back({values[i], labels[i]});
    }
    sort(items.rbegin(), items.rend());
    
    unordered_map<int, int> labelCount; 
    int sum = 0;  
    int c = 0;  
    
    for (auto &item : items) {
        int value = item.first;
        int label = item.second;
        
        if (labelCount[label] < useLimit) {
            sum += value;
            labelCount[label]++;
            c++;
        }
        if (c == numWanted) break;
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    vector<int>values(n);
    for(int i=0;i<n;i++){
        cin >> values[i];
    }
    vector<int>labels(n);
    for(int i=0;i<n;i++){
        cin >> labels[i];
    }
    int numWanted , useLimit;
    cin >> numWanted >> useLimit;
    cout << largestValsFromLabels(values, labels, numWanted, useLimit);
    return 0;
}