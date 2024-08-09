#include<bits/stdc++.h>
using namespace std;
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return heights[a] > heights[b];
    });
    vector<string> sortedNames(n);
    for (int i = 0; i < n; ++i) {
        sortedNames[i] = names[indices[i]];
    }
    
    return sortedNames;
}

int main(){
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    vector<string> sortedNames = sortPeople(names, heights);
    for (int i = 0; i < sortedNames.size(); ++i) {
        cout << sortedNames[i] << endl;
    }
    return 0;
}