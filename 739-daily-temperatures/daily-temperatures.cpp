class Solution {
public:
    vector<int> nge(vector<int> arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!=-1&&arr[s.top()]<=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        ans=nge(temperatures,n);
        for(int i=0;i<n;i++){
            if(ans[i]==-1) ans[i]=0;
            else{
                ans[i]-=i;
            }
        }
        return ans;
    }
};