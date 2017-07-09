#ifndef YUV_LIB_CONFIG_H
#define YUV_LIB_CONFIG_H

#if defined(_MSC_VER)
#define YUVLIB_API __fastcall
#define YUVLIB_INLINE __forceinline
#if defined(YUV_LIB_DYNAMIC)
#if defined(_USRDLL)
#define YUVLIB_EXPORT __declspec(dllexport)
#else
#define YUVLIB_EXPORT __declspec(dllimport)
#endif
#else
#define YUVLIB_EXPORT
#endif
#elif defined(__GNUC__)
#define YUVLIB_API
#define YUVLIB_INLINE
#define YUVLIB_EXPORT
#else
#define YUVLIB_API
#define YUVLIB_INLINE
#define YUVLIB_EXPORT
#endif

#endif