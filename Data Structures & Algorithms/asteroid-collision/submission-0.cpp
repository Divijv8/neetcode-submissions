class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for(int current : asteroids){
            bool des = false;

            while(!ans.empty() && current < 0 && ans.back() > 0){
                if(abs(ans.back()) == abs(current)){
                    ans.pop_back();
                    des = true;
                    break;
                } else if(abs(ans.back()) > abs(current)){
                    des = true;
                    break;
                } else {
                    ans.pop_back();
                }
            }

            if(!des){
                ans.push_back(current);
            }
        }

        return ans;
    }
};