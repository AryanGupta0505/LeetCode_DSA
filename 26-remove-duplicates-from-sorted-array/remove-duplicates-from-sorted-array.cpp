class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> count;
        int n=nums.size();
        int index=0;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
            if(count[nums[i]]<=1){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};