class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char,int> count;
        for(int i=0;i<s.length();i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        for(auto i:count){
            if(i.second!=0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //1st sol -tle
        // vector<vector<string>> ans;
        // vector<bool> used(strs.size(), false);
        // for(int i = 0; i < strs.size(); i++) {
        //     if(used[i])
        //         continue;
        //     vector<string> group;
        //     group.push_back(strs[i]);
        //     used[i] = true;
        //     for(int j = i + 1; j < strs.size(); j++) {
        //         if(!used[j] && isAnagram(strs[i], strs[j])) {
        //             group.push_back(strs[j]);
        //             used[j] = true;
        //         }
        //     }
        //     ans.push_back(group);
        // }
        // return ans;
        //2nd sol o(nklogk)
        // unordered_map<string, vector<string>> mp;
        // for(string s:strs) {
        //     string key = s;
        //     sort(key.begin(), key.end());
        //     mp[key].push_back(s);
        // }
        // vector<vector<string>> ans;
        // for(auto i: mp) {
        //     ans.push_back(i.second);
        // }
        // return ans;
        //3rd sol o(nk)
                unordered_map<string, vector<string>> mp;

        for(string s : strs) {
            int count[26] = {0};
            for(char c : s)
                count[c - 'a']++;

            string key;
            for(int i = 0; i < 26; i++) {
                key += to_string(count[i]);
                key += '#';
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto i: mp) {
            ans.push_back(i.second);
        }
        return ans;


    }
};