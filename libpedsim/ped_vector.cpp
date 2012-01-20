//
// pedsim - A microscopic pedestrian simulation system. 
// Copyright (c) 2003 - 2012 by Christian Gloor
//                              

#include "ped_vector.h"

#include "math.h"

using namespace std;

/// Default constructor, which makes sure that all the values are set to 0.
/// \date    2012-01-16
Ped::Tvector::Tvector() {
	x = 0;
	y = 0;
	z = 0;
}

/// Vector cross product helper: calculates the cross product of two vectors.
/// \date    2010-02-12
/// \todo    This syntax is a bit weird. Will change in future.
/// \warning The result is assigned to the vector calling the method. 
/// \param   *a The first vector
/// \param   *b The second vector
void Ped::Tvector::cross(Ped::Tvector *a, Ped::Tvector *b) {
	this->x = a->y*b->z - a->z*b->y;
	this->y = a->z*b->x - a->x*b->z;
	this->z = a->x*b->y - a->y*b->x;
}


/// Normalizes the vector to a length of 1.
/// \date    2010-02-12
void Ped::Tvector::normalize() {
	double length = sqrt(x*x + y*y + z*z);
	x = x / length;
	y = y / length;
	z = z / length;
}

/// Vector scalar product helper: calculates the scalar product of two vectors.
/// \date    2012-01-14
/// \todo    This syntax is a bit weird. Will change in future.
/// \return  double The scalar product.
/// \param   *a The first vector
/// \param   *b The second vector
double Ped::Tvector::scalar(Ped::Tvector *a, Ped::Tvector *b) {
	return acos( (a->x*b->x + a->y*b->y + a->z*b->z) / ( sqrt(a->x*a->x + a->y*a->y + a->z*a->z) * sqrt(b->x*b->x + b->y*b->y + b->z*b->z) ) );
}