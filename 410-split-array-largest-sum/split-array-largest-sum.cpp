class Solution {
public:
    int allocate_k(vector<int>& nums,int sum,int k){
        int start = 1;
        long long total_sum=0;
        for(int i=0;i<nums.size();i++){
            if(total_sum+nums[i]>sum){
                start+=1;
                total_sum = nums[i];
            }
            else{
                total_sum += nums[i];
            }
        }
        return start;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int count_k = allocate_k(nums,mid,k);
            if(count_k>k) low=mid+1;
            else high = mid-1;
        }
        return low;
    }
};