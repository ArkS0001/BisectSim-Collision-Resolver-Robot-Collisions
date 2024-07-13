// O(n logn) - Simulation, Sorting, Stack
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        set<vector<int>> robots; // <position, idx, health, dirn>
        for(int i = 0; i < positions.size(); i++) {
            robots.insert({positions[i], i, healths[i], (directions[i] == 'L' ? 0 : 1)});
        }

        set<vector<int>> remaining; // <idx, health>
        vector<vector<int>> stk; // <idx, health of robots heading in the right direction>
        for(auto& robot : robots) {
            int pos = robot[0], idx = robot[1], h = robot[2], d = robot[3];
            if(d == 1) stk.push_back({idx, h});
            else {
                while(!stk.empty() && h > 0) {
                    if(stk.back()[1] <= h) {
                        if(h == stk.back()[1]) h = 0;
                        else h--;
                        stk.pop_back();
                    } else {
                        h = 0;
                        stk.back()[1]--;
                        if(stk.back()[1] == 0) stk.pop_back();
                    }
                }
                if(h > 0) remaining.insert({idx, h});
            }
        }
        for(vector<int> robot : stk) {
            remaining.insert(robot);
        }
        
        vector<int> output;
        for(auto& robot : remaining) {
            output.push_back(robot[1]);
        }
        return output;
    }
};
