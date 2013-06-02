/*!
 * \project_name PHYM : Physic of mechanics
 * \file genericFilechooserWindow.cpp
 * \brief Generic filechooser window body.
 * \details This class is used to launch a generic filechooser
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 15 april 2013
 *
 * This software is published in MPLv2.0
 *
 */

#include "genericFilechooserWindow.hpp"

genericFilechooserWindow::genericFilechooserWindow
(
	Gtk::Window& parent, 
	const Glib::ustring& title, 
	Gtk::FileChooserAction action, 
	Glib::ustring currentFolder,
	bool multipleSelection,
	unsigned int mimeType
) 
: 
	 Gtk::FileChooserDialog (parent, title, action)
{
	// append filechooser buttons and linked events
	add_button
	(
		Gtk::Stock::CANCEL, 
		Gtk::RESPONSE_CANCEL
	);
	add_button
	(
		Gtk::Stock::OK, 
		Gtk::RESPONSE_OK
	);
	// set the path to folder of the application as current folder
	set_current_folder(currentFolder);
	// Allow the selection of several files
	set_select_multiple(multipleSelection);
	// ask confirmation before overwrite an existing file
	if (action == Gtk::FILE_CHOOSER_ACTION_SAVE)
		set_do_overwrite_confirmation(true);
	// mime type file filter
	setFilters(mimeType);
	// run the filechooser and grab the result
	response = run();
	// alert dialog
	if (action != Gtk::FILE_CHOOSER_ACTION_SAVE) {
		if (response == Gtk::RESPONSE_OK and 
		!genericFeatures::fileExists(get_filename()))
		{
			genericAlertWindow * AC = new genericAlertWindow
			(
				*this, 
				"File error" , 
				"The file you are trying to open does not exist"
			);
			delete AC;
		}
	} else {
		if (response == Gtk::RESPONSE_OK) {
			outputProject = genericFeatures::isExtension(get_filename(),"xml")
					? get_filename()
					: get_filename()+".xml";
				
		}
	}
}

genericFilechooserWindow::~genericFilechooserWindow
(
	void
)
{
}

int genericFilechooserWindow::getResponse
(
	void
)
{
	return response;
}

Glib::ustring genericFilechooserWindow::getURIToFile
(
	void
)
{
	return genericFeatures::removePrefix(get_uri(),"file://");
}



std::vector<Glib::ustring> genericFilechooserWindow::getURIToFiles
(
	void
)
{
	return get_uris();
}
	
std::string genericFilechooserWindow::getPathToSave
(
	void
)
{
	return outputProject;
}

void genericFilechooserWindow::setCFilter
(
	void
) 
{
	// filter for c/c++ files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	// add the filters to the filechooser
	filter->set_name("C/C++ files");
	filter->add_mime_type("text/x-c");
	filter->add_mime_type("text/x-c++");
	filter->add_mime_type("text/x-c-header");
	add_filter(filter);
}

void genericFilechooserWindow::setImgFilter
(
	void
) 
{
	// filter for image files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	// add the filters to the filechooser
	filter->add_pixbuf_formats();
	filter->set_name("Images");
	add_filter(filter);
}

void genericFilechooserWindow::setGladeFilter
(
	void
) 
{
	// filter for Glade files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	// add the filters to the filechooser
	filter->set_name("Glade files");
	filter->add_pattern("*.glade");
	add_filter(filter);
}

void genericFilechooserWindow::setAnyFilter
(
	void
) 
{
	// filter for any file
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	// add the filters to the filechooser
	filter->set_name("Any files");
	filter->add_pattern("*");
	add_filter(filter);
}

void genericFilechooserWindow::setXMLFilter
(
	void
) 
{
	// filter for AutoPackager XML files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	filter->set_name("AutoPackager configuration");
	filter->add_pattern("*.xml");
	// add the filters to the filechooser
	add_filter(filter);
}

void genericFilechooserWindow::setDoxygenFilter
(
	void
) 
{
	// filter for AutoPackager XML files
	Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
	filter->set_name("Doxygen configuration");
	filter->add_pattern("*.cfg");
	// add the filters to the filechooser
	add_filter(filter);
}

void genericFilechooserWindow::setFilters
(
	unsigned int mimeType
)
{	
	switch (mimeType)
	{
		case 1 : {setCFilter();} break;
		case 2 : {setImgFilter();}	break;
		case 3 : {setGladeFilter();} break;
		case 4 : {setAnyFilter();}	break;
		case 5 : {setDoxygenFilter();}	break;
		case 6 : {/* directory mode, no filter*/}	break;
		default : {setXMLFilter();}
	}
}
