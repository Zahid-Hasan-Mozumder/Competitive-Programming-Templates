#include <bits/stdc++.h>
#include <climits>

using namespace std;

vector<int> size, parent;

void init(int n){
    parent.clear(); parent.resize(n + 1);
    size.clear(); size.resize(n + 1, 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
}

int find(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int u, int v){
    int pu = find(u);
    int pv = find(v);
    // If u and v are in different group
    if(pu != pv){
        // Always keeping the big tree or group at left
        if(size[pu] < size[pv])
            swap(pu, pv);
        // Attaching right smallest group to left biggest group
        parent[pv] = pu;
        size[pu] += size[pv];
    }
}

int main(){
    
    int n, q; cin >> n >> q;
    
    init(n);
    
    while(q--){
        int qt; cin >> qt;
        // 1 : Add an edge between this two nodes
        // 2 : Does this two nodes belong to the same component
        if(qt == 1){
            int u, v; cin >> u >> v;
            Union(u, v);
        }
        else if(qt == 2){
            int u, v; cin >> u >> v;
            if(find(u) == find(v)) cout<< "Belongs to the same component" << '\n';
            else cout<< "Does not belong to the same component" << '\n';
        }
    }
}
