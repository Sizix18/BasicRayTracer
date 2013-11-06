//
//  Ray.cpp
//  raytracer
//
//  Created by Admin on 9/19/13.
//  Copyright (c) 2013 Jeff Einspahr. All rights reserved.
//

#include "Ray.h"

Ray::Ray( )
{
    
}

Ray::Ray(Vec3 &origin, Vec3 &dir)
:o(origin), d(dir)
{}

Ray::~Ray()
{
}
