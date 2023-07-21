// Given an array of integers preorder, which represents the preorder traversal of a BST, 
// construct the tree and return its root.

class Solution {
public:
    void buildTree(TreeNode* root, vector<int>& preorder, int &x, int mx, int mn){
        if(x>=preorder.size()){return;}
        root->val = preorder[x];
        if(x==preorder.size()-1){return;}
        
        if((preorder[x+1] < root->val) && preorder[x+1]<mx && preorder[x+1]>mn){
            root->left = new TreeNode;
            x++;
            buildTree(root->left, preorder,x,root->val,mn);
        }
        if((x+1<preorder.size()) && (preorder[x+1] > root->val) && (preorder[x+1]<mx) && (preorder[x+1]>mn)){
            root->right = new TreeNode;
            x++;
            buildTree(root->right, preorder,x,mx,root->val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode;
        int x = 0;
        buildTree(root,preorder, x, 1001,-1);
        return root;
    }
};