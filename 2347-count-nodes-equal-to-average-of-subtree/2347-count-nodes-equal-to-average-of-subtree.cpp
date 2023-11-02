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

    int findSum(TreeNode* root, int &count){
        if(root == NULL){
            return 0;
        }
        count++;
        int left = findSum(root->left, count);
        int right = findSum(root->right, count);
        return root->val+left+right;
    }
    void solve(TreeNode* root, int &res){
        if(root == NULL){
            return;
        }
        int count = 0;
        int sum = findSum(root, count);
        if(sum/count == root->val){
            res++;
        }

        solve(root->left, res);
        solve(root->right, res);
    }
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};