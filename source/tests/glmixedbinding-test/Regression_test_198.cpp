#include <gmock/gmock.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glmixedbinding/glmixedbinding.h>
#include <glmixedbinding/gl/gl.h>

#include <stdexcept>


glmixedbinding::ContextHandle context_cast(GLFWwindow* context) {
    static_assert(
        sizeof(glmixedbinding::ContextHandle) >= sizeof(GLFWwindow*), 
        "glmixedbinding::ContextHandle doesn't have enough space to hold GLFWwindow*");
    return reinterpret_cast<glmixedbinding::ContextHandle>(context);
}

class Regression_198 : public testing::Test
{
public:
};


TEST(Regression_198, releaseContext)  // releaseContext(ctx) wipes out functions on contexts other than ctx #198
{
    try {
        if (!glfwInit())
        {
            SUCCEED();
            return;
        }

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE, false);

        auto context_A = glfwCreateWindow(320, 240, "Regression198-A", nullptr, nullptr);
        ASSERT_NE(nullptr, context_A);
        auto context_A_gl = context_cast(context_A);
        glmixedbinding::initialize(context_A_gl, ::glfwGetProcAddress, true, false);

        auto context_B = glfwCreateWindow(320, 240, "Regression198-B", nullptr, nullptr);
        ASSERT_NE(nullptr, context_B);
        auto context_B_gl = context_cast(context_B);
        glmixedbinding::initialize(context_B_gl, ::glfwGetProcAddress, true, false);

        glmixedbinding::releaseContext(context_B_gl);
        glfwDestroyWindow(context_B);

        glfwMakeContextCurrent(context_A);
        glmixedbinding::useContext(context_A_gl);
        gl::GLint major = 0;
        glGetIntegerv(gl::GL_MAJOR_VERSION, &major);

        glmixedbinding::releaseContext(context_A_gl);
        glfwDestroyWindow(context_A);
        glfwTerminate();
    } catch (std::out_of_range & ex) {
        FAIL() << "Unexpected exception std::out_of_range thrown with message: " << ex.what();
    } catch (...) {
        SUCCEED();
    }
    SUCCEED();
}
