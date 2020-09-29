#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "SparseRow.h"



template <typename T>
class Sparse
{
    private:
        std::vector<SparseRow<T>> sparse_;
        int row_num_, col_num_;

        std::string const errMsgOutOfCol = "Columns index out larger than horizontal size of matrix";
        std::string const errMsgWrongVecSize = "Wrong vector size";

    public:

        Sparse();

        Sparse(int sparse_size){
            sparse_.resize(sparse_size);
            row_num_ = sparse_size;
            col_num_ = sparse_size;
            
        }

        Sparse(int row_num, int col_num){
            sparse_.resize(row_num);
            row_num_ = row_num;
            col_num_ = col_num;
            
        }

        ~Sparse(){};

        std::vector<T> operator * (std::vector<T> const& vec);

        Sparse<T> operator+ (Sparse<T> const& matrix);

        void setRow(int rowNum, const std::vector<int> columnsTmp, std::vector<T> const& valuesTmp);


        void setRow(int row_ind, int col_ind, T const& value);


        void printMatrix();

};