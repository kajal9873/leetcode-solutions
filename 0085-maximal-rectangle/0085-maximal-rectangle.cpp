class Solution {
public:
    int largesthistogramarea(vector<int>& heights){
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();
        for(int i=0; i<=n; i++){
            int currheight = i==n? 0: heights[i];
            while(!st.empty() && heights[st.top()]>currheight){
                int height = heights[st.top()];
                st.pop();
                int right = i;
                int left = st.empty()? -1: st.top();
                int width = right-left-1;
                maxarea = max(maxarea, height*width);
            }
            st.push(i);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols,0);
        int maxarea = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j]=='1'){
                    heights[j] += 1;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxarea = max(maxarea, largesthistogramarea(heights));
        }
        return maxarea;
    }
};