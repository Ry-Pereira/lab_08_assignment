/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string matrix_numbers_text_file_name;
    int size_of_matrix;
    cout<<"Hello Welcome to Matrix Operations and ETC." << "\n";
    cout<<"Enter Matrix Numbers Text File Name: ";
    cin >> matrix_numbers_text_file_name;
    
    
    string line;
    ifstream myfile(matrix_numbers_text_file_name);
    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line.empty()){
                cout << "EMpty" << "\n";
            }
            else{
                cout << line.size() << "\n";
                
            }
          
            
        }
        myfile.close();
    }
    
    
    
    


    return 0;
}