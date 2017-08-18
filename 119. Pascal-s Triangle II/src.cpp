class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        if(rowIndex == 0) 
        {
            res.push_back(1);
            return res;
        }
        else if(rowIndex == 1)
        {
            res.push_back(1);
            res.push_back(1);
            return res;
        }
        else if(rowIndex == 2)
        {
            res.push_back(1);
            res.push_back(2);
            res.push_back(1);
            return res;
        }
        
        res.push_back(1);
        res.push_back(2);
        res.push_back(1);
        
        vector<int> last_row;
        
        for(int i = 3; i <= rowIndex; i++)
        {
            last_row.assign(res.begin(), res.end());
            res.clear();
            res.push_back(1);
            
            for(int j = 1; j <= i; j++)
            {
                if(j <= i/2)
                    res.push_back(last_row[j-1] + last_row[j]);
                else
                    res.push_back(res[i - j]);
            }               
                
        }
        return res;

    }
};
