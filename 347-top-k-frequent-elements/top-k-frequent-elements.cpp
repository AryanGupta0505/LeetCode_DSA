class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1st sol
        // unordered_map<int, int> freq;
        // for(int num : nums) {
        //     freq[num]++;
        // }
        // // Store {frequency, number}
        // vector<pair<int, int>> arr;
        // for(auto &it : freq) {
        //     arr.push_back({it.second, it.first});
        // }
        // // Sort by frequency
        // sort(arr.begin(), arr.end(),
        //      greater<pair<int, int>>());
        // vector<int> ans;
        // for(int i = 0; i < k; i++) {
        //     ans.push_back(arr[i].second);
        // }
        // return ans;
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto &it : freq) {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};