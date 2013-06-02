/*!
 * \project_name PHYM : Physic of mechanics
 * \file genericAlertWindow.cpp
 * \brief Generic alert window functions body
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 15 april 2013
 *
 * This software is published in MPLv2.0
 *
 */

#include "genericAlertWindow.hpp"

genericAlertWindow::genericAlertWindow
(
		Gtk::Window& alertParent,
	 	const Glib::ustring & alertTitle,
	 	std::string alertMessage
) 
: 
	 Gtk::MessageDialog (alertParent, alertTitle)
{
	set_secondary_text(alertMessage);
	run();
}

genericAlertWindow::~genericAlertWindow
(
	void
)
{
}
