
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar * label)
{
    return glmixedbinding::Binding::ObjectLabel(identifier, name, length, label);
}

void glObjectLabelKHR(GLenum identifier, GLuint name, GLsizei length, const GLchar * label)
{
    return glmixedbinding::Binding::ObjectLabelKHR(identifier, name, length, label);
}

void glObjectPtrLabel(const void * ptr, GLsizei length, const GLchar * label)
{
    return glmixedbinding::Binding::ObjectPtrLabel(ptr, length, label);
}

void glObjectPtrLabelKHR(const void * ptr, GLsizei length, const GLchar * label)
{
    return glmixedbinding::Binding::ObjectPtrLabelKHR(ptr, length, label);
}

GLenum glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option)
{
    return glmixedbinding::Binding::ObjectPurgeableAPPLE(objectType, name, option);
}

GLenum glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option)
{
    return glmixedbinding::Binding::ObjectUnpurgeableAPPLE(objectType, name, option);
}

void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    return glmixedbinding::Binding::Ortho(left, right, bottom, top, zNear, zFar);
}

void glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f)
{
    return glmixedbinding::Binding::OrthofOES(l, r, b, t, n, f);
}

void glOrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f)
{
    return glmixedbinding::Binding::OrthoxOES(l, r, b, t, n, f);
}


} // namespace glmixed