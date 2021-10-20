// Given n pairs of parentheses, 
// write a function to generate all combinations of well-formed parentheses

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]


// Fpr me, Problem was how to ensure the validity of generated parenthesis
class Solution {
public:
    void backtrack(vector<string> &res,string str, int no, int nc){
        // no is the number of open brackets left
        // nc is the number of closing brackets left
        // when no decrease, nc increases
        if(no==0 && nc==0){
            res.push_back(str);
            return;
        }
        if(no>0){backtrack(res, str+"(", no-1, nc+1);}  
        if(nc>0){backtrack(res, str+")", no, nc-1);}
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,"",n,0);
        return res;
    }
};