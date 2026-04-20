// class TrieNode{
//     public:
//         char data;
//         TrieNode* children[26];
//         int childCount;
//         bool isTerminal;
//         TrieNode(char ch){
//             data=ch;
//             for(int i=0;i<26;i++){
//                 children[i]=NULL;
//             }
//             childCount=0;
//             isTerminal=false;
//         }
// };
// class Trie{
//     public:
//         TrieNode* root;
//         Trie(char ch){
//             root=new TrieNode(ch);
//         }
//         void insertUtil(TrieNode* root,string word){
//             if(word.length()==0){
//                 root->isTerminal=true;
//                 return;
//             }
//             int index=word[0]-'a';
//             TrieNode* child;
//             if(root->children[index]!=NULL){
//                 child=root->children[index];
//             }
//             else{
//                 child=new TrieNode(word[0]);
//                 root->childCount++;
//                 root->children[index]=child;
//             }
//             insertUtil(child,word.substr(1));
//         }
//         void insertWord(string word){
//             insertUtil(root,word);
//         }
//         void lcp(string str,string &ans){
//             TrieNode* temp = root;
//             for(int i=0;i<str.length();i++){
//                 char ch=str[i];
//                 if(temp->childCount==1){
//                     ans.push_back(ch);
//                     int index=ch-'a';
//                     temp=temp->children[index];
//                 }
//                 else{
//                     break;
//                 }
//                 if(temp->isTerminal){
//                     break;
//                 }
//             }
//         }
// };
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // for (auto &s : strs) {
        //     if (s.empty()) return "";
        // }
        // Trie* t=new Trie('\0');
        // for(int i=0;i<strs.size();i++){
        //     t->insertWord(strs[i]);
        // }
        // string first=strs[0];
        // string ans="";
        // t->lcp(first,ans);
        // return ans;
        string ans="";
        for(int i=0;i<strs[0].length();i++){
            char ch=strs[0][i];
            bool match=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j].length()<i||ch!=strs[j][i]){
                    match=false;
                    break;
                }
            }
            if(match==false) break;
            else ans.push_back(ch);
        }
        return ans;
    }
};