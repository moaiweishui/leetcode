class Solution {
public:
    void mapInsert(string path, string file, unordered_map<string, vector<string>>& hmap)
    {
        int posLeft, posRight;
        string fileName, fileContent;

        posLeft = file.find('(', 0);
        posRight = file.find(')', posLeft);
        fileName = file.substr(0, posLeft);
        fileContent = file.substr(posLeft + 1, posRight - posLeft - 1);

        auto mapit = hmap.find(fileContent);
        if (mapit == hmap.end())
        {
            vector<string> tmpv;
            tmpv.push_back(path + fileName);
            hmap.insert(pair<string, vector<string>>(fileContent, tmpv));
        }
        else
        {
            hmap[fileContent].push_back(path + fileName);
        }
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        char space = ' ';
        string s, path, file, fileName, fileContent;
        int pos;
        int posLeft, posRight;
        
        unordered_map<string, vector<string>> hmap;
        
        for(auto it = paths.begin(); it != paths.end(); it++)
        {
            s = *it;
            pos = s.find(space, 0);
            path = s.substr(0, pos);
            path += '/';
            s = s.substr(pos + 1, s.length());
            
            while(1)
            {
                pos = s.find(space, 0);
                if(pos == -1)
                {
                    file = s;
                    mapInsert(path, file, hmap);
                    break;
                }
                else
                {
                    file = s.substr(0, pos);
                    mapInsert(path, file, hmap);
                    s = s.substr(pos + 1, s.length() - pos - 1);
                }
            }    
        }
        
        for(auto it = hmap.begin(); it != hmap.end(); it++)
        {
            if((*it).second.size() != 1)
                res.push_back((*it).second);
        }
        
        return res;
    }
};
