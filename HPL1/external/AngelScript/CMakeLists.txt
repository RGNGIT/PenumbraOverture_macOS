cmake_minimum_required (VERSION 3.5)
project (AngelScript)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(AngelScript STATIC
  source/as_anyobject.cpp
  source/as_arrayobject.cpp
  source/as_builder.cpp
  source/as_bytecode.cpp
  source/as_callfunc.cpp
  source/as_callfunc_x86.cpp
  source/as_callfunc_arm64_gcc.cpp
  source/as_compiler.cpp
  source/as_configgroup.cpp
  source/as_context.cpp
  source/as_datatype.cpp
  source/as_gcobject.cpp
  source/as_generic.cpp
  source/as_module.cpp
  source/as_objecttype.cpp
  source/as_outputbuffer.cpp
  source/as_parser.cpp
  source/as_restore.cpp
  source/as_scriptcode.cpp
  source/as_scriptengine.cpp
  source/as_scriptfunction.cpp
  source/as_scriptnode.cpp
  source/as_scriptstruct.cpp
  source/as_string.cpp
  source/as_string_util.cpp
  source/as_thread.cpp
  source/as_tokenizer.cpp
  source/as_typeinfo.cpp
  source/as_variablescope.cpp
)

target_include_directories(AngelScript PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
