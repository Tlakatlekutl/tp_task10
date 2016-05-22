#include <iostream>
#include "tpComplex.h"
#include <vector>
#include <string>

#include "debug.h"
using namespace std;

int main()
{
    try
    {

        tpComplex<double> a(5,-2.4);
        cout << a;
        cout << a+a;
        cout << a-a;
        cout << a*a;
        LOG("temp",a);
        vector<tpComplex<double>> v;
    }
    catch(...)
    {
        cout<<"Все плохо!!!";
    }
    return 0;
}
