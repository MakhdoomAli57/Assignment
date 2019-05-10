#include<bits/stdc++.h> 
                                      // increasing short j f 
using namespace std;                  
struct Proces 
{ 
   int prid;  
   int btt;  
}; 

bool compare(Proces h, Proces kbn) 
{ 
     return (h.btt < kbn.btt); 
} 
void dhoondleWaitingTime(Proces pro[], int numbr, int wat[]) 
{  
    wat[0] = 0; //first process 
    for (int i = 1; i < numbr ; i++ ) 
        wat[i] = pro[i-1].btt + wat[i-1] ; 
} 
void dhoondleTurnAroundTime(Proces pro[], int numbr, int wat[], int tt[]) 
{ 
    
    for (int i = 0; i < numbr ; i++) 
    tt[i] = pro[i].btt + wat[i]; 
} 
  
void dhoondleavgTime(Proces pro[], int numbr) 
{ 
    int wat[numbr], tt[numbr], total_wat = 0, total_tt = 0; 
  
    
    dhoondleWaitingTime(pro, numbr, wat);  
    dhoondleTurnAroundTime(pro, numbr, wat, tt); 
    cout << "\n  hamaray Processes "<<endl;
	cout<< "  inn ka Burst time "<<endl;
	cout<< "this is Waiting time " <<endl;
	cout<< "ye ha Turn around time\n"; 
    for (int i = 0; i < numbr; i++) 
    { 
        total_wat = total_wat + wat[i]; 
        total_tt = total_tt + tt[i]; 
        cout << "    " << pro[i].prid << " "<< "\t\t"<< pro[i].btt << "\t " << wat[i] << "\t\t " << tt[i] <<endl; 
    } 
    cout << "Avg waiting time = "<< (float)total_wat / (float)numbr; 
    cout << "\nAvge turn around time = "<< (float)total_tt / (float)numbr; 
} 
   
int main() 
{ 
    Proces pro[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}}; 
    cout<<" ";
    int numbr = sizeof pro / sizeof pro[0]; 
    sort(pro, pro + numbr, compare); // Sorting processes by burst time. 
  
    cout << "process ka execution order\n"; 
    for (int i = 0 ; i < numbr; i++) 
        cout << pro[i].prid <<" "; 
    dhoondleavgTime(pro, numbr); 
    return 0; 
} 
