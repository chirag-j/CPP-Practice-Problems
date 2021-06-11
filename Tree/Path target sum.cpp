bool dfs(TreeNode* root,int sum, int targetSum){
    if(root->left==nullptr && root->right==nullptr){
        if(sum==targetSum){
            return true;
        }
        return false;
    }
    if(root->left!=nullptr){
        if(dfs(root->left, sum+root->left->val, targetSum)){
            return true;
        }
    }
    if(root->right!=nullptr){
        if(dfs(root->right, sum+root->right->val, targetSum)){
            return true;
        }
    }
    return false;
}
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root!=nullptr && dfs(root, root->val, targetSum)){
            return true;
        }
        return false;
    }
};