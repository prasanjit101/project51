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


*where m is a matrix object,v is a value,F is a function name*

---
## Operator:
```
+
-
*
/
<<
+=
-=
*=
/=
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
