class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for(int current : asteroids){
            bool destroyed = false;

            while(!ans.empty() && ans.back() > 0 && current < 0){
                if(ans.back() == -current){
                    ans.pop_back();
                    destroyed = true;
                    break;
                } else if(ans.back() > -current){
                    destroyed = true;
                    break;
                } else {
                    ans.pop_back();
                }
            }

            if(!destroyed){
                ans.push_back(current);
            }
        }

        return ans;
    }
};