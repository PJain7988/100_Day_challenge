#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() >= num) maxHeap.push(num);
        else minHeap.push(num);

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return maxHeap.top()/2.0 + minHeap.top()/2.0;
        }
        return maxHeap.top();
    }
};
int main(){
    MedianFinder mf;
    int n;
    cin>>n;
    vector<string>operations(n);
    vector<vector<int>>nums(n);
    for(int i=0;i<n;i++){
        cin>>operations[i];
        if (operations[i] == "addNum") {
            int num;
            cin >> num;
            nums[i].push_back(num);
        }
    }
    for (int i = 0; i < n; i++) {
        if (operations[i] == "MedianFinder") {
            cout << "MedianFinder initialized" << endl;
        }
        else if (operations[i] == "addNum") {
            mf.addNum(nums[i][0]);
            cout << "Added number: " << nums[i][0] << endl;
        }
        else if (operations[i] == "findMedian") {
            double median = mf.findMedian();
            cout << "Current median: " << median << endl;
        }
    }
    return 0;
}