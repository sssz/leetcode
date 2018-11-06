// Double index scan
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int re  = 0;
        while(j>i){
            re = max(re, min(height[i], height[j]) * (j-i));
            if(height[i] < height[j]){
                i++;
            } else {
                j--;
            }
        }
        return re;
    }
};