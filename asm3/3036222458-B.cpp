#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<vector<int> > inputVector(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > v;
    for (int i = 0; i < n; i++){
        vector<int> v1(n,0);
        v.push_back(v1);
    }

    for (int i = 0; i < m; i++){
        int a,b,t;
        cin >> a >> b >> t;
        v[a][b] = t;
        v[b][a] = t;
    }
    return v;
}

int mindist(vector<int> dist, vector<bool> visited){
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < dist.size(); i++){
        if (dist[i] <= min && !visited[i]){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int dijkstra(int s, int d,vector<vector<int> > v){
    vector<int> dist(v.size(), INT_MAX);
    vector<bool> visited(v.size(), false);
    int index;
    dist[s] = 0;
    for (int i = 0;i < v.size();i++){
        index = mindist(dist, visited);
        visited[index] = true;
        for (int j = 0; j < v.size(); j++){
            if (!visited[j] && v[index][j] && dist[index] != INT_MAX && dist[index] + v[index][j] < dist[j]){
                dist[j] = dist[index] + v[index][j];
            }
        }
    }
    if (dist[d] == INT_MAX){
        return -1;
    }
    else{
        return dist[d];
    }
}

int main(){
    int s,d;
    vector<vector<int> > v = inputVector();
    cin >> s >> d;
    cout << dijkstra(s,d,v) << endl;
}