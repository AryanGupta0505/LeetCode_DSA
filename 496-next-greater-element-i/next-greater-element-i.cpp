class Solution {
public:
    vector<int> nge(vector<int> arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!=-1&&s.top()<=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(curr);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans(n1);
        vector<int> large(n2);
        large=nge(nums2,n2);
        for(int i=0;i<n2;i++){
            cout<<large[i]<<" ";
        }
        for(int i=0;i<n1;i++){
            int element=nums1[i];
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==element){
                    ans[i]=large[j];
                    break;
                }
            }
        }
        return ans;
    }
};