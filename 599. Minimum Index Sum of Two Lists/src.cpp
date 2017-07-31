class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int index_sum = 0x7FFFFFFF;
        vector<string> res;
        for(int i = 0; i<list1.size(); i++)
        {
            if(i <= index_sum)
            {
                vector<string>::iterator it1 = list2.begin();
                vector<string>::iterator it2;
                it2 = find(list2.begin(), list2.end(), list1[i]);
                if(it2 != list2.end())
                {
                    if((int(it2-it1) + i) < index_sum)
                    {
                        index_sum = int(it2-it1) + i;
                        res.clear();
                        res.push_back(list1[i]);
                    }
                    else if((int(it2-it1) + i) == index_sum)
                    {
                        res.push_back(list1[i]);
                    }
                }
            }
        }
        return res;
    }
};
