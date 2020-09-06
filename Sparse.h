#pragma once
#include <iostream>
#include <vector>
#include "SparseRow.h"



// template<class T>
class Sparse
{
    private:
        // std::vector<SparseRow<T>> sparse_;
        std::vector<SparseRow<double>> sparse_;
        int sparseSize_;

    public:

        Sparse();

        Sparse(int sparseSize){
            sparse_.resize(sparseSize);
            sparseSize_ = sparseSize;
            
        }

        ~Sparse(){};

        // std::vector<T> operator * (const std::vector<T> & vec);

        
        // void setRow(int rowNum, const std::vector<T> valuesTmp, const std::vector<int> columnsTmp);
        void setRow(int rowNum, std::vector<double> valuesTmp, std::vector<int> columnsTmp);

        // void setRow(int rowNum, T valueTmp, int columnTmp);

};