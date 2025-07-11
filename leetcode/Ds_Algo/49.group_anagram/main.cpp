class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto &s:strs){
            string sorted=s;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(s);
        }
        vector<vector<string>>res;
        for(auto &str:mp){
            res.push_back(str.second);
        }
        return res;
    }
};