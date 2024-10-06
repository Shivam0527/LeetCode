class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;

        for (int i = 0; i < operations.size(); i++) {
            int j = 0;
            if (operations[i][j] == '-') j++;
            if (isdigit(operations[i][j])) {
                ans.push_back(stoi(operations[i]));
            } else if (operations[i] == \C\) {
                ans.pop_back();
            } else if (operations[i] == \D\) {
                int temp = ans.back();
                ans.push_back(temp * 2);
            } else if (operations[i] == \+\) {
                int num1 = ans.back();
                int num2 = ans[ans.size() - 2]; 
                ans.push_back(num1 + num2);
            }
        }

        int sum = 0;
        for (auto it : ans) sum += it;

        return sum;
    }
};
