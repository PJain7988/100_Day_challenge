#include<bits/stdc++.h>
using namespace std;
class WordDictionary {
    public:
    bool check(string &a, string &b){
        int i = 0;
        while(i < a.size()){
            if(b[i] != '.' && b[i] != a[i]) return false;
            i++;
        }
        return true;
    }
    unordered_map<int, vector<string>> mp;
    WordDictionary() {}
        void addWord(string word) {
            mp[word.size()].push_back(word);
        }
        bool search(string word) {
            if(mp.find(word.size()) == mp.end()) return false;

            for(auto &i : mp[word.size()]){
                bool ans = check(i, word);
                if(ans) return true;
            }
    return false;
    }
};
int main(){
    WordDictionary dictionary;
    int choice;
    while (true) {
        cin >> choice;
        if (choice == 1) {
            string word;
            cin >> word;
            dictionary.addWord(word);
        } 
        else if (choice == 2) {
            string word;
            cin >> word;
            bool found = dictionary.search(word);
            if (found) {
                cout << "Word found.\n";
            } else {
                cout << "Word not found.\n";
            }
        } 
        else if (choice == 3) {
            break;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}