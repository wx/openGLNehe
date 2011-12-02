set(inc_path ${project_inc_path})
set(lib_path ${project_lib_path} )

file(GLOB app_src
${sin_root}/app/src/*.cpp
)
file(GLOB main_src "src/*.cpp")

set(src_list
${app_src}
${main_src}
)

 
set(p_name lesson01)
include_directories(${inc_path} ./include)
link_directories(${lib_path})
#add_library(${libname} SHARED ${src_list})
#add_library(${libname} STATIC ${src_list})
add_executable(${p_name} ${src_list})
#set_target_properties(${PName} PROPERTIES SOVERSION ${PVersion})
target_link_libraries(${p_name} -lGL -lGLU -lX11)


#set(stage $ENV{HOME}/app)

#set(INSTALL_ARCHIVE_DIR ${stage}/priv)
#set(INSTALL_PROGRAM_DIR ${stage}/priv)
#set(INSTALL_LIBRARY_DIR ${stage}/priv)

#set(base_root ${stage}/../corgi_server/corgi_base)
#set(stage ${default_path})
set(INSTALL_ARCHIVE_DIR ${stage}/lib)
set(INSTALL_PROGRAM_DIR ${stage}/bin)
set(INSTALL_LIBRARY_DIR ${stage}/lib)

#install(TARGETS ${PName}  LIBRARY DESTINATION
#            ${INSTALL_LIBRARY_DIR}
#        ARCHIVE DESTINATION
#            ${INSTALL_ARCHIVE_DIR})
            
install(TARGETS ${p_name}  RUNTIME DESTINATION
            ${INSTALL_LIBRARY_DIR}
        ARCHIVE DESTINATION
            ${INSTALL_ARCHIVE_DIR})            
