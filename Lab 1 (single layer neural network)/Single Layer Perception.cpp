#include <bits/stdc++.h>
using namespace std;
int main()
{
    float weight[3]={0.2,0.3,0.4},t=0.5,sum=0.0,r=0.0;
    int i,j,k,l;
    float input[8][3]={0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,1,1};
    int ac[8]={0,0,0,0,1,1,1,1},output[8];
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for(l=0;l<5;l++)
    {
        cout<<"EPOCH"<<l<<endl;
        start:
        for(i=0;i<=3;i++)
        {
            sum=0.0;

            for(j=0;j<=2;j++)
            {
                sum=sum+weight[j]*input[i][j];
                if(sum>t && input[i][j]==1)
                {
                    k=j;
                    //cout<<k<<endl;
                }


            }
            //cout<<"Sum="<<sum<<endl;
            if(sum>t)
            {
                    weight[k]=weight[k]-input[i][k];
                    //cout<<weight[k]<<endl;
                    goto start;
            }

        }
        st:
        for(i=4;i<=7;i++)
        {
            sum=0.0;

            for(j=0;j<=2;j++)
            {
                sum=sum+weight[j]*input[i][j];
                //cout<<"de="<<i<<j<<"="<<"Input="<<input[i][j]<<"Weight="<<weight[j]<<endl;

                if(sum<t && input[i][j]==1 && j<3)
                {
                    k=j;
                    //cout<<k<<endl;
                }

            }
            //cout<<"Sum="<<i<<"="<<sum<<endl;
            //k=(i%3)-1;
            if(sum<t)
            {
                    weight[k]=weight[k]+input[i][k];
                    //cout<<"Input"<<k<<input[i][k]<<endl;
                    //cout<<"Weight"<<i<<k<<"="<<weight[k]<<endl;
                    goto st;

            }

         }
         for(k=0;k<3;k++)
         {
              cout<<"Weight="<<weight[k]<<endl;
         }
         cout<<"......................"<<endl;
    }



    cout<<"Final Weight"<<endl;
    for(k=0;k<3;k++)
    {
        cout<<weight[k]<<endl;
    }

    for(i=0;i<8;i++)
    {
        for(j=0;j<3;j++)
        {
            r=r+weight[j]*input[i][j];
        }
        if(r>t)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }




    return 0;


}
