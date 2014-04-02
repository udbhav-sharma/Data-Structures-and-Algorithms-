#include<iostream>
#include<cstring>

using namespace std;

char X[100]=" ",Y[100]=" ";
int B[100][100],C[100][100],X_len,Y_len;

/*
For immediate left i have used value 1
For diagonally upwards i have used value 2
For upwards i have used value 3
*/

void LCS()
{
    int i,j;

    for(i=1;i<=X_len;i++)
    {
        for(j=1;j<=Y_len;j++)
        {
            if(X[i]==Y[j])
            {
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]=2;
            }
            else if(C[i][j-1]>=C[i-1][j])
            {
                C[i][j]=C[i][j-1];
                B[i][j]=1;
            }
            else
            {
                C[i][j]=C[i-1][j];
                B[i][j]=3;
            }
        }
    }
}

void PRINT_LCS(int m,int n)
{
    if(m==0 || n==0)
        return ;
    switch (B[m][n])
    {
        case 1:
            PRINT_LCS(m,n-1);
            break;
        case 2:
            PRINT_LCS(m-1,n-1);
            cout<<X[m];
            break;
        case 3:
            PRINT_LCS(m-1,n);
            break;
    }
}

int main()
{
    char temp[100];
    cout<<"Enter the sequences\n";

    cout<<"1:  ";
    cin>>temp;
    X_len=strlen(temp);
    strcat(X,temp);

    cout<<"\n2:  ";
    cin>>temp;
    Y_len=strlen(temp);
    strcat(Y,temp);

    LCS();

    cout<<"LCS is:\n";
    PRINT_LCS(X_len,Y_len);

    cout<<endl<<"With length:  "<<C[X_len][Y_len];

    return 0;
}
