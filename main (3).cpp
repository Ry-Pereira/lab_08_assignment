/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;

class Matrix {
public:
	int number_of_rows;
	int number_of_columns;
	vector<vector<int>> grid;

	Matrix(int rows, int columns) {
		number_of_rows = rows;
		number_of_columns = columns;
		grid.resize(rows,vector<int>(columns,0));
	}

	void store_value(int row,int column,int value) {
		grid[row][column] = value;
	}

};

pair<Matrix,Matrix> create_matrices(string matrix_text_file){
    string line;
	int n = 1;
	int m=-1;
	int j = 0;
	int size_of_matrix;

	ifstream myfile(matrix_text_file);
	if (myfile.is_open()) {
		Matrix matrix1(0,0);
		Matrix matrix2(0,0);
		while (getline(myfile,line)) {
			if(!line.empty() && line.back() == '\n') {
				//Removes the newline character at the end of the line
				line.pop_back();
			}
			if(n ==1) {
				std::stringstream ss(line);
				cout << line<< "\n";
				ss >> size_of_matrix;
				int rows = size_of_matrix;
				int columns = size_of_matrix;
				matrix1 = Matrix(rows,columns);
				matrix2 = Matrix(rows,columns);

			}
			else {
				std::stringstream ss(line);
				string s;

				if(line.size()-1) {

					if(m < size_of_matrix) {
						for(int i = 0; i<size_of_matrix; i++) {
							std::getline(ss,s,' ');
							int value = stoi(s);
							matrix1.store_value(i,m,value);
							cout<<"MS Row: "<<m<< " Column: "<<i<< " Value: "<<value << "\n";
						}
						if(m == size_of_matrix) {
							cout<<"\n";
							j= 0;
						}
					}
					else{
						for(int i = 0; i<size_of_matrix; i++) {
							std::getline(ss,s,' ');
							int value = stoi(s);
							matrix2.store_value(i,j,value);
							cout<<"MR Row "<<j<< " Column: "<<i<< " Value: "<<value << "\n";
						}
						j++;
					}

				}

				m++;
				
			}
			n++;
		}
		myfile.close();
		return {matrix1,matrix2};
	}
}
Matrix create_matrice(string matrix_text_file){
    string line;
	int n = 1;
	int m=-1;
	int j = 0;
	int size_of_matrix;

	ifstream myfile(matrix_text_file);
	if (myfile.is_open()) {
		Matrix matrix1(0,0);
		Matrix matrix2(0,0);
		while (getline(myfile,line)) {
			if(!line.empty() && line.back() == '\n') {
				//Removes the newline character at the end of the line
				line.pop_back();
			}
			if(n ==1) {
				std::stringstream ss(line);
				cout << line<< "\n";
				ss >> size_of_matrix;
				int rows = size_of_matrix;
				int columns = size_of_matrix;
				matrix1 = Matrix(rows,columns);
				matrix2 = Matrix(rows,columns);

			}
			else {
				std::stringstream ss(line);
				string s;

				if(line.size()-1) {

					if(m < size_of_matrix) {
						for(int i = 0; i<size_of_matrix; i++) {
							std::getline(ss,s,' ');
							int value = stoi(s);
							matrix1.store_value(i,m,value);
							cout<<"MS Row: "<<m<< " Column: "<<i<< " Value: "<<value << "\n";
						}
					}

				}

				m++;
				
			}
			n++;
		}
		myfile.close();
		return {matrix1,matrix2};
	}
}

Matrix add_matrices(Matrix matrix_1,Matrix matrix_2){
    Matrix result_matrix{matrix_1.number_of_rows,matrix_1.number_of_columns};
    
    for(int row=0;row<matrix_1.number_of_rows;row++){
        for(int column = 0; column < matrix_1.number_of_columns;column){
            int value = matrix_1.grid[row][column] + matrix_2.grid[row][column];
            result_matrix.store_value(row,column,value);
            
        }
        
    }
    
    return result_matrix;
}

Matrix multiply_matrices(Matrix matrix_1,Matrix matrix_2){
    Matrix result_matrix{matrix_1.number_of_rows,matrix_1.number_of_columns};
    
    for(int row=0;row<matrix_1.number_of_rows;row++){
        for(int column = 0; column < matrix_1.number_of_columns;column){
            for(int colu = 0; colu < matrix_2.number_of_columns;colu){
            int value = matrix_1.grid[row][colu] * matrix_2.grid[colu][row];
            result_matrix.store_value(row,column,value);
            }
            
        }
        
    }
    
    return result_matrix;
}

void sum_diagonal(Matrix matrix_1,Matrix matrix_2){
    int d = 0;
    int matrix_1_result_main_sum = 0;
    int matrix_1_result_secondary_sum = 0;
    int matrix_2_result_main_sum = 0;
    int matrix_2_result_secondary_sum = 0;
    Matrix result_matrix_1{matrix_2.number_of_rows,matrix_2.number_of_columns};
    Matrix result_matrix_2{matrix_2.number_of_rows,matrix_2.number_of_columns};
    for(int row = 0; row < matrix_1.number_of_rows;row++;){
        matrix_1_result_main_sum+= matrix_1.grid[row][d]
        d++;
    }
    for(int row = matrix_1.number_of_rows; row > 0;row--;){
        matrix_1_result_secondary_sum+= matrix_1.grid[row][d]
        d--;
    }
    for(int row = 0; row < matrix_2.number_of_rows;row++;){
        matrix_2_result_main_sum+= matrix_2.grid[row][d]
        d++;
    }
    for(int row = matrix_2.number_of_rows; row > 0;row--;){
        matrix_2_result_secondary_sum+= matrix_2.grid[row][d]
        d--;
    }
    cout<< matrix_1_result_main_sum << "\n";
    cout<< matrix_1_result_secondary_sum << "\n";
    cout<< matrix_2_result_main_sum << "\n";
    cout<< matrix_2_result_secondary_sum << "\n";
    
}

int main()
{
	string matrix_numbers_text_file_name;
	cout<<"Hello Welcome to Matrix Operations and ETC." << "\n";
	cout<<"Enter Matrix Numbers Text File Name: ";
	cin >> matrix_numbers_text_file_name;
	pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
	Matrix matrix1 = matrices.first;
	Matrix matrix2 = matrices.second;
	
	return 0;
}