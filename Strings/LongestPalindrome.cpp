// Given a string s which consists of lowercase or uppercase letters, 
// return the length of the longest palindrome that can be built with those letters.
// Note that this is different from longest Palidromic subsequence which is an LCS problem--Dynamic programming

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for(int i=0; i<s.size(); i++){
            count[s[i]]++;
        }
        int lenPal = 0;
        for(auto &it : count){
            if(it.second % 2 == 0){
                lenPal+=it.second;
                it.second = 0;
            }
            else if(it.second == 1){
                continue;
            }
            else{
                lenPal+=(it.second-1);
                it.second = 1;
            }
        }
        for(auto &it : count){
            if(it.second > 0){
                lenPal++;
                break;
            }
        }
        return lenPal;
    }
};