class Solution {
public:
    char to_lower(char c)
    {
	    if (c >= 'A' && c <= 'Z')
		    c += 'a' - 'A';
	    return c;
    }
    
    
    vector<string> findWords(vector<string>& words) {
        int r1[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    	int r2[] = { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
	    int r3[] = { 'z', 'x', 'c', 'v', 'b', 'n', 'm' };

	    vector<char> _vec1(r1, r1 + 10);
	    vector<char> _vec2(r2, r2 + 9);
	    vector<char> _vec3(r3, r3 + 7);
        
        vector<string> res;
        
        vector<string>::iterator it;
        for (it = words.begin(); it != words.end(); it++)
	    {
		    string _tmp = *it;
		    vector<char> tmp_vec;

		    if (find(_vec1.begin(), _vec1.end(), to_lower(_tmp[0])) != _vec1.end())
			    tmp_vec = _vec1;
		    else if (find(_vec2.begin(), _vec2.end(), to_lower(_tmp[0])) != _vec2.end())
			    tmp_vec = _vec2;
		    else
			    tmp_vec = _vec3;

		    bool flag = true;

		    for (int i = 1; i < _tmp.length(); i++)
		    {
			    if (find(tmp_vec.begin(), tmp_vec.end(), to_lower(_tmp[i])) == tmp_vec.end())
			    {
			    	flag = false;
				    break;
			    }
		    }

		    if (flag)
			    res.push_back(*it);
	    }
        return res;
    }
};
