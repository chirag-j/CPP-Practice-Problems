// leetcode DFS easy problem
#include<iostream>
#include<vector>
using namesapce std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
int findDepth(Node* root, int height, int &maxHeight){
    if(root == nullptr){
        return height;
    }
    height++;
    maxHeight = max(maxHeight, height);
    cout<<root->val<<" "<<maxHeight<<endl;
    for(auto child : root->children){
        findDepth(child, height, maxHeight);
    }
    return height;
}

int main(){
    int maxHeight = 0;
    findDepth();
    return 0;
}