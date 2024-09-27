
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glEdgeFlag(GLboolean flag)
{
    return glmixedbinding::Binding::EdgeFlag(flag);
}

void glEdgeFlagFormatNV(GLsizei stride)
{
    return glmixedbinding::Binding::EdgeFlagFormatNV(stride);
}

void glEdgeFlagPointer(GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::EdgeFlagPointer(stride, pointer);
}

void glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean * pointer)
{
    return glmixedbinding::Binding::EdgeFlagPointerEXT(stride, count, pointer);
}

void glEdgeFlagPointerListIBM(GLint stride, const GLboolean ** pointer, GLint ptrstride)
{
    return glmixedbinding::Binding::EdgeFlagPointerListIBM(stride, pointer, ptrstride);
}

void glEdgeFlagv(const GLboolean * flag)
{
    return glmixedbinding::Binding::EdgeFlagv(flag);
}

void glEGLImageTargetRenderbufferStorageOES(GLenum target, GLeglImageOES image)
{
    return glmixedbinding::Binding::EGLImageTargetRenderbufferStorageOES(target, image);
}

void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, const GLint* attrib_list)
{
    return glmixedbinding::Binding::EGLImageTargetTexStorageEXT(target, image, attrib_list);
}

void glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image)
{
    return glmixedbinding::Binding::EGLImageTargetTexture2DOES(target, image);
}

void glEGLImageTargetTextureStorageEXT(GLuint texture, GLeglImageOES image, const GLint* attrib_list)
{
    return glmixedbinding::Binding::EGLImageTargetTextureStorageEXT(texture, image, attrib_list);
}

void glElementPointerAPPLE(GLenum type, const void * pointer)
{
    return glmixedbinding::Binding::ElementPointerAPPLE(type, pointer);
}

void glElementPointerATI(GLenum type, const void * pointer)
{
    return glmixedbinding::Binding::ElementPointerATI(type, pointer);
}

void glEnable(GLenum cap)
{
    return glmixedbinding::Binding::Enable(cap);
}

void glEnableClientState(GLenum array)
{
    return glmixedbinding::Binding::EnableClientState(array);
}

void glEnableClientStateiEXT(GLenum array, GLuint index)
{
    return glmixedbinding::Binding::EnableClientStateiEXT(array, index);
}

void glEnableClientStateIndexedEXT(GLenum array, GLuint index)
{
    return glmixedbinding::Binding::EnableClientStateIndexedEXT(array, index);
}

void glEnableDriverControlQCOM(GLuint driverControl)
{
    return glmixedbinding::Binding::EnableDriverControlQCOM(driverControl);
}

void glEnablei(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::Enablei(target, index);
}

void glEnableiEXT(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::EnableiEXT(target, index);
}

void glEnableIndexedEXT(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::EnableIndexedEXT(target, index);
}

void glEnableiNV(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::EnableiNV(target, index);
}

void glEnableiOES(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::EnableiOES(target, index);
}

void glEnableVariantClientStateEXT(GLuint id)
{
    return glmixedbinding::Binding::EnableVariantClientStateEXT(id);
}

void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index)
{
    return glmixedbinding::Binding::EnableVertexArrayAttrib(vaobj, index);
}

void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index)
{
    return glmixedbinding::Binding::EnableVertexArrayAttribEXT(vaobj, index);
}

void glEnableVertexArrayEXT(GLuint vaobj, GLenum array)
{
    return glmixedbinding::Binding::EnableVertexArrayEXT(vaobj, array);
}

void glEnableVertexAttribAPPLE(GLuint index, GLenum pname)
{
    return glmixedbinding::Binding::EnableVertexAttribAPPLE(index, pname);
}

void glEnableVertexAttribArray(GLuint index)
{
    return glmixedbinding::Binding::EnableVertexAttribArray(index);
}

void glEnableVertexAttribArrayARB(GLuint index)
{
    return glmixedbinding::Binding::EnableVertexAttribArrayARB(index);
}

void glEnd()
{
    return glmixedbinding::Binding::End();
}

void glEndConditionalRender()
{
    return glmixedbinding::Binding::EndConditionalRender();
}

void glEndConditionalRenderNV()
{
    return glmixedbinding::Binding::EndConditionalRenderNV();
}

void glEndConditionalRenderNVX()
{
    return glmixedbinding::Binding::EndConditionalRenderNVX();
}

void glEndFragmentShaderATI()
{
    return glmixedbinding::Binding::EndFragmentShaderATI();
}

void glEndList()
{
    return glmixedbinding::Binding::EndList();
}

void glEndOcclusionQueryNV()
{
    return glmixedbinding::Binding::EndOcclusionQueryNV();
}

void glEndPerfMonitorAMD(GLuint monitor)
{
    return glmixedbinding::Binding::EndPerfMonitorAMD(monitor);
}

void glEndPerfQueryINTEL(GLuint queryHandle)
{
    return glmixedbinding::Binding::EndPerfQueryINTEL(queryHandle);
}

void glEndQuery(GLenum target)
{
    return glmixedbinding::Binding::EndQuery(target);
}

void glEndQueryARB(GLenum target)
{
    return glmixedbinding::Binding::EndQueryARB(target);
}

void glEndQueryEXT(GLenum target)
{
    return glmixedbinding::Binding::EndQueryEXT(target);
}

void glEndQueryIndexed(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::EndQueryIndexed(target, index);
}

void glEndTilingQCOM(GLbitfield preserveMask)
{
    return glmixedbinding::Binding::EndTilingQCOM(preserveMask);
}

void glEndTransformFeedback()
{
    return glmixedbinding::Binding::EndTransformFeedback();
}

void glEndTransformFeedbackEXT()
{
    return glmixedbinding::Binding::EndTransformFeedbackEXT();
}

void glEndTransformFeedbackNV()
{
    return glmixedbinding::Binding::EndTransformFeedbackNV();
}

void glEndVertexShaderEXT()
{
    return glmixedbinding::Binding::EndVertexShaderEXT();
}

void glEndVideoCaptureNV(GLuint video_capture_slot)
{
    return glmixedbinding::Binding::EndVideoCaptureNV(video_capture_slot);
}

void glEvalCoord1d(GLdouble u)
{
    return glmixedbinding::Binding::EvalCoord1d(u);
}

void glEvalCoord1dv(const GLdouble * u)
{
    return glmixedbinding::Binding::EvalCoord1dv(u);
}

void glEvalCoord1f(GLfloat u)
{
    return glmixedbinding::Binding::EvalCoord1f(u);
}

void glEvalCoord1fv(const GLfloat * u)
{
    return glmixedbinding::Binding::EvalCoord1fv(u);
}

void glEvalCoord1xOES(GLfixed u)
{
    return glmixedbinding::Binding::EvalCoord1xOES(u);
}

void glEvalCoord1xvOES(const GLfixed * coords)
{
    return glmixedbinding::Binding::EvalCoord1xvOES(coords);
}

void glEvalCoord2d(GLdouble u, GLdouble v)
{
    return glmixedbinding::Binding::EvalCoord2d(u, v);
}

void glEvalCoord2dv(const GLdouble * u)
{
    return glmixedbinding::Binding::EvalCoord2dv(u);
}

void glEvalCoord2f(GLfloat u, GLfloat v)
{
    return glmixedbinding::Binding::EvalCoord2f(u, v);
}

void glEvalCoord2fv(const GLfloat * u)
{
    return glmixedbinding::Binding::EvalCoord2fv(u);
}

void glEvalCoord2xOES(GLfixed u, GLfixed v)
{
    return glmixedbinding::Binding::EvalCoord2xOES(u, v);
}

void glEvalCoord2xvOES(const GLfixed * coords)
{
    return glmixedbinding::Binding::EvalCoord2xvOES(coords);
}

void glEvalMapsNV(GLenum target, GLenum mode)
{
    return glmixedbinding::Binding::EvalMapsNV(target, mode);
}

void glEvalMesh1(GLenum mode, GLint i1, GLint i2)
{
    return glmixedbinding::Binding::EvalMesh1(mode, i1, i2);
}

void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
{
    return glmixedbinding::Binding::EvalMesh2(mode, i1, i2, j1, j2);
}

void glEvalPoint1(GLint i)
{
    return glmixedbinding::Binding::EvalPoint1(i);
}

void glEvalPoint2(GLint i, GLint j)
{
    return glmixedbinding::Binding::EvalPoint2(i, j);
}

void glEvaluateDepthValuesARB()
{
    return glmixedbinding::Binding::EvaluateDepthValuesARB();
}

void glExecuteProgramNV(GLenum target, GLuint id, const GLfloat * params)
{
    return glmixedbinding::Binding::ExecuteProgramNV(target, id, params);
}

void glExtGetBufferPointervQCOM(GLenum target, void ** params)
{
    return glmixedbinding::Binding::ExtGetBufferPointervQCOM(target, params);
}

void glExtGetBuffersQCOM(GLuint * buffers, GLint maxBuffers, GLint * numBuffers)
{
    return glmixedbinding::Binding::ExtGetBuffersQCOM(buffers, maxBuffers, numBuffers);
}

void glExtGetFramebuffersQCOM(GLuint * framebuffers, GLint maxFramebuffers, GLint * numFramebuffers)
{
    return glmixedbinding::Binding::ExtGetFramebuffersQCOM(framebuffers, maxFramebuffers, numFramebuffers);
}

void glExtGetProgramBinarySourceQCOM(GLuint program, GLenum shadertype, GLchar * source, GLint * length)
{
    return glmixedbinding::Binding::ExtGetProgramBinarySourceQCOM(program, shadertype, source, length);
}

void glExtGetProgramsQCOM(GLuint * programs, GLint maxPrograms, GLint * numPrograms)
{
    return glmixedbinding::Binding::ExtGetProgramsQCOM(programs, maxPrograms, numPrograms);
}

void glExtGetRenderbuffersQCOM(GLuint * renderbuffers, GLint maxRenderbuffers, GLint * numRenderbuffers)
{
    return glmixedbinding::Binding::ExtGetRenderbuffersQCOM(renderbuffers, maxRenderbuffers, numRenderbuffers);
}

void glExtGetShadersQCOM(GLuint * shaders, GLint maxShaders, GLint * numShaders)
{
    return glmixedbinding::Binding::ExtGetShadersQCOM(shaders, maxShaders, numShaders);
}

void glExtGetTexLevelParameterivQCOM(GLuint texture, GLenum face, GLint level, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::ExtGetTexLevelParameterivQCOM(texture, face, level, pname, params);
}

void glExtGetTexSubImageQCOM(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, void * texels)
{
    return glmixedbinding::Binding::ExtGetTexSubImageQCOM(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, texels);
}

void glExtGetTexturesQCOM(GLuint * textures, GLint maxTextures, GLint * numTextures)
{
    return glmixedbinding::Binding::ExtGetTexturesQCOM(textures, maxTextures, numTextures);
}

GLboolean glExtIsProgramBinaryQCOM(GLuint program)
{
    return glmixedbinding::Binding::ExtIsProgramBinaryQCOM(program);
}

void glExtractComponentEXT(GLuint res, GLuint src, GLuint num)
{
    return glmixedbinding::Binding::ExtractComponentEXT(res, src, num);
}

void glExtrapolateTex2DQCOM(GLuint src1, GLuint src2, GLuint output, GLfloat scaleFactor)
{
    return glmixedbinding::Binding::ExtrapolateTex2DQCOM(src1, src2, output, scaleFactor);
}

void glExtTexObjectStateOverrideiQCOM(GLenum target, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::ExtTexObjectStateOverrideiQCOM(target, pname, param);
}


} // namespace glmixed