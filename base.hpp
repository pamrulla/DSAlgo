//Must Include in every file
#pragma once

#include <iostream>

#ifdef _DSALGO_DLL
#define _DSALGO_API __declspec(dllexport)
#else
#define _DSALGO_API __declspec(dllimport)
#endif
