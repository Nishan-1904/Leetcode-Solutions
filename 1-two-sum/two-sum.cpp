class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map <int,int> result;
        vector <int> v;
        for(int i=0;i<n;i++){
            int current = nums[i];
            int more = target - current;
            if(result.find(more)!= result.end()){
                v.push_back(i);
                v.push_back(result[more]);
            }
            else 
            result[current]=i;
        }
        return v;
    }
};