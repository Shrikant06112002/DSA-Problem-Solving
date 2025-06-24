class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> f;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                f.push_back(i);
            }            
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<f.size();j++){
                if(abs(i-f[j])<=k){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};