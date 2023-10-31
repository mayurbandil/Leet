class Solution {
public:
    vector<int> nsr(vector<int>& nums){
      vector<int> ans;
      stack<pair<int, int>> st;
      for(int i = nums.size()-1; i >= 0; i--){
          while(!st.empty() && st.top().first>=nums[i]){
              st.pop();
          }

          if(st.empty()){
              ans.push_back(-1);
          }else{
              ans.push_back(st.top().second);
          }

          st.push({nums[i], i});
      }
    reverse(ans.begin(), ans.end());
      return ans;
    }
        vector<int> nsl(vector<int>& nums){
      vector<int> ans;
      stack<pair<int, int>> st;
      for(int i = 0; i < nums.size(); i++){
          while(!st.empty() && st.top().first>=nums[i]){
              st.pop();
          }

          if(st.empty()){
              ans.push_back(-1);
          }else{
              ans.push_back(st.top().second);
          }

          st.push({nums[i], i});
      }
      return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr1 = nsr(heights);
        vector<int> nsl1 = nsl(heights);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nsr1[i]==-1 && nsl1[i]==-1){
                ans = max(ans, heights[i]*n);
            }else if(nsr1[i]==-1 && nsl1[i] != -1){
                ans = max(ans, heights[i]*(n-nsl1[i]-1));
            }else if(nsr1[i]!=-1 && nsl1[i]==-1){
                ans = max(ans, heights[i]*(nsr1[i]));
            }else{
                ans = max(ans, heights[i]*(nsr1[i]-nsl1[i]-1));
            }
        }

        return ans;
    }
};