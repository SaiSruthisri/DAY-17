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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(root==nullptr)
        {
            return ans;
        }
        q.push(root);

        while(!q.empty())
        {

            int size =q.size();
            vector<int>level;
            for(int i=0;i<size ;i++)
            {
                TreeNode* temp= q.front();
                level.push_back(temp->val);
                q.pop();
                if(temp->left !=NULL)q.push(temp->left);
                if(temp->right !=NULL)q.push(temp->right);

            }
            reverse(level.begin(),level.end());
            ans.push_back(level[0]);

        }
        return ans;
    }
};
