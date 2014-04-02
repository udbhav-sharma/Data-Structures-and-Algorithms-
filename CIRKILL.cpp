#include<iostream>
#include<stdio.h>
#include<cmath>
#include<iomanip>

using namespace std;

struct coordinates
{
    double x,y;
}C[35],center;

double radius_square;

void draw_circle(coordinates A, coordinates B,coordinates C)
{
    double x3,x4,y3,y4,m1,m2;

    double denominator;

    denominator=(B.y-A.y);
    if(denominator==0)
    {
        m1=(A.x-C.x)/(C.y-A.y);
        m2=(B.x-C.x)/(C.y-B.y);
        x3=(A.x+C.x)/2.0;
        y3=(A.y+C.y)/2.0;
        x4=(B.x+C.x)/2.0;
        y4=(B.y+C.y)/2.0;
    }
    else
    {
        m1=(A.x-B.x)/(B.y-A.y);
        x3=(A.x+B.x)/2.0;
        y3=(A.y+B.y)/2.0;
        denominator=(B.y-C.y);
        if(denominator==0)
        {
            m2=(A.x-C.x)/(C.y-A.y);
            x4=(A.x+C.x)/2.0;
            y4=(A.y+C.y)/2.0;
        }
        else
        {
            m2=(B.x-C.x)/(C.y-B.y);
            x4=(B.x+C.x)/2.0;
            y4=(B.y+C.y)/2.0;
        }
    }

    if(m1==m2)
    {
        center.x=A.x;
        center.y=A.y;
        radius_square=0;
    }

    else
    {
        center.x=(y3-y4 + m2*x4 - m1*x3)/(m2-m1);
        center.y=(m2*y3 - m1*m2*x3 - m1*y4 + m1*m2*x4)/(m2-m1);
        radius_square=pow((center.y - A.y),2)+pow((center.x - A.x),2);
    }
}

bool check_point(coordinates A)
{
    return (pow((center.y - A.y),2) + pow((center.x - A.x),2) <=radius_square);
}

int main()
{
    int T,i,j,k,t,count;
    double N,ans;

    cin>>T;

    while(T--)
    {
        cin>>N;

        for(i=0;i<N;i++)
            cin>>C[i].x>>C[i].y;

        count=0;
        for(i=0;i<N;i++)
        {
            for(j=i+1;j<N;j++)
            {
                for(k=j+1;k<N;k++)
                {
                    draw_circle(C[i],C[j],C[k]);
                    for(t=0;t<N;t++)
                        if(t!=i && t!=j && t!=k)
                            if(check_point(C[t]))
                                count++;
                }
            }
        }
        cout.precision(6);
        cout<<(6.0*count)/(N*(N-1)*(N-2)*(N-3))<<endl;
    }
    return 0;
}
