//
//  3DObject.cpp
//  raytracer
//
//  Created by Admin on 9/19/13.
//  Copyright (c) 2013 Jeff Einspahr. All rights reserved.
//

#include "3DObject.h"
Object::Object()
:material(0.0,0.0,0.0)
{}

Object::~Object()
{}

Sphere::Sphere()
:center(0,0,0), radius(0)
{}
Sphere::Sphere(Vec3 c, double r)
:center(c), radius(r)
{}
Sphere::Sphere(double a, double b, double c, double r)
:center(a,b,c), radius(r)
{}

bool Sphere::Intersect(Ray &r, Hit &h)
{
    Vec3 x = r.o - center;
    double a = r.d.dot(r.d);
    double b = r.d.dot(x * 2);
    double c = x.dot(x) - (radius * radius);
    double d = (b*b) - (4.f * a * c);
    double t;

    if (d < 0.0 ) {
        return false;
    }
    else {
        double e = sqrt(d);
        double denom = 2.0 * a;
        t = ((-b - e)/ denom);
        if (t > 0.001) {
            if(h.t > t || h.t == -10.0)
            {
                h.t = t;
                h.hit = r.o + r.d * t;
                h.objectMaterial = &material;
                return true;
            }
        }
        t = ((-b + e)/denom);
        if (t > 0.001) {
            if(h.t > t || h.t == -10.0)
            {
                h.t = t;
                h.hit = r.o + r.d * t;
                h.objectMaterial = &material;
                return true;
            }
        }
    }
    return false;
    
}

Vec3 Sphere::normal(Hit &h)
{
    Vec3 n = (h.hit - center);
    n.normalize();
    return(n);
}

Sphere::~Sphere()
{}