#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c,delta;

    cout << "Insert the value of a (x^2)" << endl;
    cin >> a;
    cout << "" << endl;

    cout << "Insert the value of b (x)" << endl;
    cin >> b;
    cout << "" << endl;

    cout << "Insert the value of c" << endl;
    cin >> c;
    cout << "" << endl;


    if (a == 0)
    {
        if (b == 0 && c == 0)
        {
            cout << "There's no equation!" << endl;
            return 0;
        }

        else
        {
            cout << "It's not a quadratic equation! (a cannot be 0!)" << endl;
            return 0;
        }
    }

    cout << "The equation is: ";

    if (a==1)
    {
        cout << "x^2";
    }

    else if (a==-1)
    {
        cout << "-x^2";
    }

    else
    {
        cout << a << "x^2";
    }

    if (b > 0)
    {
        if (b == 1)
        {
            cout << "+x";
        }
        else
        {
            cout << "+" << b << "x";
        }
    }
    else if (b < 0)
    {
        if (b == -1)
        {
            cout << "-x";
        }
        else
        {
            cout << b << "x";
        }
    }

    if (c > 0)
    {
        cout << "+" << c;
    }

    else if (c < 0)
    {
        cout << c;
    }

    else
    {
        cout << "";
    }

    cout << " = 0" << endl;

    cout << "" << endl;



    delta = (b*b)-(4*a*c);  // Calculation of Delta //

    auto fixNegativeZero = [](double& x)
    {
        if (x == 0) x = 0;
    };


    if (delta > 0)
    {
        double x1,x2;

        x1 = (-b-sqrt(delta))/(2*a);  // Calculation of x1 //

        x2 = (-b+sqrt(delta))/(2*a);  // Calculation of x2 //

        fixNegativeZero(x1);
        fixNegativeZero(x2);

        cout << "Solutions: ";

        if (x1 < x2)
        {
            cout << "S{" << x1 << "," << x2 << "}" << endl;
            cout << "" << endl;
        }

        else
        {
            cout << "S{" << x2 << "," << x1 << "}" << endl;
            cout << "" << endl;
        }



        cout << "Decomposition: ";



        if ( (x1 < 0 && x2 < 0) || (x1 < 0 && x2 > 0) || (x1 > 0 && x2 < 0) || (x1 > 0 && x2 > 0) )
        {
            if (a == 1){
            cout << "";
            } else if (a == -1){
            cout << "-";
            } else {
            cout << a;
            }

            if (x1 < 0 && x2 < 0)
            {
                cout << "(x+" << -x1 << ")(x+" << -x2 << ")";
            }

            else if (x1 < 0 && x2 > 0)
            {
                cout << "(x+" << -x1 << ")(x" << -x2 << ")";
            }

            else if (x1 > 0 && x2 < 0)
            {
                cout << "(x" << -x1 << ")(x+" << -x2 << ")";
            }

            else if (x1 > 0 && x2 > 0)
            {
                cout << "(x" << -x1 << ")(x" << -x2 << ")";
            }
        }

        else if (a < 0 && b < 0 && c == 0)
        {
            if (a ==-1)
            {
                cout << "-x(x+" << -b << ")";
            }
            else
            {
                cout << "-x(" << -a << "x+" << -b << ")";
            }
        }

        else if (a < 0 && b > 0 && c == 0)
        {
            if (a ==-1)
            {
                cout << "-x(x-" << b << ")";
            }
            else
            {
                cout << "-x(" << -a << "x" << -b << ")";
            }
        }

        else if (a > 0 && b < 0 && c == 0)
        {
            if (a==1)
            {
                cout << "x(x" << b << ")";
            }
            else
            {
                cout << "x(" << a << "x" << b << ")";
            }
        }

        else if (a > 0 && b > 0 && c == 0)
        {
            if (a==1)
            {
                cout << "x(x+" << b << ")";
            }
            else
            {
                cout << "x(" << a << "x+" << b << ")";
            }
        }

        cout << " = 0" << endl;
    }

    else if (delta == 0)
    {
        double x;

        x = -b/(2*a);

        fixNegativeZero(x);

        cout << "Solution: S{" << x << "}" << endl;
        cout << "" << endl;



        cout << "Decomposition: ";

        if (x < 0)
        {
            cout << "(x+" << -x << ")^2";
        }

        else if (x > 0)
        {
            cout << "(x" << -x << ")^2";
        }

        cout << " = 0" << endl;
    }

    else
    {
        cout << "There are no real solutions. It could be solved using complex numbers:" << endl;
        cout << "" << endl;

        double x_REAL = -b/(2*a);

        double x1_IMAG = -sqrt(-delta)/(2*a);
        double x2_IMAG = sqrt(-delta)/(2*a);

        fixNegativeZero(x_REAL);

        fixNegativeZero(x1_IMAG);
        fixNegativeZero(x2_IMAG);

        if (b==0)
        {
            cout << "Solutions: S{" << x1_IMAG << "i," << x2_IMAG << "i}" << endl;
            cout << "" << endl;

            cout << "Decomposition: ";

            if (x1_IMAG < 0 && x2_IMAG < 0)
            {
                cout << "(x+" << -x1_IMAG << "i)(x+" << -x2_IMAG << "i)" << endl;
            }

            else if (x1_IMAG < 0 && x2_IMAG > 0)
            {
                cout << "(x+" << -x1_IMAG << "i)(x" << -x2_IMAG << "i)" << endl;
            }

            else if (x1_IMAG > 0 && x2_IMAG < 0)
            {
                cout << "(x" << -x1_IMAG << "i)(x+" << -x2_IMAG << "i)" << endl;
            }

            else if (x1_IMAG > 0 && x2_IMAG > 0)
            {
                cout << "(x" << -x1_IMAG << "i)(x" << -x2_IMAG << "i)" << endl;
            }
        }

        else
        {
            if (x1_IMAG < 0 && x2_IMAG < 0)
            {
                cout << "Solutions: S{" << x_REAL << x1_IMAG << "i," << x_REAL << x2_IMAG << "i}" << endl;
                cout << "" << endl;

                cout << "Decomposition: ";

                if (a == 1)
                {
                    cout << "";
                }

                else if (a == -1)
                {
                    cout << "-";
                }

                else
                {
                    cout << a;
                }

                if (x_REAL > 0)
                {
                    cout << "(x" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x" << -x_REAL << "+" << -x2_IMAG << "i)" << endl;
                }

                else if (x_REAL < 0)
                {
                    cout << "(x+" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x+" << -x_REAL << "+" << -x2_IMAG << "i)" << endl;
                }
            }

            if (x1_IMAG < 0 && x2_IMAG > 0)
            {

                cout << "Solutions: S{" << x_REAL << x1_IMAG << "i," << x_REAL << "+" << x2_IMAG << "i}" << endl;
                cout << "" << endl;

                cout << "Decomposition: ";

                if (a == 1)
                {
                    cout << "";
                }

                else if (a == -1)
                {
                    cout << "-";
                }

                else
                {
                    cout << a;
                }

                if (x_REAL > 0)
                {
                    cout << "(x" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x" << -x_REAL << -x2_IMAG << "i)" << endl;
                }

                else if (x_REAL < 0)
                {
                    cout << "(x+" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x+" << -x_REAL << -x2_IMAG << "i)" << endl;
                }
            }

            if (x1_IMAG > 0 && x2_IMAG < 0)
            {
                cout << "Solutions: S{" << x_REAL << "+" << x1_IMAG << "i," << x_REAL << x2_IMAG << "i}" << endl;
                cout << "" << endl;

                cout << "Decomposition: ";

                if (a == 1)
                {
                    cout << "";
                }

                else if (a == -1)
                {
                    cout << "-";
                }

                else
                {
                    cout << a;
                }

                if (x_REAL > 0)
                {
                    cout << "(x" << -x_REAL << -x1_IMAG << "i)" << "(x" << -x_REAL << "-" << -x2_IMAG << "i)" << endl;
                }

                else if (x_REAL < 0)
                {
                    cout << "(x+" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x+" << -x_REAL << "-" << -x2_IMAG << "i)" << endl;
                }
            }

            if (x1_IMAG > 0 && x2_IMAG > 0)
            {
                cout << "Solutions: S{" << x_REAL << "+" << x1_IMAG << "i," << x_REAL << "+" << x2_IMAG << "i}" << endl;
                cout << "" << endl;

                cout << "Decomposition: ";

                if (a == 1)
                {
                    cout << "";
                }

                else if (a == -1)
                {
                    cout << "-";
                }

                else
                {
                    cout << a;
                }

                if (x_REAL > 0)
                {
                    cout << "(x" << -x_REAL << -x1_IMAG << "i)" << "(x" << -x_REAL << "-" << -x2_IMAG << "i)" << endl;
                }

                else if (x_REAL < 0)
                {
                    cout << "(x+" << -x_REAL << -x1_IMAG << "i)" << "(x+" << -x_REAL << "-" << -x2_IMAG << "i)" << endl;
                }
            }
        }
    }

    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;

    cout << "Press 'X' button to close the program." << endl;

    while (true)
    {
        cin.get();
    }
}
