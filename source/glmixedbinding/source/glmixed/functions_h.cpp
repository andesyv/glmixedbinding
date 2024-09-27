
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glHint(GLenum target, GLenum mode)
{
    return glmixedbinding::Binding::Hint(target, mode);
}

void glHintPGI(GLenum target, VertexHintsMaskPGI mode)
{
    return glmixedbinding::Binding::HintPGI(target, mode);
}

void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
{
    return glmixedbinding::Binding::Histogram(target, width, internalformat, sink);
}

void glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
{
    return glmixedbinding::Binding::HistogramEXT(target, width, internalformat, sink);
}


} // namespace glmixed