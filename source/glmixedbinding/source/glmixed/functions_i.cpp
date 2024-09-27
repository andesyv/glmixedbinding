
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glIglooInterfaceSGIX(GLenum pname, const void * params)
{
    return glmixedbinding::Binding::IglooInterfaceSGIX(pname, params);
}

void glImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::ImageTransformParameterfHP(target, pname, param);
}

void glImageTransformParameterfvHP(GLenum target, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::ImageTransformParameterfvHP(target, pname, params);
}

void glImageTransformParameteriHP(GLenum target, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::ImageTransformParameteriHP(target, pname, param);
}

void glImageTransformParameterivHP(GLenum target, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::ImageTransformParameterivHP(target, pname, params);
}

void glImportMemoryFdEXT(GLuint memory, GLuint64 size, GLenum handleType, GLint fd)
{
    return glmixedbinding::Binding::ImportMemoryFdEXT(memory, size, handleType, fd);
}

void glImportMemoryWin32HandleEXT(GLuint memory, GLuint64 size, GLenum handleType, void * handle)
{
    return glmixedbinding::Binding::ImportMemoryWin32HandleEXT(memory, size, handleType, handle);
}

void glImportMemoryWin32NameEXT(GLuint memory, GLuint64 size, GLenum handleType, const void * name)
{
    return glmixedbinding::Binding::ImportMemoryWin32NameEXT(memory, size, handleType, name);
}

void glImportSemaphoreFdEXT(GLuint semaphore, GLenum handleType, GLint fd)
{
    return glmixedbinding::Binding::ImportSemaphoreFdEXT(semaphore, handleType, fd);
}

void glImportSemaphoreWin32HandleEXT(GLuint semaphore, GLenum handleType, void * handle)
{
    return glmixedbinding::Binding::ImportSemaphoreWin32HandleEXT(semaphore, handleType, handle);
}

void glImportSemaphoreWin32NameEXT(GLuint semaphore, GLenum handleType, const void * name)
{
    return glmixedbinding::Binding::ImportSemaphoreWin32NameEXT(semaphore, handleType, name);
}

GLsync glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags)
{
    return glmixedbinding::Binding::ImportSyncEXT(external_sync_type, external_sync, flags);
}

void glIndexd(GLdouble c)
{
    return glmixedbinding::Binding::Indexd(c);
}

void glIndexdv(const GLdouble * c)
{
    return glmixedbinding::Binding::Indexdv(c);
}

void glIndexf(GLfloat c)
{
    return glmixedbinding::Binding::Indexf(c);
}

void glIndexFormatNV(GLenum type, GLsizei stride)
{
    return glmixedbinding::Binding::IndexFormatNV(type, stride);
}

void glIndexFuncEXT(GLenum func, GLclampf ref)
{
    return glmixedbinding::Binding::IndexFuncEXT(func, ref);
}

void glIndexfv(const GLfloat * c)
{
    return glmixedbinding::Binding::Indexfv(c);
}

void glIndexi(GLint c)
{
    return glmixedbinding::Binding::Indexi(c);
}

void glIndexiv(const GLint * c)
{
    return glmixedbinding::Binding::Indexiv(c);
}

void glIndexMask(GLuint mask)
{
    return glmixedbinding::Binding::IndexMask(mask);
}

void glIndexMaterialEXT(GLenum face, GLenum mode)
{
    return glmixedbinding::Binding::IndexMaterialEXT(face, mode);
}

void glIndexPointer(GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::IndexPointer(type, stride, pointer);
}

void glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void * pointer)
{
    return glmixedbinding::Binding::IndexPointerEXT(type, stride, count, pointer);
}

void glIndexPointerListIBM(GLenum type, GLint stride, const void ** pointer, GLint ptrstride)
{
    return glmixedbinding::Binding::IndexPointerListIBM(type, stride, pointer, ptrstride);
}

void glIndexs(GLshort c)
{
    return glmixedbinding::Binding::Indexs(c);
}

void glIndexsv(const GLshort * c)
{
    return glmixedbinding::Binding::Indexsv(c);
}

void glIndexub(GLubyte c)
{
    return glmixedbinding::Binding::Indexub(c);
}

void glIndexubv(const GLubyte * c)
{
    return glmixedbinding::Binding::Indexubv(c);
}

void glIndexxOES(GLfixed component)
{
    return glmixedbinding::Binding::IndexxOES(component);
}

void glIndexxvOES(const GLfixed * component)
{
    return glmixedbinding::Binding::IndexxvOES(component);
}

void glInitNames()
{
    return glmixedbinding::Binding::InitNames();
}

void glInsertComponentEXT(GLuint res, GLuint src, GLuint num)
{
    return glmixedbinding::Binding::InsertComponentEXT(res, src, num);
}

void glInsertEventMarkerEXT(GLsizei length, const GLchar * marker)
{
    return glmixedbinding::Binding::InsertEventMarkerEXT(length, marker);
}

void glInstrumentsBufferSGIX(GLsizei size, GLint * buffer)
{
    return glmixedbinding::Binding::InstrumentsBufferSGIX(size, buffer);
}

void glInterleavedArrays(GLenum format, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::InterleavedArrays(format, stride, pointer);
}

void glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight)
{
    return glmixedbinding::Binding::InterpolatePathsNV(resultPath, pathA, pathB, weight);
}

void glInvalidateBufferData(GLuint buffer)
{
    return glmixedbinding::Binding::InvalidateBufferData(buffer);
}

void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
    return glmixedbinding::Binding::InvalidateBufferSubData(buffer, offset, length);
}

void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments)
{
    return glmixedbinding::Binding::InvalidateFramebuffer(target, numAttachments, attachments);
}

void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments)
{
    return glmixedbinding::Binding::InvalidateNamedFramebufferData(framebuffer, numAttachments, attachments);
}

void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
    return glmixedbinding::Binding::InvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height);
}

void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
    return glmixedbinding::Binding::InvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
}

void glInvalidateTexImage(GLuint texture, GLint level)
{
    return glmixedbinding::Binding::InvalidateTexImage(texture, level);
}

void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)
{
    return glmixedbinding::Binding::InvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

GLboolean glIsAsyncMarkerSGIX(GLuint marker)
{
    return glmixedbinding::Binding::IsAsyncMarkerSGIX(marker);
}

GLboolean glIsBuffer(GLuint buffer)
{
    return glmixedbinding::Binding::IsBuffer(buffer);
}

GLboolean glIsBufferARB(GLuint buffer)
{
    return glmixedbinding::Binding::IsBufferARB(buffer);
}

GLboolean glIsBufferResidentNV(GLenum target)
{
    return glmixedbinding::Binding::IsBufferResidentNV(target);
}

GLboolean glIsCommandListNV(GLuint list)
{
    return glmixedbinding::Binding::IsCommandListNV(list);
}

GLboolean glIsEnabled(GLenum cap)
{
    return glmixedbinding::Binding::IsEnabled(cap);
}

GLboolean glIsEnabledi(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::IsEnabledi(target, index);
}

GLboolean glIsEnablediEXT(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::IsEnablediEXT(target, index);
}

GLboolean glIsEnabledIndexedEXT(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::IsEnabledIndexedEXT(target, index);
}

GLboolean glIsEnablediNV(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::IsEnablediNV(target, index);
}

GLboolean glIsEnablediOES(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::IsEnablediOES(target, index);
}

GLboolean glIsFenceAPPLE(GLuint fence)
{
    return glmixedbinding::Binding::IsFenceAPPLE(fence);
}

GLboolean glIsFenceNV(GLuint fence)
{
    return glmixedbinding::Binding::IsFenceNV(fence);
}

GLboolean glIsFramebuffer(GLuint framebuffer)
{
    return glmixedbinding::Binding::IsFramebuffer(framebuffer);
}

GLboolean glIsFramebufferEXT(GLuint framebuffer)
{
    return glmixedbinding::Binding::IsFramebufferEXT(framebuffer);
}

GLboolean glIsImageHandleResidentARB(GLuint64 handle)
{
    return glmixedbinding::Binding::IsImageHandleResidentARB(handle);
}

GLboolean glIsImageHandleResidentNV(GLuint64 handle)
{
    return glmixedbinding::Binding::IsImageHandleResidentNV(handle);
}

GLboolean glIsList(GLuint list)
{
    return glmixedbinding::Binding::IsList(list);
}

GLboolean glIsMemoryObjectEXT(GLuint memoryObject)
{
    return glmixedbinding::Binding::IsMemoryObjectEXT(memoryObject);
}

GLboolean glIsNameAMD(GLenum identifier, GLuint name)
{
    return glmixedbinding::Binding::IsNameAMD(identifier, name);
}

GLboolean glIsNamedBufferResidentNV(GLuint buffer)
{
    return glmixedbinding::Binding::IsNamedBufferResidentNV(buffer);
}

GLboolean glIsNamedStringARB(GLint namelen, const GLchar * name)
{
    return glmixedbinding::Binding::IsNamedStringARB(namelen, name);
}

GLboolean glIsObjectBufferATI(GLuint buffer)
{
    return glmixedbinding::Binding::IsObjectBufferATI(buffer);
}

GLboolean glIsOcclusionQueryNV(GLuint id)
{
    return glmixedbinding::Binding::IsOcclusionQueryNV(id);
}

GLboolean glIsPathNV(GLuint path)
{
    return glmixedbinding::Binding::IsPathNV(path);
}

GLboolean glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y)
{
    return glmixedbinding::Binding::IsPointInFillPathNV(path, mask, x, y);
}

GLboolean glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y)
{
    return glmixedbinding::Binding::IsPointInStrokePathNV(path, x, y);
}

GLboolean glIsProgram(GLuint program)
{
    return glmixedbinding::Binding::IsProgram(program);
}

GLboolean glIsProgramARB(GLuint program)
{
    return glmixedbinding::Binding::IsProgramARB(program);
}

GLboolean glIsProgramNV(GLuint id)
{
    return glmixedbinding::Binding::IsProgramNV(id);
}

GLboolean glIsProgramPipeline(GLuint pipeline)
{
    return glmixedbinding::Binding::IsProgramPipeline(pipeline);
}

GLboolean glIsProgramPipelineEXT(GLuint pipeline)
{
    return glmixedbinding::Binding::IsProgramPipelineEXT(pipeline);
}

GLboolean glIsQuery(GLuint id)
{
    return glmixedbinding::Binding::IsQuery(id);
}

GLboolean glIsQueryARB(GLuint id)
{
    return glmixedbinding::Binding::IsQueryARB(id);
}

GLboolean glIsQueryEXT(GLuint id)
{
    return glmixedbinding::Binding::IsQueryEXT(id);
}

GLboolean glIsRenderbuffer(GLuint renderbuffer)
{
    return glmixedbinding::Binding::IsRenderbuffer(renderbuffer);
}

GLboolean glIsRenderbufferEXT(GLuint renderbuffer)
{
    return glmixedbinding::Binding::IsRenderbufferEXT(renderbuffer);
}

GLboolean glIsSampler(GLuint sampler)
{
    return glmixedbinding::Binding::IsSampler(sampler);
}

GLboolean glIsSemaphoreEXT(GLuint semaphore)
{
    return glmixedbinding::Binding::IsSemaphoreEXT(semaphore);
}

GLboolean glIsShader(GLuint shader)
{
    return glmixedbinding::Binding::IsShader(shader);
}

GLboolean glIsStateNV(GLuint state)
{
    return glmixedbinding::Binding::IsStateNV(state);
}

GLboolean glIsSync(GLsync sync)
{
    return glmixedbinding::Binding::IsSync(sync);
}

GLboolean glIsSyncAPPLE(GLsync sync)
{
    return glmixedbinding::Binding::IsSyncAPPLE(sync);
}

GLboolean glIsTexture(GLuint texture)
{
    return glmixedbinding::Binding::IsTexture(texture);
}

GLboolean glIsTextureEXT(GLuint texture)
{
    return glmixedbinding::Binding::IsTextureEXT(texture);
}

GLboolean glIsTextureHandleResidentARB(GLuint64 handle)
{
    return glmixedbinding::Binding::IsTextureHandleResidentARB(handle);
}

GLboolean glIsTextureHandleResidentNV(GLuint64 handle)
{
    return glmixedbinding::Binding::IsTextureHandleResidentNV(handle);
}

GLboolean glIsTransformFeedback(GLuint id)
{
    return glmixedbinding::Binding::IsTransformFeedback(id);
}

GLboolean glIsTransformFeedbackNV(GLuint id)
{
    return glmixedbinding::Binding::IsTransformFeedbackNV(id);
}

GLboolean glIsVariantEnabledEXT(GLuint id, GLenum cap)
{
    return glmixedbinding::Binding::IsVariantEnabledEXT(id, cap);
}

GLboolean glIsVertexArray(GLuint array)
{
    return glmixedbinding::Binding::IsVertexArray(array);
}

GLboolean glIsVertexArrayAPPLE(GLuint array)
{
    return glmixedbinding::Binding::IsVertexArrayAPPLE(array);
}

GLboolean glIsVertexArrayOES(GLuint array)
{
    return glmixedbinding::Binding::IsVertexArrayOES(array);
}

GLboolean glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname)
{
    return glmixedbinding::Binding::IsVertexAttribEnabledAPPLE(index, pname);
}


} // namespace glmixed