
#pragma once


#include <glmixedbinding/noglmixed.h>
#include <glmixedbinding/glmixed/functions.h>


namespace gl41
{

// import functions
using glmixed::glActiveShaderProgram;
using glmixed::glActiveTexture;
using glmixed::glAttachShader;
using glmixed::glBeginConditionalRender;
using glmixed::glBeginQuery;
using glmixed::glBeginQueryIndexed;
using glmixed::glBeginTransformFeedback;
using glmixed::glBindAttribLocation;
using glmixed::glBindBuffer;
using glmixed::glBindBufferBase;
using glmixed::glBindBufferRange;
using glmixed::glBindFragDataLocation;
using glmixed::glBindFragDataLocationIndexed;
using glmixed::glBindFramebuffer;
using glmixed::glBindProgramPipeline;
using glmixed::glBindRenderbuffer;
using glmixed::glBindSampler;
using glmixed::glBindTexture;
using glmixed::glBindTransformFeedback;
using glmixed::glBindVertexArray;
using glmixed::glBlendColor;
using glmixed::glBlendEquation;
using glmixed::glBlendEquationi;
using glmixed::glBlendEquationSeparate;
using glmixed::glBlendEquationSeparatei;
using glmixed::glBlendFunc;
using glmixed::glBlendFunci;
using glmixed::glBlendFuncSeparate;
using glmixed::glBlendFuncSeparatei;
using glmixed::glBlitFramebuffer;
using glmixed::glBufferData;
using glmixed::glBufferSubData;
using glmixed::glCheckFramebufferStatus;
using glmixed::glClampColor;
using glmixed::glClear;
using glmixed::glClearBufferfi;
using glmixed::glClearBufferfv;
using glmixed::glClearBufferiv;
using glmixed::glClearBufferuiv;
using glmixed::glClearColor;
using glmixed::glClearDepth;
using glmixed::glClearDepthf;
using glmixed::glClearStencil;
using glmixed::glClientWaitSync;
using glmixed::glColorMask;
using glmixed::glColorMaski;
using glmixed::glColorP3ui;
using glmixed::glColorP3uiv;
using glmixed::glColorP4ui;
using glmixed::glColorP4uiv;
using glmixed::glCompileShader;
using glmixed::glCompressedTexImage1D;
using glmixed::glCompressedTexImage2D;
using glmixed::glCompressedTexImage3D;
using glmixed::glCompressedTexSubImage1D;
using glmixed::glCompressedTexSubImage2D;
using glmixed::glCompressedTexSubImage3D;
using glmixed::glCopyBufferSubData;
using glmixed::glCopyTexImage1D;
using glmixed::glCopyTexImage2D;
using glmixed::glCopyTexSubImage1D;
using glmixed::glCopyTexSubImage2D;
using glmixed::glCopyTexSubImage3D;
using glmixed::glCreateProgram;
using glmixed::glCreateShader;
using glmixed::glCreateShaderProgramv;
using glmixed::glCullFace;
using glmixed::glDeleteBuffers;
using glmixed::glDeleteFramebuffers;
using glmixed::glDeleteProgram;
using glmixed::glDeleteProgramPipelines;
using glmixed::glDeleteQueries;
using glmixed::glDeleteRenderbuffers;
using glmixed::glDeleteSamplers;
using glmixed::glDeleteShader;
using glmixed::glDeleteSync;
using glmixed::glDeleteTextures;
using glmixed::glDeleteTransformFeedbacks;
using glmixed::glDeleteVertexArrays;
using glmixed::glDepthFunc;
using glmixed::glDepthMask;
using glmixed::glDepthRange;
using glmixed::glDepthRangeArrayv;
using glmixed::glDepthRangef;
using glmixed::glDepthRangeIndexed;
using glmixed::glDetachShader;
using glmixed::glDisable;
using glmixed::glDisablei;
using glmixed::glDisableVertexAttribArray;
using glmixed::glDrawArrays;
using glmixed::glDrawArraysIndirect;
using glmixed::glDrawArraysInstanced;
using glmixed::glDrawBuffer;
using glmixed::glDrawBuffers;
using glmixed::glDrawElements;
using glmixed::glDrawElementsBaseVertex;
using glmixed::glDrawElementsIndirect;
using glmixed::glDrawElementsInstanced;
using glmixed::glDrawElementsInstancedBaseVertex;
using glmixed::glDrawRangeElements;
using glmixed::glDrawRangeElementsBaseVertex;
using glmixed::glDrawTransformFeedback;
using glmixed::glDrawTransformFeedbackStream;
using glmixed::glEnable;
using glmixed::glEnablei;
using glmixed::glEnableVertexAttribArray;
using glmixed::glEndConditionalRender;
using glmixed::glEndQuery;
using glmixed::glEndQueryIndexed;
using glmixed::glEndTransformFeedback;
using glmixed::glFenceSync;
using glmixed::glFinish;
using glmixed::glFlush;
using glmixed::glFlushMappedBufferRange;
using glmixed::glFramebufferRenderbuffer;
using glmixed::glFramebufferTexture;
using glmixed::glFramebufferTexture1D;
using glmixed::glFramebufferTexture2D;
using glmixed::glFramebufferTexture3D;
using glmixed::glFramebufferTextureLayer;
using glmixed::glFrontFace;
using glmixed::glGenBuffers;
using glmixed::glGenerateMipmap;
using glmixed::glGenFramebuffers;
using glmixed::glGenProgramPipelines;
using glmixed::glGenQueries;
using glmixed::glGenRenderbuffers;
using glmixed::glGenSamplers;
using glmixed::glGenTextures;
using glmixed::glGenTransformFeedbacks;
using glmixed::glGenVertexArrays;
using glmixed::glGetActiveAttrib;
using glmixed::glGetActiveSubroutineName;
using glmixed::glGetActiveSubroutineUniformiv;
using glmixed::glGetActiveSubroutineUniformName;
using glmixed::glGetActiveUniform;
using glmixed::glGetActiveUniformBlockiv;
using glmixed::glGetActiveUniformBlockName;
using glmixed::glGetActiveUniformName;
using glmixed::glGetActiveUniformsiv;
using glmixed::glGetAttachedShaders;
using glmixed::glGetAttribLocation;
using glmixed::glGetBooleani_v;
using glmixed::glGetBooleanv;
using glmixed::glGetBufferParameteri64v;
using glmixed::glGetBufferParameteriv;
using glmixed::glGetBufferPointerv;
using glmixed::glGetBufferSubData;
using glmixed::glGetCompressedTexImage;
using glmixed::glGetDoublei_v;
using glmixed::glGetDoublev;
using glmixed::glGetError;
using glmixed::glGetFloati_v;
using glmixed::glGetFloatv;
using glmixed::glGetFragDataIndex;
using glmixed::glGetFragDataLocation;
using glmixed::glGetFramebufferAttachmentParameteriv;
using glmixed::glGetInteger64i_v;
using glmixed::glGetInteger64v;
using glmixed::glGetIntegeri_v;
using glmixed::glGetIntegerv;
using glmixed::glGetMultisamplefv;
using glmixed::glGetProgramBinary;
using glmixed::glGetProgramInfoLog;
using glmixed::glGetProgramiv;
using glmixed::glGetProgramPipelineInfoLog;
using glmixed::glGetProgramPipelineiv;
using glmixed::glGetProgramStageiv;
using glmixed::glGetQueryIndexediv;
using glmixed::glGetQueryiv;
using glmixed::glGetQueryObjecti64v;
using glmixed::glGetQueryObjectiv;
using glmixed::glGetQueryObjectui64v;
using glmixed::glGetQueryObjectuiv;
using glmixed::glGetRenderbufferParameteriv;
using glmixed::glGetSamplerParameterfv;
using glmixed::glGetSamplerParameterIiv;
using glmixed::glGetSamplerParameterIuiv;
using glmixed::glGetSamplerParameteriv;
using glmixed::glGetShaderInfoLog;
using glmixed::glGetShaderiv;
using glmixed::glGetShaderPrecisionFormat;
using glmixed::glGetShaderSource;
using glmixed::glGetString;
using glmixed::glGetStringi;
using glmixed::glGetSubroutineIndex;
using glmixed::glGetSubroutineUniformLocation;
using glmixed::glGetSynciv;
using glmixed::glGetTexImage;
using glmixed::glGetTexLevelParameterfv;
using glmixed::glGetTexLevelParameteriv;
using glmixed::glGetTexParameterfv;
using glmixed::glGetTexParameterIiv;
using glmixed::glGetTexParameterIuiv;
using glmixed::glGetTexParameteriv;
using glmixed::glGetTransformFeedbackVarying;
using glmixed::glGetUniformBlockIndex;
using glmixed::glGetUniformdv;
using glmixed::glGetUniformfv;
using glmixed::glGetUniformIndices;
using glmixed::glGetUniformiv;
using glmixed::glGetUniformLocation;
using glmixed::glGetUniformSubroutineuiv;
using glmixed::glGetUniformuiv;
using glmixed::glGetVertexAttribdv;
using glmixed::glGetVertexAttribfv;
using glmixed::glGetVertexAttribIiv;
using glmixed::glGetVertexAttribIuiv;
using glmixed::glGetVertexAttribiv;
using glmixed::glGetVertexAttribLdv;
using glmixed::glGetVertexAttribPointerv;
using glmixed::glHint;
using glmixed::glIsBuffer;
using glmixed::glIsEnabled;
using glmixed::glIsEnabledi;
using glmixed::glIsFramebuffer;
using glmixed::glIsProgram;
using glmixed::glIsProgramPipeline;
using glmixed::glIsQuery;
using glmixed::glIsRenderbuffer;
using glmixed::glIsSampler;
using glmixed::glIsShader;
using glmixed::glIsSync;
using glmixed::glIsTexture;
using glmixed::glIsTransformFeedback;
using glmixed::glIsVertexArray;
using glmixed::glLineWidth;
using glmixed::glLinkProgram;
using glmixed::glLogicOp;
using glmixed::glMapBuffer;
using glmixed::glMapBufferRange;
using glmixed::glMinSampleShading;
using glmixed::glMultiDrawArrays;
using glmixed::glMultiDrawElements;
using glmixed::glMultiDrawElementsBaseVertex;
using glmixed::glMultiTexCoordP1ui;
using glmixed::glMultiTexCoordP1uiv;
using glmixed::glMultiTexCoordP2ui;
using glmixed::glMultiTexCoordP2uiv;
using glmixed::glMultiTexCoordP3ui;
using glmixed::glMultiTexCoordP3uiv;
using glmixed::glMultiTexCoordP4ui;
using glmixed::glMultiTexCoordP4uiv;
using glmixed::glNormalP3ui;
using glmixed::glNormalP3uiv;
using glmixed::glPatchParameterfv;
using glmixed::glPatchParameteri;
using glmixed::glPauseTransformFeedback;
using glmixed::glPixelStoref;
using glmixed::glPixelStorei;
using glmixed::glPointParameterf;
using glmixed::glPointParameterfv;
using glmixed::glPointParameteri;
using glmixed::glPointParameteriv;
using glmixed::glPointSize;
using glmixed::glPolygonMode;
using glmixed::glPolygonOffset;
using glmixed::glPrimitiveRestartIndex;
using glmixed::glProgramBinary;
using glmixed::glProgramParameteri;
using glmixed::glProgramUniform1d;
using glmixed::glProgramUniform1dv;
using glmixed::glProgramUniform1f;
using glmixed::glProgramUniform1fv;
using glmixed::glProgramUniform1i;
using glmixed::glProgramUniform1iv;
using glmixed::glProgramUniform1ui;
using glmixed::glProgramUniform1uiv;
using glmixed::glProgramUniform2d;
using glmixed::glProgramUniform2dv;
using glmixed::glProgramUniform2f;
using glmixed::glProgramUniform2fv;
using glmixed::glProgramUniform2i;
using glmixed::glProgramUniform2iv;
using glmixed::glProgramUniform2ui;
using glmixed::glProgramUniform2uiv;
using glmixed::glProgramUniform3d;
using glmixed::glProgramUniform3dv;
using glmixed::glProgramUniform3f;
using glmixed::glProgramUniform3fv;
using glmixed::glProgramUniform3i;
using glmixed::glProgramUniform3iv;
using glmixed::glProgramUniform3ui;
using glmixed::glProgramUniform3uiv;
using glmixed::glProgramUniform4d;
using glmixed::glProgramUniform4dv;
using glmixed::glProgramUniform4f;
using glmixed::glProgramUniform4fv;
using glmixed::glProgramUniform4i;
using glmixed::glProgramUniform4iv;
using glmixed::glProgramUniform4ui;
using glmixed::glProgramUniform4uiv;
using glmixed::glProgramUniformMatrix2dv;
using glmixed::glProgramUniformMatrix2fv;
using glmixed::glProgramUniformMatrix2x3dv;
using glmixed::glProgramUniformMatrix2x3fv;
using glmixed::glProgramUniformMatrix2x4dv;
using glmixed::glProgramUniformMatrix2x4fv;
using glmixed::glProgramUniformMatrix3dv;
using glmixed::glProgramUniformMatrix3fv;
using glmixed::glProgramUniformMatrix3x2dv;
using glmixed::glProgramUniformMatrix3x2fv;
using glmixed::glProgramUniformMatrix3x4dv;
using glmixed::glProgramUniformMatrix3x4fv;
using glmixed::glProgramUniformMatrix4dv;
using glmixed::glProgramUniformMatrix4fv;
using glmixed::glProgramUniformMatrix4x2dv;
using glmixed::glProgramUniformMatrix4x2fv;
using glmixed::glProgramUniformMatrix4x3dv;
using glmixed::glProgramUniformMatrix4x3fv;
using glmixed::glProvokingVertex;
using glmixed::glQueryCounter;
using glmixed::glReadBuffer;
using glmixed::glReadPixels;
using glmixed::glReleaseShaderCompiler;
using glmixed::glRenderbufferStorage;
using glmixed::glRenderbufferStorageMultisample;
using glmixed::glResumeTransformFeedback;
using glmixed::glSampleCoverage;
using glmixed::glSampleMaski;
using glmixed::glSamplerParameterf;
using glmixed::glSamplerParameterfv;
using glmixed::glSamplerParameteri;
using glmixed::glSamplerParameterIiv;
using glmixed::glSamplerParameterIuiv;
using glmixed::glSamplerParameteriv;
using glmixed::glScissor;
using glmixed::glScissorArrayv;
using glmixed::glScissorIndexed;
using glmixed::glScissorIndexedv;
using glmixed::glSecondaryColorP3ui;
using glmixed::glSecondaryColorP3uiv;
using glmixed::glShaderBinary;
using glmixed::glShaderSource;
using glmixed::glStencilFunc;
using glmixed::glStencilFuncSeparate;
using glmixed::glStencilMask;
using glmixed::glStencilMaskSeparate;
using glmixed::glStencilOp;
using glmixed::glStencilOpSeparate;
using glmixed::glTexBuffer;
using glmixed::glTexCoordP1ui;
using glmixed::glTexCoordP1uiv;
using glmixed::glTexCoordP2ui;
using glmixed::glTexCoordP2uiv;
using glmixed::glTexCoordP3ui;
using glmixed::glTexCoordP3uiv;
using glmixed::glTexCoordP4ui;
using glmixed::glTexCoordP4uiv;
using glmixed::glTexImage1D;
using glmixed::glTexImage2D;
using glmixed::glTexImage2DMultisample;
using glmixed::glTexImage3D;
using glmixed::glTexImage3DMultisample;
using glmixed::glTexParameterf;
using glmixed::glTexParameterfv;
using glmixed::glTexParameteri;
using glmixed::glTexParameterIiv;
using glmixed::glTexParameterIuiv;
using glmixed::glTexParameteriv;
using glmixed::glTexSubImage1D;
using glmixed::glTexSubImage2D;
using glmixed::glTexSubImage3D;
using glmixed::glTransformFeedbackVaryings;
using glmixed::glUniform1d;
using glmixed::glUniform1dv;
using glmixed::glUniform1f;
using glmixed::glUniform1fv;
using glmixed::glUniform1i;
using glmixed::glUniform1iv;
using glmixed::glUniform1ui;
using glmixed::glUniform1uiv;
using glmixed::glUniform2d;
using glmixed::glUniform2dv;
using glmixed::glUniform2f;
using glmixed::glUniform2fv;
using glmixed::glUniform2i;
using glmixed::glUniform2iv;
using glmixed::glUniform2ui;
using glmixed::glUniform2uiv;
using glmixed::glUniform3d;
using glmixed::glUniform3dv;
using glmixed::glUniform3f;
using glmixed::glUniform3fv;
using glmixed::glUniform3i;
using glmixed::glUniform3iv;
using glmixed::glUniform3ui;
using glmixed::glUniform3uiv;
using glmixed::glUniform4d;
using glmixed::glUniform4dv;
using glmixed::glUniform4f;
using glmixed::glUniform4fv;
using glmixed::glUniform4i;
using glmixed::glUniform4iv;
using glmixed::glUniform4ui;
using glmixed::glUniform4uiv;
using glmixed::glUniformBlockBinding;
using glmixed::glUniformMatrix2dv;
using glmixed::glUniformMatrix2fv;
using glmixed::glUniformMatrix2x3dv;
using glmixed::glUniformMatrix2x3fv;
using glmixed::glUniformMatrix2x4dv;
using glmixed::glUniformMatrix2x4fv;
using glmixed::glUniformMatrix3dv;
using glmixed::glUniformMatrix3fv;
using glmixed::glUniformMatrix3x2dv;
using glmixed::glUniformMatrix3x2fv;
using glmixed::glUniformMatrix3x4dv;
using glmixed::glUniformMatrix3x4fv;
using glmixed::glUniformMatrix4dv;
using glmixed::glUniformMatrix4fv;
using glmixed::glUniformMatrix4x2dv;
using glmixed::glUniformMatrix4x2fv;
using glmixed::glUniformMatrix4x3dv;
using glmixed::glUniformMatrix4x3fv;
using glmixed::glUniformSubroutinesuiv;
using glmixed::glUnmapBuffer;
using glmixed::glUseProgram;
using glmixed::glUseProgramStages;
using glmixed::glValidateProgram;
using glmixed::glValidateProgramPipeline;
using glmixed::glVertexAttrib1d;
using glmixed::glVertexAttrib1dv;
using glmixed::glVertexAttrib1f;
using glmixed::glVertexAttrib1fv;
using glmixed::glVertexAttrib1s;
using glmixed::glVertexAttrib1sv;
using glmixed::glVertexAttrib2d;
using glmixed::glVertexAttrib2dv;
using glmixed::glVertexAttrib2f;
using glmixed::glVertexAttrib2fv;
using glmixed::glVertexAttrib2s;
using glmixed::glVertexAttrib2sv;
using glmixed::glVertexAttrib3d;
using glmixed::glVertexAttrib3dv;
using glmixed::glVertexAttrib3f;
using glmixed::glVertexAttrib3fv;
using glmixed::glVertexAttrib3s;
using glmixed::glVertexAttrib3sv;
using glmixed::glVertexAttrib4bv;
using glmixed::glVertexAttrib4d;
using glmixed::glVertexAttrib4dv;
using glmixed::glVertexAttrib4f;
using glmixed::glVertexAttrib4fv;
using glmixed::glVertexAttrib4iv;
using glmixed::glVertexAttrib4Nbv;
using glmixed::glVertexAttrib4Niv;
using glmixed::glVertexAttrib4Nsv;
using glmixed::glVertexAttrib4Nub;
using glmixed::glVertexAttrib4Nubv;
using glmixed::glVertexAttrib4Nuiv;
using glmixed::glVertexAttrib4Nusv;
using glmixed::glVertexAttrib4s;
using glmixed::glVertexAttrib4sv;
using glmixed::glVertexAttrib4ubv;
using glmixed::glVertexAttrib4uiv;
using glmixed::glVertexAttrib4usv;
using glmixed::glVertexAttribDivisor;
using glmixed::glVertexAttribI1i;
using glmixed::glVertexAttribI1iv;
using glmixed::glVertexAttribI1ui;
using glmixed::glVertexAttribI1uiv;
using glmixed::glVertexAttribI2i;
using glmixed::glVertexAttribI2iv;
using glmixed::glVertexAttribI2ui;
using glmixed::glVertexAttribI2uiv;
using glmixed::glVertexAttribI3i;
using glmixed::glVertexAttribI3iv;
using glmixed::glVertexAttribI3ui;
using glmixed::glVertexAttribI3uiv;
using glmixed::glVertexAttribI4bv;
using glmixed::glVertexAttribI4i;
using glmixed::glVertexAttribI4iv;
using glmixed::glVertexAttribI4sv;
using glmixed::glVertexAttribI4ubv;
using glmixed::glVertexAttribI4ui;
using glmixed::glVertexAttribI4uiv;
using glmixed::glVertexAttribI4usv;
using glmixed::glVertexAttribIPointer;
using glmixed::glVertexAttribL1d;
using glmixed::glVertexAttribL1dv;
using glmixed::glVertexAttribL2d;
using glmixed::glVertexAttribL2dv;
using glmixed::glVertexAttribL3d;
using glmixed::glVertexAttribL3dv;
using glmixed::glVertexAttribL4d;
using glmixed::glVertexAttribL4dv;
using glmixed::glVertexAttribLPointer;
using glmixed::glVertexAttribP1ui;
using glmixed::glVertexAttribP1uiv;
using glmixed::glVertexAttribP2ui;
using glmixed::glVertexAttribP2uiv;
using glmixed::glVertexAttribP3ui;
using glmixed::glVertexAttribP3uiv;
using glmixed::glVertexAttribP4ui;
using glmixed::glVertexAttribP4uiv;
using glmixed::glVertexAttribPointer;
using glmixed::glVertexP2ui;
using glmixed::glVertexP2uiv;
using glmixed::glVertexP3ui;
using glmixed::glVertexP3uiv;
using glmixed::glVertexP4ui;
using glmixed::glVertexP4uiv;
using glmixed::glViewport;
using glmixed::glViewportArrayv;
using glmixed::glViewportIndexedf;
using glmixed::glViewportIndexedfv;
using glmixed::glWaitSync;

} // namespace gl41