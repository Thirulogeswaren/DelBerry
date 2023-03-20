#ifndef DEBRY_PE_H
#define DEBRY_PE_H

#include "vector2.h"
#include "debrymath.h"
#include "particle.h"

#ifdef DEBRY_ENABLE_LOG
#include "iostream"
#define DEBRY_LOG(build_in_type) std::cout << build_in_type << "\n"
#else
#define DEBRY_LOG(build_in_type) 
#endif

#endif 
