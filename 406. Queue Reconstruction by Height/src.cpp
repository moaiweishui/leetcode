class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if(a.first > b.first)
            return true;
        else if(a.first < b.first)
            return false;
        else 
            return a.second < b.second;
    }
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int len = people.size();
        vector<pair<int, int>> res;
        if(len == 0)
            return res;
        
        sort(people.begin(), people.end(), cmp);
        
        res.push_back(people[0]);
          
        for(int i = 1; i < len; i++)
        {
            if(people[i].second > i)
                res.push_back(people[i]);
            else
                res.insert(res.begin() + people[i].second, people[i]);
        }
        
        return res;
    }
};
