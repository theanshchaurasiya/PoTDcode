class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            if (count == depth - 1)
                break;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left != NULL)
                    q.push(front->left);
                if (front->right != NULL)
                    q.push(front->right);
            }
            count++;
        }
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            TreeNode* newLeft = new TreeNode(val);
            newLeft->left = front->left;
            front->left = newLeft;
            TreeNode* newRight = new TreeNode(val);
            newRight->right = front->right;
            front->right = newRight;
        }
        return root;
    }
};