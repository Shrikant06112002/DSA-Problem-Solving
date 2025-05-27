#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans=0,l=0;
        for(int i=0;i<s.length();i++){
            if(set.find(s[i]) != set.end()){
                while(l<i && set.find(s[i]) != set.end()){
                    set.erase(s[l]);
                    l++;
                }   
            }
            set.insert(s[i]);
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};