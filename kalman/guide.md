# Matrix class -

## Data :
>row, col, 2d vector
---
## Methods :


1.add- add(m) - *add two matrix*

2.subtract = subtract(m) - *subtract one matrix from another*

3.multiply = multiply(m) - *multiply two matrix*

4.dot = dot(m) - *dot product of two matrix*

5.transpose = transpose() - *transpose a matrix*

6.multiply by value = multiply(v) - *multiply values*

7.divide by value = divide(v) - *divide values*

8.applyFunction = applyFunction(F) - *apply function to elements*

9.fill = fill(v) - *fill matrix with a particular value*

10.put = put(i,j,v) - *put the value in a specified index*

11.get = get(i,j) - *get the value of a specified index*

12.getCofactor(i,j) - *get the cofactor for index i and j*

13.getDeterminant() - *to get the determinant of the matrix*

14.adjMatrix() - *to get the adjoint matrix*

15.inverseMatrix() - *To get the inverse of a matrix*

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
    Matrix(row,col);
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
