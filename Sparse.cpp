#pragma once
#include "Sparse.h"

template <typename T>
std::vector<T> Sparse<T>::operator*(std::vector<T> const& vec)
{

            bool condition = sparseSize_ != vec.size();
            std::vector<T> output;
            std::vector<int> columnTmp;
            std::vector<T> valuesTmp;

            if(condition)
            {
                std::cout<<"Wrong vector size !"<< std::endl;
                
                return output;
            }

            
            for(int i = 0; i < sparseSize_; i++)
            {
                columnTmp = sparse_[i].columns;
                valuesTmp = sparse_[i].values;

                output.push_back(0);
                
                for(int j=0; j<columnTmp.size(); j++)
                {
                    output[i] += valuesTmp[j]*vec[columnTmp[j]];
                    
                }

                

            }
    return output;
};

template <typename T>
void Sparse<T>::setRow(int rowNum, std::vector<T> const& valuesTmp, const std::vector<int> columnsTmp)
{
    (sparse_[rowNum].values) = valuesTmp;
    (sparse_[rowNum].columns) = columnsTmp;
}

template <typename T>
void Sparse<T>::setRow(int rowNum, T const& valueTmp, int columnTmp)
{
    sparse_[rowNum].values.push_back(valueTmp);
    sparse_[rowNum].columns.push_back(columnTmp);
}


template <typename T>
void Sparse<T>::printMatrix()
{
    bool is_present;
    int col_ind_sp = 0;

    for(int row_ind = 0; row_ind < sparseSize_; row_ind++)
    {
        for(int col_ind = 0; col_ind < sparseSize_; col_ind++)
        {
            is_present = std::find(sparse_[row_ind].columns.begin(), sparse_[row_ind].columns.end(), col_ind) != sparse_[row_ind].columns.end();
            
            if(is_present)
            {
                std::cout << sparse_[row_ind].values[col_ind_sp] << "\t";
                col_ind_sp++;
            }
            else
            {
                std::cout << "0\t";
            }
            
        }
        col_ind_sp = 0;
        std::cout << std::endl;
    }

}

