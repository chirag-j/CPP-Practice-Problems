// Given a Binary Tree, convert it into its mirror.
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node->right == NULL && node->left == NULL){
            return;
        }
        if(node->right == NULL){
            node->right = node->left;
            node->left = NULL;
            mirror(node->right);
        }
        else if(node->left == NULL){
            node->left = node->right;
            node->right = NULL;
            mirror(node->left);
        }
        else{
            Node * temp = node->left;
            node->left = node->right;
            node->right = temp;
            
            mirror(node->left);
            mirror(node->right);
            // code here
        }
    }
};