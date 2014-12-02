#include <cctype>          // Provides toupper
#include <iostream>        // Provides cout and cin
#include <cstdlib>         // Provides EXIT_SUCCESS
#include <string>
using namespace std;


// PROTOTYPES for functions used by this test program:
void pattern(ostream& outs, unsigned int n, unsigned int i);

int main()
{
    int i2;
    int w;
    cout << "Enter an integer (a power of 2): ";
    cin >> i2;
    cout << "Enter an offset: ";
    cin >> w;
    pattern(cout, i2, w);
    return (EXIT_SUCCESS);
}

          // i is the offset
          // n is the asterisks

void pattern(ostream& outs, unsigned int n, unsigned int i)
{
    if (n == 0) return;
    if (n == 1)
    {
        for (unsigned int a = 0; a < i; a++)
        {
            cout << " " ;
        }
        for (unsigned int b = 0; b < n; b++)
        {
            cout << "*" ;
        }
        cout << endl;
        return;
    }

    else 
    {
        pattern(cout, n/2, i);
        for (unsigned int a = 0; a < i; a++)
        {
            cout << " ";
        }
        for (unsigned int b = 0; b < n; b++)
        {
            cout << "*";
        }
        cout << endl;
        pattern(cout,n/2,(n/2)+i);
    }
}




