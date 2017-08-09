class Solution {
public:
    void swap(vector<int>& v, int pos1, int pos2)
    {
	    int tmp = v[pos1];
	    v[pos1] = v[pos2];
	    v[pos2] = tmp;
    }
    
    vector<int> ann(int n, int k)
    {
	    vector<int> start_v, end_v;

	    for (int i = 1; i <= n; i++)
	    {
		    start_v.push_back(i);
		    end_v.push_back(n + 1 - i);
	    }
		
	    if(k == 1)
            return start_v;

        int cnt = 1;
        
	    while (start_v != end_v)
	    {
		    for (int i = n - 2; i >= 0; i--)
		    {   
			    if (start_v[i] < start_v[i + 1])
			    {
				    int min_of_max = start_v[i + 1];
				    int index = i + 1;
				    for (int j = i + 1; j < start_v.size(); j++)
				    {
					    if (start_v[j] > start_v[i] && start_v[j] < min_of_max)
					    {
						    min_of_max = start_v[j];
						    index = j;
					    }
				    }
				    swap(start_v, i, index);
				    reverse(start_v.begin() + i + 1, start_v.end());
                    cnt++;
				    if(cnt == k)
                        return start_v;
                    else
                        break;
			    }
		    }
	    }
    }
    
    string getPermutation(int n, int k) {
        
        vector<int> resv = ann(n, k);
        
        string res = "";
        
        for(int i = 0; i < resv.size(); i++)
        {
            res.append(1, resv[i]+48);
        }
        
        return res;
       
    }
};
