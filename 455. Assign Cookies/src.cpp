class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        if(s.size() == 0)
        {
            return 0;
        }
        if(g[0] > s[s.size()-1])
        {
            return 0;
        }
        for(int i = 0; i != g.size(); i++)
        {
            vector<int>::iterator it = s.begin();
            while(it != s.end())
            {
                if(g[i] <= *it)
                {
                    res++;
                    it = s.erase(it);
                    break;
                }
                else
                {
                    it++;
                }
            }
        }
        
        return res;
    }
};
