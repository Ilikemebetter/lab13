#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[], int, double[]);

int main()
{
    double A[] = {1.2, 3.5, 6.9, 7.8, 12.5, 0.5};
    int N = sizeof(A) / sizeof(A[0]);
    double B[6];
    stat(A, N, B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[])
{
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        double mean = (sum / N);
        B[0] = mean;
    }

    double sumsd = 0;
    for (int j = 0; j < N; j++)
    {
        sumsd += pow((A[j] - B[0]), 2);
        double sd = sqrt(sumsd / N);
        B[1] = sd;
    }

    double sumgm = 1;
    for (int k = 0; k < N; k++)
    {
        sumgm *= A[k];
        double gm = pow((sumgm), (1.0 / N));
        B[2] = gm;
    }

    double sumhm = 0;
    for (int m = 0; m < N; m++)
    {
        sumhm += 1 / A[m];
        double hm = N / sumhm;
        B[3] = hm;
    }

    double max = 0;
    for (int o = 0; o < N; o++)
    {
        if (max <= A[o])
        {
            max = A[o];
        }
    }B[4] = max;
    

    double min = A[0];
    for (int p = 0; p < N; p++)
    {
        if (min >= A[p])
        {
            min = A[p];
        }
    }B[5] = min;
    
}
