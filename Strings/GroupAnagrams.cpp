// Given an array of strings strs, group the anagrams together. 
// You can return the answer in any order.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> store;
        vector<vector<string>> result;
        // result.push_back({});
        int n=0;
        string temp;
        for(int i=0; i<strs.size(); i++){
            temp = strs[i];
            sort(temp.begin(), temp.end());
            // cout<<temp<<endl;
            if(store.find(temp) == store.end()){
                store[temp] = n;
                result.push_back({strs[i]});
                n++;
            }
            else{
                result[store[temp]].push_back(strs[i]);
            }
        }
        return result;
    }
};