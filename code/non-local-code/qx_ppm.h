/*****************************************************************
\Author:	Qingxiong Yang
\Function:	Read/Write images (constrained to ppm and pgm files).
******************************************************************/
#ifndef QX_PPM_H
#define QX_PPM_H
#include "qx_basic.h"
#define QX_DEF_IS_PPM 1
#define QX_DEF_IS_PGM 0
/*basic function*/
/*get the size of the target image, and the properties of the image, and use the following 
4 functions to read the image data*/
unsigned char* loadimage(char* file_name, int &h, int &w, bool &is_ppm);
int loadimage(unsigned char* out,char* file_name, int h, int w);
int loadimage(float* out,unsigned char *out_u,char* file_name, int h, int w);
void get_ascii_pgm(unsigned char *image,FILE* file_in,int h,int w);
void get_ascii_ppm(unsigned char *image,FILE* file_in,int h,int w);
unsigned char* get_binary_ppm(FILE* file_in,int h,int w);/*If the image is a ppm image in binary mode*/
unsigned char* get_binary_pgm(FILE* file_in,int h,int w);/*If the image is a pgm image in binary mode*/
unsigned char* get_ascii_ppm(FILE* file_in,int h,int w);/*If the image is a ppm image in ascii mode*/
unsigned char* get_ascii_pgm(FILE* file_in,int h,int w);/*If the image is a pgm image in ascii mode*/
/*both saveimage_ppm and save_image_pgm use the following Four functions to save an image*/
void saveimage_ppm(char *file_name,unsigned char *image,int h,int w,bool is_binary=true);
void saveimage_pgm(char *file_name,unsigned char *image,int h,int w,bool is_binary=true);
void write_binary_ppm(char* file_name,unsigned char* image,int h,int w);/*If the image is a ppm image in binary mode*/
void write_binary_pgm(char* file_name,unsigned char* image,int h,int w);/*If the image is a pgm image in binary mode*/
void write_ascii_ppm(char* file_name,unsigned char *image,int h,int w);/*If the image is a ppm image in ascii mode*/
void write_ascii_pgm(char* file_name,unsigned char *image,int h,int w);/*If the image is a pgm image in ascii mode*/

/*extended function*/
/*To get the size of the image*/
void qx_image_size(char* file_name, int &h, int &w,int *nr_channel=NULL);
/*load image (with height h and width w) as a float matrix 
(if image is color image, do color to gray conversion)*/
float** loadimage_pgm(char *file_name,int &h,int &w);
/*load ppm image (with height h and width w) as a float cubic (size: h x w x 3)*/
float*** loadimage_ppm(char *file_name,int &h,int &w);
/*load ppm image (with height h and width w) as a unsigned char cubic (size: h x w x 3)*/
unsigned char*** loadimage_ppm_u(char *file_name,int &h,int &w);
/*load pgm image as a float matrix, and save the height as h, and width as w*/
int** loadimage_pgm_i(char *file_name,int &h,int &w);
/*load image (with height h and width w) as a unsigned matrix 
(if image is color image, do color to gray conversion)*/
unsigned char** loadimage_pgm_u(char *file_name,int &h,int &w);
/*The following Four functions are used to save an image of different data types*/
void saveimage_pgm(char *file_name,float **image,int h,int w,int scale=1);
void saveimage_pgm(char *file_name,unsigned char **image,int h,int w,int scale=1);
void saveimage_pgm_ascii(char *file_name,float **image,int h,int w,int scale=1);
void saveimage_pgm_ascii(char *file_name,int **image,int h,int w,int scale=1);
void saveimage_pgm(char *file_name,int **image,int h,int w,int scale=1);
void saveimage_ppm(char *file_name,float ***image,int h,int w,int scale=1);
void saveimage_ppm(char *file_name,double ***image,int h,int w,int scale=1);
void saveimage_ppm(char *file_name,unsigned char ***image,int h,int w,int scale=1);


/*load image*/
int qx_loadimage(char*file_name,unsigned char*image,int h,int w,int *nr_channel=NULL);
int qx_loadimage(char*file_name,short*image,int h,int w,int *nr_channel=NULL);
int qx_loadimage(char*file_name,float*image,int h,int w,int *nr_channel=NULL);
/*save image*/
void qx_saveimage(char*file_name,float*image,int h,int w,int channel);
void qx_saveimage(char*file_name,double*image_d,int h,int w,int channel);
void qx_saveimage(char*file_name,short*image,int h,int w,int channel);
void qx_saveimage(char*file_name,unsigned char*image,int h,int w,int channel);
float *loadimage(char* file_name,int &h,int &w,int *is_ppm=NULL);
int loadimage(char* file_name,float *image,int &h,int &w,int *nr_channel=NULL);
float *get_binary(FILE* file_in,int h,int w,int channel);
void saveimage(char* file_name,float *image,int h,int w,int channel=1);
void saveimage(char* file_name,double *image_d,int h,int w,int channel);
float ***loadimage_ftif(char *file_name,int &h,int &w,int &nr_channel);
#endif/*PPM_H*/