// matrix_multiply.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "matrix_multiply.h"

typedef vector <double> record_t;
typedef vector <record_t> data_t;

// Below I overload the stream input operator to read a list of CSV fields (which is a CSV record).
//  Remember; a record is a list of doubles separated by commas ','.
istream& operator >> (istream& ins, record_t& record)
{
	string line;
	string field;
	double f = 0.0;
	
	record.clear();					//make certain the returned record contains only the stuff we read now
	getline(ins, line);				//read entire line into a string (a CSV record is terminated by a newline)
	stringstream ss(line);			//use a stringstream to separate the fields out of the line
	while (getline(ss, field, ','))
	{
		stringstream fs(field);		//convert each field into a double (we REQUIRE that the CSV contains only floats)
		fs >> f;
		record.push_back(f);		//add converted field to the end of the record
	}

	// We have read a single line, converted it to a list of fields, converted the fields from strings to doubles, and stored the 
	//  results in the argument record.  Now we return the argument stream as required by this input overload function.
	return ins;
}

// Below I overload the stream input operator to read a list of CVS records.
//  Here we only worry about reading in records, not fields.
istream& operator >> (istream& ins, data_t& data)
{
	data.clear();					//make certain the returned data only contains the CSV data we read now
	record_t record;				
	
	while (ins >> record)			//for every record we can read from the file, append it to our resulting data
	{
		data.push_back(record);
	}

	// Return the argument stream as required for this kind of input stream overload
	return ins;
}


int main()
{
		
	data_t data_1;						//This is the data for matrix_1
	data_t data_2;						//This is the data for matrix_2
	float matrix_result[100][100];		//This is the result of the matrix multiplication
	float result = 0.0;
	int matrix_1_row;
	int matrix_1_column;
	int matrix_2_row;
	int matrix_2_column;
	int matrix_result_row;
	int matrix_result_column;
	int i, j, k;
	
	ifstream infile_1("matrix_1.csv");	//This is the file containing the data, we read it into data.
	infile_1 >> data_1;

	if (!infile_1.eof())					//Alert if anything went wrong
	{
		cout << "ERROR: Had issues reading in the CSV file \n \n";
		return 1;
	}

	ifstream infile_2("matrix_2.csv");	//This is the file containing the data, we read it into data.
	infile_2 >> data_2;

	if (!infile_2.eof())					//Alert if anything went wrong
	{
		cout << "ERROR: Had issues reading in the CSV file \n \n";
		return 1;
	}

	/*cout << "The CSV file for matrix_1 contains " << data_1.size() << " records. \n";
	cout << "The third row, seventh column value is: " << data_1[3 - 1][7 - 1];
	cout << endl;

	cout << "The CSV file for matrix_2 contains " << data_2.size() << " records. \n";
	cout << "The third row, seventh column value is: " << data_2[3 - 1][7 - 1];
	cout << endl;

	cout << data_1[3 - 1][7 - 1] + data_2[3 - 1][7 - 1] << endl;*/

	matrix_1_row = data_1.size();
	matrix_1_column = data_1[0].size();

	//cout << "The size of the first matrix is " << matrix_1_row << " x " << matrix_1_column << ". \n";

	matrix_2_row = data_2.size();
	matrix_2_column = data_2[0].size();

	//cout << "The size of the second matrix is " << matrix_2_row << " x " << matrix_2_column << ". \n";

	if (matrix_1_column == matrix_2_row)
	{
		cout << "We can do a matrix multiply" << endl;
		//Create a resultant matrix for the multiplication and fill with zeros
		for (i = 0; i < matrix_1_row; ++i)
		{
			for (j = 0; j < matrix_2_column; ++j)
			{
				matrix_result[i][j] = 0;
			}
		}

		//To multiply matrices, multiply the rows of the first matrix by the columns of the second matrix
		for (i = 0; i < matrix_1_row; ++i)
		{
			for (j = 0; j < matrix_2_column; ++j)
			{
				for (k = 0; k < matrix_1_column; ++k)
				{
					matrix_result[i][j] += data_1[i][k] * data_2[k][j];
				}
			}
		}

		//Let's print out the Resultant Matrix
		cout << endl;
		cout << endl;
		cout << "The final Resultant Matrix is: " << endl;
		for (i = 0; i < matrix_1_row; ++i)
		{
			for (j = 0; j < matrix_2_column; ++j)
			{
				cout << " " << matrix_result[i][j];
				if (j == matrix_2_column - 1)
				{
					cout << endl;
				}
			}
		}
		//Note: Final result should be a matrix of size matrix_1_row by matrix_2_column
	}
	else
	{
		cout << "Impossible to do a matrix multiply due to mis-sized matrix shapes" << endl;
		//return 1;
	}

	// Holds output window open in Visual Studio if you are getting input from the user
	//  just need cin.get() if you are not getting any input from the user
	//cin.clear();
	//cin.ignore();
	//cin.get();

	return 0;
}


