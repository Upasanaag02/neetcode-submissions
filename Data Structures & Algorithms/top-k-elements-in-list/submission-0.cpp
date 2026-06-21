class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        vector<pair<int,int>>ans;
        vector<int>result;
        for(int i:nums){
             freq[i]++;
        }
        for(auto it:freq){
            ans.push_back({it.second,it.first});
        }
        sort(ans.rbegin(),ans.rend());
        for(int i=0;i<k;i++){
              result.push_back(ans[i].second);
        }
        return result;
    }
};
