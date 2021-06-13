int sum = 0;
void LeafSum(TreeNode* root, int depth, int &maxD){
    cout<<root->val<<" "<<sum<<endl;
    if(root->left == nullptr && root->right==nullptr){
        if(depth == maxD){
            sum+=root->val;
        }
        else if(depth>maxD){
            maxD = depth;
             sum = root->val;
        }
        return;
    }
    if(root->left!=nullptr){
        LeafSum(root->left, depth+1, maxD);
    }
    if(root->right!=nullptr){
        LeafSum(root->right, depth+1, maxD);
    }
}
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        sum = 0;
        int maxD = 0;
        LeafSum(root, 0, maxD);
        return sum;
    }
};