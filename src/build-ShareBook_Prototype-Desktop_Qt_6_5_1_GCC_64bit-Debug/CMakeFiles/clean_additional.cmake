# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appShareBook_Prototype_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appShareBook_Prototype_autogen.dir/ParseCache.txt"
  "appShareBook_Prototype_autogen"
  )
endif()
