
#pragma once


#include <functional>

#include <glmixedbinding/glmixedbinding_api.h>


namespace glmixedbinding
{


/**
*  @brief
*    The generic pointer to a function
*/
using ProcAddress = void(*)();

/**
*  @brief
*    The signature for the getProcAddress function
*/
using GetProcAddress = std::function<ProcAddress(const char*)>;


} // namespace glmixedbinding