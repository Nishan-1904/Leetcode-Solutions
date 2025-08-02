class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char,int>mpp;
        priority_queue<int> maxH;
        queue<pair<int,int>> q;
        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]]++;
        }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            maxH.push(it->second);
        }
        while(!maxH.empty() || !q.empty()){
            time++;
            if(!maxH.empty()){
                int count = maxH.top();
                maxH.pop();
                count--;
                if(count>0){
                    q.push({count,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                maxH.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};