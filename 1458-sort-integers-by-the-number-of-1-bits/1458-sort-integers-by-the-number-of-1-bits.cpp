class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh;
        for(auto i : arr){
            int num = i;
            int cnt = 0;
            while(num>0){
              if(num%2==1){
                  cnt++;
              }
              num/=2;
            }
            mh.push({cnt, i});
            
        }

        arr.clear();
        while(!mh.empty()){
            arr.push_back(mh.top().second);
            mh.pop();
        }

        return arr;
        
    }
};