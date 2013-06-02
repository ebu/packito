/*!
 * \project_name AutoPackager
 * \file genericAssistant.cpp
 * \brief 
 * \details 
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 29 may 2013
 *
 * This software is published in MPLv2.0
 *
 */



#include "genericAssistant.hpp"

// class constructor and destructor

GenericAssistant::GenericAssistant
(
	std::string assistantTitle,
	std::vector<std::string> assistantLabels,
	std::vector<std::string> assistantPlaceholders,
	bool assistantModalMode
)
{
	set_title(assistantTitle);
	set_default_size (323, 200);
	set_modal(assistantModalMode);
	
	container = manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,(2*assistantLabels.size())-1));
	
	for (unsigned int i=0;i<assistantLabels.size();i++) 
	{
		
		Gtk::Box * b = manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL,3));
		Gtk::Label * l = manage(new Gtk::Label(assistantLabels.at(i)));
		b->add(*l);
		Gtk::AspectFrame * af = manage(new Gtk::AspectFrame());
		b->add(*af);
		// entry and placeholder....
		Gtk::Entry * e = manage(new Gtk::Entry());
		e->set_placeholder_text(assistantPlaceholders.at(i).c_str());
		b->add(*e);
		// record the entry's content
		Entry.push_back(e);
		// show_children
		b->show_all_children();
		// add
		container->add(*b);
		if (assistantLabels.size()-1 != i) 
		{
			Gtk::AspectFrame * af = manage(new Gtk::AspectFrame());
			container->add(*af);	
		} 
	}
	container->show_all_children();
	// set assistant pages and config it
	append_page(*container);
	set_page_complete(*container, true);	
	set_page_type(*container, Gtk::ASSISTANT_PAGE_CONFIRM);
	show_all_children();
	// close or cancel the assistant
	signal_cancel().connect
	(
		sigc::mem_fun
		(
			*this,
			&GenericAssistant::on_assistant_cancel
		)
	);
	signal_close().connect
	(
		sigc::mem_fun
		(
			*this,
			&GenericAssistant::on_assistant_close
		)
	);

}

GenericAssistant::~GenericAssistant
(
	void
)
{
}

void GenericAssistant::on_assistant_cancel
(
	void
)
{
	hide();
}

void GenericAssistant::on_assistant_close
(
	void
)
{

	hide();
}

std::vector<std::string> GenericAssistant::getResponse
(
	void
)
{
	std::vector<std::string> tmp;
	for (unsigned int i=0; i<Entry.size();i++) 
	{
		tmp.push_back((Entry.at(i))->get_text());
	}
	return tmp;
}
