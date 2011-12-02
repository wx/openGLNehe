/*
 * AppMain.cpp
 *
 *  Created on: 2011-12-2
 *      Author: xin
 */

#include "AppMain.hpp"

namespace Nehe {

AppMain::AppMain() :
		_display_ptr(0), _vi_ptr(0) {
	GLint att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	std::copy(att, att + sizeof(att), _att);
}

AppMain::~AppMain() {
}

void AppMain::init() {
	this->_display_ptr = XOpenDisplay(NULL);

	//	The argument to XOpenDisplay() is NULL.
	//	This means the graphical output will be sent to the computer on which it is executed.
	if (_display_ptr == NULL) {
		printf("\n\tcannot connect to X server\n\n");
		exit(0);
	}

	_root = DefaultRootWindow(_display_ptr);

	_vi_ptr = glXChooseVisual(this->_display_ptr, 0, _att);

	if (_vi_ptr == NULL) {
		printf("\n\tno appropriate visual found\n\n");
		exit(0);
	} else {
		printf("\n\tvisual %p selected\n", (void *) _vi_ptr->visualid);
	} /* %p creates hexadecimal output like in glxinfo */

	_cmap = XCreateColormap(_display_ptr, _root, _vi_ptr->visual, AllocNone);

	_swa.colormap = _cmap;
	_swa.event_mask = ExposureMask | KeyPressMask;

	_win = XCreateWindow(_display_ptr, _root, 0, 0, 600, 600, 0, _vi_ptr->depth,
			InputOutput, _vi_ptr->visual, CWColormap | CWEventMask, &_swa);

	XMapWindow(_display_ptr, _win);

	XStoreName(_display_ptr, _win, "VERY SIMPLE APPLICATION");

	_glc = glXCreateContext(_display_ptr, _vi_ptr, NULL, GL_TRUE);
	glXMakeCurrent(_display_ptr, _win, _glc);

	glEnable(GL_DEPTH_TEST);
}

void AppMain::run() {
	while (1) {
		XNextEvent(_display_ptr, &_xev);

		if (_xev.type == Expose) {
			XGetWindowAttributes(_display_ptr, _win, &_gwa);
			glViewport(0, 0, _gwa.width, _gwa.height);
			this->draw();
			glXSwapBuffers(_display_ptr, _win);
		}

		else if (_xev.type == KeyPress) {
			glXMakeCurrent(_display_ptr, None, NULL);
			glXDestroyContext(_display_ptr, _glc);
			XDestroyWindow(_display_ptr, _win);
			XCloseDisplay(_display_ptr);
			exit(0);
		}
	}
}

} /* namespace Nehe */

