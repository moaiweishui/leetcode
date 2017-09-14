/**************** Solution 1 ****************/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);        
        vector<int> row;
        vector<vector<int>> innode(numCourses, row);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i].first]++;
            innode[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        int node;
        
        while(!q.empty())
        {
            node = q.front();
            q.pop();
            indegree[node] = -1;
            
            for(int i = 0; i < innode[node].size(); i++)
            {
                //adj_matrix[node][innode[node][i]] = false;
                indegree[innode[node][i]]--;
                if(indegree[innode[node][i]] == 0)
                        q.push(innode[node][i]);
            }
        }
        
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] != -1)
                return false;
                
        
        
        return true;
    }
};
