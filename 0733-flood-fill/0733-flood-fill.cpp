class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int columns=image[sr].size();
        int rows=image.size();
        vector<vector<int>>ans=image;
        image[sr][sc]=color;
        if(sc+1<columns&&ans[sr][sc+1]==ans[sr][sc])
            floodFill(image,sr,sc+1,color);
        if(sc-1>=0&&ans[sr][sc-1]==ans[sr][sc])
            floodFill(image,sr,sc-1,color);
        if(sr+1<rows&&ans[sr+1][sc]==ans[sr][sc])
            floodFill(image,sr+1,sc,color);
        if(sr-1>=0&&ans[sr-1][sc]==ans[sr][sc])
            floodFill(image,sr-1,sc,color);
        return image;
    }
};