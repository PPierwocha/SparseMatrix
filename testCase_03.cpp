#include "Sparse.h"
#include "Sparse.cpp"
#include <iostream>




int main()
{
    std::vector<double> vec_1{1, 2.0, 3.0};
    std::vector<double> vec_2 = vec_1;
    
    Sparse<double> sparse_matrix_1(5);
    Sparse<double> sparse_matrix_2(5);
    Sparse<double> sparse_matrix_3(5);
    Sparse<double> sparse_matrix_4(5);
    //////////////////////////////////////
    //First matrix

    

    sparse_matrix_1.setRow(0, 0, 1);    sparse_matrix_1.setRow(0, 1, 1);
    sparse_matrix_1.setRow(1, 0, -1);    sparse_matrix_1.setRow(1, 2, 2);
    sparse_matrix_1.setRow(2, 0, 1);    sparse_matrix_1.setRow(2, 1, 3);    sparse_matrix_1.setRow(2, 4, 5);
    sparse_matrix_1.setRow(3, 3, 3);
    sparse_matrix_1.setRow(4, 2, 6);    sparse_matrix_1.setRow(4, 3, 2.5);

    // ////////////////////////////////////////
    // // Second matrix
    sparse_matrix_2.setRow(0, 1, 2);    sparse_matrix_2.setRow(0, 3, -1);
    sparse_matrix_2.setRow(1, 0, -1);    sparse_matrix_2.setRow(1, 1, 2);
    sparse_matrix_2.setRow(2, 0, 0.5);    sparse_matrix_2.setRow(2, 2, 2);    sparse_matrix_2.setRow(2, 3, 4.5);
    sparse_matrix_2.setRow(3, 0, 3);
    sparse_matrix_2.setRow(4, 1, 6);    sparse_matrix_2.setRow(4, 4, 2.5);


    //////////////////////////////////////////
    // // Addition

   sparse_matrix_3 = sparse_matrix_1 + sparse_matrix_2;
   sparse_matrix_4 = sparse_matrix_1 - sparse_matrix_2;

    //////////////////////////
    // Print sparse matrix
    std::cout << std::endl;
    std::cout << "First matrix:" << std::endl;
    sparse_matrix_1.printMatrix();

    std::cout << std::endl;
    std::cout << "Second matrix:" << std::endl;
    sparse_matrix_2.printMatrix();

    std::cout << std::endl;
    std::cout << "Addition:" << std::endl;
    sparse_matrix_3.printMatrix();
    
    std::cout << std::endl;
    std::cout << "Difference:" << std::endl;
    sparse_matrix_4.printMatrix();

    return 0;
}