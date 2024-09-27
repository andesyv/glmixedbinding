
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glMakeBufferNonResidentNV(GLenum target)
{
    return glmixedbinding::Binding::MakeBufferNonResidentNV(target);
}

void glMakeBufferResidentNV(GLenum target, GLenum access)
{
    return glmixedbinding::Binding::MakeBufferResidentNV(target, access);
}

void glMakeImageHandleNonResidentARB(GLuint64 handle)
{
    return glmixedbinding::Binding::MakeImageHandleNonResidentARB(handle);
}

void glMakeImageHandleNonResidentNV(GLuint64 handle)
{
    return glmixedbinding::Binding::MakeImageHandleNonResidentNV(handle);
}

void glMakeImageHandleResidentARB(GLuint64 handle, GLenum access)
{
    return glmixedbinding::Binding::MakeImageHandleResidentARB(handle, access);
}

void glMakeImageHandleResidentNV(GLuint64 handle, GLenum access)
{
    return glmixedbinding::Binding::MakeImageHandleResidentNV(handle, access);
}

void glMakeNamedBufferNonResidentNV(GLuint buffer)
{
    return glmixedbinding::Binding::MakeNamedBufferNonResidentNV(buffer);
}

void glMakeNamedBufferResidentNV(GLuint buffer, GLenum access)
{
    return glmixedbinding::Binding::MakeNamedBufferResidentNV(buffer, access);
}

void glMakeTextureHandleNonResidentARB(GLuint64 handle)
{
    return glmixedbinding::Binding::MakeTextureHandleNonResidentARB(handle);
}

void glMakeTextureHandleNonResidentNV(GLuint64 handle)
{
    return glmixedbinding::Binding::MakeTextureHandleNonResidentNV(handle);
}

void glMakeTextureHandleResidentARB(GLuint64 handle)
{
    return glmixedbinding::Binding::MakeTextureHandleResidentARB(handle);
}

void glMakeTextureHandleResidentNV(GLuint64 handle)
{
    return glmixedbinding::Binding::MakeTextureHandleResidentNV(handle);
}

void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points)
{
    return glmixedbinding::Binding::Map1d(target, u1, u2, stride, order, points);
}

void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points)
{
    return glmixedbinding::Binding::Map1f(target, u1, u2, stride, order, points);
}

void glMap1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points)
{
    return glmixedbinding::Binding::Map1xOES(target, u1, u2, stride, order, points);
}

void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points)
{
    return glmixedbinding::Binding::Map2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points)
{
    return glmixedbinding::Binding::Map2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void glMap2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points)
{
    return glmixedbinding::Binding::Map2xOES(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void * glMapBuffer(GLenum target, GLenum access)
{
    return glmixedbinding::Binding::MapBuffer(target, access);
}

void * glMapBufferARB(GLenum target, GLenum access)
{
    return glmixedbinding::Binding::MapBufferARB(target, access);
}

void * glMapBufferOES(GLenum target, GLenum access)
{
    return glmixedbinding::Binding::MapBufferOES(target, access);
}

void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, MapBufferAccessMask access)
{
    return glmixedbinding::Binding::MapBufferRange(target, offset, length, access);
}

void * glMapBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length, MapBufferAccessMask access)
{
    return glmixedbinding::Binding::MapBufferRangeEXT(target, offset, length, access);
}

void glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void * points)
{
    return glmixedbinding::Binding::MapControlPointsNV(target, index, type, ustride, vstride, uorder, vorder, packed, points);
}

void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2)
{
    return glmixedbinding::Binding::MapGrid1d(un, u1, u2);
}

void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2)
{
    return glmixedbinding::Binding::MapGrid1f(un, u1, u2);
}

void glMapGrid1xOES(GLint n, GLfixed u1, GLfixed u2)
{
    return glmixedbinding::Binding::MapGrid1xOES(n, u1, u2);
}

void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2)
{
    return glmixedbinding::Binding::MapGrid2d(un, u1, u2, vn, v1, v2);
}

void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2)
{
    return glmixedbinding::Binding::MapGrid2f(un, u1, u2, vn, v1, v2);
}

void glMapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2)
{
    return glmixedbinding::Binding::MapGrid2xOES(n, u1, u2, v1, v2);
}

void * glMapNamedBuffer(GLuint buffer, GLenum access)
{
    return glmixedbinding::Binding::MapNamedBuffer(buffer, access);
}

void * glMapNamedBufferEXT(GLuint buffer, GLenum access)
{
    return glmixedbinding::Binding::MapNamedBufferEXT(buffer, access);
}

void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, MapBufferAccessMask access)
{
    return glmixedbinding::Binding::MapNamedBufferRange(buffer, offset, length, access);
}

void * glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, MapBufferAccessMask access)
{
    return glmixedbinding::Binding::MapNamedBufferRangeEXT(buffer, offset, length, access);
}

void * glMapObjectBufferATI(GLuint buffer)
{
    return glmixedbinding::Binding::MapObjectBufferATI(buffer);
}

void glMapParameterfvNV(GLenum target, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::MapParameterfvNV(target, pname, params);
}

void glMapParameterivNV(GLenum target, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::MapParameterivNV(target, pname, params);
}

void * glMapTexture2DINTEL(GLuint texture, GLint level, GLbitfield access, GLint * stride, GLenum * layout)
{
    return glmixedbinding::Binding::MapTexture2DINTEL(texture, level, access, stride, layout);
}

void glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points)
{
    return glmixedbinding::Binding::MapVertexAttrib1dAPPLE(index, size, u1, u2, stride, order, points);
}

void glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points)
{
    return glmixedbinding::Binding::MapVertexAttrib1fAPPLE(index, size, u1, u2, stride, order, points);
}

void glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points)
{
    return glmixedbinding::Binding::MapVertexAttrib2dAPPLE(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points)
{
    return glmixedbinding::Binding::MapVertexAttrib2fAPPLE(index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void glMaterialf(GLenum face, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::Materialf(face, pname, param);
}

void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::Materialfv(face, pname, params);
}

void glMateriali(GLenum face, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::Materiali(face, pname, param);
}

void glMaterialiv(GLenum face, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::Materialiv(face, pname, params);
}

void glMaterialxOES(GLenum face, GLenum pname, GLfixed param)
{
    return glmixedbinding::Binding::MaterialxOES(face, pname, param);
}

void glMaterialxvOES(GLenum face, GLenum pname, const GLfixed * param)
{
    return glmixedbinding::Binding::MaterialxvOES(face, pname, param);
}

void glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    return glmixedbinding::Binding::MatrixFrustumEXT(mode, left, right, bottom, top, zNear, zFar);
}

void glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::MatrixIndexPointerARB(size, type, stride, pointer);
}

void glMatrixIndexubvARB(GLint size, const GLubyte * indices)
{
    return glmixedbinding::Binding::MatrixIndexubvARB(size, indices);
}

void glMatrixIndexuivARB(GLint size, const GLuint * indices)
{
    return glmixedbinding::Binding::MatrixIndexuivARB(size, indices);
}

void glMatrixIndexusvARB(GLint size, const GLushort * indices)
{
    return glmixedbinding::Binding::MatrixIndexusvARB(size, indices);
}

void glMatrixLoad3x2fNV(GLenum matrixMode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixLoad3x2fNV(matrixMode, m);
}

void glMatrixLoad3x3fNV(GLenum matrixMode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixLoad3x3fNV(matrixMode, m);
}

void glMatrixLoaddEXT(GLenum mode, const GLdouble * m)
{
    return glmixedbinding::Binding::MatrixLoaddEXT(mode, m);
}

void glMatrixLoadfEXT(GLenum mode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixLoadfEXT(mode, m);
}

void glMatrixLoadIdentityEXT(GLenum mode)
{
    return glmixedbinding::Binding::MatrixLoadIdentityEXT(mode);
}

void glMatrixLoadTranspose3x3fNV(GLenum matrixMode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixLoadTranspose3x3fNV(matrixMode, m);
}

void glMatrixLoadTransposedEXT(GLenum mode, const GLdouble * m)
{
    return glmixedbinding::Binding::MatrixLoadTransposedEXT(mode, m);
}

void glMatrixLoadTransposefEXT(GLenum mode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixLoadTransposefEXT(mode, m);
}

void glMatrixMode(GLenum mode)
{
    return glmixedbinding::Binding::MatrixMode(mode);
}

void glMatrixMult3x2fNV(GLenum matrixMode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixMult3x2fNV(matrixMode, m);
}

void glMatrixMult3x3fNV(GLenum matrixMode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixMult3x3fNV(matrixMode, m);
}

void glMatrixMultdEXT(GLenum mode, const GLdouble * m)
{
    return glmixedbinding::Binding::MatrixMultdEXT(mode, m);
}

void glMatrixMultfEXT(GLenum mode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixMultfEXT(mode, m);
}

void glMatrixMultTranspose3x3fNV(GLenum matrixMode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixMultTranspose3x3fNV(matrixMode, m);
}

void glMatrixMultTransposedEXT(GLenum mode, const GLdouble * m)
{
    return glmixedbinding::Binding::MatrixMultTransposedEXT(mode, m);
}

void glMatrixMultTransposefEXT(GLenum mode, const GLfloat * m)
{
    return glmixedbinding::Binding::MatrixMultTransposefEXT(mode, m);
}

void glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    return glmixedbinding::Binding::MatrixOrthoEXT(mode, left, right, bottom, top, zNear, zFar);
}

void glMatrixPopEXT(GLenum mode)
{
    return glmixedbinding::Binding::MatrixPopEXT(mode);
}

void glMatrixPushEXT(GLenum mode)
{
    return glmixedbinding::Binding::MatrixPushEXT(mode);
}

void glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
    return glmixedbinding::Binding::MatrixRotatedEXT(mode, angle, x, y, z);
}

void glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    return glmixedbinding::Binding::MatrixRotatefEXT(mode, angle, x, y, z);
}

void glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z)
{
    return glmixedbinding::Binding::MatrixScaledEXT(mode, x, y, z);
}

void glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z)
{
    return glmixedbinding::Binding::MatrixScalefEXT(mode, x, y, z);
}

void glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z)
{
    return glmixedbinding::Binding::MatrixTranslatedEXT(mode, x, y, z);
}

void glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z)
{
    return glmixedbinding::Binding::MatrixTranslatefEXT(mode, x, y, z);
}

void glMaxActiveShaderCoresARM(GLuint count)
{
    return glmixedbinding::Binding::MaxActiveShaderCoresARM(count);
}

void glMaxShaderCompilerThreadsARB(GLuint count)
{
    return glmixedbinding::Binding::MaxShaderCompilerThreadsARB(count);
}

void glMaxShaderCompilerThreadsKHR(GLuint count)
{
    return glmixedbinding::Binding::MaxShaderCompilerThreadsKHR(count);
}

void glMemoryBarrier(MemoryBarrierMask barriers)
{
    return glmixedbinding::Binding::MemoryBarrier(barriers);
}

void glMemoryBarrierByRegion(MemoryBarrierMask barriers)
{
    return glmixedbinding::Binding::MemoryBarrierByRegion(barriers);
}

void glMemoryBarrierEXT(MemoryBarrierMask barriers)
{
    return glmixedbinding::Binding::MemoryBarrierEXT(barriers);
}

void glMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::MemoryObjectParameterivEXT(memoryObject, pname, params);
}

void glMinmax(GLenum target, GLenum internalformat, GLboolean sink)
{
    return glmixedbinding::Binding::Minmax(target, internalformat, sink);
}

void glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink)
{
    return glmixedbinding::Binding::MinmaxEXT(target, internalformat, sink);
}

void glMinSampleShading(GLfloat value)
{
    return glmixedbinding::Binding::MinSampleShading(value);
}

void glMinSampleShadingARB(GLfloat value)
{
    return glmixedbinding::Binding::MinSampleShadingARB(value);
}

void glMinSampleShadingOES(GLfloat value)
{
    return glmixedbinding::Binding::MinSampleShadingOES(value);
}

void glMulticastBarrierNV()
{
    return glmixedbinding::Binding::MulticastBarrierNV();
}

void glMulticastBlitFramebufferNV(GLuint srcGpu, GLuint dstGpu, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, ClearBufferMask mask, GLenum filter)
{
    return glmixedbinding::Binding::MulticastBlitFramebufferNV(srcGpu, dstGpu, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glMulticastBufferSubDataNV(GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data)
{
    return glmixedbinding::Binding::MulticastBufferSubDataNV(gpuMask, buffer, offset, size, data);
}

void glMulticastCopyBufferSubDataNV(GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
    return glmixedbinding::Binding::MulticastCopyBufferSubDataNV(readGpu, writeGpuMask, readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void glMulticastCopyImageSubDataNV(GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
{
    return glmixedbinding::Binding::MulticastCopyImageSubDataNV(srcGpu, dstGpuMask, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}

void glMulticastFramebufferSampleLocationsfvNV(GLuint gpu, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat * v)
{
    return glmixedbinding::Binding::MulticastFramebufferSampleLocationsfvNV(gpu, framebuffer, start, count, v);
}

void glMulticastGetQueryObjecti64vNV(GLuint gpu, GLuint id, GLenum pname, GLint64 * params)
{
    return glmixedbinding::Binding::MulticastGetQueryObjecti64vNV(gpu, id, pname, params);
}

void glMulticastGetQueryObjectivNV(GLuint gpu, GLuint id, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::MulticastGetQueryObjectivNV(gpu, id, pname, params);
}

void glMulticastGetQueryObjectui64vNV(GLuint gpu, GLuint id, GLenum pname, GLuint64 * params)
{
    return glmixedbinding::Binding::MulticastGetQueryObjectui64vNV(gpu, id, pname, params);
}

void glMulticastGetQueryObjectuivNV(GLuint gpu, GLuint id, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::MulticastGetQueryObjectuivNV(gpu, id, pname, params);
}

void glMulticastScissorArrayvNVX(GLuint gpu, GLuint first, GLsizei count, const GLint * v)
{
    return glmixedbinding::Binding::MulticastScissorArrayvNVX(gpu, first, count, v);
}

void glMulticastViewportArrayvNVX(GLuint gpu, GLuint first, GLsizei count, const GLfloat * v)
{
    return glmixedbinding::Binding::MulticastViewportArrayvNVX(gpu, first, count, v);
}

void glMulticastViewportPositionWScaleNVX(GLuint gpu, GLuint index, GLfloat xcoeff, GLfloat ycoeff)
{
    return glmixedbinding::Binding::MulticastViewportPositionWScaleNVX(gpu, index, xcoeff, ycoeff);
}

void glMulticastWaitSyncNV(GLuint signalGpu, GLbitfield waitGpuMask)
{
    return glmixedbinding::Binding::MulticastWaitSyncNV(signalGpu, waitGpuMask);
}

void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount)
{
    return glmixedbinding::Binding::MultiDrawArrays(mode, first, count, drawcount);
}

void glMultiDrawArraysEXT(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount)
{
    return glmixedbinding::Binding::MultiDrawArraysEXT(mode, first, count, primcount);
}

void glMultiDrawArraysIndirect(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawArraysIndirect(mode, indirect, drawcount, stride);
}

void glMultiDrawArraysIndirectAMD(GLenum mode, const void * indirect, GLsizei primcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawArraysIndirectAMD(mode, indirect, primcount, stride);
}

void glMultiDrawArraysIndirectBindlessCountNV(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount)
{
    return glmixedbinding::Binding::MultiDrawArraysIndirectBindlessCountNV(mode, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}

void glMultiDrawArraysIndirectBindlessNV(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount)
{
    return glmixedbinding::Binding::MultiDrawArraysIndirectBindlessNV(mode, indirect, drawCount, stride, vertexBufferCount);
}

void glMultiDrawArraysIndirectCount(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride);
}

void glMultiDrawArraysIndirectCountARB(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawArraysIndirectCountARB(mode, indirect, drawcount, maxdrawcount, stride);
}

void glMultiDrawArraysIndirectEXT(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawArraysIndirectEXT(mode, indirect, drawcount, stride);
}

void glMultiDrawElementArrayAPPLE(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount)
{
    return glmixedbinding::Binding::MultiDrawElementArrayAPPLE(mode, first, count, primcount);
}

void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount)
{
    return glmixedbinding::Binding::MultiDrawElements(mode, count, type, indices, drawcount);
}

void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex)
{
    return glmixedbinding::Binding::MultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex);
}

void glMultiDrawElementsBaseVertexEXT(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex)
{
    return glmixedbinding::Binding::MultiDrawElementsBaseVertexEXT(mode, count, type, indices, drawcount, basevertex);
}

void glMultiDrawElementsEXT(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount)
{
    return glmixedbinding::Binding::MultiDrawElementsEXT(mode, count, type, indices, primcount);
}

void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawElementsIndirect(mode, type, indirect, drawcount, stride);
}

void glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, const void * indirect, GLsizei primcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawElementsIndirectAMD(mode, type, indirect, primcount, stride);
}

void glMultiDrawElementsIndirectBindlessCountNV(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount)
{
    return glmixedbinding::Binding::MultiDrawElementsIndirectBindlessCountNV(mode, type, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
}

void glMultiDrawElementsIndirectBindlessNV(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount)
{
    return glmixedbinding::Binding::MultiDrawElementsIndirectBindlessNV(mode, type, indirect, drawCount, stride, vertexBufferCount);
}

void glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride);
}

void glMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawElementsIndirectCountARB(mode, type, indirect, drawcount, maxdrawcount, stride);
}

void glMultiDrawElementsIndirectEXT(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawElementsIndirectEXT(mode, type, indirect, drawcount, stride);
}

void glMultiDrawMeshTasksIndirectCountNV(GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawMeshTasksIndirectCountNV(indirect, drawcount, maxdrawcount, stride);
}

void glMultiDrawMeshTasksIndirectNV(GLintptr indirect, GLsizei drawcount, GLsizei stride)
{
    return glmixedbinding::Binding::MultiDrawMeshTasksIndirectNV(indirect, drawcount, stride);
}

void glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, const GLint * first, const GLsizei * count, GLsizei primcount)
{
    return glmixedbinding::Binding::MultiDrawRangeElementArrayAPPLE(mode, start, end, first, count, primcount);
}

void glMultiModeDrawArraysIBM(const GLenum * mode, const GLint * first, const GLsizei * count, GLsizei primcount, GLint modestride)
{
    return glmixedbinding::Binding::MultiModeDrawArraysIBM(mode, first, count, primcount, modestride);
}

void glMultiModeDrawElementsIBM(const GLenum * mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount, GLint modestride)
{
    return glmixedbinding::Binding::MultiModeDrawElementsIBM(mode, count, type, indices, primcount, modestride);
}

void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer)
{
    return glmixedbinding::Binding::MultiTexBufferEXT(texunit, target, internalformat, buffer);
}

void glMultiTexCoord1bOES(GLenum texture, GLbyte s)
{
    return glmixedbinding::Binding::MultiTexCoord1bOES(texture, s);
}

void glMultiTexCoord1bvOES(GLenum texture, const GLbyte * coords)
{
    return glmixedbinding::Binding::MultiTexCoord1bvOES(texture, coords);
}

void glMultiTexCoord1d(GLenum target, GLdouble s)
{
    return glmixedbinding::Binding::MultiTexCoord1d(target, s);
}

void glMultiTexCoord1dARB(GLenum target, GLdouble s)
{
    return glmixedbinding::Binding::MultiTexCoord1dARB(target, s);
}

void glMultiTexCoord1dv(GLenum target, const GLdouble * v)
{
    return glmixedbinding::Binding::MultiTexCoord1dv(target, v);
}

void glMultiTexCoord1dvARB(GLenum target, const GLdouble * v)
{
    return glmixedbinding::Binding::MultiTexCoord1dvARB(target, v);
}

void glMultiTexCoord1f(GLenum target, GLfloat s)
{
    return glmixedbinding::Binding::MultiTexCoord1f(target, s);
}

void glMultiTexCoord1fARB(GLenum target, GLfloat s)
{
    return glmixedbinding::Binding::MultiTexCoord1fARB(target, s);
}

void glMultiTexCoord1fv(GLenum target, const GLfloat * v)
{
    return glmixedbinding::Binding::MultiTexCoord1fv(target, v);
}

void glMultiTexCoord1fvARB(GLenum target, const GLfloat * v)
{
    return glmixedbinding::Binding::MultiTexCoord1fvARB(target, v);
}

void glMultiTexCoord1hNV(GLenum target, GLhalfNV s)
{
    return glmixedbinding::Binding::MultiTexCoord1hNV(target, s);
}

void glMultiTexCoord1hvNV(GLenum target, const GLhalfNV * v)
{
    return glmixedbinding::Binding::MultiTexCoord1hvNV(target, v);
}

void glMultiTexCoord1i(GLenum target, GLint s)
{
    return glmixedbinding::Binding::MultiTexCoord1i(target, s);
}

void glMultiTexCoord1iARB(GLenum target, GLint s)
{
    return glmixedbinding::Binding::MultiTexCoord1iARB(target, s);
}

void glMultiTexCoord1iv(GLenum target, const GLint * v)
{
    return glmixedbinding::Binding::MultiTexCoord1iv(target, v);
}

void glMultiTexCoord1ivARB(GLenum target, const GLint * v)
{
    return glmixedbinding::Binding::MultiTexCoord1ivARB(target, v);
}

void glMultiTexCoord1s(GLenum target, GLshort s)
{
    return glmixedbinding::Binding::MultiTexCoord1s(target, s);
}

void glMultiTexCoord1sARB(GLenum target, GLshort s)
{
    return glmixedbinding::Binding::MultiTexCoord1sARB(target, s);
}

void glMultiTexCoord1sv(GLenum target, const GLshort * v)
{
    return glmixedbinding::Binding::MultiTexCoord1sv(target, v);
}

void glMultiTexCoord1svARB(GLenum target, const GLshort * v)
{
    return glmixedbinding::Binding::MultiTexCoord1svARB(target, v);
}

void glMultiTexCoord1xOES(GLenum texture, GLfixed s)
{
    return glmixedbinding::Binding::MultiTexCoord1xOES(texture, s);
}

void glMultiTexCoord1xvOES(GLenum texture, const GLfixed * coords)
{
    return glmixedbinding::Binding::MultiTexCoord1xvOES(texture, coords);
}

void glMultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t)
{
    return glmixedbinding::Binding::MultiTexCoord2bOES(texture, s, t);
}

void glMultiTexCoord2bvOES(GLenum texture, const GLbyte * coords)
{
    return glmixedbinding::Binding::MultiTexCoord2bvOES(texture, coords);
}

void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t)
{
    return glmixedbinding::Binding::MultiTexCoord2d(target, s, t);
}

void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t)
{
    return glmixedbinding::Binding::MultiTexCoord2dARB(target, s, t);
}

void glMultiTexCoord2dv(GLenum target, const GLdouble * v)
{
    return glmixedbinding::Binding::MultiTexCoord2dv(target, v);
}

void glMultiTexCoord2dvARB(GLenum target, const GLdouble * v)
{
    return glmixedbinding::Binding::MultiTexCoord2dvARB(target, v);
}

void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t)
{
    return glmixedbinding::Binding::MultiTexCoord2f(target, s, t);
}

void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t)
{
    return glmixedbinding::Binding::MultiTexCoord2fARB(target, s, t);
}

void glMultiTexCoord2fv(GLenum target, const GLfloat * v)
{
    return glmixedbinding::Binding::MultiTexCoord2fv(target, v);
}

void glMultiTexCoord2fvARB(GLenum target, const GLfloat * v)
{
    return glmixedbinding::Binding::MultiTexCoord2fvARB(target, v);
}

void glMultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t)
{
    return glmixedbinding::Binding::MultiTexCoord2hNV(target, s, t);
}

void glMultiTexCoord2hvNV(GLenum target, const GLhalfNV * v)
{
    return glmixedbinding::Binding::MultiTexCoord2hvNV(target, v);
}

void glMultiTexCoord2i(GLenum target, GLint s, GLint t)
{
    return glmixedbinding::Binding::MultiTexCoord2i(target, s, t);
}

void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t)
{
    return glmixedbinding::Binding::MultiTexCoord2iARB(target, s, t);
}

void glMultiTexCoord2iv(GLenum target, const GLint * v)
{
    return glmixedbinding::Binding::MultiTexCoord2iv(target, v);
}

void glMultiTexCoord2ivARB(GLenum target, const GLint * v)
{
    return glmixedbinding::Binding::MultiTexCoord2ivARB(target, v);
}

void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t)
{
    return glmixedbinding::Binding::MultiTexCoord2s(target, s, t);
}

void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t)
{
    return glmixedbinding::Binding::MultiTexCoord2sARB(target, s, t);
}

void glMultiTexCoord2sv(GLenum target, const GLshort * v)
{
    return glmixedbinding::Binding::MultiTexCoord2sv(target, v);
}

void glMultiTexCoord2svARB(GLenum target, const GLshort * v)
{
    return glmixedbinding::Binding::MultiTexCoord2svARB(target, v);
}

void glMultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t)
{
    return glmixedbinding::Binding::MultiTexCoord2xOES(texture, s, t);
}

void glMultiTexCoord2xvOES(GLenum texture, const GLfixed * coords)
{
    return glmixedbinding::Binding::MultiTexCoord2xvOES(texture, coords);
}

void glMultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r)
{
    return glmixedbinding::Binding::MultiTexCoord3bOES(texture, s, t, r);
}

void glMultiTexCoord3bvOES(GLenum texture, const GLbyte * coords)
{
    return glmixedbinding::Binding::MultiTexCoord3bvOES(texture, coords);
}

void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
    return glmixedbinding::Binding::MultiTexCoord3d(target, s, t, r);
}

void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
    return glmixedbinding::Binding::MultiTexCoord3dARB(target, s, t, r);
}

void glMultiTexCoord3dv(GLenum target, const GLdouble * v)
{
    return glmixedbinding::Binding::MultiTexCoord3dv(target, v);
}

void glMultiTexCoord3dvARB(GLenum target, const GLdouble * v)
{
    return glmixedbinding::Binding::MultiTexCoord3dvARB(target, v);
}

void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
    return glmixedbinding::Binding::MultiTexCoord3f(target, s, t, r);
}

void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
    return glmixedbinding::Binding::MultiTexCoord3fARB(target, s, t, r);
}

void glMultiTexCoord3fv(GLenum target, const GLfloat * v)
{
    return glmixedbinding::Binding::MultiTexCoord3fv(target, v);
}

void glMultiTexCoord3fvARB(GLenum target, const GLfloat * v)
{
    return glmixedbinding::Binding::MultiTexCoord3fvARB(target, v);
}

void glMultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r)
{
    return glmixedbinding::Binding::MultiTexCoord3hNV(target, s, t, r);
}

void glMultiTexCoord3hvNV(GLenum target, const GLhalfNV * v)
{
    return glmixedbinding::Binding::MultiTexCoord3hvNV(target, v);
}

void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r)
{
    return glmixedbinding::Binding::MultiTexCoord3i(target, s, t, r);
}

void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r)
{
    return glmixedbinding::Binding::MultiTexCoord3iARB(target, s, t, r);
}

void glMultiTexCoord3iv(GLenum target, const GLint * v)
{
    return glmixedbinding::Binding::MultiTexCoord3iv(target, v);
}

void glMultiTexCoord3ivARB(GLenum target, const GLint * v)
{
    return glmixedbinding::Binding::MultiTexCoord3ivARB(target, v);
}

void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r)
{
    return glmixedbinding::Binding::MultiTexCoord3s(target, s, t, r);
}

void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r)
{
    return glmixedbinding::Binding::MultiTexCoord3sARB(target, s, t, r);
}

void glMultiTexCoord3sv(GLenum target, const GLshort * v)
{
    return glmixedbinding::Binding::MultiTexCoord3sv(target, v);
}

void glMultiTexCoord3svARB(GLenum target, const GLshort * v)
{
    return glmixedbinding::Binding::MultiTexCoord3svARB(target, v);
}

void glMultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r)
{
    return glmixedbinding::Binding::MultiTexCoord3xOES(texture, s, t, r);
}

void glMultiTexCoord3xvOES(GLenum texture, const GLfixed * coords)
{
    return glmixedbinding::Binding::MultiTexCoord3xvOES(texture, coords);
}

void glMultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q)
{
    return glmixedbinding::Binding::MultiTexCoord4bOES(texture, s, t, r, q);
}

void glMultiTexCoord4bvOES(GLenum texture, const GLbyte * coords)
{
    return glmixedbinding::Binding::MultiTexCoord4bvOES(texture, coords);
}

void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
    return glmixedbinding::Binding::MultiTexCoord4d(target, s, t, r, q);
}

void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
    return glmixedbinding::Binding::MultiTexCoord4dARB(target, s, t, r, q);
}

void glMultiTexCoord4dv(GLenum target, const GLdouble * v)
{
    return glmixedbinding::Binding::MultiTexCoord4dv(target, v);
}

void glMultiTexCoord4dvARB(GLenum target, const GLdouble * v)
{
    return glmixedbinding::Binding::MultiTexCoord4dvARB(target, v);
}

void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    return glmixedbinding::Binding::MultiTexCoord4f(target, s, t, r, q);
}

void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    return glmixedbinding::Binding::MultiTexCoord4fARB(target, s, t, r, q);
}

void glMultiTexCoord4fv(GLenum target, const GLfloat * v)
{
    return glmixedbinding::Binding::MultiTexCoord4fv(target, v);
}

void glMultiTexCoord4fvARB(GLenum target, const GLfloat * v)
{
    return glmixedbinding::Binding::MultiTexCoord4fvARB(target, v);
}

void glMultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q)
{
    return glmixedbinding::Binding::MultiTexCoord4hNV(target, s, t, r, q);
}

void glMultiTexCoord4hvNV(GLenum target, const GLhalfNV * v)
{
    return glmixedbinding::Binding::MultiTexCoord4hvNV(target, v);
}

void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
    return glmixedbinding::Binding::MultiTexCoord4i(target, s, t, r, q);
}

void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
    return glmixedbinding::Binding::MultiTexCoord4iARB(target, s, t, r, q);
}

void glMultiTexCoord4iv(GLenum target, const GLint * v)
{
    return glmixedbinding::Binding::MultiTexCoord4iv(target, v);
}

void glMultiTexCoord4ivARB(GLenum target, const GLint * v)
{
    return glmixedbinding::Binding::MultiTexCoord4ivARB(target, v);
}

void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
    return glmixedbinding::Binding::MultiTexCoord4s(target, s, t, r, q);
}

void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
    return glmixedbinding::Binding::MultiTexCoord4sARB(target, s, t, r, q);
}

void glMultiTexCoord4sv(GLenum target, const GLshort * v)
{
    return glmixedbinding::Binding::MultiTexCoord4sv(target, v);
}

void glMultiTexCoord4svARB(GLenum target, const GLshort * v)
{
    return glmixedbinding::Binding::MultiTexCoord4svARB(target, v);
}

void glMultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q)
{
    return glmixedbinding::Binding::MultiTexCoord4xOES(texture, s, t, r, q);
}

void glMultiTexCoord4xvOES(GLenum texture, const GLfixed * coords)
{
    return glmixedbinding::Binding::MultiTexCoord4xvOES(texture, coords);
}

void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords)
{
    return glmixedbinding::Binding::MultiTexCoordP1ui(texture, type, coords);
}

void glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint * coords)
{
    return glmixedbinding::Binding::MultiTexCoordP1uiv(texture, type, coords);
}

void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords)
{
    return glmixedbinding::Binding::MultiTexCoordP2ui(texture, type, coords);
}

void glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint * coords)
{
    return glmixedbinding::Binding::MultiTexCoordP2uiv(texture, type, coords);
}

void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords)
{
    return glmixedbinding::Binding::MultiTexCoordP3ui(texture, type, coords);
}

void glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint * coords)
{
    return glmixedbinding::Binding::MultiTexCoordP3uiv(texture, type, coords);
}

void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords)
{
    return glmixedbinding::Binding::MultiTexCoordP4ui(texture, type, coords);
}

void glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint * coords)
{
    return glmixedbinding::Binding::MultiTexCoordP4uiv(texture, type, coords);
}

void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::MultiTexCoordPointerEXT(texunit, size, type, stride, pointer);
}

void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::MultiTexEnvfEXT(texunit, target, pname, param);
}

void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::MultiTexEnvfvEXT(texunit, target, pname, params);
}

void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::MultiTexEnviEXT(texunit, target, pname, param);
}

void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::MultiTexEnvivEXT(texunit, target, pname, params);
}

void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param)
{
    return glmixedbinding::Binding::MultiTexGendEXT(texunit, coord, pname, param);
}

void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble * params)
{
    return glmixedbinding::Binding::MultiTexGendvEXT(texunit, coord, pname, params);
}

void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::MultiTexGenfEXT(texunit, coord, pname, param);
}

void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::MultiTexGenfvEXT(texunit, coord, pname, params);
}

void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::MultiTexGeniEXT(texunit, coord, pname, param);
}

void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::MultiTexGenivEXT(texunit, coord, pname, params);
}

void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels)
{
    return glmixedbinding::Binding::MultiTexImage1DEXT(texunit, target, level, internalformat, width, border, format, type, pixels);
}

void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels)
{
    return glmixedbinding::Binding::MultiTexImage2DEXT(texunit, target, level, internalformat, width, height, border, format, type, pixels);
}

void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels)
{
    return glmixedbinding::Binding::MultiTexImage3DEXT(texunit, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::MultiTexParameterfEXT(texunit, target, pname, param);
}

void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::MultiTexParameterfvEXT(texunit, target, pname, params);
}

void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::MultiTexParameteriEXT(texunit, target, pname, param);
}

void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::MultiTexParameterIivEXT(texunit, target, pname, params);
}

void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint * params)
{
    return glmixedbinding::Binding::MultiTexParameterIuivEXT(texunit, target, pname, params);
}

void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::MultiTexParameterivEXT(texunit, target, pname, params);
}

void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer)
{
    return glmixedbinding::Binding::MultiTexRenderbufferEXT(texunit, target, renderbuffer);
}

void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels)
{
    return glmixedbinding::Binding::MultiTexSubImage1DEXT(texunit, target, level, xoffset, width, format, type, pixels);
}

void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels)
{
    return glmixedbinding::Binding::MultiTexSubImage2DEXT(texunit, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels)
{
    return glmixedbinding::Binding::MultiTexSubImage3DEXT(texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void glMultMatrixd(const GLdouble * m)
{
    return glmixedbinding::Binding::MultMatrixd(m);
}

void glMultMatrixf(const GLfloat * m)
{
    return glmixedbinding::Binding::MultMatrixf(m);
}

void glMultMatrixxOES(const GLfixed * m)
{
    return glmixedbinding::Binding::MultMatrixxOES(m);
}

void glMultTransposeMatrixd(const GLdouble * m)
{
    return glmixedbinding::Binding::MultTransposeMatrixd(m);
}

void glMultTransposeMatrixdARB(const GLdouble * m)
{
    return glmixedbinding::Binding::MultTransposeMatrixdARB(m);
}

void glMultTransposeMatrixf(const GLfloat * m)
{
    return glmixedbinding::Binding::MultTransposeMatrixf(m);
}

void glMultTransposeMatrixfARB(const GLfloat * m)
{
    return glmixedbinding::Binding::MultTransposeMatrixfARB(m);
}

void glMultTransposeMatrixxOES(const GLfixed * m)
{
    return glmixedbinding::Binding::MultTransposeMatrixxOES(m);
}


} // namespace glmixed