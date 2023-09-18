#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:

    double dfs(int u, int v, vector<bool> & aVisited, vector<vector<double>> aWeights, double aDistance){

        double retDistance;
        for (int i =0; i<aVisited.size(); i++){ 
            if (aWeights[u][i]!=0 && aVisited[i]==false){ // includes itself
                aVisited[i] = true;
                if (i == v) {
                    return aDistance * aWeights[u][i];
                } else {
                    retDistance = dfs(i, v, aVisited, aWeights, aDistance * aWeights[u][i]);
                    if (retDistance!=-1.0) {
                        return retDistance;
                    }
                }
            }
        }
        return -1.0; // if there was no route via this node that reaches v then return -1
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 1. find a set of variables
        unordered_map<string, int> varIndex;
        int index = 0;
        for (auto pair: equations){
            for (int i=0; i< pair.size(); i++){
                if (varIndex.find(pair[i])==varIndex.end()) {
                    varIndex[pair[i]] = index;
                    index++;
                }
            }
        }

        // 2. initialize 0 array of len(varIndex) x len(varIndex)
        vector<vector<double>> weights(varIndex.size(), vector<double>(varIndex.size(), 0.0));
        
        // 3. loop over equations & values and fill in the weights matrix
        for (int i =0; i < equations.size(); i++){
            weights[varIndex[equations[i][0]]][varIndex[equations[i][1]]] = values[i];
            weights[varIndex[equations[i][1]]][varIndex[equations[i][0]]] = double(1.0 /values[i]);
        }

        // 4. given a query (u, v), dfs starting from u keep track of weightmultiple and return it when reaching v
        vector<double> answers;
        int numVars = varIndex.size();
        for (auto pair: queries){
            vector<bool> visited(numVars, false);
            double distance = 1.0;
            if(varIndex.find(pair[0])==varIndex.end() || varIndex.find(pair[1])==varIndex.end()) answers.push_back(-1.0);
            else {answers.push_back(dfs(varIndex[pair[0]], varIndex[pair[1]], visited, weights, distance));}
        }
        return answers;
    }
};

int main(){
    vector<vector<string>> equations = {{"x1","x2"}, {"x2","x3"}, {"x1","x4"}, {"x2","x5"}};
    vector<double> values={3.0,0.5,3.4,5.6};
    vector<vector<string>> queries = {{"x2","x4"},{"x1","x5"},{"x1","x3"},{"x5","x5"},{"x5","x1"},{"x3","x4"},{"x4","x3"},{"x6","x6"},{"x0","x0"}}; 
    vector<double> answers;

    Solution solver;
    answers = solver.calcEquation(equations, values, queries);
    for (double item: answers){
        cout << item << " ";
    }
    cout << endl;
}