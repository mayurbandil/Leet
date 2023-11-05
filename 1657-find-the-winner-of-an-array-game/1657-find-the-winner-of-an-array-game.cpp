class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k > arr.size()){
            return *max_element(arr.begin(), arr.end());
        }
        deque<int> dq;
        for(auto i : arr){
            dq.push_back(i);
        }
        int cons = 0;
        int prev = -1;
        while(cons<k){
            int f = dq.front();
            dq.pop_front();
            int s = dq.front();
            dq.pop_front();
            if(f>s){
                int curr = f;
                dq.push_front(f);
                dq.push_back(s);
                if(prev==-1 || curr == prev){
                   cons++;
                   prev = curr;
                }else if(prev != curr){
                   cons = 0;
                   prev = curr;
                }
            }else{
                int curr = s;
                dq.push_front(s);
                dq.push_back(f);
                if(prev==-1 || curr == prev){
                   cons++;
                   prev = curr;
                }else if(prev != curr){
                   cons = 0;
                   cons++;
                   prev = curr;
                }
            }
        }

return prev;
    }
};