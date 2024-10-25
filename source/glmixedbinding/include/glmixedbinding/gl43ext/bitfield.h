
#pragma once


#include <glmixedbinding/noglmixed.h>

#include <glmixedbinding/glmixed/bitfield.h>


namespace gl43ext
{


// import bitfields to namespace
using glmixed::GL_2X_BIT_ATI;
using glmixed::GL_4X_BIT_ATI;
using glmixed::GL_8X_BIT_ATI;
using glmixed::GL_ALL_BARRIER_BITS_EXT;
using glmixed::GL_ALL_SHADER_BITS_EXT;
using glmixed::GL_ATOMIC_COUNTER_BARRIER_BIT_EXT;
using glmixed::GL_BIAS_BIT_ATI;
using glmixed::GL_BLUE_BIT_ATI;
using glmixed::GL_BOLD_BIT_NV;
using glmixed::GL_BUFFER_UPDATE_BARRIER_BIT_EXT;
using glmixed::GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT;
using glmixed::GL_CLIENT_STORAGE_BIT;
using glmixed::GL_COLOR3_BIT_PGI;
using glmixed::GL_COLOR4_BIT_PGI;
using glmixed::GL_COMMAND_BARRIER_BIT_EXT;
using glmixed::GL_COMP_BIT_ATI;
using glmixed::GL_CONTEXT_FLAG_DEBUG_BIT_KHR;
using glmixed::GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR;
using glmixed::GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB;
using glmixed::GL_DYNAMIC_STORAGE_BIT;
using glmixed::GL_EDGEFLAG_BIT_PGI;
using glmixed::GL_EIGHTH_BIT_ATI;
using glmixed::GL_ELEMENT_ARRAY_BARRIER_BIT_EXT;
using glmixed::GL_FONT_ASCENDER_BIT_NV;
using glmixed::GL_FONT_DESCENDER_BIT_NV;
using glmixed::GL_FONT_HAS_KERNING_BIT_NV;
using glmixed::GL_FONT_HEIGHT_BIT_NV;
using glmixed::GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV;
using glmixed::GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV;
using glmixed::GL_FONT_NUM_GLYPH_INDICES_BIT_NV;
using glmixed::GL_FONT_UNDERLINE_POSITION_BIT_NV;
using glmixed::GL_FONT_UNDERLINE_THICKNESS_BIT_NV;
using glmixed::GL_FONT_UNITS_PER_EM_BIT_NV;
using glmixed::GL_FONT_X_MAX_BOUNDS_BIT_NV;
using glmixed::GL_FONT_X_MIN_BOUNDS_BIT_NV;
using glmixed::GL_FONT_Y_MAX_BOUNDS_BIT_NV;
using glmixed::GL_FONT_Y_MIN_BOUNDS_BIT_NV;
using glmixed::GL_FRAGMENT_SHADER_BIT_EXT;
using glmixed::GL_FRAMEBUFFER_BARRIER_BIT_EXT;
using glmixed::GL_GEOMETRY_DEFORMATION_BIT_SGIX;
using glmixed::GL_GLYPH_HAS_KERNING_BIT_NV;
using glmixed::GL_GLYPH_HEIGHT_BIT_NV;
using glmixed::GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV;
using glmixed::GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV;
using glmixed::GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV;
using glmixed::GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV;
using glmixed::GL_GLYPH_VERTICAL_BEARING_X_BIT_NV;
using glmixed::GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV;
using glmixed::GL_GLYPH_WIDTH_BIT_NV;
using glmixed::GL_GREEN_BIT_ATI;
using glmixed::GL_HALF_BIT_ATI;
using glmixed::GL_INDEX_BIT_PGI;
using glmixed::GL_ITALIC_BIT_NV;
using glmixed::GL_LGPU_SEPARATE_STORAGE_BIT_NVX;
using glmixed::GL_MAP_COHERENT_BIT;
using glmixed::GL_MAP_PERSISTENT_BIT;
using glmixed::GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI;
using glmixed::GL_MAT_AMBIENT_BIT_PGI;
using glmixed::GL_MAT_COLOR_INDEXES_BIT_PGI;
using glmixed::GL_MAT_DIFFUSE_BIT_PGI;
using glmixed::GL_MAT_EMISSION_BIT_PGI;
using glmixed::GL_MAT_SHININESS_BIT_PGI;
using glmixed::GL_MAT_SPECULAR_BIT_PGI;
using glmixed::GL_MESH_SHADER_BIT_NV;
using glmixed::GL_MULTISAMPLE_BIT_3DFX;
using glmixed::GL_MULTISAMPLE_BIT_ARB;
using glmixed::GL_MULTISAMPLE_BIT_EXT;
using glmixed::GL_NEGATE_BIT_ATI;
using glmixed::GL_NORMAL_BIT_PGI;
using glmixed::GL_PER_GPU_STORAGE_BIT_NV;
using glmixed::GL_PERFQUERY_GLOBAL_CONTEXT_INTEL;
using glmixed::GL_PERFQUERY_SINGLE_CONTEXT_INTEL;
using glmixed::GL_PIXEL_BUFFER_BARRIER_BIT_EXT;
using glmixed::GL_QUARTER_BIT_ATI;
using glmixed::GL_QUERY_ALL_EVENT_BITS_AMD;
using glmixed::GL_QUERY_BUFFER_BARRIER_BIT;
using glmixed::GL_QUERY_DEPTH_BOUNDS_FAIL_EVENT_BIT_AMD;
using glmixed::GL_QUERY_DEPTH_FAIL_EVENT_BIT_AMD;
using glmixed::GL_QUERY_DEPTH_PASS_EVENT_BIT_AMD;
using glmixed::GL_QUERY_STENCIL_FAIL_EVENT_BIT_AMD;
using glmixed::GL_RED_BIT_ATI;
using glmixed::GL_SATURATE_BIT_ATI;
using glmixed::GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV;
using glmixed::GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT;
using glmixed::GL_SPARSE_STORAGE_BIT_ARB;
using glmixed::GL_TASK_SHADER_BIT_NV;
using glmixed::GL_TEXCOORD1_BIT_PGI;
using glmixed::GL_TEXCOORD2_BIT_PGI;
using glmixed::GL_TEXCOORD3_BIT_PGI;
using glmixed::GL_TEXCOORD4_BIT_PGI;
using glmixed::GL_TEXTURE_DEFORMATION_BIT_SGIX;
using glmixed::GL_TEXTURE_FETCH_BARRIER_BIT_EXT;
using glmixed::GL_TEXTURE_STORAGE_SPARSE_BIT_AMD;
using glmixed::GL_TEXTURE_UPDATE_BARRIER_BIT_EXT;
using glmixed::GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT;
using glmixed::GL_UNIFORM_BARRIER_BIT_EXT;
using glmixed::GL_VERTEX23_BIT_PGI;
using glmixed::GL_VERTEX4_BIT_PGI;
using glmixed::GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT;
using glmixed::GL_VERTEX_SHADER_BIT_EXT;


} // namespace gl43ext