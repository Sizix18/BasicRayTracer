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

Plane::Plane()
{}
Plane::Plane(double a, double b, double c, double d, double e, double f)
:norm(a,b,c), a(d,e,f)
{}

Plane::Plane(Vec3 n, Vec3 a)
{}
bool Plane::Intersect(Ray &r, Hit &h)
{
    double t;
    t = ((a - r.o).dot(norm))/(r.d.dot(norm));
    if (t >0.001 || t < 1.0) {
        if (t < h.t || h.t == -10.0) {
        h.t = t;
        //h.hit = (r.o + r.d * h.t - a) * normal;
        h.hit = r.o + r.d* h.t;
        h.objectMaterial = &material;
        return true;
        }
    }
    return false;
}

Vec3 Plane::normal(Hit &h)
{
    return(norm);
}

Triangle::Triangle()
{}
Triangle::Triangle(Vec3 p1, Vec3 p2, Vec3 p3):
a(p1), b(p2), c(p3)
{}
Triangle::Triangle(double a, double b, double c, double d, double e, double f, double g, double h, double i)
:a(a,b,c), b(d,e,f), c(g,h,i)
{}

bool Triangle::Intersect(Ray &r, Hit &h)
{
    Vec3 e1 = b - a;
    Vec3 e2 = c - a;
    Vec3 p = cross(r.d, e2);
    double tempA = e1.dot(p);
    
    if (tempA == 0) {
        return false;
    }
    double tempF = 1.0/tempA;
    Vec3 s = r.o - a;
    double tempU = s.dot(p) * tempF;
    if (tempU < 0.0 || tempU >1.0) {
        return false;
    }
    Vec3 q = cross(s, e1);
    double tempV = r.d.dot(q) * tempF;
    if (tempV < 0.0 || (tempV+tempU) > 1.0) {
        return false;
    }
    double tempT = e2.dot(q) * tempF;
    if (h.t > tempT || h.t == -10.0) {
    h.t = tempT;
    h.hit = r.o +r.d * h.t;
    return true;
    }
    return false;
}

Vec3 Triangle::normal(Hit &h)
{
    Vec3 n = cross((b - a), (c - a));
    n.normalize();
    return(n);
}


Triangle::~Triangle()
{}
