//
//  Camera.cpp
//  raytracer
//
//  Created by Admin on 9/18/13.
//  Copyright (c) 2013 Jeff Einspahr. All rights reserved.
//

#include "Camera.h"

Camera::Camera( )
:center(0.0,0.0,0.0), direction(0.0,0.0,0.0), up(0.0,0.0,0.0), angle(0.0), distance(0.0), u(0.0,0.0,0.0),v(0.0,0.0,0.0), w(0.0,0.0,0.0)
{
    gaze = (direction - center);
    gaze.normalize();
    right = cross(gaze, up);
}

Camera::Camera(double a, double b, double c, double e, double f, double g, double h, double i, double j)
:center(a,b,c),direction(e,f,g), up(h,i,j), angle(0.0), distance(0.0), u(0.0,0.0,0.0),v(0.0,0.0,0.0), w(0.0,0.0,0.0)
{
    gaze = (direction - center);
    gaze.normalize();
    right = cross(gaze, up);

}

Camera::Camera(Vec3 c, Vec3 d, Vec3 u)
:center(c), direction(d), up(u), angle(0.0), distance(0.0), u(0.0,0.0,0.0),v(0.0,0.0,0.0), w(0.0,0.0,0.0)
{
    gaze = (direction - center);
    gaze.normalize();
    right = cross(gaze, up);
}
 
Camera::~Camera()
{
    
}
void Camera::calcUVW()
{
    w = center - direction;
    w.normalize();
    w.display();
    u = cross(up, w);
    u.normalize();
    u.display();
    v = cross(w, u);
    v.normalize();
    v.display();
}
