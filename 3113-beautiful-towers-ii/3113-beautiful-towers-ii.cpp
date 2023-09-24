class Solution {
public:
    void find(vector<int> nums, vector<long long> &ans){
        stack<pair<long long, int>> P;
        for(int i = 0; i < nums.size(); i++){
           if(i==0){
             ans[i]=nums[i];
             P.push({ans[i], i});
           }
           else{

           while(P.top().first >nums[i]){
               P.pop();
               if(P.empty()){
                   break;
               }
           }

           if(P.empty()){
               ans[i]=nums[i];
               long long z = i;
               z++;
               ans[i]*=z;
           }else{
               ans[i]=ans[P.top().second];
               long long z = (i-P.top().second);
               long long val = nums[i];
               val*=z;
               ans[i]+=val;
           }
           }

           P.push({nums[i], i});
        }
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long>pref(n),suff(n);
        
        
        find(maxHeights,pref);
        reverse(maxHeights.begin(),maxHeights.end());
        find(maxHeights,suff);
        reverse(suff.begin(),suff.end());
        reverse(maxHeights.begin(),maxHeights.end());
        
        long long ans1 = 0;
        for(int i=0;i<n;++i){
            
            long long val = maxHeights[i];
            val = (pref[i] + suff[i])-val;
            ans1 = max(ans1,val);
        }
        
        
        return ans1;
    }
};