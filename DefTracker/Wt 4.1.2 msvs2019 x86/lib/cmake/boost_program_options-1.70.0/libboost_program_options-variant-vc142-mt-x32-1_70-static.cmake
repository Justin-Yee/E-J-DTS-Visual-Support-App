# Generated by Boost 1.70.0

# address-model=32

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  _BOOST_SKIPPED("libboost_program_options-vc142-mt-x32-1_70.lib" "32 bit, need 64")
  return()
endif()

# layout=versioned

# toolset=vc142

if(Boost_COMPILER AND NOT Boost_COMPILER STREQUAL "vc142")
  _BOOST_SKIPPED("libboost_program_options-vc142-mt-x32-1_70.lib" "vc142, Boost_COMPILER=${Boost_COMPILER}")
  return()
endif()

if(BOOST_DETECTED_TOOLSET AND NOT BOOST_DETECTED_TOOLSET STREQUAL "vc142")
  _BOOST_SKIPPED("libboost_program_options-vc142-mt-x32-1_70.lib" "vc142, detected ${BOOST_DETECTED_TOOLSET}, set Boost_COMPILER to override")
  return()
endif()

# link=static

if(NOT "${Boost_USE_STATIC_LIBS}" STREQUAL "" AND NOT Boost_USE_STATIC_LIBS)
  _BOOST_SKIPPED("libboost_program_options-vc142-mt-x32-1_70.lib" "static, Boost_USE_STATIC_LIBS=${Boost_USE_STATIC_LIBS}")
  return()
endif()

if(BUILD_SHARED_LIBS AND NOT Boost_USE_STATIC_LIBS)
  _BOOST_SKIPPED("libboost_program_options-vc142-mt-x32-1_70.lib" "static, BUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}, set Boost_USE_STATIC_LIBS=ON to override")
  return()
endif()

# runtime-link=shared

if(Boost_USE_STATIC_RUNTIME)
  _BOOST_SKIPPED("libboost_program_options-vc142-mt-x32-1_70.lib" "shared runtime, Boost_USE_STATIC_RUNTIME=${Boost_USE_STATIC_RUNTIME}")
  return()
endif()

# runtime-debugging=off

if(Boost_USE_DEBUG_RUNTIME)
  _BOOST_SKIPPED("libboost_program_options-vc142-mt-x32-1_70.lib" "release runtime, Boost_USE_DEBUG_RUNTIME=${Boost_USE_DEBUG_RUNTIME}")
  return()
endif()

# threading=multi

# variant=release

if(NOT "${Boost_USE_RELEASE_LIBS}" STREQUAL "" AND NOT Boost_USE_RELEASE_LIBS)
  _BOOST_SKIPPED("libboost_program_options-vc142-mt-x32-1_70.lib" "release, Boost_USE_RELEASE_LIBS=${Boost_USE_RELEASE_LIBS}")
  return()
endif()

message(STATUS "  libboost_program_options-vc142-mt-x32-1_70.lib")

# Target file name: libboost_program_options-vc142-mt-x32-1_70.lib
set_property(TARGET Boost::program_options APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Boost::program_options PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE CXX
  IMPORTED_LOCATION_RELEASE "${_BOOST_LIBDIR}/libboost_program_options-vc142-mt-x32-1_70.lib"
  )

list(APPEND _BOOST_PROGRAM_OPTIONS_DEPS headers)
