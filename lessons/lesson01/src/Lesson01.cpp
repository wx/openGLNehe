/*
 * Lesson01.cpp
 *
 *  Created on: 2011-12-2
 *      Author: xin
 */

#include "lesson01/include/Lesson01.hpp"

namespace Nehe {

Lesson01::Lesson01() {
	// TODO Auto-generated constructor stub

}

Lesson01::~Lesson01() {
	// TODO Auto-generated destructor stub
}

void Lesson01::draw() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1., 1., -1., 1., 1., 20.);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);

	glBegin(GL_QUADS);
	glColor3f(1., 0., 0.);
	glVertex3f(-.75, -.75, 0.);
	glColor3f(0., 1., 0.);
	glVertex3f(.75, -.75, 0.);
	glColor3f(0., 0., 1.);
	glVertex3f(.75, .75, 0.);
	glColor3f(1., 1., 0.);
	glVertex3f(-.75, .75, 0.);
	glEnd();
}

} /* namespace Nehe */
