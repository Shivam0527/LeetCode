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
    int miniSwap(vector<int>& tempVec) {

        vector<int> sortedVec = tempVec;
        sort(sortedVec.begin(), sortedVec.end());

        int cnt = 0;

        unordered_map<int, int> mpp;
        for(int i=0; i<tempVec.size(); i++) 
            mpp[tempVec[i]] = i;

        for(int i=0; i<sortedVec.size(); i++) {
            if(tempVec[i] != sortedVec[i]) {
                cnt++;
                int currPos = mpp[sortedVec[i]];
                mpp[tempVec[i]] = currPos;
                swap(tempVec[currPos], tempVec[i]);
            }
        }

        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        int cnt = 0;
        if(!root)
            return cnt;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> tempVec;

            for(int i=0; i<n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                tempVec.push_back(temp->val);

                if(temp->left)
                    q.push(temp->left);
                if(temp->right) 
                    q.push(temp->right);
            }

            cnt += miniSwap(tempVec);
        }

        return cnt;        
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
