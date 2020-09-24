/*
 * Andrew Player
 * CS311
 * 09/24/2020
 * Source for Project 3 
*/

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;


void didItThrow(const function<void()> & ff,
                bool & threw)
{
    try {
        ff();
        threw = false;
        return;
    } catch(std::runtime_error& e) {
        threw = true;
        throw e;
    } catch(std::exception& e) {
        threw = true;
        throw e;
    } catch(int i) {
        threw = true;
        throw i;
    }
}


int gcd(int a,
        int b)
{
    if(b == 0) return a;
    int temp = b;
    b = a % b;
    a = temp;
    return gcd(a, b);
}