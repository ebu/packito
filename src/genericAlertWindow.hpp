#ifndef CPP_GENERICALERTWINDOW_CLASS_H
#define CPP_GENERICALERTWINDOW_CLASS_H

/*!
 * \project_name PHYM : Physic of mechanics
 * \file genericAlertWindow.cpp
 * \brief Generic alert window functions specifications
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 15 april 2013
 *
 * This software is published in MPLv2.0
 *
 */

#include <gtkmm.h>
#include <gdkmm.h>
#include <iostream>
#include <string>
#include <fstream>

class genericAlertWindow : public Gtk::MessageDialog
{
public:

	/*!*
	* @brief Class constructor
	* @brief The genericAlertWindow class constructor instantiates a new dialog message.\n\n
	* @param[in] Gtk::Window& alertParent : The window which instantiates the dialog message
	* @param[in] const Glib::ustring alertTitle : The title of the dialog message window
	* @param[in] std::string alertMessage : The message to write into the dialog box
	*/
	genericAlertWindow
	(
		Gtk::Window& alertParent,
	 	const Glib::ustring & alertTitle,
	 	std::string alertMessage
	);
	
	virtual ~genericAlertWindow
	(
		void
	);
	
protected:

};

#endif /*CPP_GENERICALERTWINDOW_CLASS_H*/
