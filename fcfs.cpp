#include<iostream>                        // fcfs
using namespace std;
int main()
{
    int no,burstt[20],waitt[20],tt[20],avgwt=0,avgtat=0,k,j;
    cout<<"          Enter---- number---- of----- processes(max 20):";
    cin>>no;
    cout<<"      Enter Process----------------- Burst Time"<<endl;
    for(k=0;k<no;k++)
    {
        cout<<"P["<<k+1<<"]:";
        cin>>burstt[k];
    }
  waitt[0]=0;        // waiting time nikalna ha iss se ye waja ha iski
    for(k=1;k<no;k++)
    {
        waitt[k]=0;
        for(j=0;j<k;j++)
            waitt[k]+=burstt[j];
    }
  cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;
    for(k=0;k<no;k++)                           // ye turnaround time milnay ke liye
    {                                          
        tt[k]=burstt[k]+waitt[k];
        avgwt+=waitt[k];
        avgtat+=tt[k];
        cout<<"\nP["<<k+1<<"]"<<"\t\t"<<burstt[k]<<"\t\t"<<waitt[k]<<"\t\t"<<tt[k]<<endl;
    }
 
    avgwt/=k;
    avgtat/=k;
    cout<<endl; //precautionary lagaya ha 
    cout<<"Avg Waiting ---------Time:"<<avgwt;
    cout<<" ";
    cout<<"Avg Turnaround ------- Time:"<<avgtat;
 
    return 0;
}
