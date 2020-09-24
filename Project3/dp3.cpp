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
    if(a == 0) return b;
    if(a > b) return gcd(b, a);
    else return gcd(b % a, a);
}