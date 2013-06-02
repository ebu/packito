/*!
 * \project_name AutoPackager
 * \file main.cpp
 * \brief
 * \details 
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 23 may 2013
 *
 * This software is published in MPLv2.0
 *
 */

/*!
 *
 * \mainpage AutoPackager presentation
 *
 */
 
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/builder.h>
#include <gtkmm/treeview.h>
#include <glibmm/fileutils.h>
#include <glibmm/markup.h>
#include <iostream>


#include "packagerWindow.hpp"

int main (int argc, char *argv[]) {
	// init gtk
	Gtk::Main app(argc, argv);
	//Load the Glade file and instiate its widgets:
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
	try
	{
		refBuilder->add_from_file("AutoPackager.glade");
	}
	catch(const Glib::FileError& err)
	{
		std::cerr << "FileError: " << err.what() << std::endl;
		return 1;
	}
	catch(const Glib::MarkupError& err)
	{
		std::cerr << "MarkupError: " << err.what() << std::endl;
		return 1;
	}
	catch(const Gtk::BuilderError& err)
	{
		std::cerr << "BuilderError: " << err.what() << std::endl;
		return 1;
	}
	// Instantiate a window and set its glade reference
	PackagerWindow * MainWindow;
	refBuilder->get_widget_derived("AutoPackager",MainWindow);
	// run the gtk application
	Gtk::Main::run(* MainWindow );
	// free memory properlyy
	delete MainWindow;
	return 0;
}
