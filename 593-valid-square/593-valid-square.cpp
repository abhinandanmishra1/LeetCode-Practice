class Solution {
public:
    int distance(vector<int>p1,vector<int>p2){
        return pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> st;
        vector<vector<int>> points={p1,p2,p3,p4};
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                int dist=distance(points[i],points[j]);
                if(dist==0) return false;
                st.insert(dist);
            }
        }
        return st.size()==2;
    }
};


/*
If the given geomtery is square then it will have only two different lengths between points

one is diagonal and other one is side of the square;
*/