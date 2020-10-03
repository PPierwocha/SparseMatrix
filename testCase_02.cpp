#include "Sparse.h"
#include "Sparse.cpp"
#include <iostream>




int main()
{
    std::vector<double> vec_1{1, 2.0, 3.0};
    std::vector<double> vec_2 = vec_1;

    vec_2[0] = 5;

    std::cout << vec_1[0];
    
    Sparse<double> sparse_matrix_1(3);
    Sparse<double> sparse_matrix_2(3);
    Sparse<double> sparse_matrix_3(3);

    //////////////////////////////////////
    //First matrix

    std::vector<double> rowVal_1{1, -1};
    std::vector<int> rowCol_1{0, 1};

    sparse_matrix_1.setRow(0, rowCol_1, rowVal_1);

    std::vector<double> rowVal_2{-1.0, 1.0};
    std::vector<int> rowCol_2{1, 2};

    sparse_matrix_1.setRow(1, rowCol_2, rowVal_2);

    sparse_matrix_1.setRow(2, 2, 1.0);
    

    // ////////////////////////////////////////
    // // Second matrix
    rowVal_1 = {1, -1};
    rowCol_1 = {0, 2};

    sparse_matrix_2.setRow(0, rowCol_1, rowVal_1);

    rowVal_2 = {-1.0, 1.0};
    rowCol_2 = {1, 2};

    sparse_matrix_2.setRow(1, rowCol_2, rowVal_2);

    sparse_matrix_2.setRow(2, 0, 1.0);


    //////////////////////////////////////////
    // // Addition

   sparse_matrix_3 = sparse_matrix_1 + sparse_matrix_2;

    //////////////////////////
    // Print sparse matrix
    std::cout << std::endl;
    sparse_matrix_1.printMatrix();

    std::cout << std::endl;
    sparse_matrix_2.printMatrix();

    std::cout << std::endl;
    sparse_matrix_3.printMatrix();
    
    return 0;
}