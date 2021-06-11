void findLeafSequence(TreeNode* root, vector<int> &seq){
    if(root->left == nullptr && root->right == nullptr){
        seq.push_back(root->val);
        return;
    }
    if(root->left!=nullptr){
        findLeafSequence(root->left, seq);
    }
    if(root->right!=nullptr){
        findLeafSequence(root->right, seq);
    }
}
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafseq1, leafseq2;
        findLeafSequence(root1, leafseq1);
        findLeafSequence(root2, leafseq2);
        if(leafseq1.size()!=leafseq2.size()){
            return false;
        }
        for(int i=0; i<leafseq1.size(); i++){
            if(leafseq1[i]!=leafseq2[i]){
                return false;
            }
        }
        return true;
    }
};