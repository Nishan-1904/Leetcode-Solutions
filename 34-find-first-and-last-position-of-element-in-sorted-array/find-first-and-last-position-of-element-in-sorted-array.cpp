class Solution {
public:
    int findFirst(vector<int>& nums,int target,int n){
        int low = 0;
        int high = n-1;
        int mid;
        int res=-1;
        while(low<=high){
            mid = low+((high-low)/2);
            if(nums[mid]==target){
                res=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
    int findLast(vector<int>& nums,int target,int n){
        int low = 0;
        int high = n-1;
        int mid;
        int res=-1;
        while(low<=high){
            mid = low+((high-low)/2);
            if(nums[mid]==target){
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = findFirst(nums,target,n);
        int last = findLast(nums,target,n);
        vector<int> ans = {first,last};
        return ans;
    }
};