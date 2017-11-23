/*
 * engine.h
 *
 *  Created on: Nov 23, 2017
 *      Author: efarhan
 */

#ifndef INCLUDE_ENGINE_H_
#define INCLUDE_ENGINE_H_

#include <iostream>

struct Vector
{
	float x = 0.0f;
	float y = 0.0f;
};

struct Transform
{

	Vector position;
	float angle;

	void print()
	{
		std::cout << "Position: "<<position.x<<", "<<position.y<<"\n"
				<<"Angle: "<<angle<<"\n\n";
	}
};



#endif /* INCLUDE_ENGINE_H_ */
