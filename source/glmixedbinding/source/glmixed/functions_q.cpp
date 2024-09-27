
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glQueryCounter(GLuint id, GLenum target)
{
    return glmixedbinding::Binding::QueryCounter(id, target);
}

void glQueryCounterEXT(GLuint id, GLenum target)
{
    return glmixedbinding::Binding::QueryCounterEXT(id, target);
}

GLbitfield glQueryMatrixxOES(GLfixed * mantissa, GLint * exponent)
{
    return glmixedbinding::Binding::QueryMatrixxOES(mantissa, exponent);
}

void glQueryObjectParameteruiAMD(GLenum target, GLuint id, GLenum pname, OcclusionQueryEventMaskAMD param)
{
    return glmixedbinding::Binding::QueryObjectParameteruiAMD(target, id, pname, param);
}

GLint glQueryResourceNV(GLenum queryType, GLint tagId, GLuint count, GLint * buffer)
{
    return glmixedbinding::Binding::QueryResourceNV(queryType, tagId, count, buffer);
}

void glQueryResourceTagNV(GLint tagId, const GLchar * tagString)
{
    return glmixedbinding::Binding::QueryResourceTagNV(tagId, tagString);
}


} // namespace glmixed