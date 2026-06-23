class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto str:s){
              if(str=='(' ||str=='['||str=='{'){
                st.push(str);
              }
              else{
                if(st.empty()){
                    return false;
                }
                
                else{
                    char last=st.top();
                    st.pop();
                    if((str==')' && last!='(')||(str==']' && last!='[')||(str=='}' && last!='{')){
                           return false;
                    }
                }
              }
        }
        return st.empty();
    }
};
