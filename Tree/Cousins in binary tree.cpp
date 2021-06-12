#include<iostream>
#include<vector>
#include<queue>

// depth_qu stores the depth of respective node on the bfs queue


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> qu;
        queue<int> depth_qu;
        if(root==nullptr){return false;}
        int depth = 0;
        qu.push(root);
        depth_qu.push(depth);
        int xp_val=0, yp_val=0, xd=0, yd=0;

        if(root->val == x || root->val == y){return false;}

        while(qu.size()!=0){
            depth = depth_qu.front() +1;
            for(auto child : {qu.front()->left, qu.front()->right}){
                if(child!=nullptr){
                    if(child->val == x){
                        xd = depth;
                        xp_val = qu.front()->val;
                        if(yd){break;}
                    }
                    else if(child->val == y){
                        yd = depth;
                        yp_val = qu.front()->val;
                        if(xd){break;}
                    }
                    cout<<child->val<<" "<<depth<<endl;
                    qu.push(child);
                    depth_qu.push(depth);
                }
            }
            qu.pop();
            depth_qu.pop();
        }
        if(xd == yd){
            if(xp_val!=yp_val){
                return true;
            }
        }
        return false;
    }
};