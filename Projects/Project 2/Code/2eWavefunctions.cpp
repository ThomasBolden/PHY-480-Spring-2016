/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Project 2 - Schrodinger's Equation for two electrons in
					a three-dimensional harmonic oscillator well

		Part d)   -	Solving the 2-electron wavefunction of coordinate
					rho with varying omega_rho

		Results are saved to a text file.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <iostream>
#include <fstream>
#include <iomanip>

#include <string>
#include <time.h>

#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

ofstream myfile;

int main(){

	int n;

	cout << "Dimensionality of matrix (n): ";
	cin >> n;

	double omega;

	cout << "Value for Omega_r: ";
	cin >> omega;

	string filename;

	cout << "Enter a name for the file: ";
	cin >> filename;

	double rho = 5.0;
	double h;
	double el;

	h = rho / n;
	el = -1.0/(h*h);

	mat A(n-1,n-1);
	vec p(n+1);
	vec z(n+1);

	for (int i = 0; i < n; i++){

		p(i) = i*h;

	}

	for (int i = 0; i < n-1; i++){

		z(i) = pow(omega,2)*pow(p(i+1),2) + 1.0/p(i+1) + 2.0/(pow(h,2));

	}

	for (int i = 0; i < n-1; i++){

		A(i,i) = z(i);

		if (i != n-2){

			A(i,i+1) = el;
			A(i+1,i) = el;

		}
	}

	vec eigenvalues;
	mat eigenvectors;

	eig_sym(eigenvalues,eigenvectors,A);

	myfile.open(filename);
	myfile << setiosflags(ios::showpoint | ios::uppercase);
	myfile << right << setw(10) << setfill(' ') << "rho" << endl;

	for (int i = 0; i < n-1; i++){

		myfile << setw(15) << setfill(' ') << setprecision(10) << p(i+1);
		myfile << setw(15) << setfill(' ') << setprecision(10) 
			   << eigenvectors.col(0);
		myfile << setw(15) << setfill(' ') << setprecision(10) 
			   << eigenvectors.col(1);
		myfile << setw(15) << setfill(' ') << setprecision(10) 
			   << eigenvectors.col(2) << endl;

	}

	myfile.close();
	return 0;


	//eigenvectors.col(0)

}




















