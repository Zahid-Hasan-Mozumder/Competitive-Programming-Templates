#include <bits/stdc++.h>
#include <climits>

using namespace std;

bool floydWarshall(vector<vector<int>> &cost){
    int n = cost.size();
    for(int i=0; i<n; i++) cost[i][i] = 0;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    // Checking if there exist any negative wait cycle
    for(int i=0; i<n; i++){
        if(cost[i][i] < 0)
            return true;
    }
    return false;
}

int main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> cost(n, vector<int>(n, 1e9));
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        cost[u][v] = w;
        cost[v][u] = w;
    }
  
    if(floydWarshall(cost)) 
        cout<< "Negative Weight Cycle is Present" << '\n';
    else
        cout<< "Negative Weight Cycle is Not Present" << '\n';
  
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cost[i][j] == 1e9) cout<< -1 << " ";
            else cout<< cost[i][j] << " ";
        }
        cout<< '\n';
    }
}
