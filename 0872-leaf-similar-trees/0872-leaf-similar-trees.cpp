class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        deque<int> leaves;
        bool ans = 1;
        
        function<void(TreeNode*, bool)> traverse = [&](TreeNode * node, bool push) {
            if(!node)
                return;
            
            if(!(node -> left) and !(node -> right)){
                if(push){
                    leaves.push_back(node -> val);
                }
                else{
                    if(leaves.empty() or node -> val != leaves.front())
                        ans = 0;
                    
                    if(!leaves.empty())
                        leaves.pop_front();
                }
            }
            
            traverse(node -> left, push);
            traverse(node -> right, push);
        };
        
        traverse(root1, 1);
        traverse(root2, 0);
        
        return (ans and leaves.empty());
    }
};