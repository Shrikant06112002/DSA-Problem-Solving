class Solution {
public:
    int longestSubsequence(string s, int k) {
        bool stop = false;
        int i= s.length()-1,res=0,val=0,j=0;
        for( ;i>=0;i--){
            if(s[i]=='0'){
                res++;
            }else if(!stop && j<31){
                val+=pow(2,j);
                if(k<val){
                    stop=true;
                }else{
                    res++;
                }
            }
            j++;
        }
        return res;
    }
};