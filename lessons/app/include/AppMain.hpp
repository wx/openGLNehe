/*
 * AppMain.hpp
 *
 *  Created on: 2011-12-2
 *      Author: xin
 */

#ifndef APPMAIN_HPP_
#define APPMAIN_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#include <cstdlib>
#include <algorithm>

namespace Nehe {

class AppMain {
public:
	AppMain();
	virtual ~AppMain();

	void init();
	void run();

protected:
	virtual void draw()=0;
protected:
	Display *_display_ptr;
	Window _root;
	XVisualInfo *_vi_ptr;
	Colormap _cmap;
	XSetWindowAttributes _swa;
	Window _win;
	GLXContext _glc;
	XWindowAttributes _gwa;
	XEvent _xev;
	GLint _att[128];
};

} /* namespace Nehe */
#endif /* APPMAIN_HPP_ */
