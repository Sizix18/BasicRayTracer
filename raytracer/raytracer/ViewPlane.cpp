//
//  viewPlane.cpp
//  raytracer
//
//  Created by Admin on 9/18/13.
//  Copyright (c) 2013 Jeff Einspahr. All rights reserved.
//

#include "ViewPlane.h"
ViewPlane::ViewPlane( )
:width(0),height(0),pixelsize(0.0)
{}

ViewPlane::ViewPlane(double w, double h, double p)
:width(w), height(h), pixelsize(p)
{}

ViewPlane::~ViewPlane()
{}