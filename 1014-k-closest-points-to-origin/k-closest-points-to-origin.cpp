class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxH;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();++i){
            int x = points[i][0];
            int y = points[i][1];
            int squared_dist = x * x + y * y;

            maxH.push({squared_dist, i});
            if(maxH.size()>k){
                maxH.pop();
            }
        }
        while (!maxH.empty()) {
            int point_index = maxH.top().second;
            ans.push_back(points[point_index]);
            maxH.pop();
        }
        return ans;
    }
};