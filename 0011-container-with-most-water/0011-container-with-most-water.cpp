class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxwater = 0;
        int left = 0, right = n-1;
        while(left<right){
            int width = right-left;
            int minheight = min(height[left],height[right]);
            int currarea = minheight * width;
            maxwater = max(maxwater,currarea);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxwater;
    }
};