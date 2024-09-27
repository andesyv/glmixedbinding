
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glSampleCoverage(GLfloat value, GLboolean invert)
{
    return glmixedbinding::Binding::SampleCoverage(value, invert);
}

void glSampleCoverageARB(GLfloat value, GLboolean invert)
{
    return glmixedbinding::Binding::SampleCoverageARB(value, invert);
}

void glSampleCoveragexOES(GLclampx value, GLboolean invert)
{
    return glmixedbinding::Binding::SampleCoveragexOES(value, invert);
}

void glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle)
{
    return glmixedbinding::Binding::SampleMapATI(dst, interp, swizzle);
}

void glSampleMaskEXT(GLclampf value, GLboolean invert)
{
    return glmixedbinding::Binding::SampleMaskEXT(value, invert);
}

void glSampleMaski(GLuint maskNumber, GLbitfield mask)
{
    return glmixedbinding::Binding::SampleMaski(maskNumber, mask);
}

void glSampleMaskIndexedNV(GLuint index, GLbitfield mask)
{
    return glmixedbinding::Binding::SampleMaskIndexedNV(index, mask);
}

void glSampleMaskSGIS(GLclampf value, GLboolean invert)
{
    return glmixedbinding::Binding::SampleMaskSGIS(value, invert);
}

void glSamplePatternEXT(GLenum pattern)
{
    return glmixedbinding::Binding::SamplePatternEXT(pattern);
}

void glSamplePatternSGIS(GLenum pattern)
{
    return glmixedbinding::Binding::SamplePatternSGIS(pattern);
}

void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::SamplerParameterf(sampler, pname, param);
}

void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * param)
{
    return glmixedbinding::Binding::SamplerParameterfv(sampler, pname, param);
}

void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::SamplerParameteri(sampler, pname, param);
}

void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint * param)
{
    return glmixedbinding::Binding::SamplerParameterIiv(sampler, pname, param);
}

void glSamplerParameterIivEXT(GLuint sampler, GLenum pname, const GLint * param)
{
    return glmixedbinding::Binding::SamplerParameterIivEXT(sampler, pname, param);
}

void glSamplerParameterIivOES(GLuint sampler, GLenum pname, const GLint * param)
{
    return glmixedbinding::Binding::SamplerParameterIivOES(sampler, pname, param);
}

void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint * param)
{
    return glmixedbinding::Binding::SamplerParameterIuiv(sampler, pname, param);
}

void glSamplerParameterIuivEXT(GLuint sampler, GLenum pname, const GLuint * param)
{
    return glmixedbinding::Binding::SamplerParameterIuivEXT(sampler, pname, param);
}

void glSamplerParameterIuivOES(GLuint sampler, GLenum pname, const GLuint * param)
{
    return glmixedbinding::Binding::SamplerParameterIuivOES(sampler, pname, param);
}

void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * param)
{
    return glmixedbinding::Binding::SamplerParameteriv(sampler, pname, param);
}

void glScaled(GLdouble x, GLdouble y, GLdouble z)
{
    return glmixedbinding::Binding::Scaled(x, y, z);
}

void glScalef(GLfloat x, GLfloat y, GLfloat z)
{
    return glmixedbinding::Binding::Scalef(x, y, z);
}

void glScalexOES(GLfixed x, GLfixed y, GLfixed z)
{
    return glmixedbinding::Binding::ScalexOES(x, y, z);
}

void glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    return glmixedbinding::Binding::Scissor(x, y, width, height);
}

void glScissorArrayv(GLuint first, GLsizei count, const GLint * v)
{
    return glmixedbinding::Binding::ScissorArrayv(first, count, v);
}

void glScissorArrayvNV(GLuint first, GLsizei count, const GLint * v)
{
    return glmixedbinding::Binding::ScissorArrayvNV(first, count, v);
}

void glScissorArrayvOES(GLuint first, GLsizei count, const GLint * v)
{
    return glmixedbinding::Binding::ScissorArrayvOES(first, count, v);
}

void glScissorExclusiveArrayvNV(GLuint first, GLsizei count, const GLint * v)
{
    return glmixedbinding::Binding::ScissorExclusiveArrayvNV(first, count, v);
}

void glScissorExclusiveNV(GLint x, GLint y, GLsizei width, GLsizei height)
{
    return glmixedbinding::Binding::ScissorExclusiveNV(x, y, width, height);
}

void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
    return glmixedbinding::Binding::ScissorIndexed(index, left, bottom, width, height);
}

void glScissorIndexedNV(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
    return glmixedbinding::Binding::ScissorIndexedNV(index, left, bottom, width, height);
}

void glScissorIndexedOES(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
    return glmixedbinding::Binding::ScissorIndexedOES(index, left, bottom, width, height);
}

void glScissorIndexedv(GLuint index, const GLint * v)
{
    return glmixedbinding::Binding::ScissorIndexedv(index, v);
}

void glScissorIndexedvNV(GLuint index, const GLint * v)
{
    return glmixedbinding::Binding::ScissorIndexedvNV(index, v);
}

void glScissorIndexedvOES(GLuint index, const GLint * v)
{
    return glmixedbinding::Binding::ScissorIndexedvOES(index, v);
}

void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue)
{
    return glmixedbinding::Binding::SecondaryColor3b(red, green, blue);
}

void glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue)
{
    return glmixedbinding::Binding::SecondaryColor3bEXT(red, green, blue);
}

void glSecondaryColor3bv(const GLbyte * v)
{
    return glmixedbinding::Binding::SecondaryColor3bv(v);
}

void glSecondaryColor3bvEXT(const GLbyte * v)
{
    return glmixedbinding::Binding::SecondaryColor3bvEXT(v);
}

void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue)
{
    return glmixedbinding::Binding::SecondaryColor3d(red, green, blue);
}

void glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue)
{
    return glmixedbinding::Binding::SecondaryColor3dEXT(red, green, blue);
}

void glSecondaryColor3dv(const GLdouble * v)
{
    return glmixedbinding::Binding::SecondaryColor3dv(v);
}

void glSecondaryColor3dvEXT(const GLdouble * v)
{
    return glmixedbinding::Binding::SecondaryColor3dvEXT(v);
}

void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
    return glmixedbinding::Binding::SecondaryColor3f(red, green, blue);
}

void glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue)
{
    return glmixedbinding::Binding::SecondaryColor3fEXT(red, green, blue);
}

void glSecondaryColor3fv(const GLfloat * v)
{
    return glmixedbinding::Binding::SecondaryColor3fv(v);
}

void glSecondaryColor3fvEXT(const GLfloat * v)
{
    return glmixedbinding::Binding::SecondaryColor3fvEXT(v);
}

void glSecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue)
{
    return glmixedbinding::Binding::SecondaryColor3hNV(red, green, blue);
}

void glSecondaryColor3hvNV(const GLhalfNV * v)
{
    return glmixedbinding::Binding::SecondaryColor3hvNV(v);
}

void glSecondaryColor3i(GLint red, GLint green, GLint blue)
{
    return glmixedbinding::Binding::SecondaryColor3i(red, green, blue);
}

void glSecondaryColor3iEXT(GLint red, GLint green, GLint blue)
{
    return glmixedbinding::Binding::SecondaryColor3iEXT(red, green, blue);
}

void glSecondaryColor3iv(const GLint * v)
{
    return glmixedbinding::Binding::SecondaryColor3iv(v);
}

void glSecondaryColor3ivEXT(const GLint * v)
{
    return glmixedbinding::Binding::SecondaryColor3ivEXT(v);
}

void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue)
{
    return glmixedbinding::Binding::SecondaryColor3s(red, green, blue);
}

void glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue)
{
    return glmixedbinding::Binding::SecondaryColor3sEXT(red, green, blue);
}

void glSecondaryColor3sv(const GLshort * v)
{
    return glmixedbinding::Binding::SecondaryColor3sv(v);
}

void glSecondaryColor3svEXT(const GLshort * v)
{
    return glmixedbinding::Binding::SecondaryColor3svEXT(v);
}

void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
    return glmixedbinding::Binding::SecondaryColor3ub(red, green, blue);
}

void glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue)
{
    return glmixedbinding::Binding::SecondaryColor3ubEXT(red, green, blue);
}

void glSecondaryColor3ubv(const GLubyte * v)
{
    return glmixedbinding::Binding::SecondaryColor3ubv(v);
}

void glSecondaryColor3ubvEXT(const GLubyte * v)
{
    return glmixedbinding::Binding::SecondaryColor3ubvEXT(v);
}

void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue)
{
    return glmixedbinding::Binding::SecondaryColor3ui(red, green, blue);
}

void glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue)
{
    return glmixedbinding::Binding::SecondaryColor3uiEXT(red, green, blue);
}

void glSecondaryColor3uiv(const GLuint * v)
{
    return glmixedbinding::Binding::SecondaryColor3uiv(v);
}

void glSecondaryColor3uivEXT(const GLuint * v)
{
    return glmixedbinding::Binding::SecondaryColor3uivEXT(v);
}

void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue)
{
    return glmixedbinding::Binding::SecondaryColor3us(red, green, blue);
}

void glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue)
{
    return glmixedbinding::Binding::SecondaryColor3usEXT(red, green, blue);
}

void glSecondaryColor3usv(const GLushort * v)
{
    return glmixedbinding::Binding::SecondaryColor3usv(v);
}

void glSecondaryColor3usvEXT(const GLushort * v)
{
    return glmixedbinding::Binding::SecondaryColor3usvEXT(v);
}

void glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride)
{
    return glmixedbinding::Binding::SecondaryColorFormatNV(size, type, stride);
}

void glSecondaryColorP3ui(GLenum type, GLuint color)
{
    return glmixedbinding::Binding::SecondaryColorP3ui(type, color);
}

void glSecondaryColorP3uiv(GLenum type, const GLuint * color)
{
    return glmixedbinding::Binding::SecondaryColorP3uiv(type, color);
}

void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::SecondaryColorPointer(size, type, stride, pointer);
}

void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::SecondaryColorPointerEXT(size, type, stride, pointer);
}

void glSecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, const void ** pointer, GLint ptrstride)
{
    return glmixedbinding::Binding::SecondaryColorPointerListIBM(size, type, stride, pointer, ptrstride);
}

void glSelectBuffer(GLsizei size, GLuint * buffer)
{
    return glmixedbinding::Binding::SelectBuffer(size, buffer);
}

void glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint * counterList)
{
    return glmixedbinding::Binding::SelectPerfMonitorCountersAMD(monitor, enable, group, numCounters, counterList);
}

void glSemaphoreParameterivNV(GLuint semaphore, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::SemaphoreParameterivNV(semaphore, pname, params);
}

void glSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, const GLuint64 * params)
{
    return glmixedbinding::Binding::SemaphoreParameterui64vEXT(semaphore, pname, params);
}

void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column)
{
    return glmixedbinding::Binding::SeparableFilter2D(target, internalformat, width, height, format, type, row, column);
}

void glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column)
{
    return glmixedbinding::Binding::SeparableFilter2DEXT(target, internalformat, width, height, format, type, row, column);
}

void glSetFenceAPPLE(GLuint fence)
{
    return glmixedbinding::Binding::SetFenceAPPLE(fence);
}

void glSetFenceNV(GLuint fence, GLenum condition)
{
    return glmixedbinding::Binding::SetFenceNV(fence, condition);
}

void glSetFragmentShaderConstantATI(GLuint dst, const GLfloat * value)
{
    return glmixedbinding::Binding::SetFragmentShaderConstantATI(dst, value);
}

void glSetInvariantEXT(GLuint id, GLenum type, const void * addr)
{
    return glmixedbinding::Binding::SetInvariantEXT(id, type, addr);
}

void glSetLocalConstantEXT(GLuint id, GLenum type, const void * addr)
{
    return glmixedbinding::Binding::SetLocalConstantEXT(id, type, addr);
}

void glSetMultisamplefvAMD(GLenum pname, GLuint index, const GLfloat * val)
{
    return glmixedbinding::Binding::SetMultisamplefvAMD(pname, index, val);
}

void glShadeModel(GLenum mode)
{
    return glmixedbinding::Binding::ShadeModel(mode);
}

void glShaderBinary(GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length)
{
    return glmixedbinding::Binding::ShaderBinary(count, shaders, binaryFormat, binary, length);
}

void glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1)
{
    return glmixedbinding::Binding::ShaderOp1EXT(op, res, arg1);
}

void glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2)
{
    return glmixedbinding::Binding::ShaderOp2EXT(op, res, arg1, arg2);
}

void glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3)
{
    return glmixedbinding::Binding::ShaderOp3EXT(op, res, arg1, arg2, arg3);
}

void glShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length)
{
    return glmixedbinding::Binding::ShaderSource(shader, count, string, length);
}

void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB ** string, const GLint * length)
{
    return glmixedbinding::Binding::ShaderSourceARB(shaderObj, count, string, length);
}

void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)
{
    return glmixedbinding::Binding::ShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
}

void glShadingRateCombinerOpsEXT(GLenum combinerOp0, GLenum combinerOp1)
{
    return glmixedbinding::Binding::ShadingRateCombinerOpsEXT(combinerOp0, combinerOp1);
}

void glShadingRateEXT(GLenum rate)
{
    return glmixedbinding::Binding::ShadingRateEXT(rate);
}

void glShadingRateImageBarrierNV(GLboolean synchronize)
{
    return glmixedbinding::Binding::ShadingRateImageBarrierNV(synchronize);
}

void glShadingRateImagePaletteNV(GLuint viewport, GLuint first, GLsizei count, const GLenum * rates)
{
    return glmixedbinding::Binding::ShadingRateImagePaletteNV(viewport, first, count, rates);
}

void glShadingRateQCOM(GLenum rate)
{
    return glmixedbinding::Binding::ShadingRateQCOM(rate);
}

void glShadingRateSampleOrderCustomNV(GLenum rate, GLuint samples, const GLint * locations)
{
    return glmixedbinding::Binding::ShadingRateSampleOrderCustomNV(rate, samples, locations);
}

void glShadingRateSampleOrderNV(GLenum order)
{
    return glmixedbinding::Binding::ShadingRateSampleOrderNV(order);
}

void glSharpenTexFuncSGIS(GLenum target, GLsizei n, const GLfloat * points)
{
    return glmixedbinding::Binding::SharpenTexFuncSGIS(target, n, points);
}

void glSignalSemaphoreEXT(GLuint semaphore, GLuint numBufferBarriers, const GLuint * buffers, GLuint numTextureBarriers, const GLuint * textures, const GLenum * dstLayouts)
{
    return glmixedbinding::Binding::SignalSemaphoreEXT(semaphore, numBufferBarriers, buffers, numTextureBarriers, textures, dstLayouts);
}

void glSignalSemaphoreui64NVX(GLuint signalGpu, GLsizei fenceObjectCount, const GLuint * semaphoreArray, const GLuint64 * fenceValueArray)
{
    return glmixedbinding::Binding::SignalSemaphoreui64NVX(signalGpu, fenceObjectCount, semaphoreArray, fenceValueArray);
}

void glSignalVkFenceNV(GLuint64 vkFence)
{
    return glmixedbinding::Binding::SignalVkFenceNV(vkFence);
}

void glSignalVkSemaphoreNV(GLuint64 vkSemaphore)
{
    return glmixedbinding::Binding::SignalVkSemaphoreNV(vkSemaphore);
}

void glSpecializeShader(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue)
{
    return glmixedbinding::Binding::SpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

void glSpecializeShaderARB(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue)
{
    return glmixedbinding::Binding::SpecializeShaderARB(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

void glSpriteParameterfSGIX(GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::SpriteParameterfSGIX(pname, param);
}

void glSpriteParameterfvSGIX(GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::SpriteParameterfvSGIX(pname, params);
}

void glSpriteParameteriSGIX(GLenum pname, GLint param)
{
    return glmixedbinding::Binding::SpriteParameteriSGIX(pname, param);
}

void glSpriteParameterivSGIX(GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::SpriteParameterivSGIX(pname, params);
}

void glStartInstrumentsSGIX()
{
    return glmixedbinding::Binding::StartInstrumentsSGIX();
}

void glStartTilingQCOM(GLuint x, GLuint y, GLuint width, GLuint height, GLbitfield preserveMask)
{
    return glmixedbinding::Binding::StartTilingQCOM(x, y, width, height, preserveMask);
}

void glStateCaptureNV(GLuint state, GLenum mode)
{
    return glmixedbinding::Binding::StateCaptureNV(state, mode);
}

void glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag)
{
    return glmixedbinding::Binding::StencilClearTagEXT(stencilTagBits, stencilClearTag);
}

void glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat * transformValues)
{
    return glmixedbinding::Binding::StencilFillPathInstancedNV(numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues);
}

void glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask)
{
    return glmixedbinding::Binding::StencilFillPathNV(path, fillMode, mask);
}

void glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
    return glmixedbinding::Binding::StencilFunc(func, ref, mask);
}

void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    return glmixedbinding::Binding::StencilFuncSeparate(face, func, ref, mask);
}

void glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask)
{
    return glmixedbinding::Binding::StencilFuncSeparateATI(frontfunc, backfunc, ref, mask);
}

void glStencilMask(GLuint mask)
{
    return glmixedbinding::Binding::StencilMask(mask);
}

void glStencilMaskSeparate(GLenum face, GLuint mask)
{
    return glmixedbinding::Binding::StencilMaskSeparate(face, mask);
}

void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    return glmixedbinding::Binding::StencilOp(fail, zfail, zpass);
}

void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
    return glmixedbinding::Binding::StencilOpSeparate(face, sfail, dpfail, dppass);
}

void glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
    return glmixedbinding::Binding::StencilOpSeparateATI(face, sfail, dpfail, dppass);
}

void glStencilOpValueAMD(GLenum face, GLuint value)
{
    return glmixedbinding::Binding::StencilOpValueAMD(face, value);
}

void glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat * transformValues)
{
    return glmixedbinding::Binding::StencilStrokePathInstancedNV(numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues);
}

void glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask)
{
    return glmixedbinding::Binding::StencilStrokePathNV(path, reference, mask);
}

void glStencilThenCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues)
{
    return glmixedbinding::Binding::StencilThenCoverFillPathInstancedNV(numPaths, pathNameType, paths, pathBase, fillMode, mask, coverMode, transformType, transformValues);
}

void glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode)
{
    return glmixedbinding::Binding::StencilThenCoverFillPathNV(path, fillMode, mask, coverMode);
}

void glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues)
{
    return glmixedbinding::Binding::StencilThenCoverStrokePathInstancedNV(numPaths, pathNameType, paths, pathBase, reference, mask, coverMode, transformType, transformValues);
}

void glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode)
{
    return glmixedbinding::Binding::StencilThenCoverStrokePathNV(path, reference, mask, coverMode);
}

void glStopInstrumentsSGIX(GLint marker)
{
    return glmixedbinding::Binding::StopInstrumentsSGIX(marker);
}

void glStringMarkerGREMEDY(GLsizei len, const void * string)
{
    return glmixedbinding::Binding::StringMarkerGREMEDY(len, string);
}

void glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits)
{
    return glmixedbinding::Binding::SubpixelPrecisionBiasNV(xbits, ybits);
}

void glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW)
{
    return glmixedbinding::Binding::SwizzleEXT(res, in, outX, outY, outZ, outW);
}

void glSyncTextureINTEL(GLuint texture)
{
    return glmixedbinding::Binding::SyncTextureINTEL(texture);
}


} // namespace glmixed