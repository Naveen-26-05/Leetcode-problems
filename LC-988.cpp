#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

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
    
    void findPath(TreeNode* root, priority_queue<string,vector<string>,greater<string>>& pq, string s) {
        if (!root)
            return;
        string temp ="";
        if (!root->left && !root->right) {
            temp = 'a' + root->val;
            s = temp + s;
            pq.push(s);
            s.clear();
            temp.clear();
            return;
        }
        temp = 'a' + root->val;
        s = temp + s;
        temp.clear();
        findPath(root->left, pq, s);
        findPath(root->right, pq, s);
        return;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if (!root)
            return "";
        priority_queue<string,vector<string>,greater<string>> pq;
        findPath(root, pq, "");
        return pq.top();
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution solution;
    string result = solution.smallestFromLeaf(root);
    cout << "Smallest string from leaf: " << result << endl;

    // Freeing memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
