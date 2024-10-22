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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<long long> pq;

        deque<TreeNode*> dq;

        dq.push_back(root);

        while(dq.size() != 0) {

            int levelSize = dq.size();
            int i=0; 
            long long sum = 0;    

            while(i < levelSize) {
                TreeNode* temp = dq.front();

                sum += temp->val;

                if(temp->left) {
                    dq.push_back(temp->left);
                }
                if(temp->right) {
                    dq.push_back(temp->right);
                }

                i++;
                dq.pop_front();
            }

            pq.push(sum);
        }

        if(pq.size() < k) return -1;   

        while(k > 1) {
            pq.pop();
            k--;
        }     

        return pq.top();
    }
};

const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();