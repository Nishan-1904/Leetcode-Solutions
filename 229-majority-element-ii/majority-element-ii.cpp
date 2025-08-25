class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            if(it->second > n/3){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};