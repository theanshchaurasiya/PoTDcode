class Solution {
public:
    void dfs(TreeNode* root, string str, vector<string>& collection) {
        if (root == NULL)
            return;
        str.push_back(char('a' + root->val));
        if (root->left == NULL && root->right == NULL) {
            reverse(str.begin(), str.end());
            collection.push_back(str);
            return;
        }
        dfs(root->left, str, collection);
        dfs(root->right, str, collection);
        str.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string str;
        vector<string> collection;
        dfs(root, str, collection);
        sort(collection.begin(), collection.end());
        return collection[0];
    }
};