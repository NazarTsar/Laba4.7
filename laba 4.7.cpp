#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateLn(double x, double eps) {
    double a = x;
    double sum = x;
    int n = 0;

    do {
        n++;
        a *= -x / n;
        sum += a;
    } while (abs(a) >= eps);

    return sum;
}

int main() {
    double xp, xk, dx, eps;
    cout << "Enter xp: "; cin >> xp;
    cout << "Enter xk: "; cin >> xk;
    cout << "Enter dx: "; cin >> dx;
    cout << "Enter eps: "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "ln(x+1)" << " |"
        << setw(10) << "S" << " |"
        << setw(7) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    double x = xp;
    while (x <= xk) {
        double lnValue = log(x + 1);
        double approxValue = calculateLn(x, eps);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(6) << lnValue << " |"
            << setw(10) << setprecision(6) << approxValue << " |"
            << setw(7) << (int)(log(eps) / log(abs(x))) + 1 << " |"
            << endl;

        x += dx;
    }

    cout << "-------------------------------------------------" << endl;

    return 0;
}
