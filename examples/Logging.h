#ifndef _example_logging_h_
#define _example_logging_h_

#include <iostream>

#define LOG_ERROR(text) \
   std::cerr << text << std::endl;

#define LOG_WARNING(text) \
   std::cerr << text << std::endl;

#endif  // _example_logging_h_
