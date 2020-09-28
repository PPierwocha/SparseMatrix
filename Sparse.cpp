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