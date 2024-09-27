
#include "Meta_Maps.h"

#include <glmixedbinding/glmixed/boolean.h>


using namespace glmixed;


namespace glmixedbinding { namespace aux
{


const std::unordered_map<GLboolean, std::string> Meta_StringsByBoolean =
{
    { glmixed::GL_FALSE, "GL_FALSE" },
    { glmixed::GL_TRUE, "GL_TRUE" }
};


} } // namespace glmixedbinding::aux