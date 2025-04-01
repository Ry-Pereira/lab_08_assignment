//Program Name: Problem 1: Football Score Possibilities
//Brief Description: This program produces all possible combinations of scoring plays given by a NFL score from the user. The program keeps going until the player puts in a input of 0 or 1.
//Input: The input is a valid intger value from the user.
//Ouput: The ouput will be all possible combinations of scorinh plays as long as the NFL score input is not 0 or 1. If the input is 0 or 1, the progrma will ends as result.
//All collaborators: None
//Other Sources:Github Copilot and ChatGPT BroCode from Youtube, Stack Overflow, and GeekforGeeks
//Author: Ryan Antony Pereira
//Creation Date: 3/26/2025
//Last Modified Date: 4/1/2025

//Includes the iostream library file to include standard input and ouput for cin and cout
#include <iostream>
//Includes the C++ fstream libary for file input and output, open and close functionality
#include <fstream>
//Includes the C++ string library for string manipulation and implmentation
#include <string>
#include <cmath>
//Includes the C++ sstream library for file string parsing functionality
#include <sstream>
#include <vector>
using namespace std;


//Defining a Matrix class object
class Matrix {
//The private section, where class memeber cannot be directly accessed by outside of class
private:
	//Declares integer number of rows to hold the number of rows in a matrix 
	int number_of_rows;
	//Declares integer number of rows to hold the number of columns in a matrix 
	int number_of_columns;
	//Declares integer 2d vector grid to implement the matrix grid
	vector<vector<int>> grid;

	//The public section, where the functions can be accessed outside of class
	public:
	//Constructor for Matrix object that takes in a integer rows and columsn paramter arguments for initialization
	Matrix(int rows, int columns) {
		//Assigns number of rows to integer rows paramter argument
		number_of_rows = rows;
		//Assigns number of columns to integer columns paramter argument
		number_of_columns = columns;
		//Reesizes the 2d vector grid to the number of rows by number fo columns
		grid.resize(rows,vector<int>(columns,0));
	}

	//Stores value function that takes in a integer row,column, and value to store the value at the matrix grid at location row by column
	void store_value(int row,int column,int value) {
		//2d vector grid stores the value at grid at row by column
		grid[row][column] = value;
	}
	//Function for printing grid
	void print_grid() {
		//Prints to terminal the column numbers
	    cout<< "Column ";
		//For in loop to iterate through eaach column and print a number to indicate position of cell
	    for(int column = 0; column < number_of_columns+1; column++){
			////Prints to terminal ouput a | to indicate a barrier spacing
	        cout<< column << "|";
	    }
		//Prints newline spacing
	    cout<<"\n";
		//For in loop to iterate throguh each row
		for(int row= 1; row<number_of_rows; row++) {
			//Pritns to terminal ouput the Row and number wiht a | to indicate barreier spacing and cell location
	        cout<< "Row "<<row << "| ";
			//For in loop to iterate through each columns
			for(int column = 0; column < number_of_columns; column++) {
				//Prints to terminal ouput the value at grid of row by column location witha  space
				cout<<grid[row][column]<< " ";
			}
			//Prints newline spacing
			cout<<"\n";
		}
	}
};

//Function to return a created pair of 2 nxn matrices with string matrix text file arument passed in
pair<Matrix,Matrix> create_matrices(string matrix_text_file) {
	//Declares string line to hol line of file
	string line;
	//Declares and initializes integer line number to 1 to keep track of the number of line there are
	int line_number = 1;
	//Declares and initializes integer current row to -1 to keep track of the placment of rows to matrices
	int current_row=-1;
	//Declares and initializes integer current matrix 2 row to 0, to keep track of the placmeent of matrix 2 rows
	int current_matrix_2_row = 0;
	//Declares integer size of matrix to hold matrix size
	int size_of_matrix;
	//Matrix object matrix 1 is declared and initialized with with a 0,0 pair passed in to indicate the vector grid is 0,0 in size
	Matrix matrix1(0,0);
	//Matrix object matrix 2 is declared and initialized with with a 0,0 pair passed in to indicate the vector grid is 0,0 in size
	Matrix matrix2(0,0);

	//Opens the matrix text file in the matrix file ifstream object for reading and extracting information
	ifstream matrix_file(matrix_text_file);
	//The matrix file is openeded
	if (matrix_file.is_open()) {
	
		//Continously goes through line by line in matrix file until there are no more lines to read
		while (getline(matrix_file,line)) {
			//If the line is not empty and the back of it contains a newline character, it removes it
			if(!line.empty() && line.back() == '\n') {
				//Removes the newline character at the end of the line
				line.pop_back();
			}
			//If line number is 1, the matrix size number is there
			if(line_number ==1) {
				//Declares and intializes a stringstream object for parsing of the line
				std::stringstream ss(line);
				//Extracts the matrix size form the stirng stream object for storing in size of matrix
				ss >> size_of_matrix;
				//Declares and initializes rows to size of matrix
				int rows = size_of_matrix;
				//Declares and initializes columns to size of matrix
				int columns = size_of_matrix;
				//Declares and initializes matrix1 to Matrix object with rows and columns passed in
				matrix1 = Matrix(rows,columns);
				//Declares and initializes matrix2 to Matrix object with rows and columns passed in
				matrix2 = Matrix(rows,columns);
			}
			//If the line number is not 1, then the rest of the lines are Matrix numbers to be stored
			else {
				//Declares and intializes a stringstream object for parsing of the line
				std::stringstream ss(line);
				//Declares string cell element
				string cell_element;
				//Checks if line is not empty with the line size
				if(line.size()-1) {
					//If current row is within bound of size of matrix
					if(current_row < size_of_matrix) {
						//For in loop to iterate through each column 
						for(int column = 0; column<size_of_matrix; column++) {
							//Gets the cell element until hitting a empty space and stores it in cell element
							std::getline(ss,cell_element,' ');
							//Declares and initializes cell element convert to integer
							int value = stoi(cell_element);
							//matrix 1 object executes the store value function with current row and colum with value passed in to store that value in the row by colum ni grid of matrix1
							matrix1.store_value(current_row,column,value);
						}
						//If the current row is equal to size of matrix, the next matrix is to be stored with the other elements
						if(current_row == size_of_matrix) {
							//Initialzies current matrix 2 row to 0
							current_matrix_2_row = 0;
						}
					}
					//Current row is not less than size of matrix, means the nex matrix needs to be stored with elements
					else {
						//For in loop to iterate through each column
						for(int column = 0; column<size_of_matrix; column++) {
							////Gets the cell element until hitting a empty space and stores it in cell element
							std::getline(ss,cell_element,' ');
							//Declares and initializes cell element convert to integer
							int value = stoi(cell_element);
							//matrix 2 object executes the store value function with current matrix 2 row and colum with value passed in to store that value in the row by colum ni grid of matrix2
							matrix2.store_value(current_matrix_2_row ,column,value);
						}
						//current matrix 2 row is incremented
						current_matrix_2_row ++;
					}
				}
				//Current row is incremented
				current_row++;
			}
			//Line number is incremented
			line_number++;
		}
	}
	//Matrix file is closed
	matrix_file.close();
	//Returns the pair with amtrix 1 and 2 in it
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
//Function that returns a matrix with its columns swapped 
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

//Function that returns a updated matrix object with integer row,column, and value passed in as argument to update matrix at row by column location with new value
Matrix update_matrix(Matrix matrix,int row,int column, int value) {
	//Matrix obejct executes the store value with row,column,value input passed in to store the value at that row by column location
	matrix.store_value(row,column,value);
	//Returns matrix object
	return matrix;
}

//Function,returns nothing, prints the menu for user to see what choice they want to make on what matrix operation they want to make
void print_menu() {
	//Prints ouput to terminal to prompt the user that choice 1 is for them to input a 2 nxn matrix text file to read and stores the matrixes separate and print them to the termianl
	cout<<"1: Read values from a file into the matrix" << "\n";
	//Prints ouput to terminal to prompt the user that choice 2 is for them to input a 2 nxn matrix text file to read and stores the matrixes, and perform an addition operation, and print the result to terminal
	cout<<"2: Add two matrices and display the result" << "\n";
	//Prints output to terminal to prompt the user that choice 3 is for them to input a 2 nxn matrix text file to read and stores the matrixes seperate, and perform a multiplication operation, and print the result to terminal.
	cout<<"3: Multiply two matrices and display the result" << "\n";
	//Prints output to termianl to prompt the user that chouce 4 is for them to input a 1 nxn matrix text file to read and stores the matrix, and print out the sum of the main and secondary diagonals of that matrix
	cout<<"4: Get the sum of matrix diagonal elements" << "\n";
	//Prints output to terminal to prompt the user that choice 5 is for them to input a 1 nxn matrix text file to read and stores the matrix, and swap the rows based on user input, and print out the result matrix of the row swapiing.
	cout<<"5: Swap matrix rows and display the result" << "\n";
	//Prints output to terminal to prompt the user that choice 6 is for them to input a 1 nxn matrix text file to read and stores the matrix, and swap the columns based on user input, and print out the result matrix of the column swapiing.0
	cout<<"6: Swap matrix columns and display the result" << "\n";
	//Prints output to terminal to prompt the user that choice 7 is for them to input a 1 nxn matrix text file to read and stores the matrix, and updates it by the users row,column, and value input and updates the matrix on that info, and prints out the reuslt matrix of that
	cout<<"7: Update matrix  at row by column with new value and display the result" << "\n";
}
//Choice selection, returns nothing, to indicate the user to make a choice on what matric operation choice to be done
void choice_selection() {
	//Declares integer choice
	int choice;
	//Prints ouput to terminal to prompt the user for a choice input
	cout<<"Choice: ";
	//Stores user input in choice
	cin  >> choice;
	//Declares string matrix numbers text file name
	string matrix_numbers_text_file_name;
	//Declares and initializes matrix1 matrix object witha  grid size of 0 and 0 indicated by those arguments passed in
	Matrix matrix1(0,0);
	//Declares and initializes matrix2 matrix object witha  grid size of 0 and 0 indicated by those arguments passed in
	Matrix matrix2(0,0);
	//Declares and initializes result matrix object witha  grid size of 0 and 0 indicated by those arguments passed in
	Matrix result_matrix(0,0);
	//Declares and initializes matrix matrix object witha  grid size of 0 and 0 indicated by those arguments passed in
	Matrix matrix(0,0);

	//Swtich case statement with choice passed in as argument, to check what choice was made, and what operation to execute
	switch(choice) {
	//If choice case is integer 1, Choice 1 is executed for a given 2 nxn matrix, to print the two matrices
	case 1:
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
		//Prints output termianl the printed matrix 1 grid
		cout<< "Matrix 1: \n";
		//Result matrix object executes the print grid function
		matrix1.print_grid();
		//Printed outout to terminal some newline spacing
		cout<< "\n";
		//Prints output termianl the printed matrix 1 grid
		cout<< "Matrix 2: \n";
		//Result matrix object executes the print grid function
		matrix2.print_grid();
		//Break statement to get of switch case statement
		break;
	}
	//If choice case is integer 2, Choice 2 is executed for a given 2 nxn matrix, add the two matrices
	case 2:
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
		//Result matrix is a stores result matrix from the ouput of the executed add matrices function with matrix 1 and 2 passed in as argument
		result = add_matrices(matrix1,matrix2);
		//Prints ouput to terminal the result output
		cout<<"Result: \n";
		//Result matrix object executes the print grid function
		result.print_grid();
		//Break statement to get of switch case statement
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