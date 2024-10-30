/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traversal(vector<int>& ans, Node* root) {
        if(!root)
            return;

        ans.push_back(root->val);

        for(auto child : root->children) {
            traversal(ans, child);
        }
    }
    vector<int> preorder(Node* root) {

        vector<int> ans;

        traversal(ans, root);

        return ans;      
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
