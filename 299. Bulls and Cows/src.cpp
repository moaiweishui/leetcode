class Solution {
public:
    string getHint(string secret, string guess) {
        multiset<char> ss;
        multiset<char> gs;
        int bull = 0;
        int cow = 0;
        for(int i = 0; i < secret.length(); i++)
        {
            if(secret[i] == guess[i])
                bull++;
            else
            {
                ss.insert(secret[i]);
                gs.insert(guess[i]);                
            }
        }
        
        for (multiset<char>::iterator it = ss.begin(); it != ss.end(); it++)
	    {
		    multiset<char>::iterator ite = find(gs.begin(), gs.end(), *it);
		    if (ite != gs.end())
		    {
			    cow++;
			    gs.erase(ite);
		    }			
	    }
        
        string bull_s;
        string cow_s;
        stringstream sstream;
        sstream << bull;
        sstream >> bull_s;
        sstream.str("");
        sstream.clear();
        sstream << cow;
        sstream >> cow_s;
        
        return bull_s + 'A' + cow_s + 'B';      
    }
};
