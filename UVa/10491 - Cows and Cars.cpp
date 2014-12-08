#include <iostream>
#include <cstdio>

using namespace std;

int main ( ) {
    double cars, cows, show;
    while ( cin >> cows >> cars >> show ) {
           double r = (cows + cars) - show - 1;
           printf( "%.5f\n", ( cows*cars/r + cars*(cars-1)/r )/( cows + cars ) );      
    }      
}
