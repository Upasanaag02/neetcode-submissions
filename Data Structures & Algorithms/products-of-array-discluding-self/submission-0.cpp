class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        bool have_zero=false;
        vector<int>ans;
        int count=0;
       for(int i:nums){
            if(i!=0){
                product*=i;
            }
            else{
                have_zero=true;
               count++;
            }
       }
       for(int i:nums){
                if(count>1){
                    ans.push_back(0);
                    continue;
                }
                else if(have_zero && i!=0){
                    ans.push_back(0);
                }
                else if(i!=0){
                    ans.push_back(product/i);
                }
                else{
                    ans.push_back(product);
                }
       }
       return ans;
    }
};
