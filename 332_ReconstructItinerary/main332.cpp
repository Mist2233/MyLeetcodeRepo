#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket: tickets) {
            if (ticket[0] == "JDK") {
                cur_path.push_back(ticket[0]);
                cur_path.push_back(ticket[1]);
                break;
            }
        }

        
    }

    void backtrack(vector<vector<string>>& tickets, int start_idx) {
        
    }

private:
    vector<string> cur_path;

};