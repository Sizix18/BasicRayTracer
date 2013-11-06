#include "Vec3.h"

Vec3::Vec3( )
{
    components[X] = 0.0;
    components[Y] = 0.0;
    components[Z] = 0.0;
    
}

Vec3::Vec3( const Vec3& v)
{
    this->components[X] = v.components[X];
    this->components[Y] = v.components[Y];
    this->components[Z] = v.components[Z];
}
Vec3::Vec3( const Vec3* v )
{
    this->components[X] = v->components[X];
    this->components[Y] = v->components[Y];
    this->components[Z] = v->components[Z];
    
}
Vec3::Vec3( const double* ptr )
{
    this->components[X] = *(ptr+X);
    this->components[Y] = *(ptr+Y);
    this->components[Z] = *(ptr+Z);

}
Vec3::Vec3( const double& a, const double& b, const double& c )
{
    this->components[X] = a;
    this->components[Y] = b;
    this->components[Z] = c;
}
Vec3& Vec3::operator =( const Vec3 &src )
{
    this->components[X] = src.components[X];
    this->components[Y] = src.components[Y];
    this->components[Z] = src.components[Z];
    return *this;
}

bool Vec3::operator ==( const Vec3& src ) const
{
    for (int i = 0; i <4; i++)
    {
        if (this->components[i] != src.components[i])
        {
            return false;
        }
    }
    return true;
}
bool Vec3::operator !=( const Vec3& src ) const
{
    for (int i = 0; i <4; i++)
    {
        if (this->components[i] != src.components[i])
        {
            return true;
        }
    }
    return false;
    
}
const Vec3& Vec3::operator +=( const Vec3 &v )
{
    *this = *this + v;
    return *this;
    
}
const Vec3& Vec3::operator +=( const double &scalar )
{
    *this = *this + scalar;
    return *this;
}
const Vec3& Vec3::operator -=( const Vec3 &v )
{
    *this = *this - v;
    return *this;
    
}
const Vec3& Vec3::operator -=( const double &scalar )
{
    *this = *this - scalar;
    return *this;

}
const Vec3& Vec3::operator *=( const double &scalar )
{
    *this = *this * scalar;
    return *this;
   
}
const Vec3& Vec3::operator /=( const double &scalar )
{
    *this = *this / scalar;
    return *this;

}
Vec3 Vec3::operator *( const Vec3 &v) const
{
return Vec3(this->components[X]*v.components[X], this->components[Y]*v.components[Y], this->components[Z]*v.components[Z]);
}

Vec3 Vec3::operator +( const Vec3 &v ) const
{
    return Vec3(this->components[X]+v.components[X], this->components[Y]+v.components[Y], this->components[Z]+v.components[Z]);
}
Vec3 Vec3::operator +( const double &scalar ) const
{
    return Vec3(this->components[X]+scalar, this->components[Y]+scalar, this->components[Z]+scalar);
}
Vec3 Vec3::operator -( const Vec3 &v ) const
{
    return Vec3(this->components[X]-v.components[X], this->components[Y]-v.components[Y], this->components[Z]-v.components[Z]);
}
Vec3 Vec3::operator -( const double &scalar ) const
{
    return Vec3(this->components[X] - scalar, this->components[Y] - scalar, this->components[Z] - scalar);

}
Vec3 Vec3::operator -( ) const
{
    return Vec3(this->components[X]*(-1), this->components[Y]*(-1), this->components[Z]*(-1));
}
Vec3 Vec3::operator *( const double &scalar) const
{
    return Vec3(this->components[X] * scalar, this->components[Y] * scalar, this->components[Z] * scalar);
}
Vec3 Vec3::operator /( const double &scalar ) const
{
    return Vec3(this->components[X] / scalar, this->components[Y] / scalar, this->components[Z] / scalar);
}
const double Vec3::operator []( const size_t index ) const
{
    return this->components[index];
}
double& Vec3::operator []( const size_t index )
{
    return this->components[index];
}
// Returning a pointer is terrible but handy
const double* Vec3::constPtr( ) const
{
    double *xyz = new double[3];
    
    xyz[X] = this->components[X];
    xyz[Y] = this->components[Y];
    xyz[Z] = this->components[Z];
    return xyz;
    
}
const double& Vec3::x( ) const
{
    return this->components[X];
}
const double& Vec3::y( ) const
{
    return this->components[Y];
}
const double& Vec3::z( ) const
{
    return this->components[Z];
}
void Vec3::x( const double& a )
{
    this->components[X] = a;
}
void Vec3::y( const double& b )
{
    this->components[Y] = b;
}
void Vec3::z( const double& c )
{
    this->components[Z] = c;
}
// Math
void Vec3::normalize( )
{
    components[X]/=this->length();
    components[Y]/=this->length();
    components[Z]/=this->length();
}
double Vec3::length( ) const
{
    return (sqrt(this->squaredLength()));
}
double Vec3::squaredLength( ) const
{
    return (components[X] * components[X] +
            components[Y] * components[Y] +
            components[Z] * components[Z]);
}
double Vec3::angle( const Vec3& v ) const
{
    double dotProduct = dot(v);
    double thisLength = length();
    double vLength = v.length();
    return (dotProduct/(thisLength*vLength));
}
/*double Vec3::cosDoubleTheta( const Vec3 &v ) const
{
    
}*/
double Vec3::distanceFrom( const Vec3& v ) const
{
    return (sqrt(squaredDistanceFrom(v)));
}
double Vec3::squaredDistanceFrom( const Vec3& v ) const
{
    
    return SQR(this->components[X] - v.components[X]) + SQR(this->components[Y] - v.components[Y]) + SQR(this->components[Z] - v.components[Z]);
    
}
double Vec3::dot( const Vec3 &v ) const
{
    
    return ((this->components[X] * v.components[X]) +
            (this->components[Y] * v.components[Y]) +
            (this->components[Z] * v.components[Z]));
}


Vec3 operator *( const double &scalar, const Vec3 &v)
{
    return (v*scalar);//may need to create new instance of vector with Vec3
}
Vec3 cross( const Vec3 &u, const Vec3 &v )
{
    return Vec3((u.y() * v.z())-(u.z() * v.y()),
                (u.z() * v.x())-(u.x() * v.z()),
                (u.x() * v.y()) - (u.y() * v.x()));
}
void Vec3::display()
{
    std::cout << this->components[0] << ", " << this->components[1] << ", " << this->components[2] << std::endl;
}
/*Vec3 normal( Vec3 &a, Vec3 &b, Vec3 &c )
{
    
}*/
