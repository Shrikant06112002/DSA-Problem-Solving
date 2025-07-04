class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = 0;
        for(int i=1;i<nums.size();i++){
            res = max(res,abs(nums[i]-nums[i-1]));
        }
        res = max(res,abs(nums[0]-nums[nums.size()-1]));
        return res;
    }
};