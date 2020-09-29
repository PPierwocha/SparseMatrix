#include "Sparse.h"
#include "Sparse.cpp"
#include <iostream>




int main()
{
    std::vector<double> vec_1{1, 2.0, 3.0};
    std::vector<double> vec_2;


    
    Sparse<double> sparse_matrix(3);

    //////////////////////////////////////
    //Setting first row

    std::vector<double> rowVal_1{1, -1};
    std::vector<int> rowCol_1{0, 1};

    sparse_matrix.setRow(0, rowCol_1, rowVal_1);
    std::cout <<  "First row set. Vector insertion - Test passed" << std::endl;

    ///////////////////////////////////////
    //Setting second row

    std::vector<double> rowVal_2{-1.0, 1.0};
    std::vector<int> rowCol_2{1, 2};

    sparse_matrix.setRow(1, rowCol_2, rowVal_2);
    std::cout <<  "Second row set. Vector insertion - Test passed" << std::endl;

    // ////////////////////////////////////////
    // // Setting third row - inserting single number    

    sparse_matrix.setRow(2, 2, 1.0);
    std::cout <<  "Third row set. Single number insertion - Test passed" << std::endl;

    // ////////////////////////////////////////
    // // Setting fourth row - inserting single number    
    sparse_matrix.setRow(3, 0, 1);
    std::cout <<  "Fourth row set (matrix resizing to 4 rows). Single number insertion - Test passed" << std::endl;

    // ////////////////////////////////////
    // // Matrix vector multiplication

    vec_2 = sparse_matrix*vec_1;
    std::cout << "Matrix vector multiplication works - Test passed" << std::endl;
    
    std::cout << std::endl;
    for(int i = 0; i < vec_2.size(); i++)
    {
        std::cout<<vec_2[i]<<std::endl;
    }

    //////////////////////////
    // Print sparse matrix
    std::cout << std::endl;
    sparse_matrix.printMatrix();

    
    
    return 0;
}