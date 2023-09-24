class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        if(maxHeights.size()==1){
            return maxHeights[0];
        }
        if(maxHeights.size()==2){
            return maxHeights[0]+maxHeights[1];
        }
        vector<int> maxHeights1 = maxHeights;
        int n = maxHeights.size();
        long long ans = 0;
        if(maxHeights1[0]>=maxHeights1[1]){
            long long sum = maxHeights1[0]+maxHeights1[1];
        for(int i = 2; i < maxHeights1.size(); i++){
            if(maxHeights1[i]<=maxHeights1[i-1]){
                sum+=maxHeights1[i];
            }else{
                maxHeights1[i]=maxHeights1[i-1];
                sum+=maxHeights1[i];
            }
        }
            ans = max(ans, sum);
            
        }
        
        maxHeights1=maxHeights;
        
        if(maxHeights1[n-1]>=maxHeights1[n-2]){
            long long sum = maxHeights1[n-1]+maxHeights1[n-2];
            for(int i = n-3; i >= 0; i--){
            if(maxHeights1[i]<=maxHeights1[i+1]){
                sum+=maxHeights1[i];
            }else{
                maxHeights1[i]=maxHeights1[i+1];
                sum+=maxHeights1[i];
            }
                ans = max(ans, sum);
            }
        }
        
        maxHeights1=maxHeights;
        
        for(int i = 1; i < n-1; i++){
            if(maxHeights1[i]>=maxHeights1[i-1] && maxHeights1[i]>=maxHeights1[i+1]){
                long long sum = maxHeights1[i] + maxHeights1[i-1];
            for(int j = i-2; j >= 0; j--){
            if(maxHeights1[j]<=maxHeights1[j+1]){
                sum+=maxHeights1[j];
            }else{
                maxHeights1[j]=maxHeights1[j+1];
                sum+=maxHeights1[j];
            }
            }
                sum+=maxHeights1[i+1];
            for(int j = i+2; j < maxHeights1.size(); j++){
            if(maxHeights1[j]<=maxHeights1[j-1]){
                sum+=maxHeights1[j];
            }else{
                maxHeights1[j]=maxHeights1[j-1];
                sum+=maxHeights1[j];
            }
        }  
                ans = max(sum, ans);
                maxHeights1=maxHeights;
            }
        }
        
        return ans;
        
    }
};
