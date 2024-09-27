
#include "Binding_pch.h"


using namespace glmixed;


namespace glmixedbinding
{


Function<void, GLuint, GLenum> Binding::QueryCounter("glQueryCounter");
Function<void, GLuint, GLenum> Binding::QueryCounterEXT("glQueryCounterEXT");
Function<GLbitfield, GLfixed *, GLint *> Binding::QueryMatrixxOES("glQueryMatrixxOES");
Function<void, GLenum, GLuint, GLenum, OcclusionQueryEventMaskAMD> Binding::QueryObjectParameteruiAMD("glQueryObjectParameteruiAMD");
Function<GLint, GLenum, GLint, GLuint, GLint *> Binding::QueryResourceNV("glQueryResourceNV");
Function<void, GLint, const GLchar *> Binding::QueryResourceTagNV("glQueryResourceTagNV");


} // namespace glmixedbinding