#ifndef CPP_PACKAGERWINDOW_CLASS_H
#define CPP_PACKAGERWINDOW_CLASS_H

/*!
 * \project_name AutoPackager
 * \file packagerWindow.hpp
 * \brief 
 * \details 
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 23 may 2013
 *
 * This software is published in MPLv2.0
 *
 */


/*! \class PackagerWindow
 * \brief 
 */

#include <sys/types.h> // file creation and co
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <glibmm/convert.h>

#include <gtkmm/treeview.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/treemodelcolumn.h>
#include <gtkmm/liststore.h>
#include <gtkmm/treeselection.h>


#include "packagerEngine.hpp"
#include "genericFilechooserWindow.hpp"
#include "genericAssistant.hpp"

#define COLOREVEN "#F9F9F9"
#define COLORODD "#EEEEEE"

class PackagerWindow : public Gtk::Window
{
	public:
		PackagerWindow
		(
			BaseObjectType* cobject,
			const Glib::RefPtr<Gtk::Builder>& refGlade
		);
		virtual ~PackagerWindow
		(
			void
		);

	protected:

		Glib::RefPtr<Gtk::Builder> m_refGlade; /*!< m_refGlade : Glade references */
		
		// _Menubar
		// _File
		Gtk::MenuItem* AutoPackagerMenuItemNew;/*!< AutoPackagerMenuItemNew This menu item creates a new project */
		Gtk::MenuItem* AutoPackagerMenuItemOpen;/*!< AutoPackagerMenuItemOpen This menu item opens an existing project */
		Gtk::MenuItem* AutoPackagerMenuItemSave;/*!< AutoPackagerMenuItemSave This menu item saves the current project */
		Gtk::MenuItem* AutoPackagerMenuItemSaveas;/*!< AutoPackagerMenuItemSaveas This menu item saves the current project as a new one. */
		Gtk::MenuItem* AutoPackagerMenuItemQuit;/*!< AutoPackagerMenuItemQuit This menu item closes the application */
		// _Help
		Gtk::MenuItem* AutoPackagerMenuItemAbout;/*!< AutoPackagerMenuItemAbout This menu item opens the about dialog */

		// box
		Gtk::Box * EmptyBox; /*!< EmptyBox This box encapsulates the welcome message */
		Gtk::Box * ProjectBox; /*!< ProjectBox This box encapsulates the project description */
		Gtk::Box * SourceBox; /*!< SourceBox This box allows to define the project sources*/
		Gtk::Box * DependencyBox; /*!< DependencyBox All dependencies will be setted into this box*/
		Gtk::Box * EnvironmentBox; /*!< EnvironmentBox This box defines the project environment */
		Gtk::Box * EmptyControllerBox; /*!< EmptyControllerBox This box ... */
		Gtk::Box * ProjectControllerBox; /*!< ProjectControllerBox This box ... */
		Gtk::Box * SourceControllerBox; /*!< SourceControllerBox This box ... */
		Gtk::Box * DependencyControllerBox; /*!< DependencyControllerBox This box ... */
		Gtk::Box * EnvironmentControllerBox; /*!< EnvironmentControllerBox This box ... */

		// eventbox
		Gtk::EventBox * WelcomeMsgEventBox; /*!< WelcomeMsgEventBox This EventBox makes the embedded label sensitive */
		
		// scrolled window
		Gtk::ScrolledWindow * SourceScrolledSrc; /*!< SourceScrolledSrc This scrolled window ... */
		Gtk::ScrolledWindow * SourceScrolledImg; /*!< SourceScrolledImg This scrolled window ... */
		Gtk::ScrolledWindow * SourceScrolledGlade; /*!< SourceScrolledGlade This scrolled window ... */
		Gtk::ScrolledWindow * SourceScrolledOthers; /*!< SourceScrolledOthers This scrolled window ... */
		Gtk::ScrolledWindow * DependencyScrolledI; /*!< DependencyScrolledI This scrolled window ... */
		Gtk::ScrolledWindow * DependencyScrolledL; /*!< DependencyScrolledL This scrolled window ... */
		Gtk::ScrolledWindow * DependencyScrolledl; /*!< DependencyScrolledl This scrolled window ... */
		Gtk::ScrolledWindow * EnvironmentScrolledPKG; /*!< EnvironmentScrolledPKG This scrolled window ... */
		Gtk::ScrolledWindow * EnvironmentScrolledVariable; /*!< EnvironmentScrolledVariable This scrolled window ... */

		// buttons
		Gtk::Button * ProjectDoxygenOpenButton; /*!< ProjectDoxygenOpenButton This button ...*/
		Gtk::Button * ProjectOutputOpenButton; /*!< ProjectOutputOpenButton This button ...*/
		Gtk::Button * ProjectNextButton; /*!< ProjectNextButton This button ...*/
		Gtk::Button * SourceSrcOpenButton; /*!< SourceSrcOpenButton This button ...*/
		Gtk::Button * SourceImgOpenButton; /*!< SourceImgOpenButton This button ...*/
		Gtk::Button * SourceGladeOpenButton; /*!< SourceGladeOpenButton This button ...*/
		Gtk::Button * SourceOthersOpenButton; /*!< SourceOthersOpenButton This button ...*/
		Gtk::Button * SourceRemoveSrcButton; /*!< SourceRemoveSrcButton This button ...*/
		Gtk::Button * SourceRemoveImgButton; /*!< SourceRemoveImgButton This button ...*/
		Gtk::Button * SourceRemoveGladeButton; /*!< SourceRemoveGladeButton This button ...*/
		Gtk::Button * SourceRemoveOthersButton; /*!< SourceRemoveOthersButton This button ...*/
		Gtk::Button * SourcePreviousButton; /*!< SourcePreviousButton This button ...*/
		Gtk::Button * SourceNextButton; /*!< SourceNextButton This button ...*/
		Gtk::Button * DependencyIOpenButton; /*!< DependencyIOpenButton This button ...*/
		Gtk::Button * DependencyLOpenButton; /*!< DependencyLOpenButton This button ...*/
		Gtk::Button * DependencylOpenButton; /*!< DependencylOpenButton This button ...*/
		Gtk::Button * EnvironmentPKGOpenButton; /*!< EnvironmentPKGOpenButton This button ...*/
		Gtk::Button * DependencyRemoveIButton; /*!< DependencyRemoveIButton This button ...*/
		Gtk::Button * DependencyRemoveLButton; /*!< DependencyRemoveLButton This button ...*/
		Gtk::Button * DependencyRemovelButton; /*!< DependencyRemovelButton This button ...*/
		Gtk::Button * EnvironmentRemovePKGButton; /*!< DependencyRemoveIncludeButton This button ...*/
		Gtk::Button * DependencyPreviousButton; /*!< DependencyPreviousButton This button ...*/
		Gtk::Button * DependencyNextButton; /*!< DependencyNextButton This button ...*/
		Gtk::Button * EnvironmentVariableOpenButton; /*!< EnvironmentVariableOpenButton This button ...*/
		Gtk::Button * EnvironmentRemoveVariableButton; /*!< EnvironmentRemoveVariableButton This button ...*/
		Gtk::Button * EnvironmentPreviousButton; /*!< EnvironmentPreviousButton This button ...*/
		Gtk::Button * EnvironmentNextButton; /*!< EnvironmentNextButton This button ...*/
		
		// radiobuttons
		Gtk::RadioButton * ProjectLanguageC; /*!< ProjectLanguageC This radiobutton ...*/
		Gtk::RadioButton * ProjectLanguageCPP; /*!< ProjectLanguageCPP This radiobutton ...*/
		
		// entry
		Gtk::Entry * ProjectNameEntry; /*!< ProjectNameEntry This entry ...*/
		Gtk::Entry * ProjectTarballEntry; /*!< ProjectTarballEntry This entry ...*/
		Gtk::Entry * ProjectURLEntry; /*!< ProjectURLEntry This entry ...*/
		Gtk::Entry * ProjectBugReportEntry; /*!< ProjectBugReportEntry This entry ...*/
		Gtk::Entry * ProjectDoxygenEntry; /*!< ProjectDoxygenEntry This entry ...*/
		Gtk::Entry * ProjectOutputEntry; /*!< ProjectOutputEntry This entry ...*/
		Gtk::Entry * EnvironmentCompilerFlagsEntry; /*!< EnvironmentCompilerFlagsEntry This entry ...*/
		Gtk::Entry * EnvironmentArgumentsEntry; /*!< EnvironmentArgumentsEntry This entry ...*/
		Gtk::Entry * ProjectMajorVersion; /*!< ProjectMajorVersion This entry ...*/
		Gtk::Entry * ProjectMinorVersion; /*!< ProjectMinorVersion This entry ...*/
		Gtk::Entry * ProjectMicroVersion; /*!< ProjectMicroVersion This entry ...*/
		
		// label
		Gtk::Label * EmptyTitleLabel; /*!< EmptyTitleLabel This label ...*/
		Gtk::Label * ProjectTitleLabel; /*!< ProjectTitleLabel This label ...*/
		Gtk::Label * SourceTitleLabel; /*!< SourceTitleLabel This label ...*/
		Gtk::Label * DependencyTitleLabel; /*!< DependencyTitleLabel This label ...*/
		Gtk::Label * EnvironmentTitleLabel; /*!< EnvironmentTitleLabel This label ...*/
		
		// assistant
		GenericAssistant * GA;
		
		// engine
		PackagerEngine * engine;
		
		//Tree model columns
		class FileColumns : public Gtk::TreeModel::ColumnRecord 
		{
			public:
		
				FileColumns()
				{ 
					add(fileidcol);
					add(filepathcol);
					add(filecellbgcolorcol);
				}

			Gtk::TreeModelColumn<std::size_t> fileidcol;
			Gtk::TreeModelColumn<std::string> filepathcol;
			Gtk::TreeModelColumn<Glib::ustring> filecellbgcolorcol;
	  	};
	  	
	  	FileColumns fColumns;
	  	Gtk::TreeView * sourceTreeview;
		Gtk::TreeView * imageTreeview;
		Gtk::TreeView * gladeTreeview;
		Gtk::TreeView * othersTreeview;
		Gtk::TreeView * ITreeview;
		Gtk::TreeView * LTreeview;
		Gtk::TreeView * lTreeview;
		Gtk::TreeView * PKGTreeview;
		Glib::RefPtr<Gtk::ListStore> sourceStore;
		Glib::RefPtr<Gtk::ListStore> imageStore;
		Glib::RefPtr<Gtk::ListStore> gladeStore;
		Glib::RefPtr<Gtk::ListStore> othersStore;
		Glib::RefPtr<Gtk::ListStore> IStore;
		Glib::RefPtr<Gtk::ListStore> LStore;
		Glib::RefPtr<Gtk::ListStore> lStore;
		Glib::RefPtr<Gtk::ListStore> PKGStore;
		Glib::RefPtr<Gtk::TreeSelection> sourceSelection;
		Glib::RefPtr<Gtk::TreeSelection> imageSelection;
		Glib::RefPtr<Gtk::TreeSelection> gladeSelection;
		Glib::RefPtr<Gtk::TreeSelection> othersSelection;
		Glib::RefPtr<Gtk::TreeSelection> ISelection;
		Glib::RefPtr<Gtk::TreeSelection> LSelection;
		Glib::RefPtr<Gtk::TreeSelection> lSelection;
		Glib::RefPtr<Gtk::TreeSelection> PKGSelection;
		
	  	
		class VarEnvColumns : public Gtk::TreeModel::ColumnRecord 
		{
			public:
		
				VarEnvColumns()
				{ 
					add(variableenvidcol);
					add(variableenvnamecol);
					add(variableenvvaluecol);
					add(variableenvcellbgcolorcol);
				}

			Gtk::TreeModelColumn<std::size_t> variableenvidcol;
			Gtk::TreeModelColumn<std::string> variableenvnamecol;
			Gtk::TreeModelColumn<std::string> variableenvvaluecol;
			Gtk::TreeModelColumn<Glib::ustring> variableenvcellbgcolorcol;
	  	};
	  	
	  	VarEnvColumns eColumns;
		Gtk::TreeView * varenvTreeview;
		Glib::RefPtr<Gtk::ListStore> varenvStore;
		Glib::RefPtr<Gtk::TreeSelection> varenvSelection;

		void refGladeMenu
		(
			void
		);
		void refGladeButtons
		(
			void
		);
		void refGladeWidgets
		(
			void
		);
	
		void connectSignalActivate
		(
			void
		);
	
		void connectSignalClicked
		(
			void
		);
		
		void connectSignalEvent
		(
			void
		);
		
		void initListStores
		(
			void
		);
	
		void on_AutoPackagerMenuItemNew_activate
		(
			void
		);
		
		bool on_AutoPackagerEventNew_press
		(
			GdkEventButton * event
		);
	
		void on_AutoPackagerMenuItemOpen_activate
		(
			void
		);
		
		void load_configuration
		(
			std::string configfile
		);
	
		void on_AutoPackagerMenuItemSave_activate
		(
			void
		);

		void on_AutoPackagerMenuItemSaveas_activate
		(
			void
		);
	
		void on_AutoPackagerMenuItemQuit_activate
		(
			void
		);
	
		void on_AutoPackagerMenuItemAbout_activate
		(
			void
		);
		
		void updatePage
		(
			unsigned int nextPage
		);
		
		void changePage
		(
			bool back
		);
		
		void on_addfile_clicked
		(
			std::string title,
			unsigned int mime,
			Glib::RefPtr<Gtk::ListStore> store,
			Gtk::FileChooserAction action
		);
		
		void on_add_env_var_clicked
		(
			std::string title,
			Glib::RefPtr<Gtk::ListStore> store
		);
		
		void on_add_static_clicked
		(
			std::string title,
			Glib::RefPtr<Gtk::ListStore> store
		);
		
		void on_remove_clicked
		(
			Glib::RefPtr<Gtk::TreeSelection> selection,
			Glib::RefPtr<Gtk::ListStore> store
		);
		void on_doxygen_open
		(
			void
		);
		
		void on_output_select
		(
			void
		);
		
		void on_build_project
		(
			void
		);
		
		void on_varenv_assistant_apply
		(
			Glib::RefPtr<Gtk::ListStore> store
		);
		
		void on_static_assistant_apply
		(
			Glib::RefPtr<Gtk::ListStore> store
		);
};

#endif
