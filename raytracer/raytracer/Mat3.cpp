#include "Mat3.h"


Mat3::Mat3( )
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
}
Mat3::Mat3( const Mat3& m )
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
}
Mat3::Mat3( double a, double b, double c,
     double d, double e, double f,
     double g, double h, double i )
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
}
Mat3::Mat3( const Vec3 &col_a,
     const Vec3 &col_b,
     const Vec3 &col_c )
{
    this->data[0] = col_a.x();
    this->data[1] = col_a.y();
    this->data[2] = col_a.z();
    this->data[3] = col_b.x();
    this->data[4] = col_b.y();
    this->data[5] = col_b.z();
    this->data[6] = col_c.x();
    this->data[7] = col_c.y();
    this->data[8] = col_c.z();
}
Mat3::Mat3( double array[9] )
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
}
Mat3& Mat3::operator =( const Mat3& m )
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
    return *this;
}
Mat3& Mat3::operator =( const double array[9] )
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
    
    return *this;

}
bool Mat3::operator ==( const Mat3& m ) const
{
    for (int i=0; i<9; ++i) {
        if (this->data[i] != m.data[i]) {
            return false;
        }
    }
    return true;
}
bool Mat3::operator !=( const Mat3& m ) const
{
    for (int i=0; i<9; ++i) {
        if (this->data[i] != m.data[i]) {
            return true;
        }
    }
    return false;
}
Mat3& Mat3::operator +=( const Mat3& m )
{
    *this = *this + m;
    return *this;
    
}
Mat3& Mat3::operator +=( const double &scalar )
{
    *this = *this + scalar;
    return *this;
}
Mat3& Mat3::operator -=( const Mat3& m )
{
    *this = *this - m;
    return *this;
}
Mat3& Mat3::operator *=( const double &scalar )
{
    *this = *this * scalar;
    return *this;

}
Mat3& Mat3::operator /=( const double &scalar )
{
    *this = *this / scalar;
    return *this;
}
const double Mat3::operator ()( const size_t &col_i, const size_t &row_j ) const
{
    return (this->data[(3*(col_i - 1) + (row_j -1))]);
}
double& Mat3::operator ()( const size_t &col_i, const size_t &row_j )
{
    return (this->data[(3*(col_i - 1) + (row_j -1))]);
}
//const Vec3 operator []( const size_t col_i ) const;
Vec3 Mat3::operator []( const size_t &col_i )
{
    switch (col_i) {
        case 1:
            return Vec3(this->data[0],
                        this->data[1],
                        this->data[2]);
            break;
        case 2:
            return Vec3(this->data[3],
                        this->data[4],
                        this->data[5]);

        case 3:
            return Vec3(this->data[6],
                        this->data[7],
                        this->data[8]);
        default:
            return Vec3(-9999,-9999,-9999);
            break;
    }
    
    
    
    
    /*return Vec3(this->data[col_i - 1],
                this->data[col_i],
                this->data[col_i  + 1]);*/
}
Vec3 Mat3::col( const size_t &col_i ) const
{
    switch (col_i) {
        case 1:
            return Vec3(this->data[0],
                        this->data[1],
                        this->data[2]);
            break;
        case 2:
            return Vec3(this->data[3],
                        this->data[4],
                        this->data[5]);
            
        case 3:
            return Vec3(this->data[6],
                        this->data[7],
                        this->data[8]);
        default:
            return Vec3(-9999,-9999,-9999);
            break;
    }
 
}
Vec3 Mat3::row( const size_t &row_j ) const
{
 return Vec3(this->data[(row_j-1)],
             this->data[(row_j+2)],
             this->data[(row_j+5)]);
}
// Miscellaneous Methods
double Mat3::get_data(int value )
{
    
    return this->data[value];
}


double Mat3::determinant( )
{
    return (this->data[0] * ((this->data[4] * this->data[8]) - (this->data[7] * this->data[5])) -
            this->data[3] * ((this->data[1] * this->data[8]) - (this->data[7] * this->data[2])) +
            this->data[6] * ((this->data[1] * this->data[5]) - (this->data[4] * this->data[2])));
}
Mat3 Mat3::transpose( )
{
    int temp = this->data[1];
    this->data[1] = this->data[3];
    this->data[3] = temp;
    temp = this->data[2];
    this->data[2] = this->data[6];
    this->data[6] = temp;
    temp = this->data[5];
    this->data[5] = this->data[7];
    this->data[7] = temp;
    return *this;
    
}

Mat3 Mat3::adjoint( )
{
    return Mat3(((this->data[4] * this->data[8]) - (this->data[5] * this->data[7])),
                -((this->data[1] * this->data[8]) - (this->data[2] * this->data[7])),
                ((this->data[1] * this->data[5]) - (this->data[2] * this->data[4])),
                -((this->data[3] * this->data[8]) - (this->data[5] * this->data[6])),
                ((this->data[0] * this->data[8]) - (this->data[2] * this->data[6])),
                -((this->data[0] * this->data[5]) - (this->data[2] * this->data[3])),
                ((this->data[3] * this->data[7]) - (this->data[4] * this->data[6])),
                -((this->data[0] * this->data[7]) - (this->data[1] * this->data[6])),
                ((this->data[0] * this->data[4]) - (this->data[1] * this->data[3]))).transpose();
    
}
Mat3 Mat3::inverse( double& determinant )
{
    if (this->determinant() == 0.0) {
        std::cerr << "This Matrix cannot be inversed" << std::endl;
        return *this;
    }
    else
        return (this->adjoint() * (1/this->determinant()));
}
// Arithmetic Operators
Mat3 Mat3::operator +( const Mat3 &n )
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
    return *this;

}
Mat3 Mat3::operator +( const double &scalar ) const
{
    return Mat3(this->data[0] + scalar,
                this->data[1] + scalar,
                this->data[2] + scalar,
                this->data[3] + scalar,
                this->data[4] + scalar,
                this->data[5] + scalar,
                this->data[6] + scalar,
                this->data[7] + scalar,
                this->data[8] + scalar);
}

Mat3 Mat3::operator -( const Mat3 &n )
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
    return *this;
   
}
Mat3 Mat3::operator -( const double &scalar ) const
{
    return Mat3(this->data[0] - scalar,
                this->data[1] - scalar,
                this->data[2] - scalar,
                this->data[3] - scalar,
                this->data[4] - scalar,
                this->data[5] - scalar,
                this->data[6] - scalar,
                this->data[7] - scalar,
                this->data[8] - scalar);
}

Mat3 Mat3::operator -( )
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
    return *this;
    
}
Mat3 Mat3::operator *( const double &scalar ) const
{
    return Mat3(this->data[0] * scalar,
                this->data[1] * scalar,
                this->data[2] * scalar,
                this->data[3] * scalar,
                this->data[4] * scalar,
                this->data[5] * scalar,
                this->data[6] * scalar,
                this->data[7] * scalar,
                this->data[8] * scalar);
}
Mat3 Mat3::operator *( const Mat3 &n )
{
    Mat3 temp;
    
	temp.data[0] = this->data[0] * n.data[0] + this->data[1] * n.data[3] + this->data[2] * n.data[6];
	temp.data[1] = this->data[0] * n.data[1] + this->data[1] * n.data[4] + this->data[2] * n.data[7];
	temp.data[2] = this->data[0] * n.data[2] + this->data[1] * n.data[5] + this->data[2] * n.data[8];
    
	temp.data[3] = this->data[3] * n.data[0] + this->data[4] * n.data[3] + this->data[5] * n.data[6];
	temp.data[4] = this->data[3] * n.data[1] + this->data[4] * n.data[4] + this->data[5] * n.data[7];
	temp.data[5] = this->data[3] * n.data[2] + this->data[4] * n.data[5] + this->data[5] * n.data[8];
	
	temp.data[6] = this->data[6] * n.data[0] + this->data[7] * n.data[3] + this->data[8] * n.data[6];
	temp.data[7] = this->data[6] * n.data[1] + this->data[7] * n.data[4] + this->data[8] * n.data[7];
	temp.data[8] = this->data[6] * n.data[2] + this->data[7] * n.data[5] + this->data[8] * n.data[8];
    
	return temp;
}
Vec3 Mat3::operator *( const Vec3 &v )
{
    return Vec3(((v.x() * this->data[0]) + (v.y() * this->data[3]) + (v.z() * this->data[6])),
                ((v.x() * this->data[1]) + (v.y() * this->data[4]) + (v.z() * this->data[7])),
                ((v.x() * this->data[2]) + (v.y() * this->data[5]) + (v.z() * this->data[8])));
}
Mat3 Mat3::operator /( const double &scalar )
{
    return Mat3(this->data[0] / scalar,
                this->data[1] / scalar,
                this->data[2] / scalar,
                this->data[3] / scalar,
                this->data[4] / scalar,
                this->data[5] / scalar,
                this->data[6] / scalar,
                this->data[7] / scalar,
                this->data[8] / scalar);

}
void Mat3::identity()
{
    this->data[0] = 1.0;
    this->data[1] = 0.0;
    this->data[2] = 0.0;
    this->data[3] = 0.0;
    this->data[4] = 1.0;
    this->data[5] = 0.0;
    this->data[6] = 0.0;
    this->data[7] = 0.0;
    this->data[8] = 1.0;

    
}
void Mat3::display()
{
    std::cout << this->data[0] << ", " << this->data[3] << ", " << this->data[6] << std::endl;
    std::cout << this->data[1] << ", " << this->data[4] << ", " << this->data[7] << std::endl;
    std::cout << this->data[2] << ", " << this->data[5] << ", " << this->data[8] << std::endl;
}

Mat3 operator *( const double &scalar, const Mat3 &m)
{
    return m * scalar;
}

void copyMatrixToArray( Mat3& m, double a[9] )
{
    for (int i = 0; i < 9; ++i) {
        a[i] = m.get_data(i);
    }
}

Mat3 rotate(const double angleInDegrees, const double x, const double y, const double z)
{
    Mat3 rotate;
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

Mat3 uniformScale(double s)
{
    Mat3 mat;
    mat.identity();
    mat(1,1) = s;
    mat(2,2) = s;
    mat(3,3) = s;
    
    return mat;
}

Mat3 scale(double a, double b, double c)
{
    Mat3 mat;
    mat.identity();
    mat(1,1) = a;
    mat(2,2) = b;
    mat(3,3) = c;
    return mat;
}