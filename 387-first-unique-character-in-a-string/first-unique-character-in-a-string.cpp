#include <utility>
#include <queue>
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>count;
        queue<pair<char,int>>q;
        int value=-1;
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            count[ch]++;
            q.push(make_pair(ch,i));
            while(!q.empty()){
                if(count[q.front().first]>1){
                    q.pop();
                }
                else{
                    ans.push_back(q.front().second);
                    break;
                }
            }
            if(q.empty()){
                ans.push_back(-1);
            }
        }
        return ans[ans.size()-1];
    }
};