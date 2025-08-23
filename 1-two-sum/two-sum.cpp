class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int diff = target-nums[i];
            if(mpp.find(diff)!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[diff]);
                break;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};