
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer)
{
    return glmixedbinding::Binding::FeedbackBuffer(size, type, buffer);
}

void glFeedbackBufferxOES(GLsizei n, GLenum type, const GLfixed * buffer)
{
    return glmixedbinding::Binding::FeedbackBufferxOES(n, type, buffer);
}

GLsync glFenceSync(GLenum condition, GLbitfield flags)
{
    return glmixedbinding::Binding::FenceSync(condition, flags);
}

GLsync glFenceSyncAPPLE(GLenum condition, GLbitfield flags)
{
    return glmixedbinding::Binding::FenceSyncAPPLE(condition, flags);
}

void glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage)
{
    return glmixedbinding::Binding::FinalCombinerInputNV(variable, input, mapping, componentUsage);
}

void glFinish()
{
    return glmixedbinding::Binding::Finish();
}

GLint glFinishAsyncSGIX(GLuint * markerp)
{
    return glmixedbinding::Binding::FinishAsyncSGIX(markerp);
}

void glFinishFenceAPPLE(GLuint fence)
{
    return glmixedbinding::Binding::FinishFenceAPPLE(fence);
}

void glFinishFenceNV(GLuint fence)
{
    return glmixedbinding::Binding::FinishFenceNV(fence);
}

void glFinishObjectAPPLE(GLenum object, GLint name)
{
    return glmixedbinding::Binding::FinishObjectAPPLE(object, name);
}

void glFinishTextureSUNX()
{
    return glmixedbinding::Binding::FinishTextureSUNX();
}

void glFlush()
{
    return glmixedbinding::Binding::Flush();
}

void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
{
    return glmixedbinding::Binding::FlushMappedBufferRange(target, offset, length);
}

void glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size)
{
    return glmixedbinding::Binding::FlushMappedBufferRangeAPPLE(target, offset, size);
}

void glFlushMappedBufferRangeEXT(GLenum target, GLintptr offset, GLsizeiptr length)
{
    return glmixedbinding::Binding::FlushMappedBufferRangeEXT(target, offset, length);
}

void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
    return glmixedbinding::Binding::FlushMappedNamedBufferRange(buffer, offset, length);
}

void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
    return glmixedbinding::Binding::FlushMappedNamedBufferRangeEXT(buffer, offset, length);
}

void glFlushPixelDataRangeNV(GLenum target)
{
    return glmixedbinding::Binding::FlushPixelDataRangeNV(target);
}

void glFlushRasterSGIX()
{
    return glmixedbinding::Binding::FlushRasterSGIX();
}

void glFlushStaticDataIBM(GLenum target)
{
    return glmixedbinding::Binding::FlushStaticDataIBM(target);
}

void glFlushVertexArrayRangeAPPLE(GLsizei length, void * pointer)
{
    return glmixedbinding::Binding::FlushVertexArrayRangeAPPLE(length, pointer);
}

void glFlushVertexArrayRangeNV()
{
    return glmixedbinding::Binding::FlushVertexArrayRangeNV();
}

void glFogCoordd(GLdouble coord)
{
    return glmixedbinding::Binding::FogCoordd(coord);
}

void glFogCoorddEXT(GLdouble coord)
{
    return glmixedbinding::Binding::FogCoorddEXT(coord);
}

void glFogCoorddv(const GLdouble * coord)
{
    return glmixedbinding::Binding::FogCoorddv(coord);
}

void glFogCoorddvEXT(const GLdouble * coord)
{
    return glmixedbinding::Binding::FogCoorddvEXT(coord);
}

void glFogCoordf(GLfloat coord)
{
    return glmixedbinding::Binding::FogCoordf(coord);
}

void glFogCoordfEXT(GLfloat coord)
{
    return glmixedbinding::Binding::FogCoordfEXT(coord);
}

void glFogCoordFormatNV(GLenum type, GLsizei stride)
{
    return glmixedbinding::Binding::FogCoordFormatNV(type, stride);
}

void glFogCoordfv(const GLfloat * coord)
{
    return glmixedbinding::Binding::FogCoordfv(coord);
}

void glFogCoordfvEXT(const GLfloat * coord)
{
    return glmixedbinding::Binding::FogCoordfvEXT(coord);
}

void glFogCoordhNV(GLhalfNV fog)
{
    return glmixedbinding::Binding::FogCoordhNV(fog);
}

void glFogCoordhvNV(const GLhalfNV * fog)
{
    return glmixedbinding::Binding::FogCoordhvNV(fog);
}

void glFogCoordPointer(GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::FogCoordPointer(type, stride, pointer);
}

void glFogCoordPointerEXT(GLenum type, GLsizei stride, const void * pointer)
{
    return glmixedbinding::Binding::FogCoordPointerEXT(type, stride, pointer);
}

void glFogCoordPointerListIBM(GLenum type, GLint stride, const void ** pointer, GLint ptrstride)
{
    return glmixedbinding::Binding::FogCoordPointerListIBM(type, stride, pointer, ptrstride);
}

void glFogf(GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::Fogf(pname, param);
}

void glFogFuncSGIS(GLsizei n, const GLfloat * points)
{
    return glmixedbinding::Binding::FogFuncSGIS(n, points);
}

void glFogfv(GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::Fogfv(pname, params);
}

void glFogi(GLenum pname, GLint param)
{
    return glmixedbinding::Binding::Fogi(pname, param);
}

void glFogiv(GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::Fogiv(pname, params);
}

void glFogxOES(GLenum pname, GLfixed param)
{
    return glmixedbinding::Binding::FogxOES(pname, param);
}

void glFogxvOES(GLenum pname, const GLfixed * param)
{
    return glmixedbinding::Binding::FogxvOES(pname, param);
}

void glFragmentColorMaterialSGIX(GLenum face, GLenum mode)
{
    return glmixedbinding::Binding::FragmentColorMaterialSGIX(face, mode);
}

void glFragmentCoverageColorNV(GLuint color)
{
    return glmixedbinding::Binding::FragmentCoverageColorNV(color);
}

void glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::FragmentLightfSGIX(light, pname, param);
}

void glFragmentLightfvSGIX(GLenum light, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::FragmentLightfvSGIX(light, pname, params);
}

void glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::FragmentLightiSGIX(light, pname, param);
}

void glFragmentLightivSGIX(GLenum light, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::FragmentLightivSGIX(light, pname, params);
}

void glFragmentLightModelfSGIX(GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::FragmentLightModelfSGIX(pname, param);
}

void glFragmentLightModelfvSGIX(GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::FragmentLightModelfvSGIX(pname, params);
}

void glFragmentLightModeliSGIX(GLenum pname, GLint param)
{
    return glmixedbinding::Binding::FragmentLightModeliSGIX(pname, param);
}

void glFragmentLightModelivSGIX(GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::FragmentLightModelivSGIX(pname, params);
}

void glFragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::FragmentMaterialfSGIX(face, pname, param);
}

void glFragmentMaterialfvSGIX(GLenum face, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::FragmentMaterialfvSGIX(face, pname, params);
}

void glFragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::FragmentMaterialiSGIX(face, pname, param);
}

void glFragmentMaterialivSGIX(GLenum face, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::FragmentMaterialivSGIX(face, pname, params);
}

void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode)
{
    return glmixedbinding::Binding::FramebufferDrawBufferEXT(framebuffer, mode);
}

void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum * bufs)
{
    return glmixedbinding::Binding::FramebufferDrawBuffersEXT(framebuffer, n, bufs);
}

void glFramebufferFetchBarrierEXT()
{
    return glmixedbinding::Binding::FramebufferFetchBarrierEXT();
}

void glFramebufferFetchBarrierQCOM()
{
    return glmixedbinding::Binding::FramebufferFetchBarrierQCOM();
}

void glFramebufferFoveationConfigQCOM(GLuint framebuffer, GLuint numLayers, GLuint focalPointsPerLayer, GLuint requestedFeatures, GLuint * providedFeatures)
{
    return glmixedbinding::Binding::FramebufferFoveationConfigQCOM(framebuffer, numLayers, focalPointsPerLayer, requestedFeatures, providedFeatures);
}

void glFramebufferFoveationParametersQCOM(GLuint framebuffer, GLuint layer, GLuint focalPoint, GLfloat focalX, GLfloat focalY, GLfloat gainX, GLfloat gainY, GLfloat foveaArea)
{
    return glmixedbinding::Binding::FramebufferFoveationParametersQCOM(framebuffer, layer, focalPoint, focalX, focalY, gainX, gainY, foveaArea);
}

void glFramebufferParameteri(GLenum target, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::FramebufferParameteri(target, pname, param);
}

void glFramebufferParameteriMESA(GLenum target, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::FramebufferParameteriMESA(target, pname, param);
}

void glFramebufferPixelLocalStorageSizeEXT(GLuint target, GLsizei size)
{
    return glmixedbinding::Binding::FramebufferPixelLocalStorageSizeEXT(target, size);
}

void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode)
{
    return glmixedbinding::Binding::FramebufferReadBufferEXT(framebuffer, mode);
}

void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    return glmixedbinding::Binding::FramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    return glmixedbinding::Binding::FramebufferRenderbufferEXT(target, attachment, renderbuffertarget, renderbuffer);
}

void glFramebufferSampleLocationsfvARB(GLenum target, GLuint start, GLsizei count, const GLfloat * v)
{
    return glmixedbinding::Binding::FramebufferSampleLocationsfvARB(target, start, count, v);
}

void glFramebufferSampleLocationsfvNV(GLenum target, GLuint start, GLsizei count, const GLfloat * v)
{
    return glmixedbinding::Binding::FramebufferSampleLocationsfvNV(target, start, count, v);
}

void glFramebufferSamplePositionsfvAMD(GLenum target, GLuint numsamples, GLuint pixelindex, const GLfloat * values)
{
    return glmixedbinding::Binding::FramebufferSamplePositionsfvAMD(target, numsamples, pixelindex, values);
}

void glFramebufferShadingRateEXT(GLenum target, GLenum attachment, GLuint texture, GLint baseLayer, GLsizei numLayers, GLsizei texelWidth, GLsizei texelHeight)
{
    return glmixedbinding::Binding::FramebufferShadingRateEXT(target, attachment, texture, baseLayer, numLayers, texelWidth, texelHeight);
}

void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
    return glmixedbinding::Binding::FramebufferTexture(target, attachment, texture, level);
}

void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    return glmixedbinding::Binding::FramebufferTexture1D(target, attachment, textarget, texture, level);
}

void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    return glmixedbinding::Binding::FramebufferTexture1DEXT(target, attachment, textarget, texture, level);
}

void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    return glmixedbinding::Binding::FramebufferTexture2D(target, attachment, textarget, texture, level);
}

void glFramebufferTexture2DDownsampleIMG(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint xscale, GLint yscale)
{
    return glmixedbinding::Binding::FramebufferTexture2DDownsampleIMG(target, attachment, textarget, texture, level, xscale, yscale);
}

void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    return glmixedbinding::Binding::FramebufferTexture2DEXT(target, attachment, textarget, texture, level);
}

void glFramebufferTexture2DMultisampleEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples)
{
    return glmixedbinding::Binding::FramebufferTexture2DMultisampleEXT(target, attachment, textarget, texture, level, samples);
}

void glFramebufferTexture2DMultisampleIMG(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples)
{
    return glmixedbinding::Binding::FramebufferTexture2DMultisampleIMG(target, attachment, textarget, texture, level, samples);
}

void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
    return glmixedbinding::Binding::FramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
}

void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
    return glmixedbinding::Binding::FramebufferTexture3DEXT(target, attachment, textarget, texture, level, zoffset);
}

void glFramebufferTexture3DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
    return glmixedbinding::Binding::FramebufferTexture3DOES(target, attachment, textarget, texture, level, zoffset);
}

void glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
    return glmixedbinding::Binding::FramebufferTextureARB(target, attachment, texture, level);
}

void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
    return glmixedbinding::Binding::FramebufferTextureEXT(target, attachment, texture, level);
}

void glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
    return glmixedbinding::Binding::FramebufferTextureFaceARB(target, attachment, texture, level, face);
}

void glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
    return glmixedbinding::Binding::FramebufferTextureFaceEXT(target, attachment, texture, level, face);
}

void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    return glmixedbinding::Binding::FramebufferTextureLayer(target, attachment, texture, level, layer);
}

void glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    return glmixedbinding::Binding::FramebufferTextureLayerARB(target, attachment, texture, level, layer);
}

void glFramebufferTextureLayerDownsampleIMG(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, GLint xscale, GLint yscale)
{
    return glmixedbinding::Binding::FramebufferTextureLayerDownsampleIMG(target, attachment, texture, level, layer, xscale, yscale);
}

void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    return glmixedbinding::Binding::FramebufferTextureLayerEXT(target, attachment, texture, level, layer);
}

void glFramebufferTextureMultisampleMultiviewOVR(GLenum target, GLenum attachment, GLuint texture, GLint level, GLsizei samples, GLint baseViewIndex, GLsizei numViews)
{
    return glmixedbinding::Binding::FramebufferTextureMultisampleMultiviewOVR(target, attachment, texture, level, samples, baseViewIndex, numViews);
}

void glFramebufferTextureMultiviewOVR(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews)
{
    return glmixedbinding::Binding::FramebufferTextureMultiviewOVR(target, attachment, texture, level, baseViewIndex, numViews);
}

void glFramebufferTextureOES(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
    return glmixedbinding::Binding::FramebufferTextureOES(target, attachment, texture, level);
}

void glFrameTerminatorGREMEDY()
{
    return glmixedbinding::Binding::FrameTerminatorGREMEDY();
}

void glFrameZoomSGIX(GLint factor)
{
    return glmixedbinding::Binding::FrameZoomSGIX(factor);
}

void glFreeObjectBufferATI(GLuint buffer)
{
    return glmixedbinding::Binding::FreeObjectBufferATI(buffer);
}

void glFrontFace(GLenum mode)
{
    return glmixedbinding::Binding::FrontFace(mode);
}

void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    return glmixedbinding::Binding::Frustum(left, right, bottom, top, zNear, zFar);
}

void glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f)
{
    return glmixedbinding::Binding::FrustumfOES(l, r, b, t, n, f);
}

void glFrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f)
{
    return glmixedbinding::Binding::FrustumxOES(l, r, b, t, n, f);
}


} // namespace glmixed