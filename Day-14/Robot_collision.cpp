#include<bits/stdc++.h>
using namespace std;
 vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st;
        vector<int> result(n, -1);

        for (int idx : indices) {
            if (directions[idx] == 'R') {
                st.push(idx);
            } else {
                while (!st.empty() && healths[idx] > 0) {
                    int j = st.top();
                    if (healths[j] < healths[idx]) {
                        st.pop();
                        healths[idx] -= 1;
                        result[j] = -1;
                    } else if (healths[j] > healths[idx]) {
                        st.pop();
                        healths[j] -= 1;
                        st.push(j); 
                        healths[idx] = 0;
                    } else {
                        st.pop();
                        healths[idx] = 0;
                        result[j] = -1;
                    }
                }
                if (healths[idx] > 0) {
                    result[idx] = healths[idx];
                }
            }
        }
        while (!st.empty()) {
            int j = st.top();
            st.pop();
            result[j] = healths[j];
        }
        vector<int> survivors;
        for (int i = 0; i < n; ++i) {
            if (result[i] != -1) {
                survivors.push_back(result[i]);
            }
        }

        return survivors;
    }

int main(){
    int n;
    cin>>n;
    vector<int>positions(n);
    vector<int>healths(n);
    string direction;
    cin>>direction;
    vector<int>result = survivedRobotsHealths(positions,healths,direction);
    for(int i=0;i<n;i++){
       cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}