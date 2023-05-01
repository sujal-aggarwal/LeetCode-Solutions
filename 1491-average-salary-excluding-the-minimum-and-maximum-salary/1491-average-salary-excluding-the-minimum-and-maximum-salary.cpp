class Solution {
public:
    #define all(x) x.begin(),x.end()
    double average(vector<int>& salary) {
        return (accumulate(all(salary),0)-(*min_element(all(salary)))-(*max_element(all(salary))))/(double)(salary.size()-2);
    }
};