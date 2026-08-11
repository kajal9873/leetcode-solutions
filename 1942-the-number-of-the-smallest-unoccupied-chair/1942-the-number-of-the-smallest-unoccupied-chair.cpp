class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> order(n);
        for(int i=0; i<n; i++) order[i] = i;
        sort(order.begin(),order.end(),[&](int a, int b){
            return times[a][0]<times[b][0];
        });
        priority_queue<int, vector<int>, greater<int>> availablechairs;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied;
        int nextnewchair = 0;
        int answerchair = -1;
        for(int idx : order){
            int arrival = times[idx][0];
            int leaving = times[idx][1];
            while(!occupied.empty() && occupied.top().first<=arrival){
                int freechair = occupied.top().second;
                occupied.pop();
                availablechairs.push(freechair);
            }
            int chairforthisfriend;
            if(!availablechairs.empty()){
                chairforthisfriend = availablechairs.top();
                availablechairs.pop();
            }else{
                chairforthisfriend = nextnewchair;
                nextnewchair++;
            }
            occupied.push({leaving,chairforthisfriend});
            if(idx==targetFriend){
                answerchair = chairforthisfriend;
            }
        }
        return answerchair;
    }
};