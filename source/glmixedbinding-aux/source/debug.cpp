
#include <glmixedbinding-aux/debug.h>

#include <iostream>

#include <glmixedbinding/glmixedbinding.h>
#include <glmixedbinding/Binding.h>
#include <glmixedbinding/glmixed/glmixed.h>
#include <glmixedbinding/FunctionCall.h>


namespace
{


// Don't rely on Meta.h for now
std::string readableErrorCode(glmixed::GLenum errorCode)
{
    switch(errorCode)
    {
    case glmixed::GL_NO_ERROR:
        return "GL_NO_ERROR";
    case glmixed::GL_INVALID_ENUM:
        return "GL_INVALID_ENUM";
    case glmixed::GL_INVALID_VALUE:
        return "GL_INVALID_VALUE";
    case glmixed::GL_INVALID_OPERATION:
        return "GL_INVALID_OPERATION";
    case glmixed::GL_INVALID_FRAMEBUFFER_OPERATION:
        return "GL_INVALID_FRAMEBUFFER_OPERATION";
    case glmixed::GL_OUT_OF_MEMORY:
        return "GL_OUT_OF_MEMORY";
    default:
        return "Unknown Error";
    }
}

auto getErrorCallbackRegistered = false;


} // namespace


namespace glmixedbinding { namespace aux
{


void registerGetErrorCallback()
{
    glmixedbinding::setAfterCallback([](const glmixedbinding::FunctionCall & functionCall) {
        const auto errorCode = Binding::GetError.directCall();

        if (errorCode == glmixed::GL_NO_ERROR)
        {
            return;
        }

        std::cerr << functionCall.function->name() << " generated " << readableErrorCode(errorCode);
    });

    getErrorCallbackRegistered = true;
}

void enableGetErrorCallback()
{
    if (!getErrorCallbackRegistered)
    {
        registerGetErrorCallback();
    }

    glmixedbinding::setCallbackMaskExcept(glmixedbinding::CallbackMask::After, { "glGetError" });
}

void disableGetErrorCallback()
{
    glmixedbinding::removeCallbackMaskExcept(glmixedbinding::CallbackMask::After, { "glGetError" });
}


} } // namespace glmixedbinding::aux
