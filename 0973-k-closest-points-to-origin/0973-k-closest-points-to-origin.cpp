class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans(k);
        priority_queue<vector<int>>max_heap;
        for(auto &i:points){
            int x=i[0],y=i[1];
            max_heap.push({x*x+y*y,x,y});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        for(int i=0;i<k;i++){
            vector<int>arr=max_heap.top();
            max_heap.pop();
            ans[i]={arr[1],arr[2]};
        }
        return ans;
    }
};