class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> u;
        int n = s.length();
        int r=0;
        int maxFreq = 0;
        int windowSize = 0;
        int res=0;
        for(int l=0;l<n;l++){
            u[s[l]]++;
            maxFreq = max(maxFreq,u[s[l]]);
            while((l-r+1) - maxFreq > k){
                u[s[r]]--;
                r++;
            }
            res = max(res,l-r+1);
        }
        return res;
    }
};