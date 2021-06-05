/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void inorderTraversal(TreeNode* root, vector<int> &inorder){
    if(root->left != nullptr){
        inorderTraversal(root->left, inorder);
    }
    inorder.push_back(root->val);
    if(root->right != nullptr){
        inorderTraversal(root->right, inorder);
    }
}

TreeNode* Find(TreeNode* root, int key){
    if(root->val==key){
        return root;
    }
    if(root->val<key){
        return Find(root->right, key);
    }
    else{
        return Find(root->left, key);
    }
}
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        // vector<TreeNode> *newT = new vector<TreeNode>(inorder.size());
        TreeNode *trn = new TreeNode[inorder.size()];
        TreeNode *itr = trn;
        for(int i=0; i<inorder.size(); i++){
            itr->val = inorder[i];
            if(i+1 == inorder.size()){
                itr->right = nullptr;
            }
            else{
                itr->right = itr+1;
            }
            itr->left = nullptr;
            itr++;
        }
        return trn;
    }
};