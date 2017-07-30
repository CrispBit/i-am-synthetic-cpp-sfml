# Locate crispsynth
#
# This module defines
#  CRISPSYNTH_FOUND, if false, do not try to link to CrispSynth
#  CRISPSYNTH_LIBRARY, where to find libcrispsynth.a
#  CRISPSYNTH_INCLUDE_DIR, where to find crispsynth
#
# By default, the dynamic libraries of CrispSynth will be found. To find the static ones instead,
# you must set the CRISPSYNTH_STATIC_LIBRARY variable to TRUE before calling find_package(CrispSynth ...).
#
# If CrispSynth is not installed in a standard path, you can use the CRISPSYNTH_DIR CMake variable
# to tell CMake where CrispSynth is.

# attempt to find static library first if this is set
if(CRISPSYNTH_STATIC_LIBRARY)
    set(CRISPSYNTH_STATIC libcrispsynth.a)
endif()

# find the CrispSynth include directory
find_path(CRISPSYNTH_INCLUDE_DIR crispsynth
          PATH_SUFFIXES include
          PATHS
          ~/Library/Frameworks/crispsynth/include/
          /Library/Frameworks/crispsynth/include/
          /usr/local/include/
          /usr/include/
          /sw/crispsynth/         # Fink
          /opt/local/crispsynth/  # DarwinPorts
          /opt/csw/crispsynth/      # Blastwave
          /opt/crispsynth/
          ${CRISPSYNTH_DIR}/include/)

# find the crispsynth library
find_library(CRISPSYNTH_LIBRARY
             NAMES ${CRISPSYNTH_STATIC} crispsynth
             PATH_SUFFIXES lib64 lib
             PATHS ~/Library/Frameworks
                    /Library/Frameworks
                    /usr/local
                    /usr
                    /sw
                    /opt/local
                    /opt/csw
                    /opt
                    ${CRISPSYNTH_DIR}/lib)

# handle the QUIETLY and REQUIRED arguments and set CRISPSYNTH_FOUND to TRUE if all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CRISPSYNTH DEFAULT_MSG CRISPSYNTH_INCLUDE_DIR CRISPSYNTH_LIBRARY)
mark_as_advanced(CRISPSYNTH_INCLUDE_DIR CRISPSYNTH_LIBRARY)
