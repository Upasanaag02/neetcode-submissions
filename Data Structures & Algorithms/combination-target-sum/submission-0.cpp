class Solution {
public:
    vector<vector<int>>ans;
    vector<int>combine;
    set<vector<int>>s;
    void dfs(int index,vector<int>&nums,int target){
        
        if(index==nums.size() || target<0){
            return;
        }
        if(target==0){
            if(s.find(combine)==s.end()){
                ans.push_back(combine);
                s.insert(combine);
            }
             return;
        }
        
        combine.push_back(nums[index]);
        dfs(index+1,nums,target-nums[index]);
        dfs(index,nums,target-nums[index]);
        combine.pop_back();
        dfs(index+1,nums,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0,nums,target);
        return ans;
    }
};
