class Solution {
public:
    bool is_lower(char c)
    {
        if ((c >= 'a') && (c <= 'z'))
            return true;
        else if((c >= 'A') && (c <= 'Z'))
            return false;
    }
    
    bool detectCapitalUse(string word) {
        int len = word.size();
        if(len == 1)
            return true;
        
        bool res = true;
                
        if(is_lower(word[0]))  //aaaaaaa
        {
            for(int i = 1;i < len; i++)
            {
                if(!is_lower(word[i]))
                    return false;
            }
        }
        else  
        {
            if(!is_lower(word[1])) //AAAAAAAA
            {
                for(int i = 2; i < len; i++)
                {
                    if(is_lower(word[i]))
                        return false;
                }
            }
            else  //Aaaaaaa
            {
                for(int i = 2; i < len; i++)
                {
                    if(!is_lower(word[i]))
                        return false;
                }
            }
        }
        return res;
    }
};
