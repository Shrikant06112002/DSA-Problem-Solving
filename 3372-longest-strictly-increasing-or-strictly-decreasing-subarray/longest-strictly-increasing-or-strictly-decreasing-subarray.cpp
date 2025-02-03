class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // int j=0,k=0,n=nums.size(),maxL=0;
        // for(int i=0;i<n;i++){
        //     j=i;
        //     k=i;
        //     while(j<n-1 && nums[j]<nums[j+1]){
        //         j++;
        //     }
        //     while(k<n-1 && nums[k]>nums[k+1]){
        //         k++;
        //     }
        //     maxL = max(max(k-i,j-i)+1,maxL);
        // }
        // return maxL;
        if(nums.empty()) return 0;
        int j=1,k=1,n=nums.size(),maxL=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                j++;
                k=1;
            }else if(nums[i]<nums[i-1]){
                k++;
                j=1;
            }else{
                k=1;
                j=1;
            }
            maxL=max(max(k,j),maxL);
        }
        return maxL;

    }
};