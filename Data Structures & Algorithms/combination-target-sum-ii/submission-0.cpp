class Solution {
public:
    vector<vector<int>>ans;
    vector<int>subsets;
    void dfs(vector<int>&candidates,int index,int target){
        if(target==0){
             ans.push_back(subsets);
             return;
        }
        if(target<0 || index==candidates.size()){
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])
                   continue;
              subsets.push_back(candidates[i]);
              dfs(candidates,i+1,target-candidates[i]);
              subsets.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates,0,target);
        return ans;
    }
};
