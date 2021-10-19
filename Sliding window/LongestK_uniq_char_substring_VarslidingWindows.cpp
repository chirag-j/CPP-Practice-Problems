// Given a string you need to print the size of the longest possible substring 
// that has exactly K unique characters. 
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> count;
        int num_uniq = 0, j=0, res = 0;
        for(int i=0; i<s.size(); i++){
            if(num_uniq==k){
                res = max(res, j-i);   //Why not j-i+1, think (j was already incremented the last time)
            }
            while(num_uniq<=k && j<s.size()){
                if(count[s[j]] == 0){
                    num_uniq++;
                }
                count[s[j]]++;
                if(num_uniq==k){
                    res = max(res, j-i+1);
                }
                j++;
            }
            count[s[i]]--;
            if(count[s[i]]==0){num_uniq--;}
            
        }
        if(res==0){return -1;}
        return res;
    // your code here
    }
};
