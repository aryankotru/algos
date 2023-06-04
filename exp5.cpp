#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cout<<"Enter the number of nodes"<<endl;
cin>>n;
cout<<"Enter the number of edges"<<endl;
cin>>m;
vector<pair<int,int>> graph[n+1];
cout<<"Enter the nodes you want to connect"<<endl;
for(int i=0;i<m;i++){
int n1,n2,wt;
cout<<"Enter node-1"<<endl;
cin>>n1;
cout<<"Enter node-2"<<endl;
cin>>n2;
cout<<"Enter the weight between them"<<endl;
cin>>wt;
graph[n1].push_back({n2,wt});
graph[n2].push_back({n1,wt});
}
for(int i=0;i<n;i++){
cout<<i<<"==>";
for(const pair<int,int>& x:graph[i]){
cout<<x.first<<"["<<x.second<<"] ";
}
cout<<endl;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int distance[n+1];
for(int i=0;i<n;i++){
distance[i]=INT_MAX;
}
int source;
cout<<"Enter the source node"<<endl;
cin>>source;
distance[source]=0;
pq.push(make_pair(0,source));
while(!pq.empty()){
int distance1=pq.top().first;
int node=pq.top().second;
pq.pop();
vector<pair<int,int>>::iterator ite;
for(ite=graph[node].begin();ite!=graph[node].end();++ite){
//in this graph second element is the distance
int nod=ite->first;
int dist=ite->second;
if(distance[nod]>(distance[node]+dist)){
distance[nod]=distance[node]+dist;
pq.push(make_pair(distance[nod],nod));
}
}
}
cout<<"The distance from source node to all the other nodes are: "<<endl;
for(int i=1;i<n+1;i++){
cout<<source<<"--->"<<i<<"["<<distance[i]<<"]"<<endl;
}
return 0;
}