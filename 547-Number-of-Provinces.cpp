class Solution {
public:
    void DFS(int v, vector<vector<int>>& isConnected, vector<int>& visited) {        
        visited[v] = 1;

        for(int i=0; i<isConnected[v].size(); i++) {
            if(!visited[i] && isConnected[v][i] != 0)
                DFS(i, isConnected, visited);
        }        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n, 0);
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                cnt++;
                DFS(i, isConnected, visited);
            }
        }

        return cnt;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
