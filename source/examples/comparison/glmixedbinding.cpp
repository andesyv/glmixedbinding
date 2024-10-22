
#include "glmixedbinding.h"

#include <iostream>

#include <GLFW/glfw3.h>

#include <glmixedbinding/glmixed/glmixed.h>

#include <glmixedbinding/AbstractFunction.h>

#include <glmixedbinding-aux/types_to_string.h>

#include <glmixedbinding/Binding.h>

#include <glmixedbinding/CallbackMask.h>

#include <glmixedbinding/FunctionCall.h>


using namespace glmixed;

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
            glmixed::GLenum error = glmixed::glGetError();
            if (error != glmixed::GL_NO_ERROR)
                std::cout << "Error: " << error << std::endl;
        });
    }
    else
        glmixedbinding::Binding::setCallbackMask(glmixedbinding::CallbackMask::None);
}
