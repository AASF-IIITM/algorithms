// C++ implementation of Newton's algorithm of finding square root.
// It calcualtes square root of a number accurately upto 5 decimal places.

#include <iostream>
using namespace std;

double SquareRoot(double n)
{
    const double precision = 1E-15;
    double x = 1; // assuming initial value of square root to be 1.
    while (1)
    {
        double a = (x + n / x) / 2; // taking avearage of lower and upper limits of x until it is less than precision
        if (abs(x - a) < precision)
            break;
        x = a;
    }
    return x;
}

int main()
{
    double n;
    cin >> n;
    cout << SquareRoot(n) << endl;
    return 0;
}
