class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>>cars;
        for(int i=0;i<position.size();i++){
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
            
        }
        sort(cars.begin(),cars.end());
        stack<double>st;
        for(int i=cars.size()-1;i>=0;i--){
            double curr=cars[i].second;
            
            if(st.empty() || st.top()<curr){
                st.push(curr);
            }
        }
        return st.size();
    }
};
