class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int volume = 0;
        int max = 0;
        while(i < j){
            volume = (j - i) * (std::min(height[i], height[j]));
            if(volume > max){
                max = volume;
            }
            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return max;
    }
};