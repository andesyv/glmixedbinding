
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar * label)
{
    return glmixedbinding::Binding::LabelObjectEXT(type, object, length, label);
}

void glLGPUCopyImageSubDataNVX(GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srxY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth)
{
    return glmixedbinding::Binding::LGPUCopyImageSubDataNVX(sourceGpu, destinationGpuMask, srcName, srcTarget, srcLevel, srcX, srxY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
}

void glLGPUInterlockNVX()
{
    return glmixedbinding::Binding::LGPUInterlockNVX();
}

void glLGPUNamedBufferSubDataNVX(GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data)
{
    return glmixedbinding::Binding::LGPUNamedBufferSubDataNVX(gpuMask, buffer, offset, size, data);
}

void glLightEnviSGIX(GLenum pname, GLint param)
{
    return glmixedbinding::Binding::LightEnviSGIX(pname, param);
}

void glLightf(GLenum light, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::Lightf(light, pname, param);
}

void glLightfv(GLenum light, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::Lightfv(light, pname, params);
}

void glLighti(GLenum light, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::Lighti(light, pname, param);
}

void glLightiv(GLenum light, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::Lightiv(light, pname, params);
}

void glLightModelf(GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::LightModelf(pname, param);
}

void glLightModelfv(GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::LightModelfv(pname, params);
}

void glLightModeli(GLenum pname, GLint param)
{
    return glmixedbinding::Binding::LightModeli(pname, param);
}

void glLightModeliv(GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::LightModeliv(pname, params);
}

void glLightModelxOES(GLenum pname, GLfixed param)
{
    return glmixedbinding::Binding::LightModelxOES(pname, param);
}

void glLightModelxvOES(GLenum pname, const GLfixed * param)
{
    return glmixedbinding::Binding::LightModelxvOES(pname, param);
}

void glLightxOES(GLenum light, GLenum pname, GLfixed param)
{
    return glmixedbinding::Binding::LightxOES(light, pname, param);
}

void glLightxvOES(GLenum light, GLenum pname, const GLfixed * params)
{
    return glmixedbinding::Binding::LightxvOES(light, pname, params);
}

void glLineStipple(GLint factor, GLushort pattern)
{
    return glmixedbinding::Binding::LineStipple(factor, pattern);
}

void glLineWidth(GLfloat width)
{
    return glmixedbinding::Binding::LineWidth(width);
}

void glLineWidthxOES(GLfixed width)
{
    return glmixedbinding::Binding::LineWidthxOES(width);
}

void glLinkProgram(GLuint program)
{
    return glmixedbinding::Binding::LinkProgram(program);
}

void glLinkProgramARB(GLhandleARB programObj)
{
    return glmixedbinding::Binding::LinkProgramARB(programObj);
}

void glListBase(GLuint base)
{
    return glmixedbinding::Binding::ListBase(base);
}

void glListDrawCommandsStatesClientNV(GLuint list, GLuint segment, const void ** indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count)
{
    return glmixedbinding::Binding::ListDrawCommandsStatesClientNV(list, segment, indirects, sizes, states, fbos, count);
}

void glListParameterfSGIX(GLuint list, GLenum pname, GLfloat param)
{
    return glmixedbinding::Binding::ListParameterfSGIX(list, pname, param);
}

void glListParameterfvSGIX(GLuint list, GLenum pname, const GLfloat * params)
{
    return glmixedbinding::Binding::ListParameterfvSGIX(list, pname, params);
}

void glListParameteriSGIX(GLuint list, GLenum pname, GLint param)
{
    return glmixedbinding::Binding::ListParameteriSGIX(list, pname, param);
}

void glListParameterivSGIX(GLuint list, GLenum pname, const GLint * params)
{
    return glmixedbinding::Binding::ListParameterivSGIX(list, pname, params);
}

void glLoadIdentity()
{
    return glmixedbinding::Binding::LoadIdentity();
}

void glLoadIdentityDeformationMapSGIX(FfdMaskSGIX mask)
{
    return glmixedbinding::Binding::LoadIdentityDeformationMapSGIX(mask);
}

void glLoadMatrixd(const GLdouble * m)
{
    return glmixedbinding::Binding::LoadMatrixd(m);
}

void glLoadMatrixf(const GLfloat * m)
{
    return glmixedbinding::Binding::LoadMatrixf(m);
}

void glLoadMatrixxOES(const GLfixed * m)
{
    return glmixedbinding::Binding::LoadMatrixxOES(m);
}

void glLoadName(GLuint name)
{
    return glmixedbinding::Binding::LoadName(name);
}

void glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte * program)
{
    return glmixedbinding::Binding::LoadProgramNV(target, id, len, program);
}

void glLoadTransposeMatrixd(const GLdouble * m)
{
    return glmixedbinding::Binding::LoadTransposeMatrixd(m);
}

void glLoadTransposeMatrixdARB(const GLdouble * m)
{
    return glmixedbinding::Binding::LoadTransposeMatrixdARB(m);
}

void glLoadTransposeMatrixf(const GLfloat * m)
{
    return glmixedbinding::Binding::LoadTransposeMatrixf(m);
}

void glLoadTransposeMatrixfARB(const GLfloat * m)
{
    return glmixedbinding::Binding::LoadTransposeMatrixfARB(m);
}

void glLoadTransposeMatrixxOES(const GLfixed * m)
{
    return glmixedbinding::Binding::LoadTransposeMatrixxOES(m);
}

void glLockArraysEXT(GLint first, GLsizei count)
{
    return glmixedbinding::Binding::LockArraysEXT(first, count);
}

void glLogicOp(GLenum opcode)
{
    return glmixedbinding::Binding::LogicOp(opcode);
}


} // namespace glmixed