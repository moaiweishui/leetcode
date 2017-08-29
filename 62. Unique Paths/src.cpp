/********************** Solution 1 **********************/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> start_v(m + n - 2, 0);
        vector<int> end_v(m + n - 2, 0);
        for(int i = 0; i < m - 1; i++)
        {
            start_v[i] = 1;
            end_v[m + n - 3 - i] = 1;
        }
        
        int res = 1;
        
        int len = m + n - 2;
        
        while(start_v != end_v)
        {
            int i;
            for(i = 0; i < len - 1; i++)
                if(start_v[i] == 1 && start_v[i + 1] == 0)
                {
                    start_v[i] = 0;
                    start_v[i + 1] = 1;
                    break;
                }
            
            int cnt = 0;
            for(int j = 0; j < i; j++)
            {
                if(start_v[j] == 1)
                {
                    cnt++;
                    start_v[j] = 0;
                }
            }
            for(int j = 0; j < cnt; j++)
                start_v[j] = 1;
            res++;
        }
        
        return res;
    }
};


/********************** Solution 2 **********************/
