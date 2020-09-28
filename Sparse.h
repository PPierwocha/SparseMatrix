#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "SparseRow.h"



template <typename T>
class Sparse
{
    private:
        std::vector<SparseRow<T>> sparse_;
        int sparseSize_;

    public:

        Sparse();

        Sparse(int sparseSize){
            sparse_.resize(sparseSize);
            sparseSize_ = sparseSize;
            
        }

        ~Sparse(){};

        std::vector<T> operator * (std::vector<T> const& vec);

        void setRow(int rowNum, std::vector<T> const& valuesTmp, const std::vector<int> columnsTmp);


        void setRow(int rowNum, T const& valueTmp, int columnTmp);


        void printMatrix();

};