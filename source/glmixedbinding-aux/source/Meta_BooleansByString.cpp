
#include "Meta_Maps.h"

#include <glmixedbinding/glmixed/boolean.h>


using namespace glmixed;


namespace glmixedbinding { namespace aux
{


const std::unordered_map<std::string, GLboolean> Meta_BooleansByString =
{
    { "GL_FALSE", glmixed::GL_FALSE },
    { "GL_TRUE", glmixed::GL_TRUE }
};


} } // namespace glmixedbinding::aux