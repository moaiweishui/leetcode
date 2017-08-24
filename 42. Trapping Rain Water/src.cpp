/****************** Solution 1 *******************/
class Solution {
public:
    int trap(vector<int>& height) {
        
        int h = 1;      
        int len = height.size();
        int flag = true;
        int res = 0;
        
        while(flag)
        {
            int start = -1, end = -1;
            for(int i = 0; i < len; i++)
                if(height[i] >= h)
                {
                    start = i;
                    break;
                }            
            if(start == -1)
                break;
            for(int i = len - 1; i >= 0; i--)
                if(height[i] >= h)
                {
                    end = i;
                    break;
                }
            if(end == -1 || start == end)
                break;
            int _tmp = 0;
            cout<<start<<'-'<<end<<endl;
            for(int i = start; i <= end; i++)
            {
                if(height[i] < h)
                    _tmp++;
            }
            res += _tmp;
            h++;
        }
        return res;
    }
};

/****************** Solution 2 *******************/
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        
        if(len == 0 || len == 1 || len ==2)
            return 0;
        
        int left_h, right_h;
        int l = 0, r = height.size() - 1;
        int res = 0;
        
        while (l < r)
        {
            left_h = height[l];
            right_h = height[r];
            if (left_h <= right_h)
            {
                l++;
                while (l < r && height[l] <= left_h)
                {
                    res += left_h - height[l];
                    l++;
                }
            }
            else
            {
                r--;
                while (l < r && height[r] <= right_h)
                {
                    res += right_h - height[r];
                    r--;
                }
            } 
        }
        return res;
    }
};
