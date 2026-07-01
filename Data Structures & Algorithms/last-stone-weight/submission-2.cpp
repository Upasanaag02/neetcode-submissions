class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int,vector<int>>maxHeap;

        for(int num:stones){
            maxHeap.push(num);
            
        }
        
        while(maxHeap.size()!=1 && !(maxHeap.empty())){
            int num1=maxHeap.top();
            maxHeap.pop();
            int num2=maxHeap.top();
            maxHeap.pop();
            if(num1<num2){
                maxHeap.push(num2-num1);
            }
            else if(num2<num1){
                maxHeap.push(num1-num2);
            }
            else{
                continue;
            }
        }
        int ans=maxHeap.top();
        if(maxHeap.empty()){
             ans=0;
        }
        return ans;
    }
};
