
#include "Binding_pch.h"


using namespace glmixed;


namespace glmixedbinding
{


Function<void, GLenum, GLuint, GLsizei, const GLchar *> Binding::ObjectLabel("glObjectLabel");
Function<void, GLenum, GLuint, GLsizei, const GLchar *> Binding::ObjectLabelKHR("glObjectLabelKHR");
Function<void, const void *, GLsizei, const GLchar *> Binding::ObjectPtrLabel("glObjectPtrLabel");
Function<void, const void *, GLsizei, const GLchar *> Binding::ObjectPtrLabelKHR("glObjectPtrLabelKHR");
Function<GLenum, GLenum, GLuint, GLenum> Binding::ObjectPurgeableAPPLE("glObjectPurgeableAPPLE");
Function<GLenum, GLenum, GLuint, GLenum> Binding::ObjectUnpurgeableAPPLE("glObjectUnpurgeableAPPLE");
Function<void, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble> Binding::Ortho("glOrtho");
Function<void, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat> Binding::OrthofOES("glOrthofOES");
Function<void, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed> Binding::OrthoxOES("glOrthoxOES");


} // namespace glmixedbinding