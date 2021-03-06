﻿#define forn(i, n) for(int i=0; i<n; i++)
#define foran(i,a, n) for(int i=a; i<n; i++)

#include "tepaykinma.h"

/**
 * Введение в дисциплину
 */
void tepaykinma::lab1()
{
  cout << "Hello World!" << endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void tepaykinma::lab2() {
    int n = N;

    forn(i, n)
    {
        //sort(matr.begin() + i, matr.end(), comp_first);

        int maxi = i;
        foran(j, i + 1, n)
        {
            if(A[j][i] > A[maxi][i]) maxi = j;
        }
        forn(k,n)
        {
            swap(A[maxi][k],A[i][k]);
        }
        swap(b[maxi],b[i]);

        double first = A[i][i];
        foran(j, i, n)
        {
            A[i][j] /= first;
        }
        b[i] /= first;
        foran(j, i + 1, n)
        {
            first = A[j][i];
            foran(k, i, n)
            {
                A[j][k] -= A[i][k] * first;
            }
            b[j] -= b[i] * first;
        }
    }


    for (int i = n; i >= 0; i--)
    {
        foran(j, i + 1, n)
        {
            b[i] += -A[i][j] * x[j];
            A[i][j] = 0;
        }
        x[i] = b[i];
    }

}



/**
 * Метод прогонки
 */
void tepaykinma::lab3()
{
    double* y = new double[N];
    double* alpha = new double[N];
    double* beta = new double[N];

    //  c = A[i][i+1]  i = 0,...,N-2
    //  a = A[i][i-1]  i = 0,...,N-1

    y[0] = A[0][0];
    alpha[0] = -A[0][0+1] / y[0];
    beta[0] = b[0] / y[0];
    foran(i, 1, N - 1)
    {
        y[i] = A[i][i] + A[i][i-1]*alpha[i-1];
        alpha[i] = -A[i][i+1] / y[i];
        beta[i] = (b[i] - A[i][i-1]*beta[i-1]) / y[i];
    }
    y[N - 1] = A[N - 1][N - 1] + A[N - 1][N - 2] * alpha[N - 2];
    beta[N - 1] = (b[N - 1] - A[N - 1][N - 2] * beta[N - 2]) / y[N - 1];

    x[N - 1] = beta[N - 1];
    for(int i = N - 2; i >= 0; i--)
    {
        x[i] = alpha[i]*x[i+1] + beta[i];

    }





    delete[] y;
    delete[] alpha;
    delete[] beta;
}



/**
 * Метод Холецкого
 */
void tepaykinma::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void tepaykinma::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void tepaykinma::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void tepaykinma::lab7()
{

}


void tepaykinma::lab8()
{

}


void tepaykinma::lab9()
{

}


std::string tepaykinma::get_name()
{
  return "Tepaykin M.A.";
}




#undef LL
#undef forn
#undef foran

