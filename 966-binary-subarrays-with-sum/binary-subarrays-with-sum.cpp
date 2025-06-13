class Solution {
public:
    int helper(vector<int>& nums, int goal){
        //two pointer
        if(goal<0) return 0;
        int l=0,n=nums.size(),sum=0,res=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            res+=(r-l+1);
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal) - helper(nums,goal-1);
    }
};