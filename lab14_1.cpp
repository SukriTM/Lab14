#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double x[], int N, double y[]){
    double sum, sum_std, m=1, sum_hm, max=x[0], min=x[0];
    for (int i = 0; i < N; i++)
    {
        sum += x[i];
        m *= x[i];
        sum_hm += 1.0/x[i];
        if(x[i]>max) max=x[i];
        if(x[i]<min) min=x[i];
    }
    y[0]=sum/N;

    for (int i = 0; i < N; i++)
    {
        sum_std += (pow(x[i],2)-pow(y[0],2));
    }
    y[1]=sqrt(sum_std/N);
    y[2]=pow(m,1.0/N);
    y[3]=N/sum_hm;
    y[4]=max;
    y[5]=min;

}