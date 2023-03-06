#include "image.h"

// HW0 #1
// const Image& im: input image
// int x,y: pixel coordinates
// int ch: channel of interest
// returns the 0-based location of the pixel value in the data array
int pixel_address(const Image& im, int x, int y, int ch) {

    // TODO: calculate and return the index
  int dim= im.w*im.h; //dimensione dell canale
  int pixel_index= ch* (im.w * im.h);
  int col=x, riga=y,cha=ch;

  /*
  //prendo quelli prima sulla riga
  for(int i=0;i<col;i++){
    start++;
  }

  //prendo tutti quelli sopra
  for(int i=0;i<riga;i++){
    for(int j=0;j<im.w;j++){
      start++;
    }
  }
   */
  // a quello che ho già sommo tutti quelli sopra e tutti quelli sotto

  pixel_index= pixel_index+ (im.w*y) +x;

  return pixel_index;
  }

// HW0 #1
// const Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
// returns the value of the clamped pixel at channel ch
float get_clamped_pixel(const Image& im, int x, int y, int ch)
  {
  // TODO: clamp the coordinates and return the correct pixel value
  int colonne=im.w;
  int righe=im.h;
  int canali=im.c;

  //x sono le colonne, y le righe
  if(x<0) x=0;
  if(x>=colonne) x=colonne-1;
  if(y<0) y=0;
  if(y>=righe) y=righe-1;
  if(ch<0) ch=0;
  if(ch>=canali) ch=canali-1;

  //int indexOk= im(x,y,ch);

  
  return im.data[pixel_address(im,x,y,ch)];
  }


// HW0 #1+
// Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
void set_pixel(Image& im, int x, int y, int c, float value)
  {
  // TODO: Only set the pixel to the value if it's inside the image
  

  int righe=im.h;
  int colonne=im.w;
  int canali=im.c;
  if(x>=colonne || x<0) return;
  if(y<0 || y>=righe) return;
  if(c<0 || c >=canali) return;

  im.data[pixel_address(im,x,y,c)]=value;

  
  }



// HW0 #2
// Copies an image
// Image& to: destination image
// const Image& from: source image
void copy_image(Image& to, const Image& from)
  {
  // allocating data for the new image
  to.data=(float*)calloc(from.w*from.h*from.c,sizeof(float));
  to.c=from.c;
  
  // TODO: populate the remaining fields in 'to' and copy the data
  // You might want to check how 'memcpy' function works
  
  to.w=from.w;

  to.h=from.h;

  memcpy(from.data,to.data, to.size()*sizeof(float));


  }
