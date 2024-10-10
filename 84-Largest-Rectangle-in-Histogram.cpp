class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};

const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();