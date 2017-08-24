class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();

        int l = 0, r = len - 1;
        int max = min(height[l], height[r]) * (r - l);
        
        int temp;

        while(l < r)
        {
            if(height[l] >= height[r])
                r--;
            else
                l++;
            
            temp = min(height[l], height[r]) * (r - l);
            if(temp > max)
                max = temp;
        }
        
        return max;
    }
};
