#include <iostream>
#include <cmath>

int main()
{
    double a,b,c,delta;

    std::cout << "Insert the value of a (x^2)" << std::endl;
    std::cin >> a;
    std::cout << "" << std::endl;

    std::cout << "Insert the value of b (x)" << std::endl;
    std::cin >> b;
    std::cout << "" << std::endl;

    std::cout << "Insert the value of c" << std::endl;
    std::cin >> c;
    std::cout << "" << std::endl;


    if (a == 0){
        if (b == 0 && c == 0){
            std::cout << "There's no equation!" << std::endl;
            return 0;
        }

        else {
            std::cout << "It's not a quadratic equation! (a cannot be 0!)" << std::endl;
            return 0;
        }
    }

    std::cout << "The equation is: ";

    if (a==1){
        std::cout << "x^2";
    } else if (a==-1){
        std::cout << "-x^2";
    } else {
        std::cout << a << "x^2";
    }

    if (b > 0){
        if (b == 1){
            std::cout << "+x";
        } else {
            std::cout << "+" << b << "x";
        }
    }

    else if (b < 0){
        if (b == -1){
            std::cout << "-x";
        } else {
            std::cout << b << "x";
        }
    }

    if (c > 0){
        std::cout << "+" << c;
    } else if (c < 0){
        std::cout << c;
    } else {
        std::cout << "";
    }

    std::cout << " = 0" << std::endl;

    std::cout << "" << std::endl;



    delta = (b*b)-(4*a*c);  // Calculation of Delta //

    auto fixNegativeZero = [](double& x){
        if (x == 0) x = 0;
    };


    if (delta > 0){
        double x1,x2;

        x1 = (-b-sqrt(delta))/(2*a);  // Calculation of x1 //

        x2 = (-b+sqrt(delta))/(2*a);  // Calculation of x2 //

        fixNegativeZero(x1);
        fixNegativeZero(x2);

        std::cout << "Solutions: ";

        if (x1 < x2){
            std::cout << "S{" << x1 << "," << x2 << "}" << std::endl;
            std::cout << "" << std::endl;
        }

        else {
            std::cout << "S{" << x2 << "," << x1 << "}" << std::endl;
            std::cout << "" << std::endl;
        }



        std::cout << "Decomposition: ";



        if ( (x1 < 0 && x2 < 0) || (x1 < 0 && x2 > 0) || (x1 > 0 && x2 < 0) || (x1 > 0 && x2 > 0) ){
            if (a == 1){
            std::cout << "";
            } else if (a == -1){
            std::cout << "-";
            } else {
            std::cout << a;
            }

            if (x1 < 0 && x2 < 0){
                std::cout << "(x+" << -x1 << ")(x+" << -x2 << ")";
            }

            else if (x1 < 0 && x2 > 0){
                std::cout << "(x+" << -x1 << ")(x" << -x2 << ")";
            }

            else if (x1 > 0 && x2 < 0){
                std::cout << "(x" << -x1 << ")(x+" << -x2 << ")";
            }

            else if (x1 > 0 && x2 > 0){
                std::cout << "(x" << -x1 << ")(x" << -x2 << ")";
            }
        }

        else if (a < 0 && b < 0 && c == 0){
            if (a ==-1){
                std::cout << "-x(x+" << -b << ")";
            }
            else {
                std::cout << "-x(" << -a << "x+" << -b << ")";
            }
        }

        else if (a < 0 && b > 0 && c == 0){
            if (a ==-1){
                std::cout << "-x(x-" << b << ")";
            }
            else{
                std::cout << "-x(" << -a << "x" << -b << ")";
            }
        }

        else if (a > 0 && b < 0 && c == 0){
            if (a==1){
                std::cout << "x(x" << b << ")";
            }
            else {
                std::cout << "x(" << a << "x" << b << ")";
            }
        }

        else if (a > 0 && b > 0 && c == 0){
            if (a==1){
                std::cout << "x(x+" << b << ")";
            }
            else{
                std::cout << "x(" << a << "x+" << b << ")";
            }
        }

       std::cout << " = 0" << std::endl;
    }

    else if (delta == 0){
        double x;

        x = -b/(2*a);

        fixNegativeZero(x);

        std::cout << "Solution: S{" << x << "}" << std::endl;
        std::cout << "" << std::endl;



        std::cout << "Decomposition: ";

        if (x < 0){
            std::cout << "(x+" << -x << ")^2";
        }

        else if (x > 0){
            std::cout << "(x" << -x << ")^2";
        }

        std::cout << " = 0" << std::endl;
    }

    else {
        std::cout << "There are no real solutions. It could be solved using complex numbers:" << std::endl;
        std::cout << "" << std::endl;

        double x_REAL = -b/(2*a);

        double x1_IMAG = -sqrt(-delta)/(2*a);
        double x2_IMAG = sqrt(-delta)/(2*a);

        fixNegativeZero(x_REAL);

        fixNegativeZero(x1_IMAG);
        fixNegativeZero(x2_IMAG);

        if (b==0){
            std::cout << "Solutions: S{" << x1_IMAG << "i," << x2_IMAG << "i}" << std::endl;
            std::cout << "" << std::endl;

            std::cout << "Decomposition: ";

            if (x1_IMAG < 0 && x2_IMAG < 0){
                std::cout << "(x+" << -x1_IMAG << "i)(x+" << -x2_IMAG << "i)" << std::endl;
            }

            else if (x1_IMAG < 0 && x2_IMAG > 0){
                std::cout << "(x+" << -x1_IMAG << "i)(x" << -x2_IMAG << "i)" << std::endl;
            }

            else if (x1_IMAG > 0 && x2_IMAG < 0){
                std::cout << "(x" << -x1_IMAG << "i)(x+" << -x2_IMAG << "i)" << std::endl;
            }

            else if (x1_IMAG > 0 && x2_IMAG > 0){
                std::cout << "(x" << -x1_IMAG << "i)(x" << -x2_IMAG << "i)" << std::endl;
            }
        }

        else {
            if (x1_IMAG < 0 && x2_IMAG < 0){
                std::cout << "Solutions: S{" << x_REAL << x1_IMAG << "i," << x_REAL << x2_IMAG << "i}" << std::endl;
                std::cout << "" << std::endl;

                std::cout << "Decomposition: ";

                if (a == 1){
                    std::cout << "";
                }

                else if (a == -1){
                    std::cout << "-";
                }

                else {
                    std::cout << a;
                }

                if (x_REAL > 0){
                    std::cout << "(x" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x" << -x_REAL << "+" << -x2_IMAG << "i)" << std::endl;
                }

                else if (x_REAL < 0){
                    std::cout << "(x+" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x+" << -x_REAL << "+" << -x2_IMAG << "i)" << std::endl;
                }
            }

            if (x1_IMAG < 0 && x2_IMAG > 0){

                std::cout << "Solutions: S{" << x_REAL << x1_IMAG << "i," << x_REAL << "+" << x2_IMAG << "i}" << std::endl;
                std::cout << "" << std::endl;

                std::cout << "Decomposition: ";

                if (a == 1){
                    std::cout << "";
                }

                else if (a == -1){
                    std::cout << "-";
                }

                else {
                    std::cout << a;
                }

                if (x_REAL > 0){
                    std::cout << "(x" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x" << -x_REAL << -x2_IMAG << "i)" << std::endl;
                }

                else if (x_REAL < 0){
                    std::cout << "(x+" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x+" << -x_REAL << -x2_IMAG << "i)" << std::endl;
                }
            }

            if (x1_IMAG > 0 && x2_IMAG < 0){
                std::cout << "Solutions: S{" << x_REAL << "+" << x1_IMAG << "i," << x_REAL << x2_IMAG << "i}" << std::endl;
                std::cout << "" << std::endl;

                std::cout << "Decomposition: ";

                if (a == 1){
                    std::cout << "";
                }

                else if (a == -1){
                    std::cout << "-";
                }

                else {
                    std::cout << a;
                }

                if (x_REAL > 0){
                    std::cout << "(x" << -x_REAL << -x1_IMAG << "i)" << "(x" << -x_REAL << "-" << -x2_IMAG << "i)" << std::endl;
                }

                else if (x_REAL < 0){
                    std::cout << "(x+" << -x_REAL << "+" << -x1_IMAG << "i)" << "(x+" << -x_REAL << "-" << -x2_IMAG << "i)" << std::endl;
                }
            }

            if (x1_IMAG > 0 && x2_IMAG > 0){
                std::cout << "Solutions: S{" << x_REAL << "+" << x1_IMAG << "i," << x_REAL << "+" << x2_IMAG << "i}" << std::endl;
                std::cout << "" << std::endl;

                std::cout << "Decomposition: ";

                if (a == 1){
                    std::cout << "";
                }

                else if (a == -1){
                    std::cout << "-";
                }

                else {
                    std::cout << a;
                }

                if (x_REAL > 0){
                    std::cout << "(x" << -x_REAL << -x1_IMAG << "i)" << "(x" << -x_REAL << "-" << -x2_IMAG << "i)" << std::endl;
                }

                else if (x_REAL < 0){
                    std::cout << "(x+" << -x_REAL << -x1_IMAG << "i)" << "(x+" << -x_REAL << "-" << -x2_IMAG << "i)" << std::endl;
                }
            }
        }
    }

    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "Press 'X' button to close the program." << std::endl;

    while (true){
        std::cin.get();
    }
}
