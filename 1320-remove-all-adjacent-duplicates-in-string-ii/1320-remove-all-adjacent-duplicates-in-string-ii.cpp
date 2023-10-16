class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        for(auto i : s){
            if(st.size()==0){
                st.push_back({i, 1});
            }else if(st[st.size()-1].first == i){
                st[st.size()-1].second++;
                if(st[st.size()-1].second == k){
                    st.pop_back();
                }
            }else{
                st.push_back({i, 1});
            }
        }

        string ans;
        for(int i = 0; i < st.size(); i++){
            int num = st[i].second;
            char c = st[i].first;
            while(num>0){
                ans.push_back(c);
                num--;
            }
        }

        return ans;
    }
};