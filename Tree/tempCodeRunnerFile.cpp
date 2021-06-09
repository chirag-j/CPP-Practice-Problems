int maxHeight = 0;
int findDepth(Node* root, int height){
    if(root == nullptr){
        return height;
    }
    height++;
    maxHeight = max(maxHeight, height);
    for(auto child : root->children){
        findDepth(child, height);
    }
    return height;
}