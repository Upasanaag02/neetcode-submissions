class Solution {
public:
    bool isPalindrome(string s) {
        string new_1="";
        for(auto it:s){
            if(isalnum(it)){
                new_1+=tolower(it);
            }
        }
        int l=0;
        int r=new_1.size()-1;
        while(l<=r){
            if(new_1[l]!=new_1[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
