#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

template <class T>
class Matrix
{
private:
    vector<vector<T>> array;
    int row;
    int col;

public:
    Matrix<T>(int row, int col);
    Matrix<T>(vector<vector<T>> const &array);
    Matrix<T>();

    int getRow() const;
    int getCol() const;

    Matrix<T> add(const Matrix<T> &m) const;      //add two matrix
    Matrix<T> subtract(const Matrix<T> &m) const; //subtract one matrix from another
    Matrix<T> multiply(const Matrix<T> &m) const; //multiply two matrix
    Matrix<T> dot(const Matrix<T> &m) const;      //dot product of two matrix
    Matrix<T> transpose() const;                  //transpose a matrix
    Matrix<T> multiply(const T &value) const;     //multiply values
    Matrix<T> divide(const T &value) const;       //divide values

    Matrix<T> getCofactor(int x, int y) const;
    double getDeterminant() const;
    Matrix<T> adjMatrix() const;
    Matrix<T> inverseMatrix() const;

    Matrix<T> applyFunction(T (*function)(T)) const; //apply function to elements

    void fill(const T &value);              //fill matrix with a particular value
    void put(int h, int w, const T &value); //put the value in a specified index
    T get(int h, int w) const;              //get the value of a specified index

    void print(ostream &flux) const;

    bool operator==(const Matrix<T> &m);
    bool operator!=(const Matrix<T> &m);
    Matrix<T> operator+=(const Matrix<T> &m);
    Matrix<T> operator-=(const Matrix<T> &m);
    Matrix<T> operator*=(const Matrix<T> &m);
    Matrix<T> operator*=(const T &m);
    Matrix<T> operator/=(const T &m);
    T &operator()(int y, int x);
};

template <class T>
Matrix<T> operator+(const Matrix<T> &a, const Matrix<T> &b);
template <class T>
Matrix<T> operator-(const Matrix<T> &a, const Matrix<T> &b);
template <class T>
Matrix<T> operator*(const Matrix<T> &a, const Matrix<T> &b);
template <class T>
Matrix<T> operator*(const T &b, const Matrix<T> &a);
template <class T>
Matrix<T> operator/(const Matrix<T> &a, const T &b);
template <class T>
ostream &operator<<(ostream &flux, const Matrix<T> &m);

#endif

template <class T>
Matrix<T>::Matrix(int row, int col)
{
    this->row = row;
    this->col = col;
    this->array = vector<vector<T>>(row, vector<T>(col));
}

template <class T>
Matrix<T>::Matrix(vector<vector<T>> const &array)
{
    if (array.size() == 0)
        throw invalid_argument("Size of array must be greater than 0.");

    this->row = array.size();
    this->col = array[0].size();
    this->array = array;
}

template <class T>
Matrix<T>::Matrix()
{
    row = 0;
    col = 0;
}

template <class T>
int Matrix<T>::getRow() const
{
    return row;
}

template <class T>
int Matrix<T>::getCol() const
{
    return col;
}

template <class T>
void Matrix<T>::fill(const T &value)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] = value;
        }
    }
}

template <class T>
void Matrix<T>::put(int h, int w, const T &value)
{
    if (!(h >= 0 && h < row && w >= 0 && w < col))
        throw invalid_argument("Index out of bounds.");

    array[h][w] = value;
}

template <class T>
T Matrix<T>::get(int h, int w) const
{
    if (!(h >= 0 && h < row && w >= 0 && w < col))
        throw invalid_argument("Index out of bounds.");

    return array[h][w];
}

template <class T>
Matrix<T> Matrix<T>::multiply(const T &value) const
{
    Matrix ans(array);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans.array[i][j] *= value;
        }
    }

    return ans;
}

template <class T>
Matrix<T> Matrix<T>::divide(const T &value) const
{
    Matrix ans(array);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans.array[i][j] /= value;
        }
    }

    return ans;
}

template <class T>
Matrix<T> Matrix<T>::add(const Matrix &m) const
{
    if (!(row == m.row && col == m.col))
        throw invalid_argument("Matrix dimension must be the same.");

    Matrix ans(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans.array[i][j] = array[i][j] + m.array[i][j];
        }
    }

    return ans;
}

template <class T>
Matrix<T> Matrix<T>::subtract(const Matrix &m) const
{
    if (!(row == m.row && col == m.col))
        throw invalid_argument("Matrix dimension must be the same.");

    Matrix ans(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans.array[i][j] = array[i][j] - m.array[i][j];
        }
    }
    return ans;
}

template <class T>
Matrix<T> Matrix<T>::dot(const Matrix &m) const
{
    if (!(row == m.row && col == m.col))
        throw invalid_argument("Matrix dimension must be the same.");

    Matrix ans(row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans.array[i][j] = array[i][j] * m.array[i][j];
        }
    }
    return ans;
}

template <class T>
Matrix<T> Matrix<T>::multiply(const Matrix &m) const
{
    if (!(col == m.row))
        throw invalid_argument("Dot product not compatible.");

    T w = 0;
    int mwidth = m.col;

    Matrix<T> ans(row, mwidth);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < mwidth; j++)
        {
            for (int h = 0; h < col; h++)
            {
                w += array[i][h] * m.array[h][j];
            }
            ans.array[i][j] = w;
            w = 0;
        }
    }

    return ans;
}

template <class T>
Matrix<T> Matrix<T>::transpose() const
{
    Matrix<T> ans(col, row);

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            ans.array[i][j] = array[j][i];
        }
    }
    return ans;
}

template <class T>
Matrix<T> Matrix<T>::applyFunction(T (*function)(T)) const
{
    Matrix<T> ans(row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans.array[i][j] = (*function)(array[i][j]);
        }
    }

    return ans;
}

template <class T>
void Matrix<T>::print(ostream &flux) const
{
    int maxLength[col] = {};
    stringstream ss;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ss << array[i][j];
            if (maxLength[j] < ss.str().size())
            {
                maxLength[j] = ss.str().size();
            }
            ss.str(string());
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            flux << array[i][j];
            ss << array[i][j];
            for (int k = 0; k < maxLength[j] - ss.str().size() + 1; k++)
            {
                flux << " ";
            }
            ss.str(string());
        }
        flux << endl;
    }
}

template <class T>
bool Matrix<T>::operator==(const Matrix &m)
{
    if (row == m.row && col == m.col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (array[i][j] != m.array[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix &m)
{
    return !operator==(m);
}

template <class T>
Matrix<T> Matrix<T>::operator+=(const Matrix &m)
{
    this->array = add(m).array;
    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator-=(const Matrix &m)
{
    this->array = subtract(m).array;
    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator*=(const Matrix &m)
{
    this->array = multiply(m).array;
    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator*=(const T &m)
{
    *this = this->multiply(m);
    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator/=(const T &m)
{
    *this = this->divide(m);
    return *this;
}

template <class T>
T &Matrix<T>::operator()(int y, int x)
{
    if (!(y >= 0 && y < row && x >= 0 && x < col))
        throw invalid_argument("Index out of bounds.");
    return array[y][x];
}

template <class T>
Matrix<T> operator+(const Matrix<T> &a, const Matrix<T> &b)
{
    return a.add(b);
}

template <class T>
Matrix<T> operator-(const Matrix<T> &a, const Matrix<T> &b)
{
    return a.subtract(b);
}

template <class T>
Matrix<T> operator*(const Matrix<T> &a, const Matrix<T> &b)
{
    return a.multiply(b);
}

template <class T>
Matrix<T> operator*(const T &b, const Matrix<T> &a)
{
    return a.multiply(b);
}
template <class T>
Matrix<T> operator/(const Matrix<T> &a, const T &b)
{
    return a.divide(b);
}

template <class T>
ostream &operator<<(ostream &flux, const Matrix<T> &m)
{
    m.print(flux);
    return flux;
}

// Get Cofactor of certain element
template <class T>
Matrix<T> Matrix<T>::getCofactor(int x, int y) const
{  // e is array to store the cofactor
   Matrix<T> e(row-1,col-1);

     int i=0,j=0;
     for(int iR=0;iR<row;iR++)
    {
        for(int iC=0;iC<col;iC++)
         {
                if (iR != x && iC != y)
                {
                    e.array[i][j++] = array[iR][iC];
                    if (j == col - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
         }
    }
    return e;
 }

//Function To get determinant of array using Cofactor
template <class T>
double Matrix<T>::getDeterminant() const
{
    double value = 0; // Initialize result
	if( col !=row)
		throw("Invalid array dimension");
   //  Base case : if array contains single element
    if (row == 1 && col==1)
        return array[0][0];
    // Matrix to store result
    Matrix<T> temp;
    // To store sign multiplier
    int sign = 1;
    // Iterate for each element of first row
	for(int iR=0;iR<row;iR++)
	{   temp=getCofactor(0,iR);
		value+= (sign * array[0][iR] )* (getCofactor(0, iR).getDeterminant());
		sign*=-1;
	}
	return value;
}

// To find Adjoint of Matrix
template <class T>
Matrix<T> Matrix<T>:: adjMatrix() const
{
        Matrix<T> adj(row,col);
        if (row == 1 && col==1)
        {
            adj.array[0][0] = 1;
            return adj;
        }
        int sign = -1;

        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                sign=((i+j)%2==0 ? 1:-1);
                adj.array[j][i] = sign*(getCofactor(i,j).getDeterminant());
                
            }
        }

       return adj;

}

// Function To find The Inverse Of Matrix
template <class T>
Matrix<T> Matrix<T>::inverseMatrix() const{
    double resultDeterminant=this->getDeterminant();
    if (resultDeterminant == 0)
    {
        cout << "Singular array, can't find its inverse";
    }

    Matrix<T> D=this->adjMatrix();
    D/=resultDeterminant;
	return D;

}
