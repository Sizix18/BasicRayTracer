//
//  Material.cpp
//  raytracer
//
//  Created by Admin on 9/22/13.
//  Copyright (c) 2013 Jeff Einspahr. All rights reserved.
//

#include "Material.h"

Material::Material( )
 :diffuseColor(0.0,0.0,0.0)
{}

Material::Material(double a, double b, double c)
:diffuseColor(a,b,c)
{}
Material::Material(Vec3 color)
:diffuseColor(color)
{}

Material::~Material()
{}