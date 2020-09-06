#pragma once
#include <iostream>
#include <vector>
#include "SparseRow.h"




class Sparse
{
    private:
        std::vector<SparseRow<double>> sparse_;
        int sparseSize_;

    public:

        Sparse();

        Sparse(int sparseSize){
            sparse_.resize(sparseSize);
            sparseSize_ = sparseSize;
            
        }

        ~Sparse(){};

        std::vector<double> operator * (const std::vector<double> & vec);

        void setRow(int rowNum, const std::vector<double> valuesTmp, const std::vector<int> columnsTmp);


        void setRow(int rowNum, double valueTmp, int columnTmp);

};