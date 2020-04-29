#include <bits/stdc++.h>
using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n)
{
    int i; 
    if(n<21) // for all numbers upto 20, this is the easier approach
    {
        unsigned long long fac=1;
        for(i=1;i<=n;i++)
            fac = fac * i;
        cout << fac;
        return;
    }
    
    /* For numbers bigger than 20, approach is to store the value of new factorial value in an array and then print it.
       For example : To store 245 in the array,
       a[2]=2
       a[1]=4
       a[0]=5 
       
       To multiply a number say k to this value, we start off from the index 0 of the array.
       At every iteration, we calculate k * a[index]. We also maintain a carry from the previous index which is initialized to 0.
       Now, at every step, we calculate product = a[index] * k + temp.
       The new value of a[index] will be product % 10 and the new value of carry will be product/10.
       We propogate this carry to higher order digits.
       Example:  

       arr[1]=3
       arr[0]=6
       We need to multiply arr by 5. We first multiply 6 by 5.  
       6*5=30, 30 % 10 = 0, 30/10=3;  
       arr[0]=0; and carry=3.
       We then multiply arr[1] by 5. 
       prod = arr[1]*5 + carry
       prod = 3*5+3=18
       arr[1] = prod%10 = 8
       carry= prod/10 = 1
       Propogating the carry
       arr[2]=1
       arr[2]=1, arr[1]=8, arr[0]=0*/
       
    unsigned long long fac=2432902008176640000; // this is the factorial value of 20.
    int carry,prod,p,dig=19,arr[200];
    for(p=21;p<=n;p++)
    {
        carry=0;
        if(p==21)
        {
            for(i=0;i<dig;i++)
            {
                arr[i] = fac%10;
                fac = fac/10;
            }
        }
        for(i=0;i<dig;i++)
        {
            prod = arr[i]*p + carry;
            arr[i] = prod%10;
            carry = prod/10;
        }
        while(carry!=0)
        {
            arr[i] = carry%10;
            carry=carry/10;
            dig++;
            i++;
        }
    }
    for(i=dig-1;i>=0;i--)
        cout << arr[i];
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    extraLongFactorials(n);
    return 0;
}
