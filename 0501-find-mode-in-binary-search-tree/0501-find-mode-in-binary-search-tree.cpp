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

    void solve(TreeNode* root, map<int, int> &mapp)
    {
        if(root == NULL){
            return;
        }

        mapp[root->val]++;
        solve(root->left, mapp);
        solve(root->right, mapp);

        return;
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int> mapp;
        vector<int> ans;
        solve(root, mapp);
        int maxf = 0;
        for(auto i : mapp){
            maxf = max(maxf, i.second);
        }

        for(auto i : mapp){
            if(maxf == i.second){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};