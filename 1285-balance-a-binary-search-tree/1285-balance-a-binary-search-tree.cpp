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
    void inor(vector<TreeNode*> &ans, TreeNode* root){
        if(root == NULL){
            return;
        }

        inor(ans, root->left);
        ans.push_back(root);
        inor(ans, root->right);
    }
    TreeNode* bt(vector<TreeNode*> &ans, int s, int e){
        if(s>e){
            return NULL;
        }

        int mid = (e+s)/2;
        TreeNode* root = ans[mid];
        root->left = bt(ans, s, mid-1);
        root->right = bt(ans, mid+1, e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        vector<TreeNode*> ans;
        inor(ans, root);
        return bt(ans, 0, ans.size()-1);
    }
};