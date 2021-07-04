/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
vector<int> lv;
void leftV(Node *root, int height){
    for(auto child: {root->left, root->right}){
        if(child!=NULL){
            if(lv.size() <= height){
                lv.push_back(child->data);
            }
            leftV(child, height+1);
        }
    }
}

vector<int> leftView(Node *root){
    lv.clear();
    if(root==NULL){
        return lv;
    }
    
    lv.push_back(root->data);
    leftV(root, 1);
    return lv;
}
