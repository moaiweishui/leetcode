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

/****************** Solution 3 *******************/
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        
        if(len == 0 || len == 1 || len ==2)
            return 0;
        
        vector<int> left_maxh(len, 0);
        vector<int> right_maxh(len, 0);
        
        int left_h = height[0];
        left_maxh[0] = left_h;
        
        for(int i = 1; i < len; i++)
        {
            if(height[i] > left_h)
                left_h = height[i];
            left_maxh[i] = left_h;
        }
        
        int right_h = height[len - 1];
        right_maxh[len - 1] = right_h;
        
        for(int i = len - 2; i >= 0; i--)
        {
            if (height[i] > right_h)
                right_h = height[i];
            right_maxh[i] = right_h;
        }
        
        int res = 0;
        for (int i = 0; i < len; i++)
            res += min(left_maxh[i], right_maxh[i]) - height[i];
        
        return res;
    }
};

/****************** Solution 4 *******************/
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        
        if(len == 0 || len == 1 || len ==2)
            return 0;
        
        stack<int> st;
        int p = 0;

        int res = 0;

        for (int i = 0; i < len; i++)
        {
            while (!st.empty() && (height[i] > height[st.top()]))
            {
                int temp = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = i - st.top() - 1;
                int h = min(height[i], height[st.top()]) - height[temp];
                res += distance * h;
            }
            st.push(i);
        }
        
        return res;
    }
};


/****************** Solution 5 *******************/
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        
        if(len == 0 || len == 1 || len ==2)
            return 0;
        
        //int max = 0;
        int max_index = 0;
        
        vector<int> left_h(len, 0);
        int left_max = height[0];
        
        vector<int> sum(len, 0);
        
        for(int i = 0; i < len; i++)
        {           
            if(height[i] > left_max)
            {
                left_max = height[i];
                max_index = i;
            }
            left_h[i] = left_max;
            if(i == 0)
                sum[i] = 0;
            else
                sum[i] = sum[i - 1] + left_max - height[i];
        }
        
        int res = sum[max_index];
        
        int right_max = height[len - 1];
        
        for(int i = len - 1; i > max_index; i--)
        {
            if (height[i] > right_max)
                right_max = height[i];
            res += right_max - height[i];
        }
        
        return res;
    }
};
