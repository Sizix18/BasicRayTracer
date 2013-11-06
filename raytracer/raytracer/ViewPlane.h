//
//  viewPlane.h
//  raytracer
//
//  Created by Admin on 9/18/13.
//  Copyright (c) 2013 Jeff Einspahr. All rights reserved.
//

#ifndef raytracer_ViewPlane_h
#define raytracer_ViewPlane_h
class ViewPlane
{
public:
    double width;
    double height;
    double pixelsize;
    ViewPlane();
    ViewPlane(double w, double h, double p);
    ~ViewPlane();
};


#endif
