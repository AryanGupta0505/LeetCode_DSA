class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s[s.length()-1]==' '){
            s.pop_back();
        }
        int cnt=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' ') break;
            cnt++;
        }
        return cnt;
    }
};