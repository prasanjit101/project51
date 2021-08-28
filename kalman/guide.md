# Matrix class -

## Data :
>row, col, 2d vector
---
## Methods :


1.add- M.add(m) - *add two matrix*

2.subtract = M.subtract(m) - *subtract one matrix from another*

3.multiply = M.multiply(m) - *multiply two matrix*

4.dot = M.dot(m) - *dot product of two matrix*

5.transpose = M.transpose() - *transpose a matrix*

6.multiply by value = M.multiply(v) - *multiply values*

7.divide by value = M.divide(v) - *divide values*

8.applyFunction = M.applyFunction(F) - *apply function to elements*

9.fill = M.fill(v) - *fill matrix with a particular value*

10.put = M.put(i,j,v) - *put the value in a specified index*

11.get = M.get(i,j) - *returns the value of a specified index*

12.Coafctor- M.getCofactor(i,j) - *returns the cofactor of Matrix M for index i and j*

13.Determinant- M.getDeterminant() - *returns the determinant of the matrix M*

14.Adjoint Matrix- M.adjMatrix() - *returns the adjoint matrix M*

15.Inverse Matrix- M.inverseMatrix() - *returns the inverse of a matrix M*

*where m is a matrix object,v is a value,F is a function name*

### Examples:

Matrix<float> M({{1,2,3},{4,5,6},{7,8,9}});
M.get(1,2); //to get element at index (1,2)
M.transpose();
M.multiply(4);

---
## Operator:
```
+
-
*
/
<<
+= (object)
-= (object)
*= (value,object)
/= (value)
```
---
### Examples:
```
M3=M2+M1
or 
M3+=M1 <-> M3=M3+M1
cout<<M3;
```
---
## Initialization :

```Matrix object declaration -
    Matrix<float> Mat(vector);
or
    Matrix<float> Mat({{1,2},{3,4}});
or
    Matrix<float>(row,col);

to declare a column matrix-
    Matrix<float>({{3},{4}});

to declare a row matrix-
    Matrix<float> ({3,4});

```

## Input :
```
T -> State transition matrix
C -> Control matrix
M -> Measurement matrix
Ez -> Measurement Noise matrix
Ex -> Process noise matrix
X -> State vector
P -> State covariance matrix
```
---
