class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int res = true;
        vector<char> v;
        
        for(int i = 0; i < magazine.length(); i++)
        {
            v.push_back(magazine[i]);
        }
        
        for(int i = 0; i < ransomNote.length(); i++)
        {
            vector<char>::iterator it;
            it = find(v.begin(), v.end(), ransomNote[i]);
            if(it == v.end())
            {
                res = false;
                break;
            }
            else
            {
                v.erase(it);
            }
            
        }
        
        return res;
    }
};
