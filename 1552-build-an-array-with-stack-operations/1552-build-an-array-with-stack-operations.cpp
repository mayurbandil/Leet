class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        int i = 0;
        int j = 1; 
        while(i<target.size()){
            st.push(j);
            ans.push_back("Push");
            if(st.top()!=target[i]){
                st.pop();
                ans.push_back("Pop");
            }else{
                i++;
            }
            j++;
        }

        return ans;
    }
};