class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<int> v;
        
        int edge12 = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        int edge13 = (p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]);
        int edge14 = (p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]);
        int edge23 = (p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1]);
        int edge24 = (p2[0]-p4[0])*(p2[0]-p4[0]) + (p2[1]-p4[1])*(p2[1]-p4[1]);
        int edge34 = (p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1]);
        
        v.push_back(edge12);
        v.push_back(edge13);
        v.push_back(edge14);
        v.push_back(edge23);
        v.push_back(edge24);
        v.push_back(edge34);
        
        sort(v.begin(), v.end());
        if(v[0] == 0 || v[1] == 0 || v[2] == 0 || v[3] == 0 || v[4] == 0 || v[5] == 0)
            return false;
        else if(v[0] == v[1] && v[0] == v[2] && v[0] == v[3] && v[4] == v[5])
            return true;
        else
            return false;
        
    }
};
