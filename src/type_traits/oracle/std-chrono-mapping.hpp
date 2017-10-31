#ifndef STD_CHRONO_SYSTEM_CLOCK_TIME_POINT_MAPPING_HXX
#define STD_CHRONO_SYSTEM_CLOCK_TIME_POINT_MAPPING_HXX

#include <chrono>

#pragma db value(std::chrono::system_clock::time_point) type("DATE")
#pragma db value(std::chrono::high_resolution_clock::time_point) type("TIMESTAMP")

#endif
