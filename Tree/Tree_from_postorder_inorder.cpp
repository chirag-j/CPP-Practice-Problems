class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int i1,int i2, int p1, int p2){
        if(i2<i1 || p2<p1){return nullptr;}
        TreeNode* root = new TreeNode (postorder[p2]);
        if(i1==i2 || p1==p2){
            return root;
        }
        for(int i=i1; i<=i2; i++){
            if(inorder[i] == postorder[p2]){
                root->left = buildTree(inorder, postorder, i1, i-1, p1, p1+(i-1 -i1) );
                root->right = buildTree(inorder, postorder, i+1, i2, p1+(i-i1), p2-1);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size()-1, 0,postorder.size()-1);   
    }
};