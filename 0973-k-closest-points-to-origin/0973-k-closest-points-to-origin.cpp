class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(begin(points), begin(points) + k, end(points), [](const auto& a, const auto& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
        points.resize(k);
        return move(points);
    }
};