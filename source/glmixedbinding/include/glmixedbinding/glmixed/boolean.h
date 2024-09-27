
#pragma once


#include <glmixedbinding/Boolean32.h>

#include <glmixedbinding/glmixedbinding_api.h>
#include <glmixedbinding/glmixedbinding_features.h>
#include <glmixedbinding/noglmixed.h>


namespace glmixed
{


using GLboolean = glmixedbinding::Boolean32;


// import booleans to namespace

GLMIXEDBINDING_CONSTEXPR static const GLboolean GL_FALSE = GLboolean(0);
GLMIXEDBINDING_CONSTEXPR static const GLboolean GL_TRUE = GLboolean(1);


} // namespace glmixed