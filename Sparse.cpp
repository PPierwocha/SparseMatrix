#pragma once
#include "Sparse.h"

template <typename T>
std::vector<T> Sparse<T>::operator*(std::vector<T> const& vec)
{

            bool condition = col_num_ != vec.size();
            std::vector<T> output;
            std::vector<int> columnTmp;
            std::vector<T> valuesTmp;

            if(condition)
                throw std::range_error(errMsgWrongVecSize);

            
            for(int i = 0; i < row_num_; i++)
            {
                columnTmp = sparse_[i].columns;
                valuesTmp = sparse_[i].values;

                output.push_back(0);
                
                for(int j=0; j<columnTmp.size(); j++)
                    output[i] += valuesTmp[j]*vec[columnTmp[j]];

            }
    return output;
};

template <typename T>
Sparse<T> Sparse<T>::operator+ (Sparse<T> const& matrix)
{
    Sparse<T> output(row_num_, col_num_);
    int size_1, size_2;
    int iter_1, iter_2;
    bool columns_condition = true;
    bool continue_flag_1, continue_flag_2;


    if(row_num_ != matrix.row_num_)
        throw std::range_error(std::string("Different row numbers !"));
    

    if(col_num_ != matrix.col_num_)
        throw std::range_error(std::string("Different columns numbers !"));

    for(int row_ind = 0; row_ind < row_num_; row_ind++)
    {
        size_1 = sparse_[row_ind].columns.size();
        size_2 = matrix.sparse_[row_ind].columns.size();
        iter_1 = 0;
        iter_2 = 0;

        continue_flag_1 = true;
        continue_flag_2 = true;

        columns_condition = (iter_1 < size_1) && (iter_2 < size_2);

        while(columns_condition)
        {
            columns_condition = !( (iter_1 == (size_1 - 1)) && (iter_2 == (size_2 - 1)) );

            if(sparse_[row_ind].columns[iter_1] == matrix.sparse_[row_ind].columns[iter_2])
            {
                output.setRow(row_ind, sparse_[row_ind].columns[iter_1], sparse_[row_ind].values[iter_1] + matrix.sparse_[row_ind].values[iter_2]);
                
                if(iter_1 == (size_1 - 1))
                    continue_flag_1 = false;

                if(iter_1 != (size_1 - 1))
                    iter_1++;

                if(iter_2 == (size_2 - 1))
                    continue_flag_2 = false;
                
                if(iter_2 != (size_2 - 1))
                    iter_2++;
            }
            else if( (sparse_[row_ind].columns[iter_1] < matrix.sparse_[row_ind].columns[iter_2]) && continue_flag_1 )
            {
                output.setRow(row_ind, sparse_[row_ind].columns[iter_1], sparse_[row_ind].values[iter_1]);

                if(iter_1 == (size_1 - 1))
                    continue_flag_1 = false;
                
                if(iter_1 != (size_1 - 1))
                    iter_1++;
                
                
            }
            else if( (sparse_[row_ind].columns[iter_1] > matrix.sparse_[row_ind].columns[iter_2]) && continue_flag_2)
            {
                output.setRow(row_ind, matrix.sparse_[row_ind].columns[iter_2], matrix.sparse_[row_ind].values[iter_2]);

                if(iter_2 == (size_2 - 1))
                    continue_flag_2 = false;

                if(iter_2 != (size_2 - 1))
                    iter_2++;
                
                
            }
            
            
            if(!continue_flag_1 && continue_flag_2)
                {
                    output.setRow(row_ind, matrix.sparse_[row_ind].columns[iter_2], matrix.sparse_[row_ind].values[iter_2]);

                    if(iter_2 == (size_2 - 1))
                        continue_flag_2 = false;

                    if(iter_2 != (size_2 - 1))
                        iter_2++;
                }

            
            

            if(!continue_flag_2 && continue_flag_1)
                {
                    output.setRow(row_ind, sparse_[row_ind].columns[iter_1], sparse_[row_ind].values[iter_1]);

                    if(iter_1 == (size_1 - 1))
                        continue_flag_1 = false;
                    
                    if(iter_1 != (size_1 - 1))
                        iter_1++;
                }

        }
    }


    return output;

}

template <typename T>
Sparse<T> Sparse<T>::operator- (Sparse<T> const& matrix)
{
    Sparse<T> output(row_num_, col_num_);
    int size_1, size_2;
    int iter_1, iter_2;
    bool columns_condition = true;
    bool continue_flag_1, continue_flag_2;


    if(row_num_ != matrix.row_num_)
        throw std::range_error(std::string("Different row numbers !"));
    

    if(col_num_ != matrix.col_num_)
        throw std::range_error(std::string("Different columns numbers !"));

    for(int row_ind = 0; row_ind < row_num_; row_ind++)
    {
        size_1 = sparse_[row_ind].columns.size();
        size_2 = matrix.sparse_[row_ind].columns.size();
        iter_1 = 0;
        iter_2 = 0;

        continue_flag_1 = true;
        continue_flag_2 = true;

        columns_condition = (iter_1 < size_1) && (iter_2 < size_2);

        while(columns_condition)
        {
            columns_condition = !( (iter_1 == (size_1 - 1)) && (iter_2 == (size_2 - 1)) );

            if(sparse_[row_ind].columns[iter_1] == matrix.sparse_[row_ind].columns[iter_2])
            {
                output.setRow(row_ind, sparse_[row_ind].columns[iter_1], sparse_[row_ind].values[iter_1] - matrix.sparse_[row_ind].values[iter_2]);
                
                if(iter_1 == (size_1 - 1))
                    continue_flag_1 = false;

                if(iter_1 != (size_1 - 1))
                    iter_1++;

                if(iter_2 == (size_2 - 1))
                    continue_flag_2 = false;
                
                if(iter_2 != (size_2 - 1))
                    iter_2++;
            }
            else if( (sparse_[row_ind].columns[iter_1] < matrix.sparse_[row_ind].columns[iter_2]) && continue_flag_1 )
            {
                output.setRow(row_ind, sparse_[row_ind].columns[iter_1], sparse_[row_ind].values[iter_1]);

                if(iter_1 == (size_1 - 1))
                    continue_flag_1 = false;
                
                if(iter_1 != (size_1 - 1))
                    iter_1++;
                
                
            }
            else if( (sparse_[row_ind].columns[iter_1] > matrix.sparse_[row_ind].columns[iter_2]) && continue_flag_2)
            {
                output.setRow(row_ind, matrix.sparse_[row_ind].columns[iter_2], - matrix.sparse_[row_ind].values[iter_2]);

                if(iter_2 == (size_2 - 1))
                    continue_flag_2 = false;

                if(iter_2 != (size_2 - 1))
                    iter_2++;
                
                
            }
            
            
            if(!continue_flag_1 && continue_flag_2)
                {
                    output.setRow(row_ind, matrix.sparse_[row_ind].columns[iter_2], - matrix.sparse_[row_ind].values[iter_2]);

                    if(iter_2 == (size_2 - 1))
                        continue_flag_2 = false;

                    if(iter_2 != (size_2 - 1))
                        iter_2++;
                }

            
            

            if(!continue_flag_2 && continue_flag_1)
                {
                    output.setRow(row_ind, sparse_[row_ind].columns[iter_1], sparse_[row_ind].values[iter_1]);

                    if(iter_1 == (size_1 - 1))
                        continue_flag_1 = false;
                    
                    if(iter_1 != (size_1 - 1))
                        iter_1++;
                }

        }
    }


    return output;

}

template <typename T>
Sparse<T>& Sparse<T>::operator= (const Sparse<T>& other)
{
    sparse_ = other.sparse_;
    row_num_ = other.row_num_;
    col_num_ = other.col_num_;

    return *this;
}

template <typename T>
void Sparse<T>::setRow(int row_ind, const std::vector<int> columns_inds, std::vector<T> const& values)
{
    for(int i = 0; i < columns_inds.size(); i++)
    {
        if(columns_inds[i] > (col_num_ - 1))
            col_num_ = columns_inds[i] + 1;
    }

    if(row_ind > (row_num_ - 1))
    {
        row_num_ = row_ind + 1;
        sparse_.resize(row_num_);
    }

    (sparse_[row_ind].values) = values;
    (sparse_[row_ind].columns) = columns_inds;
}

template <typename T>
void Sparse<T>::setRow(int row_ind, int col_ind, T const& value)
{
    if(col_ind > (col_num_ - 1))
        col_num_ = col_ind + 1;

    if(row_ind > (row_num_ - 1))
    {
        row_num_ = row_ind + 1;
        sparse_.resize(row_num_);
    }

    sparse_[row_ind].values.push_back(value);
    sparse_[row_ind].columns.push_back(col_ind);
}


template <typename T>
void Sparse<T>::printMatrix()
{
    bool is_present;
    int col_ind_sp = 0;
    std::vector<int>::iterator ptr;

    for(int row_ind = 0; row_ind < row_num_; row_ind++)
    {
        for(int col_ind = 0; col_ind < col_num_; col_ind++)
        {
            ptr = std::find(sparse_[row_ind].columns.begin(), sparse_[row_ind].columns.end(), col_ind);
            
            is_present = ptr != sparse_[row_ind].columns.end();
            
            if(is_present)
            {
                
                std::cout << sparse_[row_ind].values[col_ind_sp] << "\t";
                col_ind_sp++;
            }
            else
                std::cout << "0\t";
            
        }
        col_ind_sp = 0;
        std::cout << std::endl;
    }

}

