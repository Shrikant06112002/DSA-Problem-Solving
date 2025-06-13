class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k<0) return 0;
        int l=0,cnt=0,res=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2!=0) cnt++;
            while(cnt>k){
                if(nums[l]%2!=0) cnt--;
                l++;
            }
            res+=(r-l+1);
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};