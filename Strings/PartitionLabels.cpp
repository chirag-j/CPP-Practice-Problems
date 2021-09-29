// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

// Return a list of integers representing the size of these parts.

 

void merge(vector<int> &group, int x, int y){
    for(int i = x+1; i<=y; i++){
        group[i] = group[x];
    }
}
void display(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> group(s.size(), -1), result;
        unordered_map<char, int> storage;
        // int grp_num = 0;
        // result[0] = 0;
        for(int i=0; i<s.size(); i++){
            if(storage.find(s[i]) == storage.end()){
                storage[s[i]] = i;
                group[i] = i;
            }
            else{
                merge(group, storage.find(s[i])->second, i);
                grp_num = i+1;
            }
        }
        int temp = 1;
        display(group);
        for(int i=1; i<=group.size(); i++){
            if(i==group.size() || group[i-1] != group[i]){
                result.push_back(temp);
                temp=1;
            }
            else{
                temp++;
            }
        }
        return result;
    }
};