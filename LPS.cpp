#include<iostream>
#include<cstring>

using namespace std;

#define LEFT 1
#define DIAGONAL 2
#define UP 3

char X[100]=" ",Y[100]=" ";
int B[100][100],C[100][100],X_len,Y_len;

void LPS()
{
    int i,j;

    for(i=1;i<=X_len;i++)
    {
        for(j=1;j<=Y_len;j++)
        {
            if(X[i]==Y[j])
            {
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]=DIAGONAL;
            }
            else if(C[i][j-1]>=C[i-1][j])
            {
                C[i][j]=C[i][j-1];
                B[i][j]=LEFT;
            }
            else
            {
                C[i][j]=C[i-1][j];
                B[i][j]=UP;
            }
        }
    }
}

void PRINT_LPS(int m,int n)
{
    if(m==0 || n==0)
        return ;
    switch (B[m][n])
    {
        case LEFT:
            PRINT_LCS(m,n-1);
            break;
        case DIAGONAL:
            PRINT_LCS(m-1,n-1);
            cout<<X[m];
            break;
        case UP:
            PRINT_LCS(m-1,n);
            break;
    }
}

int main()
{
    char temp1[100];
    char temp2[100];
    cout<<"Enter the sequence\n";

    cout<<"1:  ";
    cin>>temp1;
    X_len=strlen(temp1);
    strcat(X,temp1);

    temp2[X_len]='\0';
    for(int i=0;i<X_len;i++)
        temp2[X_len-1-i]=temp1[i];
    Y_len=strlen(temp1);
    strcat(Y,temp2);

    LPS();

    cout<<"LPS is:\n";
    PRINT_LPS(X_len,Y_len);

    cout<<endl<<"With length:  "<<C[X_len][Y_len];

    return 0;
}
