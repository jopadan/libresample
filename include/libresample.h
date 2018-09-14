/**********************************************************************

  resample.h

  Real-time library interface by Dominic Mazzoni

  Based on resample-1.7:
    http://www-ccrma.stanford.edu/~jos/resample/

  Dual-licensed as LGPL and BSD; see README.md and LICENSE* files.

**********************************************************************/

#ifndef LIBRESAMPLE_INCLUDED
#define LIBRESAMPLE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

void *resample_open(int      highQuality,
                    double   minFactor,
                    double   maxFactor);

void *resample_opend(int      highQuality,
                    double   minFactor,
                    double   maxFactor);

void *resample_dup(const void *handle);

void *resample_dupd(const void *handle);

int resample_get_filter_width(const void *handle);

int resample_get_filter_widthd(const void *handle);

int resample_process(void   *handle,
                     float  factor,
                     const float  *inBuffer,
                     int     inBufferLen,
                     int     lastFlag,
                     int    *inBufferUsed,
                     float  *outBuffer,
                     int     outBufferLen);

int resample_processd(void   *handle,
                     double  factor,
                     const double  *inBuffer,
                     int     inBufferLen,
                     int     lastFlag,
                     int    *inBufferUsed,
                     double  *outBuffer,
                     int     outBufferLen);

void resample_close(void *handle);

void resample_closed(void *handle);

#ifdef __cplusplus
}		/* extern "C" */
#endif	/* __cplusplus */

#endif /* LIBRESAMPLE_INCLUDED */
