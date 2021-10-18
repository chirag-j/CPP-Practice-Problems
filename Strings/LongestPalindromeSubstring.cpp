// Note = Longest Palindrome Subsequnce is DP
// This is not
// approach
// 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int expandFromMiddle(string s, int left, int right){
    if(s[left] != s[right]){
        return 0;
    }
    int n = s.length();
    while((left>0) && ((right+1)<n) && (s[left-1]==s[right+1])){
        left--;
        right++;
    }
    return (right-left+1);
}

string longestPalindrome(string s) {
    int start = 0, end = 0, len;
    for(int i=0; i<s.size(); i++){
        len = max(expandFromMiddle(s, i, i),expandFromMiddle(s, i, i+1));
        if(len > end-start+1){
            start = i - (len-1)/2;
            end = i + len/2;
        }
    }
    return s.substr(start, end-start+1);
}


int main(){
    string s = "aabba";
    cout<<longestPalindrome(s);
    return 0;
}