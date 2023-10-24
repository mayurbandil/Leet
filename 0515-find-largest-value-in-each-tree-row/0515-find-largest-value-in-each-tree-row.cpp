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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        int maxi = INT_MIN;
        while(!q.empty()){
            TreeNode* curr = q.front();
            if(curr == NULL){
            q.pop();
               ans.push_back(maxi);
               maxi = INT_MIN;
               if(q.empty()){
                   break;
               }
               q.push(NULL);
            }else if(curr != NULL){
                maxi = max(maxi, curr->val);
                if(curr->left != NULL){
                    q.push(curr->left);

                } if(curr->right != NULL){
                    q.push(curr->right);    
                }
                q.pop();
            }
        }

        return ans;
    }
};