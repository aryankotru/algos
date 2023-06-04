#include<iostream>
using namespace std;
int main(){
int n,m;
cout<<"Enter the number of nodes"<<endl;
cin>>n;
cout<<"Enter the number of edges"<<endl;
cin>>m;
int graph[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i==j){
graph[i][j]=0;
}
else{
graph[i][j]=INT_MAX;
}
}
}
for(int i=0;i<m;i++){
int a,b,wt;
cout<<"Enter the first node you want to connect"<<endl;
cin>>a;
cout<<"Enter the second node you want to connect"<<endl;
cin>>b;
cout<<"Enter the weight between them"<<endl;
cin>>wt;
graph[a][b]=wt;
}
cout<<"Before Applying Floyd warshall Algorithm"<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<i<<"===>"<<j<<"["<<graph[i][j]<<"]"<<endl;
}
cout<<endl;
}
int newgraph[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
newgraph[i][j]=graph[i][j];
}
}
for(int k=0;k<n;k++){
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(newgraph[i][k]==INT_MAX || newgraph[k][j]==INT_MAX)
continue;
else if(newgraph[i][k]+newgraph[k][j]<newgraph[i][j]){
newgraph[i][j]=newgraph[i][k]+newgraph[k][j];
}
}
}
}
cout<<"ALL PAIR SHORTEST PATH"<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<i<<"===>"<<j<<"["<<newgraph[i][j]<<"]"<<endl;
}
cout<<endl;
}
return 0;
}
