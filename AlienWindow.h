#ifndef __GL_POLYGON_WINDOW_H__
#define __GL_POLYGON_WINDOW_H__ 1

#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QTimer>
#include <QBoxLayout>
#include "AlienWidget.h"

class AlienWindow: public QWidget
	{
	public:


	// constructor / destructor
	AlienWindow(QWidget *parent);
	~AlienWindow();

	// visual hierarchy
	// menu bar
	QMenuBar *menuBar;
		// file menu
		QMenu *fileMenu;
			// quit action
			QAction *actionQuit;

	// window layout
	QBoxLayout *windowLayout;

	// beneath that, the main widget
	AlienWidget *cubeWidget;
	// and a slider for the number of vertices
	QSlider *nVerticesSlider;

	// a timer
	QTimer *ptimer;

	// resets all the interface elements
	void ResetInterface();
	};

#endif
