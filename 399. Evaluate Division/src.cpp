class Solution {
public:
    void findPath(vector<vector<double>>& weight_matrix, vector<vector<bool>>& valid_matrix, 
        vector<int>& path, int start, int end, double& res, bool& flag)
    {
        if (flag)
            return;
        
        if (start == end)
        {
            flag = true;
            return;
        }
        
        for (int i = 0; i < valid_matrix[start].size(); i++)
        {
            if (i != start && valid_matrix[start][i] == true && weight_matrix[start][i] != -1 && find(path.begin(), path.end(), i) == path.end())
            {
                double tmp = weight_matrix[start][i];
                path.push_back(i);
                if (!flag)
                    res *= tmp;
                findPath(weight_matrix, valid_matrix, path, i, end, res, flag);
                if (!flag)
                    res = res / tmp;
                path.pop_back();
            }
        }

        return;
    }
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> node_map;
        int cnt = 0;
        for(auto it = equations.begin(); it != equations.end(); it++)
        {
            auto findit = node_map.find((*it).first);
            if(findit == node_map.end())
            {
                node_map[(*it).first] = cnt;
                cnt++;
            }
            findit = node_map.find((*it).second);
            if(findit == node_map.end())
            {
                node_map[(*it).second] = cnt;
                cnt++;
            }
        }
        
        vector<vector<double>> weight_matrix(cnt, vector<double>(cnt, 0));
        vector<vector<bool>> valid_matrix(cnt, vector<bool>(cnt, false));
        
        for(int i = 0; i < cnt; i++)
        {
            weight_matrix[i][i] = 1.0;
            valid_matrix[i][i] = true;
        }
        
        int start, end;
        
        for(int i = 0; i < equations.size(); i++)
        {
            start = (*node_map.find(equations[i].first)).second;
            end = (*node_map.find(equations[i].second)).second;
            weight_matrix[start][end] = values[i];
            weight_matrix[end][start] = 1.0/values[i];
            valid_matrix[start][end] = true;
            valid_matrix[end][start] = true;
        }
        
        vector<double> res(queries.size(), -1);
        vector<int> path;
        
        for(int i = 0; i < queries.size(); i++)
        {
            auto findit = node_map.find(queries[i].first);
            if(findit == node_map.end())
                continue;
            else
                start = (*findit).second;
            
            findit = node_map.find(queries[i].second);
            if(findit == node_map.end())
                continue;
            else
                end = (*findit).second;
            
            if(valid_matrix[start][end])
                res[i] = weight_matrix[start][end];
            else
            {
                path.clear();
                path.push_back(start);
                double path_res = 1;
                bool flag = false;
                findPath(weight_matrix, valid_matrix, path, start, end, path_res, flag);
                if (!flag)
                {
                    weight_matrix[start][end] = -1.0;
                    weight_matrix[end][start] = -1.0;
                }
                else
                {
                    weight_matrix[start][end] = path_res;
                    weight_matrix[end][start] = 1.0 / path_res;
                }
                valid_matrix[start][end] = true;
                valid_matrix[end][start] = true;
                res[i] = weight_matrix[start][end];
                cout<<i<<'-'<<res[i]<<endl;
            }
        }
        
        return res;
    }
};
