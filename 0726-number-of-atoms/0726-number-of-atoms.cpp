class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<map<string, int>> st;
        map<string, int> current;
        
        for (int i = 0; i < n; ) {
            if (isupper(formula[i])) {
                string element = "";
                element += formula[i++];
                while (i < n && islower(formula[i]))
                    element += formula[i++];
                
                string num = "";
                while (i < n && isdigit(formula[i]))
                    num += formula[i++];
                
                int count = (num.empty()) ? 1 : stoi(num);
                current[element] += count;
            } else if (formula[i] == '(') {
                st.push((current));
                current.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                string num = "";
                while (i < n && isdigit(formula[i]))
                    num += formula[i++];
                
                int multiplier = (num.empty()) ? 1 : stoi(num);
                
                if (!st.empty()) {
                    for (auto& [element, count] : current) {
                        st.top()[element] += count * multiplier;
                    }
                    current = (st.top());
                    st.pop();
                }
            }
        }
        
        map<string, int> finalCount = move(current);
        string result;
        
        for (auto& [element, count] : finalCount) {
            result += element;
            if (count > 1)
                result += to_string(count);
        }
        
        return result;
    }
};
