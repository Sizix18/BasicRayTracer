/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
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
 * $Id: Scene.cpp 4419 2013-09-12 04:16:46Z mshafae $
 *
 */

#include "Scene.h"
#include <string>
#include <cmath>

Scene::Scene( string inputFilename, string outputFilename, string depthFilename ) :
	myInputSceneFile( inputFilename ),
	myOutputFile( outputFilename ),
	myDepthFile( depthFilename ),
	myCamera( ),
	myBackgroundColor( 0.0, 0.0, 0.0 ),
	lineNumber(0),
	tokenCount(0),
	length(0),
	i(0),
	j(0)
{
	myNumberOfMaterials = -1;
	materials = NULL;
	myCurrentMaterial = NULL;
	//objects = NULL;
}

Scene::~Scene( ){
	// Nothing to free.
}

Camera& Scene::camera( ){
	return( myCamera );
}
ViewPlane& Scene::viewPlane( ){
    return( myViewPlane);
}


Pixel Scene::backgroundColor( ){
	return( myBackgroundColor );
}

int Scene::numberOfMaterials( ){
	return( myNumberOfMaterials );
}

void Scene::setCurrentMaterial( int i ){
	if( i >= myNumberOfMaterials ){
	  throw( "Index out of range" );	
	}else{
		myCurrentMaterial = materials[i];
	}
}

Material* Scene::currentMaterial( ){
	return( myCurrentMaterial );
}

std::vector<Object*> Scene::group( ){
	return( objects );
}

string& Scene::inputSceneFile( ){
	return( myInputSceneFile );
}

string& Scene::outputFile( ){
	return( myOutputFile );
}

string& Scene::depthFile( ){
	return( myDepthFile );
}

bool Scene::hasInputSceneFilePath( void ){
	bool ret = true;
	if( myInputSceneFile == "" ){
		ret = false;
	}
	return( ret );
}

bool Scene::hasOutputFilePath( void ){
	bool ret = true;
	if( myOutputFile == "" ){
		ret = false;
	}
	return( ret );
}

bool Scene::hasDepthFilePath( void ){
	bool ret = true;
	if( myDepthFile == "" ){
		ret = false;
	}
	return( ret );
}


void Scene::setInputSceneFile( string file ){
	myInputSceneFile = file;
}

void Scene::setOutputFile( string file ){
	myOutputFile = file;
}

void Scene::setDepthFile( string file ){
	myDepthFile = file;
}

float Scene::parseFloat( ){
	float ret = (float)atof( currentToken );
	return( ret );
}

double Scene::parseDouble( ){
	double ret = (double)atof( currentToken );
	return( ret );
}

int Scene::parseInt( ){
	int ret = atoi( currentToken );
	return( ret );
}

void Scene::checkToken( const char *str, const char *stage  ){
	if( strcmp( currentToken, str ) != 0 ){
		cerr << stage << " parse error at line " << lineNumber << " token " << tokenCount << ": " << currentToken << endl;
		cerr << "Current line: " << currentLine << endl;
		cerr << "Expected \'" << str << "\'" << endl;
		exit( 1 );
	}
}

void Scene::parseCamera( ){
  nextToken( );
  if( strcmp(currentToken, "OrthographicCamera") == 0 ){
    parseOrthographicCamera( );
  }else if( strcmp(currentToken, "PerspectiveCamera") == 0 ){
    // add me
  }else if( strcmp(currentToken, "SimplePerspectiveCamera") == 0 ){
    // add me
  }else{
  	checkToken( "OrthographicCamera | PerspectiveCamera | SimplePerspectiveCamera", "Camera" );
  }
}

void Scene::parseOrthographicCamera( ){
	// You will need to adjust this so that the result 
	// from parseFloat is stored somewhere meaningful.
    //DONE
	float vec[3];
	checkToken( "OrthographicCamera", "Camera" );
	nextToken( );
	checkToken( "{", "Camera" );
	nextToken( );
	checkToken( "center", "Camera" );
	for( int i = 0; i < 3; i++ ){
		nextToken( );
		vec[i] = parseFloat( );
	}
    myCamera.center.x(vec[0]);
    myCamera.center.y(vec[1]);
    myCamera.center.z(vec[2]);
	nextToken( );
	checkToken( "direction", "Camera" );
	for( int i = 0; i < 3; i++ ){
		nextToken( );
		vec[i] = parseFloat( );
	}
    myCamera.direction.x(vec[0]);
    myCamera.direction.y(vec[1]);
    myCamera.direction.z(vec[2]);
	nextToken( );
	checkToken( "up", "Camera" );
	for( int i = 0; i < 3; i++ ){
		nextToken( );
		vec[i] = parseFloat( );
	}
    myCamera.up.x(vec[0]);
    myCamera.up.y(vec[1]);
    myCamera.up.z(vec[2]);
    myCamera.gaze = (myCamera.center - myCamera.direction);
    myCamera.right = (cross(myCamera.gaze, myCamera.up));
	nextToken( );
	checkToken( "}", "Camera" );
}

void Scene::parseViewPlane( ){
	// You will need to adjust this so that the result 
	// from parseFloat is stored somewhere meaningful.
    //DONE
	float val;
	nextToken( );
	checkToken( "ViewPlane", "ViewPlane" );
	nextToken( );
	checkToken( "{", "ViewPlane" );
	nextToken( );
	checkToken( "width", "ViewPlane" );
	nextToken( );
	val = parseFloat( );
    myViewPlane.width = val;

	nextToken( );
	checkToken( "height", "ViewPlane" );
	nextToken( );
	val = parseFloat( );
    myViewPlane.height = val;

	nextToken( );
	checkToken( "pixelsize", "ViewPlane" );
	nextToken( );
	val = parseFloat( );
    myViewPlane.pixelsize = val;
	
	nextToken( );
	checkToken( "}", "ViewPlane" );
}

void Scene::parseBackground( ){
	// You will need to adjust this so that the result 
	// from parseFloat is stored somewhere meaningful.
	//DONE
	float vec[3];
	nextToken( );
	checkToken( "Background", "Background" );
	nextToken( );
	checkToken( "{", "Background" );
	
	nextToken( );
	checkToken( "color", "Background" );
	for( int i = 0; i < 3; i++ ){
		nextToken( );
		vec[i] = parseFloat( );
	}
	myBackgroundColor.r = vec[0];
    myBackgroundColor.b = vec[1];
    myBackgroundColor.g = vec[2];
	nextToken( );
	checkToken( "}", "Background" );
}

void Scene::parseMaterials( ){
	//cerr << "materials not implemented" << endl;
    int numMaterials;
    double vec[3];
    nextToken();
    checkToken("Materials", "Materials");
    nextToken( );
    checkToken("{", "Materials");
    nextToken( );
    checkToken("numMaterials", "Materials");
    nextToken();
    numMaterials = parseInt( );
    myNumberOfMaterials = numMaterials;
    materials = new Material*[numMaterials];
    for (int i= 0; i<numMaterials; i++) {
        nextToken();
        checkToken("PhongMaterial", "PhongMaterial");
        nextToken();
        checkToken("{", "PhongMaterial");
        nextToken();
        checkToken("diffuseColor", "PhongMaterial");
        for (int j = 0; j<3; j++) {
            nextToken();
            vec[j] = parseInt();
        }
        
        materials[i] = new Material(vec[0],vec[1],vec[2]);
        
        nextToken();
        checkToken("}", "PhongMaterial");
    }
    nextToken();
    checkToken("}", "Materials");
    
}

void Scene::parseGroup( ){
	//cerr << "group not implemented" << endl;
    //DONE
    int numObjects;
    int matIndex;
    double center[3];
    double radius;
    
    nextToken();
    checkToken("Group", "Group");
    nextToken();
    checkToken("{", "Group");
    nextToken();
    checkToken("numObjects", "Group");
    nextToken();
    numObjects = parseInt();
    //myGroup = new Group();
    for (int i = 0; i < numObjects; i++) {
        nextToken();
        checkToken("MaterialIndex", "Group");
        nextToken();
        matIndex = parseInt();
        nextToken();
        checkToken("Sphere", "Sphere");
        nextToken();
        checkToken("{", "Sphere");
        nextToken();
        checkToken("center", "Sphere");
        for (int j = 0; j<3; j++) {
            nextToken();
            center[j] = parseDouble( );
        }
        nextToken();
        checkToken("radius", "Sphere");
        nextToken();
        radius = parseDouble();
        nextToken();
        checkToken("}", "Sphere");
        Sphere *addSphere = NULL;
        objects.push_back(addSphere);
        
        objects[i] = new Sphere(center[0],center[1],center[2],radius);
        objects[i]->material = materials[matIndex]->diffuseColor;
        //addSphere->material = materials[matIndex]->diffuseColor;
        //objects.push_back(addSphere);
    }
    
}


bool Scene::parse( ){	
	bool ret = true;
	lineNumber = 0;
	tokenCount = 0;
	
	inputFileStream.open( myInputSceneFile.c_str( ), ios::in );
	if( inputFileStream.fail( ) ){
		cerr << "Error opening \"" << myInputSceneFile << "\" for reading." << endl;
		exit( 1 );
	}
	parseCamera( );
    parseViewPlane( );
	parseBackground( );
	parseMaterials( );
	parseGroup( );

	inputFileStream.close( );
	
	return( ret );
}

bool Scene::areMoreTokens( ){
	bool ret = false;
	if( j < length ){
		ret = true;
	}
	return( ret );
}

void Scene::advance( ){
	if( currentLine[j] == ' ' || currentLine[j] == '\t' || currentLine[j] == '\n' ){
		while( currentLine[j] == ' ' || currentLine[j] == '\t' || currentLine[j] == '\n' ){
			j++;
		}
		i = j;
	}
}
void Scene::nextOnLine( ){
	//advance( );
	while( currentLine[j] != ' ' && currentLine[j] != '\t' && currentLine[j] != '\n' && currentLine[j] != 0 ){
		j++;
	}
	//cout << "ending: " << i <<  ", " << j << endl;
	currentLine[j] = 0;
	int tmp = i;
	if( i != j ){
		while( i <= j ){
			currentToken[i - tmp] = currentLine[i];
			//cout << "copying: " << (i - tmp) <<  ", " << i << endl;
			i++;
		}
		//cerr << lineNumber << ": " << ++tokenCount << ": '" << currentToken << "'" << endl;
	}
	j++;
	i = j;
}

void Scene::nextToken( ){
	if( !inputFileStream.eof( ) ){
		advance( );
		if( areMoreTokens( ) ){
			nextOnLine( );
		}else{
			do{
				inputFileStream.getline( currentLine, sizeof(currentLine) );
				lineNumber++;
				length = strlen( currentLine );
				//cerr << "new line of length: " << length << endl;
			}while( length <= 0 );
			i = 0;
			j = 0;
			advance( );
			//cerr << "Line: " << currentLine << endl;
			if( areMoreTokens( ) ){
				nextOnLine( );
			}
		}
	}
}

Pixel Scene::Shader(Object &o, Vec3 &light, Hit &hitRecord, Vec3 normal )
{
    double result = normal.dot(light);
    if (result < 0){
        result = 0;
    }
    else if (result > 1){
        result = 1;
    }
    Vec3 shade;
    shade.x(hitRecord.objectMaterial->diffuseColor.x() * result);
    shade.y(hitRecord.objectMaterial->diffuseColor.y() * result);
    shade.z(hitRecord.objectMaterial->diffuseColor.z() * result);
    //shade.x(1 * result);
    //shade.y(1 * result);
    //shade.z(1 * result);
    shade = (shade * 255);
    Pixel p((int)round(shade.x()), (int)round(shade.y()), (int)round(shade.z()));
    
    return(p);
}

void Scene::write( std::ostream &out ) const {
	out << "Input scene file: " << myInputSceneFile << endl;
	out << "Output file: " << myOutputFile << endl;
	out << "Depth file: " << myDepthFile << endl;
	out << "Camera:" << endl;
	// not implemented yet out << myCamera << endl;
	out << "Background Color: " << myBackgroundColor << endl;
	out << "Number of Materials: " << myNumberOfMaterials << endl;
	out << "Materials:" << endl;
	// not implemented yet copy(materials[0], materials[myNumberOfMaterials], ostream_iterator<Material>(out, "\n" );
	out << "Group:" << endl;
	// not implemented yet out << myGroup << endl;
}

std::ostream& operator <<( std::ostream &out, const Scene &s ){
	s.write( out );
	return( out );
}
