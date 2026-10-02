class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> ans;
        for(int curr : nums){
            bool destroyed = false;
            while(!ans.empty() && curr < 0 && ans.back() > 0){
                if(ans.back() == -curr){
                    destroyed = true;
                    ans.pop_back();
                    break;
                } else if(ans.back() > -curr){
                    destroyed = true;
                    break;
                } else {
                    ans.pop_back();
                }
            }

            if(!destroyed){
                ans.push_back(curr);
            }
        }

        return ans;
    }
};