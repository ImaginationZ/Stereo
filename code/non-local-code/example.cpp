#include "qx_basic.h"
#include "qx_ppm.h"
#include "qx_nonlocal_cost_aggregation.h"
#define QX_DEF_SIGMA							0.1//0.1

void stereo(char*filename_disparity_map,char*filename_left_image,char*filename_right_image,int max_disparity,bool use_post_processing)
{
	double sigma=QX_DEF_SIGMA;
	unsigned char***left,***right,**disparity; 
	int h,w;

	qx_image_size(filename_left_image,h,w);//obtain image size

	left=qx_allocu_3(h,w,3);//allocate memory
	right=qx_allocu_3(h,w,3);
	disparity=qx_allocu(h,w);

	qx_nonlocal_cost_aggregation m_nlca;//non-local cost aggregation class
	m_nlca.init(h,w,max_disparity,sigma);//initialization

	qx_loadimage(filename_left_image,left[0][0],h,w);//load left image
	qx_loadimage(filename_right_image,right[0][0],h,w);//load right image

	qx_timer timer;//
	timer.start();

	m_nlca.matching_cost(left,right);//compute matching cost
	timer.time_display("Matching cost computation");
	
	timer.start();
	m_nlca.disparity(disparity,use_post_processing);//compute disparity
	if(use_post_processing) timer.time_display("Non-local cost aggregation (including non-local post processing)");
	else timer.time_display("Non-local cost aggregation (excluding non-local post processing)");

	for(int y=0;y<h;y++) for(int x=0;x<w;x++) disparity[y][x]*=256/max_disparity;//rescale the disparity map for visualization
	qx_saveimage(filename_disparity_map,disparity[0],h,w,1);//write the obtained disparity map to the harddrive


	qx_freeu_3(left); left=NULL;//free memory
	qx_freeu_3(right); right=NULL;
	qx_freeu(disparity); disparity=NULL;
}
int main(int argc,char*argv[])
{
	if(argc!=5)
	{
		printf("Usage:\n");
		printf("*.exe: filename_disparity_map filename_left_image filename_right_image max_disparity\n");
		return(-1);
	}
	char*filename_disparity_map=argv[1];
	char*filename_left_image=argv[2];
	char*filename_right_image=argv[3];
	int max_disparity=atoi(argv[4]);

	stereo(filename_disparity_map,filename_left_image,filename_right_image,max_disparity,false);//excluding non-local post processing
	// stereo(filename_disparity_map,filename_left_image,filename_right_image,max_disparity,true);//including non-local post processing
	return(0);
}
