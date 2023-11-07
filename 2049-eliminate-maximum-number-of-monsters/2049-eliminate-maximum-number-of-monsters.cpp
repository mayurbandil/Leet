class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue <float, vector<float>, greater<float>> pq;

        for(int i = 0; i < dist.size(); i++){
            float time = (float)dist[i]/(float)speed[i];
            pq.push(time);
        }

        float cnt = 0;
        int ans = 0;
        while(!pq.empty()){
            float temp = pq.top();
            pq.pop();
            temp -= cnt;
            if(temp>0){
                ans++;
            }else{
                break;
            }
            cnt++;

        }

        return ans;;
    }
};