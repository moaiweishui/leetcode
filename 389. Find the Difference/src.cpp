/********************** Solution 1 ****************************/
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int i;
        for(i = 0; i< s.length(); i++)
        {
            if(s[i] != t[i])
                return t[i];
        }
        
        return t[i];
    }
};

/********************** Solution 2 ****************************/
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> count(26, 0);
        
        for (int i = 0; i < s.length(); i++)
            count[s[i] - 97] ++;

        for (int i = 0; i < t.length(); i++)
        {
            count[t[i] - 97] --;
            if (count[t[i] - 97] == -1)
            {
                return t[i];
            }
            
        }
        
    }
};
