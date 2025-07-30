class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        if(groupSize==1) return true;
        vector<int> window;
        queue<int> q;
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i=0;i<hand.size();i++){
            minH.push(hand[i]);
        }
        int top = minH.top();
        minH.pop();
        window.push_back(top); 
        int i = 1;
        while(!minH.empty()){
            int ele = minH.top();
            if(i==0){
                window.push_back(ele);
                minH.pop();
                i=1;
            }
            else{
                if((ele-window[i-1])==1){
                    window.push_back(ele);
                    minH.pop();
                    i++;
                }
                else if((ele-window[i-1])==0){
                    q.push(ele);
                    minH.pop();
                }
                else{
                    return false;
                }
                if(window.size()==groupSize){
                    i = 0;
                    window.clear();
                    while(!q.empty()){
                        minH.push(q.front());
                        q.pop();
                    }
                }
            }
            
        }
        return window.empty();
    }
};