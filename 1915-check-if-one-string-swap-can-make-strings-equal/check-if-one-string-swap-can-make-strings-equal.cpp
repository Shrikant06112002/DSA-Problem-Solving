class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        // sort(s1.begin(),s1.end());
        // sort(s2.begin(),s2.end());
        unordered_map<char,int> um1;
        unordered_map<char,int> um2;

        for(char it:s1){
            um1[it]++;
        }
        for(char it:s2){
            um2[it]++;
        }
        if(um1.size()!=um2.size()) return false;
        for(auto it:um1){
            if(!um2.contains(it.first)) return false;
            if(um2[it.first] != it.second) return false;
        }
        // for(char it:s2){
        //     if(us.find(it)==us.end()){
        //         return false;
        //     }else if(us[it])
        // }

        int cnt=0;
        for(int i=0;i<s1.length();++i){
            if(s1[i]!=s2[i] && (!s2.contains(s1[i]) || !s1.contains(s2[i]))) return false;
            if(s1[i]!=s2[i]) cnt++;
            if(cnt>2) return false;
        }
        return true;
    }
};