class BrowserHistory {
public:
    vector<string>history;
    int current_index=0;
    int max_index=0;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        if(current_index<max_index){
            history[current_index+1]=url;
            current_index++;
            max_index=current_index;
        }else{
            if(max_index+1<history.size()){
                history[current_index+1]=url;
                current_index++;
                max_index=current_index;
            }
            else{
                history.push_back(url);
                current_index++;
                max_index++;
            }
        }
    }
    
    string back(int steps) {
        current_index-=steps;
        if(current_index<0){
            current_index=0;
        }
        return history[current_index];
    }
    
    string forward(int steps) {
        current_index+=steps;
        if(current_index>max_index){
            current_index=max_index;
        }
        return history[current_index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */