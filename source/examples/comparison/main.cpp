
#include <iostream>
#include <ratio>
#include <thread>

#include <GLFW/glfw3.h>

#include <glmixedbinding/Version.h>

#include <glmixedbinding-aux/ContextInfo.h>
#include <glmixedbinding-aux/logging.h>
#include <glmixedbinding-aux/types_to_string.h>
#include <glmixedbinding-aux/ValidVersions.h>

#include "Timer.h"
#include <thread>
#include <fstream>

#include "glmixedbinding.h"
#include "glew.h"



void compare()
{
    const int ITERATIONS = 8192;
    const int ITERATIONS_WARMUP = ITERATIONS / 32;


    Timer timer;

    std::cout <<  std::endl << "test: initialize bindings ..." << std::endl;

    timer.start("      glmixedbinding ");
    glmixedbinding_init();

    timer.restart("      glew      ");
    glew_init();

    timer.stop();


    std::cout << std::endl
        << "OpenGL Version:  " << glmixedbinding::aux::ContextInfo::version() << std::endl
        << "OpenGL Vendor:   " << glmixedbinding::aux::ContextInfo::vendor() << std::endl
        << "OpenGL Renderer: " << glmixedbinding::aux::ContextInfo::renderer() << std::endl;


    std::cout << std::endl << "prep: warm-up ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "      glew      " << std::endl;
    for (int i = 0; i < ITERATIONS_WARMUP; ++i)
        glew_test();

    std::cout << "      glmixedbinding " << std::endl;
    for (int i = 0; i < ITERATIONS_WARMUP; ++i)
        glmixedbinding_test();

    timer.setSteps(24 * ITERATIONS);
    

    std::cout << std::endl << "test: average call times for " << ITERATIONS << " x 24 calls ..." << std::endl;

    timer.start("      glew      ");
    for (int i = 0; i < ITERATIONS; ++i)
        glew_test();

    long double glew_avg = timer.restart("      glmixedbinding ");

    for (int i = 0; i < ITERATIONS; ++i)
        glmixedbinding_test();

    long double glmixedbinding_avg = timer.stop();

 
    std::cout << std::endl << "test: again, now with error checking ..." << std::endl;

    glew_error(true);
    glmixedbinding_error(true);

    timer.start("      glew      ");
    for (int i = 0; i < ITERATIONS; ++i)
        glew_test();

    long double glew_avg_err = timer.restart("      glmixedbinding ");
    for (int i = 0; i < ITERATIONS; ++i)
        glmixedbinding_test();

    long double glmixedbinding_avg_err = timer.stop();
    glmixedbinding_error(false);

    std::cout << std::endl << "test: again, now with logging ..." << std::endl;
    glmixedbinding::aux::start("logs/comparison");
    timer.start("      glmixedbinding ");

    for (int i = 0; i < ITERATIONS; ++i)
        glmixedbinding_test();
    
    long double glmixedbinding_avg_log = timer.stop();
    glmixedbinding::aux::stop();


    std::cout << std::endl << "glmixedbinding/glew decrease:                 " << (glmixedbinding_avg / glew_avg - 1.0) * 100.0 << "%" << std::endl;
    std::cout << std::endl << "glmixedbinding/glew decrease (error checks):  " << (glmixedbinding_avg_err / glew_avg_err - 1.0) * 100.0 << "%" << std::endl;
    std::cout << std::endl << "glmixedbinding decrease with logging:         " << (glmixedbinding_avg_log / glmixedbinding_avg  - 1.0) * 100.0 << "%" << std::endl;

    std::cout << std::endl << "finalizing ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

void errorfun(int errnum, const char * errmsg)
{
    std::cerr << errnum << ": " << errmsg << std::endl;
}

int main(int /*argc*/, char* /*argv*/[])
{
    glfwSetErrorCallback(errorfun);

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

    glfwMakeContextCurrent(window);

    compare();

    glfwTerminate();
    return 0;
}
