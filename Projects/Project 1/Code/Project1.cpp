// Project 1 - Vector and Matrix Operations

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
//#include "armadillo"

using namespace std;
//using namespace arma;
ofstream myfile;


int main(){

	// -~- Declaration of Variables -~- \\
	double n;
	string outfilename;

	cout << "Enter a number: "; // user enters a number 
	cin >> n;
	cout << "Enter a name for the output file: "; 
	// user enters a name for the output file
	cin >> outfilename;

	// body of the program



	// writing value to file, to be read and graphed in python later
    myfile.open(outfilename);
	//myfile << setiosflags(ios::showpoint | ios::uppercase); 
	// setting scientific notation of numbers
	myfile << n << endl;

    myfile.close();

	return 0;

}