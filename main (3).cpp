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
	    cout<< "Column ";
	    for(int column = 0; column < number_of_columns+1; column++){
	        cout<< column << " ";
	    }
	    cout<<"\n";
		for(int row= 0; row<number_of_rows; row++) {
	        cout<< "Row "<<row << " ";
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
		myfile.close();
		return {matrix1,matrix2};
	}
}
Matrix create_matrice(string matrix_text_file) {
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
		return matrix1;
	}
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
		for(int column = 0; column < matrix_1.number_of_columns; column) {
			for(int colu = 0; colu < matrix_2.number_of_columns; colu) {
				int value = matrix_1.grid[row][colu] * matrix_2.grid[colu][row];
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

	Matrix result_matrix_1{matrix_1.number_of_rows,matrix_1.number_of_columns};

	for(int row = 0; row < matrix_1.number_of_rows; row++) {
		matrix_1_result_main_sum+= matrix_1.grid[row][d];
		d++;
	}
	for(int row = matrix_1.number_of_rows; row > 0; row--) {
		matrix_1_result_secondary_sum+= matrix_1.grid[row][d];
		d--;
	}

	cout<< matrix_1_result_main_sum << "\n";
	cout<< matrix_1_result_secondary_sum << "\n";


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
			result_matrix.store_value(column_num_1,row,value);
		}
		for(int row = 0; row< matrix_1.number_of_rows; row++) {
			int value = matrix_1.grid[row][column_num_1];
			result_matrix.store_value(column_num_2,row,value);
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
	Matrix result(0,0);
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

	case 3:
	{
		cout<<"Enter Matrix Numbers Text File Name: ";
		cin >> matrix_numbers_text_file_name;
		pair<Matrix,Matrix> matrices = create_matrices(matrix_numbers_text_file_name);
		matrix1 = matrices.first;
		matrix2 = matrices.second;
		result = multiply_matrices(matrix1,matrix2);
		break;
	}
	case 4:
	{
		cout<<"Enter Matrix Numbers Text File Name: ";
		matrix = create_matrice(matrix_numbers_text_file_name);
		sum_diagonal(matrix);
		break;
	}
	case 5:
	{
		cout<<"Enter Matrix Numbers Text File Name: ";
		matrix = create_matrice(matrix_numbers_text_file_name);
		sum_diagonal(matrix);
		break;
	}
	case 6:
	{
		cout<<"Enter Matrix Numbers Text File Name: ";
		matrix = create_matrice(matrix_numbers_text_file_name);
		sum_diagonal(matrix);
		break;
	}
	case 7:
	{
		cout<<"Enter Matrix Numbers Text File Name: ";
		cin >> matrix_numbers_text_file_name;
		break;
	}

	}

}
int main()
{
	cout<<"Hello Welcome to Matrix Operations and ETC." << "\n";
	choice_selection();
	return 0;
}