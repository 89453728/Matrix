/*
matrix.h

Copyright (C) 2020-2021 Yassin Achengli <0619883460@uma.es>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, see
<https://www.gnu.org/licenses/>.

======================================================================
*/

#ifndef MATRIX_F
#define MATRIX_F
#include "cmplx.h"
#include <string>
#include <ostream>

typedef unsigned int idx_type;

namespace ff {
    template<class T>
    class Matrix {
        private: 
            idx_type size[2];
            T** data;
        public: 
            Matrix();
            Matrix(const idx_type &rows, const idx_type &cols);
            Matrix(const Matrix &o);
            
            Matrix operator+(const Matrix &o)const;
            Matrix operator-(const Matrix &o)const;
            Matrix operator*(const Matrix &o)const;
            Matrix operator*(const T &o)const;
            Matrix operator/(const T &o)const;
            Matrix operator=(const Matrix &o);
            Matrix operator+=(const Matrix &o);
            Matrix operator-=(const Matrix &o);
            Matrix operator*=(const Matrix &o);
            Matrix operator*=(const T &o);
            Matrix operator/=(const T &o);
            bool operator==(const Matrix &o)const;
            bool operator!=(const Matrix &o)const;
            bool operator>(const Matrix &o)const;
            bool operator>=(const Matrix &o)const;
            bool operator<(const Matrix &o)const;
            bool operator<=(const Matrix &o)const;

            T& operator()(const idx_type &row, const idx_type &col);
            T operator[](const idx_type &row, const idx_type &col)const;
            
            T elem(const idx_type &row,const idx_type &col);
            T numel(const idx_type &row,const idx_type &col);
            idx_type rows()const;
            idx_type cols()const;
            
            std::string toString()const;

            friend std::ostream& operator<<(const std::ostream &out, const Matrix &o);
            friend Matrix operator*(const Matrix &o,const T d);
    };
}

ff::Matrix::Matrix(){
    size[0]=0;
    size[1]=0;
}
ff::Matrix::Matrix(const idx_type &rows, const idx_type &cols){
    size[0]=rows;
    size[1]=cols;
    data = new T*[rows];
    for(idx_type i=0;i<rows;i++){
        data[i] = new T[cols];
    }
}
ff::Matrix::Matrix(const ff::Matrix &o){
    size[0] = o.rows();
    size[1] = o.cols();
    data = new T*[o.rows()];
    for(idx_type i=0;i<rows;i++){
        data[i]=new T[o.cols()];
    }
    for(idx_type=0;i<size[0];i++){
        for(idx_type=0;i<size[1];i++){
            data[i][j] = o.
        }
    }
}


#endif
