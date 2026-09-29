class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        vector<int> inDegree(26, 0);
        vector<bool> encounter(26, false);
        vector<vector<bool>> keep(26, vector<bool>(26, false));

        for(string word : words){
            for(char ch : word){
                encounter[ch-'a'] = true;
            }
        }

        int j = 0;
        for (int i = 1; i < words.size(); i++) {
            int len = min(words[i - 1].size(), words[i].size());
            string str1 = words[i - 1];
            string str2 = words[i];
            j = 0;
            while (j < len && str1[j] == str2[j]) {
                j++;
            }
            if (j == len) {
                if (str1.size() > str2.size()) return "";

                continue;
            }
            if (!keep[str1[j] - 'a'][str2[j] - 'a']) {
                adj[str1[j]].push_back(str2[j]);
                // encounter[str2[j] - 'a'] = true;
                // encounter[str1[j] - 'a'] = true;
                keep[str1[j] - 'a'][str2[j] - 'a'] = true;
                inDegree[str2[j] - 'a'] += 1;
            }
        }

        queue<char> q;
        for (int i = 0; i < 26; i++) {
            if (encounter[i]) {
                if (inDegree[i] == 0) {
                    q.push('a' + i);
                }
            }
        }

        string ans = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();

            ans += curr;

            for (char ch : adj[curr]) {
                inDegree[ch - 'a']--;
                if (encounter[ch-'a'] && inDegree[ch - 'a'] == 0) {
                    q.push(ch);
                }
            }
        }

        int total = 0;
        for(bool val : encounter){
            if(val){
                total++;
            }
        }
        return total != ans.size() ? "" : ans;
    }
};
