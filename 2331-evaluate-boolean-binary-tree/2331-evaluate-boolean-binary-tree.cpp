class Solution {
public:
    int calc(TreeNode* root,int value){
        if(root==NULL){
            return value;
        }
        if(root->val==1){
            value=1;
        }
        else if(root->val==0){
            value=0;
        }
        int left=calc(root->left,value);
        int right=calc(root->right,value);
        if(root->val==2){
            value=left|right;
        }
        else{
            value=left&right;
        }
        return value;
    }


    bool evaluateTree(TreeNode* root) {
        int x=calc(root,0);
        return x==1;
    }
};
