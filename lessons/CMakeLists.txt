cmake_minimum_required(VERSION 2.8)
project(OpenGLNehe)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "-std=gnu++0x")
#set(corgi_path $ENV{HOME})

set(usr_path
/usr
)
set(usr_local_path
/usr/local
)

set(library_version 0.0.0.1)

set(third_part ${CMAKE_CURRENT_SOURCE_DIR}/../third_part)

set(project_inc_path
${usr_path}/include
${usr_local_path}/include
${CMAKE_CURRENT_SOURCE_DIR}/app/include
${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_CURRENT_SOURCE_DIR}
)

set(project_lib_path
${usr_path}/lib
${usr_local_path}/lib
${CMAKE_CURRENT_SOURCE_DIR}/lib
)

set(sin_root
${CMAKE_CURRENT_SOURCE_DIR}
)

set(stage
${CMAKE_CURRENT_SOURCE_DIR}
)

set(stage ${CMAKE_CURRENT_SOURCE_DIR})

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/Lessons01)
