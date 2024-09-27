
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glAccum(GLenum op, GLfloat value)
{
    return glmixedbinding::Binding::Accum(op, value);
}

void glAccumxOES(GLenum op, GLfixed value)
{
    return glmixedbinding::Binding::AccumxOES(op, value);
}

GLboolean glAcquireKeyedMutexWin32EXT(GLuint memory, GLuint64 key, GLuint timeout)
{
    return glmixedbinding::Binding::AcquireKeyedMutexWin32EXT(memory, key, timeout);
}

void glActiveProgramEXT(GLuint program)
{
    return glmixedbinding::Binding::ActiveProgramEXT(program);
}

void glActiveShaderProgram(GLuint pipeline, GLuint program)
{
    return glmixedbinding::Binding::ActiveShaderProgram(pipeline, program);
}

void glActiveShaderProgramEXT(GLuint pipeline, GLuint program)
{
    return glmixedbinding::Binding::ActiveShaderProgramEXT(pipeline, program);
}

void glActiveStencilFaceEXT(GLenum face)
{
    return glmixedbinding::Binding::ActiveStencilFaceEXT(face);
}

void glActiveTexture(GLenum texture)
{
    return glmixedbinding::Binding::ActiveTexture(texture);
}

void glActiveTextureARB(GLenum texture)
{
    return glmixedbinding::Binding::ActiveTextureARB(texture);
}

void glActiveVaryingNV(GLuint program, const GLchar * name)
{
    return glmixedbinding::Binding::ActiveVaryingNV(program, name);
}

void glAlphaFragmentOp1ATI(GLenum op, GLuint dst, FragmentShaderDestModMaskATI dstMod, GLuint arg1, GLuint arg1Rep, FragmentShaderColorModMaskATI arg1Mod)
{
    return glmixedbinding::Binding::AlphaFragmentOp1ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod);
}

void glAlphaFragmentOp2ATI(GLenum op, GLuint dst, FragmentShaderDestModMaskATI dstMod, GLuint arg1, GLuint arg1Rep, FragmentShaderColorModMaskATI arg1Mod, GLuint arg2, GLuint arg2Rep, FragmentShaderColorModMaskATI arg2Mod)
{
    return glmixedbinding::Binding::AlphaFragmentOp2ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod);
}

void glAlphaFragmentOp3ATI(GLenum op, GLuint dst, FragmentShaderDestModMaskATI dstMod, GLuint arg1, GLuint arg1Rep, FragmentShaderColorModMaskATI arg1Mod, GLuint arg2, GLuint arg2Rep, FragmentShaderColorModMaskATI arg2Mod, GLuint arg3, GLuint arg3Rep, FragmentShaderColorModMaskATI arg3Mod)
{
    return glmixedbinding::Binding::AlphaFragmentOp3ATI(op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod);
}

void glAlphaFunc(GLenum func, GLfloat ref)
{
    return glmixedbinding::Binding::AlphaFunc(func, ref);
}

void glAlphaFuncQCOM(GLenum func, GLclampf ref)
{
    return glmixedbinding::Binding::AlphaFuncQCOM(func, ref);
}

void glAlphaFuncxOES(GLenum func, GLfixed ref)
{
    return glmixedbinding::Binding::AlphaFuncxOES(func, ref);
}

void glAlphaToCoverageDitherControlNV(GLenum mode)
{
    return glmixedbinding::Binding::AlphaToCoverageDitherControlNV(mode);
}

void glApplyFramebufferAttachmentCMAAINTEL()
{
    return glmixedbinding::Binding::ApplyFramebufferAttachmentCMAAINTEL();
}

void glApplyTextureEXT(GLenum mode)
{
    return glmixedbinding::Binding::ApplyTextureEXT(mode);
}

GLboolean glAreProgramsResidentNV(GLsizei n, const GLuint * programs, GLboolean * residences)
{
    return glmixedbinding::Binding::AreProgramsResidentNV(n, programs, residences);
}

GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences)
{
    return glmixedbinding::Binding::AreTexturesResident(n, textures, residences);
}

GLboolean glAreTexturesResidentEXT(GLsizei n, const GLuint * textures, GLboolean * residences)
{
    return glmixedbinding::Binding::AreTexturesResidentEXT(n, textures, residences);
}

void glArrayElement(GLint i)
{
    return glmixedbinding::Binding::ArrayElement(i);
}

void glArrayElementEXT(GLint i)
{
    return glmixedbinding::Binding::ArrayElementEXT(i);
}

void glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset)
{
    return glmixedbinding::Binding::ArrayObjectATI(array, size, type, stride, buffer, offset);
}

GLuint glAsyncCopyBufferSubDataNVX(GLsizei waitSemaphoreCount, const GLuint * waitSemaphoreArray, const GLuint64 * fenceValueArray, GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsizei signalSemaphoreCount, const GLuint * signalSemaphoreArray, const GLuint64 * signalValueArray)
{
    return glmixedbinding::Binding::AsyncCopyBufferSubDataNVX(waitSemaphoreCount, waitSemaphoreArray, fenceValueArray, readGpu, writeGpuMask, readBuffer, writeBuffer, readOffset, writeOffset, size, signalSemaphoreCount, signalSemaphoreArray, signalValueArray);
}

GLuint glAsyncCopyImageSubDataNVX(GLsizei waitSemaphoreCount, const GLuint * waitSemaphoreArray, const GLuint64 * waitValueArray, GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, GLsizei signalSemaphoreCount, const GLuint * signalSemaphoreArray, const GLuint64 * signalValueArray)
{
    return glmixedbinding::Binding::AsyncCopyImageSubDataNVX(waitSemaphoreCount, waitSemaphoreArray, waitValueArray, srcGpu, dstGpuMask, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth, signalSemaphoreCount, signalSemaphoreArray, signalValueArray);
}

void glAsyncMarkerSGIX(GLuint marker)
{
    return glmixedbinding::Binding::AsyncMarkerSGIX(marker);
}

void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj)
{
    return glmixedbinding::Binding::AttachObjectARB(containerObj, obj);
}

void glAttachShader(GLuint program, GLuint shader)
{
    return glmixedbinding::Binding::AttachShader(program, shader);
}


} // namespace glmixed