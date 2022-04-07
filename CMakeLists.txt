cmake_minimum_required(VERSION 3.16)

# concepts :)
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

# set the project name
project(FurtherEncapsulationTest)

# find sources here
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -iquote ${PROJECT_SOURCE_DIR}")

# set sources here
set(SOURCES further_encapsulation_test.cpp random_appliances.hpp random_appliances.cpp commander_class.hpp appliance_commanders.hpp appliance_commanders.cpp remote_control.hpp)

# add the executable
add_executable(FurtherEncapsulationTest ${SOURCES})
