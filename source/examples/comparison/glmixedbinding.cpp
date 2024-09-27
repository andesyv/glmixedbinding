
#include "glmixedbinding.h"

#include <iostream>

#include <GLFW/glfw3.h>

#include <glmixedbinding/gl/gl.h>

#include <glmixedbinding/AbstractFunction.h>

#include <glmixedbinding-aux/types_to_string.h>

#include <glmixedbinding/Binding.h>

#include <glmixedbinding/CallbackMask.h>

#include <glmixedbinding/FunctionCall.h>


using namespace gl;

namespace
{
    #include "gltest_data.inl"
}


void glmixedbinding_init()
{
    glmixedbinding::Binding::initialize([](const char * name) {
        return glfwGetProcAddress(name);
    }, false);
}


void glmixedbinding_test()
{
    #include "gltest.inl"
}


void glmixedbinding_error(bool enable)
{
    if (enable)
    {
        glmixedbinding::Binding::setCallbackMaskExcept(glmixedbinding::CallbackMask::After, { "glGetError" });

        glmixedbinding::Binding::setAfterCallback([](const glmixedbinding::FunctionCall &)
        {
            gl::GLenum error = gl::glGetError();
            if (error != gl::GL_NO_ERROR)
                std::cout << "Error: " << error << std::endl;
        });
    }
    else
        glmixedbinding::Binding::setCallbackMask(glmixedbinding::CallbackMask::None);
}
