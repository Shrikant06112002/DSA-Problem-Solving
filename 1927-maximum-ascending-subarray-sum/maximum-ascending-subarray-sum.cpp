class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.empty()) return 0;
        int sum = nums[0];
        int maxSum = sum;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }else{
                sum=nums[i];
            }
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
};