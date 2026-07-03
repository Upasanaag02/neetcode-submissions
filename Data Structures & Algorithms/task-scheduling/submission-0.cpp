class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;

        for(char task:tasks){
            freq[task]++;

        }

        priority_queue<int>maxheap;

        for(auto it:freq){
            maxheap.push(it.second);
        }

        queue<pair<int,int>>cooldown;
        int time=0;
        while(!cooldown.empty()|| !maxheap.empty()){
           time++;
           if (!maxheap.empty()) {
                int cnt=maxheap.top();
                maxheap.pop();
                cnt--;
                if(cnt>0){
               cooldown.push({cnt,time+n});
           }}
        

        if(!cooldown.empty() && cooldown.front().second==time){
            maxheap.push(cooldown.front().first);
            cooldown.pop();
        }}
        return time;
    }
};
