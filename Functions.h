// Header file to contain user-defined Functions

// Display Commands
void commands()
{
    cout << "1     -     Linear Equation\n"
         << "2     -     Quadrati Equation\n"
         << "3     -     Cubic Equation\n"
         << "?     -     See Commands\n"
         << "ESC   -     END\n";
}

// Generate a horizontal line to separate sections
void separate(char type)
{
    cout << "\n";
    for (int i (0); i < 50; i++)
    {
        cout << type;
    }
    cout << "\n\n";
}

/**********LINEAR**********/
// LINEAR Equation
void Linear()
{
    // taking input
    cout << "For ax + b = 0,\n";
    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;

    // Check if the equation is strictly linear
    if (a == 0) // No Equation
    {
        cout << "No equation to solve!!\n";
        return;
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
            cout << " - " << (-1) * b;
        else
            cout << " + " << b;
    }
    cout << " = 0\n\n";

    // solving equation
    b *= -1;
    A = b / a;
    cout << "x = " << A << "\n";
}

/**********QUADRATIC**********/
// QUADRTIC Equation
void Quadratic()
{
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
        if (b == 0) // No equation
        {
            cout << "No equation to solve!!\n";
            return;
        }
        cout << "It's a linear equation, try '1' command!!\n";
        return;
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
                cout << (-1) * b;
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
            cout << " - " << (-1) * c;
        else
            cout << " + " << c;
    }
    cout << " = 0\n\n";

    // solving discriminent
    D = (b * b) - 4 * a * c;
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
            cout << "Root 2 = "
                 << "-" << D << "i\n";
        }
        return;
    }

    A = b + D;
    B = b - D;

    cout << "Root 1 = " << A << "\n";
    cout << "Root 2 = " << B << "\n";
}

/**********CUBIC**********/

// Expression value at x
double expression(float x)
{
    double l = a; // x cube term
    l *= x;
    l *= x;
    l *= x;
    double m = b; // x square term
    if (b != 0)
    {
        m *= x;
        m *= x;
    }
    double n = c; // x term
    n *= x;
    double o = d; // constant term

    return (l + m + n + o);
}

// Get one root of a cubic equation
void alpha()
{
    double Fp = expression(xp);
    double Fn = expression(xn);
    int Fsign (0);
    if (Fp < 0)
        Fsign = 1;

    while (Fsign == 0)
    {
        if (expression(xp+p) > 0)
        {
            if (xp_check == 1)
            {
                Fp = expression(xp+p);
                xp += p;
            }
        }
        else
        {
            xn_check = 0;
            A = xn+p;
            return;
        }

        if (expression(xn-p) > 0)
        {
            if (xn_check == 1)
            {
                Fn = expression(xn-p);
                xn -= p;
            }
        }
        else
        {
            xp_check = 0;
            A = xn-p;
            return;
        }
    }
    while (Fsign == 1)
    {
        if (expression(xp+p) < 0)
        {
            if (xp_check == 1)
            {
                Fp = expression(xp+p);
                xp += p;
            }
        }
        else
        {
            xn_check = 0;
            A = xp+p;
            return;
        }

        if (expression(xn-p) < 0)
        {
            if (xn_check == 1)
            {
                Fn = expression(xn - p);
                xn -= p;
            }
        }
        else
        {
            xp_check = 0;
            A = xn-p;
            return;
        }
    }
}

// CUBIC Equation
void Cubic()
{
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
                return;
            }
            cout << "It's a linear equation, try '1' command!!\n";
            return;
        }
        cout << "It's a quadratic equation, try '2' command!!\n";
        return;
    }

    // decimal precision requirement
    cout << "Decimal Precision upto : ";
    cin >> decPrecion;

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
                cout << (-1) * b;
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
                cout << (-1) * c;
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
            cout << " - " << (-1) * d;
        else
            cout << " + " << d;
    }
    cout << " = 0\n\n";

    // SOLUTION
    if (d == 0) // 0 is a root
    {
        cout << "Root 1 = 0\n";
        return;
    }

    // Decimal Precision loop
    // loop runs for i = 0 
    // to (decPrecision + number of 0 in DT)
    for (int i (0); i <= decPrecion+2; i++)
    {
        alpha();
        p /= 10;
        if (expression(A) == 0)
        {
            break;
        }
    }

    cout << "Root 1 = " << A << "\n";

    // Reset values
    p = DT;
    xp = 0;
    xn = 0; 
    xn_check = 1;
    xp_check = 1;
}
