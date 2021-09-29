// Given a pattern and a string s, find if s follows the same pattern.

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // vector<string> words;
        string word = "";
        unordered_map<char, string> mapping;
        unordered_map<string, char> op_map;
        int word_num = 0;
        for(int i=0; i<=s.size(); i++){
            if(word_num >= pattern.size()){
                return false;
            }
            if(s[i] == ' ' || i == s.size()){
                // words.push_back(word);
                if(mapping.find(pattern[word_num]) == mapping.end()){
                    if(op_map.find(word) == op_map.end()){
                        mapping[pattern[word_num]] = word;
                        op_map[word] = pattern[word_num];
                    }
                    else{
                        return false;
                    }
                }
                else if(mapping[pattern[word_num]] != word){
                    return false;
                }
                word_num++;
                word = "";
            }
            else{
                word+=s[i];
            }
        }
        // if(word_num != pattern.size()){
        //     return false;
        // }
        return (word_num == pattern.size());
    }
};