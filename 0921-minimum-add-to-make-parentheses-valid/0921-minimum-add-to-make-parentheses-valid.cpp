class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int answer = 0;
        for(int ch : s){
            if(ch=='('){
                open++;
            }else{
                if(open>0){
                    open--;
                }else{
                    answer++;
                }
            }
        }
        answer += open;
        return answer;
    }
};