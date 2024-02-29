class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0; // 0---->even level, 1---->odd level
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while (!pendingNodes.empty()) {
            int size = pendingNodes.size();
            int lastValue;
            if (level == 1) {
                lastValue = INT_MAX;
            } else
                lastValue = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                if (level == 1 &&
                    ((front->val % 2) == 1 || (front->val) >= lastValue))
                    return false;
                if (level == 0 &&
                    ((front->val % 2) == 0 || (front->val) <= lastValue))
                    return false;
                lastValue = front->val;
                if (front->left)
                    pendingNodes.push(front->left);
                if (front->right)
                    pendingNodes.push(front->right);
            }
            level = !level;
        }
        return true;
    }
};