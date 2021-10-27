map<int, int> hdd;
void dfs(Node *root, int hd){
    hdd[hd] += root->data;
    if(root->left != NULL){
        dfs(root->left, hd-1);
    }
    if(root->right != NULL){
        dfs(root->right, hd+1);
    }
}
    

class Solution{
  public:
    
    vector <int> verticalSum(Node *root) {
        hdd.clear();
        vector<int> res;
        dfs(root, 0);
        for(auto &i:hdd){
            res.push_back(i.second);
        }
        return res;
        // add code here.
    }
};