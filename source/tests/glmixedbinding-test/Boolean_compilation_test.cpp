
#include <gmock/gmock.h>


#include <glmixedbinding/gl45core/boolean.h>


using namespace glmixed;


TEST(Boolean, Compilation)
{
    const gl45core::GLboolean b1 = gl45core::GL_TRUE;
    const glmixed::GLboolean b2 = glmixed::GL_TRUE;
    const GLboolean b3 = GL_TRUE;

    (void)b1;
    (void)b2;
    (void)b3;

    SUCCEED();  // compiling this file without errors and warnings results in successful test
}
