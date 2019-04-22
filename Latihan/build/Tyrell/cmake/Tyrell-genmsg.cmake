# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "Tyrell: 1 messages, 1 services")

set(MSG_I_FLAGS "-ITyrell:/home/tyrell/Latihan/src/Tyrell/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(Tyrell_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg" NAME_WE)
add_custom_target(_Tyrell_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Tyrell" "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg" ""
)

get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv" NAME_WE)
add_custom_target(_Tyrell_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Tyrell" "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Tyrell
)

### Generating Services
_generate_srv_cpp(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Tyrell
)

### Generating Module File
_generate_module_cpp(Tyrell
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Tyrell
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(Tyrell_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(Tyrell_generate_messages Tyrell_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg" NAME_WE)
add_dependencies(Tyrell_generate_messages_cpp _Tyrell_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv" NAME_WE)
add_dependencies(Tyrell_generate_messages_cpp _Tyrell_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Tyrell_gencpp)
add_dependencies(Tyrell_gencpp Tyrell_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Tyrell_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Tyrell
)

### Generating Services
_generate_srv_eus(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Tyrell
)

### Generating Module File
_generate_module_eus(Tyrell
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Tyrell
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(Tyrell_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(Tyrell_generate_messages Tyrell_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg" NAME_WE)
add_dependencies(Tyrell_generate_messages_eus _Tyrell_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv" NAME_WE)
add_dependencies(Tyrell_generate_messages_eus _Tyrell_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Tyrell_geneus)
add_dependencies(Tyrell_geneus Tyrell_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Tyrell_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Tyrell
)

### Generating Services
_generate_srv_lisp(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Tyrell
)

### Generating Module File
_generate_module_lisp(Tyrell
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Tyrell
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(Tyrell_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(Tyrell_generate_messages Tyrell_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg" NAME_WE)
add_dependencies(Tyrell_generate_messages_lisp _Tyrell_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv" NAME_WE)
add_dependencies(Tyrell_generate_messages_lisp _Tyrell_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Tyrell_genlisp)
add_dependencies(Tyrell_genlisp Tyrell_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Tyrell_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Tyrell
)

### Generating Services
_generate_srv_nodejs(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Tyrell
)

### Generating Module File
_generate_module_nodejs(Tyrell
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Tyrell
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(Tyrell_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(Tyrell_generate_messages Tyrell_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg" NAME_WE)
add_dependencies(Tyrell_generate_messages_nodejs _Tyrell_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv" NAME_WE)
add_dependencies(Tyrell_generate_messages_nodejs _Tyrell_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Tyrell_gennodejs)
add_dependencies(Tyrell_gennodejs Tyrell_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Tyrell_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Tyrell
)

### Generating Services
_generate_srv_py(Tyrell
  "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Tyrell
)

### Generating Module File
_generate_module_py(Tyrell
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Tyrell
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(Tyrell_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(Tyrell_generate_messages Tyrell_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/msg/demo_msg.msg" NAME_WE)
add_dependencies(Tyrell_generate_messages_py _Tyrell_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/tyrell/Latihan/src/Tyrell/srv/demo_srv.srv" NAME_WE)
add_dependencies(Tyrell_generate_messages_py _Tyrell_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Tyrell_genpy)
add_dependencies(Tyrell_genpy Tyrell_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Tyrell_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Tyrell)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Tyrell
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(Tyrell_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Tyrell)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Tyrell
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(Tyrell_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Tyrell)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Tyrell
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(Tyrell_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Tyrell)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Tyrell
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(Tyrell_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Tyrell)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Tyrell\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Tyrell
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(Tyrell_generate_messages_py std_msgs_generate_messages_py)
endif()
