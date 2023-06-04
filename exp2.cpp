#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
void printarray(T arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

template<class T>

void merge(T arr[],int mid,int low,int high)
{
	int i,j,k,B[100];
	i=low;
	j=mid+1;
	k=low;

	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			B[k]=arr[i];
			i++;
			k++;

		}
		else
		{
			B[k]=arr[j];
			j++;
			k++;
		}
	}

	while(i<=mid)
	{
		B[k]=arr[i];
			k++;
			i++;
		}

	while(j<=high)
	{
		B[k]=arr[j];
			k++;
			j++;
		}

	for(int i=low;i<=high;i++)
	{
		arr[i]=B[i];
	}
}

template<class T>

void mergesort(T arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,mid,low,high);
	}
}

int main()
{
	int i,n;
	int arr1[]={2,55,4,7,1};
	n=5;
	cout<<"The unsorted array:";
	printarray(arr1,n);
	for(i=0;i<5;i++)
	{
	mergesort(arr1,0,4);
	}
	cout<<endl;
	cout<<"The sorted array:";
	printarray(arr1,n);



	char arr2[]={'a','j','h','c','m'};
	cout<<endl;
	cout<<"The unsorted array:";
	printarray(arr2,n);
	for(i=0;i<5;i++)
	{
	
	mergesort(arr2,0,4);
	}
	cout<<endl;
	cout<<"The sorted array:";
	printarray(arr2,n);

	long int arr3[]={800,34567,4567,876,45678};
	cout<<endl;
	cout<<"The unsorted array:";
	printarray(arr3,n);
	for(i=0;i<5;i++)
	{
	
	mergesort(arr3,0,4);
	}
	cout<<endl;
	cout<<"The sorted array:";
	printarray(arr3,n);

	double arr4[]={800.00,345,4567.00,8,45678};
	cout<<endl;
	cout<<"The unsorted array:";
	printarray(arr4,n);
	for(i=0;i<5;i++)
	{
	
	mergesort(arr4,0,4);
	}
	cout<<endl;
	cout<<"The sorted array:";
	printarray(arr4,n);
	getch();

}

