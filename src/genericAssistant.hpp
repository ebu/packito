#ifndef CPP_GENERICASSISTANT_CLASS_H
#define CPP_GENERICASSISTANT_CLASS_H

/*!
 * \project_name AutoPackager
 * \file genericAssistant.hpp
 * \brief 
 * \details 
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 29 may 2013
 *
 * This software is published in MPLv2.0
 *
 */


/*! \class GenericAssistant
 * \brief 
 */

#include <gtkmm/assistant.h>
#include <gtkmm/aspectframe.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>


#include <sigc++/sigc++.h>

#include <glibmm/fileutils.h>
#include <glibmm/i18n.h>
#include <glibmm/main.h>
#include <glibmm/thread.h>
#include <glibmm/ustring.h>

#include <gdkmm/color.h>

#include <gtkmm/actiongroup.h>
#include <gtkmm/clipboard.h>
#include <gtkmm/enums.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/filefilter.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/stock.h>
#include <gtkmm/toolbar.h>
#include <gtkmm/toolbutton.h>
#include <gtkmm/uimanager.h>


#include <iostream>

class GenericAssistant : public Gtk::Assistant
{
	public:
	
		GenericAssistant
		(
			std::string assistantTitle,
			std::vector<std::string> assistantLabels,
			std::vector<std::string> assistantPlaceholders,
			bool assistantModalMode
		);
		
		virtual ~GenericAssistant
		(
			void
		);
		
		std::vector<std::string> getResponse
		(
			void
		);

	protected:
		std::vector<Gtk::Entry *> Entry;
		Gtk::Box * container;
	
		void on_assistant_cancel
		(
			void
		);

		void on_assistant_close
		(
			void
		);
		
};

#endif
