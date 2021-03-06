#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <GL/glew.h>
#include "global.h"
#include "cube.h"

using namespace glm;

void Cube::setup()
{
	setupVertices();
	setupVAO();
}

void Cube::renderWireframe()
{
	glDrawArrays(GL_LINES, 0, 6 * 4);
}

void Cube::render()
{
	for (int i = 0; i < 6; i++)
		glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4);
}

btRigidBody *Cube::createRigidBody(btScalar mass, btVector3 scale, btTransform t)
{
	btCollisionShape* fallshape = new btBoxShape(scale);
	btDefaultMotionState* fallMotionState = new btDefaultMotionState(t);
	btVector3 fallInertia(0,0,0);
	fallshape->calculateLocalInertia(mass,fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallshape, fallInertia);
	btRigidBody* fallRigidBody = new btRigidBody(fallRigidBodyCI);
	return fallRigidBody;
}

void Cube::setupVertices()
{
	const vec3 vertices[6][4] = {
		// Front
		{vec3(1.f, 1.f, 1.f), vec3(-1.f, 1.f, 1.f), vec3(-1.f, -1.f, 1.f), vec3(1.f, -1.f, 1.f),},
		// Up
		{vec3(1.f, 1.f, 1.f), vec3(1.f, 1.f, -1.f), vec3(-1.f, 1.f, -1.f), vec3(-1.f, 1.f, 1.f),},
		// Right
		{vec3(1.f, 1.f, 1.f), vec3(1.f, -1.f, 1.f), vec3(1.f, -1.f, -1.f), vec3(1.f, 1.f, -1.f),},
		// Back
		{vec3(-1.f, 1.f, -1.f), vec3(1.f, 1.f, -1.f), vec3(1.f, -1.f, -1.f), vec3(-1.f, -1.f, -1.f),},
		// Down
		{vec3(-1.f, -1.f, 1.f), vec3(-1.f, -1.f, -1.f), vec3(1.f, -1.f, -1.f), vec3(1.f, -1.f, 1.f),},
		// Left
		{vec3(-1.f, -1.f, 1.f), vec3(-1.f, 1.f, 1.f), vec3(-1.f, 1.f, -1.f), vec3(-1.f, -1.f, -1.f),},
	};
	const vec3 normals[6] = {
		vec3(0.f, 0.f, 1.f),
		vec3(0.f, 1.f, 0.f),
		vec3(1.f, 0.f, 0.f),
		vec3(0.f, 0.f, -1.f),
		vec3(0.f, -1.f, 0.f),
		vec3(-1.f, 0.f, 0.f),
	};
	const vec2 texCoords[4] = {
		vec2(1.f, 1.f), vec2(0.f, 1.f), vec2(0.f, 0.f), vec2(1.f, 0.f),
	};
	for (int i = 0; i != 6; i++) {
		for (int j = 0; j != 4; j++) {
			this->vertices.push_back(vertices[i][j]);
			this->normals.push_back(normals[i]);
			this->texCoords.push_back(texCoords[j]);
		}
	}
}
