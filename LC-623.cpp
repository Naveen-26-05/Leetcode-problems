#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void findDepthMinus1andAddNodes(TreeNode* root, int& val, int cur_depth, int& depth){
        if(root==NULL){
            return;
        }
        if(cur_depth==depth-1){
            root->left=new TreeNode(val,root->left,NULL);
            root->right=new TreeNode(val,NULL,root->right);
            return;
        }
        findDepthMinus1andAddNodes(root->left, val, cur_depth+1, depth);
        findDepthMinus1andAddNodes(root->right, val, cur_depth+1, depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int cur_depth=1;
        if(cur_depth==depth){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        findDepthMinus1andAddNodes(root,val,cur_depth,depth);
        return root;
    }
};

// Sample usage
int main() {
    Solution solution;
    
    // Creating a sample tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);

    // Adding a new row with value 1 at depth 2
    TreeNode* modifiedRoot = solution.addOneRow(root, 1, 2);

    // Output the modified tree
    std::cout << "Modified Tree:" << std::endl;
    std::cout << "   " << modifiedRoot->val << std::endl;
    std::cout << "  / \\" << std::endl;
    std::cout << " " << modifiedRoot->left->val << "   " << modifiedRoot->right->val << std::endl;
    std::cout << "/ \\   /" << std::endl;
    std::cout << modifiedRoot->left->left->val << "  " << modifiedRoot->left->right->val << " " << modifiedRoot->right->left->val << std::endl;

    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right;
    delete root;
    
    return 0;
}
