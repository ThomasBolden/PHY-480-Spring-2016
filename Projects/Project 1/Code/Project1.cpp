/* 

Project 1 a,b - Vector and Matrix Operations 
Solving a tridiagonal matrix

*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <armadillo>
#include "time.h"

using namespace std;
using namespace arma;

ofstream myfile;

// -~- Functions -~- \\

double f(double x){
	return 100*exp(-10*x);
}

double analyze(double x){
	return 1.0-(1-exp(-10))*x-exp(-10*x);
}

// -~- Main -~- \\

int main(){

	// -~- Declaration of Variables -~- \\

	int n;
	string outfilename;

	cout << "Dimensions of the nxn matrix: ";
	while(!(cin >> n)){
    	cout << "Not a valid number! Try again: ";
    	cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Enter a name for the output file: "; 
	cin >> outfilename;

	// -~- Body of the program -~- \\

	clock_t start , finish ;
	start = clock();

	double h = (1.0) / (n + 1.0);
	double *x = new double[n+2];
	double *tildeb = new double[n+1];
	tildeb[0] = 0;

	int *a = new int[n+1]; 
	int *b = new int[n+1]; 
	int *c = new int[n+1];

	double *diag_temp = new double[n+1];

    double *u = new double[n+2]; // Analytical solution
    double *v = new double[n+2]; // Numerical solution
    
    u[0] = 0;
    v[0] = 0;

    for (int i=0; i<=n+1; i++) {
        x[i] = i*h;
    }

    for (int i=1; i<=n; i++) {
        tildeb[i] = h*h*f(x[i]);
        u[i] = analyze(x[i]);
        a[i] = -1;
        b[i] = 2;
        c[i] = -1;
    }

    c[n] = 0;
    a[1] = 0;

    // Algorithm for finding v:
    double b_temp = b[1];
    v[1] = tildeb[1]/b_temp;
    for (int i=2;i<=n;i++) {
       diag_temp[i] = c[i-1]/b_temp;
       b_temp = b[i] - a[i]*diag_temp[i];
       v[i] = (tildeb[i]-v[i-1]*a[i])/b_temp;
    }

    // Row reduction; backward substition:
    for (int i=n-1;i>=1;i--) {
        v[i] -= diag_temp[i+1]*v[i+1];
    }

    finish = clock() - start;

    double processortime = ((double)finish)/CLOCKS_PER_SEC;

	// -~- writing results to file, to be read and graphed in python -~- \\

    myfile.open(outfilename);
	//myfile << setiosflags(ios::showpoint | ios::uppercase); //sci notation
	myfile << "Solution to tridiagonal matrix of size n=" << n << endl;
	myfile << "Time elapsed = " << processortime << " seconds" << endl ;
	myfile << "       x:             u(x):          v(x):  " << endl;
    for (int i=1;i<=n;i++) {
       myfile << setw(15) << setprecision(8) << x[i];
       myfile << setw(15) << setprecision(8) << u[i];
       myfile << setw(15) << setprecision(8) << v[i] << endl;
    }

    myfile.close();

    delete [] x;
    delete [] tildeb;
    delete [] a;
    delete [] b;
    delete [] c;
    delete [] u;
    delete [] v;

	return 0;

}