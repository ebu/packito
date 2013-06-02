#ifndef CPP_GENERICFILECHOOSERWINDOW_CLASS_H
#define CPP_GENERICFILECHOOSERWINDOW_CLASS_H

/*!
 * \project_name PHYM : Physic of mechanics
 * \file genericFilechooserWindow.hpp
 * \brief Generic filechooser window specification.
 * \details This class is used to launch a generic filechooser
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

#include "genericAlertWindow.hpp"
#include "genericFeatures.hpp"

class genericFilechooserWindow : public Gtk::FileChooserDialog
{
public:

	/*!*
	* @brief Class constructor
	* @brief The genericFilechooserWindow class constructor instantiates a new filechooser with alert messages required.\n\n
	* @param[in] Gtk::Window& parent : The parent window which instantiates the filechooser
	* @param[in] const Glib::ustring& title : The title of the filechooser message window
	* @param[in] Gtk::FileChooserAction action : The type of action supported by the FileChooser
	* @param[in] Glib::ustring currentFolder : Set the directory of entry of the filechooser
	* @param[in] bool multipleSelection : Allow the selection of several files
	* @param[in] int mimeType : Set the mime type filter \n\n
		0 : By default -> xml (*.xml)\n\n
		1 : Amy C/C++ files (*.c *.cpp *.cxx *.h *.hpp *.hxx)\n\n
		2 : Any image files  (*.gif *.jpg *.png ...)\n\n
		3 : Glade files (*.glade)\n\n
		4 : Any file (*.*)\n\n
		5 : Doxygen configuration file (*.*)\n\n
		6 : Directory mode only \n\n
	*/	
	genericFilechooserWindow
	(
		Gtk::Window& parent, 
		const Glib::ustring& title, 
		Gtk::FileChooserAction action, 
		Glib::ustring currentFolder,
		bool multipleSelection,
		unsigned int mimeType = 0
	);
	
	
	virtual ~genericFilechooserWindow
	(
		void
	);

	/**
	* @fn int getResponse(void)
	* @brief This function will return the Gtk::ResponType of the filechooser
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return int if all is right or an error at compilation time.
	*/
	int getResponse
	(
		void
	);

	/**
	* @fn Glib::ustring getURIToFile(void)
	* @brief This function will return the URI to the selected file
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return Glib::ustring if all is right or an error at compilation time.
	*/
	Glib::ustring getURIToFile
	(
		void
	);
	
	/**
	* @fn std::vector<Glib::ustring> getURIToFiles(void)
	* @brief This function will return a vector with the URI to all selected files
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return std::vector<Glib::ustring> if all is right or an error at compilation time.
	*/
	std::vector<Glib::ustring> getURIToFiles
	(
		void
	);
	
	/**
	* @fn std::string getPathToSave(void)
	* @brief This function will return the path to file in which the project must be saved
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return std::string if all is right or an error at compilation time.
	*/
	std::string getPathToSave
	(
		void
	);
	
protected:

	int response; /*!< response the Gtk::ResponType selected by the user into the filechooser */
	std::string outputProject;
	

	/**
	* @fn void setCFilter(void)
	* @brief This function filters files whose mime type corresponds to C/C++ files. All others mime types are excluded
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setCFilter
	(
		void
	);
	
	/**
	* @fn void setImgFilter(void)
	* @brief This function filters files whose mime type corresponds to picture files. All others mime types are excluded
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setImgFilter
	(
		void
	);
	
	/**
	* @fn void setGladeFilter(void)
	* @brief This function filters files whose mime type corresponds to Glade files. All others mime types are excluded
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setGladeFilter
	(
		void
	);
	
	/**
	* @fn void setAnyFilter(void)
	* @brief This function filters files whose mime type corresponds to any file. All others mime types are excluded
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setAnyFilter
	(
		void
	);

	/**
	* @fn void setXMLFilter(void)
	* @brief This function filters files whose mime type corresponds to XML files. All others mime types are excluded
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setXMLFilter
	(
		void
	);
	
	/**
	* @fn void setDoxygenFilter(void)
	* @brief This function filters files whose mime type corresponds to Doxygen configuration files. All others mime types are excluded
	* @brief
	* @note needs more documentation
	* @param[in] void : no params
	* @return void if all is right or an error at compilation time.
	*/
	void setDoxygenFilter
	(
		void
	);
	
	/**
	* @fn void setFilters(unsigned int mimeType)
	* @brief This function allows you to set the appropriate mime types
	* @brief
	* @note needs more documentation
	* @param[in] unsigned int mimeType : this int defines the appropriate mime types
	* @note Values for mime types are : \n
	* \li \c \b 0 : By default, xml file. 
	* @return nothning if all is right or an error at compilation time.
	*/
	void setFilters
	(
		unsigned int mimeType
	);

};

#endif /*CPP_GENERICFILECHOOSERWINDOW_CLASS_H*/
