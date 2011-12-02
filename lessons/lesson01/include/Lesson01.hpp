/*
 * Lesson01.hpp
 *
 *  Created on: 2011-12-2
 *      Author: xin
 */

#ifndef LESSON01_HPP_
#define LESSON01_HPP_
#include <AppMain.hpp>

namespace Nehe {

class Lesson01:public AppMain {
public:
	Lesson01();
	virtual ~Lesson01();

protected:
	virtual void draw();
};

} /* namespace Nehe */
#endif /* LESSON01_HPP_ */
