#ifndef _MSGFX_MAT4_H_
#define _MSGFX_MAT4_H_

#include <iostream>
#include <iomanip>
#include "Mat3.h"

#ifndef MSGFX_FP
#define MSGFX_FP

#define FP_EPSILON 1e-9
#define ALMOST_ZERO FP_EPSILON

#define FP_EQUAL(a, b, delta) ( ((a) == (b)) || \
( (a)-(delta) < (b) && \
(a)+(delta) > (b)) )

#define FP_LT(a, b, delta)  (fabs((a) - (b)) < (delta))

#define FP_GT(a, b, delta)  (fabs((a) - (b)) > (delta))

#define IOS_FP_PRECISION 5
#endif


/*
 * OPENGL IS COLUMN MAJOR
 * C IS ROW MAJOR
 *
 * This class is column major
 */

class Mat4{
private:
    double data[16];
public:
    Mat4( );
    Mat4( Mat3& m);
    Mat4( const Mat4& m );
    Mat4( double a, double b, double c, double d,
         double e, double f, double g, double h,
          double i, double j, double k, double l,
          double m, double n, double o, double p);
    
    explicit Mat4( double array[16] );
    Mat4& operator =( const Mat4& m );
    Mat4& operator =( const double array[16] );
    bool operator ==( const Mat4& m ) const;
    bool operator !=( const Mat4& m ) const;
    Mat4& operator +=( const Mat4& m );
    Mat4& operator +=( const double &scalar );
    Mat4& operator -=( const Mat4& m );
    Mat4& operator *=( const double &scalar );
    Mat4& operator /=( const double &scalar );
    const double operator ()( const size_t &col_i, const size_t &row_j ) const;
    double& operator ()( const size_t &col_i, const size_t &row_j );
    // Miscellaneous Methods
    double get_data( int value);
    double determinant( );
    Mat4 transpose( );
    Mat3 FindCofactorMatrix3x3 ( const size_t& index );
    Mat4 adjoint( );
    Mat4 inverse( double& determinant );
    // Arithmetic Operators
    Mat4 operator +( const Mat4 &n );
    Mat4 operator +( const double &scalar ) const;
    Mat4 operator -( const Mat4 &n );
    Mat4 operator -( const double &scalar ) const;
    Mat4 operator -( );
    Mat4 operator *( const double &scalar ) const;
    Mat4 operator *( const Mat4 &n ) const;
    Mat4 operator /( const double &scalar );
    std::ostream& write( std::ostream& out ) const;
    std::ostream& description( std::ostream &out = std::cerr ) const;
    void identity();
    void display();
    double* returnArray();
};

Mat4 operator *( const double &scalar, const Mat4 &m);

void copyMatrixToArray( Mat4& m, double a[16] );
void Swap(double &a, double &b);

Mat4 uniformScaleM4(double s);
Mat4 rotateM4(const double angleInDegrees, const double x, const double y, const double z);
Mat4 scaleM4(double a, double b, double c);
Mat4 translateM4(double a, double b, double c);


#endif
