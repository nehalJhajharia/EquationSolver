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

// Expression value at x
float expression(float x)
{
    return ((a*x*x*x) + (b*x*x) + (c*x) + d);
}

// Get one root of a cubic equation
float alpha()
{
    float xp (0); // (+)ve x
    float xn (0); // (-)ve x
    float Fp = expression(xp);
    float Fn = Fp;
    int Fsign (0);
    if (Fp < 0)
        Fsign = 1;

    while (Fsign == 0)
    {
        if (expression(xp+DT) > 0)
        {
            Fp = expression(xp+DT);
            xp += DT;
        }
        else    return xp+DT;

        if (expression(xn-DT) > 0)
        {
            Fn = expression(xn-DT);
            xn -= DT;
        }
        else    return xn-DT;
    }
    while (Fsign == 1)
    {
        if (expression(xp+DT) < 0)
        {
            Fp = expression(xp+DT);
            xp += DT;
        }
        else    return xp+DT;

        if (expression(xn-DT) < 0)
        {
            Fn = expression(xn-DT);
            xn -= DT;
        }
        else    return xn-DT;
    }

    return 0;
}