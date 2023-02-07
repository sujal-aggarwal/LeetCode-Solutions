class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set<int>s;
        int i=0;
        int j=1;
        int maxsize=1;
        map<int,int>mp;
        mp[fruits[i]]++;
        while(j<fruits.size())
        {
            mp[fruits[j]]++;
            if(mp.size()>2)
            {
                maxsize=max(maxsize,j-i);
                while(mp.size()!=2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                        mp.erase(fruits[i]);
                    i++;
                }
            }
            j++;
        }
        maxsize=max(maxsize,j-i);
        return maxsize;
    }
//     class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         // We use a hash map 'basket' to store the number of each type of fruit.
//         unordered_map<int, int> basket;
//         int left = 0, maxPicked = 0;
        
//         // Add fruit from the right index (right) of the window.
//         for (int right = 0; right < fruits.size(); ++right) {
//             basket[fruits[right]]++;
            
//             // If the current window has more than 2 types of fruit,
//             // we remove fruit from the left index (left) of the window,
//             // until the window has only 2 types of fruit.
//             while (basket.size() > 2) {
//                 basket[fruits[left]]--;
//                 if (basket[fruits[left]] == 0)
//                     basket.erase(fruits[left]);
//                 left++;
//             }
            
//             // Update maxPicked.
//             maxPicked = max(maxPicked, right - left + 1);
//         }
        
//         // Return maxPicked as the maximum number of fruits we can collect.
//         return maxPicked;
//     }
// };
};