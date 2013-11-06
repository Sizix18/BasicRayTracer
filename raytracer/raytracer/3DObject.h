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
    virtual bool Intersect(Ray &r, Hit &t)
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
    bool Intersect(Ray &r, Hit &t);
    Vec3 normal(Hit &h);
    
};


#endif
