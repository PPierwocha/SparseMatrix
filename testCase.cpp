#include "Sparse.h"
#include "Sparse.cpp"
//#include <iostream>




int main()
{
    std::vector<double> vec_1{1.0, 2.0, 3.0};
    std:: vector<double> vec_2;


    
    Sparse sparseMatrix(3);

    std::vector<double> rowVal_1{1.0, -1.0};
    std::vector<int> rowCol_1{0, 1};

    
    sparseMatrix.setRow(0, rowVal_1, rowCol_1);

    std::vector<double> rowVal_2{-1.0, 1.0};
    std::vector<int> rowCol_2{1, 2};

    sparseMatrix.setRow(1, rowVal_2, rowCol_2);

    

    sparseMatrix.setRow(2, 1.0, 2);

    

    vec_2 = sparseMatrix*vec_1;
    
    for(int i = 0; i < vec_2.size(); i++)
    {
        std::cout<<vec_2[i]<<std::endl;
    }

    
    
    return 0;
}