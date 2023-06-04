//Binary Search code
#include<iostream>
#include<conio.h>
using namespace std;

int BinarySearch(int low,int high,int element,int a[])
{
	int mid;
	if(low>high)
	{
		cout<<"Element not found"<<endl;
	}
	else if(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==element)
		{
		cout<<"Number is found at index"<<mid;
		return 0;
		}
		else if(a[mid]<element)
	{
		BinarySearch(mid+1,high,element,a);
		}
		else if(a[mid]>element)
		{
		BinarySearch(low,mid-1,element,a);
	}
	

	}
	
}
int main()
{
	int a[100],element,n,i,low,high;
	cout<<"Enter the size of array:"<<endl;
	cin>>n;
	cout<<"The sorted values are:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the element to be searched:"<<endl;
	cin>>element;
	low=0;
	high=n-1;
	BinarySearch(low,high,element,a);	
	getch();

}
