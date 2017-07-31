class Solution {
public:
    static bool cmp(pair<char, int>& x, pair<char, int>& y)
    {
	    return x.second > y.second;
    }
    
    string frequencySort(string s) {
        map<char, int> m;
        for (int i = 0; i < s.length(); i++)
	    {
		    if (m.count(s[i]) == 0)
			    m[s[i]] = 1;
		    else
			    m[s[i]] += 1;
	    }
        
        vector<pair<char, int>> v;
	    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		    v.push_back(pair<char, int>(it->first, it->second));
        sort(v.begin(), v.end(), cmp);
        
        string res;
	    for (int i = 0; i < v.size(); i++)
            res.append(v[i].second, v[i].first);
        return res;
    }
};
