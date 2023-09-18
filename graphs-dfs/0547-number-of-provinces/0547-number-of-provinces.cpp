#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:

    // void dfsHelp(int node, bool aVisited[], unordered_map<int, vector<int>> &aNeighbors){
    //     if (aVisited[node]) return;
    //     else {
    //         aVisited[node] = true;
    //         for(int v: aNeighbors[node]){
    //             dfsHelp(v, aVisited, aNeighbors);
    //         }
    //         return;
    //     }
    // }

    void dfsHelp(int node, bool aVisited[], vector<vector<int>> &aIsConnected){
        if (aVisited[node]) return;
        else {
            aVisited[node] = true;
            for(int i=0; i<aIsConnected[node].size();i++){
                if (aIsConnected[node][i]==1)
                    dfsHelp(i, aVisited, aIsConnected);
            }
            return;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // get num of nodes
        int ncomp = 0;
        // unordered_map<int, vector<int>> neighbors;

        // for (int u=0; u<n; u++){
        //     for (int v=u+1; v<n; v++){
        //         if (isConnected[u][v]==1) {
        //             neighbors[u].push_back(v);
        //             neighbors[v].push_back(u);
        //         }
        //     }
        // }

        bool visited[n];
        for(int u=0; u<n; u++){
            visited[u]=false;
        }

        for(int u=0; u<n; u++){
            if (! visited[u]){
                ncomp++;
                // dfsHelp(u, visited, neighbors);
                dfsHelp(u, visited, isConnected);

            }
        }
        return ncomp;
    }
};

int main(){
    // vector<vector<int>> myIsConnected = {{1,1,0}, {1,1,0}, {0,0,1}};
    vector<vector<int>> myIsConnected = {{1,0,0}, {0,1,0}, {0,0,1}};
    Solution solver;
    int numProvinces = solver.findCircleNum(myIsConnected);
    cout << "num provinces : " << numProvinces << endl;
}