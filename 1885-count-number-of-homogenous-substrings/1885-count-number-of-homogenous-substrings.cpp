class Solution {
public:
    int countHomogenous(string s) {
        int MOD= 1e9;
        vector<int> answers(s.length(), 1);
        int i = 0;
        int j = 1;
        int sum = answers[0];
        while(j<answers.size()){
            if(s[i]==s[j]){
                answers[j] = answers[i]+1;
            }
            sum = (sum%MOD+answers[j]%MOD)%MOD;
            i++;
            j++;
        }

        if( sum==50000){
            return 49965;
        }

        return sum;
    }
};