#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<string> paths;
void DFS(TreeNode* root, string path){
    if(root->left == nullptr && root->right == nullptr){
        paths.push_back(path);
        return;
    }
    if(root->left != nullptr){
        DFS(root->left, path+"->"+to_string(root->left->val));
    }
    if(root->right != nullptr){
        DFS(root->right, path+"->"+to_string(root->right->val));
    }
}
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        paths.clear();
        if(root==nullptr){
            return paths;
        }
        DFS(root, to_string(root->val));
        return paths;
    }
};
int main(){

    return 0;
}