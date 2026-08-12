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
        //2nd
        // unordered_map<int, int> freq;
        // for(int num : nums) {
        //     freq[num]++;
        // }
        // priority_queue<pair<int, int>> pq;
        // for(auto &it : freq) {
        //     pq.push({it.second, it.first});
        // }
        // vector<int> ans;
        // for(int i = 0; i < k; i++) {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        //3rd
        // unordered_map<int, int> freq;
        // // Count frequencies
        // for(int num : nums) {
        //     freq[num]++;
        // }
        // // Min heap: {frequency, number}
        // priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        // for(auto &it : freq) {
        //     pq.push({it.second, it.first});
        //     if(pq.size() > k) {
        //         pq.pop();
        //     }
        // }
        // vector<int> ans;
        // while(!pq.empty()) {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;
        //4th
        int n = nums.size();
        unordered_map<int, int> freq;
        // Step 1: Count frequencies
        for(int num : nums) {
            freq[num]++;
        }
        // Step 2: Create buckets
        vector<vector<int>> bucket(n + 1);
        // Step 3: Put numbers into frequency buckets
        for(auto &it : freq) {
            int num = it.first;
            int count = it.second;
            bucket[count].push_back(num);
        }
        // Step 4: Traverse from highest frequency
        vector<int> ans;
        for(int i = n; i >= 1 && ans.size() < k; i--) {
            for(int num : bucket[i]) {
                ans.push_back(num);
                if(ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};