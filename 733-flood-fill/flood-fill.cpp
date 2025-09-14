class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        int initial = image[sr][sc];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){                
                image[sr][sc]=color;
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && image[nrow][ncol]==initial && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return image;
    }
};