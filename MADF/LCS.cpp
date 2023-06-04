#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
int mat[10][10];
int lcs(string X, string Y, int m, int n)
{
mat[m+1][n+1];
for (int i = 0; i <= m; i++)
{
for (int j = 0; j <= n; j++)
{
if (i == 0 || j == 0)
mat[i][j] = 0;
else if (X[i - 1] == Y[j - 1])
mat[i][j] = mat[i - 1][j - 1] + 1;
else
mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
}
}
return mat[m][n];
}
int main()
{
string X,Y;
cout<<"Enter String 1: ";
getline(cin,X);
cout<<endl<<"Enter String 2: ";
getline(cin,Y);
int m = X.size();
int n = Y.size();
cout <<endl<< "Length of LCS is: " << lcs(X, Y, m, n);
getch();
}
