#include<iostream>
using namespace std;
class bankers
{
    int p,r,seq[20],al[20][20],rn[20][20],avl[20],ed;
    int com();
public:
    void getdata();
    void safe_seq();
};
void bankers::getdata()
{
    cout<<"Enter number of processes : ";
    cin>>p;
    cout<<"Enter number of resources : ";
    cin>>r;
    cout<<"Enter number of instances available of each resource : ";
    for(int i=0;i<r;i++)
        cin>>avl[i];
    for(int i=0;i<p;i++)
    {
        cout<<"Enter no. of instances of resources allocated to process p["<<i<<"] : ";
        for(int y=0;y<r;y++)
            cin>>al[i][y];
    }
    for(int i=0;i<p;i++)
    {
        cout<<"Enter max no. of instances of resources process p["<<i<<"] needs : ";
        for(int y=0;y<r;y++)
            cin>>rn[i][y];
    }
}
int bankers::com()
{
    int flag=0,fl=0;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<ed;j++)
            if(i==seq[j])
            {
                fl=1;
                break;
            }
        if(fl!=1)
        {
            for(int j=0;j<r;j++)
            {
                if(avl[j]-rn[i][j]+al[i][j]<0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                return i;
            flag=0;
        }
        fl=0;
    }
    return -1;
}
void bankers::safe_seq()
{
    int temp,flag=0;
    ed=0;
    for(int i=0;i<p;i++)
    {
        temp=com();
        if(temp!=-1)
        {
            for(int y=0;y<r;y++)
                avl[y]+=al[temp][y];
            seq[ed++]=temp;
        }
        else
        {
            cout<<"\nSystem is in unsafe state ";
            flag=1;
            break;
        }
    }
    if(flag!=1)
    {
        cout<<"Safe sequence is : ";
        for(int i=0;i<ed;i++)
            cout<<"p["<<seq[i]<<"]  ";
    }
}
int main()
{
    bankers banker;
    banker.getdata();
    banker.safe_seq();
    return 0;
}


