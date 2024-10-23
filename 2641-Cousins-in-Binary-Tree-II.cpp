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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        if(!root) return root;

        queue<TreeNode*> que;
        que.push(root);

        int nextLevelSum = root->val;

        while(!que.empty()) {

            int n = que.size();
            int calNextLevelSum = 0;

            while(n > 0) {

                TreeNode* temp = que.front();
                que.pop();

                temp->val = nextLevelSum - temp->val;

                int siblingSum = temp->left != NULL ? temp->left->val : 0;
                siblingSum += temp->right != NULL ? temp->right->val : 0;

                if(temp->left) {
                    calNextLevelSum += temp->left->val;
                    temp->left->val = siblingSum;
                    que.push(temp->left);
                }        
                        
                if(temp->right) {
                    calNextLevelSum += temp->right->val;
                    temp->right->val = siblingSum;
                    que.push(temp->right);
                }

                n--;
            }

            nextLevelSum = calNextLevelSum;
        }

        return root;
    }
};


//Code with Two pass Solution TC --> O(2N) and SC --> O(N)

// class Solution {
// public:
//     TreeNode* replaceValueInTree(TreeNode* root) {
        
//         if(!root) return root;

//         queue<TreeNode*> que;
//         vector<long long> levelSum;

//         que.push(root);

//         while(!que.empty()) {

//             int n = que.size();
//             long long sum = 0;

//             while(n > 0) {
//                 TreeNode* temp = que.front();

//                 que.pop();
//                 sum += temp->val;

//                 if(temp->left) que.push(temp->left);
//                 if(temp->right) que.push(temp->right);

//                 n--;
//             }

//             levelSum.push_back(sum);
//         }

//         que.push(root);

//         root->val = 0;
//         int i = 1;

//         while(!que.empty()) {

//             int n = que.size();

//             while(n > 0) {
//                 TreeNode* temp = que.front();
//                 que.pop();

//                 long long siblingSum = temp->left != NULL ? temp->left->val : 0;
//                 siblingSum += temp->right != NULL ? temp->right->val : 0;

//                 if(temp->left) {
//                     temp->left->val = levelSum[i] - siblingSum;
//                     que.push(temp->left);
//                 }
//                 if(temp->right) {
//                     temp->right->val = levelSum[i] - siblingSum;
//                     que.push(temp->right);
//                 }

//                 n--;
//             }

//             i++;
//         }

//         return root;        
//     }
// };
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
