class Solution {
public:
    void fillMat(vector<vector<int>>& image, vector<vector<int>>& visited, int sr, int sc, int currColor, int color) {

        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
            return;
        if(visited[sr][sc] == 1)
            return;
        if(image[sr][sc] != currColor)
            return;

        visited[sr][sc] = 1;
        image[sr][sc] = color;

        fillMat(image, visited, sr+1, sc, currColor, color);
        fillMat(image, visited, sr, sc+1, currColor, color);
        fillMat(image, visited, sr-1, sc, currColor, color);
        fillMat(image, visited, sr, sc-1, currColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int currColor = image[sr][sc];

        vector<vector<int>> visited(n, vector<int>(m, 0));
        fillMat(image, visited, sr, sc, currColor, color);

        return image;        
    }
};