class Solution {
public:
    int solve(TreeNode* root, int &ans)
    {
        if(!root)
        {
            return 0;
        }
        int left= solve(root->left,ans);
        int right=solve(root->right,ans);

        ans+=abs(left) + abs(right);

        return (left+right+root->val-1);

    }
    int distributeCoins(TreeNode* root) {
        int ans=0;

        int coints= solve(root,ans);

        return ans;
    }
};