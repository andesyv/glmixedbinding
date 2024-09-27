
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glWaitSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, const GLuint * buffers, GLuint numTextureBarriers, const GLuint * textures, const GLenum * srcLayouts)
{
    return glmixedbinding::Binding::WaitSemaphoreEXT(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, srcLayouts);
}

void glWaitSemaphoreui64NVX(GLuint waitGpu, GLsizei fenceObjectCount, const GLuint * semaphoreArray, const GLuint64 * fenceValueArray)
{
    return glmixedbinding::Binding::WaitSemaphoreui64NVX(waitGpu, fenceObjectCount, semaphoreArray, fenceValueArray);
}

void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    return glmixedbinding::Binding::WaitSync(sync, flags, timeout);
}

void glWaitSyncAPPLE(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    return glmixedbinding::Binding::WaitSyncAPPLE(sync, flags, timeout);
}

void glWaitVkSemaphoreNV(GLuint64 vkSemaphore)
{
    return glmixedbinding::Binding::WaitVkSemaphoreNV(vkSemaphore);
}

void glWeightbvARB(GLint size, const GLbyte * weights)
{
    return glmixedbinding::Binding::WeightbvARB(size, weights);
}

void glWeightdvARB(GLint size, const GLdouble * weights)
{
    return glmixedbinding::Binding::WeightdvARB(size, weights);
}

void glWeightfvARB(GLint size, const GLfloat * weights)
{
    return glmixedbinding::Binding::WeightfvARB(size, weights);
}

void glWeightivARB(GLint size, const GLint * weights)
{
    return glmixedbinding::Binding::WeightivARB(size, weights);
}

void glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint * paths, const GLfloat * weights)
{
    return glmixedbinding::Binding::WeightPathsNV(resultPath, numPaths, paths, weights);
}

void glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::WeightPointerARB(size, type, stride, pointer);
}

void glWeightsvARB(GLint size, const GLshort * weights)
{
    return glmixedbinding::Binding::WeightsvARB(size, weights);
}

void glWeightubvARB(GLint size, const GLubyte * weights)
{
    return glmixedbinding::Binding::WeightubvARB(size, weights);
}

void glWeightuivARB(GLint size, const GLuint * weights)
{
    return glmixedbinding::Binding::WeightuivARB(size, weights);
}

void glWeightusvARB(GLint size, const GLushort * weights)
{
    return glmixedbinding::Binding::WeightusvARB(size, weights);
}

void glWindowPos2d(GLdouble x, GLdouble y)
{
    return glmixedbinding::Binding::WindowPos2d(x, y);
}

void glWindowPos2dARB(GLdouble x, GLdouble y)
{
    return glmixedbinding::Binding::WindowPos2dARB(x, y);
}

void glWindowPos2dMESA(GLdouble x, GLdouble y)
{
    return glmixedbinding::Binding::WindowPos2dMESA(x, y);
}

void glWindowPos2dv(const GLdouble * v)
{
    return glmixedbinding::Binding::WindowPos2dv(v);
}

void glWindowPos2dvARB(const GLdouble * v)
{
    return glmixedbinding::Binding::WindowPos2dvARB(v);
}

void glWindowPos2dvMESA(const GLdouble * v)
{
    return glmixedbinding::Binding::WindowPos2dvMESA(v);
}

void glWindowPos2f(GLfloat x, GLfloat y)
{
    return glmixedbinding::Binding::WindowPos2f(x, y);
}

void glWindowPos2fARB(GLfloat x, GLfloat y)
{
    return glmixedbinding::Binding::WindowPos2fARB(x, y);
}

void glWindowPos2fMESA(GLfloat x, GLfloat y)
{
    return glmixedbinding::Binding::WindowPos2fMESA(x, y);
}

void glWindowPos2fv(const GLfloat * v)
{
    return glmixedbinding::Binding::WindowPos2fv(v);
}

void glWindowPos2fvARB(const GLfloat * v)
{
    return glmixedbinding::Binding::WindowPos2fvARB(v);
}

void glWindowPos2fvMESA(const GLfloat * v)
{
    return glmixedbinding::Binding::WindowPos2fvMESA(v);
}

void glWindowPos2i(GLint x, GLint y)
{
    return glmixedbinding::Binding::WindowPos2i(x, y);
}

void glWindowPos2iARB(GLint x, GLint y)
{
    return glmixedbinding::Binding::WindowPos2iARB(x, y);
}

void glWindowPos2iMESA(GLint x, GLint y)
{
    return glmixedbinding::Binding::WindowPos2iMESA(x, y);
}

void glWindowPos2iv(const GLint * v)
{
    return glmixedbinding::Binding::WindowPos2iv(v);
}

void glWindowPos2ivARB(const GLint * v)
{
    return glmixedbinding::Binding::WindowPos2ivARB(v);
}

void glWindowPos2ivMESA(const GLint * v)
{
    return glmixedbinding::Binding::WindowPos2ivMESA(v);
}

void glWindowPos2s(GLshort x, GLshort y)
{
    return glmixedbinding::Binding::WindowPos2s(x, y);
}

void glWindowPos2sARB(GLshort x, GLshort y)
{
    return glmixedbinding::Binding::WindowPos2sARB(x, y);
}

void glWindowPos2sMESA(GLshort x, GLshort y)
{
    return glmixedbinding::Binding::WindowPos2sMESA(x, y);
}

void glWindowPos2sv(const GLshort * v)
{
    return glmixedbinding::Binding::WindowPos2sv(v);
}

void glWindowPos2svARB(const GLshort * v)
{
    return glmixedbinding::Binding::WindowPos2svARB(v);
}

void glWindowPos2svMESA(const GLshort * v)
{
    return glmixedbinding::Binding::WindowPos2svMESA(v);
}

void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z)
{
    return glmixedbinding::Binding::WindowPos3d(x, y, z);
}

void glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z)
{
    return glmixedbinding::Binding::WindowPos3dARB(x, y, z);
}

void glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z)
{
    return glmixedbinding::Binding::WindowPos3dMESA(x, y, z);
}

void glWindowPos3dv(const GLdouble * v)
{
    return glmixedbinding::Binding::WindowPos3dv(v);
}

void glWindowPos3dvARB(const GLdouble * v)
{
    return glmixedbinding::Binding::WindowPos3dvARB(v);
}

void glWindowPos3dvMESA(const GLdouble * v)
{
    return glmixedbinding::Binding::WindowPos3dvMESA(v);
}

void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z)
{
    return glmixedbinding::Binding::WindowPos3f(x, y, z);
}

void glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z)
{
    return glmixedbinding::Binding::WindowPos3fARB(x, y, z);
}

void glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z)
{
    return glmixedbinding::Binding::WindowPos3fMESA(x, y, z);
}

void glWindowPos3fv(const GLfloat * v)
{
    return glmixedbinding::Binding::WindowPos3fv(v);
}

void glWindowPos3fvARB(const GLfloat * v)
{
    return glmixedbinding::Binding::WindowPos3fvARB(v);
}

void glWindowPos3fvMESA(const GLfloat * v)
{
    return glmixedbinding::Binding::WindowPos3fvMESA(v);
}

void glWindowPos3i(GLint x, GLint y, GLint z)
{
    return glmixedbinding::Binding::WindowPos3i(x, y, z);
}

void glWindowPos3iARB(GLint x, GLint y, GLint z)
{
    return glmixedbinding::Binding::WindowPos3iARB(x, y, z);
}

void glWindowPos3iMESA(GLint x, GLint y, GLint z)
{
    return glmixedbinding::Binding::WindowPos3iMESA(x, y, z);
}

void glWindowPos3iv(const GLint * v)
{
    return glmixedbinding::Binding::WindowPos3iv(v);
}

void glWindowPos3ivARB(const GLint * v)
{
    return glmixedbinding::Binding::WindowPos3ivARB(v);
}

void glWindowPos3ivMESA(const GLint * v)
{
    return glmixedbinding::Binding::WindowPos3ivMESA(v);
}

void glWindowPos3s(GLshort x, GLshort y, GLshort z)
{
    return glmixedbinding::Binding::WindowPos3s(x, y, z);
}

void glWindowPos3sARB(GLshort x, GLshort y, GLshort z)
{
    return glmixedbinding::Binding::WindowPos3sARB(x, y, z);
}

void glWindowPos3sMESA(GLshort x, GLshort y, GLshort z)
{
    return glmixedbinding::Binding::WindowPos3sMESA(x, y, z);
}

void glWindowPos3sv(const GLshort * v)
{
    return glmixedbinding::Binding::WindowPos3sv(v);
}

void glWindowPos3svARB(const GLshort * v)
{
    return glmixedbinding::Binding::WindowPos3svARB(v);
}

void glWindowPos3svMESA(const GLshort * v)
{
    return glmixedbinding::Binding::WindowPos3svMESA(v);
}

void glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
    return glmixedbinding::Binding::WindowPos4dMESA(x, y, z, w);
}

void glWindowPos4dvMESA(const GLdouble * v)
{
    return glmixedbinding::Binding::WindowPos4dvMESA(v);
}

void glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    return glmixedbinding::Binding::WindowPos4fMESA(x, y, z, w);
}

void glWindowPos4fvMESA(const GLfloat * v)
{
    return glmixedbinding::Binding::WindowPos4fvMESA(v);
}

void glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w)
{
    return glmixedbinding::Binding::WindowPos4iMESA(x, y, z, w);
}

void glWindowPos4ivMESA(const GLint * v)
{
    return glmixedbinding::Binding::WindowPos4ivMESA(v);
}

void glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w)
{
    return glmixedbinding::Binding::WindowPos4sMESA(x, y, z, w);
}

void glWindowPos4svMESA(const GLshort * v)
{
    return glmixedbinding::Binding::WindowPos4svMESA(v);
}

void glWindowRectanglesEXT(GLenum mode, GLsizei count, const GLint * box)
{
    return glmixedbinding::Binding::WindowRectanglesEXT(mode, count, box);
}

void glWriteMaskEXT(GLuint res, GLuint in, VertexShaderWriteMaskEXT outX, VertexShaderWriteMaskEXT outY, VertexShaderWriteMaskEXT outZ, VertexShaderWriteMaskEXT outW)
{
    return glmixedbinding::Binding::WriteMaskEXT(res, in, outX, outY, outZ, outW);
}


} // namespace glmixed