class Solution {
public:
    void swap(string& s, int i, int j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    bool isVowel(char c)
    {
        switch (c)
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
        default:
            return false;
        }
    }
    
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r)
        {
            while (l<r && !isVowel(s[l]))
            {
                l++;
            }

            while (l < r && !isVowel(s[r]))
            {
                r--;
            }

            if (l < r){
                swap(s, l, r);
                l++;
                r--;
            }
        }
        return s;
    }
};
