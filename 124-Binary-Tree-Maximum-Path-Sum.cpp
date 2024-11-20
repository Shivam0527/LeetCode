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
    int maxSumFinder(TreeNode* root, int& maxi) {
        if(!root) 
            return 0;

        int leftSum = max(0, maxSumFinder(root->left, maxi));
        int rightSum = max(0, maxSumFinder(root->right, maxi));

        int newSum = root->val + leftSum + rightSum;

        maxi = max(newSum, maxi);

        return max(leftSum, rightSum) + root->val;
    }
    int maxPathSum(TreeNode* root) {

        int maxi = -1e9;

        maxSumFinder(root, maxi);

        return maxi;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
