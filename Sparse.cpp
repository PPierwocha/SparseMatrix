#pragma once
#include "Sparse.h"


std::vector<double> Sparse::operator*(const std::vector<double> & vec)
{

            bool condition = sparseSize_ != vec.size();
            std::vector<double> output;
            std::vector<int> columnTmp;
            std::vector<double> valuesTmp;

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


void Sparse::setRow(int rowNum, const std::vector<double> valuesTmp, const std::vector<int> columnsTmp)
{
    (sparse_[rowNum].values) = valuesTmp;
    (sparse_[rowNum].columns) = columnsTmp;
}


void Sparse::setRow(int rowNum, double valueTmp, int columnTmp)
{
    sparse_[rowNum].values.push_back(valueTmp);
    sparse_[rowNum].columns.push_back(columnTmp);
}