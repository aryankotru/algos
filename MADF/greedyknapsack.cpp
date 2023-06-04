#include<iostream>
using namespace std;
int i,j;
void knapsack(float a[],float b[],int m,int n)
{
float x[20];
int u=m;
float z[20];
for(i=0;i<n;i++)
{
z[i]=b[i]/a[i];
cout<<"p/w"<<i+1<<":"<<z[i]<<endl;
}
cout<<endl;
cout<<"Decreasing order wrt p/w:\n"<<endl;
for(i=0;i<n;i++)
{
x[i]=0.0;
float f;
for(j=0;j<n-i-1;j++)
{
if(z[j]<z[j+1])
{
f=z[j];
int r=a[j];
z[j]=z[j+1];
a[j]=a[j+1];
z[j+1]=f;
a[j+1]=r;
}
}
}
for(i=0;i<n;i++)
cout<<a[i]<<endl;
cout<<endl;
for(i=0;i<n;i++)
{
if(a[i]>u)
break;
x[i]=1.0;
u=u-a[i];
}
if(i<n)
x[i]=u/a[i];
cout<<"solution:"<<endl;
for(i=0;i<n;i++)
{
cout<<a[i]<<"->"<<x[i]<<endl;
}
}
int main()
{
float w[20],p[20];
int t,c;
cout<<"Enter the capacity of the bag:";
cin>>c;
cout<<"Enter the no of elements:";
cin>>t;
cout<<endl;
for(i=0;i<t;i++)
{
cout<<"Enter the weight:"<<i+1<<":";
cin>>w[i];
cout<<"Enter the profit:"<<i+1<<":";
cin>>p[i];
cout<<endl;
}
knapsack(w,p,c,t);
}
