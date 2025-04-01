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
	void print_grid() {
	    cout<< "Col ";
	    for(int column = 0; column < number_of_columns+1; column++){
	        cout<< column << "|";
	    }
	    cout<<"\n";
		for(int row= 0; row<number_of_rows; row++) {
	        cout<< "Row "<<row << "| ";
			for(int column = 0; column < number_of_columns; column++) {
				cout<<grid[row][column]<< " ";
			}
			cout<<"\n";
			
		}
	}

};

pair<Matrix,Matrix> create_matrices(string matrix_text_file) {
	string line;
	int n = 1;
	int m=-1;
	int j = 0;
	int size_of_matrix;
	Matrix matrix1(0,0);
	Matrix matrix2(0,0);

	ifstream myfile(matrix_text_file);
	if (myfile.is_open()) {
	
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
							matrix1.store_value(m,i,value);
					
						}
						if(m == size_of_matrix) {
							cout<<"\n";
							j= 0;
						}
					}
					else {
						for(int i = 0; i<size_of_matrix; i++) {
							std::getline(ss,s,' ');
							int value = stoi(s);
							matrix2.store_value(j,i,value);
							
						}
						j++;
					}
				}
				m++;
			}
			n++;
		}
		
	}
	myfile.close();
	return {matrix1,matrix2};
}
Matrix create_matrice(string matrix_text_file) {
	string line;
	int n = 1;
	int m= -1;
	int j = 0;
	int size_of_matrix;
	Matrix matrix1(0,0);

	ifstream myfile(matrix_text_file);
	if (myfile.is_open()) {
	
		while (getline(myfile,line)) {
			if(!line.empty() && line.back() == '\n') {
				//Removes the newline character at the end of the line
				line.pop_back();
			}
			if(n ==1) {
				std::stringstream ss(line);
				ss >> size_of_matrix;
				int rows = size_of_matrix;
				int columns = size_of_matrix;
				matrix1 = Matrix(rows,columns);

			}
			else {
				std::stringstream ss(line);
				string s;
				if(line.size()-1) {
					if(m < size_of_matrix) {
						for(int i = 0; i<size_of_matrix; i++) {
							std::getline(ss,s,' ');
							int value = stoi(s);
							matrix1.store_value(m,i,value);
							
						}
					}
				}
				m++;
			}
			n++;
		}
	}
	
	myfile.close();
	return matrix1;
}

Matrix add_matrices(Matrix matrix_1,Matrix matrix_2) {
	Matrix result_matrix(matrix_1.number_of_rows,matrix_1.number_of_columns);

	for(int row=0; row<matrix_1.number_of_rows; row++) {
		for(int column = 0; column < matrix_1.number_of_columns; column++) {
			int value = matrix_1.grid[row][column] + matrix_2.grid[row][column];
			result_matrix.store_value(row,column,value);
		}
	}
    cout<<"hello";
    cout<<"Out"<< result_matrix.grid[0][0] << "\n";
    
	return result_matrix;
}

Matrix multiply_matrices(Matrix matrix_1,Matrix matrix_2) {
	Matrix result_matrix{matrix_1.number_of_rows,matrix_1.number_of_columns};

	for(int row=0; row<matrix_1.number_of_rows; row++) {
		for(int column = 0; column < matrix_1.number_of_columns; column++) {
		    int value = 0;
			for(int colu = 0; colu < matrix_2.number_of_columns; colu++) {
				value += matrix_1.grid[row][colu] * matrix_2.grid[colu][column];
				result_matrix.store_value(row,column,value);
			}

		}

	}
  
	return result_matrix;
}

void sum_diagonal(Matrix matrix_1) {
   
	int d = 0;
	int matrix_1_result_main_sum = 0;
	int matrix_1_result_secondary_sum = 0;

	for(int row = 0; row < matrix_1.number_of_rows; row++) {
		matrix_1_result_main_sum+= matrix_1.grid[row][d];

		d++;
	}
	d = matrix_1.number_of_columns-1;
	for(int row = 0; row < matrix_1.number_of_rows; row++) {
		matrix_1_result_secondary_sum+= matrix_1.grid[row][d];
		
		d--;
	}
	cout<<"Matrix Main Diagonal Sum " << matrix_1_result_main_sum << "\n";
	cout<<"Matrix Secondary Diagonal Sum"<< matrix_1_result_secondary_sum << "\n";


}

Matrix swap_rows(Matrix matrix_1,int row_num_1,int row_num_2) {
	Matrix result_matrix = matrix_1;

	if(row_num_1> matrix_1.number_of_rows) {
		return result_matrix;
	}
	else if(row_num_2> matrix_1.number_of_rows) {
		return result_matrix;
	}
	else if(row_num_1 < 0) {
		return result_matrix;
	}
	else if(row_num_2 < 0) {
		return result_matrix;
	}
	else {
		for(int col = 0; col< matrix_1.number_of_rows; col++) {
			int value = matrix_1.grid[row_num_2][col];
			result_matrix.store_value(row_num_1,col,value);
		}
		for(int col = 0; col< matrix_1.number_of_rows; col++) {
			int value = matrix_1.grid[row_num_1][col];
			result_matrix.store_value(row_num_2,col,value);
		}
		return result_matrix;
	}

}
Matrix swap_columns(Matrix matrix_1,int column_num_1,int column_num_2) {
	Matrix result_matrix = matrix_1;

	if(column_num_1> matrix_1.number_of_rows) {
		return result_matrix;
	}
	else if(column_num_2> matrix_1.number_of_rows) {
		return result_matrix;
	}
	else if(column_num_1 < 0) {
		return result_matrix;
	}
	else if(column_num_2 < 0) {
		return result_matrix;
	}
	else {
		for(int row = 0; row< matrix_1.number_of_rows; row++) {
			int value = matrix_1.grid[row][column_num_2];
			result_matrix.store_value(row,column_num_1,value);
		}
		for(int row = 0; row< matrix_1.number_of_rows; row++) {
			int value = matrix_1.grid[row][column_num_1];
			result_matrix.store_value(row,column_num_2,value);
		}
		return result_matrix;
	}

}

Matrix update_matrix(Matrix matrix,int row,int column, int value) {
	matrix.store_value(row,column,value);
	return matrix;
}

void print_menu() {
	cout<<"1: Read values from a file into the matrix" << "\n";
	cout<<"2: Add two matrices and display the result" << "\n";
	cout<<"3: Multiply two matrices and display the result" << "\n";
	cout<<"4: Get the sum of matrix diagonal elements" << "\n";
	cout<<"5: Swap matrix rows and display the result" << "\n";
	cout<<"6: Swap matrix columns and display the result" << "\n";
	cout<<"7: Update matrix rows and display the result" << "\n";
}
void choice_selection() {
	int choice;
	cout<<"Choice: ";
	cin  >> choice;
	string matrix_numbers_text_file_name;
	Matrix matrix1(0,0);
	Matrix matrix2(0,0);
	Matrix result_matrix(0,0);
	Matrix matrix(0,0);


	switch(choice) {
	case 1:
	{
		cout<<"Enter Matrix Numbers Text File Name: ";
		cin >> matrix_numbers_text_file_name;
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		matrix1 = matrices.first;
		matrix2 = matrices.second;
		cout<< "Matrix 1: \n";
		matrix1.print_grid();
		cout<< "\n";
		cout<< "Matrix 2: \n";
		matrix2.print_grid();
		break;
	}
	case 2:
	{
		cout<<"Enter Matrix Numbers Text File Name: ";
		cin >> matrix_numbers_text_file_name;
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		matrix1 = matrices.first;
		matrix2 = matrices.second;
		result = add_matrices(matrix1,matrix2);
		cout<<"Result: \n";
		result.print_grid();
		break;
	}

	//If choice case is integer 3, Choice 3 is executed for a given 2 nxn matrix,  to multiply the two matrices
	case 3:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//matrices pair stores result ouput of the executed function called create matrices with matrix numbers text filename passed in as argument this gives two matrixes
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		//Matrix1 is set to the first of the matrices pair
		matrix1 = matrices.first;
		//Matrix2 is set to the second of the matrices pair
		matrix2 = matrices.second;
		//Result matrix is a stores result matrix from the ouput of the executed multiply matrices function with matrix 1 and 2 passed in as argument
		result_matrix = multiply_matrices(matrix1,matrix2);
		//Prints ouput to terminal the result output
		cout<<"Result: \n";
		//Result matrix object executes the print grid function
		result_matrix.print_grid();
		//Break statement to get of switch case statement
		break;
	}
	//If choice case is integer 4, Choice 4 is executed for a given matrix, to coutned for the sum of its main and secondary diagonal sum, to be printed to the user
	case 4:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//matrix stores result ouput of the executed function called create matrice with matrix numbers text filename passed in as argument
		matrix = create_matrice(matrix_numbers_text_file_name);
		//Result matrix object executes the print grid function
		matrix.print_grid();
		//Sum diagoanl function is executed with matrix input passed in as arugment to count up the main and secodnary sum diagonal
		sum_diagonal(matrix);
		//Break statement to get of switch case statement
		break;
	}
	//If choice case is integer 5, Choice 5 is executed for a given matrix to swap row values, and be printed to terminal
	case 5:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//matrix stores result ouput of the executed function called create matrice with matrix numbers text filename passed in as argument
		matrix = create_matrice(matrix_numbers_text_file_name);
		//Declares integer row1
		int row1;
		//Declares integer row2
		int row2;
		//Prints ouput to terminal to prompt the user for a Row 1 number to Swap
		cout<<"Enter Row 1 to Swap";
		//Stores user input in row1
		cin >> row1;
		//Prints ouput to terminal to prompt the user for a Row 2 number to Swap
		cout<<"Enter Row 2 to Swap";
		//Stores user input in row2
		cin >> row2;
		//Result matrix stores the updated matrix of result from the executed swap rows function with matrix,row1, and row2 passed in arguments, to swap the row valus
		result_matrix = swap_rows(matrix,row1,row2);
		//Result matrix object executes the print grid function
		result_matrix.print_grid();
		//Break statement to get out of switch case statement
		break;
	}
	//If choice case is integer 6, Choice 6 is executed for a given matrix to swap column values, and be printed to terminal
	case 6:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//matrix stores result ouput of the executed function called create matrice with matrix numbers text filename passed in as argument
		matrix = create_matrice(matrix_numbers_text_file_name);
		//Declares integer column1
		int column1;
		//Declares integer column2
		int column2;
		//Prints ouput to terminal to prompt the user for a Column 1 number to Swap
		cout<<"Enter Column 1 to Swap";
		//Stores user input in column1
		cin >> column1;
		//Prints ouput to terminal to prompt the user for a Column 2 number to Swap
		cout<<"Enter Column 2 to Swap";
		//Stores user input in column2
		cin >> column2;
		//Result matrix stores the updated matrix of result from the executed swap columns function with matrix,column1, and column2 passed in arguments, to swap the column valus
		result_matrix = swap_columns(matrix,column1,column2);
		//Result matrix object executes the print grid function
		result_matrix.print_grid();
		//Break statement to get out of switch case statement
		break;
	}
	//If choice case is integer 7, Choice 7 is executed for a given matrix to be given a updated value at the row by column location
	case 7:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//matrix stores result ouput of the executed function called create matrice with matrix numbers text filename passed in as argument
		matrix = create_matrice(matrix_numbers_text_file_name);
		//Declares integer column
		int column;
		//Declares integer row
		int row;
		//Declares integer value
		int value;
		//Prints ouput to terminal to prompt the user for a row number
		cout<<"Enter Row Number: ";
		//Stores user input into row
		cin>>row;
		//Prints ouput to terminal to prompt the user for a column number
		cout<<"Enter Column Number: ";
		//Stores user input into column
		cin>>column;
		//Prints ouput to terminal to prompt the user for a value to be stored in the matrix at location row by column
		cout<<"Enter Value to be stores: ";
		//Stores the user input into value
		cin>>value;
		//Result matrix stores the updated matrix result from the update matrix function with matrix,row,column, and value input. The matrix is updated with the value stored in the grid at row by cloumn location
		result_matrix = update_matrix(matrix,row,column,value);
		//Result matrix object executes the print grid function
		result_matrix.print_grid();
		//Break statement to get out of switch case statement
		break;
	}

	}

}

//This function is the main entry point into the program itself
int main()
{
	//Prints ouput to terminal to welcome the user to Matrix Operation and Etc.
	cout<<"Hello Welcome to Matrix Operations and ETC." << "\n\n";
	//Executes the print menu function
	print_menu();
	//Pritns output to terminal newline spacing
	cout<< "\n";
	//Executes the choice selection function that asks the user what choice they want and will execute that Matrix operation choice
	choice_selection();
	//Returns 0 to indicate to the user that program has ended without issue
	return 0;
}