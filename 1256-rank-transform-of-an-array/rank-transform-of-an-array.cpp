class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        unordered_map<int,int> mpp;
        int rank = 1;
        while(!pq.empty()){
            int top = pq.top();
            mpp[top]=rank;
            pq.pop();
            if(top!=pq.top()){
                rank++;
            }
        }
        for(int i=0;i<arr.size();i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};