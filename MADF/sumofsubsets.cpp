#include<iostream>
using namespace std;
void sumSub(int n,int i,int sum,int w,int remSum,int subset[],int set[])
{
if((sum+set[i]<=w)&& (remSum>=0))
{
subset[i]=1;
sumSub(n,i+1,sum+set[i],w,remSum-set[i],subset,set);
subset[i]=0;
sumSub(n,i+1,sum,w,remSum-set[i],subset,set);
}
else
if(sum==w)
{
cout<<endl;
for(int j=0;j<n;j++) cout<<subset[j]<<" ";
}
}
int main()
{
int n,w,remSum=0;
cout<<"Enter number of elements in set: ";
cin>>n;
int* set=new int[n];
int* subset=new int[n];
for(int i=0;i<n;i++) subset[i]=0;
cout<<"\nEnter "<<n<<" elements: ";
for(int i=0;i<n;i++)
{
cin>>set[i];
remSum+=set[i];
}
cout<<"\nEnter the sum you want: ";
cin>>w;
cout<<endl<<"Required subsets are: \n";
sumSub(n,0,0,w,remSum,subset,set);
}
