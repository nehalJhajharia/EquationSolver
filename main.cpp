#include <iostream>
#include <math.h>

using namespace std;

#define ESC 27
#define DT 100

// Essential variables
char key ('\0');
float a (0); // Coefficient
float b (0); // Coefficient
float c (0); // Coefficient
float d (0); // Coefficient
float D (0); // Discriminent
float A (0); // Root 1
float B (0); // Root 2
float C (0); // Root 3
int complexCheck (0); // whether Discriminent is (-)ve
double xp(0); // (+)ve x
double xn(0); // (-)ve x
int xp_check (1); // (+)ve x
int xn_check (1); // (-)ve x
float p = DT; // variable for root precision in cubic equation
double Fp (0); // function value at (+)ve x
double Fn (0); // function value at (-)ve x
int decPrecion (1);

// Header file of some user-defined functions
#include "Functions.h"

// MAIN
int main()
{
    separate('#');
    commands();
    separate('*');

    while(key != ESC)
    {
        cout << "Select an action : ";
        cin >> key;

        switch (key)
        {
        case '1': // Linear Equation
            separate('*');
            Linear();
            separate('*');
            break;

        case '2': // Quadratic Equation
            separate('*');
            Quadratic();
            separate('*');
            break;

        case '3': // Cubic Equation
            separate('*');
            Cubic();
            separate('*');
            break;

        case '?': // Display Commands
            separate('*');
            commands();
            separate('*');
            break;

        case ESC: // END
            separate('*');
            cout << "Thank You :)\n";
            separate('#');
            break;
        
        default:
            separate('*');
            cout << "Oops! No command for " << key << ".\n";
            separate('*');
            break;
        }
    }

    return 0;
}