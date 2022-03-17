class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
     queue<vector<int>> q;
     int n=image.size();
     int m=image[0].size();
     q.push({sr,sc});
     int curr=image[sr][sc];
     if(curr==newColor) return image;
     vector<int> arr={0,1,0,-1};
     vector<int> brr={1,0,-1,0};   
        image[sr][sc]=newColor;
     while(!q.empty()){
         auto a=q.front();
         q.pop();
         for(int i=0;i<4;i++){
             int ii=a[0]+arr[i];
             int jj=a[1]+brr[i];
             if(ii<0 or ii>=n or jj<0 or jj>=m or image[ii][jj]!=curr) continue;
             image[ii][jj]=newColor;
             q.push({ii,jj});
         }
     }   
      return image;  
    }
};