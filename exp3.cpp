#include<iostream>
using namespace std;
#include<conio.h>
template<class t>
int part(t a[],int m,int p)
{
	t v=a[m];
	int i=m,j=p;
	do
	{
		do
		{
			i=i+1;
		}while(a[i]<v);
		do
		{
			j=j-1;
		}while(a[j]>v);
		if(i<j)
		{
			t l;
			l=a[i];
			a[i]=a[j];
			a[j]=l;
		}
	}while(i<j);

	a[m]=a[j];
	a[j]=v;
	return j;
}

template<class t>
void quicksort(t a[],int p,int q)
{
	if(p<q)
	{
		int j=part(a,p,q+1);
		quicksort(a,p,j-1);
		quicksort(a,j+1,q);
	}
}
int main()
{
	int a[10],n;
	float b[10];
	char c[10];

	cout<<endl<<"\nEnter the number of integers:";
	cin>>n;
	cout<<endl<<"\nEnter the numbers: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	int q=0,h1=n-1;
	quicksort(a,q,h1);
	cout<<"\nThe sorted integers are:";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl<<"\nEnter the number of floating numbers:";
	cin>>n;
	cout<<endl<<"\nEnter the numbers: ";
	for(int i=0;i<n;i++)
		cin>>b[i];
	int l2=0,h2=n-1;
	quicksort(b,l2,h2);
	cout<<"\nThe sorted floating numbers are:";
	for(int i=0;i<n;i++)
	cout<<b[i]<<"  ";

	cout<<endl<<"\nEnter the number of characters:";
	cin>>n;
	cout<<endl<<"\nEnter the characters: ";
	for(int i=0;i<n;i++)
		cin>>c[i];
	int l3=0,h3=n-1;
	quicksort(c,l3,h3);
	cout<<"\nThe sorted characters are:";
	for(int i=0;i<n;i++)
	cout<<c[i]<<" ";
	getch();

}

