class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        if(size == 0)
            return 0;
        else if(size == 1)
            return duration;
        
        int res = 0;
        int last_time = timeSeries[0];
        
    	for (int i = 1; i < timeSeries.size(); i++)
	    {
		    if ((timeSeries[i] - last_time) >= duration)
		    {
			    res += duration;
		    }
		    else
		    {
			    res += timeSeries[i] - last_time;
		    }
		    last_time = timeSeries[i];
	    }
        return res + duration;
        
    }
};
