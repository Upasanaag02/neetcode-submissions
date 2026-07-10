class Solution {
public:
    vector<string>ans;
    string curr;
    void dfs(int open,int close,int n){
        if(curr.size()==2*n){
            ans.push_back(curr);
        }
        if(open<n){
            curr.push_back('(');
            dfs(open+1,close,n);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            dfs(open,close+1,n);
            curr.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return ans;
    }
};
