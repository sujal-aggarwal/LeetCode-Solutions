//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        vector<int>con(N);
        for(int i=1;i<N;i++){
            con[i]++;con[p[i]]++;
        }
        int ans=0;
        for(auto x:con){
            if(x==1)ans++;
        }
        return (N-ans-1>=0)?N-ans-1:0;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends