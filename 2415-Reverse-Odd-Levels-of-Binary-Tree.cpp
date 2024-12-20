/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *right;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        if(!root)
            return root;

        queue<TreeNode*> q;

        q.push(root);
        int cnt = 1;

        while(!q.empty()) {
            int n = q.size();
            cnt++;

            vector<TreeNode*> tempVec;

            for(int i=0; i<n; i++) {

                TreeNode* temp = q.front();
                q.pop();

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);

                tempVec.push_back(temp);
            }

            if(cnt%2 == 1) {
                int left = 0;
                int right = tempVec.size() - 1;

                while(left < right) {
                    int tempVal = tempVec[left]->val;
                    tempVec[left]->val = tempVec[right]->val;
                    tempVec[right]->val = tempVal;

                    left++;
                    right--;
                }
            }
        }

        return root;       
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
