class Solution {
public:
    long long solve(string text, string pattern){
        long long cnt = 0;
        long long ans = 0;
        for(auto i : text){
            if(i==pattern[0]){
                cnt++;
            }else if(i==pattern[1]){
                ans+=cnt;
            }
            
        }

        return ans;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        if(pattern[0]==pattern[1]){
            string temp = text;
            temp = pattern[0]+temp;
            long long cnt = 0;
            for(auto i : temp){
                if(i==pattern[0]){
                    cnt++;
                }
            }
            return (cnt*(cnt-1))/2;

        }
        string t1 = pattern[0]+text;
        string t2 = text+pattern[1];

        return max(solve(t1, pattern), solve(t2, pattern));
    }
};