class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> zeroes;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }
        }
        int k = zeroes.size();
        for(int i=0;i<k;i++){
            int r = zeroes[i].first;
            int c = zeroes[i].second;
            for(int i=0;i<n;i++){
                matrix[i][c]=0;
            }
            for(int i=0;i<m;i++){
                matrix[r][i]=0;
            }
        }
    }
};