class Solution {
public:
    bool ispossible(vector<int>& piles, int h,int k){
        long long need=0;
        for(auto pile:piles){
             need+=(pile+k-1)/k;
        }
        if(need<=h){
            return true;
        }
        else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
           int  mid=l+(r-l)/2;
            if(ispossible(piles,h,mid)){
                   ans=mid;
                   r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
