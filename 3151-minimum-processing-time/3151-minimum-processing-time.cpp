class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end());
        reverse(processorTime.begin(), processorTime.end());
        int ans = 0;
        int pi = 0;
        for(int i = 0; i < tasks.size(); i++){
              ans = max(ans, tasks[i]+processorTime[pi]);
              if(pi<processorTime.size() && (i+1)%4==0){
                pi++;
              }

        }

        return ans;

    }
};