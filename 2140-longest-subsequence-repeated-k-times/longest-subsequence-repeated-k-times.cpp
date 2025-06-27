class Solution {
public:
    bool isExits(string &temp,string &s,int k){
        string curr="";
        while(k--) curr+=temp;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==curr[j]){
                j++;
            }
            if(curr.size()==j){
                break;
            }
        }
        return curr.size()==j;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        //brute force
        //permutation of all combinarion
        string ans="";
        queue<string> que;
        que.push("");
        string curr="";
        string temp="";
        while(!que.empty()){
            curr=que.front(); que.pop();
            for(char c='a';c<='z';c++){
                temp=curr+c;
                if(isExits(temp,s,k)){
                    que.push(temp);
                    if(ans.size()<=temp.size() || temp > ans){
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};