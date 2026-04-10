class Solution {
public:
    vector<int> merge(vector<int> first, vector<int> second){
        int i=0,j=0,k=0;
        int m=first.size();
        int n=second.size();
        vector<int> ans(m+n);
        while(i<m && j<n){
            if(first[i]<=second[j]){
                ans[k++]=first[i++];
            }
            else{
                ans[k++]=second[j++];
            }
        }
        while(i<m){
            ans[k++]=first[i++];
        }
        while(j<n){
            ans[k++]=second[j++];
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray;
        mergedArray=merge(nums1,nums2);
        int p=mergedArray.size();
        if(p%2==1) return mergedArray[p/2]/1.0;
        return (mergedArray[p/2 -1] +mergedArray[p/2])/2.0;
    }
};