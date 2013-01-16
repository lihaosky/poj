/****************************************************************************
 * File        : improc.cpp
 * Author      : Hayden So, April Chow, Giuseppe Mak
 * Date        : 22/11/2008
 * Description :
 *   This file contains the main program for the ENGG1002 Project -
 * EEE - Image Processing.
 *****************************************************************************/
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <string.h>
#include <iostream>

using namespace std;

/* This specify the target image mode so that save_img knows how to 
 * translate the pixel values into a underlying GTK+ image.
 */
enum colorMode {GREYSCALE, RGB};

struct image {
	colorMode mode;       // color mode.
	int height;           // image height
	int width;            // image width
	struct pixel** pix;   // A 2D arrays of struct pixel as defined below
};

struct pixel {
	int red;
	int green;
	int blue;
	int intensity;
};

/*****************************************************************************
 * Global Variables
 *****************************************************************************/

/* contains all the widgets in this app */
struct myWidgets {
    
    // Window, alignment boxes and accelerator group
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *hbox;
    GtkWidget *statusHbox;
    GtkAccelGroup *accelGroup;

    // Menubar and menu items
    GtkWidget *menubar;
    GtkWidget *shellFile;
    GtkWidget *itemFile;
    GtkWidget *itemOpen;
    GtkWidget *itemSave;
    GtkWidget *itemQuit;
    GtkWidget *itemSep;
    
    // Toolbar and icons
    GtkWidget *toolbar;
    GtkToolItem *iconOpen;
    GtkToolItem *iconSave;
    GtkToolItem *iconQuit;
    GtkToolItem *iconSep;

    // Combo box for choosing image filters
    GtkWidget *combo;
    
    // Update button
    GtkWidget *button;

    // Scrolled window
    GtkWidget *scrolledWindow;
    
    // Event box
    GtkWidget *eventBox;
    
    // Image widget and pixel buffer
    GtkWidget *imgWidget;
    GdkPixbuf *pixbuf;
    
    // Statusbar
    GtkWidget *statusbarLeft;
    GtkWidget *statusbarRight;
    
    // Self-defined 2D image structures
    struct image *baseImg;
    struct image *currentImg;
    // Previous filter being chosen
    gchar *prev;
    
};


/*****************************************************************************
 * Helper Functions
 *  _   _      _                   _____                 _   _                 
 * | | | | ___| |_ __   ___ _ __  |  ___|   _ _ __   ___| |_(_) ___  _ __  ___ 
 * | |_| |/ _ \ | '_ \ / _ \ '__| | |_ | | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 * |  _  |  __/ | |_) |  __/ |    |  _|| |_| | | | | (__| |_| | (_) | | | \__ \
 * |_| |_|\___|_| .__/ \___|_|    |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
 *              |_|                                                            
 *****************************************************************************/

/* Allocate memory for storing 2D matric of pixels 
 * Return 0 on success */
int alloc_pixmem(struct image* img)
{
    // Allocate memory for each pixel
    img->pix = (struct pixel**) g_malloc(sizeof(struct pixel*) * img->height);
    if (!img->pix) {
	    return 1;
    }
    for (int i = 0; i < img->height; i++) {
        img->pix[i] = (struct pixel*) g_malloc(sizeof(struct pixel) * img->width);
	if (!img->pix[i]) {
		return 1;
	}
    }
    return 0;
}

/* Free the memory allocated for storing the pixels of img
 */
void free_pixmem(struct image *img)
{
    // Clear the old image (if present)
    if (img->pix) {
        for (int i = 0; i < img->height; i++)
            g_free(img->pix[i]);
        g_free(img->pix);
    }
}

int init_image(struct image* img, GdkPixbuf *pixbuf)
{
    // Get the basic information about an image
    int rowstride = gdk_pixbuf_get_rowstride(pixbuf);
    int numChannels = gdk_pixbuf_get_n_channels(pixbuf);
    img->height = gdk_pixbuf_get_height(pixbuf);
    img->width = gdk_pixbuf_get_width(pixbuf);
    img->mode = RGB;
    
    // Allocate memory for each pixel
    if (alloc_pixmem(img)) {
	    cerr << "Error allocating memory for img" << endl;
	    return 1;
    }
    
    // Initialize the 2D image array
    guchar *pixels = gdk_pixbuf_get_pixels(pixbuf);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            guchar *p = pixels + i * rowstride + j * numChannels;
            img->pix[i][j].red = p[0];
            img->pix[i][j].green = p[1];
            img->pix[i][j].blue = p[2];
            img->pix[i][j].intensity = (p[0] + p[1] + p[2]) / 3;
        }
    }
    
    return 0;
}

/*this function will initialize a image with pixbuf's width as height, height as width
*it's for rotation*/
int init1_image(struct image* img, GdkPixbuf *pixbuf)
{
    // Get the basic information about an image
    int rowstride = gdk_pixbuf_get_rowstride(pixbuf);
    int numChannels = gdk_pixbuf_get_n_channels(pixbuf);
    img->height = gdk_pixbuf_get_width(pixbuf);
    img->width = gdk_pixbuf_get_height(pixbuf);
    img->mode = RGB;
    
    // Allocate memory for each pixel
    if (alloc_pixmem(img)) {
	    cerr << "Error allocating memory for img" << endl;
	    return 1;
    }
    
    // Initialize the 2D image array
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
                 img->pix[i][j].red=0;
                 img->pix[i][j].green=0;
                 img->pix[i][j].blue=0;
                 img->pix[i][j].intensity=0;
                 }
    }
    
    return 0;
}

/*this function will initialize a image with double size of pixbuf's
*it's for zoom out*/
int init2_image(struct image* img, GdkPixbuf *pixbuf)
{
    // Get the basic information about an image
    int rowstride = gdk_pixbuf_get_rowstride(pixbuf);
    int numChannels = gdk_pixbuf_get_n_channels(pixbuf);
    img->height = gdk_pixbuf_get_height(pixbuf)*2;
    img->width = gdk_pixbuf_get_width(pixbuf)*2;
    img->mode = RGB;
    
    // Allocate memory for each pixel
    if (alloc_pixmem(img)) {
	    cerr << "Error allocating memory for img" << endl;
	    return 1;
    }
    
    // Initialize the 2D image array
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pix[i][j].red = 0;
            img->pix[i][j].green = 0;
            img->pix[i][j].blue = 0;
            img->pix[i][j].intensity =0;
        }
    }
    
    return 0;
}

/*this function will initialize a image of half size of pixbuf's
*it's for zoom in*/
int init3_image(struct image* img, GdkPixbuf *pixbuf)
{
    // Get the basic information about an image
    int rowstride = gdk_pixbuf_get_rowstride(pixbuf);
    int numChannels = gdk_pixbuf_get_n_channels(pixbuf);
    img->height = gdk_pixbuf_get_height(pixbuf)/2;
    img->width = gdk_pixbuf_get_width(pixbuf)/2;
    img->mode = RGB;
    
    // Allocate memory for each pixel
    if (alloc_pixmem(img)) {
	    cerr << "Error allocating memory for img" << endl;
	    return 1;
    }
    
    // Initialize the 2D image array
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pix[i][j].red = 0;
            img->pix[i][j].green = 0;
            img->pix[i][j].blue = 0;
            img->pix[i][j].intensity =0;
        }
    }
    
    return 0;
}

GdkPixbuf *init_pixbuf(struct image *img)
{
    GdkPixbuf *pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, img->width, img->height);
    int rowstride = gdk_pixbuf_get_rowstride(pixbuf);
    int numChannels = gdk_pixbuf_get_n_channels(pixbuf);
    guchar *pixels = gdk_pixbuf_get_pixels(pixbuf);
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            guchar *p = pixels + i * rowstride + j * numChannels;
            if (img->mode == GREYSCALE) {
                p[0] = img->pix[i][j].intensity;
                p[1] = img->pix[i][j].intensity;
                p[2] = img->pix[i][j].intensity;
            }
            else {
                p[0] = img->pix[i][j].red;
                p[1] = img->pix[i][j].green;
                p[2] = img->pix[i][j].blue;
            }
        }
    }
    
    return pixbuf;
}


/* Draw te pixbuf stored in mw->pixbuf to screen using the widget mw->imgWidget */
void show_image(myWidgets *mw)
{
    //  Load the new image into the scrolled window  
    gtk_image_set_from_pixbuf(GTK_IMAGE(mw->imgWidget), mw->pixbuf);
    gtk_widget_show(mw->imgWidget);
}    
 
/*********************************************************************************
 * Image Filters
 *  ___                              _____ _ _ _   _                
 * |_ _|_ __ ___   __ _  __ _  ___  |  ___(_) | |_| |_ ___ _ __ ___ 
 *  | || '_ ` _ \ / _` |/ _` |/ _ \ | |_  | | | __| __/ _ \ '__/ __|
 *  | || | | | | | (_| | (_| |  __/ |  _| | | | |_| |_  __/ |  \__ \
 * |___|_| |_| |_|\__,_|\__, |\___| |_|   |_|_|\__|\__\___|_|  |___/
 *                      |___/                                       
 *********************************************************************************/

/* Convert the image in simg into greyscale and store the resultin dimg.  The color
 * mode of dimg is changed from RGB to GREYSCALE as a result.
 * Returns 0 on success, 1 on error.
 */
int GreyscaleConvert(struct image* dimg, struct image* simg)
{
	if(!simg||!dimg){return 1;}
	//compute the average of color components in simg and store in dimg: for grey convertion
	 for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    int color=(simg->pix[i][j].red+simg->pix[i][j].green+simg->pix[i][j].blue)/3;
                    dimg->pix[i][j].red=color;
                    dimg->pix[i][j].green=color;
                    dimg->pix[i][j].blue=color;
                    dimg->pix[i][j].intensity=color;
                    }
    }
	return 0;
}




//get smaller value of two integers
int min(int a,int b)
 {
    return a>b?b:a;
 }
 
//get larger value of two integers
int max(int a,int b)
 {
       return a>b?a:b;
 }
 
 
/* Perform blurring filter on the image in simg.  The result is stored in dimg
 * Return 0 on succes, 1 on error.
 */
int BlurImage(struct image* dimg, struct image* simg)
{
	if(!simg||!dimg){return 1;}
	
	//blur filter: 5 by 5 mitrix
	int filter[5][5]={0,0,1,0,0,
                 0,1,1,1,0,
                 1,1,1,1,1,
                 0,1,1,1,0,
                 0,0,1,0,0};
                 
    //sum_red sum_green sum_blue store temporary value of convolution
    int sum_red,sum_green,sum_blue;
    
    
    //compute convolution of filter and color component store in dimg, treat overflow ones as 1: for blurring
	for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    sum_red=0;
                    sum_blue=0;
                    sum_green=0;
                    for(int m=0;m<5;m++){
                            for(int n=0;n<5;n++){
                                    // out-bound
                                    if(((m+i-2)<0)||((n+j-2)<0)||((m+i-2)>=simg->height)||((n+j-2)>=simg->width)){
                                                     sum_red+=filter[m][n];
                                                     sum_green+=filter[m][n];
                                                     sum_blue+=filter[m][n];
                                                     continue;}
                                    sum_red+=simg->pix[m+i-2][n+j-2].red*filter[m][n];
                                    sum_green+=simg->pix[m+i-2][n+j-2].green*filter[m][n];
                                    sum_blue+=simg->pix[m+i-2][n+j-2].blue*filter[m][n];
                                    }
                    }
                    dimg->pix[i][j].red=min(sum_red/13,255);
                    dimg->pix[i][j].green=min(sum_green/13,255);
                    dimg->pix[i][j].blue=min(sum_blue/13,255);
                    }
    }
	return 0;
}


/* Perform motion_blurring filter on the image in simg.  The result is stored in dimg
 * Return 0 on succes, 1 on error.
 */
int motion_blur(image* dimg,image* simg)
{
    if(!simg||!dimg){return 1;}
    //motion blur filter: 9 by 9 matrix
    int filter[9][9] ={
    1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1,
    };
    
    
    //sum_red sum_green sum_blue strore temporary value of convolution
    int sum_red,sum_green,sum_blue;
    
    //compute convolution of filter and color component store in dimg, treat overflow ones as 1: for motion blurring
    for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    sum_red=0;
                    sum_blue=0;
                    sum_green=0;
                    for(int m=0;m<9;m++){
                            for(int n=0;n<9;n++){
                                    // out-bound
                                    if(((m+i-4)<0)||((n+j-4)<0)||((m+i-4)>=simg->height)||((n+j-4)>=simg->width)){
                                                     sum_red+=filter[m][n];
                                                     sum_green+=filter[m][n];
                                                     sum_blue+=filter[m][n];
                                                     continue;}
                                    sum_red+=simg->pix[m+i-4][n+j-4].red*filter[m][n];
                                    sum_green+=simg->pix[m+i-4][n+j-4].green*filter[m][n];
                                    sum_blue+=simg->pix[m+i-4][n+j-4].blue*filter[m][n];
                                    }
                    }
                    dimg->pix[i][j].red=min(sum_red/9,255);
                    dimg->pix[i][j].green=min(sum_green/9,255);
                    dimg->pix[i][j].blue=min(sum_blue/9,255);
                    }
    }
    return 0;
}


/* Perform sharpen filter on the image in simg.  The result is stored in dimg
 * Return 0 on succes, 1 on error.
 */
int sharpen(image* dimg,image* simg)
{
    if(!simg||!dimg){return 1;}
    //sharpen filter: 5 by 5 matrix
    int filter[5][5] ={
    -1, -1, -1, -1, -1,
    -1,  2,  2,  2, -1,
    -1,  2,  8,  2, -1,
    -1,  2,  2,  2, -1,
    -1, -1, -1, -1, -1,
    };
    
    //sum_red sum_green sum_blue strore temporary value of convolution
    int sum_red,sum_green,sum_blue;
    
    //compute convolution of filter and color component store in dimg, treat overflow ones as 1:for sharpen
    for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    sum_red=0;
                    sum_blue=0;
                    sum_green=0;
                    for(int m=0;m<5;m++){
                            for(int n=0;n<5;n++){
                                    // out-bound
                                    if(((m+i-2)<0)||((n+j-2)<0)||((m+i-2)>=simg->height)||((n+j-2)>=simg->width)){
                                                     sum_red+=filter[m][n];
                                                     sum_green+=filter[m][n];
                                                     sum_blue+=filter[m][n];
                                                     continue;}
                                    sum_red+=simg->pix[m+i-2][n+j-2].red*filter[m][n];
                                    sum_green+=simg->pix[m+i-2][n+j-2].green*filter[m][n];
                                    sum_blue+=simg->pix[m+i-2][n+j-2].blue*filter[m][n];
                                    }
                    }
                    dimg->pix[i][j].red=min(max(sum_red/8,0),255);
                    dimg->pix[i][j].green=min(max(sum_green/8,0),255);
                    dimg->pix[i][j].blue=min(max(sum_blue/8,0),255);
                    }
    }
    return 0;
}


/* Perform sharpen filter on the image in simg.  The result is stored in dimg
 * Return 0 on succes, 1 on error.
 */
int emboss(image* dimg,image* simg)
{
    if(!simg||!dimg){return 1;}
    
    
    //emboss filter: 5 by 5 matrix
    int filter[5][5] ={
    -1, -1, -1, -1,  0,
    -1, -1, -1,  0,  1,
    -1, -1,  0,  1,  1,
    -1,  0,  1,  1,  1,
     0,  1,  1,  1,  1
     };
     
     //sum_red sum_green sum_blue strore temporary value of convolution
    int sum_red,sum_green,sum_blue;
    
    //compute convolution of filter and color component store in dimg, treat overflow ones as 1:for emboss
    for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    sum_red=0;
                    sum_blue=0;
                    sum_green=0;
                    for(int m=0;m<5;m++){
                            for(int n=0;n<5;n++){
                                    // out-bound
                                    if(((m+i-2)<0)||((n+j-2)<0)||((m+i-2)>=simg->height)||((n+j-2)>=simg->width)){
                                                     sum_red+=filter[m][n];
                                                     sum_green+=filter[m][n];
                                                     sum_blue+=filter[m][n];
                                                     continue;}
                                    sum_red+=simg->pix[m+i-2][n+j-2].red*filter[m][n];
                                    sum_green+=simg->pix[m+i-2][n+j-2].green*filter[m][n];
                                    sum_blue+=simg->pix[m+i-2][n+j-2].blue*filter[m][n];
                                    }
                    }
                    dimg->pix[i][j].red=min(max(sum_red+128,0),255);
                    dimg->pix[i][j].green=min(max(sum_green+128,0),255);
                    dimg->pix[i][j].blue=min(max(sum_blue+128,0),255);
                    }
    }
    return 0;
}

/* Perform Sobel edge detection on the image in simg.  The result is 
 * stored in dimg.
 * Return 0 on succes, 1 on error.
 */  
int EdgeDetect(struct image* dimg, struct image* simg)
{
	if(!simg||!dimg){return 1;}
	
	//convert the image to greyscale at first
	GreyscaleConvert(dimg,simg);
	
	//create a temporay object to store the value of color components of greyscale dimg
	image* temp;
    temp = (struct image *) g_malloc(sizeof(struct image));
    temp->height=simg->height;
    temp->width=simg->width;
    temp->mode=RGB;
   	int ret = alloc_pixmem(temp);
	if (ret) {
		cerr << "Error allocating memory for output image"<< endl;
		exit(1);
	}
    for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    temp->pix[i][j].red=dimg->pix[i][j].red;
                    temp->pix[i][j].green=dimg->pix[i][j].green;
                    temp->pix[i][j].blue=dimg->pix[i][j].blue;
                    }
    }
    
    //east west direction filter
	int Hew[3][3]={-1,0,1,
                   -2,0,2,
                   -1,0,1
                   };
    
    //north south direction filter
	int Hns[3][3]={1,2,1,
                   0,0,0,
                   -1,-2,-1
                   };
                   
    //sum_red1 green1 blue1 store the temporary sum of east west direction
    //sum_red2 green2 blue2 store the temporary sum of north south direction
	int sum_red1,sum_red2,sum_green1,sum_green2,sum_blue1,sum_blue2;
	
	//compute convolution of filter and color component store in dimg, treat overflow ones as 0: for edge detection
	for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    sum_red1=0;
                    sum_red2=0;
                    sum_blue1=0;
                    sum_blue2=0;
                    sum_green1=0;
                    sum_green2=0;
                    for(int m=0;m<3;m++){
                            for(int n=0;n<3;n++){
                                    // out-bound
                                    if(((m+i-1)<0)||((n+j-1)<0)||((m+i-1)==simg->height)||((n+j-1)==simg->width)){continue;}
                                    sum_red1+=temp->pix[m+i-1][n+j-1].red*Hew[m][n];
                                    sum_green1+=temp->pix[m+i-1][n+j-1].green*Hew[m][n];
                                    sum_blue1+=temp->pix[m+i-1][n+j-1].blue*Hew[m][n];
                                    sum_red2+=temp->pix[m+i-1][n+j-1].red*Hns[m][n];
                                    sum_green2+=temp->pix[m+i-1][n+j-1].green*Hns[m][n];
                                    sum_blue2+=temp->pix[m+i-1][n+j-1].blue*Hns[m][n];
                                    }
                    }
                    dimg->pix[i][j].red=min(max((sum_red1+sum_red2),0),255);
                    dimg->pix[i][j].green=min(max((sum_green1+sum_green2),0),255);
                    dimg->pix[i][j].blue=min(max((sum_blue1+sum_blue2),0),255);
                    }
    }
    free_pixmem(temp);
    delete temp;
	return 0;
}
    
/* perform upside down of simg store result in dimg
 * Return 0 on succes, 1 on error.
 */  
int upside_down(image* dimg,image* simg)
{
    if(!simg||!dimg){return 1;}
    for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    dimg->pix[simg->height-1-i][j].red=simg->pix[i][j].red;
                    dimg->pix[simg->height-1-i][j].green=simg->pix[i][j].green;
                    dimg->pix[simg->height-1-i][j].blue=simg->pix[i][j].blue;
                    }
    }
    return 0;
}

/* perform rotate_clockwise of simg and store result in dimg
 * Return 0 on succes, 1 on error.
 */  
int rotate_clockwise(image* dimg,image *simg)
{
    if(!simg||!dimg){return 1;}
    //rotate clockwise
    for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    dimg->pix[j][simg->height-1-i].red=simg->pix[i][j].red;
                    dimg->pix[j][simg->height-1-i].blue=simg->pix[i][j].blue;
                    dimg->pix[j][simg->height-1-i].green=simg->pix[i][j].green;
                    }
    }
    return 0;
}

/* perform rotate_counter_clockwise of simg store result in dimg
 * Return 0 on succes, 1 on error.
 */  
int rotate_counter_clockwise(image *dimg,image *simg)
{
    if(!simg||!dimg){return 1;}
    //rotate counter clockwise
    for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    dimg->pix[simg->width-1-j][i].red=simg->pix[i][j].red;
                    dimg->pix[simg->width-1-j][i].blue=simg->pix[i][j].blue;
                    dimg->pix[simg->width-1-j][i].green=simg->pix[i][j].green;
                      }
    }
    return 0;
}

/* perform zoom_out of simg store result in dimg
 * Return 0 on succes, 1 on error.
 */  
int zoom_out(image *dimg,image *simg)
{
    if(!simg||!dimg){return 1;}
    //zoom out: initial four pixels in dimg with one pixel in simg
    for(int i=0;i<simg->height;i++){
            for(int j=0;j<simg->width;j++){
                    //change pixels in new image
                    dimg->pix[2*i][2*j].red=simg->pix[i][j].red;
                    dimg->pix[2*i][2*j+1].red=simg->pix[i][j].red;
                    dimg->pix[2*i+1][2*j].red=simg->pix[i][j].red;
                    dimg->pix[2*i+1][2*j+1].red=simg->pix[i][j].red;
                    dimg->pix[2*i][2*j].blue=simg->pix[i][j].blue;
                    dimg->pix[2*i][2*j+1].blue=simg->pix[i][j].blue;
                    dimg->pix[2*i+1][2*j].blue=simg->pix[i][j].blue;
                    dimg->pix[2*i+1][2*j+1].blue=simg->pix[i][j].blue;
                    dimg->pix[2*i][2*j].green=simg->pix[i][j].green;
                    dimg->pix[2*i][2*j+1].green=simg->pix[i][j].green;
                    dimg->pix[2*i+1][2*j].green=simg->pix[i][j].green;
                    dimg->pix[2*i+1][2*j+1].green=simg->pix[i][j].green;
                    }
            }
    return 0;
}

/* perform zoom_in of simg store result in dimg
 * Return 0 on succes, 1 on error.
 */ 
int zoom_in(image *dimg,image *simg)
{
    if(!simg||!dimg){return 1;}
    //zoom in: only store one fourth pixels from simg to dimg
    for(int i=0;i<simg->height-1;i+=2){
            for(int j=0;j<simg->width-1;j+=2){
                    //change pixels in new image
                    dimg->pix[i/2][j/2].red=simg->pix[i][j].red;
                    dimg->pix[i/2][j/2].green=simg->pix[i][j].green;
                    dimg->pix[i/2][j/2].blue=simg->pix[i][j].blue;
                    }
        }
        return 0;
}
                    
/**************************************************************************************
 * Callback Functions 
 *   ____      _ _ _                _    
 *  / ___|__ _| | | |__   __ _  ___| | __
 * | |   / _` | | | '_ \ / _` |/ __| |/ /
 * | |___ (_| | | | |_) | (_| | (__|   < 
 *  \____\__,_|_|_|_.__/ \__,_|\___|_|\_\
 *
 *  _____                 _   _                 
 * |  ___|   _ _ __   ___| |_(_) ___  _ __  ___ 
 * | |_ | | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 * |  _|| |_| | | | | (__| |_| | (_) | | | \_  \
 * |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
 *                                              
 **************************************************************************************/

/* Create an Open File dialog box for user to select a file to open.
 * The opened file is stored in wm->baseImg and wm->currentImg */
void open_image(GtkWidget *widget, myWidgets *mw)
{
    GtkWidget *fileDialog = gtk_file_chooser_dialog_new("Open File",
                            GTK_WINDOW(mw->window),
                            GTK_FILE_CHOOSER_ACTION_OPEN,
    				        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
    				        GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
    				        NULL);
    GError *error = NULL;
    
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_add_pixbuf_formats(filter);
    gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(fileDialog), filter);
    
    if (gtk_dialog_run(GTK_DIALOG(fileDialog)) == GTK_RESPONSE_ACCEPT) {
        gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileDialog));
        
        // Load the image into the pixel buffer
        mw->pixbuf = gdk_pixbuf_new_from_file(filename, &error);
        
        if (error) {
            // Output an error dialog
            GtkWidget *errDialog;
            gchar *errMsg = g_strdup_printf("Unable to open the file: %s\n", filename);
            errDialog = gtk_message_dialog_new(
                            GTK_WINDOW(mw->window),
                            GTK_DIALOG_DESTROY_WITH_PARENT,
                            GTK_MESSAGE_ERROR,
                            GTK_BUTTONS_OK,
                            errMsg);
            gtk_window_set_title(GTK_WINDOW(errDialog), "Error");
            gtk_dialog_run(GTK_DIALOG(errDialog));
            gtk_widget_destroy(errDialog);
            g_error_free(error);
            g_free(errMsg);
        }
        else {
            // Free the memory 
            free_pixmem(mw->baseImg);
            free_pixmem(mw->currentImg);
            (void) init_image(mw->baseImg, mw->pixbuf);
	        (void) init_image(mw->currentImg, mw->pixbuf);
	    // Show image on screen
            show_image(mw);

            // Enable the related widgets
            gtk_widget_set_sensitive(mw->itemSave, TRUE);
            gtk_widget_set_sensitive(GTK_WIDGET(mw->iconSave), TRUE);
            gtk_widget_set_sensitive(mw->combo, TRUE);
            gtk_widget_set_sensitive(mw->button, TRUE);
            gtk_combo_box_set_active(GTK_COMBO_BOX(mw->combo), 0);
        }
        
        // Free the filename and pixel buffer
        g_free(filename);
        g_object_unref(mw->pixbuf);
    }
    
    gtk_widget_destroy(fileDialog);
}

/* Create a Save File dialog box for user to pick a file name to 
 * save the image contained in mw */
void save_image(GtkWidget *widget, myWidgets *mw)
{   
    GtkWidget *fileDialog = gtk_file_chooser_dialog_new("Save File",
                            GTK_WINDOW(mw->window),
                            GTK_FILE_CHOOSER_ACTION_SAVE,
                            GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                            GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
                            NULL);
    GError *error = NULL;
    
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_add_pixbuf_formats(filter);
    gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(fileDialog), filter);  
    
    if (gtk_dialog_run(GTK_DIALOG(fileDialog)) == GTK_RESPONSE_ACCEPT) {
        gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileDialog));
        
        // Load the image into the pixel buffer
        mw->pixbuf = init_pixbuf(mw->currentImg);
        
        // Save the pixel buffer
        gdk_pixbuf_save(mw->pixbuf, filename, "jpeg", &error, "quality", "100", NULL);
        
        if (error) {
            // Output an error dialog
            GtkWidget *errDialog;
            gchar *errMsg = g_strdup_printf("Unable to save the file: %s\n", filename);
            errDialog = gtk_message_dialog_new(
                            GTK_WINDOW(mw->window),
                            GTK_DIALOG_DESTROY_WITH_PARENT,
                            GTK_MESSAGE_ERROR,
                            GTK_BUTTONS_OK,
                            errMsg);
            gtk_window_set_title(GTK_WINDOW(errDialog), "Error");
            gtk_dialog_run(GTK_DIALOG(errDialog));
            gtk_widget_destroy(errDialog);
            g_error_free(error);
            g_free(errMsg);
        }
        
        // Free the filename and pixel buffer
        g_free(filename);
        g_object_unref(mw->pixbuf);
    }
    
    gtk_widget_destroy(fileDialog);
}

/* This function is called when the Update button is clicked
 * It should call the appropriate filter according to current value
 * of the filter selection box.  Store the processed image in mw->currentImg
 * If Original is selected, you should copy mw->baseImg as mw->currentImg.
 */
void button_clicked(GtkWidget *widget, myWidgets *mw)
{
    /* Get the current text stored in the filter selection combo box */
    gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(mw->combo));
    

    /*perform corresponding filter respect to the selected text*/
    
    //greyscale
    if(!strcmp(text,"Greyscale")){
           free_pixmem(mw->currentImg);                  //free currentImg pixels
           mw->pixbuf=init_pixbuf(mw->baseImg);          //get baseImg pixels
           init_image(mw->currentImg,mw->pixbuf);        //initialize mw->currentImg with baseImg
           GreyscaleConvert(mw->currentImg,mw->baseImg); //convert currentImg to greyscale 
           g_object_unref(mw->pixbuf);                   //free pixbuf
          }
          
          
    //blurring
    else if(!strcmp(text,"Blurring")){
           free_pixmem(mw->currentImg);             //free currentImg pixels
           mw->pixbuf=init_pixbuf(mw->baseImg);     //get baseImg pixels
           init_image(mw->currentImg,mw->pixbuf);   //initialize mw->currentImg with baseImg
           BlurImage(mw->currentImg,mw->baseImg);   //blur currentImg
           g_object_unref(mw->pixbuf);              //free pixbuf
          }
          
          
    //edge detection
    else if(!strcmp(text,"Edge detection")){
           free_pixmem(mw->currentImg);              //free currentImg pixels
           mw->pixbuf=init_pixbuf(mw->baseImg);      //get baseImg pixels
           init_image(mw->currentImg,mw->pixbuf);    //initialize mw->currentImg with baseImg
           EdgeDetect(mw->currentImg,mw->baseImg);   //edge dectection
           g_object_unref(mw->pixbuf);               //free pixbuf
         }
         
         
    //upside down
    else if(!strcmp(text,"upside_down")){
          image *temp=new image;                    //create temp to store currentImg pixels
          mw->pixbuf=init_pixbuf(mw->currentImg);   //get currentImg pixels
          init_image(temp,mw->pixbuf);              //initialize temp with pixbuf
          upside_down(mw->currentImg,temp);         //upside down currentImg
          g_object_unref(mw->pixbuf);               //free pixbuf
          free_pixmem(temp);                        //free temp pixels
          delete temp;                              //delete temp
         }
         
         
     //motion blurring    
    else if(!strcmp(text,"motion_blur")){
         free_pixmem(mw->currentImg);               //free currentImg pixels
         mw->pixbuf=init_pixbuf(mw->baseImg);       //get baseImg pixels
         init_image(mw->currentImg,mw->pixbuf);     //initialize currentImg with baseImg
         motion_blur(mw->currentImg,mw->baseImg);   //motion blur currentImg
         g_object_unref(mw->pixbuf);                //free pixbuf
         }
         
         
    //sharpen     
    else if(!strcmp(text,"sharpen")){
           free_pixmem(mw->currentImg);              //free currentImg
           mw->pixbuf=init_pixbuf(mw->baseImg);      //get baseImg pixels
           init_image(mw->currentImg,mw->pixbuf);    //initialize currentImg with baseImg
           sharpen(mw->currentImg,mw->baseImg);      //sharpen currentImg
           g_object_unref(mw->pixbuf);               //free pixbuf
         }
         
    
    //emboss     
    else if(!strcmp(text,"emboss")){
          free_pixmem(mw->currentImg);                //free currentImg
          mw->pixbuf=init_pixbuf(mw->baseImg);        //get baseImg pixels
          init_image(mw->currentImg,mw->pixbuf);      //initialize currentImg with baseImg
          emboss(mw->currentImg,mw->baseImg);         //emboss currentImg
          g_object_unref(mw->pixbuf);                 //free pixbuf
         }
         
         
         
     //rotate   clockwise
    else if(!strcmp(text,"rotate_clockwise")){
          image *temp=new image;                       //create temp to store currentImg pixels
          mw->pixbuf=init_pixbuf(mw->currentImg);      //get currentImg pixels
          init_image(temp,mw->pixbuf);                 //initialize temp with pixbuf
          free_pixmem(mw->currentImg);                 //free currentImg pixels
          init1_image(mw->currentImg,mw->pixbuf);      //initialize currentImg with different width and height 
          rotate_clockwise(mw->currentImg,temp);       //rotate currentImg
          g_object_unref(mw->pixbuf);                  //free pixbuf
          free_pixmem(temp);                           //free temp pixels
          delete temp;                                 //delete temp
         
         }
         
         
    //rotate counter clockwise
   else if(!strcmp(text,"rotate_counter_clock")){
         image *temp=new image;                              //create temp to store currentImg pixels
          mw->pixbuf=init_pixbuf(mw->currentImg);            //get currentImg pixels
          init_image(temp,mw->pixbuf);                       //initialize temp with pixbuf
          free_pixmem(mw->currentImg);                       //free currentImg pixels
          init1_image(mw->currentImg,mw->pixbuf);            //initialize currentImg with different width and height
          rotate_counter_clockwise(mw->currentImg,temp);     //rotate currentImg
          g_object_unref(mw->pixbuf);                        //free pixbuf
          free_pixmem(temp);                                 //free temp pixels
          delete temp;                                       //delete temp
    }
    
    
    //zoom out
    else if(!strcmp(text,"zoom_out X 2")){
          image *temp=new image;                         //create temp to store currentImg pixels
          mw->pixbuf=init_pixbuf(mw->currentImg);        //get currentImg pixels
          init_image(temp,mw->pixbuf);                   //initialize temp with pixbuf
          free_pixmem(mw->currentImg);                   //free currentImg pixels
          init2_image(mw->currentImg,mw->pixbuf);        //initialize currentImg with double width and height
          zoom_out(mw->currentImg,temp);                 //zoom out currentImg
          g_object_unref(mw->pixbuf);                    //free pixbuf
          free_pixmem(temp);                             //free temp pixels
          delete temp;                                   //delete temp
         }
         
         
    //zoom in 
    else if(!strcmp(text,"zoom_in X 0.5")){
          image *temp=new image;                            //create temp to store currentImg pixels
          mw->pixbuf=init_pixbuf(mw->currentImg);           //get currentImg pixels
          init_image(temp,mw->pixbuf);                      //initialize temp with pixbuf
          free_pixmem(mw->currentImg);                      //free currentImg pixels
          init3_image(mw->currentImg,mw->pixbuf);           //initialize currentImg with half width and height
          zoom_in(mw->currentImg,temp);                     //zoom in currentImg
          free_pixmem(temp);                                //free pixbuf
          delete temp;                                      //free temp pixels
          g_object_unref(mw->pixbuf);                       //delete temp
          }
          
          
   //change to original     
    else{
    //initialize mw->currentImg with mw->baseImg
         free_pixmem(mw->currentImg);
         mw->pixbuf=init_pixbuf(mw->baseImg);
         init_image(mw->currentImg,mw->pixbuf);
         for(int i=0;i<mw->baseImg->height;i++){
                 for(int j=0;j<mw->baseImg->width;j++){
                         mw->currentImg->pix[i][j].red=mw->baseImg->pix[i][j].red;
                         mw->currentImg->pix[i][j].blue=mw->baseImg->pix[i][j].blue;
                         mw->currentImg->pix[i][j].green=mw->baseImg->pix[i][j].green;
                         }
         }
         g_object_unref(mw->pixbuf);
    }


    // Save the name of the current filter
    strcpy(mw->prev, text);
        
    // Show the current image
     mw->pixbuf = init_pixbuf(mw->currentImg);
     show_image(mw);
     
    // Show the current filter in the statusbar
    gtk_statusbar_push(GTK_STATUSBAR(mw->statusbarRight),
		       gtk_statusbar_get_context_id(GTK_STATUSBAR(mw->statusbarRight), text), text);
    
    // Free the pixel buffer
    g_object_unref(mw->pixbuf);

    g_free(text);
}

/* This is called whenever the mouse scrolls over our image.  We will update
 * the current position other status information in the status bar */
static gboolean mouse_scroll(GtkWidget *widget, GdkEventMotion *event, myWidgets *mw)
{
    int x, y;
    GdkModifierType state;

    if (event->is_hint) {
        gdk_window_get_pointer(event->window, &x, &y, &state);
    }
    else {
        x = (int)(event->x);
        y = (int)(event->y);
        state = (GdkModifierType)(event->state);
    }
    
    gchar *text;
    if ((x >= 0 && x < mw->currentImg->width) && (y >= 0 && y < mw->currentImg->height)) {
        if (mw->currentImg->mode == RGB) {
            int red = mw->currentImg->pix[y][x].red;
            int green = mw->currentImg->pix[y][x].green;
            int blue = mw->currentImg->pix[y][x].blue;
            text = g_strdup_printf("(%d, %d) R: %d, G: %d, B: %d", x, y, red, green, blue);
        }
        else {
            int intensity = mw->currentImg->pix[y][x].intensity;
            text = g_strdup_printf("(%d, %d) I: %d", x, y, intensity);
        }
        
        // Show the coordinates in the statusbar
        gtk_statusbar_push(GTK_STATUSBAR(mw->statusbarLeft),
            gtk_statusbar_get_context_id(GTK_STATUSBAR(mw->statusbarLeft), text), text);

        g_free(text);
    }
    else {
        gtk_statusbar_push(GTK_STATUSBAR(mw->statusbarLeft),
            gtk_statusbar_get_context_id(GTK_STATUSBAR(mw->statusbarLeft), ""), "");
    }
    
    return TRUE;
}

/* End this program */
void main_quit(GtkWidget *widget, myWidgets *mw)
{
    if (mw->baseImg->pix) {
        for (int i = 0; i < mw->baseImg->height; i++) {
            g_free(mw->baseImg->pix[i]);
        }
        g_free(mw->baseImg->pix);
    }

    
    if (mw->currentImg->pix) {
        for (int i = 0; i < mw->currentImg->height; i++) {
            g_free(mw->currentImg->pix[i]);
        }
        g_free(mw->currentImg->pix);
    }
    g_free(mw->baseImg);
    g_free(mw->currentImg);
    g_free(mw->prev);

    gtk_main_quit();
}



/***********************************************************
 * Main Program.
 *  __  __       _       
 * |  \/  | __ _(_)_ __  
 * | |\/| |/ _` | | '_ \ 
 * | |  | | (_| | | | | |
 * |_|  |_|\__,_|_|_| |_|
 *                       
 ***********************************************************/
int main( int argc, char *argv[])
{
    // Declare all the widgets
    myWidgets mw;
    
    // Initialize the GUI
    gtk_init(&argc, &argv);
    
    // Create the main window
    mw.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(mw.window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(mw.window), 500, 500);
    gtk_window_set_title(GTK_WINDOW(mw.window), "Simple Photoshop");
    
    // Create the vertical box
    mw.vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(mw.window), mw.vbox);
    
    // Create the menubar and menu items
    mw.menubar = gtk_menu_bar_new();
    mw.shellFile = gtk_menu_new();
    
    mw.accelGroup = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(mw.window), mw.accelGroup);
    
    mw.itemFile = gtk_menu_item_new_with_mnemonic("_File");
    mw.itemOpen = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, mw.accelGroup);
    mw.itemSave = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, mw.accelGroup);
    mw.itemSep = gtk_separator_menu_item_new();
    mw.itemQuit= gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, mw.accelGroup);
    
    gtk_widget_add_accelerator(mw.itemQuit, "activate", mw.accelGroup, 
      GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
      
    gtk_widget_set_sensitive(mw.itemSave, FALSE);
    
    // Insert the menu items into the menubar
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(mw.itemFile), mw.shellFile);
    gtk_menu_shell_append(GTK_MENU_SHELL(mw.shellFile), mw.itemOpen);
    gtk_menu_shell_append(GTK_MENU_SHELL(mw.shellFile), mw.itemSave);
    gtk_menu_shell_append(GTK_MENU_SHELL(mw.shellFile), mw.itemSep);
    gtk_menu_shell_append(GTK_MENU_SHELL(mw.shellFile), mw.itemQuit);
    gtk_menu_shell_append(GTK_MENU_SHELL(mw.menubar), mw.itemFile);
    gtk_box_pack_start(GTK_BOX(mw.vbox), mw.menubar, FALSE, FALSE, 0);
    
    // Create the toolbar and insert icons into it
    mw.toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(mw.toolbar), GTK_TOOLBAR_ICONS);
    
    mw.iconOpen = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_tool_item_set_tooltip_text(mw.iconOpen, "Open"); 
    gtk_toolbar_insert(GTK_TOOLBAR(mw.toolbar), mw.iconOpen, -1);
    
    mw.iconSave = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
    gtk_tool_item_set_tooltip_text(mw.iconSave, "Save");
    gtk_toolbar_insert(GTK_TOOLBAR(mw.toolbar), mw.iconSave, -1);
    
    mw.iconSep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(mw.toolbar), mw.iconSep, -1); 
    
    mw.iconQuit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
    gtk_tool_item_set_tooltip_text(mw.iconQuit, "Quit");
    gtk_toolbar_insert(GTK_TOOLBAR(mw.toolbar), mw.iconQuit, -1);
    
    gtk_box_pack_start(GTK_BOX(mw.vbox), mw.toolbar, FALSE, FALSE, 0);
    gtk_widget_set_sensitive(GTK_WIDGET(mw.iconSave), FALSE);
    
    // Create the combo box
    mw.combo = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "Original");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "Greyscale");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "Blurring");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "motion_blur");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "Edge detection");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "sharpen");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "emboss");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "rotate_clockwise");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "rotate_counter_clock");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "upside_down");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "zoom_out X 2");
    gtk_combo_box_append_text(GTK_COMBO_BOX(mw.combo), "zoom_in X 0.5");
    gtk_combo_box_set_active(GTK_COMBO_BOX(mw.combo), 0);
    gtk_widget_set_sensitive(GTK_WIDGET(mw.combo), FALSE);

    // Create the update button
    mw.button = gtk_button_new_with_mnemonic("_Update");
    gtk_widget_set_sensitive(GTK_WIDGET(mw.button), FALSE);

    // Pack the combo box and update button
    mw.hbox = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(mw.hbox), mw.combo, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(mw.hbox), mw.button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(mw.vbox), mw.hbox, FALSE, FALSE, 0);
    
    // Create the event box
    mw.eventBox = gtk_event_box_new();
    
    gtk_widget_set_events (mw.eventBox, 
			 GDK_POINTER_MOTION_MASK
			 | GDK_POINTER_MOTION_HINT_MASK); 
    
    // Create the scrolled window
    mw.scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(mw.scrolledWindow), 2);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(mw.scrolledWindow),
                                GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    
    // Create the image widget
    mw.imgWidget = gtk_image_new();
    gtk_misc_set_alignment(GTK_MISC(mw.imgWidget), 0.0, 0.0);
    gtk_misc_set_padding(GTK_MISC(mw.imgWidget), 0, 0);
    
    // Pack the event box, image widget and scrolled window
    gtk_container_add(GTK_CONTAINER(mw.eventBox), mw.imgWidget);  
    gtk_scrolled_window_add_with_viewport(
        GTK_SCROLLED_WINDOW(mw.scrolledWindow), mw.eventBox);
    gtk_box_pack_start(GTK_BOX(mw.vbox), mw.scrolledWindow, TRUE, TRUE, 0);
    
    // Create the statusbar
    mw.statusHbox = gtk_hbox_new(TRUE, 0);
    mw.statusbarLeft = gtk_statusbar_new();
    mw.statusbarRight = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(mw.statusHbox), mw.statusbarLeft, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(mw.statusHbox), mw.statusbarRight, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(mw.vbox), mw.statusHbox, FALSE, FALSE, 0);
    
        
    // Allocate memory for the 2D image structures
    mw.baseImg = (struct image *) g_malloc(sizeof(struct image));
    mw.baseImg->mode = RGB;
    mw.baseImg->width = 0;
    mw.baseImg->height = 0;
    mw.baseImg->pix = NULL;
    
    mw.currentImg = (struct image *) g_malloc(sizeof(struct image));
    mw.currentImg->mode = RGB;
    mw.currentImg->width = 0;
    mw.currentImg->height = 0;
    mw.currentImg->pix = NULL;
    
    // Allocate memory for the string that holds the previous filter name
    mw.prev = (gchar *) g_malloc(sizeof(gchar) * 20);
    strcpy(mw.prev, "Original");
                   
    // Connect various signals to the callback functions
    g_signal_connect(G_OBJECT(mw.window), "destroy",
        G_CALLBACK(main_quit), &mw);
    
    g_signal_connect(G_OBJECT(mw.itemOpen), "activate",
        G_CALLBACK(open_image), &mw);

    g_signal_connect(G_OBJECT(mw.itemSave), "activate",
        G_CALLBACK(save_image), &mw);

    g_signal_connect(G_OBJECT(mw.itemQuit), "activate",
        G_CALLBACK(main_quit), &mw);

    g_signal_connect(G_OBJECT(mw.iconOpen), "clicked",
        G_CALLBACK(open_image), &mw);
    
    g_signal_connect(G_OBJECT(mw.iconSave), "clicked",
        G_CALLBACK(save_image), &mw);
    
    g_signal_connect(G_OBJECT(mw.iconQuit), "clicked",
        G_CALLBACK(main_quit), &mw);
            
    g_signal_connect(G_OBJECT(mw.button), "clicked",
        G_CALLBACK(button_clicked), &mw);
    
    g_signal_connect(G_OBJECT(mw.eventBox), "motion-notify-event",
	   G_CALLBACK(mouse_scroll), &mw);
      
    gtk_widget_show_all(mw.window);
    
    gtk_main();
    
    return 0;
}
