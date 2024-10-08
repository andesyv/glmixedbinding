
#include <iostream>
#include <algorithm>
#include <thread>

#include <GLFW/glfw3.h>

#include <glmixedbinding/glmixedbinding.h>
#include <glmixedbinding/AbstractFunction.h>
#include <glmixedbinding/Version.h>
#include <glmixedbinding/CallbackMask.h>
#include <glmixedbinding/FunctionCall.h>
#include <glmixedbinding/Binding.h>

#include <glmixedbinding/gl32/gl.h>

#include <glmixedbinding-aux/Meta.h>
#include <glmixedbinding-aux/ContextInfo.h>
#include <glmixedbinding-aux/ValidVersions.h>
#include <glmixedbinding-aux/types_to_string.h>


using namespace gl32;
using namespace glmixedbinding;

void error(int errnum, const char * errmsg)
{
    std::cerr << errnum << ": " << errmsg << std::endl;
}


#include "../comparison/gltest_data.inl"

void doGLStuff(GLFWwindow * window)
{
    glViewport(0, 0, 320, 240);

    #include "../comparison/gltest.inl"

    glfwSwapBuffers(window);
}

int main()
{
    glfwSetErrorCallback(error);

    if (!glfwInit())
        return 1;

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, false);

#ifdef SYSTEM_DARWIN
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    GLFWwindow * window = glfwCreateWindow(320, 240, "", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glmixedbinding::addContextSwitchCallback([](ContextHandle handle){
        std::cout << "Activating context " << handle << std::endl;
    });

    glfwMakeContextCurrent(window);

    // print some gl infos (query)

	glmixedbinding::initialize(glfwGetProcAddress, false); // only resolve functions that are actually used (lazy)

    std::cout << std::endl
        << "OpenGL Version:  " << aux::ContextInfo::version() << std::endl
        << "OpenGL Vendor:   " << aux::ContextInfo::vendor() << std::endl
        << "OpenGL Renderer: " << aux::ContextInfo::renderer() << std::endl << std::endl;

    glmixedbinding::setCallbackMask(CallbackMask::After | CallbackMask::ParametersAndReturnValue);

    glmixedbinding::setAfterCallback([](const glmixedbinding::FunctionCall & call) {
        std::cout << call.function->name() << "(";

        for (unsigned i = 0; i < call.parameters.size(); ++i)
        {
            std::cout << call.parameters[i].get();
            if (i < call.parameters.size() - 1)
                std::cout << ", ";
        }

        std::cout << ")";

        if (call.returnValue)
        {
            std::cout << " -> " << call.returnValue.get();
        }

        std::cout << std::endl;
    });

    Binding::CreateProgram.setAfterCallback([](GLuint id) {
        std::cout << "Created Program: " << id << std::endl;
    });
    Binding::CreateShader.setAfterCallback([](GLuint id, GLenum /*type*/) {
        std::cout << "Created Shader: " << id << std::endl;
    });
    Binding::DeleteProgram.setAfterCallback([](GLuint id) {
        std::cout << "Deleted Program: " << id << std::endl;
    });
    Binding::DeleteShader.setAfterCallback([](GLuint id) {
        std::cout << "Deleted Shader: " << id << std::endl;
    });

    doGLStuff(window);

    std::cout << std::endl;

    glfwTerminate();
    return 0;
}
