class Solution {
public:
    int helpher(vector<int>& nums, int k){
        unordered_map<int,int> map;
        int l=0,res=0;
        for(int r=0;r<nums.size();r++){
            map[nums[r]]++;
            while(map.size()>k){
                map[nums[l]]--;
                if(map[nums[l]]==0){
                    map.erase(nums[l]);
                }
                l++;
            }
            res+=r-l+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helpher(nums,k) - helpher(nums,k-1);
    }
};