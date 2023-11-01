class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(auto i : tokens){
            if(i=="+"){
               int op2 = st.top();
               st.pop();
               int op1 = st.top();
               st.pop();
               int res = op1+op2;
               st.push(res);
            }
            else if(i=="-"){
               int op2 = st.top();
               st.pop();
               int op1 = st.top();
               st.pop();
               int res = op1-op2;
               st.push(res);
            }
            else if(i=="*"){
               int op2 = st.top();
               st.pop();
               int op1 = st.top();
               st.pop();
               int res = op1*op2;
               st.push(res);
            }
            else if(i=="/"){
               int op2 = st.top();
               st.pop();
               int op1 = st.top();
               st.pop();
               int res = op1/op2;
               st.push(res);
            }else{
               int x = stoi(i);
               st.push(x);
            }
        }

        return st.top();
    }
};