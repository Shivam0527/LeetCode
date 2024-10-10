class Solution {
public:
    int maximumAreaHistogram(vector<int>& heights) {
        int n = heights.size();

        vector<int> leftSmall(n);
        vector<int> rightSmall(n);

        stack<int> st;

        for(int i=0; i<n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                leftSmall[i] = -1;
            }
            else {
                leftSmall[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                rightSmall[i] = n;
            } else {
                rightSmall[i] = st.top();
            }

            st.push(i);
        }

        int maxi=0;

        for(int i=0; i<n; i++) {
            int area = heights[i] * (rightSmall[i] - leftSmall[i] - 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> cumulativeSum(m, 0);

        int maxArea = 0;

        for(int i=0; i<n; i++) {

            for(int j=0; j<m; j++) {

                if(matrix[i][j] == '0') {
                    cumulativeSum[j] = 0;
                } 
                else {
                    cumulativeSum[j] += (matrix[i][j] - '0');
                }
            }

            maxArea = max(maxArea, maximumAreaHistogram(cumulativeSum));
        }

        return maxArea;
    }
};