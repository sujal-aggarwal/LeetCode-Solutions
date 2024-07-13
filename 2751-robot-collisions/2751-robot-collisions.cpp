class robot{
    public:
    int health;
    int position;
    char direction;
    int index;
    
    robot(int position, int health, char direction, int index){
        this->health=health;
        this->direction=direction;
        this->index=index;
        this->position=position;
    }
};
typedef pair<int,pair<int,int>> piic;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<robot> arr;
        for(int i=0;i<healths.size();i++){
            robot r1(positions[i],healths[i],directions[i],i);
            arr.push_back(r1);
        }
        sort(arr.begin(),arr.end(),[](robot& r1, robot& r2){
            return r1.position < r2.position;
        });
        deque<robot>dq;
        for(auto v:arr){
            if(v.direction=='L'){
                while(!dq.empty() && dq.back().direction == 'R' && v.health>0){
                    if(dq.back().health == v.health){
                        v.health=0;
                        dq.pop_back();
                        break;
                    }else if(dq.back().health > v.health){
                        dq.back().health--;
                        v.health=0;
                        break;
                    }else{
                        dq.pop_back();
                        v.health--;
                    }
                }
            }
            if(v.health){
                dq.push_back(v);
            }
        }
        arr.clear();
        while(!dq.empty()){
            arr.push_back(dq.front());
            dq.pop_front();
        }
        sort(arr.begin(),arr.end(),[](robot& r1, robot& r2){
            return r1.index<r2.index;
        });
        vector<int>ans;
        for(auto i:arr){
            ans.push_back(i.health);
        }
        return ans;
    }
};