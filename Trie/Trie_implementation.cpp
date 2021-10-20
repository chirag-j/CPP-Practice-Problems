// Trie -- Very useful data structure to store multiple strings
// enables very efficient prefix search, and whole word searches
// Time complexity of all operations is O(L), where L is the length of the word

#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class TrieNode{
    public:
    unordered_map<char, TrieNode*> nodes;
    bool EOW = false;
};
void display(unordered_map<char, TrieNode*> x){
    for(auto &i : x){
        cout<<i.first<<" ";
    }
    cout<<endl;
}

class Trie {
public:
    TrieNode root;
    Trie() {
        // TrieNode root;
    }
    
    void insert(string word) {
        TrieNode *temp = &root;
        for(int j=0; j<word.size(); j++){
            if((temp->nodes).find(word[j]) == (temp->nodes).end()){
                (temp->nodes)[word[j]] = new TrieNode;
                temp = (temp->nodes)[word[j]];
            }
            else{
                temp = (temp->nodes)[word[j]];
            }
            if(j==word.size()-1){
                temp->EOW = true;
            }
        }
    }
    
    bool search(string word) {
        TrieNode *temp = &root;
        for(int j=0; j<word.size(); j++){
            if((temp->nodes).find(word[j]) == (temp->nodes).end()){
                return false;
            }
            temp = (temp->nodes)[word[j]];
        }
        return temp->EOW;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = &root;
        for(int j=0; j<prefix.size(); j++){
            if((temp->nodes).find(prefix[j]) == (temp->nodes).end()){
                return false;
            }
            temp = (temp->nodes)[prefix[j]];
        }
        return true;
    }
};



int main(){
    vector<string> inp = {"abc", "abcd", "abgl", "cdf", "lmn"};
    Trie myTrie;
    for(int i=0; i<inp.size(); i++){
        myTrie.insert(inp[i]);
    }
    
    cout<<myTrie.startsWith("cd")<<endl;
    cout<<myTrie.search("abgl")<<endl;


    TrieNode *temp = (myTrie.root).nodes['a'];
    temp = temp->nodes['b'];
    // temp = temp->nodes['c'];
    // temp = temp->nodes['d'];
    // temp = temp->nodes['l'];
    display(temp->nodes);
    cout<<temp->EOW<<endl;
    return 0;
}