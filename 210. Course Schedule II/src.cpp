class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> row;
        vector<vector<int>> prenode(numCourses, row);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i].first]++;
            prenode[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        queue<int> node_q;
        
        for(int i = 0; i < indegree.size(); i++)
            if(indegree[i] == 0)
                node_q.push(i);
        
        int node;
        
        vector<int> res;
        
        while(!node_q.empty())
        {
            node = node_q.front();
            node_q.pop();
            res.push_back(node);
           
            for(int i = 0; i < prenode[node].size(); i++)
            {
                indegree[prenode[node][i]]--;
                if(indegree[prenode[node][i]] == 0)
                    node_q.push(prenode[node][i]);
            }
        }
        if(res.size() == numCourses)
            return res;
        else
        {
            res.clear();
            return res;
        }
        
    }
};
