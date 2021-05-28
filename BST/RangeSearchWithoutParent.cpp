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
// TreeNode* leftDescendant(TreeNode*N){
//     if(N->left == nullptr){
//         return N;
//     }
//     else{
//         return leftDescendant(N->left);
//     }
// }
// TreeNode* rightDescendant(TreeNode*N){
//     if(N->key < N-)
// }
// TreeNode* Next(TreeNode*N){
    
// }
void rangeSearch(TreeNode* root, int low, int high, int &sum){
    if(root->val<=high && root->val>=low){
        sum+=root->val;
    }
    if(root->left!=nullptr && root->val>=low){
        rangeSearch(root->left, low, high, sum);
    }
    if(root->right!=nullptr && root->val<=high){
        rangeSearch(root->right, low, high, sum);
    }
    
}
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        rangeSearch(root, low, high, sum);
        return sum;
    }
};