/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
    map<TreeNode*, TreeNode*> parents;
        map<TreeNode*, int> vis;

        queue<TreeNode*> q;
        q.push(root);

        parents[root] = NULL;
        vis[root] = 0;

        TreeNode* starting_node;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* top = q.front();
                q.pop();

                if(top->val == start){
                    starting_node = top;
                }

                vis[top] = 0;

                if(top->left){
                    parents[top->left] = top;
                    q.push(top->left);
                }
                if(top->right){
                    parents[top->right] = top;
                    q.push(top->right);
                }
            }
        }

        while(!q.empty()){
            q.pop();
        }

        q.push(starting_node);

        int cnt = -1;

        while(!q.empty()){
            int size = q.size();
            cnt++;
            while(size--){
                TreeNode* top = q.front();
                q.pop();

                vis[top] = 1;

                if(top->left && vis[top->left] == 0){
                    q.push(top->left);
                }

                if(top->right && vis[top->right] == 0){
                    q.push(top->right);
                }

                if(parents[top] && vis[parents[top]] == 0){
                    q.push(parents[top]);
                }
            }
        }

        return cnt;
    }
};