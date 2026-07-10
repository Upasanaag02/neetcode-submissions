class Solution {
public:
    vector<vector<int>>ans;
    vector<int>subsets;
    void dfs(vector<int>&nums,int index){
             ans.push_back(subsets);
         if(index==nums.size()){
            return;
         }
         for(int i=index;i<nums.size();i++){
             if (i > index && nums[i] == nums[i - 1])
                continue;
            subsets.push_back(nums[i]);
            dfs(nums,i+1);
            subsets.pop_back();
         }






    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        dfs(nums,0);
        return ans;
    }
};
