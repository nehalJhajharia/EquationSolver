#include <iostream>
#include <math.h>

using namespace std;

#define ESC 27
#define DT 0.1

// Essential variables
char key ('\0');
float a (0);
float b (0);
float c (0);
float d (0);
float D (0); // Discriminent
float A (0); // Root 1
float B (0); // Root 2
float C (0); // Root 3
int complexCheck (0); // whether Discriminent is (-)ve

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
            // taking input
            cout << "For ax + b = 0,\n";
            cout << "a : ";
            cin >> a;
            cout << "b : ";
            cin >> b;

            // Check if the equation is strictly linear
            if (a == 0) // No Equation
            {
                cout << "No equation to solve!!";
                separate('*');
                break;
            }

            // display equation
            cout << "\n";
            if (a != 1 && a != -1)
                cout << a;
            if (a == -1)
                cout << "-";
            cout << "x";
            if (b != 0)
            {
                if (b < 0)
                    cout << " - " << (-1)*b;
                else
                    cout << " + " << b;
            }
            cout << " = 0\n\n";

            // solving equation
            b *= -1;
            A = b / a;
            cout << "x = " << A << "\n";
            separate('*');
            break;

        case '2': // Quadratic Equation
            separate('*');
            // taking input
            cout << "For ax2 + bx + c = 0,\n";
            cout << "a : ";
            cin >> a;
            cout << "b : ";
            cin >> b;
            cout << "c : ";
            cin >> c;

            // Check if the equation is strictly quadratic
            if (a == 0) // Linear Equation
            {
                if (c == 0) // No equation
                {
                    cout << "No equation to solve!!";
                    separate('*');
                    break;
                }
                cout << "It's a linear equation, try '1' command!!\n";
                separate('*');
                break;
            }

            // display equation
            cout << "\n";
            if (a != 1 && a != -1)
                cout << a;
            if (a == -1)
                cout << "-";
            cout << "(x2)";
            if (b != 0)
            {
                if (b < 0)
                {
                    cout << " - ";
                    if (b != -1)
                        cout << (-1)*b;
                }
                else
                {
                    cout << " + ";
                    if (b != 1)
                        cout << b;
                }
                cout << "x";
            }
            if (c != 0)
            {
                if (c < 0)
                    cout << " - " << (-1)*c;
                else
                    cout << " + " << c;
            }
            cout << " = 0\n\n";

            // solving discriminent
            D = (b*b) - 4*a*c;
            if (D < 0) // Complex roots
            {
                D *= -1;
                complexCheck = 1;
            }

            D = sqrt(D);

            b *= -1;
            a *= 2;
            b /= a;
            D /= a;

            if (complexCheck == 1) // Complex roots
            {
                if (b != 0)
                {
                    cout << "Root 1 = " << b << " + " << D << "i\n";
                    cout << "Root 2 = " << b << " - " << D << "i\n";
                }
                else
                {
                    cout << "Root 1 = " << D << "i\n";
                    cout << "Root 2 = " << "-" << D << "i\n";
                }
                separate('*');
                break;
            }

            A = b + D;
            B = b - D;

            cout << "Root 1 = " << A << "\n";
            cout << "Root 2 = " << B << "\n";
            separate('*');
            break;

        case '3': // Cubic Equation
            separate('*');
            // taking input
            cout << "For ax3 + bx2 + cx + d = 0,\n";
            cout << "a : ";
            cin >> a;
            cout << "b : ";
            cin >> b;
            cout << "c : ";
            cin >> c;
            cout << "d : ";
            cin >> d;

            // Check if the equation is strictly cubic
            if (a == 0) // Quadratic Equation
            {
                if (b == 0) // Linear equation
                {
                    if (c == 0) // No equation
                    {
                        cout << "No equation to solve!!\n";
                        separate('*');
                        break;
                    }
                    cout << "It's a linear equation, try '1' command!!\n";
                    separate('*');
                    break;
                }
                cout << "It's a quadratic equation, try '2' command!!\n";
                separate('*');
                break;
            }

            // display equation
            cout << "\n";
            if (a != 1 && a != -1)
                cout << a;
            if (a == -1)
                cout << "-";
            cout << "(x3)";
            if (b != 0)
            {
                if (b < 0)
                {
                    cout << " - ";
                    if (b != -1)
                        cout << (-1)*b;
                }
                else
                {
                    cout << " + ";
                    if (b != 1)
                        cout << b;
                }
                cout << "(x2)";
            }
            if (c != 0)
            {
                if (c < 0)
                {
                    cout << " - ";
                    if (c != -1)
                        cout << (-1)*c;
                }
                else
                {
                    cout << " + ";
                    if (c != 1)
                        cout << c;
                }
                cout << "x";
            }
            if (d != 0)
            {
                if (d < 0)
                    cout << " - " << (-1)*d;
                else
                    cout << " + " << d;
            }
            cout << " = 0\n\n";

            // SOLVE
            if (d != 0) // 0 is not a root
                A = alpha();
            cout << "Root 1 belongs to [" << A-DT << ", " << A+DT << "]\n";

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