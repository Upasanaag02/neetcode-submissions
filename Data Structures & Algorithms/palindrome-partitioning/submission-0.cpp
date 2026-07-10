class Solution {
public:
    vector<vector<string>>ans;
    vector<string>partitions ;
    bool isPalindrome(string s){
            int left=0;
            int right=s.size()-1;
            while(left<=right){
                if(s[left]!=s[right]){
                     return false;
                }
                left++;
                right--;
            }
            return true;
        }
    void dfs(string s){
         if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);

            if(isPalindrome(part)){
                partitions.push_back(part);
                dfs(s.substr(i+1));
                partitions.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        dfs(s);
        return ans;
    }
};
