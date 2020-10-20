#include <bits/stdc++.h> 
using namespace std; 
  
void towerOfHanoi(int n, char source_rod, 
                    char destination, char third_rod)  
{  
    if (n == 1)  
    {  
        cout << "Move disk 1 from rod " << source_rod <<  
                            " to rod " << destination<<"\n";  
        return;  
    }  
    towerOfHanoi(n - 1, source_rod, third_rod, destination);  
    cout << "Move disk " << n << " from rod " << source_rod << 
                                " to rod " << destination <<"\n";  
    towerOfHanoi(n - 1, third_rod, destination, source_rod);  
}  
  

int main()  
{  
    int n; 
    cout<<"Enter the no. of disks ";
    cin>>n;
    cout<<"\nThe steps that are taken:  \n";

    towerOfHanoi(n, 'A', 'C', 'B'); 
  
} 