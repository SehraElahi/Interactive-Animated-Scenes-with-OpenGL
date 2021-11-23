#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>
#include <QImage>
#include "Image.h"
#include <GL/glut.h>


class AlienWidget: public QGLWidget
	{ //

	Q_OBJECT

	public:
	AlienWidget(QWidget *parent);
	~AlienWidget();

	public slots:
        // called by the timer in the main window
	void updateAngle();

	public slots:
				void updateFlying(int i);

	protected:
	// called when OpenGL context is set up
	void initializeGL();
	// called every time the widget is resized
	void resizeGL(int w, int h);
	// called every time the widget needs painting
	void paintGL();

	private:
	void wall();
	void wall2();
	void text();
	void text2();
	void floor();
	void fillimage();
	void polygon(int, int, int, int);
	void discoball();
	void rod();
	void walltext1();
	void walltext2();
	void eye();
	void antenna();
	void body();
	void spaceship ();
	void top();
	void discorod();


		GLUquadricObj* pdiscoball;
		GLUquadricObj* prod;
		GLUquadricObj* peye;
		GLUquadricObj* pbody;
		GLUquadricObj* pantenna;
		GLUquadricObj* pspaceship;
		GLUquadricObj* ptop;
		GLUquadricObj* pdiscorod;

	float angle;
	int flying;

	Image   _image;
	Image 	_image2;
	Image  	_image3;
	Image	 	_image4;
	Image 	_image5;

        QImage* p_qimage;


	}; // class GLPolygonWidget

#endif
