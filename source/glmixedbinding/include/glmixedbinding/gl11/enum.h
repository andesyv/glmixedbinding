
#pragma once


#include <glmixedbinding/noglmixed.h>

#include <glmixedbinding/glmixed/enum.h>


namespace gl11
{


// use enum type
using glmixed::GLenum;


// import enums to namespace
using glmixed::GL_2_BYTES;
using glmixed::GL_2D;
using glmixed::GL_3_BYTES;
using glmixed::GL_3D;
using glmixed::GL_3D_COLOR;
using glmixed::GL_3D_COLOR_TEXTURE;
using glmixed::GL_4_BYTES;
using glmixed::GL_4D_COLOR_TEXTURE;
using glmixed::GL_ACCUM;
using glmixed::GL_ACCUM_ALPHA_BITS;
using glmixed::GL_ACCUM_BLUE_BITS;
using glmixed::GL_ACCUM_CLEAR_VALUE;
using glmixed::GL_ACCUM_GREEN_BITS;
using glmixed::GL_ACCUM_RED_BITS;
using glmixed::GL_ADD;
using glmixed::GL_ALPHA;
using glmixed::GL_ALPHA12;
using glmixed::GL_ALPHA16;
using glmixed::GL_ALPHA4;
using glmixed::GL_ALPHA8;
using glmixed::GL_ALPHA_BIAS;
using glmixed::GL_ALPHA_BITS;
using glmixed::GL_ALPHA_SCALE;
using glmixed::GL_ALPHA_TEST;
using glmixed::GL_ALPHA_TEST_FUNC;
using glmixed::GL_ALPHA_TEST_REF;
using glmixed::GL_ALWAYS;
using glmixed::GL_AMBIENT;
using glmixed::GL_AMBIENT_AND_DIFFUSE;
using glmixed::GL_AND;
using glmixed::GL_AND_INVERTED;
using glmixed::GL_AND_REVERSE;
using glmixed::GL_ATTRIB_STACK_DEPTH;
using glmixed::GL_AUTO_NORMAL;
using glmixed::GL_AUX0;
using glmixed::GL_AUX1;
using glmixed::GL_AUX2;
using glmixed::GL_AUX3;
using glmixed::GL_AUX_BUFFERS;
using glmixed::GL_BACK;
using glmixed::GL_BACK_LEFT;
using glmixed::GL_BACK_RIGHT;
using glmixed::GL_BITMAP;
using glmixed::GL_BITMAP_TOKEN;
using glmixed::GL_BLEND;
using glmixed::GL_BLEND_DST;
using glmixed::GL_BLEND_SRC;
using glmixed::GL_BLUE;
using glmixed::GL_BLUE_BIAS;
using glmixed::GL_BLUE_BITS;
using glmixed::GL_BLUE_SCALE;
using glmixed::GL_BYTE;
using glmixed::GL_C3F_V3F;
using glmixed::GL_C4F_N3F_V3F;
using glmixed::GL_C4UB_V2F;
using glmixed::GL_C4UB_V3F;
using glmixed::GL_CCW;
using glmixed::GL_CLAMP;
using glmixed::GL_CLEAR;
using glmixed::GL_CLIENT_ATTRIB_STACK_DEPTH;
using glmixed::GL_CLIP_PLANE0;
using glmixed::GL_CLIP_PLANE1;
using glmixed::GL_CLIP_PLANE2;
using glmixed::GL_CLIP_PLANE3;
using glmixed::GL_CLIP_PLANE4;
using glmixed::GL_CLIP_PLANE5;
using glmixed::GL_COEFF;
using glmixed::GL_COLOR;
using glmixed::GL_COLOR_ARRAY;
using glmixed::GL_COLOR_ARRAY_POINTER;
using glmixed::GL_COLOR_ARRAY_SIZE;
using glmixed::GL_COLOR_ARRAY_STRIDE;
using glmixed::GL_COLOR_ARRAY_TYPE;
using glmixed::GL_COLOR_CLEAR_VALUE;
using glmixed::GL_COLOR_INDEX;
using glmixed::GL_COLOR_INDEXES;
using glmixed::GL_COLOR_LOGIC_OP;
using glmixed::GL_COLOR_MATERIAL;
using glmixed::GL_COLOR_MATERIAL_FACE;
using glmixed::GL_COLOR_MATERIAL_PARAMETER;
using glmixed::GL_COLOR_WRITEMASK;
using glmixed::GL_COMPILE;
using glmixed::GL_COMPILE_AND_EXECUTE;
using glmixed::GL_CONSTANT_ATTENUATION;
using glmixed::GL_COPY;
using glmixed::GL_COPY_INVERTED;
using glmixed::GL_COPY_PIXEL_TOKEN;
using glmixed::GL_CULL_FACE;
using glmixed::GL_CULL_FACE_MODE;
using glmixed::GL_CURRENT_COLOR;
using glmixed::GL_CURRENT_INDEX;
using glmixed::GL_CURRENT_NORMAL;
using glmixed::GL_CURRENT_RASTER_COLOR;
using glmixed::GL_CURRENT_RASTER_DISTANCE;
using glmixed::GL_CURRENT_RASTER_INDEX;
using glmixed::GL_CURRENT_RASTER_POSITION;
using glmixed::GL_CURRENT_RASTER_POSITION_VALID;
using glmixed::GL_CURRENT_RASTER_TEXTURE_COORDS;
using glmixed::GL_CURRENT_TEXTURE_COORDS;
using glmixed::GL_CW;
using glmixed::GL_DECAL;
using glmixed::GL_DECR;
using glmixed::GL_DEPTH;
using glmixed::GL_DEPTH_BIAS;
using glmixed::GL_DEPTH_BITS;
using glmixed::GL_DEPTH_CLEAR_VALUE;
using glmixed::GL_DEPTH_COMPONENT;
using glmixed::GL_DEPTH_FUNC;
using glmixed::GL_DEPTH_RANGE;
using glmixed::GL_DEPTH_SCALE;
using glmixed::GL_DEPTH_TEST;
using glmixed::GL_DEPTH_WRITEMASK;
using glmixed::GL_DIFFUSE;
using glmixed::GL_DITHER;
using glmixed::GL_DOMAIN;
using glmixed::GL_DONT_CARE;
using glmixed::GL_DOUBLE;
using glmixed::GL_DOUBLEBUFFER;
using glmixed::GL_DRAW_BUFFER;
using glmixed::GL_DRAW_PIXEL_TOKEN;
using glmixed::GL_DST_ALPHA;
using glmixed::GL_DST_COLOR;
using glmixed::GL_EDGE_FLAG;
using glmixed::GL_EDGE_FLAG_ARRAY;
using glmixed::GL_EDGE_FLAG_ARRAY_POINTER;
using glmixed::GL_EDGE_FLAG_ARRAY_STRIDE;
using glmixed::GL_EMISSION;
using glmixed::GL_EQUAL;
using glmixed::GL_EQUIV;
using glmixed::GL_EXP;
using glmixed::GL_EXP2;
using glmixed::GL_EXTENSIONS;
using glmixed::GL_EYE_LINEAR;
using glmixed::GL_EYE_PLANE;
using glmixed::GL_FASTEST;
using glmixed::GL_FEEDBACK;
using glmixed::GL_FEEDBACK_BUFFER_POINTER;
using glmixed::GL_FEEDBACK_BUFFER_SIZE;
using glmixed::GL_FEEDBACK_BUFFER_TYPE;
using glmixed::GL_FILL;
using glmixed::GL_FLAT;
using glmixed::GL_FLOAT;
using glmixed::GL_FOG;
using glmixed::GL_FOG_COLOR;
using glmixed::GL_FOG_DENSITY;
using glmixed::GL_FOG_END;
using glmixed::GL_FOG_HINT;
using glmixed::GL_FOG_INDEX;
using glmixed::GL_FOG_MODE;
using glmixed::GL_FOG_START;
using glmixed::GL_FRONT;
using glmixed::GL_FRONT_AND_BACK;
using glmixed::GL_FRONT_FACE;
using glmixed::GL_FRONT_LEFT;
using glmixed::GL_FRONT_RIGHT;
using glmixed::GL_GEQUAL;
using glmixed::GL_GREATER;
using glmixed::GL_GREEN;
using glmixed::GL_GREEN_BIAS;
using glmixed::GL_GREEN_BITS;
using glmixed::GL_GREEN_SCALE;
using glmixed::GL_INCR;
using glmixed::GL_INDEX_ARRAY;
using glmixed::GL_INDEX_ARRAY_POINTER;
using glmixed::GL_INDEX_ARRAY_STRIDE;
using glmixed::GL_INDEX_ARRAY_TYPE;
using glmixed::GL_INDEX_BITS;
using glmixed::GL_INDEX_CLEAR_VALUE;
using glmixed::GL_INDEX_LOGIC_OP;
using glmixed::GL_INDEX_MODE;
using glmixed::GL_INDEX_OFFSET;
using glmixed::GL_INDEX_SHIFT;
using glmixed::GL_INDEX_WRITEMASK;
using glmixed::GL_INT;
using glmixed::GL_INTENSITY;
using glmixed::GL_INTENSITY12;
using glmixed::GL_INTENSITY16;
using glmixed::GL_INTENSITY4;
using glmixed::GL_INTENSITY8;
using glmixed::GL_INVALID_ENUM;
using glmixed::GL_INVALID_OPERATION;
using glmixed::GL_INVALID_VALUE;
using glmixed::GL_INVERT;
using glmixed::GL_KEEP;
using glmixed::GL_LEFT;
using glmixed::GL_LEQUAL;
using glmixed::GL_LESS;
using glmixed::GL_LIGHT0;
using glmixed::GL_LIGHT1;
using glmixed::GL_LIGHT2;
using glmixed::GL_LIGHT3;
using glmixed::GL_LIGHT4;
using glmixed::GL_LIGHT5;
using glmixed::GL_LIGHT6;
using glmixed::GL_LIGHT7;
using glmixed::GL_LIGHT_MODEL_AMBIENT;
using glmixed::GL_LIGHT_MODEL_LOCAL_VIEWER;
using glmixed::GL_LIGHT_MODEL_TWO_SIDE;
using glmixed::GL_LIGHTING;
using glmixed::GL_LINE;
using glmixed::GL_LINE_LOOP;
using glmixed::GL_LINE_RESET_TOKEN;
using glmixed::GL_LINE_SMOOTH;
using glmixed::GL_LINE_SMOOTH_HINT;
using glmixed::GL_LINE_STIPPLE;
using glmixed::GL_LINE_STIPPLE_PATTERN;
using glmixed::GL_LINE_STIPPLE_REPEAT;
using glmixed::GL_LINE_STRIP;
using glmixed::GL_LINE_TOKEN;
using glmixed::GL_LINE_WIDTH;
using glmixed::GL_LINE_WIDTH_GRANULARITY;
using glmixed::GL_LINE_WIDTH_RANGE;
using glmixed::GL_LINEAR;
using glmixed::GL_LINEAR_ATTENUATION;
using glmixed::GL_LINEAR_MIPMAP_LINEAR;
using glmixed::GL_LINEAR_MIPMAP_NEAREST;
using glmixed::GL_LINES;
using glmixed::GL_LIST_BASE;
using glmixed::GL_LIST_INDEX;
using glmixed::GL_LIST_MODE;
using glmixed::GL_LOAD;
using glmixed::GL_LOGIC_OP;
using glmixed::GL_LOGIC_OP_MODE;
using glmixed::GL_LUMINANCE;
using glmixed::GL_LUMINANCE12;
using glmixed::GL_LUMINANCE12_ALPHA12;
using glmixed::GL_LUMINANCE12_ALPHA4;
using glmixed::GL_LUMINANCE16;
using glmixed::GL_LUMINANCE16_ALPHA16;
using glmixed::GL_LUMINANCE4;
using glmixed::GL_LUMINANCE4_ALPHA4;
using glmixed::GL_LUMINANCE6_ALPHA2;
using glmixed::GL_LUMINANCE8;
using glmixed::GL_LUMINANCE8_ALPHA8;
using glmixed::GL_LUMINANCE_ALPHA;
using glmixed::GL_MAP1_COLOR_4;
using glmixed::GL_MAP1_GRID_DOMAIN;
using glmixed::GL_MAP1_GRID_SEGMENTS;
using glmixed::GL_MAP1_INDEX;
using glmixed::GL_MAP1_NORMAL;
using glmixed::GL_MAP1_TEXTURE_COORD_1;
using glmixed::GL_MAP1_TEXTURE_COORD_2;
using glmixed::GL_MAP1_TEXTURE_COORD_3;
using glmixed::GL_MAP1_TEXTURE_COORD_4;
using glmixed::GL_MAP1_VERTEX_3;
using glmixed::GL_MAP1_VERTEX_4;
using glmixed::GL_MAP2_COLOR_4;
using glmixed::GL_MAP2_GRID_DOMAIN;
using glmixed::GL_MAP2_GRID_SEGMENTS;
using glmixed::GL_MAP2_INDEX;
using glmixed::GL_MAP2_NORMAL;
using glmixed::GL_MAP2_TEXTURE_COORD_1;
using glmixed::GL_MAP2_TEXTURE_COORD_2;
using glmixed::GL_MAP2_TEXTURE_COORD_3;
using glmixed::GL_MAP2_TEXTURE_COORD_4;
using glmixed::GL_MAP2_VERTEX_3;
using glmixed::GL_MAP2_VERTEX_4;
using glmixed::GL_MAP_COLOR;
using glmixed::GL_MAP_STENCIL;
using glmixed::GL_MATRIX_MODE;
using glmixed::GL_MAX_ATTRIB_STACK_DEPTH;
using glmixed::GL_MAX_CLIENT_ATTRIB_STACK_DEPTH;
using glmixed::GL_MAX_CLIP_PLANES;
using glmixed::GL_MAX_EVAL_ORDER;
using glmixed::GL_MAX_LIGHTS;
using glmixed::GL_MAX_LIST_NESTING;
using glmixed::GL_MAX_MODELVIEW_STACK_DEPTH;
using glmixed::GL_MAX_NAME_STACK_DEPTH;
using glmixed::GL_MAX_PIXEL_MAP_TABLE;
using glmixed::GL_MAX_PROJECTION_STACK_DEPTH;
using glmixed::GL_MAX_TEXTURE_SIZE;
using glmixed::GL_MAX_TEXTURE_STACK_DEPTH;
using glmixed::GL_MAX_VIEWPORT_DIMS;
using glmixed::GL_MODELVIEW;
using glmixed::GL_MODELVIEW_MATRIX;
using glmixed::GL_MODELVIEW_STACK_DEPTH;
using glmixed::GL_MODULATE;
using glmixed::GL_MULT;
using glmixed::GL_N3F_V3F;
using glmixed::GL_NAME_STACK_DEPTH;
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
using glmixed::GL_NORMAL_ARRAY;
using glmixed::GL_NORMAL_ARRAY_POINTER;
using glmixed::GL_NORMAL_ARRAY_STRIDE;
using glmixed::GL_NORMAL_ARRAY_TYPE;
using glmixed::GL_NORMALIZE;
using glmixed::GL_NOTEQUAL;
using glmixed::GL_OBJECT_LINEAR;
using glmixed::GL_OBJECT_PLANE;
using glmixed::GL_ONE;
using glmixed::GL_ONE_MINUS_DST_ALPHA;
using glmixed::GL_ONE_MINUS_DST_COLOR;
using glmixed::GL_ONE_MINUS_SRC_ALPHA;
using glmixed::GL_ONE_MINUS_SRC_COLOR;
using glmixed::GL_OR;
using glmixed::GL_OR_INVERTED;
using glmixed::GL_OR_REVERSE;
using glmixed::GL_ORDER;
using glmixed::GL_OUT_OF_MEMORY;
using glmixed::GL_PACK_ALIGNMENT;
using glmixed::GL_PACK_LSB_FIRST;
using glmixed::GL_PACK_ROW_LENGTH;
using glmixed::GL_PACK_SKIP_PIXELS;
using glmixed::GL_PACK_SKIP_ROWS;
using glmixed::GL_PACK_SWAP_BYTES;
using glmixed::GL_PASS_THROUGH_TOKEN;
using glmixed::GL_PERSPECTIVE_CORRECTION_HINT;
using glmixed::GL_PIXEL_MAP_A_TO_A;
using glmixed::GL_PIXEL_MAP_A_TO_A_SIZE;
using glmixed::GL_PIXEL_MAP_B_TO_B;
using glmixed::GL_PIXEL_MAP_B_TO_B_SIZE;
using glmixed::GL_PIXEL_MAP_G_TO_G;
using glmixed::GL_PIXEL_MAP_G_TO_G_SIZE;
using glmixed::GL_PIXEL_MAP_I_TO_A;
using glmixed::GL_PIXEL_MAP_I_TO_A_SIZE;
using glmixed::GL_PIXEL_MAP_I_TO_B;
using glmixed::GL_PIXEL_MAP_I_TO_B_SIZE;
using glmixed::GL_PIXEL_MAP_I_TO_G;
using glmixed::GL_PIXEL_MAP_I_TO_G_SIZE;
using glmixed::GL_PIXEL_MAP_I_TO_I;
using glmixed::GL_PIXEL_MAP_I_TO_I_SIZE;
using glmixed::GL_PIXEL_MAP_I_TO_R;
using glmixed::GL_PIXEL_MAP_I_TO_R_SIZE;
using glmixed::GL_PIXEL_MAP_R_TO_R;
using glmixed::GL_PIXEL_MAP_R_TO_R_SIZE;
using glmixed::GL_PIXEL_MAP_S_TO_S;
using glmixed::GL_PIXEL_MAP_S_TO_S_SIZE;
using glmixed::GL_POINT;
using glmixed::GL_POINT_SIZE;
using glmixed::GL_POINT_SIZE_GRANULARITY;
using glmixed::GL_POINT_SIZE_RANGE;
using glmixed::GL_POINT_SMOOTH;
using glmixed::GL_POINT_SMOOTH_HINT;
using glmixed::GL_POINT_TOKEN;
using glmixed::GL_POINTS;
using glmixed::GL_POLYGON;
using glmixed::GL_POLYGON_MODE;
using glmixed::GL_POLYGON_OFFSET_FACTOR;
using glmixed::GL_POLYGON_OFFSET_FILL;
using glmixed::GL_POLYGON_OFFSET_LINE;
using glmixed::GL_POLYGON_OFFSET_POINT;
using glmixed::GL_POLYGON_OFFSET_UNITS;
using glmixed::GL_POLYGON_SMOOTH;
using glmixed::GL_POLYGON_SMOOTH_HINT;
using glmixed::GL_POLYGON_STIPPLE;
using glmixed::GL_POLYGON_TOKEN;
using glmixed::GL_POSITION;
using glmixed::GL_PROJECTION;
using glmixed::GL_PROJECTION_MATRIX;
using glmixed::GL_PROJECTION_STACK_DEPTH;
using glmixed::GL_PROXY_TEXTURE_1D;
using glmixed::GL_PROXY_TEXTURE_2D;
using glmixed::GL_Q;
using glmixed::GL_QUAD_STRIP;
using glmixed::GL_QUADRATIC_ATTENUATION;
using glmixed::GL_QUADS;
using glmixed::GL_R;
using glmixed::GL_R3_G3_B2;
using glmixed::GL_READ_BUFFER;
using glmixed::GL_RED;
using glmixed::GL_RED_BIAS;
using glmixed::GL_RED_BITS;
using glmixed::GL_RED_SCALE;
using glmixed::GL_RENDER;
using glmixed::GL_RENDER_MODE;
using glmixed::GL_RENDERER;
using glmixed::GL_REPEAT;
using glmixed::GL_REPLACE;
using glmixed::GL_RETURN;
using glmixed::GL_RGB;
using glmixed::GL_RGB10;
using glmixed::GL_RGB10_A2;
using glmixed::GL_RGB12;
using glmixed::GL_RGB16;
using glmixed::GL_RGB4;
using glmixed::GL_RGB5;
using glmixed::GL_RGB5_A1;
using glmixed::GL_RGB8;
using glmixed::GL_RGBA;
using glmixed::GL_RGBA12;
using glmixed::GL_RGBA16;
using glmixed::GL_RGBA2;
using glmixed::GL_RGBA4;
using glmixed::GL_RGBA8;
using glmixed::GL_RGBA_MODE;
using glmixed::GL_RIGHT;
using glmixed::GL_S;
using glmixed::GL_SCISSOR_BOX;
using glmixed::GL_SCISSOR_TEST;
using glmixed::GL_SELECT;
using glmixed::GL_SELECTION_BUFFER_POINTER;
using glmixed::GL_SELECTION_BUFFER_SIZE;
using glmixed::GL_SET;
using glmixed::GL_SHADE_MODEL;
using glmixed::GL_SHININESS;
using glmixed::GL_SHORT;
using glmixed::GL_SMOOTH;
using glmixed::GL_SPECULAR;
using glmixed::GL_SPHERE_MAP;
using glmixed::GL_SPOT_CUTOFF;
using glmixed::GL_SPOT_DIRECTION;
using glmixed::GL_SPOT_EXPONENT;
using glmixed::GL_SRC_ALPHA;
using glmixed::GL_SRC_ALPHA_SATURATE;
using glmixed::GL_SRC_COLOR;
using glmixed::GL_STACK_OVERFLOW;
using glmixed::GL_STACK_UNDERFLOW;
using glmixed::GL_STENCIL;
using glmixed::GL_STENCIL_BITS;
using glmixed::GL_STENCIL_CLEAR_VALUE;
using glmixed::GL_STENCIL_FAIL;
using glmixed::GL_STENCIL_FUNC;
using glmixed::GL_STENCIL_INDEX;
using glmixed::GL_STENCIL_PASS_DEPTH_FAIL;
using glmixed::GL_STENCIL_PASS_DEPTH_PASS;
using glmixed::GL_STENCIL_REF;
using glmixed::GL_STENCIL_TEST;
using glmixed::GL_STENCIL_VALUE_MASK;
using glmixed::GL_STENCIL_WRITEMASK;
using glmixed::GL_STEREO;
using glmixed::GL_SUBPIXEL_BITS;
using glmixed::GL_T;
using glmixed::GL_T2F_C3F_V3F;
using glmixed::GL_T2F_C4F_N3F_V3F;
using glmixed::GL_T2F_C4UB_V3F;
using glmixed::GL_T2F_N3F_V3F;
using glmixed::GL_T2F_V3F;
using glmixed::GL_T4F_C4F_N3F_V4F;
using glmixed::GL_T4F_V4F;
using glmixed::GL_TEXTURE;
using glmixed::GL_TEXTURE_1D;
using glmixed::GL_TEXTURE_2D;
using glmixed::GL_TEXTURE_ALPHA_SIZE;
using glmixed::GL_TEXTURE_BINDING_1D;
using glmixed::GL_TEXTURE_BINDING_2D;
using glmixed::GL_TEXTURE_BLUE_SIZE;
using glmixed::GL_TEXTURE_BORDER;
using glmixed::GL_TEXTURE_BORDER_COLOR;
using glmixed::GL_TEXTURE_COMPONENTS;
using glmixed::GL_TEXTURE_COORD_ARRAY;
using glmixed::GL_TEXTURE_COORD_ARRAY_POINTER;
using glmixed::GL_TEXTURE_COORD_ARRAY_SIZE;
using glmixed::GL_TEXTURE_COORD_ARRAY_STRIDE;
using glmixed::GL_TEXTURE_COORD_ARRAY_TYPE;
using glmixed::GL_TEXTURE_ENV;
using glmixed::GL_TEXTURE_ENV_COLOR;
using glmixed::GL_TEXTURE_ENV_MODE;
using glmixed::GL_TEXTURE_GEN_MODE;
using glmixed::GL_TEXTURE_GEN_Q;
using glmixed::GL_TEXTURE_GEN_R;
using glmixed::GL_TEXTURE_GEN_S;
using glmixed::GL_TEXTURE_GEN_T;
using glmixed::GL_TEXTURE_GREEN_SIZE;
using glmixed::GL_TEXTURE_HEIGHT;
using glmixed::GL_TEXTURE_INTENSITY_SIZE;
using glmixed::GL_TEXTURE_INTERNAL_FORMAT;
using glmixed::GL_TEXTURE_LUMINANCE_SIZE;
using glmixed::GL_TEXTURE_MAG_FILTER;
using glmixed::GL_TEXTURE_MATRIX;
using glmixed::GL_TEXTURE_MIN_FILTER;
using glmixed::GL_TEXTURE_PRIORITY;
using glmixed::GL_TEXTURE_RED_SIZE;
using glmixed::GL_TEXTURE_RESIDENT;
using glmixed::GL_TEXTURE_STACK_DEPTH;
using glmixed::GL_TEXTURE_WIDTH;
using glmixed::GL_TEXTURE_WRAP_S;
using glmixed::GL_TEXTURE_WRAP_T;
using glmixed::GL_TRIANGLE_FAN;
using glmixed::GL_TRIANGLE_STRIP;
using glmixed::GL_TRIANGLES;
using glmixed::GL_UNPACK_ALIGNMENT;
using glmixed::GL_UNPACK_LSB_FIRST;
using glmixed::GL_UNPACK_ROW_LENGTH;
using glmixed::GL_UNPACK_SKIP_PIXELS;
using glmixed::GL_UNPACK_SKIP_ROWS;
using glmixed::GL_UNPACK_SWAP_BYTES;
using glmixed::GL_UNSIGNED_BYTE;
using glmixed::GL_UNSIGNED_INT;
using glmixed::GL_UNSIGNED_SHORT;
using glmixed::GL_V2F;
using glmixed::GL_V3F;
using glmixed::GL_VENDOR;
using glmixed::GL_VERSION;
using glmixed::GL_VERTEX_ARRAY;
using glmixed::GL_VERTEX_ARRAY_POINTER;
using glmixed::GL_VERTEX_ARRAY_SIZE;
using glmixed::GL_VERTEX_ARRAY_STRIDE;
using glmixed::GL_VERTEX_ARRAY_TYPE;
using glmixed::GL_VIEWPORT;
using glmixed::GL_XOR;
using glmixed::GL_ZERO;
using glmixed::GL_ZOOM_X;
using glmixed::GL_ZOOM_Y;


} // namespace gl11