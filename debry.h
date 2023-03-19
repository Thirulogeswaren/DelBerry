#ifndef DEBRY_PE_H
#define DEBRY_PE_H

#include "vector2.h"
#include "debrymath.h"


#ifdef DEBRY_ENABLE_LOG
#define DEBRY_LOG(build_in_type) std::cout << build_in_type << "\n"
#else
#define DEBRY_LOG(build_in_type) 
#endif

#endif 
