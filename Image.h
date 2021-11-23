#ifndef _IMAGE_
#define _IMAGE_

#include<string>
#include <QImage>
#include <GL/glu.h>


class Image {
 public:

  Image(const std::string& fn);

  ~Image();

  const GLubyte* imageField() const;

  unsigned int Width()  const { return _width;}
  unsigned int Height() const {return _height;}
 private:
  Image(const Image&);

  unsigned int _width;
  unsigned int _height;

  QImage* p_qimage;


  GLubyte* _image;
  GLubyte* _image3;
  GLubyte* _image4;
  GLubyte* _image5;
};

#endif
