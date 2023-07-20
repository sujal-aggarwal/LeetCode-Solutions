class Solution {
public:
    bool notstrike(int i,int j){
        if(i<0)return true;
        if(j>0)return true;
        return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        for(auto i:asteroids){
            if(res.size()==0||notstrike(res.back(),i)){
                res.push_back(i);
            }else if(!notstrike(res.back(),i)){
                if(res.back()>abs(i)){
                    continue;
                }else if(res.back()==abs(i)){
                    res.pop_back();
                }else{
                    while(res.size()>0){
                        if(notstrike(res.back(),i)){
                            break;
                        }
                        if(res.back()>abs(i)){
                            i=INT_MIN;
                            break;
                        }
                        else if(res.back()==abs(i)){
                            res.pop_back();
                            i=INT_MIN;
                            break;
                        }
                        res.pop_back();
                    }
                    if(i!=INT_MIN)
                        res.push_back(i);
                }
            }
        }
        return res;
    }
};