#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

int main()
{
    int i,j,r1,r2,N,M,T;
    char S[105];

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&N,&M);
        int P[N+2][M+2];
        int Q[N+2][M+2];
        int R[N+2][M+2];
        getchar();
        for(i=0;i<N;++i)
        {
            gets(S);
            for(j=0;j<M;++j)
            {
                P[i][j]=(S[j]=='0')?0:1;
            }
        }

        for(i=0;i<(N);++i)
            P[i][M]=0;

        for(i=0;i<M;++i)
            P[N][i]=0;

        Q[0][0]=P[0][0]+P[1][0]+P[0][1];

        for(i=1;i<M-1;++i)
            Q[0][i]= Q[0][i-1] + P[1][i]+ P[0][i+1],R[0][i]=1;

        Q[0][M-1]= Q[0][M-2]+ P[1][M-1];
        R[0][M-1]=1;

        for(i=1;i<N-1;++i)
            Q[i][0]= Q[i-1][0] + P[i+1][0]+ P[i][1],R[i][0]=2;

        Q[N-1][0]= Q[N-2][0] + P[N-1][1];
        R[N-1][0]=2;

        for(i=1;i<N;i++)
        {
            for(j=1;j<M;j++)
            {
                r1=R[i][j-1]==1?Q[i][j-1]+ P[i+1][j]+ P[i-1][j]+ P[i][j+1]:Q[i][j-1]+ P[i+1][j]+ P[i][j+1];
                r2=R[i-1][j]== 2? Q[i-1][j]+ P[i][j+1]+ P[i+1][j] + P[i][j-1]:Q[i-1][j] + P[i][j+1]+ P[i+1][j];
                if(r1<r2)
                    Q[i][j]=r1,R[i][j]=1;
                if(r2<r1)
                    Q[i][j]=r2,R[i][j]=2;
                if(r1==r2)
                    Q[i][j]=r1,R[i][j]=3;
            }
        }
        printf("%d\n",Q[N-1][M-1]);
    }
    return 0;
}

