class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto s:tokens){
            if(s=="*" || s=="+" ||s=="-" ||s=="/"){
                int num1=(st.top());
                st.pop();
                int num2=(st.top());
                st.pop();
                int value;
                if(s=="+") value=num1+num2;
                else if(s=="-") value=num2-num1;
                else if(s=="*")value=num1*num2;
                else  if(s=="/") value=num2/num1;
                st.push((value));
            }
            else{
                
                st.push(stoi(s));
            }
        }
        int ans=(st.top());
        return ans;
    }
};
