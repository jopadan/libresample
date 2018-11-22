/**********************************************************************

  resample.h

  Real-time library interface by Dominic Mazzoni

  Based on resample-1.7:
    http://www-ccrma.stanford.edu/~jos/resample/

  Dual-licensed as LGPL and BSD; see README.md and LICENSE* files.

**********************************************************************/

#ifndef LIBRESAMPLE_INCLUDED
#define LIBRESAMPLE_INCLUDED


//Set up export of functions for a dll. If you are using
//the dll version of this library in your code then you
//must define USING_LIBRESAMPLE_DYNAMIC in order to import
//the functions
#ifdef LIBRESAMPLE_EXPORTS
	#define LIBRESAMPLE_API __declspec(dllexport)
#else
	#ifdef USING_LIBRESAMPLE_DYNAMIC
		#define LIBRESAMPLE_API __declspec(dllimport)
	#else
		#define LIBRESAMPLE_API 
	#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

LIBRESAMPLE_API void *resample_open(int      highQuality,
                    double   minFactor,
                    double   maxFactor);

LIBRESAMPLE_API void *resample_opend(int      highQuality,
                    double   minFactor,
                    double   maxFactor);

LIBRESAMPLE_API void *resample_dup(const void *handle);

LIBRESAMPLE_API void *resample_dupd(const void *handle);

LIBRESAMPLE_API int resample_get_filter_width(const void *handle);

LIBRESAMPLE_API int resample_get_filter_widthd(const void *handle);

LIBRESAMPLE_API int resample_process(void   *handle,
                     float  factor,
                     const float  *inBuffer,
                     int     inBufferLen,
                     int     lastFlag,
                     int    *inBufferUsed,
                     float  *outBuffer,
                     int     outBufferLen);

LIBRESAMPLE_API int resample_processd(void   *handle,
                     double  factor,
                     const double  *inBuffer,
                     int     inBufferLen,
                     int     lastFlag,
                     int    *inBufferUsed,
                     double  *outBuffer,
                     int     outBufferLen);

LIBRESAMPLE_API void resample_close(void *handle);

LIBRESAMPLE_API void resample_closed(void *handle);

#ifdef __cplusplus
}		/* extern "C" */
#endif	/* __cplusplus */

#endif /* LIBRESAMPLE_INCLUDED */
