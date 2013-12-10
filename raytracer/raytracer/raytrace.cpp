/* Your Name Here
 * somebody at something dot TLD
 * CS 484
 * September 2008
 *
 */
/*
 * Copyright (c) 2005-2013 Michael Shafae
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * $Id: raytrace.cpp 4419 2013-09-12 04:16:46Z mshafae $
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "getopt.h"
#include "Scene.h"

bool tValueCmp(Hit a, Hit b)
{
    return (a.t < b.t);
}

void rayFactory(std::vector<Ray*> &rays, Camera &c, ViewPlane &v)
{
    for (double i = ((v.height/2)-(v.pixelsize/2)); i >= (((v.height/2) * -1)); i -= v.pixelsize) {
        for (double j = (((v.width/2) * -1)+(v.pixelsize/2)); j <=((v.width/2)); j += v.pixelsize) {
            Vec3 rayOrigin(j,i, c.center.z());
            Ray *addRay = new Ray(rayOrigin, c.direction);
            rays.push_back(addRay);
        }
    }
}
int depthClamp(double t)
{
    int x;
    x = (int)(round(t * 255));
    if (x < 0){
        x = 0;
    }
    else if (x > 255){
        x = 255;
    }
    return x;
}

Scene *gTheScene;
string gProgramName;

void usage( string message = "" ){
	cerr << message << endl;
	cerr << gProgramName << " -i <inputfile> -o <outputfile> -d <depthfile>" << endl;
	cerr << "          -or-" << endl;
	cerr << gProgramName << " --input <inputfile> --output <outputfile> --depth <depthfile>" << endl;
	
}

void parseCommandLine( int argc, char **argv ){
	int ch;
	string inputFile( "" ), outputFile( "" ), depthFile( "" );
  int resolution;
	static struct option longopts[] = {
    { "input", required_argument, NULL, 'i' },
    { "output", required_argument, NULL, 'o' },
    { "depth", required_argument, NULL, 'd' },
    { "resolution", required_argument, NULL, 'r' },
    { "verbose", required_argument, NULL, 'v' },
    { "help", required_argument, NULL, 'h' },
    { NULL, 0, NULL, 0 }
	};

	while( (ch = getopt_long(argc, argv, "i:o:d:r:vh", longopts, NULL)) != -1 ){
		switch( ch ){
			case 'i':
				// input file
				inputFile = string(optarg);
				break;
			case 'o':
				// image output file
				outputFile = string(optarg);
				break;
			case 'd':
				// depth output file
				depthFile = string( optarg );
				break;
			case 'r':
        resolution = atoi(optarg);
        break;
      case 'v':
        // set your flag here.
        break;
      case 'h':
        usage( );
        break;
			default:
				// do nothing
				break;
		}
	}
	gTheScene = new Scene( inputFile, outputFile, depthFile );
}

int main( int argc, char **argv ){
	string pathStr;
	gProgramName = argv[0];
    
	parseCommandLine( argc, argv );
	argc -= optind;
	argv += optind;
	if( gTheScene->hasInputSceneFilePath( ) &&
			gTheScene->hasOutputFilePath( ) &&
			gTheScene->hasDepthFilePath( ) ){
		gTheScene->parse( );	
		cout << *gTheScene << endl;	
	}else{
		usage( "You specify an input scene file, an output file and a depth file." );
        exit(1);
	}
    //color image with lighting
    Image image((int)(round(gTheScene->viewPlane().width/gTheScene->viewPlane().pixelsize)), (int)(round)((gTheScene->viewPlane().height/gTheScene->viewPlane().pixelsize)));
    //depth image with gray scale and no lighting
    Image depthImage(((int)(round((gTheScene->viewPlane().width/gTheScene->viewPlane().pixelsize)))), ((int)(round)((gTheScene->viewPlane().height/gTheScene->viewPlane().pixelsize))));
    
    int depthColor;
    
    //create a vector to store all of the rays
    std::vector<Ray*> listOfRays;
    
    //fill the list of rays depending on the pixelSize, Height, and Width of the ViewPlane
    rayFactory(listOfRays, gTheScene->camera(), gTheScene->viewPlane());
    
    //create a vector to store all of the hits
    std::vector<Hit*> listOfHits;
    
    //fill it with hits equal to the number of rays
    for (int j = 0; j < listOfRays.size(); ++j) {
        listOfHits.push_back(new Hit());
    }
   
    //Check for intersections with every object in our list of objects
      for (int r = 0; r < listOfRays.size(); ++r) {
        for (int obj = 0; obj < gTheScene->group().size(); ++obj) {
            if(gTheScene->group()[obj]->Intersect(*listOfRays[r], *listOfHits[r])){
            listOfHits[r]->objectNumber = obj;
            }
        }
        
    }
    

    //scale the t values to a range of 0 to 1
    double tMax, tMin = listOfHits[0]->t;
    for (int x = 0; x < listOfHits.size(); ++x) {
        if (tMax < listOfHits[x]->t) {
            tMax = listOfHits[x]->t;
        }
        if (tMin > listOfHits[x]->t) {
            tMin = listOfHits[x]->t;

        }
    }
    //For each hit we calculate the light being reflected
    for (int h = 0; h < listOfHits.size(); ++h) {
        listOfHits[h]->t /= (tMax-tMin);
        
        //if there is an intersection set the pixel color accordingly
        if (listOfHits[h]->t > 0.0) {
            depthColor = depthClamp(listOfHits[h]->t);
            Vec3 light = (gTheScene->camera().center - listOfHits[h]->hit);
            light.normalize();
            //Shader(<#Object &o#>, <#Vec3 &light#>, <#Hit &hitRecord#>, <#Vec3 normal#>)
            //cout << listOfHits[h]->objectNumber <<endl;
            image.pixels[h] = gTheScene->Shader(*gTheScene->group()[listOfHits[h]->objectNumber],
                                                light,
                                                gTheScene->group()[listOfHits[h]->objectNumber]->normal(*listOfHits[h]));
            depthImage.pixels[h] = Pixel(depthColor,depthColor,depthColor);
        }
        else {
            //otherwise set the color to our background color
            image.pixels[h] = gTheScene->backgroundColor();
            depthImage.pixels[h] = Pixel(0.4,.8,0.4);
        }
    }

    image.write(gTheScene->outputFile().c_str());
    depthImage.write(gTheScene->depthFile().c_str());
	return( 0 );
}
