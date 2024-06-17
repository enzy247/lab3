#include <iostream>
#include <cmath>

using namespace std;
/*
double f(double x) {
    return pow(x, 4) / (26 + pow(x, 2));
}

double rect_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x_i = a + i * h;
        sum += f(x_i + h / 2.0);
    }
    return h * sum;
}

double trap_method(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        sum += f(x_i);
    }
    return h * sum;
}

double simp_method(double a, double b, int n) {
    
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        sum += 2 * (i % 2 == 0 ? 2 : 1) * f(x_i);
    }
    return h / 3 * sum;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    int n_rect = 1000000;
    int n_simpson = 1000;

    double I_rect = rect_method(a, b, n_rect);
    cout << "Прямоугольники: " << I_rect << endl;

    double I_trap = trap_method(a, b, n_rect);
    cout << "Трапеции: " << I_trap << endl;

    double I_simpson = simp_method(a, b, n_simpson);
    cout << "Симпсон: " << I_simpson << endl;

    return 0;
}
*/
double f(double x) {
    return exp(-2 * x) * sin(26 * x);
}

double integrate_rect(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x_i = a + i * h;
        sum += func(x_i + h / 2.0);
    }
    return h * sum;
}

double integrate_trap(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        sum += func(x_i);
    }
    return h * sum;
}

double integrate_simp(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; ++i) {
        double x_i = a + i * h;
        sum += 2 * (i % 2 == 0 ? 2 : 1) * func(x_i);
    }
    return h / 3 * sum;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n_rect = 1000000;
    int n_simpson = 1000;

    double I_rect = integrate_rect(f, a, b, n_rect);
    cout << "Прямоугольники: " << I_rect << endl;

    double I_trap = integrate_trap(f, a, b, n_rect);
    cout << "Трапеции: " << I_trap << endl;

    double I_simpson = integrate_simp(f, a, b, n_simpson);
    cout << "Симпсон: " << I_simpson << endl;

    return 0;
}