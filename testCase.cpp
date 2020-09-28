#include "Sparse.h"
#include "Sparse.cpp"
#include <iostream>




int main()
{
    std::vector<double> vec_1{1.0, 2.0, 3.0};
    std:: vector<double> vec_2;


    
    Sparse<double> sparseMatrix(3);

    //////////////////////////////////////
    //Setting first row

    std::vector<double> rowVal_1{1, -1};
    std::vector<int> rowCol_1{0, 1};

    sparseMatrix.setRow(0, rowVal_1, rowCol_1);
    std::cout <<  "First row set. Vector insertion - Test passed" << std::endl;

    ///////////////////////////////////////
    //Setting second row

    std::vector<double> rowVal_2{-1.0, 1.0};
    std::vector<int> rowCol_2{1, 2};

    sparseMatrix.setRow(1, rowVal_2, rowCol_2);
    std::cout <<  "Second row set. Vector insertion - Test passed" << std::endl;

    // ////////////////////////////////////////
    // // Setting third row - inserting single number    

    sparseMatrix.setRow(2, 1.0, 2);
    std::cout <<  "Third row set. Single number insertion - Test passed" << std::endl;
    
    // ////////////////////////////////////
    // // Matrix vector multiplication

    vec_2 = sparseMatrix*vec_1;
    std::cout << "Matrix vector multiplication works - Test passed" << std::endl;

    for(int i = 0; i < vec_2.size(); i++)
    {
        std::cout<<vec_2[i]<<std::endl;
    }

    
    
    return 0;
}