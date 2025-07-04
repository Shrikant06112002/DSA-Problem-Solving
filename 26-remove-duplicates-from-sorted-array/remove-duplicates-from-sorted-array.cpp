class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left{};
        for(int right=1;right<nums.size();right++){
            if(nums[left]!=nums[right]){
                left++;
                nums[left]=nums[right];
            }
        }
        return ++left;

    }
};