class Solution {
public:
    bool check(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited,unordered_map<int,list<int>> &adj){
        visited[node]=true;
        dfsVisited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                bool cycle=check(i,visited,dfsVisited,adj);
                if(cycle) return true;
            }
            else if(dfsVisited[i]) return true;
        }
        dfsVisited[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool finish=check(i,visited,dfsVisited,adj);
                if(finish) return false;
            }
        }
        return true;
    }
};