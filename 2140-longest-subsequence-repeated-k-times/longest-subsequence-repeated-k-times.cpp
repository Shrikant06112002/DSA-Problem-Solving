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
        vector<int> freq(26);
        for(auto x:s) freq[x-'a']++;
        for(int i=0;i<26;i++){
            if(freq[i]<k){
                freq[i]=0;
            }
            else {
                freq[i]/=k;
            }
        }
        que.push("");
        string curr="";
        string temp="";
        while(!que.empty()){
            curr=que.front(); que.pop();
            for(int i=25;i>=0;i--){
                char c = i+'a';
                temp=curr+c;
                if(isExits(temp,s,k)){
                    que.push(temp);
                    if(ans.size()<temp.size()){
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};