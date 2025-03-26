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
using namespace std;

int main()
{
    string matrix_numbers_text_file_name;
    int size_of_matrix;
    cout<<"Hello Welcome to Matrix Operations and ETC." << "\n";
    cout<<"Enter Matrix Numbers Text File Name: ";
    cin >> matrix_numbers_text_file_name;
    
    
    string line;
    int m = 2;
    ifstream myfile(matrix_numbers_text_file_name);
    if (myfile.is_open()){
        while (getline(myfile,line)){
            for(int i = 0; i < line.size(); i++){
                
                if(i == m){
                    cout << "e";
                    m+=3;
                }
                else if(i < 3){
                    cout << line[i];
                }
                else{
                    cout << line[i];
                }
            }
            m= 2;
            
            cout << "\n";
          
            
        }
        myfile.close();
    }
    
    
    
    


    return 0;
}