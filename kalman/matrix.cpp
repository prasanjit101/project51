#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(int row, int column,vector<vector<T> > const &arr){
    this->row = arr.size();
    this->column = arr[0].size();
    this->arr = arr;
}

template <typename T>
Matrix<T>::Matrix(int column,vector<vector<T> > const &arr){
    this->row = 1;
    this->column = column;
    this->arr = arr;
}

template <typename T>
Matrix<T>::Matrix(int row,int column){
    this->row = row;
    this->column = column;
    this->arr = vector<vector<T> >(row, vector<T>(column));
}

template <typename T>
Matrix<T>::Matrix(){
    row = 0;
    column = 0;
}

template <typename T>
int Matrix<T>::getRow() const{
    return row;
}

template <typename T>
int Matrix<T>::getColumn() const{
    return column;
}

template <typename T>
void Matrix<T>::fill(const T& value){
    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<column ; j++){
            arr[i][j] = value;
        }
    }
}

template <typename T>
void Matrix<T>::insert(int h, int w, const T& value){
    if(!(h>=0 && h<row && w>=0 && w<column))
        throw invalid_argument("Index out of bounds.");

    arr[h][w] = value;
}

template <typename T>
T Matrix<T>::get(int h, int w) const{
    if(!(h>=0 && h<row && w>=0 && w<column))
        throw invalid_argument("Index out of bounds.");

    return arr[h][w];
}

template <typename T>
Matrix<T> Matrix<T>::multiply(const T& value) const{
    Matrix result(arr.size(),arr[0].size(),arr);
    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<column ; j++){
            result.arr[i][j] *= value;
        }
    }
    return result;
}


template <typename T>
Matrix<T> Matrix<T>::add(const Matrix& m) const{
    if(!(row==m.row && column==m.column))
        throw invalid_argument("Matrix dimension must be the same.");

    Matrix result(row, column);
    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<column ; j++){
            result.arr[i][j] = arr[i][j] + m.arr[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::subtract(const Matrix& m) const{
    if(!(row==m.row && column==m.column))
        throw invalid_argument("Matrix dimension must be the same.");

    Matrix result(row, column);
    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<column ; j++){
            result.arr[i][j] = arr[i][j] - m.arr[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::dot(const Matrix& m) const{
    if(!(row==m.row && column==m.column))
        throw invalid_argument("Dot product not compatible.");

    Matrix result(row, column);

    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<column ; j++){
            result.arr[i][j] = arr[i][j] * m.arr[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::multiply(const Matrix& m) const{
    if(!(column==m.row))
        throw invalid_argument("Matrix dimension must be the same.");

    T w=0;
    int mwidth = m.column;

    Matrix<T> result(row, mwidth);
    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<mwidth ; j++){
            for (int h=0 ; h<column ; h++){
                w += arr[i][h]*m.arr[h][j];
            }
            result.arr[i][j] = w;
            w=0;
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const{
    Matrix<T> result(column, row);

    for (int i=0 ; i<column ; i++){
        for (int j=0 ; j<row ; j++){
            result.arr[i][j] = arr[j][i];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::applyFunction(T (*function)(T)) const{
    Matrix<T> result(row, column);

    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<column ; j++){
            result.arr[i][j] = (*function)(arr[i][j]);
        }
    }
    return result;
}

template <typename T>
void Matrix<T>::print(ostream &flux) const{
    int maxLength[column] = {};
    stringstream ss;

    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<column ; j++){
            ss << arr[i][j];
            if(maxLength[j] < ss.str().size()){
                maxLength[j] = ss.str().size();
            }
            ss.str(string());
        }
    }

    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<column ; j++){
            flux << arr[i][j];
            ss << arr[i][j];
            for (int k=0 ; k<maxLength[j]-ss.str().size()+1 ; k++){
                flux << " ";
            }
            ss.str(string());
        }
        flux << endl;
    }
}

template <typename T>
bool Matrix<T>::operator==(const Matrix& m){
    if(row==m.row && column==m.column){
        for (int i=0 ; i<row ; i++){
            for (int j=0 ; j<column ; j++){
                if(arr[i][j]!=m.arr[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix& m){
    return !operator==(m);
}

template <typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix& m){
    this->arr = add(m).arr;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-=(const Matrix& m){
    this->arr = subtract(m).arr;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix& m){
    this->arr = multiply(m).arr;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const T &m){
    *this = this->multiply(m);
    return *this;
}


template <typename T>
T& Matrix<T>::operator()(int y, int x){
    if(!(y>=0 && y<row && x>=0 && x<column))
        throw invalid_argument("Index out of bounds.");
    return arr[y][x];
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b){
    return a.add(b);
}

template <typename T>
Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b){
    return a.subtract(b);
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b){
    return a.multiply(b);
}

template <typename T>
Matrix<T> operator*(const T &b, const Matrix<T>& a){
    return a.multiply(b);
}

template <typename T>
ostream& operator<<(ostream &flux, const Matrix<T>& m){
    m.print(flux);
    return flux;
}