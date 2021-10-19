class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){return "";}
        int resx=0, resy=INT_MAX, j=0;
        unordered_map<char, int> cst;
        for(int i=0; i<t.size(); i++){
            cst[t[i]]++;
        }
        int count = cst.size();
        
        for(int i=0; i<s.size(); i++){
            if(j<i){j=i;}
            if(count==0){
                if(j-1-i < resy-resx){
                    resx = i;
                    resy = j-1;
                }
            }
            while((cst.find(s[i]) != cst.end()) && j<s.size() && count!=0) {
                if(cst.find(s[j]) != cst.end()){
                    cst[s[j]]--;
                    if(cst[s[j]] == 0){count--;}
                }
                if(count==0){
                    if(j-i < resy-resx){
                        resx = i;
                        resy = j;
                    }
                }
                j++;
            }
            if(cst.find(s[i]) != cst.end()){
                cst[s[i]]++;
                if(cst[s[i]] == 1){count++;}
            }
        }
        if(resy == INT_MAX){return "";}
        return s.substr(resx, resy-resx+1);
    }
};