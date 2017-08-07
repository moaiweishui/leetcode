class Solution {
public:
    
    int vector2time(vector<int>& v)
    {
	    int res = 0;

	    for (int i = 0; i < v.size(); i++)
	    {
		    res += v[i];
		    res = res << 1;
	    }
	    res = res >> 1;
	    return res;
    }
    
    void formTime(vector<int>& hour, vector<int>& min, vector<string>& time)
    {
	    for (int i = 0; i < hour.size(); i++)
	    {
		    for (int j = 0; j < min.size(); j++)
		    {
			    string h_s;
			    string m_s;
			    stringstream ss1;	
			    ss1 << hour[i];
			    ss1 >> h_s;
			    stringstream ss2;
			    ss2 << min[j];
			    ss2 >> m_s;
			    if (min[j]<10)
				    time.push_back(h_s + ":0" + m_s);
			    else
				    time.push_back(h_s + ':' + m_s);
		    }
	    }
    }
    
    void cmn(int m, int n, vector<int>& num, string type)
    {
	    vector<int> start_v(m, 0);
	    vector<int> end_v(m, 0);

	    int upLim;
	    if (type == "hour")
		    upLim = 12;
	    else if (type == "minute")
		    upLim = 60;

	    for (int i = 0; i < n; i++)
	    {
		    start_v[i] = 1;
		    end_v[m - i - 1] = 1;
	    }
	    int x = vector2time(start_v);
	    if (x < upLim)
		    num.push_back(x);
	    while (start_v != end_v)
	    {
		    for (int i = 0; i < m - 1; i++)
		    {
			    if (start_v[i] == 1 && start_v[i + 1] == 0)
			    {
				    start_v[i] = 0;
				    start_v[i + 1] = 1;
				    int cnt = 0;
				    for (int j = 0; j < i; j++)
				    {
					    cnt += start_v[j];
					    start_v[j] = 0;
				    }
				    for (int j = 0; j < cnt; j++)
				    {
					    start_v[j] = 1;
				    }
				    break;
			    }
		    }
		    int x = vector2time(start_v);
		    if (x < upLim)
			    num.push_back(x);
	    }
    }
    
    
    vector<string> readBinaryWatch(int num) {
        vector<int> hour_v;
	    vector<int> min_v;

	    vector<string> time_v;
        
        for (int i = 0; i <= num; i++)
	    {
		    if (i <= 4 && (num-i) <= 6)
		    {
			    cmn(4, i, hour_v, "hour");
			    cmn(6, num - i, min_v, "minute");

			    formTime(hour_v, min_v, time_v);
			    hour_v.clear();
			    min_v.clear();
		    }
	    }
        
        return time_v;
    }
};
