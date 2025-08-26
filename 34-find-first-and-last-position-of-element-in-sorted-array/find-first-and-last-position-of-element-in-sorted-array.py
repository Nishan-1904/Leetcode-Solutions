class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        x = []
        if target in nums:
            #x=nums.index(target)
            # nums.sort(reverse=True)
            x=[]
            for i in range(len(nums)):
                if target==nums[i]:
                    x.append(i)
                else:
                    pass
            return [x[0],x[len(x)-1]]
        else:
            return [-1,-1]

        
        