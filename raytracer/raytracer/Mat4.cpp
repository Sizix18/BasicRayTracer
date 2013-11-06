//
//  Mat4.cpp
//  assignment 2
//
//  Created by Admin on 4/17/13.
//  Copyright (c) 2013 Jeff Einspahr. All rights reserved.
//

#include "Mat4.h"




Mat4::Mat4( )
{
    data[0] = 0.0;
    data[1] = 0.0;
    data[2] = 0.0;
    data[3] = 0.0;
    data[4] = 0.0;
    data[5] = 0.0;
    data[6] = 0.0;
    data[7] = 0.0;
    data[8] = 0.0;
    data[9] = 0.0;
    data[10] = 0.0;
    data[11] = 0.0;
    data[12] = 0.0;
    data[13] = 0.0;
    data[14] = 0.0;
    data[15] = 0.0;
}
Mat4::Mat4( Mat3& m)
{
    
    this->data[0] = m.get_data(0);
    this->data[1] = m.get_data(1);
    this->data[2] = m.get_data(2);
    this->data[3] = 0.0;
    this->data[4] = m.get_data(4);
    this->data[5] = m.get_data(5);
    this->data[6] = m.get_data(6);
    this->data[7] = 0.0;
    this->data[8] = m.get_data(8);
    this->data[9] = m.get_data(9);
    this->data[10] = m.get_data(10);
    this->data[11] = 0.0;
    this->data[12] = 0.0;
    this->data[13] = 0.0;
    this->data[14] = 0.0;
    this->data[15] = 1.0;
}

Mat4::Mat4( const Mat4& m )
{
    this->data[0] = m.data[0];
    this->data[1] = m.data[1];
    this->data[2] = m.data[2];
    this->data[3] = m.data[3];
    this->data[4] = m.data[4];
    this->data[5] = m.data[5];
    this->data[6] = m.data[6];
    this->data[7] = m.data[7];
    this->data[8] = m.data[8];
    this->data[9] = m.data[9];
    this->data[10] = m.data[10];
    this->data[11] = m.data[11];
    this->data[12] = m.data[12];
    this->data[13] = m.data[13];
    this->data[14] = m.data[14];
    this->data[15] = m.data[15];

}
Mat4::Mat4(double a, double b, double c, double d,
     double e, double f, double g, double h,
     double i, double j, double k, double l,
     double m, double n, double o, double p)
{
    this->data[0] = a;
    this->data[1] = b;
    this->data[2] = c;
    this->data[3] = d;
    this->data[4] = e;
    this->data[5] = f;
    this->data[6] = g;
    this->data[7] = h;
    this->data[8] = i;
    this->data[9] = j;
    this->data[10] = k;
    this->data[11] = l;
    this->data[12] = m;
    this->data[13] = n;
    this->data[14] = o;
    this->data[15] = p;

}
    
Mat4::Mat4( double array[16] )
{
    this->data[0] = array[0];
    this->data[1] = array[1];
    this->data[2] = array[2];
    this->data[3] = array[3];
    this->data[4] = array[4];
    this->data[5] = array[5];
    this->data[6] = array[6];
    this->data[7] = array[7];
    this->data[8] = array[8];
    this->data[9] = array[9];
    this->data[10] = array[10];
    this->data[11] = array[11];
    this->data[12] = array[12];
    this->data[13] = array[13];
    this->data[14] = array[14];
    this->data[15] = array[15];

}
Mat4& Mat4::operator =( const Mat4& m )
{
    this->data[0] = m.data[0];
    this->data[1] = m.data[1];
    this->data[2] = m.data[2];
    this->data[3] = m.data[3];
    this->data[4] = m.data[4];
    this->data[5] = m.data[5];
    this->data[6] = m.data[6];
    this->data[7] = m.data[7];
    this->data[8] = m.data[8];
    this->data[9] = m.data[9];
    this->data[10] = m.data[10];
    this->data[11] = m.data[11];
    this->data[12] = m.data[12];
    this->data[13] = m.data[13];
    this->data[14] = m.data[14];
    this->data[15] = m.data[15];

    return *this;
}
Mat4& Mat4::operator =( const double array[16] )
{
    this->data[0] = array[0];
    this->data[1] = array[1];
    this->data[2] = array[2];
    this->data[3] = array[3];
    this->data[4] = array[4];
    this->data[5] = array[5];
    this->data[6] = array[6];
    this->data[7] = array[7];
    this->data[8] = array[8];
    this->data[9] = array[9];
    this->data[10] = array[10];
    this->data[11] = array[11];
    this->data[12] = array[12];
    this->data[13] = array[13];
    this->data[14] = array[14];
    this->data[15] = array[15];

    return *this;
    
}
bool Mat4::operator ==( const Mat4& m ) const
{
    for (int i=0; i<16; ++i) {
        if (this->data[i] != m.data[i]) {
            return false;
        }
    }
    return true;
}
bool Mat4::operator !=( const Mat4& m ) const
{
    for (int i=0; i<16; ++i) {
        if (this->data[i] != m.data[i]) {
            return true;
        }
    }
    return false;
}
Mat4& Mat4::operator +=( const Mat4& m )
{
    *this = *this + m;
    return *this;
    
}
Mat4& Mat4::operator +=( const double &scalar )
{
    *this = *this + scalar;
    return *this;
}
Mat4& Mat4::operator -=( const Mat4& m )
{
    *this = *this - m;
    return *this;
}
Mat4& Mat4::operator *=( const double &scalar )
{
    *this = *this * scalar;
    return *this;
    
}
Mat4& Mat4::operator /=( const double &scalar )
{
    *this = *this / scalar;
    return *this;
}
const double Mat4::operator ()( const size_t &col_i, const size_t &row_j ) const
{
    return (this->data[(4*(col_i - 1) + (row_j -1))]);
}
double& Mat4::operator ()( const size_t &col_i, const size_t &row_j )
{
    return (this->data[(4*(col_i - 1) + (row_j -1))]);
}

// Miscellaneous Methods
double Mat4::get_data(int value )
{
    
    return this->data[value];
}


double Mat4::determinant( )
{
    this->transpose();
    double determinant = (( this->data[0] * this->data[5] * this->data[10] * this->data[15] ) + ( this->data[0] * this->data[6] * this->data[11] * this->data[13] ) + ( this->data[0] * this->data[7] * this->data[9] * this->data[14] )
                          + ( this->data[1] * this->data[4] * this->data[11] * this->data[14] ) + ( this->data[1] * this->data[6] * this->data[8] * this->data[15] ) + ( this->data[1] * this->data[7] * this->data[10] * this->data[12] )
                          + ( this->data[2] * this->data[4] * this->data[9] * this->data[15] ) + ( this->data[2] * this->data[5] * this->data[11] * this->data[12] ) + ( this->data[2] * this->data[7] * this->data[8] * this->data[13] )
                          + ( this->data[3] * this->data[4] * this->data[10] * this->data[13] ) + ( this->data[3] * this->data[5] * this->data[8] * this->data[14] ) + ( this->data[3] * this->data[6] * this->data[9] * this->data[12] )
                          - ( this->data[0] * this->data[5] * this->data[11] * this->data[14] ) - ( this->data[0] * this->data[6] * this->data[9] * this->data[15] ) - ( this->data[0] * this->data[7] * this->data[10] * this->data[13] )
                          - ( this->data[1] * this->data[4] * this->data[10] * this->data[15] ) - ( this->data[1] * this->data[6] * this->data[11] * this->data[12] ) - ( this->data[1] * this->data[7] * this->data[8] * this->data[14] )
                          - ( this->data[2] * this->data[4] * this->data[11] * this->data[13] ) - ( this->data[2] * this->data[5] * this->data[8] * this->data[15] ) - ( this->data[2] * this->data[7] * this->data[9] * this->data[12] )
                          - ( this->data[3] * this->data[4] * this->data[9] * this->data[14] ) - ( this->data[3] * this->data[5] * this->data[10] * this->data[12] ) - ( this->data[3] * this->data[6] * this->data[8] * this->data[13] ) );
    this->transpose();
return (determinant);
}
Mat4 Mat4::transpose( )
{
    double temp[16];
    
    for(int i=0;i<16;++i)
        temp[i] = data[i];
    
    Swap(temp[1], temp[4]);
    Swap(temp[2], temp[8]);
    Swap(temp[3], temp[12]);
    Swap(temp[6], temp[9]);
    Swap(temp[7], temp[13]);
    Swap(temp[11], temp[14]);
    return Mat4(temp);
}
Mat3 Mat4::FindCofactorMatrix3x3 ( const size_t& index )
{
    int rowC, colC;
    // These are the rows and columns to be ignored
    // Resulting values are within 0,1,2,3
    // first row is 0, last row 3
    // first col is 0, last col is 3
    rowC = index/4.0; // 4 is the number of dimensions being used
    colC = index%4;
    
    int counter = 0; // Keep track of transfering 4x4 matrix into a simple 2D array, for organization
    double temp[4][4];
    for(int row=0;row<4;++row)
        for(int col=0;col<4;++col)
            temp[row][col] = this->data[counter++];
    double cofactor[9];
    counter = 0;
    for(int row=0;row<4;++row)
        for(int col=0;col<4;++col)
        {
            if(rowC == row || colC == col)
            { // Skip that row and column
            }
            else
            {
                // Value is included for our cofactor
                cofactor[counter++] = temp[row][col];
            }
        }
    return Mat3(cofactor);
}
Mat4 Mat4::adjoint( )
{
    double detOfCofactors[16];

    this->transpose();
    for(int i=0;i<16;++i)
    {
        detOfCofactors[i] = this->FindCofactorMatrix3x3(i).determinant();
    }
    this->transpose();

    Mat4 temp(detOfCofactors);

    temp.data[1] *= -1;
    temp.data[3] *= -1;
    temp.data[4] *= -1;
    temp.data[6] *= -1;
    temp.data[9] *= -1;
    temp.data[11] *= -1;
    temp.data[12] *= -1;
    temp.data[14] *= -1;
    
    return temp.transpose();
}Mat4 Mat4::inverse( double& determinant )
{
    if (this->determinant() == 0.0) {
        std::cerr << "This Matrix cannot be inversed" << std::endl;
        return *this;
    }
    else
        return (this->adjoint() * (1/this->determinant()));
}
// Arithmetic Operators
Mat4 Mat4::operator +( const Mat4 &n )
{
    this->data[0] = n.data[0] + this->data[0];
    this->data[1] = n.data[1] + this->data[1];
    this->data[2] = n.data[2] + this->data[2];
    this->data[3] = n.data[3] + this->data[3];
    this->data[4] = n.data[4] + this->data[4];
    this->data[5] = n.data[5] + this->data[5];
    this->data[6] = n.data[6] + this->data[6];
    this->data[7] = n.data[7] + this->data[7];
    this->data[8] = n.data[8] + this->data[8];
    this->data[9] = n.data[9] + this->data[9];
    this->data[10] = n.data[10] + this->data[10];
    this->data[11] = n.data[11] + this->data[11];
    this->data[12] = n.data[12] + this->data[12];
    this->data[13] = n.data[13] + this->data[13];
    this->data[14] = n.data[14] + this->data[14];
    this->data[15] = n.data[15] + this->data[15];

    return *this;
    
}
Mat4 Mat4::operator +( const double &scalar ) const
{
    return Mat4(this->data[0] + scalar,
                this->data[1] + scalar,
                this->data[2] + scalar,
                this->data[3] + scalar,
                this->data[4] + scalar,
                this->data[5] + scalar,
                this->data[6] + scalar,
                this->data[7] + scalar,
                this->data[8] + scalar,
                this->data[9] + scalar,
                this->data[10] + scalar,
                this->data[11] + scalar,
                this->data[12] + scalar,
                this->data[13] + scalar,
                this->data[14] + scalar,
                this->data[15] + scalar);
}

Mat4 Mat4::operator -( const Mat4 &n )
{
    this->data[0] = this->data[0] - n.data[0];
    this->data[1] = this->data[1] - n.data[1];
    this->data[2] = this->data[2] - n.data[2];
    this->data[3] = this->data[3] - n.data[3];
    this->data[4] = this->data[4] - n.data[4];
    this->data[5] = this->data[5] - n.data[5];
    this->data[6] = this->data[6] - n.data[6];
    this->data[7] = this->data[7] - n.data[7];
    this->data[8] = this->data[8] - n.data[8];
    this->data[9] = this->data[9] - n.data[9];
    this->data[10] = this->data[10] - n.data[10];
    this->data[11] = this->data[11] - n.data[11];
    this->data[12] = this->data[12] - n.data[12];
    this->data[13] = this->data[13] - n.data[13];
    this->data[14] = this->data[14] - n.data[14];
    this->data[15] = this->data[15] - n.data[15];

    return *this;
    
}
Mat4 Mat4::operator -( const double &scalar ) const
{
    return Mat4(this->data[0] - scalar,
                this->data[1] - scalar,
                this->data[2] - scalar,
                this->data[3] - scalar,
                this->data[4] - scalar,
                this->data[5] - scalar,
                this->data[6] - scalar,
                this->data[7] - scalar,
                this->data[8] - scalar,
                this->data[9] - scalar,
                this->data[10] - scalar,
                this->data[11] - scalar,
                this->data[12] - scalar,
                this->data[13] - scalar,
                this->data[14] - scalar,
                this->data[15] - scalar);
}

Mat4 Mat4::operator -( )
{
    this->data[0] = this->data[0] * -1;
    this->data[1] = this->data[1] * -1;
    this->data[2] = this->data[2] * -1;
    this->data[3] = this->data[3] * -1;
    this->data[4] = this->data[4] * -1;
    this->data[5] = this->data[5] * -1;
    this->data[6] = this->data[6] * -1;
    this->data[7] = this->data[7] * -1;
    this->data[8] = this->data[8] * -1;
    this->data[9] = this->data[9] * -1;
    this->data[10] = this->data[10] * -1;
    this->data[11] = this->data[11] * -1;
    this->data[12] = this->data[12] * -1;
    this->data[13] = this->data[13] * -1;
    this->data[14] = this->data[14] * -1;
    this->data[15] = this->data[15] * -1;

    return *this;
    
}
Mat4 Mat4::operator *( const double &scalar ) const
{
    return Mat4(this->data[0] * scalar,
                this->data[1] * scalar,
                this->data[2] * scalar,
                this->data[3] * scalar,
                this->data[4] * scalar,
                this->data[5] * scalar,
                this->data[6] * scalar,
                this->data[7] * scalar,
                this->data[8] * scalar,
                this->data[9] * scalar,
                this->data[10] * scalar,
                this->data[11] * scalar,
                this->data[12] * scalar,
                this->data[13] * scalar,
                this->data[14] * scalar,
                this->data[15] * scalar);
}
Mat4 Mat4::operator *( const Mat4 &n ) const
{
    Mat4 temp = *this;
    temp.transpose();
    temp.data[0] = this->data[0] * n.data[0] + this->data[1] * n.data[4] + this->data[2] * n.data[8] + this->data[3] * n.data[12];
    temp.data[1] = this->data[0] * n.data[1] + this->data[1] * n.data[5] + this->data[2] * n.data[9] + this->data[3] * n.data[13];
    temp.data[2] = this->data[0] * n.data[2] + this->data[1] * n.data[6] + this->data[2] * n.data[10] + this->data[3] * n.data[14];
    temp.data[3] = this->data[0] * n.data[3] + this->data[1] * n.data[7] + this->data[2] * n.data[11] + this->data[3] * n.data[15];
    temp.data[4] = this->data[4] * n.data[0] + this->data[5] * n.data[4] + this->data[6] * n.data[8] + this->data[7] * n.data[12];
    temp.data[5] = this->data[4] * n.data[1] + this->data[5] * n.data[5] + this->data[6] * n.data[9] + this->data[7] * n.data[13];
    temp.data[6] = this->data[4] * n.data[2] + this->data[5] * n.data[6] + this->data[6] * n.data[10] + this->data[7] * n.data[14];
    temp.data[7] = this->data[4] * n.data[3] + this->data[5] * n.data[7] + this->data[6] * n.data[11] + this->data[7] * n.data[15];
    temp.data[8] = this->data[8] * n.data[0] + this->data[9] * n.data[4] + this->data[10] * n.data[8] + this->data[11] * n.data[12];
    temp.data[9] = this->data[8] * n.data[1] + this->data[9] * n.data[5] + this->data[10] * n.data[9] + this->data[11] * n.data[13];
    temp.data[10] = this->data[8] * n.data[2] + this->data[9] * n.data[6] + this->data[10] * n.data[10] + this->data[11] * n.data[14];
    temp.data[11] = this->data[8] * n.data[3] + this->data[9] * n.data[7] + this->data[10] * n.data[11] + this->data[11] * n.data[15];
    temp.data[12] = this->data[12] * n.data[0] + this->data[13] * n.data[4] + this->data[14] * n.data[8] + this->data[15] * n.data[12];
    temp.data[13] = this->data[12] * n.data[1] + this->data[13] * n.data[5] + this->data[14] * n.data[9] + this->data[15] * n.data[13];
    temp.data[14] = this->data[12] * n.data[2] + this->data[13] * n.data[6] + this->data[14] * n.data[10] + this->data[15] * n.data[14];
    temp.data[15] = this->data[12] * n.data[3] + this->data[13] * n.data[7] + this->data[14] * n.data[11] + this->data[15] * n.data[15];
    temp.transpose();
    return (temp);
}
Mat4 Mat4::operator /( const double &scalar )
{
    return Mat4(this->data[0] / scalar,
                this->data[1] / scalar,
                this->data[2] / scalar,
                this->data[3] / scalar,
                this->data[4] / scalar,
                this->data[5] / scalar,
                this->data[6] / scalar,
                this->data[7] / scalar,
                this->data[8] / scalar,
                this->data[9] / scalar,
                this->data[10] / scalar,
                this->data[11] / scalar,
                this->data[12] / scalar,
                this->data[13] / scalar,
                this->data[14] / scalar,
                this->data[15] / scalar);
    
}
void Mat4::identity()
{
    this->data[0] = 1.0;
    this->data[1] = 0.0;
    this->data[2] = 0.0;
    this->data[3] = 0.0;
    this->data[4] = 0.0;
    this->data[5] = 1.0;
    this->data[6] = 0.0;
    this->data[7] = 0.0;
    this->data[8] = 0.0;
    this->data[9] = 0.0;
    this->data[10] = 1.0;
    this->data[11] = 0.0;
    this->data[12] = 0.0;
    this->data[13] = 0.0;
    this->data[14] = 0.0;
    this->data[15] = 1.0;

    
    
}
void Mat4::display()
{
    std::cout << this->data[0] << ", " << this->data[4] << ", " << this->data[8] << ", " << this->data[12] << std::endl;
    std::cout << this->data[1] << ", " << this->data[5] << ", " << this->data[9] << ", " << this->data[13] << std::endl;
    std::cout << this->data[2] << ", " << this->data[6] << ", " << this->data[10] << ", " << this->data[14] << std::endl;
    std::cout << this->data[3] << ", " << this->data[7] << ", " << this->data[11] << ", " << this->data[15] <<std::endl;

}
double* Mat4::returnArray()
{
    double* array = new double[16];
    for (int i=0; i<16; ++i) {
        array[i] = this->data[i];
    }
    return array;
}

Mat4 operator *( const double &scalar, const Mat4 &m)
{
    return m * scalar;
}

void copyMatrixToArray( Mat4& m, double a[16] )
{
    for (int i = 0; i < 16; ++i) {
        a[i] = m.get_data(i);
    }
}
Mat4 translateM4(double a, double b, double c)
{
    return Mat4(1.0, 0.0, 0.0, 0.0,
                0.0, 1.0, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                a, b, c, 1.0);
}
Mat4 rotateM4(const double angleInDegrees, const double x, const double y, const double z)
{
    Mat4 rotate;
    rotate.identity();
    
    if (x == 1.0 && y == 0.0 && z == 0.0) {
        rotate(2,2) = cos(DEG2RAD(angleInDegrees));
        rotate(2,3) = sin(DEG2RAD(angleInDegrees));
        rotate(3,2) = -sin(DEG2RAD(angleInDegrees));
        rotate(3,3) = cos(DEG2RAD(angleInDegrees));
        
    }
    else if (x == 0.0 && y == 1.0 && z == 0.0) {
        rotate(1,1) = cos(DEG2RAD(angleInDegrees));
        rotate(1,3) = -sin(DEG2RAD(angleInDegrees));
        rotate(3,1) = sin(DEG2RAD(angleInDegrees));
        rotate(3,3) = cos(DEG2RAD(angleInDegrees));
        
    }
    else if (x == 0.0 && y == 0.0 && z == 1.0) {
        rotate(1,1) = cos(DEG2RAD(angleInDegrees));
        rotate(1,2) = sin(DEG2RAD(angleInDegrees));
        rotate(2,1) = -sin(DEG2RAD(angleInDegrees));
        rotate(2,2) = cos(DEG2RAD(angleInDegrees));
        
    }
    return rotate;

}

Mat4 scaleM4(double a, double b, double c)
{
    Mat4 scale;
    scale.identity();
    scale(1,1) = a;
    scale(2,2) = b;
    scale(3,3) = c;
    
    return scale;
    
}



void Swap( double& t1, double& t2 )
{
    double temp = t1;
    t1 = t2;
    t2 = temp;
}



