#include "AlienWindow.h"
#include <iostream>

// constructor / destructor
AlienWindow::AlienWindow(QWidget *parent)
	: QWidget(parent)
	{ // constructor

	// create menu bar
	menuBar = new QMenuBar(this);

	// create file menu
	fileMenu = menuBar->addMenu("&File");

	// create the action
	actionQuit = new QAction("&Quit", this);

	// leave signals & slots to the controller

	// add the item to the menu
	fileMenu->addAction(actionQuit);

	// create the window layout
	windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

	// create main widget
	cubeWidget = new AlienWidget(this);
	windowLayout->addWidget(cubeWidget);

	// create slider
	nVerticesSlider = new QSlider(Qt::Horizontal);
	connect(nVerticesSlider, SIGNAL(valueChanged(int)), cubeWidget, SLOT(updateFlying(int)));
	windowLayout->addWidget(nVerticesSlider);

	windowLayout->addWidget(nVerticesSlider);


	ptimer = new QTimer(this);
	connect(ptimer, SIGNAL(timeout()),  cubeWidget, SLOT(updateAngle()));
	ptimer->start(0);

	// connect(ptimer, SIGNAL(timeout()),  cubeWidget, SLOT(updateAngle()));


	} // constructor

AlienWindow::~AlienWindow()
	{ // destructor
	delete ptimer;
	delete nVerticesSlider;
	delete cubeWidget;
	delete windowLayout;
	delete actionQuit;
	delete fileMenu;
	delete menuBar;
	} // destructor

// resets all the interface elements
void AlienWindow::ResetInterface()
	{ // ResetInterface()
	nVerticesSlider->setMinimum(3);
	nVerticesSlider->setMaximum(30);
	nVerticesSlider->setValue(0);

	//don't use the slider for now

	//	nVerticesSlider->setValue(thePolygon->nVertices);

	// now force refresh
	cubeWidget->update();
	update();
	} // ResetInterface()
