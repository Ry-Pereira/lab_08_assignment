//Program Name: Problem 8: Matrix Function and Operations Program
//Brief Description: This program will ask the user for a matrix text fiel and options choice for adding or multiplying matrices, finding the sum diagonal, swapping rows and columsn,a dn updating the matrix at row by cloumn locaiton.
//Input: The input is a matrix text fileeither 1 nxn matrix or 2 nxn matrix with matrix sizes at the top to indicate the size of the matrix or matrices. A choice input will be put int to ask the user what Matrix funcion or operation needs to be executed based on their liking.
//Ouput: The ouput will welcome the user and give a goodbye message to the user. Print a menu to the user. Print result matrices based on the choice, that they ask. The hcoice ouptu will dicatte what Matrix function or operation needs to executed.
//All collaborators: None
//Other Sources:Github Copilot and ChatGPT 
//Author: Ryan Antony Pereira
//Creation Date: 3/26/2025
//Last Modified Date: 4/14/2025

//ChatGPT helped with debuggin, pointing out errors, helping me correct my code.

//Includes the iostream library file to include standard input and ouput for cin and cout
#include <iostream>
//Includes the C++ fstream libary for file input and output, open and close functionality
#include <fstream>
//Includes the C++ string library for string manipulation and implmentation
#include <string>
//Includes the C++ sstream library for file string parsing functionality
#include <sstream>
//Includes the C++ vector library for array manipulation and implementation
#include <vector>


//Include the C++ cmath library to do the absolut value of a integer value to be turned to positive
//Using standard namespace to avoid using std:: prefix
using namespace std;


//ChatGPT helped me with the process of class construction. Suggested vectors for matrix construction

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


	//ChatGPT helped me with the public function that can be be accessed, espicially the getter functions

	//The public section, where the functions can be accessed outside of class
	public:
	
	//Function to get number of rows
	int get_number_of_rows(){
		//Returns the number of rows
	    return number_of_rows;
	}
	//Function to get number of columns
	int get_number_of_columns(){
		//Return the number of rows
	    return number_of_rows;
	}
	//FUnction to get grid value with integer row and columns passed in as argument
	int get_grid_value(int row, int column){
		//Returns the grid value at row by column location
		return grid[row][column];
	}
	
	
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
	    cout<< "Col ";
		//For in loop to iterate through eaach column and print a number to indicate position of cell
	    for(int column = 1; column < number_of_columns+1; column++){
			//Prints to terminal ouput a | to indicate a barrier spacing
	        cout<< column << "| ";
	    }
		//Prints newline spacing
	    cout<<"\n";
		//For in loop to iterate throguh each row
		for(int row= 0; row<number_of_rows; row++) {
			//Pritns to terminal ouput the Row and number wiht a | to indicate barreier spacing and cell location
	        cout<< "Row "<<row+1 << "| ";
			//For in loop to iterate through each columns
			for(int column = 0; column < number_of_columns; column++) {
				//Prints to terminal ouput the value at grid of row by column location witha  space
				//If the grid at row by colum value is positve an is between 0 and 10
				if(grid[row][column] < 10 && grid[row][column] >= 0){
					//Declares string num to the concatenation product of 0 and string converted of the grid at row by column
				    string formmated_number = "0" + to_string(grid[row][column]);
				    cout<<formmated_number << " ";
				}
				//If the grid at row by colum value is negative but is bewteen 0 and -10
				else if(grid[row][column] < 0 && grid[row][column] > -10){
					//Declares string num to the concatenation product of 0 and string converted of the grid at row by column of the absolut to positive then convert to be negative
					string formmated_number = "-0" + to_string(abs(grid[row][column]));
				    cout<<formmated_number << " ";
				}
				//Else if the vvalue is positive or negative but is not between 0 or 10, so it does not need to be formatted
				else{
				//Prints to terminal ouput the value at grid of row by column location witha  space
				cout<<grid[row][column]<< " ";
				}
			}
			//Prints newline spacing
			cout<<"\n";
		}
	}
};


//ChatGPT was used to error check and debug this function, and give suggestion to streamline the flow of this code process

//Function to to check if file is valid, it takes a string text file to validate the file, but also see if the matrixes inside of it are equal to matrixes produces to make sure the right number of matrixes are need to be extracted
bool file_check(int matrices_produced,string text_file){

	//Declares size of matrix to hold the matrix size
    int size_of_matrix = 0;
	//Declares an iftsream file object to read it
    ifstream matrix_file(text_file);
	//Declare a string line to store line of file
    string line;
	//Declare and initialize the row amount to 0, to store the amount of rows
    int row_amount = 0;
	//Declare and initializes the got matrix size to false, in order to flag down if the matrix size was retrived
    bool got_matrix_size = false;
    
	//If the matrix is unable to be opened, the file does not exist
    if(!matrix_file.is_open()){
		//Prints to terminal that the file file name is not valid
		cout<<"File name is not valid"<<"\n";
		//Returns false to indicate it failed the file check
        return false;
    }
    
	//Loops through each line in the file
	while (getline(matrix_file,line)) {
		//If the line size is empty, it skips it
	    if(line.empty()){
			//Skips line and moves to next one
	        continue;
	    }
		//Create a stringstream object to parse line
	   stringstream ss(line);
	   //Declare a string elem to store element value in each line in the file
	   string elem;

	   //Chatgpt helped me revise this section so that matrix size will actually be found
	   
	   //If the matrix size has not been stored yet
	   if(got_matrix_size == false){
		//Reads the first value in line to size of matrix
	       ss>> size_of_matrix;
		   //Holds the integer space position of the line, to see if there is only value in the line
	       int space_position = line.find(' ');
		   //If there is any space, there is more values in the line, so it wont be passed as matrix size
	       if(ss >> elem || size_of_matrix <= 0){
				//Prints to terminal there is no matrix size
			   cout<<"There is no matrix size"<<"\n";
			   //Returns false to indicate there is no matrix size
	           return false;
	       }
           
		   
		   //Sets got matrix size to true, to indicate the matrix size was retrieved
	       got_matrix_size = true;
		   //Continues to the next line in file
	       continue;
	   }
	   //If the matrix size was retreived, the line contains matrix data
	   if(got_matrix_size == true){
		   //Declares the column num to 0, to indcate the number of column values occupying each line
	       int column_num = 0;
	       
		   //Loops throuugh each value in the line as stores it in elem
    	   while(ss>> elem){
				//Column num is incremented
    	       column_num++;
	       } 
		   //If the colum number is not equal to the size of matrix, then its not a valid nxn matrix, because there is not size of columns
	       if(column_num != size_of_matrix){
			   //Returns false to indcate there is not enough columns
			   cout<<"There are not the right amount of columns in the matrix rows" << "\n";
			   //Return false
	           return false;
	       }
		   //Increment row amount
	       row_amount++;
		   //Provides newline spacing
	       cout<<"\n";
	   }
	   }
	   //If the matrix size was not retrieved
       if(!got_matrix_size){
		//Prints to output the matrix size was not found in the file
        cout<<"Matrix Size not found in file" << "\n";
		//Returns false
        return false;
       }

	   //If the matrices produces is not equal to the row amoutn  divided by size of matrix, then there is not the right maount of matrixes in the text file
	   if(row_amount % size_of_matrix != 0 || matrices_produced != row_amount/size_of_matrix){
			//Reutnrs false with message to indcate the text file has inconsistent matrixes in the file to the particaular operation
	       cout<<"For this particular operation, it requires"<<matrices_produced<<" matrices to be in the text file"<<"\n";
		   //Returns false
	       return false;
	   }
	   //Returns true to indcate it passed all checks, to indicate it is a valid matrix text file
	   return true;

}




//Chatgpt suggested withr returnng a pair of Matrix objects in order to return two matrices

//Function to return a created pair of 2 nxn matrices with string matrix text file arument passed in
pair<Matrix,Matrix> create_matrices(string matrix_text_file) {
	//Declares string line to hol line of file
	string line;
	//Declares and initializes integer line number to 1 to keep track of the number of line there are
	int line_number = 0;
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
	//Declares got matrix size to false, to indicate the flag if the matrix size was retrieved
	bool got_matrix_size = false;

	//Opens the matrix text file in the matrix file ifstream object for reading and extracting information
	ifstream matrix_file(matrix_text_file);
	//The matrix file is opened
	if (!matrix_file.is_open()) {
		//Continously goes through line by line in matrix file until there are no more lines to read
        cout<<"Matrix file is unable to be opened"<<"\n";
        return {matrix1,matrix2};
    }
	//While loop to continously go through each lin in the matrix file
	while (getline(matrix_file,line)) {
		//If line is empty
		if(line.empty())
			//Continues in the loop 
            continue;
            
		//Chatgpt helped me revise this section so that matrices will be actually returned. As I was having initial issue with it. Below code revision helped out.
            
		//Declares and intializes a stringstream object for parsing of the line
		std::stringstream ss(line);
		if(!got_matrix_size){
		
        	//Extracts the matrix size form the stirng stream object for storing in size of matrix
        	ss >> size_of_matrix;
			//If the size of matrix is less than or equal to 0
        	if(size_of_matrix <= 0){
				//Prints to ouptut that the matrix size is nvalud
                cout<<"Invalud matrix size"<<"\n";
				//Return pair of empty matrices
                return {Matrix(0,0),Matrix(0,0)};
            }
            //Declares and initializes matrix1 to Matrix object with rows and columns passed in
    		matrix1 = Matrix(size_of_matrix,size_of_matrix);
			//Declares and initializes matrix2 to Matrix object with rows and columns passed in
    		matrix2 = Matrix(size_of_matrix,size_of_matrix);
			//Sets got matrix size to true
        	got_matrix_size = true;
			//Continue on in the loop
            continue;
		}
		    
		//ChatGPT suggested before way to find if there are missing values in the row
		//ChatGPT also helped find a better way of storing matrix values
		
		//For in loop to loop thorugh each column
		for(int column = 0; column< size_of_matrix; column++){
			//Delcares string cell element to empty string
			string cell_element = "";
			//If the cell element is not retrieved
			if(!(ss>> cell_element)){
				//Prints to ouput that there is missing values in the row
				cout<<"Missing values in the row"<<"\n";
				//Returns a pair of empty matrixes
				return {Matrix(0,0),Matrix(0,0)};
			}
			//Ineger value is set to the cell element converted to integer
		    int value = stoi(cell_element);
			
			//If the line number is less than size of matrix
		    if(line_number < size_of_matrix){
				//Matrix 1 stores the value of the line number minus size of matrix as row, column as column, and value as the value to be stored
		        matrix1.store_value(line_number,column,value);
			}
			//If the line number is more than the size of matrix
			else{
				//Matrix 2 stores the value of the line number minus size of matrix as row, column as column, and value as the value to be stored
				matrix2.store_value(line_number-size_of_matrix,column,value);
			}
		}
		//Line number is incremented
		line_number++;
		    
	}
	//Returns the pair of matrix1 and matrix2 in the pair
    return {matrix1,matrix2};
}


//ChatGpt helped me with finnding how to add two matrices

//Function that return a result matrix of a product of addition of two matrices, being the matrix 1 and 2 Matrix object input
Matrix add_matrices(Matrix matrix_1,Matrix matrix_2) {
	//Matrix object result matrix is declared and initializes with matrix 1 number of rows and columsn passed in to resize it
	Matrix result_matrix(matrix_1.get_number_of_rows(),matrix_1.get_number_of_columns());
	//For in loop to iterate through each row in matrix 1
	for(int row=0; row<matrix_1.get_number_of_rows(); row++) {
		//For in loop to iterate through each column in matrix 1
		for(int column = 0; column < matrix_1.get_number_of_columns(); column++) {
			//Integer value declared and initialzied to the prouduct of matri1 plus matrix 2 at the same location of row by column
			int value = matrix_1.get_grid_value(row,column) + matrix_2.get_grid_value(row,column);
			//Result matrix object executes the store value method with row,column,value passed in as argument
			result_matrix.store_value(row,column,value);
		}
	}
	//Returns the result matrix object
	return result_matrix;
}


//ChatGpt helped me with finnding how to multiply two matrices

//Function that return a result matrix of a product of multiplication of two matrices, being the matrix 1 and 2 Matrix object input
Matrix multiply_matrices(Matrix matrix_1,Matrix matrix_2) {
	//Matrix object result matrix is declared and initializes with matrix 1 number of rows and columsn passed in to resize it
	Matrix result_matrix{matrix_1.get_number_of_rows(),matrix_1.get_number_of_columns()};
	//For in loop to iterate through each row in matrix 1
	for(int row=0; row<matrix_1.get_number_of_rows(); row++) {
		//For in loop to iterate through each column in matrix 1
		for(int column = 0; column < matrix_1.get_number_of_columns(); column++) {
			//Integer value is declared and initialized to 0
		    int value = 0;
			//For in loop to iterate thorugh ech column in matrix 2
			for(int column_2 = 0; column_2 < matrix_2.get_number_of_columns(); column_2++) {
				//Value is incremented by multiplication product of matrix 1 at row by column in grid times the matrix2 grid at column2 by column
				value += matrix_1.get_grid_value(row,column_2) * matrix_2.get_grid_value(column_2,column);
				//Result matrix object executes the store value method with row,column,value passed in as argument
				result_matrix.store_value(row,column,value);
			}
		}
	}
	//Returns the result matrix object
	return result_matrix;
}

//ChatGpt helped me with finnding the sum of the diagonals

//Function that returns nothing, calculates the sumd idgaonal of the main and secondary digaonal of the matrix
void sum_diagonal(Matrix matrix_1) {
	//Declare and initializes column number to 0
	int column_number = 0;
	//Declares and initializes matrix 1 result main sum to 0
	int matrix_1_result_main_sum = 0;
	//Declares and initializes matrix 1 result secondary sum to 0
	int matrix_1_result_secondary_sum = 0;

	//For in loop to iterate through each row n matrix 1 number of rows
	for(int row = 0; row < matrix_1.get_number_of_rows(); row++) {
		//Matrix 1 result main sum is incremeneted by the value at matrix 1 gird at location row  by column number
		matrix_1_result_main_sum+= matrix_1.get_grid_value(row,column_number);
		//Column number is incremented
		column_number++;
	}

	//Column number is set to matrix 1 number of columns minus by 1
	column_number = matrix_1.get_number_of_columns()-1;
	//For in loop to iterate through each row n matrix 1 number of rows
	for(int row = 0; row < matrix_1.get_number_of_rows(); row++) {
		//Matrix 1 result main sum is incremeneted by the value at matrix 1 gird at location row  by column number
		matrix_1_result_secondary_sum+= matrix_1.get_grid_value(row,column_number);
		//Column number is decremented
		column_number--;
	}
	//Prints ouput to terminal the Matrix main diagonal sum 
	cout<<"Matrix Main Diagonal Sum: " << matrix_1_result_main_sum << "\n";
	//Prints ouput to terminal the Matrix secondary diagonal sum 
	cout<<"Matrix Secondary Diagonal Sum: "<< matrix_1_result_secondary_sum << "\n";
}


//ChatGpt helped me with finnding how to swap two rows

//Function that return a matrix with its rows swapped, takes in a matrix object, integer row num 1 and 2 as input
Matrix swap_rows(Matrix matrix_1,int row_num_1,int row_num_2) {
	//Matrix result matrix object is set to the matrix 1 object
	Matrix result_matrix = matrix_1;


	//If row num 1 is greater than matrix 1 number of rows, it is out of bounds
	if(row_num_1> matrix_1.get_number_of_rows()) {
		//Returns result matrix object
		return result_matrix;
	}
	//If row num 2 is greater than matrix 1 number of rows, it is out of bounds
	else if(row_num_2> matrix_1.get_number_of_rows()) {
		//Returns result matrix object
		return result_matrix;
	}
	//If row num 1 is lesser than 0, it is out of bounds
	else if(row_num_1 < 0) {
		//Returns result matrix object
		return result_matrix;
	}
	//If row num 2 is lesser than 0, it is out of bounds
	else if(row_num_2 < 0) {
		//Returns result matrix object
		return result_matrix;
	}
	//If rows are in bounds, swapping can be done for the rows
	else {
		//For in loop to iterate through each column
		for(int column = 0; column< matrix_1.get_number_of_columns(); column++) {
			//Declare and initialize value to the matrix1 at grid lcoation row num2 by column
			int value = matrix_1.get_grid_value(row_num_2,column);
			//Result matrix stores the value at the row num1 location at column with the value to swap it
			result_matrix.store_value(row_num_1,column,value);
		}
		//For in loop to iterate through each column
		for(int column = 0; column< matrix_1.get_number_of_columns(); column++) {
			//Declare and initialize value to the matrix1 at grid lcoation row num1 by column
			int value = matrix_1.get_grid_value(row_num_1,column);
			//Result matrix stores the value at the row num2 location at column with the value to swap it
			result_matrix.store_value(row_num_2,column,value);
		}
		//Returns the result matrix object with rows swapped
		return result_matrix;
	}
}



//ChatGpt helped me with finnding how to swap columns 

//Function that return a matrix with its rows swapped, takes in a matrix object, integer column num 1 and 2 as input
Matrix swap_columns(Matrix matrix_1,int column_num_1,int column_num_2) {
	//Matrix result matrix object is set to the matrix 1 object
	Matrix result_matrix = matrix_1;

	//If column num 1 is greater than matrix 1 number of columns, its out of bounds
	if(column_num_1> matrix_1.get_number_of_columns()) {
		//Returns result matrix
		return result_matrix;
	}
	//If column num 2 is greater than matrix 1 number of columns, its out of bounds
	else if(column_num_2> matrix_1.get_number_of_columns()) {
		//Returns result matrix
		return result_matrix;
	}
	//If column num 1 lessser than 0, it is out of bounds
	else if(column_num_1 < 0) {
		//Returns result matrix
		return result_matrix;
	}
	//If column num 2 lessser than 0, it is out of bounds
	else if(column_num_2 < 0) {
		//Returns result matrix
		return result_matrix;
	}
	//If column number are in bound, swapping of columns can happen
	else {
		//For in loop to iterate through each row
		for(int row = 0; row< matrix_1.get_number_of_rows(); row++) {
			//Declare and initialize value to the matrix1 at grid lcoation row by column num2
			int value = matrix_1.get_grid_value(row,column_num_2);
			//Result matrix stores the value at the row  location at column num 1 with the value to swap it
			result_matrix.store_value(row,column_num_1,value);
		}
		//For in loop to iterate through each row
		for(int row = 0; row< matrix_1.get_number_of_rows(); row++) {
			//Declare and initialize value to the matrix1 at grid lcoation row  by column num 1
			int value = matrix_1.get_grid_value(row,column_num_1);
			//Result matrix stores the value at the row  location at column num 2 with the value to swap it
			result_matrix.store_value(row,column_num_2,value);
		}
		//Returns the result matrix object with columns swapped
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

//Chatgpt helped with choice selection method.Suggested with declaring and initalizling matrixes to avoid error.

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
		cout<<"Enter 2 nxn Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//Declares is_valid to the result of file check with 2 as matrix preoducd, and matrix numbers text file name passed in
		bool is_valid = file_check(2,matrix_numbers_text_file_name);
		//If is valid is 0, it invalid
		if(is_valid == 0){
			//Prints to terminal that is invalid
		    cout<<"Invalid"<<"\n";
			//Breaks out of case switch statement
		    break;
		}
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
		cout<<"Enter 2 nxn Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//Declares is_valid to the result of file check with 2 as matrix preoducd, and matrix numbers text file name passed in
		bool is_valid = file_check(2,matrix_numbers_text_file_name);
		//If is valid is 0, it invalid
		if(is_valid == 0){
			//Prints to terminal that is invalid
		    cout<<"Invalid"<<"\n";
			//Breaks out of case switch statement
		    break;
		}
		//matrices pair stores result ouput of the executed function called create matrices with matrix numbers text filename passed in as argument this gives two matrixes
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		//Matrix1 is set to the first of the matrices pair
		matrix1 = matrices.first;
		//Matrix2 is set to the second of the matrices pair
		matrix2 = matrices.second;
		//Result matrix is a stores result matrix from the ouput of the executed add matrices function with matrix 1 and 2 passed in as argument
		result_matrix = add_matrices(matrix1,matrix2);
		//Prints ouput to terminal the result output
		cout<<"Result: \n";
		//Result matrix object executes the print grid function
		result_matrix.print_grid();
		//Break statement to get of switch case statement
		break;
	}
	//If choice case is integer 3, Choice 3 is executed for a given 2 nxn matrix,  to multiply the two matrices
	case 3:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter 2 nxn Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//Declares is_valid to the result of file check with 2 as matrix preoducd, and matrix numbers text file name passed in
		bool is_valid = file_check(2,matrix_numbers_text_file_name);
		//If is valid is 0, it invalid
		if(is_valid == 0){
			//Prints to terminal that is invalid
		    cout<<"Invalid"<<"\n";
			//Breaks out of case switch statement
		    break;
		}
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
		cout<<"Enter Single nxn Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//Declares is_valid to the result of file check with 2 as matrix preoducd, and matrix numbers text file name passed in
		bool is_valid = file_check(1,matrix_numbers_text_file_name);
		//If is valid is 0, it invalid
		if(is_valid == 0){
			//Prints to terminal that is invalid
		    cout<<"Invalid"<<"\n";
			//Breaks out of case switch statement
		    break;
		}
		//matrix stores result ouput of the executed function called create matrice with matrix numbers text filename passed in as argument
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		//Sum diagoanl function is executed with matrix input passed in as arugment to count up the main and secodnary sum diagonal
		sum_diagonal(matrices.first);
		//Break statement to get of switch case statement
		break;
	}
	//If choice case is integer 5, Choice 5 is executed for a given matrix to swap row values, and be printed to terminal
	case 5:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter Single nxn Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//Declares is_valid to the result of file check with 2 as matrix preoducd, and matrix numbers text file name passed in
		bool is_valid = file_check(1,matrix_numbers_text_file_name);
		//If is valid is 0, it invalid
		if(is_valid == 0){
			//Prints to terminal that is invalid
		    cout<<"Invalid"<<"\n";
			//Breaks out of case switch statement
		    break;
		}
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		//matrix stores result ouput of the executed function called create matrice with matrix numbers text filename passed in as argument
		//pair<Matrix,Matrix> matrices = create_matrice(matrix_numbers_text_file_name);
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

		//Checks to see if row1 and row2 is out of bounds
		if(row1-1 < 0 || row1-1 > matrices.first.get_number_of_rows() || row2-1 < 0 || row2-1 > matrices.first.get_number_of_rows() ){
			//Prints to terminal that the Row number is out of bounds
			cout<<"Row number is out of bounds"<< "\n";
			//Break out of switch case
			break;
		}
		
		else{
    		//Result matrix stores the updated matrix of result from the executed swap rows function with matrix,row1, and row2 passed in arguments, to swap the row valus
    		result_matrix = swap_rows(matrices.first,row1-1,row2-1);
    		//Result matrix object executes the print grid function
    		result_matrix.print_grid();
    		//Break statement to get out of switch case statement
    		break;
		}
	}
	//If choice case is integer 6, Choice 6 is executed for a given matrix to swap column values, and be printed to terminal
	case 6:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter Single nxn Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//Declares is_valid to the result of file check with 2 as matrix preoducd, and matrix numbers text file name passed in
		bool is_valid = file_check(1,matrix_numbers_text_file_name);
		//If is valid is 0, it invalid
		if(is_valid == 0){
			//Prints to terminal that is invalid
		    cout<<"Invalid"<<"\n";
			//Breaks out of case switch statement
		    break;
		}
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		//matrix stores result ouput of the executed function called create matrice with matrix numbers text filename passed in as argument
		//matrix = create_matrice(matrix_numbers_text_file_name);
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
		//If column1 and column2 are out of bound of the number of columns
		if(column1-1 < 0 || column1-1 > matrices.first.get_number_of_columns() || column2-1 < 0 || column2-1 >= matrices.first.get_number_of_columns() ){
			//Prints to termianl that the column is out of bounds
			cout<<"Column number is out of bounds"<<"\n";
			//Breaks out of switch statement
			break;
		}
		else{
			//Result matrix stores the updated matrix of result from the executed swap columns function with matrix,column1, and column2 passed in arguments, to swap the column valus
			result_matrix = swap_columns(matrices.first,column1-1,column2-1);
			//Result matrix object executes the print grid function
			result_matrix.print_grid();
			//Break statement to get out of switch case statement
			break;
		}
	}
	//If choice case is integer 7, Choice 7 is executed for a given matrix to be given a updated value at the row by column location
	case 7:
	{
		//Prints ouput to terminal for the user to be prompted the Matrix Numbers Text File name
		cout<<"Enter Single nxn Matrix Numbers Text File Name: ";
		//Stores the user input into matrix numbers text file name
		cin >> matrix_numbers_text_file_name;
		//Declares is_valid to the result of file check with 2 as matrix preoducd, and matrix numbers text file name passed in
		bool is_valid = file_check(1,matrix_numbers_text_file_name);
		//If is valid is 0, it invalid
		if(is_valid == 0){
			//Prints to terminal that is invalid
		    cout<<"Invalid"<<"\n";
			//Breaks out of case switch statement
		    break;
		}
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		//matrix stores result ouput of the executed function called create matrice with matrix numbers text filename passed in as argument
		//matrix = create_matrices(matrix_numbers_text_file_name);
		//Declares integer column
		int column1;
		//Declares integer row
		int row1;
		//Declares integer value
		int value;
		//Prints ouput to terminal to prompt the user for a row number
		cout<<"Enter Row Number: ";
		//Stores user input into row
		cin>>row1;
		//Prints ouput to terminal to prompt the user for a column number
		cout<<"Enter Column Number: ";
		//Stores user input into column
		cin>>column1;
		//Prints ouput to terminal to prompt the user for a value to be stored in the matrix at location row by column
		cout<<"Enter Value to be stores: ";
		//Stores the user input into value
		cin>>value;

		//Checks to see if the column is out of bounds
		if(column1-1 < 0 || column1-1 >= matrices.first.get_number_of_columns() ){
			//Prints to the terminal that the column number is out of bounds
			cout<<"Column number is out of bounds" << "\n";
			//Breaks out of swicth statement
			break;
		}
		//Checks to see if the row is out of bounds
		if(row1-1 < 0 || row1-1 >= matrices.first.get_number_of_rows() ){
			//Prints to the terminal that the column number is out of bounds
			cout<<"Row number is out of bounds" << "\n";
			//Breaks out of swicth statement
			break;
		}
		
		//If value is valid and is a real number
		if(value >=0 && value <= 0){
		    //Prints to terminal that the value is not a real number
		    cout<<"Value needs to be a real number"<<"\n";
		    //Breaks out of swicth statement
		    break;
		}
		
		
		else{
			//Result matrix stores the updated matrix result from the update matrix function with matrix,row,column, and value input. The matrix is updated with the value stored in the grid at row by cloumn location
			result_matrix = update_matrix(matrices.first,row1-1,column1-1,value);
			//Result matrix object executes the print grid function
			result_matrix.print_grid();
			//Break statement to get out of switch case statement
			break;
		}
	}
	//In case if all cases fail, default case is executed
	default:
	{
		//Prints output to terminal that there choice is invalid
		cout<<"Invalid Choice" << "\n";
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
	//Prints output to terminal that the program has ended
	cout<<"Progam has ended...Goodbye";
	//Returns 0 to indicate to the user that program has ended without issue
	return 0;
}