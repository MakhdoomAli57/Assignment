#include<iostream>
using namespace std;
class bankerwala_alg
{
    int a,h,seqq[20],all[20][20],rnn[20][20],avl[20],ed;
    int com_pr();
public:
    void getdata();
    void safe_seqq();
};
void bankerwala_alg::getdata()
{
    cout<<"number of processes likho  : ";
    cin>>a;
    cout<<"number of resources bhi bta dou : ";
    cin>>h;
    cout<<" number of instances available of each resource ye tou btana paray ga : ";
    for(int k=0;k<h;k++)
        cin>>avl[k];
    for(int k=0;k<a;k++)
    {
        cout<<"instances of resources allocated ki tadad p["<<k<<"] : ";
        for(int y=0;y<h;y++)
            cin>>all[k][y];
    }
    for(int k=0;k<a;k++)
    {
        cout<<"max no. of instances of resources process p["<<k<<"] needs : ";
        for(int y=0;y<h;y++)
            cin>>rnn[k][y];
    }
}
int bankerwala_alg::com_pr()
{
    int flag=0,fl=0;
    for(int k=0;k<a;k++)
    {
        for(int j=0;j<ed;j++)
            if(a==seqq[j])
            {
                fl=1;
                break;
            }
        if(fl!=1)
        {
            for(int j=0;j<h;j++)
            {
                if(avl[j]-rnn[a][j]+all[a][j]<0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                return a;
            flag=0;
        }
        fl=0;
    }
    return -1;
}
void bankerwala_alg::safe_seqq()
{
    int temp,flag=0;
    ed=0;
    for(int i=0;i<a;i++)
    {
        temp=com_pr();
        if(temp!=-1)
        {
            for(int y=0;y<h;y++)
                avl[y]+=all[temp][y];
            seqq[ed++]=temp;
        }
        else{
            cout<<"\n ye System ha  unsafe state  ";
            flag=1;
            break;}
    }
    if(flag!=1)
    {
        cout<<"     Safe sequence ban gya : ";
        for(int i=0;i<ed;i++)
            cout<<"p["<<seqq[i]<<"]  ";
    }
}
int main()
{
    bankerwala_alg bank;
    bank.getdata();
    bank.safe_seqq();
    return 0;
}

