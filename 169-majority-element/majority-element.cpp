class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele;
        int freq=0;
        for(int i=0;i<n;i++){
            if(freq==0){
                ele = nums[i];
                freq=1;
            } 
            else{
                if(nums[i]==ele) freq++;
                else freq--;
            }
        }
        return ele;
    }
};