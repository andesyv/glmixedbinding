
#pragma once


#include <glmixedbinding/glmixedbinding_api.h>

#include <glmixedbinding/ProcAddress.h>


namespace glmixedbinding
{


/**
*  @brief
*    Default getProcAddress implementation using libdl (Unix) and LoadLibrary (Windows).
*
*  @param[in] name
*    The name of the OpenGL function
*
*  @return
*    The resolved function pointer
*
*  @remark
*    Using glmixedbinding::getProcAddress is provided for convenience only. Please don't use this in new code.
*    Instead, use an external function resolution callback, e.g.,
*     * eglGetProcAddress
*     * wglGetProcAddress
*     * glxGetProcAddress
*     * glfwGetProcAddress
*     * QOpenGlContext::getProcAddress
*     * reinterpret_cast<glbinding::ProcAddress(*)(const char*)>(SDL_GL_GetProcAddress)
*/
GLMIXEDBINDING_API ProcAddress getProcAddress(const char * name);


} // namespace glmixedbinding
