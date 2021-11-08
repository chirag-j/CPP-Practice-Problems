// Given a string containing digits from 2-9 inclusive, 
// return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. 
// Note that 1 does not map to any letters.

map<char, string> let;
class Solution {
public:
    void backtrack(string digits, int x, string word, vector<string> &res){
        if(x>=digits.size()){
            res.push_back(word);
            return;
        }
        for(int i=0; i<let[digits[x]].size(); i++){
            backtrack(digits, x+1, word+let[digits[x]][i], res);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() ==0){return {};}
        let.clear();
        let['2'] = "abc";
        let['3'] = "def";
        let['4'] = "ghi";
        let['5'] = "jkl";
        let['6'] = "mno";
        let['7'] = "pqrs";
        let['8'] = "tuv";
        let['9'] = "wxyz";
        string temp;
        vector<string> res;
        backtrack(digits,0,"",res);
        return res;
    }
};