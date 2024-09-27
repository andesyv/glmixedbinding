
#pragma once


#include <glmixedbinding/noglmixed.h>

#include <glmixedbinding/glmixed/enum.h>


namespace gl42
{


// use enum type
using glmixed::GLenum;


// import enums to namespace
using glmixed::GL_ACTIVE_ATOMIC_COUNTER_BUFFERS;
using glmixed::GL_ACTIVE_ATTRIBUTE_MAX_LENGTH;
using glmixed::GL_ACTIVE_ATTRIBUTES;
using glmixed::GL_ACTIVE_PROGRAM;
using glmixed::GL_ACTIVE_SUBROUTINE_MAX_LENGTH;
using glmixed::GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS;
using glmixed::GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH;
using glmixed::GL_ACTIVE_SUBROUTINE_UNIFORMS;
using glmixed::GL_ACTIVE_SUBROUTINES;
using glmixed::GL_ACTIVE_TEXTURE;
using glmixed::GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH;
using glmixed::GL_ACTIVE_UNIFORM_BLOCKS;
using glmixed::GL_ACTIVE_UNIFORM_MAX_LENGTH;
using glmixed::GL_ACTIVE_UNIFORMS;
using glmixed::GL_ALIASED_LINE_WIDTH_RANGE;
using glmixed::GL_ALPHA;
using glmixed::GL_ALREADY_SIGNALED;
using glmixed::GL_ALWAYS;
using glmixed::GL_AND;
using glmixed::GL_AND_INVERTED;
using glmixed::GL_AND_REVERSE;
using glmixed::GL_ANY_SAMPLES_PASSED;
using glmixed::GL_ARRAY_BUFFER;
using glmixed::GL_ARRAY_BUFFER_BINDING;
using glmixed::GL_ATOMIC_COUNTER_BUFFER;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_BINDING;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_SIZE;
using glmixed::GL_ATOMIC_COUNTER_BUFFER_START;
using glmixed::GL_ATTACHED_SHADERS;
using glmixed::GL_BACK;
using glmixed::GL_BACK_LEFT;
using glmixed::GL_BACK_RIGHT;
using glmixed::GL_BGR;
using glmixed::GL_BGR_INTEGER;
using glmixed::GL_BGRA;
using glmixed::GL_BGRA_INTEGER;
using glmixed::GL_BLEND;
using glmixed::GL_BLEND_COLOR;
using glmixed::GL_BLEND_DST;
using glmixed::GL_BLEND_DST_ALPHA;
using glmixed::GL_BLEND_DST_RGB;
using glmixed::GL_BLEND_EQUATION;
using glmixed::GL_BLEND_EQUATION_ALPHA;
using glmixed::GL_BLEND_EQUATION_RGB;
using glmixed::GL_BLEND_SRC;
using glmixed::GL_BLEND_SRC_ALPHA;
using glmixed::GL_BLEND_SRC_RGB;
using glmixed::GL_BLUE;
using glmixed::GL_BLUE_INTEGER;
using glmixed::GL_BOOL;
using glmixed::GL_BOOL_VEC2;
using glmixed::GL_BOOL_VEC3;
using glmixed::GL_BOOL_VEC4;
using glmixed::GL_BUFFER_ACCESS;
using glmixed::GL_BUFFER_ACCESS_FLAGS;
using glmixed::GL_BUFFER_MAP_LENGTH;
using glmixed::GL_BUFFER_MAP_OFFSET;
using glmixed::GL_BUFFER_MAP_POINTER;
using glmixed::GL_BUFFER_MAPPED;
using glmixed::GL_BUFFER_SIZE;
using glmixed::GL_BUFFER_USAGE;
using glmixed::GL_BYTE;
using glmixed::GL_CCW;
using glmixed::GL_CLAMP_READ_COLOR;
using glmixed::GL_CLAMP_TO_BORDER;
using glmixed::GL_CLAMP_TO_EDGE;
using glmixed::GL_CLEAR;
using glmixed::GL_CLIP_DISTANCE0;
using glmixed::GL_CLIP_DISTANCE1;
using glmixed::GL_CLIP_DISTANCE2;
using glmixed::GL_CLIP_DISTANCE3;
using glmixed::GL_CLIP_DISTANCE4;
using glmixed::GL_CLIP_DISTANCE5;
using glmixed::GL_CLIP_DISTANCE6;
using glmixed::GL_CLIP_DISTANCE7;
using glmixed::GL_COLOR;
using glmixed::GL_COLOR_ATTACHMENT0;
using glmixed::GL_COLOR_ATTACHMENT1;
using glmixed::GL_COLOR_ATTACHMENT10;
using glmixed::GL_COLOR_ATTACHMENT11;
using glmixed::GL_COLOR_ATTACHMENT12;
using glmixed::GL_COLOR_ATTACHMENT13;
using glmixed::GL_COLOR_ATTACHMENT14;
using glmixed::GL_COLOR_ATTACHMENT15;
using glmixed::GL_COLOR_ATTACHMENT16;
using glmixed::GL_COLOR_ATTACHMENT17;
using glmixed::GL_COLOR_ATTACHMENT18;
using glmixed::GL_COLOR_ATTACHMENT19;
using glmixed::GL_COLOR_ATTACHMENT2;
using glmixed::GL_COLOR_ATTACHMENT20;
using glmixed::GL_COLOR_ATTACHMENT21;
using glmixed::GL_COLOR_ATTACHMENT22;
using glmixed::GL_COLOR_ATTACHMENT23;
using glmixed::GL_COLOR_ATTACHMENT24;
using glmixed::GL_COLOR_ATTACHMENT25;
using glmixed::GL_COLOR_ATTACHMENT26;
using glmixed::GL_COLOR_ATTACHMENT27;
using glmixed::GL_COLOR_ATTACHMENT28;
using glmixed::GL_COLOR_ATTACHMENT29;
using glmixed::GL_COLOR_ATTACHMENT3;
using glmixed::GL_COLOR_ATTACHMENT30;
using glmixed::GL_COLOR_ATTACHMENT31;
using glmixed::GL_COLOR_ATTACHMENT4;
using glmixed::GL_COLOR_ATTACHMENT5;
using glmixed::GL_COLOR_ATTACHMENT6;
using glmixed::GL_COLOR_ATTACHMENT7;
using glmixed::GL_COLOR_ATTACHMENT8;
using glmixed::GL_COLOR_ATTACHMENT9;
using glmixed::GL_COLOR_CLEAR_VALUE;
using glmixed::GL_COLOR_LOGIC_OP;
using glmixed::GL_COLOR_WRITEMASK;
using glmixed::GL_COMPARE_REF_TO_TEXTURE;
using glmixed::GL_COMPATIBLE_SUBROUTINES;
using glmixed::GL_COMPILE_STATUS;
using glmixed::GL_COMPRESSED_RED;
using glmixed::GL_COMPRESSED_RED_RGTC1;
using glmixed::GL_COMPRESSED_RG;
using glmixed::GL_COMPRESSED_RG_RGTC2;
using glmixed::GL_COMPRESSED_RGB;
using glmixed::GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT;
using glmixed::GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT;
using glmixed::GL_COMPRESSED_RGBA;
using glmixed::GL_COMPRESSED_RGBA_BPTC_UNORM;
using glmixed::GL_COMPRESSED_SIGNED_RED_RGTC1;
using glmixed::GL_COMPRESSED_SIGNED_RG_RGTC2;
using glmixed::GL_COMPRESSED_SRGB;
using glmixed::GL_COMPRESSED_SRGB_ALPHA;
using glmixed::GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM;
using glmixed::GL_COMPRESSED_TEXTURE_FORMATS;
using glmixed::GL_CONDITION_SATISFIED;
using glmixed::GL_CONSTANT_ALPHA;
using glmixed::GL_CONSTANT_COLOR;
using glmixed::GL_CONTEXT_FLAGS;
using glmixed::GL_CONTEXT_PROFILE_MASK;
using glmixed::GL_COPY;
using glmixed::GL_COPY_INVERTED;
using glmixed::GL_COPY_READ_BUFFER;
using glmixed::GL_COPY_READ_BUFFER_BINDING;
using glmixed::GL_COPY_WRITE_BUFFER;
using glmixed::GL_COPY_WRITE_BUFFER_BINDING;
using glmixed::GL_CULL_FACE;
using glmixed::GL_CULL_FACE_MODE;
using glmixed::GL_CURRENT_PROGRAM;
using glmixed::GL_CURRENT_QUERY;
using glmixed::GL_CURRENT_VERTEX_ATTRIB;
using glmixed::GL_CW;
using glmixed::GL_DECR;
using glmixed::GL_DECR_WRAP;
using glmixed::GL_DELETE_STATUS;
using glmixed::GL_DEPTH;
using glmixed::GL_DEPTH24_STENCIL8;
using glmixed::GL_DEPTH32F_STENCIL8;
using glmixed::GL_DEPTH_ATTACHMENT;
using glmixed::GL_DEPTH_CLAMP;
using glmixed::GL_DEPTH_CLEAR_VALUE;
using glmixed::GL_DEPTH_COMPONENT;
using glmixed::GL_DEPTH_COMPONENT16;
using glmixed::GL_DEPTH_COMPONENT24;
using glmixed::GL_DEPTH_COMPONENT32;
using glmixed::GL_DEPTH_COMPONENT32F;
using glmixed::GL_DEPTH_FUNC;
using glmixed::GL_DEPTH_RANGE;
using glmixed::GL_DEPTH_STENCIL;
using glmixed::GL_DEPTH_STENCIL_ATTACHMENT;
using glmixed::GL_DEPTH_TEST;
using glmixed::GL_DEPTH_WRITEMASK;
using glmixed::GL_DITHER;
using glmixed::GL_DONT_CARE;
using glmixed::GL_DOUBLE;
using glmixed::GL_DOUBLE_MAT2;
using glmixed::GL_DOUBLE_MAT2x3;
using glmixed::GL_DOUBLE_MAT2x4;
using glmixed::GL_DOUBLE_MAT3;
using glmixed::GL_DOUBLE_MAT3x2;
using glmixed::GL_DOUBLE_MAT3x4;
using glmixed::GL_DOUBLE_MAT4;
using glmixed::GL_DOUBLE_MAT4x2;
using glmixed::GL_DOUBLE_MAT4x3;
using glmixed::GL_DOUBLE_VEC2;
using glmixed::GL_DOUBLE_VEC3;
using glmixed::GL_DOUBLE_VEC4;
using glmixed::GL_DOUBLEBUFFER;
using glmixed::GL_DRAW_BUFFER;
using glmixed::GL_DRAW_BUFFER0;
using glmixed::GL_DRAW_BUFFER1;
using glmixed::GL_DRAW_BUFFER10;
using glmixed::GL_DRAW_BUFFER11;
using glmixed::GL_DRAW_BUFFER12;
using glmixed::GL_DRAW_BUFFER13;
using glmixed::GL_DRAW_BUFFER14;
using glmixed::GL_DRAW_BUFFER15;
using glmixed::GL_DRAW_BUFFER2;
using glmixed::GL_DRAW_BUFFER3;
using glmixed::GL_DRAW_BUFFER4;
using glmixed::GL_DRAW_BUFFER5;
using glmixed::GL_DRAW_BUFFER6;
using glmixed::GL_DRAW_BUFFER7;
using glmixed::GL_DRAW_BUFFER8;
using glmixed::GL_DRAW_BUFFER9;
using glmixed::GL_DRAW_FRAMEBUFFER;
using glmixed::GL_DRAW_FRAMEBUFFER_BINDING;
using glmixed::GL_DRAW_INDIRECT_BUFFER;
using glmixed::GL_DRAW_INDIRECT_BUFFER_BINDING;
using glmixed::GL_DST_ALPHA;
using glmixed::GL_DST_COLOR;
using glmixed::GL_DYNAMIC_COPY;
using glmixed::GL_DYNAMIC_DRAW;
using glmixed::GL_DYNAMIC_READ;
using glmixed::GL_ELEMENT_ARRAY_BUFFER;
using glmixed::GL_ELEMENT_ARRAY_BUFFER_BINDING;
using glmixed::GL_EQUAL;
using glmixed::GL_EQUIV;
using glmixed::GL_EXTENSIONS;
using glmixed::GL_FASTEST;
using glmixed::GL_FILL;
using glmixed::GL_FIRST_VERTEX_CONVENTION;
using glmixed::GL_FIXED;
using glmixed::GL_FIXED_ONLY;
using glmixed::GL_FLOAT;
using glmixed::GL_FLOAT_32_UNSIGNED_INT_24_8_REV;
using glmixed::GL_FLOAT_MAT2;
using glmixed::GL_FLOAT_MAT2x3;
using glmixed::GL_FLOAT_MAT2x4;
using glmixed::GL_FLOAT_MAT3;
using glmixed::GL_FLOAT_MAT3x2;
using glmixed::GL_FLOAT_MAT3x4;
using glmixed::GL_FLOAT_MAT4;
using glmixed::GL_FLOAT_MAT4x2;
using glmixed::GL_FLOAT_MAT4x3;
using glmixed::GL_FLOAT_VEC2;
using glmixed::GL_FLOAT_VEC3;
using glmixed::GL_FLOAT_VEC4;
using glmixed::GL_FRACTIONAL_EVEN;
using glmixed::GL_FRACTIONAL_ODD;
using glmixed::GL_FRAGMENT_INTERPOLATION_OFFSET_BITS;
using glmixed::GL_FRAGMENT_SHADER;
using glmixed::GL_FRAGMENT_SHADER_DERIVATIVE_HINT;
using glmixed::GL_FRAMEBUFFER;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_LAYERED;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER;
using glmixed::GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL;
using glmixed::GL_FRAMEBUFFER_BINDING;
using glmixed::GL_FRAMEBUFFER_COMPLETE;
using glmixed::GL_FRAMEBUFFER_DEFAULT;
using glmixed::GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT;
using glmixed::GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER;
using glmixed::GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS;
using glmixed::GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT;
using glmixed::GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE;
using glmixed::GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER;
using glmixed::GL_FRAMEBUFFER_SRGB;
using glmixed::GL_FRAMEBUFFER_UNDEFINED;
using glmixed::GL_FRAMEBUFFER_UNSUPPORTED;
using glmixed::GL_FRONT;
using glmixed::GL_FRONT_AND_BACK;
using glmixed::GL_FRONT_FACE;
using glmixed::GL_FRONT_LEFT;
using glmixed::GL_FRONT_RIGHT;
using glmixed::GL_FUNC_ADD;
using glmixed::GL_FUNC_REVERSE_SUBTRACT;
using glmixed::GL_FUNC_SUBTRACT;
using glmixed::GL_GEOMETRY_INPUT_TYPE;
using glmixed::GL_GEOMETRY_OUTPUT_TYPE;
using glmixed::GL_GEOMETRY_SHADER;
using glmixed::GL_GEOMETRY_SHADER_INVOCATIONS;
using glmixed::GL_GEOMETRY_VERTICES_OUT;
using glmixed::GL_GEQUAL;
using glmixed::GL_GREATER;
using glmixed::GL_GREEN;
using glmixed::GL_GREEN_INTEGER;
using glmixed::GL_HALF_FLOAT;
using glmixed::GL_HIGH_FLOAT;
using glmixed::GL_HIGH_INT;
using glmixed::GL_IMAGE_1D;
using glmixed::GL_IMAGE_1D_ARRAY;
using glmixed::GL_IMAGE_2D;
using glmixed::GL_IMAGE_2D_ARRAY;
using glmixed::GL_IMAGE_2D_MULTISAMPLE;
using glmixed::GL_IMAGE_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_IMAGE_2D_RECT;
using glmixed::GL_IMAGE_3D;
using glmixed::GL_IMAGE_BINDING_ACCESS;
using glmixed::GL_IMAGE_BINDING_FORMAT;
using glmixed::GL_IMAGE_BINDING_LAYER;
using glmixed::GL_IMAGE_BINDING_LAYERED;
using glmixed::GL_IMAGE_BINDING_LEVEL;
using glmixed::GL_IMAGE_BINDING_NAME;
using glmixed::GL_IMAGE_BUFFER;
using glmixed::GL_IMAGE_CUBE;
using glmixed::GL_IMAGE_CUBE_MAP_ARRAY;
using glmixed::GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS;
using glmixed::GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE;
using glmixed::GL_IMAGE_FORMAT_COMPATIBILITY_TYPE;
using glmixed::GL_IMPLEMENTATION_COLOR_READ_FORMAT;
using glmixed::GL_IMPLEMENTATION_COLOR_READ_TYPE;
using glmixed::GL_INCR;
using glmixed::GL_INCR_WRAP;
using glmixed::GL_INFO_LOG_LENGTH;
using glmixed::GL_INT;
using glmixed::GL_INT_2_10_10_10_REV;
using glmixed::GL_INT_IMAGE_1D;
using glmixed::GL_INT_IMAGE_1D_ARRAY;
using glmixed::GL_INT_IMAGE_2D;
using glmixed::GL_INT_IMAGE_2D_ARRAY;
using glmixed::GL_INT_IMAGE_2D_MULTISAMPLE;
using glmixed::GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_INT_IMAGE_2D_RECT;
using glmixed::GL_INT_IMAGE_3D;
using glmixed::GL_INT_IMAGE_BUFFER;
using glmixed::GL_INT_IMAGE_CUBE;
using glmixed::GL_INT_IMAGE_CUBE_MAP_ARRAY;
using glmixed::GL_INT_SAMPLER_1D;
using glmixed::GL_INT_SAMPLER_1D_ARRAY;
using glmixed::GL_INT_SAMPLER_2D;
using glmixed::GL_INT_SAMPLER_2D_ARRAY;
using glmixed::GL_INT_SAMPLER_2D_MULTISAMPLE;
using glmixed::GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_INT_SAMPLER_2D_RECT;
using glmixed::GL_INT_SAMPLER_3D;
using glmixed::GL_INT_SAMPLER_BUFFER;
using glmixed::GL_INT_SAMPLER_CUBE;
using glmixed::GL_INT_SAMPLER_CUBE_MAP_ARRAY;
using glmixed::GL_INT_VEC2;
using glmixed::GL_INT_VEC3;
using glmixed::GL_INT_VEC4;
using glmixed::GL_INTERLEAVED_ATTRIBS;
using glmixed::GL_INVALID_ENUM;
using glmixed::GL_INVALID_FRAMEBUFFER_OPERATION;
using glmixed::GL_INVALID_OPERATION;
using glmixed::GL_INVALID_VALUE;
using glmixed::GL_INVERT;
using glmixed::GL_ISOLINES;
using glmixed::GL_KEEP;
using glmixed::GL_LAST_VERTEX_CONVENTION;
using glmixed::GL_LAYER_PROVOKING_VERTEX;
using glmixed::GL_LEFT;
using glmixed::GL_LEQUAL;
using glmixed::GL_LESS;
using glmixed::GL_LINE;
using glmixed::GL_LINE_LOOP;
using glmixed::GL_LINE_SMOOTH;
using glmixed::GL_LINE_SMOOTH_HINT;
using glmixed::GL_LINE_STRIP;
using glmixed::GL_LINE_STRIP_ADJACENCY;
using glmixed::GL_LINE_WIDTH;
using glmixed::GL_LINE_WIDTH_GRANULARITY;
using glmixed::GL_LINE_WIDTH_RANGE;
using glmixed::GL_LINEAR;
using glmixed::GL_LINEAR_MIPMAP_LINEAR;
using glmixed::GL_LINEAR_MIPMAP_NEAREST;
using glmixed::GL_LINES;
using glmixed::GL_LINES_ADJACENCY;
using glmixed::GL_LINK_STATUS;
using glmixed::GL_LOGIC_OP_MODE;
using glmixed::GL_LOW_FLOAT;
using glmixed::GL_LOW_INT;
using glmixed::GL_LOWER_LEFT;
using glmixed::GL_MAJOR_VERSION;
using glmixed::GL_MAX;
using glmixed::GL_MAX_3D_TEXTURE_SIZE;
using glmixed::GL_MAX_ARRAY_TEXTURE_LAYERS;
using glmixed::GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS;
using glmixed::GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE;
using glmixed::GL_MAX_CLIP_DISTANCES;
using glmixed::GL_MAX_COLOR_ATTACHMENTS;
using glmixed::GL_MAX_COLOR_TEXTURE_SAMPLES;
using glmixed::GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS;
using glmixed::GL_MAX_COMBINED_ATOMIC_COUNTERS;
using glmixed::GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_COMBINED_IMAGE_UNIFORMS;
using glmixed::GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS;
using glmixed::GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS;
using glmixed::GL_MAX_COMBINED_UNIFORM_BLOCKS;
using glmixed::GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_CUBE_MAP_TEXTURE_SIZE;
using glmixed::GL_MAX_DEPTH_TEXTURE_SAMPLES;
using glmixed::GL_MAX_DRAW_BUFFERS;
using glmixed::GL_MAX_DUAL_SOURCE_DRAW_BUFFERS;
using glmixed::GL_MAX_ELEMENTS_INDICES;
using glmixed::GL_MAX_ELEMENTS_VERTICES;
using glmixed::GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS;
using glmixed::GL_MAX_FRAGMENT_ATOMIC_COUNTERS;
using glmixed::GL_MAX_FRAGMENT_IMAGE_UNIFORMS;
using glmixed::GL_MAX_FRAGMENT_INPUT_COMPONENTS;
using glmixed::GL_MAX_FRAGMENT_INTERPOLATION_OFFSET;
using glmixed::GL_MAX_FRAGMENT_UNIFORM_BLOCKS;
using glmixed::GL_MAX_FRAGMENT_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_FRAGMENT_UNIFORM_VECTORS;
using glmixed::GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS;
using glmixed::GL_MAX_GEOMETRY_ATOMIC_COUNTERS;
using glmixed::GL_MAX_GEOMETRY_IMAGE_UNIFORMS;
using glmixed::GL_MAX_GEOMETRY_INPUT_COMPONENTS;
using glmixed::GL_MAX_GEOMETRY_OUTPUT_COMPONENTS;
using glmixed::GL_MAX_GEOMETRY_OUTPUT_VERTICES;
using glmixed::GL_MAX_GEOMETRY_SHADER_INVOCATIONS;
using glmixed::GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS;
using glmixed::GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS;
using glmixed::GL_MAX_GEOMETRY_UNIFORM_BLOCKS;
using glmixed::GL_MAX_GEOMETRY_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_IMAGE_SAMPLES;
using glmixed::GL_MAX_IMAGE_UNITS;
using glmixed::GL_MAX_INTEGER_SAMPLES;
using glmixed::GL_MAX_PATCH_VERTICES;
using glmixed::GL_MAX_PROGRAM_TEXEL_OFFSET;
using glmixed::GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET;
using glmixed::GL_MAX_RECTANGLE_TEXTURE_SIZE;
using glmixed::GL_MAX_RENDERBUFFER_SIZE;
using glmixed::GL_MAX_SAMPLE_MASK_WORDS;
using glmixed::GL_MAX_SAMPLES;
using glmixed::GL_MAX_SERVER_WAIT_TIMEOUT;
using glmixed::GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS;
using glmixed::GL_MAX_SUBROUTINES;
using glmixed::GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS;
using glmixed::GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS;
using glmixed::GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS;
using glmixed::GL_MAX_TESS_CONTROL_INPUT_COMPONENTS;
using glmixed::GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS;
using glmixed::GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS;
using glmixed::GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS;
using glmixed::GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS;
using glmixed::GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS;
using glmixed::GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS;
using glmixed::GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS;
using glmixed::GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS;
using glmixed::GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS;
using glmixed::GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS;
using glmixed::GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS;
using glmixed::GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_TESS_GEN_LEVEL;
using glmixed::GL_MAX_TESS_PATCH_COMPONENTS;
using glmixed::GL_MAX_TEXTURE_BUFFER_SIZE;
using glmixed::GL_MAX_TEXTURE_IMAGE_UNITS;
using glmixed::GL_MAX_TEXTURE_LOD_BIAS;
using glmixed::GL_MAX_TEXTURE_SIZE;
using glmixed::GL_MAX_TRANSFORM_FEEDBACK_BUFFERS;
using glmixed::GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS;
using glmixed::GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS;
using glmixed::GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS;
using glmixed::GL_MAX_UNIFORM_BLOCK_SIZE;
using glmixed::GL_MAX_UNIFORM_BUFFER_BINDINGS;
using glmixed::GL_MAX_VARYING_COMPONENTS;
using glmixed::GL_MAX_VARYING_FLOATS;
using glmixed::GL_MAX_VARYING_VECTORS;
using glmixed::GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS;
using glmixed::GL_MAX_VERTEX_ATOMIC_COUNTERS;
using glmixed::GL_MAX_VERTEX_ATTRIBS;
using glmixed::GL_MAX_VERTEX_IMAGE_UNIFORMS;
using glmixed::GL_MAX_VERTEX_OUTPUT_COMPONENTS;
using glmixed::GL_MAX_VERTEX_STREAMS;
using glmixed::GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS;
using glmixed::GL_MAX_VERTEX_UNIFORM_BLOCKS;
using glmixed::GL_MAX_VERTEX_UNIFORM_COMPONENTS;
using glmixed::GL_MAX_VERTEX_UNIFORM_VECTORS;
using glmixed::GL_MAX_VIEWPORT_DIMS;
using glmixed::GL_MAX_VIEWPORTS;
using glmixed::GL_MEDIUM_FLOAT;
using glmixed::GL_MEDIUM_INT;
using glmixed::GL_MIN;
using glmixed::GL_MIN_FRAGMENT_INTERPOLATION_OFFSET;
using glmixed::GL_MIN_MAP_BUFFER_ALIGNMENT;
using glmixed::GL_MIN_PROGRAM_TEXEL_OFFSET;
using glmixed::GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET;
using glmixed::GL_MIN_SAMPLE_SHADING_VALUE;
using glmixed::GL_MINOR_VERSION;
using glmixed::GL_MIRRORED_REPEAT;
using glmixed::GL_MULTISAMPLE;
using glmixed::GL_NAND;
using glmixed::GL_NEAREST;
using glmixed::GL_NEAREST_MIPMAP_LINEAR;
using glmixed::GL_NEAREST_MIPMAP_NEAREST;
using glmixed::GL_NEVER;
using glmixed::GL_NICEST;
using glmixed::GL_NO_ERROR;
using glmixed::GL_NONE;
using glmixed::GL_NOOP;
using glmixed::GL_NOR;
using glmixed::GL_NOTEQUAL;
using glmixed::GL_NUM_COMPATIBLE_SUBROUTINES;
using glmixed::GL_NUM_COMPRESSED_TEXTURE_FORMATS;
using glmixed::GL_NUM_EXTENSIONS;
using glmixed::GL_NUM_PROGRAM_BINARY_FORMATS;
using glmixed::GL_NUM_SAMPLE_COUNTS;
using glmixed::GL_NUM_SHADER_BINARY_FORMATS;
using glmixed::GL_OBJECT_TYPE;
using glmixed::GL_ONE;
using glmixed::GL_ONE_MINUS_CONSTANT_ALPHA;
using glmixed::GL_ONE_MINUS_CONSTANT_COLOR;
using glmixed::GL_ONE_MINUS_DST_ALPHA;
using glmixed::GL_ONE_MINUS_DST_COLOR;
using glmixed::GL_ONE_MINUS_SRC1_ALPHA;
using glmixed::GL_ONE_MINUS_SRC1_COLOR;
using glmixed::GL_ONE_MINUS_SRC_ALPHA;
using glmixed::GL_ONE_MINUS_SRC_COLOR;
using glmixed::GL_OR;
using glmixed::GL_OR_INVERTED;
using glmixed::GL_OR_REVERSE;
using glmixed::GL_OUT_OF_MEMORY;
using glmixed::GL_PACK_ALIGNMENT;
using glmixed::GL_PACK_COMPRESSED_BLOCK_DEPTH;
using glmixed::GL_PACK_COMPRESSED_BLOCK_HEIGHT;
using glmixed::GL_PACK_COMPRESSED_BLOCK_SIZE;
using glmixed::GL_PACK_COMPRESSED_BLOCK_WIDTH;
using glmixed::GL_PACK_IMAGE_HEIGHT;
using glmixed::GL_PACK_LSB_FIRST;
using glmixed::GL_PACK_ROW_LENGTH;
using glmixed::GL_PACK_SKIP_IMAGES;
using glmixed::GL_PACK_SKIP_PIXELS;
using glmixed::GL_PACK_SKIP_ROWS;
using glmixed::GL_PACK_SWAP_BYTES;
using glmixed::GL_PATCH_DEFAULT_INNER_LEVEL;
using glmixed::GL_PATCH_DEFAULT_OUTER_LEVEL;
using glmixed::GL_PATCH_VERTICES;
using glmixed::GL_PATCHES;
using glmixed::GL_PIXEL_PACK_BUFFER;
using glmixed::GL_PIXEL_PACK_BUFFER_BINDING;
using glmixed::GL_PIXEL_UNPACK_BUFFER;
using glmixed::GL_PIXEL_UNPACK_BUFFER_BINDING;
using glmixed::GL_POINT;
using glmixed::GL_POINT_FADE_THRESHOLD_SIZE;
using glmixed::GL_POINT_SIZE;
using glmixed::GL_POINT_SIZE_GRANULARITY;
using glmixed::GL_POINT_SIZE_RANGE;
using glmixed::GL_POINT_SPRITE_COORD_ORIGIN;
using glmixed::GL_POINTS;
using glmixed::GL_POLYGON_MODE;
using glmixed::GL_POLYGON_OFFSET_FACTOR;
using glmixed::GL_POLYGON_OFFSET_FILL;
using glmixed::GL_POLYGON_OFFSET_LINE;
using glmixed::GL_POLYGON_OFFSET_POINT;
using glmixed::GL_POLYGON_OFFSET_UNITS;
using glmixed::GL_POLYGON_SMOOTH;
using glmixed::GL_POLYGON_SMOOTH_HINT;
using glmixed::GL_PRIMITIVE_RESTART;
using glmixed::GL_PRIMITIVE_RESTART_INDEX;
using glmixed::GL_PRIMITIVES_GENERATED;
using glmixed::GL_PROGRAM_BINARY_FORMATS;
using glmixed::GL_PROGRAM_BINARY_LENGTH;
using glmixed::GL_PROGRAM_BINARY_RETRIEVABLE_HINT;
using glmixed::GL_PROGRAM_PIPELINE_BINDING;
using glmixed::GL_PROGRAM_POINT_SIZE;
using glmixed::GL_PROGRAM_SEPARABLE;
using glmixed::GL_PROVOKING_VERTEX;
using glmixed::GL_PROXY_TEXTURE_1D;
using glmixed::GL_PROXY_TEXTURE_1D_ARRAY;
using glmixed::GL_PROXY_TEXTURE_2D;
using glmixed::GL_PROXY_TEXTURE_2D_ARRAY;
using glmixed::GL_PROXY_TEXTURE_2D_MULTISAMPLE;
using glmixed::GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_PROXY_TEXTURE_3D;
using glmixed::GL_PROXY_TEXTURE_CUBE_MAP;
using glmixed::GL_PROXY_TEXTURE_CUBE_MAP_ARRAY;
using glmixed::GL_PROXY_TEXTURE_RECTANGLE;
using glmixed::GL_QUADS;
using glmixed::GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION;
using glmixed::GL_QUERY_BY_REGION_NO_WAIT;
using glmixed::GL_QUERY_BY_REGION_WAIT;
using glmixed::GL_QUERY_COUNTER_BITS;
using glmixed::GL_QUERY_NO_WAIT;
using glmixed::GL_QUERY_RESULT;
using glmixed::GL_QUERY_RESULT_AVAILABLE;
using glmixed::GL_QUERY_WAIT;
using glmixed::GL_R11F_G11F_B10F;
using glmixed::GL_R16;
using glmixed::GL_R16_SNORM;
using glmixed::GL_R16F;
using glmixed::GL_R16I;
using glmixed::GL_R16UI;
using glmixed::GL_R32F;
using glmixed::GL_R32I;
using glmixed::GL_R32UI;
using glmixed::GL_R3_G3_B2;
using glmixed::GL_R8;
using glmixed::GL_R8_SNORM;
using glmixed::GL_R8I;
using glmixed::GL_R8UI;
using glmixed::GL_RASTERIZER_DISCARD;
using glmixed::GL_READ_BUFFER;
using glmixed::GL_READ_FRAMEBUFFER;
using glmixed::GL_READ_FRAMEBUFFER_BINDING;
using glmixed::GL_READ_ONLY;
using glmixed::GL_READ_WRITE;
using glmixed::GL_RED;
using glmixed::GL_RED_INTEGER;
using glmixed::GL_RENDERBUFFER;
using glmixed::GL_RENDERBUFFER_ALPHA_SIZE;
using glmixed::GL_RENDERBUFFER_BINDING;
using glmixed::GL_RENDERBUFFER_BLUE_SIZE;
using glmixed::GL_RENDERBUFFER_DEPTH_SIZE;
using glmixed::GL_RENDERBUFFER_GREEN_SIZE;
using glmixed::GL_RENDERBUFFER_HEIGHT;
using glmixed::GL_RENDERBUFFER_INTERNAL_FORMAT;
using glmixed::GL_RENDERBUFFER_RED_SIZE;
using glmixed::GL_RENDERBUFFER_SAMPLES;
using glmixed::GL_RENDERBUFFER_STENCIL_SIZE;
using glmixed::GL_RENDERBUFFER_WIDTH;
using glmixed::GL_RENDERER;
using glmixed::GL_REPEAT;
using glmixed::GL_REPLACE;
using glmixed::GL_RG;
using glmixed::GL_RG16;
using glmixed::GL_RG16_SNORM;
using glmixed::GL_RG16F;
using glmixed::GL_RG16I;
using glmixed::GL_RG16UI;
using glmixed::GL_RG32F;
using glmixed::GL_RG32I;
using glmixed::GL_RG32UI;
using glmixed::GL_RG8;
using glmixed::GL_RG8_SNORM;
using glmixed::GL_RG8I;
using glmixed::GL_RG8UI;
using glmixed::GL_RG_INTEGER;
using glmixed::GL_RGB;
using glmixed::GL_RGB10;
using glmixed::GL_RGB10_A2;
using glmixed::GL_RGB10_A2UI;
using glmixed::GL_RGB12;
using glmixed::GL_RGB16;
using glmixed::GL_RGB16_SNORM;
using glmixed::GL_RGB16F;
using glmixed::GL_RGB16I;
using glmixed::GL_RGB16UI;
using glmixed::GL_RGB32F;
using glmixed::GL_RGB32I;
using glmixed::GL_RGB32UI;
using glmixed::GL_RGB4;
using glmixed::GL_RGB5;
using glmixed::GL_RGB565;
using glmixed::GL_RGB5_A1;
using glmixed::GL_RGB8;
using glmixed::GL_RGB8_SNORM;
using glmixed::GL_RGB8I;
using glmixed::GL_RGB8UI;
using glmixed::GL_RGB9_E5;
using glmixed::GL_RGB_INTEGER;
using glmixed::GL_RGBA;
using glmixed::GL_RGBA12;
using glmixed::GL_RGBA16;
using glmixed::GL_RGBA16_SNORM;
using glmixed::GL_RGBA16F;
using glmixed::GL_RGBA16I;
using glmixed::GL_RGBA16UI;
using glmixed::GL_RGBA2;
using glmixed::GL_RGBA32F;
using glmixed::GL_RGBA32I;
using glmixed::GL_RGBA32UI;
using glmixed::GL_RGBA4;
using glmixed::GL_RGBA8;
using glmixed::GL_RGBA8_SNORM;
using glmixed::GL_RGBA8I;
using glmixed::GL_RGBA8UI;
using glmixed::GL_RGBA_INTEGER;
using glmixed::GL_RIGHT;
using glmixed::GL_SAMPLE_ALPHA_TO_COVERAGE;
using glmixed::GL_SAMPLE_ALPHA_TO_ONE;
using glmixed::GL_SAMPLE_BUFFERS;
using glmixed::GL_SAMPLE_COVERAGE;
using glmixed::GL_SAMPLE_COVERAGE_INVERT;
using glmixed::GL_SAMPLE_COVERAGE_VALUE;
using glmixed::GL_SAMPLE_MASK;
using glmixed::GL_SAMPLE_MASK_VALUE;
using glmixed::GL_SAMPLE_POSITION;
using glmixed::GL_SAMPLE_SHADING;
using glmixed::GL_SAMPLER_1D;
using glmixed::GL_SAMPLER_1D_ARRAY;
using glmixed::GL_SAMPLER_1D_ARRAY_SHADOW;
using glmixed::GL_SAMPLER_1D_SHADOW;
using glmixed::GL_SAMPLER_2D;
using glmixed::GL_SAMPLER_2D_ARRAY;
using glmixed::GL_SAMPLER_2D_ARRAY_SHADOW;
using glmixed::GL_SAMPLER_2D_MULTISAMPLE;
using glmixed::GL_SAMPLER_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_SAMPLER_2D_RECT;
using glmixed::GL_SAMPLER_2D_RECT_SHADOW;
using glmixed::GL_SAMPLER_2D_SHADOW;
using glmixed::GL_SAMPLER_3D;
using glmixed::GL_SAMPLER_BINDING;
using glmixed::GL_SAMPLER_BUFFER;
using glmixed::GL_SAMPLER_CUBE;
using glmixed::GL_SAMPLER_CUBE_MAP_ARRAY;
using glmixed::GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW;
using glmixed::GL_SAMPLER_CUBE_SHADOW;
using glmixed::GL_SAMPLES;
using glmixed::GL_SAMPLES_PASSED;
using glmixed::GL_SCISSOR_BOX;
using glmixed::GL_SCISSOR_TEST;
using glmixed::GL_SEPARATE_ATTRIBS;
using glmixed::GL_SET;
using glmixed::GL_SHADER_BINARY_FORMATS;
using glmixed::GL_SHADER_COMPILER;
using glmixed::GL_SHADER_SOURCE_LENGTH;
using glmixed::GL_SHADER_TYPE;
using glmixed::GL_SHADING_LANGUAGE_VERSION;
using glmixed::GL_SHORT;
using glmixed::GL_SIGNALED;
using glmixed::GL_SIGNED_NORMALIZED;
using glmixed::GL_SMOOTH_LINE_WIDTH_GRANULARITY;
using glmixed::GL_SMOOTH_LINE_WIDTH_RANGE;
using glmixed::GL_SMOOTH_POINT_SIZE_GRANULARITY;
using glmixed::GL_SMOOTH_POINT_SIZE_RANGE;
using glmixed::GL_SRC1_ALPHA;
using glmixed::GL_SRC1_COLOR;
using glmixed::GL_SRC_ALPHA;
using glmixed::GL_SRC_ALPHA_SATURATE;
using glmixed::GL_SRC_COLOR;
using glmixed::GL_SRGB;
using glmixed::GL_SRGB8;
using glmixed::GL_SRGB8_ALPHA8;
using glmixed::GL_SRGB_ALPHA;
using glmixed::GL_STATIC_COPY;
using glmixed::GL_STATIC_DRAW;
using glmixed::GL_STATIC_READ;
using glmixed::GL_STENCIL;
using glmixed::GL_STENCIL_ATTACHMENT;
using glmixed::GL_STENCIL_BACK_FAIL;
using glmixed::GL_STENCIL_BACK_FUNC;
using glmixed::GL_STENCIL_BACK_PASS_DEPTH_FAIL;
using glmixed::GL_STENCIL_BACK_PASS_DEPTH_PASS;
using glmixed::GL_STENCIL_BACK_REF;
using glmixed::GL_STENCIL_BACK_VALUE_MASK;
using glmixed::GL_STENCIL_BACK_WRITEMASK;
using glmixed::GL_STENCIL_CLEAR_VALUE;
using glmixed::GL_STENCIL_FAIL;
using glmixed::GL_STENCIL_FUNC;
using glmixed::GL_STENCIL_INDEX;
using glmixed::GL_STENCIL_INDEX1;
using glmixed::GL_STENCIL_INDEX16;
using glmixed::GL_STENCIL_INDEX4;
using glmixed::GL_STENCIL_INDEX8;
using glmixed::GL_STENCIL_PASS_DEPTH_FAIL;
using glmixed::GL_STENCIL_PASS_DEPTH_PASS;
using glmixed::GL_STENCIL_REF;
using glmixed::GL_STENCIL_TEST;
using glmixed::GL_STENCIL_VALUE_MASK;
using glmixed::GL_STENCIL_WRITEMASK;
using glmixed::GL_STEREO;
using glmixed::GL_STREAM_COPY;
using glmixed::GL_STREAM_DRAW;
using glmixed::GL_STREAM_READ;
using glmixed::GL_SUBPIXEL_BITS;
using glmixed::GL_SYNC_CONDITION;
using glmixed::GL_SYNC_FENCE;
using glmixed::GL_SYNC_FLAGS;
using glmixed::GL_SYNC_GPU_COMMANDS_COMPLETE;
using glmixed::GL_SYNC_STATUS;
using glmixed::GL_TESS_CONTROL_OUTPUT_VERTICES;
using glmixed::GL_TESS_CONTROL_SHADER;
using glmixed::GL_TESS_EVALUATION_SHADER;
using glmixed::GL_TESS_GEN_MODE;
using glmixed::GL_TESS_GEN_POINT_MODE;
using glmixed::GL_TESS_GEN_SPACING;
using glmixed::GL_TESS_GEN_VERTEX_ORDER;
using glmixed::GL_TEXTURE;
using glmixed::GL_TEXTURE0;
using glmixed::GL_TEXTURE1;
using glmixed::GL_TEXTURE10;
using glmixed::GL_TEXTURE11;
using glmixed::GL_TEXTURE12;
using glmixed::GL_TEXTURE13;
using glmixed::GL_TEXTURE14;
using glmixed::GL_TEXTURE15;
using glmixed::GL_TEXTURE16;
using glmixed::GL_TEXTURE17;
using glmixed::GL_TEXTURE18;
using glmixed::GL_TEXTURE19;
using glmixed::GL_TEXTURE2;
using glmixed::GL_TEXTURE20;
using glmixed::GL_TEXTURE21;
using glmixed::GL_TEXTURE22;
using glmixed::GL_TEXTURE23;
using glmixed::GL_TEXTURE24;
using glmixed::GL_TEXTURE25;
using glmixed::GL_TEXTURE26;
using glmixed::GL_TEXTURE27;
using glmixed::GL_TEXTURE28;
using glmixed::GL_TEXTURE29;
using glmixed::GL_TEXTURE3;
using glmixed::GL_TEXTURE30;
using glmixed::GL_TEXTURE31;
using glmixed::GL_TEXTURE4;
using glmixed::GL_TEXTURE5;
using glmixed::GL_TEXTURE6;
using glmixed::GL_TEXTURE7;
using glmixed::GL_TEXTURE8;
using glmixed::GL_TEXTURE9;
using glmixed::GL_TEXTURE_1D;
using glmixed::GL_TEXTURE_1D_ARRAY;
using glmixed::GL_TEXTURE_2D;
using glmixed::GL_TEXTURE_2D_ARRAY;
using glmixed::GL_TEXTURE_2D_MULTISAMPLE;
using glmixed::GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_TEXTURE_3D;
using glmixed::GL_TEXTURE_ALPHA_SIZE;
using glmixed::GL_TEXTURE_ALPHA_TYPE;
using glmixed::GL_TEXTURE_BASE_LEVEL;
using glmixed::GL_TEXTURE_BINDING_1D;
using glmixed::GL_TEXTURE_BINDING_1D_ARRAY;
using glmixed::GL_TEXTURE_BINDING_2D;
using glmixed::GL_TEXTURE_BINDING_2D_ARRAY;
using glmixed::GL_TEXTURE_BINDING_2D_MULTISAMPLE;
using glmixed::GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_TEXTURE_BINDING_3D;
using glmixed::GL_TEXTURE_BINDING_BUFFER;
using glmixed::GL_TEXTURE_BINDING_CUBE_MAP;
using glmixed::GL_TEXTURE_BINDING_CUBE_MAP_ARRAY;
using glmixed::GL_TEXTURE_BINDING_RECTANGLE;
using glmixed::GL_TEXTURE_BLUE_SIZE;
using glmixed::GL_TEXTURE_BLUE_TYPE;
using glmixed::GL_TEXTURE_BORDER_COLOR;
using glmixed::GL_TEXTURE_BUFFER;
using glmixed::GL_TEXTURE_BUFFER_DATA_STORE_BINDING;
using glmixed::GL_TEXTURE_COMPARE_FUNC;
using glmixed::GL_TEXTURE_COMPARE_MODE;
using glmixed::GL_TEXTURE_COMPRESSED;
using glmixed::GL_TEXTURE_COMPRESSED_IMAGE_SIZE;
using glmixed::GL_TEXTURE_COMPRESSION_HINT;
using glmixed::GL_TEXTURE_CUBE_MAP;
using glmixed::GL_TEXTURE_CUBE_MAP_ARRAY;
using glmixed::GL_TEXTURE_CUBE_MAP_NEGATIVE_X;
using glmixed::GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;
using glmixed::GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;
using glmixed::GL_TEXTURE_CUBE_MAP_POSITIVE_X;
using glmixed::GL_TEXTURE_CUBE_MAP_POSITIVE_Y;
using glmixed::GL_TEXTURE_CUBE_MAP_POSITIVE_Z;
using glmixed::GL_TEXTURE_CUBE_MAP_SEAMLESS;
using glmixed::GL_TEXTURE_DEPTH;
using glmixed::GL_TEXTURE_DEPTH_SIZE;
using glmixed::GL_TEXTURE_DEPTH_TYPE;
using glmixed::GL_TEXTURE_FIXED_SAMPLE_LOCATIONS;
using glmixed::GL_TEXTURE_GREEN_SIZE;
using glmixed::GL_TEXTURE_GREEN_TYPE;
using glmixed::GL_TEXTURE_HEIGHT;
using glmixed::GL_TEXTURE_IMMUTABLE_FORMAT;
using glmixed::GL_TEXTURE_INTERNAL_FORMAT;
using glmixed::GL_TEXTURE_LOD_BIAS;
using glmixed::GL_TEXTURE_MAG_FILTER;
using glmixed::GL_TEXTURE_MAX_LEVEL;
using glmixed::GL_TEXTURE_MAX_LOD;
using glmixed::GL_TEXTURE_MIN_FILTER;
using glmixed::GL_TEXTURE_MIN_LOD;
using glmixed::GL_TEXTURE_RECTANGLE;
using glmixed::GL_TEXTURE_RED_SIZE;
using glmixed::GL_TEXTURE_RED_TYPE;
using glmixed::GL_TEXTURE_SAMPLES;
using glmixed::GL_TEXTURE_SHARED_SIZE;
using glmixed::GL_TEXTURE_STENCIL_SIZE;
using glmixed::GL_TEXTURE_SWIZZLE_A;
using glmixed::GL_TEXTURE_SWIZZLE_B;
using glmixed::GL_TEXTURE_SWIZZLE_G;
using glmixed::GL_TEXTURE_SWIZZLE_R;
using glmixed::GL_TEXTURE_SWIZZLE_RGBA;
using glmixed::GL_TEXTURE_WIDTH;
using glmixed::GL_TEXTURE_WRAP_R;
using glmixed::GL_TEXTURE_WRAP_S;
using glmixed::GL_TEXTURE_WRAP_T;
using glmixed::GL_TIME_ELAPSED;
using glmixed::GL_TIMEOUT_EXPIRED;
using glmixed::GL_TIMESTAMP;
using glmixed::GL_TRANSFORM_FEEDBACK;
using glmixed::GL_TRANSFORM_FEEDBACK_ACTIVE;
using glmixed::GL_TRANSFORM_FEEDBACK_BINDING;
using glmixed::GL_TRANSFORM_FEEDBACK_BUFFER;
using glmixed::GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE;
using glmixed::GL_TRANSFORM_FEEDBACK_BUFFER_BINDING;
using glmixed::GL_TRANSFORM_FEEDBACK_BUFFER_MODE;
using glmixed::GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED;
using glmixed::GL_TRANSFORM_FEEDBACK_BUFFER_SIZE;
using glmixed::GL_TRANSFORM_FEEDBACK_BUFFER_START;
using glmixed::GL_TRANSFORM_FEEDBACK_PAUSED;
using glmixed::GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN;
using glmixed::GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH;
using glmixed::GL_TRANSFORM_FEEDBACK_VARYINGS;
using glmixed::GL_TRIANGLE_FAN;
using glmixed::GL_TRIANGLE_STRIP;
using glmixed::GL_TRIANGLE_STRIP_ADJACENCY;
using glmixed::GL_TRIANGLES;
using glmixed::GL_TRIANGLES_ADJACENCY;
using glmixed::GL_UNDEFINED_VERTEX;
using glmixed::GL_UNIFORM_ARRAY_STRIDE;
using glmixed::GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX;
using glmixed::GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES;
using glmixed::GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS;
using glmixed::GL_UNIFORM_BLOCK_BINDING;
using glmixed::GL_UNIFORM_BLOCK_DATA_SIZE;
using glmixed::GL_UNIFORM_BLOCK_INDEX;
using glmixed::GL_UNIFORM_BLOCK_NAME_LENGTH;
using glmixed::GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER;
using glmixed::GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER;
using glmixed::GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER;
using glmixed::GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER;
using glmixed::GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER;
using glmixed::GL_UNIFORM_BUFFER;
using glmixed::GL_UNIFORM_BUFFER_BINDING;
using glmixed::GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT;
using glmixed::GL_UNIFORM_BUFFER_SIZE;
using glmixed::GL_UNIFORM_BUFFER_START;
using glmixed::GL_UNIFORM_IS_ROW_MAJOR;
using glmixed::GL_UNIFORM_MATRIX_STRIDE;
using glmixed::GL_UNIFORM_NAME_LENGTH;
using glmixed::GL_UNIFORM_OFFSET;
using glmixed::GL_UNIFORM_SIZE;
using glmixed::GL_UNIFORM_TYPE;
using glmixed::GL_UNPACK_ALIGNMENT;
using glmixed::GL_UNPACK_COMPRESSED_BLOCK_DEPTH;
using glmixed::GL_UNPACK_COMPRESSED_BLOCK_HEIGHT;
using glmixed::GL_UNPACK_COMPRESSED_BLOCK_SIZE;
using glmixed::GL_UNPACK_COMPRESSED_BLOCK_WIDTH;
using glmixed::GL_UNPACK_IMAGE_HEIGHT;
using glmixed::GL_UNPACK_LSB_FIRST;
using glmixed::GL_UNPACK_ROW_LENGTH;
using glmixed::GL_UNPACK_SKIP_IMAGES;
using glmixed::GL_UNPACK_SKIP_PIXELS;
using glmixed::GL_UNPACK_SKIP_ROWS;
using glmixed::GL_UNPACK_SWAP_BYTES;
using glmixed::GL_UNSIGNALED;
using glmixed::GL_UNSIGNED_BYTE;
using glmixed::GL_UNSIGNED_BYTE_2_3_3_REV;
using glmixed::GL_UNSIGNED_BYTE_3_3_2;
using glmixed::GL_UNSIGNED_INT;
using glmixed::GL_UNSIGNED_INT_10_10_10_2;
using glmixed::GL_UNSIGNED_INT_10F_11F_11F_REV;
using glmixed::GL_UNSIGNED_INT_24_8;
using glmixed::GL_UNSIGNED_INT_2_10_10_10_REV;
using glmixed::GL_UNSIGNED_INT_5_9_9_9_REV;
using glmixed::GL_UNSIGNED_INT_8_8_8_8;
using glmixed::GL_UNSIGNED_INT_8_8_8_8_REV;
using glmixed::GL_UNSIGNED_INT_ATOMIC_COUNTER;
using glmixed::GL_UNSIGNED_INT_IMAGE_1D;
using glmixed::GL_UNSIGNED_INT_IMAGE_1D_ARRAY;
using glmixed::GL_UNSIGNED_INT_IMAGE_2D;
using glmixed::GL_UNSIGNED_INT_IMAGE_2D_ARRAY;
using glmixed::GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE;
using glmixed::GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_UNSIGNED_INT_IMAGE_2D_RECT;
using glmixed::GL_UNSIGNED_INT_IMAGE_3D;
using glmixed::GL_UNSIGNED_INT_IMAGE_BUFFER;
using glmixed::GL_UNSIGNED_INT_IMAGE_CUBE;
using glmixed::GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY;
using glmixed::GL_UNSIGNED_INT_SAMPLER_1D;
using glmixed::GL_UNSIGNED_INT_SAMPLER_1D_ARRAY;
using glmixed::GL_UNSIGNED_INT_SAMPLER_2D;
using glmixed::GL_UNSIGNED_INT_SAMPLER_2D_ARRAY;
using glmixed::GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE;
using glmixed::GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY;
using glmixed::GL_UNSIGNED_INT_SAMPLER_2D_RECT;
using glmixed::GL_UNSIGNED_INT_SAMPLER_3D;
using glmixed::GL_UNSIGNED_INT_SAMPLER_BUFFER;
using glmixed::GL_UNSIGNED_INT_SAMPLER_CUBE;
using glmixed::GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY;
using glmixed::GL_UNSIGNED_INT_VEC2;
using glmixed::GL_UNSIGNED_INT_VEC3;
using glmixed::GL_UNSIGNED_INT_VEC4;
using glmixed::GL_UNSIGNED_NORMALIZED;
using glmixed::GL_UNSIGNED_SHORT;
using glmixed::GL_UNSIGNED_SHORT_1_5_5_5_REV;
using glmixed::GL_UNSIGNED_SHORT_4_4_4_4;
using glmixed::GL_UNSIGNED_SHORT_4_4_4_4_REV;
using glmixed::GL_UNSIGNED_SHORT_5_5_5_1;
using glmixed::GL_UNSIGNED_SHORT_5_6_5;
using glmixed::GL_UNSIGNED_SHORT_5_6_5_REV;
using glmixed::GL_UPPER_LEFT;
using glmixed::GL_VALIDATE_STATUS;
using glmixed::GL_VENDOR;
using glmixed::GL_VERSION;
using glmixed::GL_VERTEX_ARRAY_BINDING;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_DIVISOR;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_ENABLED;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_INTEGER;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_NORMALIZED;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_POINTER;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_SIZE;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_STRIDE;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_TYPE;
using glmixed::GL_VERTEX_PROGRAM_POINT_SIZE;
using glmixed::GL_VERTEX_SHADER;
using glmixed::GL_VIEWPORT;
using glmixed::GL_VIEWPORT_BOUNDS_RANGE;
using glmixed::GL_VIEWPORT_INDEX_PROVOKING_VERTEX;
using glmixed::GL_VIEWPORT_SUBPIXEL_BITS;
using glmixed::GL_WAIT_FAILED;
using glmixed::GL_WRITE_ONLY;
using glmixed::GL_XOR;
using glmixed::GL_ZERO;


} // namespace gl42