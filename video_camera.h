#ifndef _VIDEO_CAMERA_H_
#define _VIDEO_CAMERA_H_


#include "header.h"

class Camera
{
public:
	Camera(int index = 0);
	~Camera();
	IplImage* read_from_camera();

	bool suc_flag;  /**< If open camera fail suc_flag=false*/

protected:
private:
	 CvCapture* c_capture;  /**< Used for function cvQueryFrame */
	 IplImage* c_capimg;		/**< Original image captured from video */
};

class Video
{
public:
	Video(std::string filename);
	~Video();
	IplImage* read_from_video(int frame_no);

	bool suc_flag;  /**< If open video fail suc_flag=false*/
	int frame_count; /**< The frame count of the open video*/

private:
    CvCapture* v_capture ;		/**< Used for function cvQueryFrame */
	IplImage* v_capimg ;		/**< Original image captured from video */
	IplImage *v_image ;		/**< Flipped Image captured from video (when nessary) */
};

#endif