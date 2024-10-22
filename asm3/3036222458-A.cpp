#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void checkVector(int s,vector<bool>* visited, vector<vector<int>> v) {
    if ((*visited)[s]) {
        return;
    }
    (*visited)[s] = true;
    for (int i = 0; i < v[s].size(); i++) {
        checkVector(v[s][i], visited,v);
    }
}

vector<vector<int>> inputVector(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++){
        vector<int> v1;
        v.push_back(v1);
    }

    for (int i = 0; i < m; i++){
        int a,b,t;
        cin >> a >> b >> t;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    return v;
}

int main(){
    int s;
    vector<vector<int>> v = inputVector();
    vector<bool> visited(v.size(),false);
    cin >> s;
    checkVector(s,&visited,v);
    cout << count(visited.begin(),visited.end(),false) << endl;
}