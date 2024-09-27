
#include "Binding_pch.h"


using namespace glmixed;


namespace glmixedbinding
{


Function<void, GLenum, GLenum> Binding::Hint("glHint");
Function<void, GLenum, VertexHintsMaskPGI> Binding::HintPGI("glHintPGI");
Function<void, GLenum, GLsizei, GLenum, GLboolean> Binding::Histogram("glHistogram");
Function<void, GLenum, GLsizei, GLenum, GLboolean> Binding::HistogramEXT("glHistogramEXT");


} // namespace glmixedbinding