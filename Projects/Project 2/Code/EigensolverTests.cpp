/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		Project 2 - Schrodinger's Equation for two electrons in
					a three-dimensional harmonic oscillator well

		Part a)   -	Jacobi's rotation algorithm "brute force".

		Part b)   -	Compare to Armadillo to find most efficient
					algorithm.
					Checking for n and rho dependency.

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

/* 
  ======= Function to return indices of largest off-diagonal element =======
	Arguments:
	mat A - matrix
	int n - size of square matrix
	int *k - new row
	int *l - new column
*/

double MaxOffDiagonal(mat A, int *k, int *l, int n){

	double maxOD;
	double a_ij;

	for (int i = 0; i < n; i++){

		for (int j = i+1; j < n; j++){

			a_ij = fabs(A(i,j));

			if (a_ij > maxOD){

				maxOD = a_ij;
				*k = i;
				*l = j;

			}
		}
	}
	return maxOD;
}

/*
  ============ Function implimenting Jacobis rotation algorithm ============
  	Arguments:
	mat &A - reference matrix A
	mat &B - reference matrix B
	int k - new row index
	int l - new column index
	int n - dimensionality of matrix
*/

void Rotate(mat &A, mat &B, int k, int l, int n){

	double t;
	double tau;
	double sine;
	double cosine;

	if ( A(k,l) != 0.0){

		tau = ( A(l,l) - A(k,k) )/( 2*A(k,l) );

		if (tau >= 0.0) { 

			t = 1.0/(fabs(tau) + sqrt(1.0 + tau*tau)); 

		} 

		else { 
			
			t = -1.0/(fabs(tau) + sqrt(1.0 + tau*tau)); 

		}

		cosine = 1.0/ sqrt (1.0 + t*t);
		sine = t*cosine; 

	}

	else {

		sine = 1.0;
		cosine = 0.0;

	}

	double A_ik;
	double A_il;
	double B_ik;
	double B_il;
	double A_kk = A(k,k);
	double A_ll = A(l,l);

	A(k,k) = A_kk*cosine*cosine - 2*A(k,l)*cosine*sine + A_ll*sine*sine;
	A(l,l) = A_ll*cosine*cosine + 2*A(k,l)*cosine*sine + A_kk*sine*sine; 
	A(k,l) = 0.0;
	A(l,k) = 0.0;

	for (int i = 0; i < n; i++){
		if (i != k && i != l){

			A_ik = A(i,k);
			A_il = A(i,l);
			A(i,k) = A_ik*cosine - A_il*sine; 
			A(k,i) = A(i,k);
			A(i,l) = A_il*cosine + A_ik*sine; 
			A(l,i) = A(i,l);

		}

		B_ik = B(i,k);
		B_il = B(i,l);
		B(i,k) = B_ik*cosine - B_il*sine;
		B(i,l) = B_il*cosine + B_ik*sine; 

	}
	return;
}

int main(){

	int n;
	int loops; 
	string filename; 
	double rho;
	double h;
	double e;
	double jacobi_time; 
	double armadillo_time; 
	rowvec N;

	int maxloops = 1e8; 
	double epsilon = 1e-10;

	filename = "Comparisons8.txt";
	rho = 8.0;

//	cout << "Enter a name for the file: ";
//	cin >> filename;
//	cout << "\nEnter a value (double) for rho: ";
//	cin >> rho;

	N << 50 << 100 << 150 << 200 << 250 << 300 << 350 << 400 << 450 << 500;

	myfile.open(filename);
	myfile << setiosflags(ios::showpoint | ios::uppercase);
	myfile << "rho: " << rho << endl;
	myfile << "Tolerance: " << epsilon << endl;
	myfile << right << setw(4) << setfill(' ') << " n: ";
	myfile << right << setw(30) << setfill(' ') << "  Eigenvalues: ";
	myfile << right << setw(16) << setfill(' ') << "  Arma Time: ";
	myfile << right << setw(16) << setfill(' ') << "  Jacobi Time: ";
	myfile << right << setw(12) << setfill(' ') << "  Transforms: " << endl;

	for (int j = 0; j < 10; j++){

		n = N(j);
		loops = 0;
		h = rho / n;
		e = -1.0/(h*h);

		vec d(n-1);
		vec p(n+1);
		vec eigenvalues(n-1);
		mat A(n-1,n-1);
		A.zeros();
		mat M(n-1,n-1);
		M.eye();

		for (int i = 0; i <= n; i++){

			p(i) = i*h;

		}

		for (int i = 0; i < n-1; i++){

			d(i) = 2/(h*h) + p(i+1)*p(i+1);

		}

		for (int i = 0; i < n-1; i++){

			A(i,i) = d(i);

			if (i != n-2){

				A(i,i+1) = e;
				A(i+1,i) = e;

			}

		}

		mat B = A;

		clock_t start_Jacobi , end_Jacobi;
		int k;
		int l;
		double MaxOffDiag = MaxOffDiagonal(A, &k, &l, n-1);

		start_Jacobi = clock();

		while (MaxOffDiag > epsilon && loops < maxloops){

			MaxOffDiag = MaxOffDiagonal(A, &k, &l, n-1);
			Rotate(A, M, k, l, n-1);
			loops ++;

		}

		end_Jacobi = clock();
		jacobi_time = (end_Jacobi - start_Jacobi)
					  /(double)CLOCKS_PER_SEC;

		for (int i = 0; i < n-1; i++){

			eigenvalues(i) = A(i,i);

		}

		eigenvalues = sort(eigenvalues);

		clock_t start_Armadillo , end_Armadillo;
		start_Armadillo = clock();
		mat eigenvector; 
		vec eigenvalue;
		eig_sym(eigenvalue , eigenvector , B); 
		end_Armadillo = clock();
		armadillo_time = (end_Armadillo - start_Armadillo)
						 /(double)CLOCKS_PER_SEC;

		myfile << right << setw(4) << setfill(' ') << n;
		myfile << right << setw(6) << setfill(' ') << "(" << eigenvalues(0) 
			   << ", ";
		myfile << right << setw(6) << setfill(' ') << eigenvalues(1) << ", ";
		myfile << right << setw(6) << setfill(' ') << eigenvalues(2) << ")";
		myfile << right << setw(16) << setfill(' ') << armadillo_time << " s";
		myfile << right << setw(16) << setfill(' ') << jacobi_time << " s";
		myfile << right << setw(12) << setfill(' ') << loops << endl;

	}

	myfile.close();
	return 0;

}