/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nicola
 *
 * Created on 1 marzo 2019, 14:47
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
double delta(double, double, double);
double valore1(double, double, double);
double valore2(double, double, double);
void stampaEqY(double, double);
void stampaEqX(double);


/*
 * Dati i coefficenti 'a', 'b' e 'c' dell'equazione x*x + y*y + a*x + b*y + c = 0 della circonferenza
 * e le coordinate del punto P(x,y) esterno o appertenente alla circonferenza
 * calcolare le due equazioni della retta
 */
int main(int argc, char** argv)
{
    ifstream file;
    file.open("input.txt");
    if (!file.is_open())
    {
        cout << "ERRORE: IMPOSSIBILE LEGGE IL FILE input.txt" << endl << endl;
        return -1;
    }
    double aC, bC, cC;
    double a2T, a0T, b2T, b1T, b0T, c2T, c1T, c0T;
    double aF, bF, cF, x, y, m1, m2, k1, k2, deltaM;
    int stato = 0;
    file >> aC >> bC >> cC >> x >> y;
    /*cout << "Inserisci a, b, c dell'equazione x^2 + y^2 + ax + by + c = 0\n";
    cout << "Coefficiente a: "; cin >> a;
    cout << "Coefficiente b"; cin >> b;
    cout << "Coefficiente c: "; cin >> c;
    cout << "Inserisci le coordinate del punto P(x;y):\n";
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;*/
    cout << "Valori: " << aC << " " << bC << " " << cC << " " << x << " " << y;
    
    // inizio algoritmo
    
    a2T = 1;
    a0T = 1;
    
    b2T = -2 * x;
    b1T = 2 * y + bC;
    b0T = aC;
    
    c2T = x * x;
    c1T = -2 * x * y -1 * bC * x;
    c0T = y * y + bC * y + cC;
    
    aF = b1T * b1T + 2 * b2T * b0T - 4 * a0T * c2T - 4 * a2T * c0T;
    bF = 2 * b1T * b0T - 4 * a0T * c1T;
    cF = b0T * b0T - 4 * a0T * c0T;

    // fine algoritmo
    cout << endl << endl;
    
    if (aF != 0)
    {
        deltaM = delta(aF, bF, cF);
        if (deltaM < 0)
        {
            stato = 0;
        }
        else if (deltaM == 0)
        {
            stato = 1;
            m1 = valore1(aF, bF, deltaM);
            k1 = y - x * m1;
        }
        else
        {
            stato = 2;
            m1 = valore1(aF, bF, deltaM);
            m2 = valore2(aF, bF, deltaM);
            k1 = y - x * m1;
            k2 = y - x * m2;
        }
        // cout << "delta: " << deltaM << endl; // debug only

        if (stato == 0)
        {
            cout << "Errore: non esiste una retta tangente" << endl;
        }
        else if (stato == 1)
        {
            cout << "Unica equazione: ";
            stampaEqY(m1, k1);
        }
        else
        {
            cout << "Equazione 1/2: ";
            stampaEqY(m1, k1);
            cout << "Equazione 2/2: ";
            stampaEqY(m2, k2);
        }
    }
    else
    {
        cout << "Equazione 1/2: ";
        stampaEqX(x);
        
        m2 = -1 * cF / bF;
        k2 = y - x * m1;
        cout << "Equazione 2/2: ";
        stampaEqY(m2, k2);
    }
    return 0;
}

double delta(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

double valore1(double a, double b, double d)
{
    double sopra = -b + sqrt(d);
    double sotto = 2 * a;
    return sopra / sotto;
}

double valore2(double a, double b, double d)
{
    return (-b - sqrt(d)) / (2 * a);
}

void stampaEqY(double m, double k)
{
    if (m == 0)
    {
        if (k > 0)
            cout << "y = " << k << endl;
        else if (k < 0)
            cout << "y = - " << -k << endl;
        else
            cout << "y = 0" << endl;
        return;
    }
    if (k > 0)
        cout << "y = " << m << "x + " << k << endl;
    else if (k < 0)
        cout << "y = " << m << "x - " << -k << endl;
    else
        cout << "y = " << m << "x" << endl;
}

void stampaEqX(double x)
{
    cout << "x = " << x << endl;
}