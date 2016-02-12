// Project 1 - Vector and Matrix Operations

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include "armadillo"

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

	double n;
	string outfilename;

	cout << "Dimensions of the nxn matrix: ";
	while(!(cin >> n)){
    	cout << "Not a valid number! Try again: ";
    	cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Enter a name for the output file: "; 
	cin >> outfilename;

	// body of the program



	// writing value to file, to be read and graphed in python later
    myfile.open(outfilename);
	myfile << setiosflags(ios::showpoint | ios::uppercase); //sci notation
	myfile << n << endl;

    myfile.close();

	return 0;

}