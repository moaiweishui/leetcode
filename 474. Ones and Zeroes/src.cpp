/********************* Solution 1 **********************/
class Solution {
public:    
    int findMaxFormWithLen(vector<string>& strs, int len, vector<pair<int, int>>& v, int m, int n)
    {   
        if(len == 1)
        {
            if(m >= v[0].first && n >= v[0].second)
                return 1;
            else
                return 0;
        }
        
        int excludelast = findMaxFormWithLen(strs, len - 1, v, m, n);
        
        if(m >= v[len - 1].first && n >= v[len - 1].second)
        {
            int includelast = 1 + findMaxFormWithLen(strs, len - 1, v, m - v[len - 1].first, n - v[len - 1].second);
            return max(includelast, excludelast);
        }
        else
        {
            return excludelast;
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> v;
        pair<int, int> temp;

        for (int i = 0; i < strs.size(); i++)
        {
            temp = make_pair(0, 0);
            for (int j = 0; j < strs[i].length(); j++)
            {
                if (strs[i][j] == '0')
                    temp.first++;
                else
                    temp.second++;
            }
            v.push_back(temp);
        }
        
        return findMaxFormWithLen(strs, strs.size(), v, m, n);
        
    }
};

/********************* Solution 2 **********************/
int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> v;
        pair<int, int> temp;

        for (int i = 0; i < strs.size(); i++)
        {
            temp = make_pair(0, 0);
            for (int j = 0; j < strs[i].length(); j++)
            {
                if (strs[i][j] == '0')
                    temp.first++;
                else
                    temp.second++;
            }
            v.push_back(temp);
        }
        
        vector<int> rowv(n + 1, 0);
        vector<vector<int>> mem(m + 1, rowv);
        
        for(int i = 0; i < strs.size(); i++)
        {
            for(int j = m; j >= v[i].first; j--)
                for(int k = n; k >= v[i].second; k--)
                {
                    mem[j][k] = max(mem[j][k], 1 + mem[j - v[i].first][k - v[i].second]);
                }
        }
        return mem[m][n];
    }
