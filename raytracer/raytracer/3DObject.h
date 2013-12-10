//
//  3DObject.h
//  raytracer
//
//  Created by Admin on 9/19/13.
//  Copyright (c) 2013 Jeff Einspahr. All rights reserved.
//

#ifndef raytracer__DObject_h
#define raytracer__DObject_h
#include "Ray.h"
#include "Hit.h"
#include "Material.h"

class Object
{
public:
    Material material;
    virtual bool Intersect(Ray &r, Hit &h)
    {
        return true;
    }
    virtual Vec3 normal(Hit &h){
        Vec3 temp;
        return temp;};
    Object();
    ~Object();
};

class Sphere:public Object
{
 public:
    double radius;
    Vec3 center;
    Sphere();
    Sphere(Vec3 c, double r);
    Sphere(double a, double b, double c, double r);
    ~Sphere();
    bool Intersect(Ray &r, Hit &h);
    Vec3 normal(Hit &h);
    
};

class Plane:public Object
{
public:
    Vec3 norm;
    Vec3 a;
    Plane();
    Plane(Vec3 n, Vec3 a);
    Plane(double a, double b, double c, double d, double e, double f);
    bool Intersect(Ray &r, Hit &h);
    Vec3 normal(Hit &h);

};

class Triangle:public Object
{
public:
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Triangle();
    Triangle(Vec3 p1, Vec3 p2, Vec3 p3);
    Triangle(double a, double b, double c, double d, double e, double f, double g, double h, double i);
    bool Intersect(Ray &r, Hit &h);
    Vec3 normal(Hit &h);
    ~Triangle();
};


#endif
