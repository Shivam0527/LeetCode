class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        
        for (int i = 0; i < indices.size(); i++) {
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }

        int oddCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((row[i] + col[j]) % 2 != 0) {
                    oddCount++;
                }
            }
        }

        return oddCount;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
