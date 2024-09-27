
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glBegin(GLenum mode)
{
    return glmixedbinding::Binding::Begin(mode);
}

void glBeginConditionalRender(GLuint id, GLenum mode)
{
    return glmixedbinding::Binding::BeginConditionalRender(id, mode);
}

void glBeginConditionalRenderNV(GLuint id, GLenum mode)
{
    return glmixedbinding::Binding::BeginConditionalRenderNV(id, mode);
}

void glBeginConditionalRenderNVX(GLuint id)
{
    return glmixedbinding::Binding::BeginConditionalRenderNVX(id);
}

void glBeginFragmentShaderATI()
{
    return glmixedbinding::Binding::BeginFragmentShaderATI();
}

void glBeginOcclusionQueryNV(GLuint id)
{
    return glmixedbinding::Binding::BeginOcclusionQueryNV(id);
}

void glBeginPerfMonitorAMD(GLuint monitor)
{
    return glmixedbinding::Binding::BeginPerfMonitorAMD(monitor);
}

void glBeginPerfQueryINTEL(GLuint queryHandle)
{
    return glmixedbinding::Binding::BeginPerfQueryINTEL(queryHandle);
}

void glBeginQuery(GLenum target, GLuint id)
{
    return glmixedbinding::Binding::BeginQuery(target, id);
}

void glBeginQueryARB(GLenum target, GLuint id)
{
    return glmixedbinding::Binding::BeginQueryARB(target, id);
}

void glBeginQueryEXT(GLenum target, GLuint id)
{
    return glmixedbinding::Binding::BeginQueryEXT(target, id);
}

void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
{
    return glmixedbinding::Binding::BeginQueryIndexed(target, index, id);
}

void glBeginTransformFeedback(GLenum primitiveMode)
{
    return glmixedbinding::Binding::BeginTransformFeedback(primitiveMode);
}

void glBeginTransformFeedbackEXT(GLenum primitiveMode)
{
    return glmixedbinding::Binding::BeginTransformFeedbackEXT(primitiveMode);
}

void glBeginTransformFeedbackNV(GLenum primitiveMode)
{
    return glmixedbinding::Binding::BeginTransformFeedbackNV(primitiveMode);
}

void glBeginVertexShaderEXT()
{
    return glmixedbinding::Binding::BeginVertexShaderEXT();
}

void glBeginVideoCaptureNV(GLuint video_capture_slot)
{
    return glmixedbinding::Binding::BeginVideoCaptureNV(video_capture_slot);
}

void glBindAttribLocation(GLuint program, GLuint index, const GLchar * name)
{
    return glmixedbinding::Binding::BindAttribLocation(program, index, name);
}

void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB * name)
{
    return glmixedbinding::Binding::BindAttribLocationARB(programObj, index, name);
}

void glBindBuffer(GLenum target, GLuint buffer)
{
    return glmixedbinding::Binding::BindBuffer(target, buffer);
}

void glBindBufferARB(GLenum target, GLuint buffer)
{
    return glmixedbinding::Binding::BindBufferARB(target, buffer);
}

void glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
{
    return glmixedbinding::Binding::BindBufferBase(target, index, buffer);
}

void glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer)
{
    return glmixedbinding::Binding::BindBufferBaseEXT(target, index, buffer);
}

void glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer)
{
    return glmixedbinding::Binding::BindBufferBaseNV(target, index, buffer);
}

void glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset)
{
    return glmixedbinding::Binding::BindBufferOffsetEXT(target, index, buffer, offset);
}

void glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset)
{
    return glmixedbinding::Binding::BindBufferOffsetNV(target, index, buffer, offset);
}

void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    return glmixedbinding::Binding::BindBufferRange(target, index, buffer, offset, size);
}

void glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    return glmixedbinding::Binding::BindBufferRangeEXT(target, index, buffer, offset, size);
}

void glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    return glmixedbinding::Binding::BindBufferRangeNV(target, index, buffer, offset, size);
}

void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint * buffers)
{
    return glmixedbinding::Binding::BindBuffersBase(target, first, count, buffers);
}

void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes)
{
    return glmixedbinding::Binding::BindBuffersRange(target, first, count, buffers, offsets, sizes);
}

void glBindFragDataLocation(GLuint program, GLuint color, const GLchar * name)
{
    return glmixedbinding::Binding::BindFragDataLocation(program, color, name);
}

void glBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar * name)
{
    return glmixedbinding::Binding::BindFragDataLocationEXT(program, color, name);
}

void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name)
{
    return glmixedbinding::Binding::BindFragDataLocationIndexed(program, colorNumber, index, name);
}

void glBindFragDataLocationIndexedEXT(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name)
{
    return glmixedbinding::Binding::BindFragDataLocationIndexedEXT(program, colorNumber, index, name);
}

void glBindFragmentShaderATI(GLuint id)
{
    return glmixedbinding::Binding::BindFragmentShaderATI(id);
}

void glBindFramebuffer(GLenum target, GLuint framebuffer)
{
    return glmixedbinding::Binding::BindFramebuffer(target, framebuffer);
}

void glBindFramebufferEXT(GLenum target, GLuint framebuffer)
{
    return glmixedbinding::Binding::BindFramebufferEXT(target, framebuffer);
}

void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
{
    return glmixedbinding::Binding::BindImageTexture(unit, texture, level, layered, layer, access, format);
}

void glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format)
{
    return glmixedbinding::Binding::BindImageTextureEXT(index, texture, level, layered, layer, access, format);
}

void glBindImageTextures(GLuint first, GLsizei count, const GLuint * textures)
{
    return glmixedbinding::Binding::BindImageTextures(first, count, textures);
}

GLuint glBindLightParameterEXT(GLenum light, GLenum value)
{
    return glmixedbinding::Binding::BindLightParameterEXT(light, value);
}

GLuint glBindMaterialParameterEXT(GLenum face, GLenum value)
{
    return glmixedbinding::Binding::BindMaterialParameterEXT(face, value);
}

void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture)
{
    return glmixedbinding::Binding::BindMultiTextureEXT(texunit, target, texture);
}

GLuint glBindParameterEXT(GLenum value)
{
    return glmixedbinding::Binding::BindParameterEXT(value);
}

void glBindProgramARB(GLenum target, GLuint program)
{
    return glmixedbinding::Binding::BindProgramARB(target, program);
}

void glBindProgramNV(GLenum target, GLuint id)
{
    return glmixedbinding::Binding::BindProgramNV(target, id);
}

void glBindProgramPipeline(GLuint pipeline)
{
    return glmixedbinding::Binding::BindProgramPipeline(pipeline);
}

void glBindProgramPipelineEXT(GLuint pipeline)
{
    return glmixedbinding::Binding::BindProgramPipelineEXT(pipeline);
}

void glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
    return glmixedbinding::Binding::BindRenderbuffer(target, renderbuffer);
}

void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer)
{
    return glmixedbinding::Binding::BindRenderbufferEXT(target, renderbuffer);
}

void glBindSampler(GLuint unit, GLuint sampler)
{
    return glmixedbinding::Binding::BindSampler(unit, sampler);
}

void glBindSamplers(GLuint first, GLsizei count, const GLuint * samplers)
{
    return glmixedbinding::Binding::BindSamplers(first, count, samplers);
}

void glBindShadingRateImageNV(GLuint texture)
{
    return glmixedbinding::Binding::BindShadingRateImageNV(texture);
}

GLuint glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value)
{
    return glmixedbinding::Binding::BindTexGenParameterEXT(unit, coord, value);
}

void glBindTexture(GLenum target, GLuint texture)
{
    return glmixedbinding::Binding::BindTexture(target, texture);
}

void glBindTextureEXT(GLenum target, GLuint texture)
{
    return glmixedbinding::Binding::BindTextureEXT(target, texture);
}

void glBindTextures(GLuint first, GLsizei count, const GLuint * textures)
{
    return glmixedbinding::Binding::BindTextures(first, count, textures);
}

void glBindTextureUnit(GLuint unit, GLuint texture)
{
    return glmixedbinding::Binding::BindTextureUnit(unit, texture);
}

GLuint glBindTextureUnitParameterEXT(GLenum unit, GLenum value)
{
    return glmixedbinding::Binding::BindTextureUnitParameterEXT(unit, value);
}

void glBindTransformFeedback(GLenum target, GLuint id)
{
    return glmixedbinding::Binding::BindTransformFeedback(target, id);
}

void glBindTransformFeedbackNV(GLenum target, GLuint id)
{
    return glmixedbinding::Binding::BindTransformFeedbackNV(target, id);
}

void glBindVertexArray(GLuint array)
{
    return glmixedbinding::Binding::BindVertexArray(array);
}

void glBindVertexArrayAPPLE(GLuint array)
{
    return glmixedbinding::Binding::BindVertexArrayAPPLE(array);
}

void glBindVertexArrayOES(GLuint array)
{
    return glmixedbinding::Binding::BindVertexArrayOES(array);
}

void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
    return glmixedbinding::Binding::BindVertexBuffer(bindingindex, buffer, offset, stride);
}

void glBindVertexBuffers(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides)
{
    return glmixedbinding::Binding::BindVertexBuffers(first, count, buffers, offsets, strides);
}

void glBindVertexShaderEXT(GLuint id)
{
    return glmixedbinding::Binding::BindVertexShaderEXT(id);
}

void glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset)
{
    return glmixedbinding::Binding::BindVideoCaptureStreamBufferNV(video_capture_slot, stream, frame_region, offset);
}

void glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture)
{
    return glmixedbinding::Binding::BindVideoCaptureStreamTextureNV(video_capture_slot, stream, frame_region, target, texture);
}

void glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz)
{
    return glmixedbinding::Binding::Binormal3bEXT(bx, by, bz);
}

void glBinormal3bvEXT(const GLbyte * v)
{
    return glmixedbinding::Binding::Binormal3bvEXT(v);
}

void glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz)
{
    return glmixedbinding::Binding::Binormal3dEXT(bx, by, bz);
}

void glBinormal3dvEXT(const GLdouble * v)
{
    return glmixedbinding::Binding::Binormal3dvEXT(v);
}

void glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz)
{
    return glmixedbinding::Binding::Binormal3fEXT(bx, by, bz);
}

void glBinormal3fvEXT(const GLfloat * v)
{
    return glmixedbinding::Binding::Binormal3fvEXT(v);
}

void glBinormal3iEXT(GLint bx, GLint by, GLint bz)
{
    return glmixedbinding::Binding::Binormal3iEXT(bx, by, bz);
}

void glBinormal3ivEXT(const GLint * v)
{
    return glmixedbinding::Binding::Binormal3ivEXT(v);
}

void glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz)
{
    return glmixedbinding::Binding::Binormal3sEXT(bx, by, bz);
}

void glBinormal3svEXT(const GLshort * v)
{
    return glmixedbinding::Binding::Binormal3svEXT(v);
}

void glBinormalPointerEXT(GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::BinormalPointerEXT(type, stride, pointer);
}

void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap)
{
    return glmixedbinding::Binding::Bitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
}

void glBitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte * bitmap)
{
    return glmixedbinding::Binding::BitmapxOES(width, height, xorig, yorig, xmove, ymove, bitmap);
}

void glBlendBarrier()
{
    return glmixedbinding::Binding::BlendBarrier();
}

void glBlendBarrierKHR()
{
    return glmixedbinding::Binding::BlendBarrierKHR();
}

void glBlendBarrierNV()
{
    return glmixedbinding::Binding::BlendBarrierNV();
}

void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    return glmixedbinding::Binding::BlendColor(red, green, blue, alpha);
}

void glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    return glmixedbinding::Binding::BlendColorEXT(red, green, blue, alpha);
}

void glBlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha)
{
    return glmixedbinding::Binding::BlendColorxOES(red, green, blue, alpha);
}

void glBlendEquation(GLenum mode)
{
    return glmixedbinding::Binding::BlendEquation(mode);
}

void glBlendEquationEXT(GLenum mode)
{
    return glmixedbinding::Binding::BlendEquationEXT(mode);
}

void glBlendEquationi(GLuint buf, GLenum mode)
{
    return glmixedbinding::Binding::BlendEquationi(buf, mode);
}

void glBlendEquationiARB(GLuint buf, GLenum mode)
{
    return glmixedbinding::Binding::BlendEquationiARB(buf, mode);
}

void glBlendEquationiEXT(GLuint buf, GLenum mode)
{
    return glmixedbinding::Binding::BlendEquationiEXT(buf, mode);
}

void glBlendEquationIndexedAMD(GLuint buf, GLenum mode)
{
    return glmixedbinding::Binding::BlendEquationIndexedAMD(buf, mode);
}

void glBlendEquationiOES(GLuint buf, GLenum mode)
{
    return glmixedbinding::Binding::BlendEquationiOES(buf, mode);
}

void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    return glmixedbinding::Binding::BlendEquationSeparate(modeRGB, modeAlpha);
}

void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha)
{
    return glmixedbinding::Binding::BlendEquationSeparateEXT(modeRGB, modeAlpha);
}

void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
    return glmixedbinding::Binding::BlendEquationSeparatei(buf, modeRGB, modeAlpha);
}

void glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
    return glmixedbinding::Binding::BlendEquationSeparateiARB(buf, modeRGB, modeAlpha);
}

void glBlendEquationSeparateiEXT(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
    return glmixedbinding::Binding::BlendEquationSeparateiEXT(buf, modeRGB, modeAlpha);
}

void glBlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
    return glmixedbinding::Binding::BlendEquationSeparateIndexedAMD(buf, modeRGB, modeAlpha);
}

void glBlendEquationSeparateiOES(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
    return glmixedbinding::Binding::BlendEquationSeparateiOES(buf, modeRGB, modeAlpha);
}

void glBlendFunc(GLenum sfactor, GLenum dfactor)
{
    return glmixedbinding::Binding::BlendFunc(sfactor, dfactor);
}

void glBlendFunci(GLuint buf, GLenum src, GLenum dst)
{
    return glmixedbinding::Binding::BlendFunci(buf, src, dst);
}

void glBlendFunciARB(GLuint buf, GLenum src, GLenum dst)
{
    return glmixedbinding::Binding::BlendFunciARB(buf, src, dst);
}

void glBlendFunciEXT(GLuint buf, GLenum src, GLenum dst)
{
    return glmixedbinding::Binding::BlendFunciEXT(buf, src, dst);
}

void glBlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst)
{
    return glmixedbinding::Binding::BlendFuncIndexedAMD(buf, src, dst);
}

void glBlendFunciOES(GLuint buf, GLenum src, GLenum dst)
{
    return glmixedbinding::Binding::BlendFunciOES(buf, src, dst);
}

void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
    return glmixedbinding::Binding::BlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
    return glmixedbinding::Binding::BlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    return glmixedbinding::Binding::BlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    return glmixedbinding::Binding::BlendFuncSeparateiARB(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glBlendFuncSeparateiEXT(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    return glmixedbinding::Binding::BlendFuncSeparateiEXT(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glBlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    return glmixedbinding::Binding::BlendFuncSeparateIndexedAMD(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
    return glmixedbinding::Binding::BlendFuncSeparateINGR(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void glBlendFuncSeparateiOES(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    return glmixedbinding::Binding::BlendFuncSeparateiOES(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glBlendParameteriNV(GLenum pname, GLint value)
{
    return glmixedbinding::Binding::BlendParameteriNV(pname, value);
}

void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, ClearBufferMask mask, GLenum filter)
{
    return glmixedbinding::Binding::BlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glBlitFramebufferANGLE(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, ClearBufferMask mask, GLenum filter)
{
    return glmixedbinding::Binding::BlitFramebufferANGLE(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, ClearBufferMask mask, GLenum filter)
{
    return glmixedbinding::Binding::BlitFramebufferEXT(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glBlitFramebufferLayerEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint srcLayer, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLint dstLayer, ClearBufferMask mask, GLenum filter)
{
    return glmixedbinding::Binding::BlitFramebufferLayerEXT(srcX0, srcY0, srcX1, srcY1, srcLayer, dstX0, dstY0, dstX1, dstY1, dstLayer, mask, filter);
}

void glBlitFramebufferLayersEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, ClearBufferMask mask, GLenum filter)
{
    return glmixedbinding::Binding::BlitFramebufferLayersEXT(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glBlitFramebufferNV(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, ClearBufferMask mask, GLenum filter)
{
    return glmixedbinding::Binding::BlitFramebufferNV(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, ClearBufferMask mask, GLenum filter)
{
    return glmixedbinding::Binding::BlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length)
{
    return glmixedbinding::Binding::BufferAddressRangeNV(pname, index, address, length);
}

void glBufferAttachMemoryNV(GLenum target, GLuint memory, GLuint64 offset)
{
    return glmixedbinding::Binding::BufferAttachMemoryNV(target, memory, offset);
}

void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage)
{
    return glmixedbinding::Binding::BufferData(target, size, data, usage);
}

void glBufferDataARB(GLenum target, GLsizeiptrARB size, const void * data, GLenum usage)
{
    return glmixedbinding::Binding::BufferDataARB(target, size, data, usage);
}

void glBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit)
{
    return glmixedbinding::Binding::BufferPageCommitmentARB(target, offset, size, commit);
}

void glBufferPageCommitmentMemNV(GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit)
{
    return glmixedbinding::Binding::BufferPageCommitmentMemNV(target, offset, size, memory, memOffset, commit);
}

void glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::BufferParameteriAPPLE(target, pname, param);
}

void glBufferStorage(GLenum target, GLsizeiptr size, const void * data, BufferStorageMask flags)
{
    return glmixedbinding::Binding::BufferStorage(target, size, data, flags);
}

void glBufferStorageEXT(GLenum target, GLsizeiptr size, const void * data, BufferStorageMask flags)
{
    return glmixedbinding::Binding::BufferStorageEXT(target, size, data, flags);
}

void glBufferStorageExternalEXT(GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, BufferStorageMask flags)
{
    return glmixedbinding::Binding::BufferStorageExternalEXT(target, offset, size, clientBuffer, flags);
}

void glBufferStorageMemEXT(GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset)
{
    return glmixedbinding::Binding::BufferStorageMemEXT(target, size, memory, offset);
}

void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data)
{
    return glmixedbinding::Binding::BufferSubData(target, offset, size, data);
}

void glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void * data)
{
    return glmixedbinding::Binding::BufferSubDataARB(target, offset, size, data);
}


} // namespace glmixed