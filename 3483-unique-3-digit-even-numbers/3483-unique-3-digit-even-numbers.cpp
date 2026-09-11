class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for(int d : digits){
            freq[d]++;
        }
        int answer = 0;
        for(int u=0; u<=8; u+=2){
            if(freq[u]==0) continue;
            freq[u]--;
            for(int h=1; h<=9; h++){
                if(freq[h]==0) continue;
                freq[h]--;
                for(int t=0; t<=9; t++){
                    if(freq[t]==0) continue;
                    answer++;
                }
                freq[h]++;
            }
            freq[u]++;
        }
        return answer;
    }
};