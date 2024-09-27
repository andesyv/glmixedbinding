
#include <gmock/gmock.h>


#include <glmixedbinding/gl10/glmixed.h>
#include <glmixedbinding/gl11/glmixed.h>
#include <glmixedbinding/gl12/glmixed.h>
#include <glmixedbinding/gl13/glmixed.h>
#include <glmixedbinding/gl14/glmixed.h>
#include <glmixedbinding/gl15/glmixed.h>
#include <glmixedbinding/gl20/glmixed.h>
#include <glmixedbinding/gl21/glmixed.h>
#include <glmixedbinding/gl30/glmixed.h>
#include <glmixedbinding/gl31/glmixed.h>
#include <glmixedbinding/gl32/glmixed.h>
#include <glmixedbinding/gl33/glmixed.h>
#include <glmixedbinding/gl40/glmixed.h>
#include <glmixedbinding/gl41/glmixed.h>
#include <glmixedbinding/gl42/glmixed.h>
#include <glmixedbinding/gl43/glmixed.h>
#include <glmixedbinding/gl44/glmixed.h>
#include <glmixedbinding/gl45/glmixed.h>
#include <glmixedbinding/gl46/glmixed.h>
#include <glmixedbinding/gles20/glmixed.h>
#include <glmixedbinding/gles30/glmixed.h>
#include <glmixedbinding/gles31/glmixed.h>
#include <glmixedbinding/gles32/glmixed.h>


TEST(AllVersions, Compilation)
{
    SUCCEED();  // compiling this file without errors and warnings results in successful test
}