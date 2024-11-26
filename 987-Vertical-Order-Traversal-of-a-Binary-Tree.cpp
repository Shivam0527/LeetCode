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
    void preOrder(int hor, int ver, TreeNode* root, map<int, vector<pair<int, int>>>& mpp) {
        if(!root)
            return;

        mpp[ver].push_back({hor, root->val});

        preOrder(hor+1, ver-1, root->left, mpp);
        preOrder(hor+1, ver+1, root->right, mpp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mpp;

        preOrder(0, 0, root, mpp);

        vector<vector<int>> ans;

        for(auto it : mpp) {
            sort(it.second.begin(), it.second.end());

            vector<int> temp;
            for(auto idx : it.second) {
                temp.push_back(idx.second);
            }

            ans.push_back(temp);
        }
            

        return ans;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
