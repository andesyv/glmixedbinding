
#include "Binding_pch.h"


using namespace glmixed;


namespace glmixedbinding
{


Function<void, GLboolean> Binding::EdgeFlag("glEdgeFlag");
Function<void, GLsizei> Binding::EdgeFlagFormatNV("glEdgeFlagFormatNV");
Function<void, GLsizei, const void *> Binding::EdgeFlagPointer("glEdgeFlagPointer");
Function<void, GLsizei, GLsizei, const GLboolean *> Binding::EdgeFlagPointerEXT("glEdgeFlagPointerEXT");
Function<void, GLint, const GLboolean **, GLint> Binding::EdgeFlagPointerListIBM("glEdgeFlagPointerListIBM");
Function<void, const GLboolean *> Binding::EdgeFlagv("glEdgeFlagv");
Function<void, GLenum, GLeglImageOES> Binding::EGLImageTargetRenderbufferStorageOES("glEGLImageTargetRenderbufferStorageOES");
Function<void, GLenum, GLeglImageOES, const GLint*> Binding::EGLImageTargetTexStorageEXT("glEGLImageTargetTexStorageEXT");
Function<void, GLenum, GLeglImageOES> Binding::EGLImageTargetTexture2DOES("glEGLImageTargetTexture2DOES");
Function<void, GLuint, GLeglImageOES, const GLint*> Binding::EGLImageTargetTextureStorageEXT("glEGLImageTargetTextureStorageEXT");
Function<void, GLenum, const void *> Binding::ElementPointerAPPLE("glElementPointerAPPLE");
Function<void, GLenum, const void *> Binding::ElementPointerATI("glElementPointerATI");
Function<void, GLenum> Binding::Enable("glEnable");
Function<void, GLenum> Binding::EnableClientState("glEnableClientState");
Function<void, GLenum, GLuint> Binding::EnableClientStateiEXT("glEnableClientStateiEXT");
Function<void, GLenum, GLuint> Binding::EnableClientStateIndexedEXT("glEnableClientStateIndexedEXT");
Function<void, GLuint> Binding::EnableDriverControlQCOM("glEnableDriverControlQCOM");
Function<void, GLenum, GLuint> Binding::Enablei("glEnablei");
Function<void, GLenum, GLuint> Binding::EnableiEXT("glEnableiEXT");
Function<void, GLenum, GLuint> Binding::EnableIndexedEXT("glEnableIndexedEXT");
Function<void, GLenum, GLuint> Binding::EnableiNV("glEnableiNV");
Function<void, GLenum, GLuint> Binding::EnableiOES("glEnableiOES");
Function<void, GLuint> Binding::EnableVariantClientStateEXT("glEnableVariantClientStateEXT");
Function<void, GLuint, GLuint> Binding::EnableVertexArrayAttrib("glEnableVertexArrayAttrib");
Function<void, GLuint, GLuint> Binding::EnableVertexArrayAttribEXT("glEnableVertexArrayAttribEXT");
Function<void, GLuint, GLenum> Binding::EnableVertexArrayEXT("glEnableVertexArrayEXT");
Function<void, GLuint, GLenum> Binding::EnableVertexAttribAPPLE("glEnableVertexAttribAPPLE");
Function<void, GLuint> Binding::EnableVertexAttribArray("glEnableVertexAttribArray");
Function<void, GLuint> Binding::EnableVertexAttribArrayARB("glEnableVertexAttribArrayARB");
Function<void> Binding::End("glEnd");
Function<void> Binding::EndConditionalRender("glEndConditionalRender");
Function<void> Binding::EndConditionalRenderNV("glEndConditionalRenderNV");
Function<void> Binding::EndConditionalRenderNVX("glEndConditionalRenderNVX");
Function<void> Binding::EndFragmentShaderATI("glEndFragmentShaderATI");
Function<void> Binding::EndList("glEndList");
Function<void> Binding::EndOcclusionQueryNV("glEndOcclusionQueryNV");
Function<void, GLuint> Binding::EndPerfMonitorAMD("glEndPerfMonitorAMD");
Function<void, GLuint> Binding::EndPerfQueryINTEL("glEndPerfQueryINTEL");
Function<void, GLenum> Binding::EndQuery("glEndQuery");
Function<void, GLenum> Binding::EndQueryARB("glEndQueryARB");
Function<void, GLenum> Binding::EndQueryEXT("glEndQueryEXT");
Function<void, GLenum, GLuint> Binding::EndQueryIndexed("glEndQueryIndexed");
Function<void, GLbitfield> Binding::EndTilingQCOM("glEndTilingQCOM");
Function<void> Binding::EndTransformFeedback("glEndTransformFeedback");
Function<void> Binding::EndTransformFeedbackEXT("glEndTransformFeedbackEXT");
Function<void> Binding::EndTransformFeedbackNV("glEndTransformFeedbackNV");
Function<void> Binding::EndVertexShaderEXT("glEndVertexShaderEXT");
Function<void, GLuint> Binding::EndVideoCaptureNV("glEndVideoCaptureNV");
Function<void, GLdouble> Binding::EvalCoord1d("glEvalCoord1d");
Function<void, const GLdouble *> Binding::EvalCoord1dv("glEvalCoord1dv");
Function<void, GLfloat> Binding::EvalCoord1f("glEvalCoord1f");
Function<void, const GLfloat *> Binding::EvalCoord1fv("glEvalCoord1fv");
Function<void, GLfixed> Binding::EvalCoord1xOES("glEvalCoord1xOES");
Function<void, const GLfixed *> Binding::EvalCoord1xvOES("glEvalCoord1xvOES");
Function<void, GLdouble, GLdouble> Binding::EvalCoord2d("glEvalCoord2d");
Function<void, const GLdouble *> Binding::EvalCoord2dv("glEvalCoord2dv");
Function<void, GLfloat, GLfloat> Binding::EvalCoord2f("glEvalCoord2f");
Function<void, const GLfloat *> Binding::EvalCoord2fv("glEvalCoord2fv");
Function<void, GLfixed, GLfixed> Binding::EvalCoord2xOES("glEvalCoord2xOES");
Function<void, const GLfixed *> Binding::EvalCoord2xvOES("glEvalCoord2xvOES");
Function<void, GLenum, GLenum> Binding::EvalMapsNV("glEvalMapsNV");
Function<void, GLenum, GLint, GLint> Binding::EvalMesh1("glEvalMesh1");
Function<void, GLenum, GLint, GLint, GLint, GLint> Binding::EvalMesh2("glEvalMesh2");
Function<void, GLint> Binding::EvalPoint1("glEvalPoint1");
Function<void, GLint, GLint> Binding::EvalPoint2("glEvalPoint2");
Function<void> Binding::EvaluateDepthValuesARB("glEvaluateDepthValuesARB");
Function<void, GLenum, GLuint, const GLfloat *> Binding::ExecuteProgramNV("glExecuteProgramNV");
Function<void, GLenum, void **> Binding::ExtGetBufferPointervQCOM("glExtGetBufferPointervQCOM");
Function<void, GLuint *, GLint, GLint *> Binding::ExtGetBuffersQCOM("glExtGetBuffersQCOM");
Function<void, GLuint *, GLint, GLint *> Binding::ExtGetFramebuffersQCOM("glExtGetFramebuffersQCOM");
Function<void, GLuint, GLenum, GLchar *, GLint *> Binding::ExtGetProgramBinarySourceQCOM("glExtGetProgramBinarySourceQCOM");
Function<void, GLuint *, GLint, GLint *> Binding::ExtGetProgramsQCOM("glExtGetProgramsQCOM");
Function<void, GLuint *, GLint, GLint *> Binding::ExtGetRenderbuffersQCOM("glExtGetRenderbuffersQCOM");
Function<void, GLuint *, GLint, GLint *> Binding::ExtGetShadersQCOM("glExtGetShadersQCOM");
Function<void, GLuint, GLenum, GLint, GLenum, GLint *> Binding::ExtGetTexLevelParameterivQCOM("glExtGetTexLevelParameterivQCOM");
Function<void, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, void *> Binding::ExtGetTexSubImageQCOM("glExtGetTexSubImageQCOM");
Function<void, GLuint *, GLint, GLint *> Binding::ExtGetTexturesQCOM("glExtGetTexturesQCOM");
Function<GLboolean, GLuint> Binding::ExtIsProgramBinaryQCOM("glExtIsProgramBinaryQCOM");
Function<void, GLuint, GLuint, GLuint> Binding::ExtractComponentEXT("glExtractComponentEXT");
Function<void, GLuint, GLuint, GLuint, GLfloat> Binding::ExtrapolateTex2DQCOM("glExtrapolateTex2DQCOM");
Function<void, GLenum, GLenum, GLint> Binding::ExtTexObjectStateOverrideiQCOM("glExtTexObjectStateOverrideiQCOM");


} // namespace glmixedbinding