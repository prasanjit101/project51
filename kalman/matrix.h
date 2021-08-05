#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Matrix{
    private:
        vector<vector<T>> arr;

    protected:
        int row;
        int column;

    public:
        Matrix<T>(int , int,vector<vector<T> > const &v );//object(rows,columns,matrix) -> for 2d matrix
        Matrix<T>(int,vector<vector<T> > const &v); //object(columns,matrix) -> for 1d matrix
        Matrix<T>(int,int);   //to declare a matrix of mxn order where m is 1st argument and n is 2nd argument    
        Matrix<T>();

        inline int getRow() const; //returns number of rows
        inline int getColumn() const;//returns number of columns

        Matrix<T> add(const Matrix<T>& m) const;
        Matrix<T> subtract(const Matrix<T>& m) const;
        Matrix<T> multiply(const Matrix<T>& m) const;
        Matrix<T> dot(const Matrix<T>& m) const;
        Matrix<T> transpose() const;
        Matrix<T> multiply(const T& value) const;
        Matrix<T> applyFunction(T (*function)(T)) const;

        void fill(const T& value);
        void insert(int h, int w, const T& value);
        T get(int h, int w) const;

        void print(ostream &flux) const;

        bool operator==(const Matrix<T>& m);
        bool operator!=(const Matrix<T>& m);
        Matrix<T> operator+=(const Matrix<T>& m);
        Matrix<T> operator-=(const Matrix<T>& m);
        Matrix<T> operator*=(const Matrix<T>& m);
        Matrix<T> operator*=(const T &m);
        T& operator()(int y, int x);
};

template <typename T> Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b);
template <typename T> Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b);
template <typename T> Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b);
template <typename T> Matrix<T> operator*(const T &b, const Matrix<T>& a);
template <typename T> ostream& operator<<(ostream &flux, const Matrix<T>& m);

#endif

