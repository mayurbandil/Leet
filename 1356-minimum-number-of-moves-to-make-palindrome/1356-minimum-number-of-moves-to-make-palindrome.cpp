class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        int ans = 0;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                int k = j;
                while(s[k]!=s[i] && k!=i){k--;}
                if(k==i){
                    ans++;
                    swap(s[i], s[i+1]);
                }else{
                    while(k<j){
                        swap(s[k], s[k+1]);
                        k++;
                        ans++;
                    }
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};