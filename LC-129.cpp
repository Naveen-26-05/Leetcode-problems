#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void getPaths(TreeNode* root, vector<int>& v, int count) {
        if (!root->left && !root->right) {
            v.push_back(count * 10 + root->val);
            return;
        }
        if (root->left) {
            getPaths(root->left, v, count * 10 + root->val);
        }
        if (root->right) {
            getPaths(root->right, v, count * 10 + root->val);
        }
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        vector<int> v;
        getPaths(root, v, 0);
        int sum = 0;
        for (auto i : v) {
            sum += i;
        }
        return sum;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution solution;
    int result = solution.sumNumbers(root);
    cout << "Sum of numbers formed by paths: " << result << endl;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
