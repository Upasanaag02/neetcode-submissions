class Solution {
public:
    vector<int>subset;
    vector<vector<int>>result;
    void dfs(int index,vector<int>nums){
        result.push_back(subset);
        for(int i=index;i<nums.size();i++){
            subset.push_back(nums[i]);
            dfs(i+1,nums);
            subset.pop_back();
        }
    }



    vector<vector<int>> subsets(vector<int>& nums) {
         dfs(0,nums);
         return result;

         
    }
};
