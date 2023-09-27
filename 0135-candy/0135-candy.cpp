class Solution {
public:
vector<int> solve(vector<int> ratings){
    int n =  ratings.size();
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i]>ratings[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        return ans;
}
    int candy(vector<int>& ratings) {
        vector<int> ansl= solve(ratings);
        reverse(ratings.begin(), ratings.end());
        vector<int> ansr=solve(ratings);
        reverse(ansr.begin(), ansr.end());
        int sum = 0;
        for(int i = 0; i < ansl.size(); i++){
            sum+=max(ansl[i], ansr[i]);
        }
        return sum;
    }
};