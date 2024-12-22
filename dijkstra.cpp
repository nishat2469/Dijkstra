#include<bits/stdc++.h>

using namespace std;
#define inf INT_MAX
#define A pair<int,int>

vector<pair<int,int>>adj_list[1000];
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

priority_queue<A,vector<A>,greater<A>>pq;
//A=pair<int,int>

int cost[1000];
int parent[1000];

void Dijkstra(int s){
cost[s]=0;
parent[s]=s;
pq.push({0,s});

while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();

    for(int i=0;i<adj_list[u].size();i++){
        int v= adj_list[u][i].first;
        int w=adj_list[u][i].second;

        if(cost[u]+w<cost[v]){
            cost[v]=cost[u]+w;
            parent[v]=u;
            pq.push({cost[v], v});
        }

    }
}





}

int main(){
int nodes, edges;

cin>>nodes>>edges;

int u,v,w;
for(int i=0;i<edges;i++){
    cin>>u>>v>>w;
    //adj_list[u].push_back(make_pair(v,w));
    adj_list[u].push_back({v,w});
    //adj_list[v].push_back({u,w});

    cost[u]=inf;
    cost[v]=inf;
}

int source, destination;
cin>>source>>destination;

Dijkstra(source);

cout<<"Cost : "<<cost[destination]<<endl;

int now=destination;
vector<int>path;
path.push_back(now);
while(parent[now]!=now){
    now=parent[now];
    path.push_back(now);
}
cout<<"Path is: "<<endl;
reverse(path.begin(),path.end());
for(int i=0;i<path.size();i++){
    if(i==path.size()-1){
    cout<<path[i]<<endl;
    }
    else{
     cout<<path[i]<<"-->";

    }
}

return 0;
}
/*
6 8
1 2 2
1 3 4
2 4 7
2 3 1
3 5 3
5 4 2
5 6 5
4 6 1
1 6
*/
