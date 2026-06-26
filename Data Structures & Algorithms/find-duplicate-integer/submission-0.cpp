class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         unordered_map<int,int>md;
          for(int i:nums){
              md[i]++;
              if(md[i]>1){
                return i;
              }
          }
          return -1;
    }
};
