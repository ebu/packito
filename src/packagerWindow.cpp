/*!
 * \project_name AutoPackager
 * \file packagerWindow.cpp
 * \brief 
 * \details 
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 23 may 2013
 *
 * This software is published in MPLv2.0
 *
 */



#include "packagerWindow.hpp"

// class constructor and destructor

PackagerWindow::PackagerWindow
(
	BaseObjectType* cobject, 
	const Glib::RefPtr<Gtk::Builder>& refGlade
) 
	: 
		Gtk::Window(cobject),
		m_refGlade(refGlade)
{
	// set glade references
	refGladeMenu();
	refGladeButtons();
	refGladeWidgets();

	// connect the signals
	connectSignalClicked(); // clicked 
	connectSignalActivate(); // activate
	connectSignalEvent(); // button press/release
	
	// init listStores
	initListStores();
	
	// init packagerEngine	
	engine = new PackagerEngine();
	
}

PackagerWindow::~PackagerWindow
(
	void
)
{
}


void PackagerWindow::refGladeMenu
(
	void
) 
{
	// menu 
	m_refGlade->get_widget
	(
		"AutoPackagerMenuItemNew", 
		AutoPackagerMenuItemNew
	);
	m_refGlade->get_widget
	(
		"AutoPackagerMenuItemOpen", 
		AutoPackagerMenuItemOpen
	);
	m_refGlade->get_widget
	(
		"AutoPackagerMenuItemSave", 
		AutoPackagerMenuItemSave
	);
	m_refGlade->get_widget
	(
		"AutoPackagerMenuItemSaveas", 
		AutoPackagerMenuItemSaveas
	);
	m_refGlade->get_widget
	(
		"AutoPackagerMenuItemQuit", 
		AutoPackagerMenuItemQuit
	);
	m_refGlade->get_widget
	(
		"AutoPackagerMenuItemAbout", 
		AutoPackagerMenuItemAbout
	);
}

void PackagerWindow::refGladeButtons
(
	void
) 
{
	// button project description	
	m_refGlade->get_widget
	(
		"ProjectDoxygenOpenButton", 
		ProjectDoxygenOpenButton
	);
	m_refGlade->get_widget
	(
		"ProjectOutputOpenButton", 
		ProjectOutputOpenButton
	);
	m_refGlade->get_widget
	(
		"ProjectNextButton", 
		ProjectNextButton
	);
	// buttons project sources
	m_refGlade->get_widget
	(
		"SourceSrcOpenButton", 
		SourceSrcOpenButton
	);
	m_refGlade->get_widget
	(
		"SourceImgOpenButton", 
		SourceImgOpenButton
	);
	m_refGlade->get_widget
	(
		"SourceGladeOpenButton", 
		SourceGladeOpenButton
	);
	m_refGlade->get_widget
	(
		"SourceOthersOpenButton", 
		SourceOthersOpenButton
	);
	m_refGlade->get_widget
	(
		"SourceRemoveSrcButton", 
		SourceRemoveSrcButton
	);
	m_refGlade->get_widget
	(
		"SourceRemoveImgButton", 
		SourceRemoveImgButton
	);
	m_refGlade->get_widget
	(
		"SourceRemoveGladeButton", 
		SourceRemoveGladeButton
	);
	m_refGlade->get_widget
	(
		"SourceRemoveOthersButton", 
		SourceRemoveOthersButton
	);
	m_refGlade->get_widget
	(
		"SourcePreviousButton", 
		SourcePreviousButton
	);
	m_refGlade->get_widget
	(
		"SourceNextButton", 
		SourceNextButton
	);
	// buttons project dependencies
	m_refGlade->get_widget
	(
		"DependencyStaticOpenButton", 
		DependencyStaticOpenButton
	);
	m_refGlade->get_widget
	(
		"DependencyDynamicOpenButton", 
		DependencyDynamicOpenButton
	);
	m_refGlade->get_widget
	(
		"DependencyIncludeOpenButton", 
		DependencyIncludeOpenButton
	);
	m_refGlade->get_widget
	(
		"DependencyRemoveStaticButton", 
		DependencyRemoveStaticButton
	);
	m_refGlade->get_widget
	(
		"DependencyRemoveDynamicButton", 
		DependencyRemoveDynamicButton
	);
	m_refGlade->get_widget
	(
		"DependencyRemoveIncludeButton", 
		DependencyRemoveIncludeButton
	);
	m_refGlade->get_widget
	(
		"DependencyPreviousButton", 
		DependencyPreviousButton
	);
	m_refGlade->get_widget
	(
		"DependencyNextButton", 
		DependencyNextButton
	);
	// buttons project environment
	m_refGlade->get_widget
	(
		"EnvironmentVariableOpenButton", 
		EnvironmentVariableOpenButton
	);
	m_refGlade->get_widget
	(
		"EnvironmentRemoveVariableButton", 
		EnvironmentRemoveVariableButton
	);
	m_refGlade->get_widget
	(
		"EnvironmentPreviousButton", 
		EnvironmentPreviousButton
	);
	m_refGlade->get_widget
	(
		"EnvironmentNextButton", 
		EnvironmentNextButton
	);
}

void PackagerWindow::refGladeWidgets
(
	void
) 
{
	// box
	m_refGlade->get_widget
	(
		"EmptyBox",
		EmptyBox
	);
	m_refGlade->get_widget
	(
		"ProjectBox",
		ProjectBox
	);
	m_refGlade->get_widget
	(
		"SourceBox",
		SourceBox
	);
	m_refGlade->get_widget
	(
		"DependencyBox",
		DependencyBox
	);
	m_refGlade->get_widget
	(
		"EnvironmentBox",
		EnvironmentBox
	);
	m_refGlade->get_widget
	(
		"EmptyControllerBox",
		EmptyControllerBox
	);
	m_refGlade->get_widget
	(
		"ProjectControllerBox",
		ProjectControllerBox
	);
	m_refGlade->get_widget
	(
		"SourceControllerBox",
		SourceControllerBox
	);
	m_refGlade->get_widget
	(
		"DependencyControllerBox",
		DependencyControllerBox
	);
	m_refGlade->get_widget
	(
		"EnvironmentControllerBox",
		EnvironmentControllerBox
	);
	// scrolled window
	m_refGlade->get_widget
	(
		"SourceScrolledSrc",
		SourceScrolledSrc
	);
	m_refGlade->get_widget
	(
		"SourceScrolledImg",
		SourceScrolledImg
	);
	m_refGlade->get_widget
	(
		"SourceScrolledGlade",
		SourceScrolledGlade
	);
	m_refGlade->get_widget
	(
		"SourceScrolledOthers",
		SourceScrolledOthers
	);
	m_refGlade->get_widget
	(
		"DependencyScrolledStatic",
		DependencyScrolledStatic
	);
	m_refGlade->get_widget
	(
		"DependencyScrolledDynamic",
		DependencyScrolledDynamic
	);
	m_refGlade->get_widget
	(
		"DependencyScrolledInclude",
		DependencyScrolledInclude
	);
	m_refGlade->get_widget
	(
		"EnvironmentScrolledVariable",
		EnvironmentScrolledVariable
	);
	// RadioButtons
	m_refGlade->get_widget
	(
		"ProjectLanguageC", 
		ProjectLanguageC
	);
	m_refGlade->get_widget
	(
		"ProjectLanguageCPP", 
		ProjectLanguageCPP
	);
	// eventbox
	m_refGlade->get_widget
	(
		"WelcomeMsgEventBox",
		WelcomeMsgEventBox
	);
	// label
	m_refGlade->get_widget
	(
		"EmptyTitleLabel",
		EmptyTitleLabel
	);
	m_refGlade->get_widget
	(
		"ProjectTitleLabel",
		ProjectTitleLabel
	);
	m_refGlade->get_widget
	(
		"SourceTitleLabel",
		SourceTitleLabel
	);
	m_refGlade->get_widget
	(
		"DependencyTitleLabel",
		DependencyTitleLabel
	);
	m_refGlade->get_widget
	(
		"EnvironmentTitleLabel",
		EnvironmentTitleLabel
	);
	// entry
	m_refGlade->get_widget
	(
		"ProjectNameEntry",
		ProjectNameEntry
	);
	m_refGlade->get_widget
	(
		"ProjectVersionEntry",
		ProjectVersionEntry
	);
	m_refGlade->get_widget
	(
		"ProjectTarballEntry",
		ProjectTarballEntry
	);
	m_refGlade->get_widget
	(
		"ProjectURLEntry",
		ProjectURLEntry
	);
	m_refGlade->get_widget
	(
		"ProjectBugReportEntry",
		ProjectBugReportEntry
	);
	m_refGlade->get_widget
	(
		"ProjectDoxygenEntry",
		ProjectDoxygenEntry
	);
	m_refGlade->get_widget
	(
		"ProjectOutputEntry",
		ProjectOutputEntry
	);
	m_refGlade->get_widget
	(
		"EnvironmentCompilerFlagsEntry",
		EnvironmentCompilerFlagsEntry
	);
	m_refGlade->get_widget
	(
		"EnvironmentArgumentsEntry",
		EnvironmentArgumentsEntry
	);
}

void PackagerWindow::connectSignalActivate
(
	void
) 
{

	// Menubar 
	// _File
	AutoPackagerMenuItemOpen->signal_activate().connect
	(
		sigc::mem_fun
		(
			*this,
			&PackagerWindow::on_AutoPackagerMenuItemOpen_activate
		)
	);
	AutoPackagerMenuItemNew->signal_activate().connect
	(
		sigc::mem_fun
		(
			*this,
			&PackagerWindow::on_AutoPackagerMenuItemNew_activate
		)
	);
	AutoPackagerMenuItemSave->signal_activate().connect
	(
		sigc::mem_fun
		(
			*this,
			&PackagerWindow::on_AutoPackagerMenuItemSave_activate
		)
	);
	AutoPackagerMenuItemSaveas->signal_activate().connect
	(
		sigc::mem_fun
		(
			*this,
			&PackagerWindow::on_AutoPackagerMenuItemSaveas_activate
		)
	);
	AutoPackagerMenuItemQuit->signal_activate().connect
	(
		sigc::mem_fun
		(
			*this,
			&PackagerWindow::on_AutoPackagerMenuItemQuit_activate
		)
	);
	// _Help
	AutoPackagerMenuItemAbout->signal_activate().connect
	(
		sigc::mem_fun
		(
			*this,
			&PackagerWindow::on_AutoPackagerMenuItemAbout_activate
		)
	);
}

void PackagerWindow::connectSignalClicked
(
	void
) 
{

	ProjectDoxygenOpenButton->signal_clicked().connect
	(
		sigc::mem_fun
		(
			*this, 
			&PackagerWindow::on_doxygen_open
		)
	);
	ProjectOutputOpenButton->signal_clicked().connect
	(
		sigc::mem_fun
		(
			*this, 
			&PackagerWindow::on_output_select
		)
	);
	ProjectNextButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::changePage
			),
			false
		)
	);
	
	SourceNextButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::changePage
			),
			false
		)
	);
	
	SourcePreviousButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::changePage
			),
			true
		)
	);
	
	DependencyNextButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::changePage
			),
			false
		)
	);
	
	DependencyPreviousButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::changePage
			),
			true
		)
	);
	EnvironmentNextButton->signal_clicked().connect
	(
		sigc::mem_fun
		(
			*this, 
			&PackagerWindow::on_build_project
		)
	);
	
	EnvironmentPreviousButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::changePage
			),
			true
		)
	);	

}

void PackagerWindow::connectSignalEvent
(
	void
) 
{
	WelcomeMsgEventBox->signal_button_press_event().connect
	(
		sigc::mem_fun
		(
			*this, 
			&PackagerWindow::on_AutoPackagerEventNew_press
		)
	);
}

void PackagerWindow::initListStores
(
	void
)
{

	Gtk::Button * actionBtn[14] =
	{
		SourceSrcOpenButton,	SourceImgOpenButton,	SourceGladeOpenButton,
		SourceOthersOpenButton, DependencyStaticOpenButton,
		DependencyDynamicOpenButton, DependencyIncludeOpenButton,
		SourceRemoveSrcButton, SourceRemoveImgButton, SourceRemoveGladeButton,
		SourceRemoveOthersButton, DependencyRemoveStaticButton,
		DependencyRemoveDynamicButton, DependencyRemoveIncludeButton
	};
	
	Gtk::TreeView * trees[7] = 
	{
		sourceTreeview = manage(new Gtk::TreeView()),
		imageTreeview = manage(new Gtk::TreeView()),
		gladeTreeview = manage(new Gtk::TreeView()),
		othersTreeview = manage(new Gtk::TreeView()),
		staticTreeview = manage(new Gtk::TreeView()),
		dynamicTreeview = manage(new Gtk::TreeView()),
		includeTreeview = manage(new Gtk::TreeView())
	};
	
	Glib::RefPtr<Gtk::ListStore> store[7] =
	{
		sourceStore, imageStore, gladeStore, othersStore,
		staticStore, dynamicStore, includeStore
	};
	
	std::string filechooserTitle[7] =
	{
		"Select the project source files",
		"Select the images of the project",
		"Select the Glade files of the project",
		"Select the other files of the project",
		"Select the static libraries of the project",
		"Select the dynamic libraries of the project",
		"Select the others #includes of the project"
	};
	
	unsigned int filechooserMimeType[7] = {1,2,3,4,4,4,4};
	
	Glib::RefPtr<Gtk::TreeSelection> selection[7] =
	{
		sourceSelection, imageSelection, gladeSelection, othersSelection,
		staticSelection, dynamicSelection, includeSelection
	};
	
	Gtk::ScrolledWindow * scrolled[7] =
	{
		SourceScrolledSrc, SourceScrolledImg, SourceScrolledGlade,
		SourceScrolledOthers, DependencyScrolledStatic,	
		DependencyScrolledDynamic, DependencyScrolledInclude
	};
		
	for (unsigned int i=0;i<7;i++) 
	{
		store[i] = Gtk::ListStore::create(fColumns);
		// set the data model
		trees[i]->set_model(store[i]);
		//Add the TreeView's view columns
		trees[i]->append_column
		(
			"ID", fColumns.fileidcol
		);
		trees[i]->append_column
		(
			"File", fColumns.filepathcol
		);
		trees[i]->append_column
		(
			"", fColumns.filecellbgcolorcol
		);
	
		Gtk::TreeView::Column* pColumn;
		for(guint j = 2; j < 3; j++)
		{ 
			pColumn = trees[i]->get_column(j);
			Gtk::CellRenderer* cellRenderer = trees[i]->get_column_cell_renderer(j);
			pColumn->add_attribute
			(
				cellRenderer->property_cell_background(), 
				fColumns.filecellbgcolorcol
			);
			pColumn->set_reorderable();
		}
		// hide some columns
		pColumn = trees[i]->get_column(2);
		pColumn->set_visible(false);
		//All the items to be reordered with drag-and-drop
		// Set the visibility state of the headers. 
		trees[i]->set_headers_visible(true);
		// Allow the column title buttons to be clicked
		trees[i]->set_headers_clickable(true);
		// enable the hover effect
		trees[i]->set_hover_selection(true);
		// Resize all columns to their optimal width. 
		trees[i]->columns_autosize();
		// all element are reordorable
		trees[i]->set_reorderable();
		trees[i]->set_rules_hint();
		trees[i]->show();
		scrolled[i]->add(*(trees[i]));
		
		selection[i] = trees[i]->get_selection();
		selection[i]->set_mode(Gtk::SELECTION_MULTIPLE);
		actionBtn[i]->signal_clicked().connect
		(
			sigc::bind
			(
				sigc::mem_fun
				(
					*this,
					&PackagerWindow::on_addfile_clicked
				),
				filechooserTitle[i],
				filechooserMimeType[i],
				store[i]
			)
		);
		actionBtn[i+7]->signal_clicked().connect
		(
			sigc::bind
			(
				sigc::mem_fun
				(
					*this,
					&PackagerWindow::on_remove_clicked
				),
				selection[i]
			)
		);
		
	}
	////////////////////////////////////////////////////
	/*Gtk::Button * EnvironmentVariableOpenButton; 
	Gtk::Button * EnvironmentRemoveVariableButton;*/
	///////////////
	varenvTreeview = manage(new Gtk::TreeView());
	varenvStore = Gtk::ListStore::create(eColumns);
	// set the data model
	varenvTreeview->set_model(varenvStore);
	//Add the TreeView's view columns
	varenvTreeview->append_column
	(
		"ID", 
		eColumns.variableenvidcol
	);
	varenvTreeview->append_column
	(
		"Variable name", 
		eColumns.variableenvnamecol
	);
	varenvTreeview->append_column
	(
		"Variable value", 
		eColumns.variableenvvaluecol
	);
	varenvTreeview->append_column
	(
		"", 
		eColumns.variableenvcellbgcolorcol
	);

	Gtk::TreeView::Column* pColumn;
	for(guint i = 3; i < 4; i++)
	{ 
		pColumn = varenvTreeview->get_column(i);
		Gtk::CellRenderer* cellRenderer = varenvTreeview->get_column_cell_renderer(i);
		pColumn->add_attribute
		(
			cellRenderer->property_cell_background(), 
			eColumns.variableenvcellbgcolorcol
		);
		pColumn->set_reorderable();
	}
	// hide some columns
	pColumn = varenvTreeview->get_column(3);
	pColumn->set_visible(false);
	//All the items to be reordered with drag-and-drop
	// Set the visibility state of the headers. 
	varenvTreeview->set_headers_visible(true);
	// Allow the column title buttons to be clicked
	varenvTreeview->set_headers_clickable(true);
	// enable the hover effect
	varenvTreeview->set_hover_selection(true);
	// Resize all columns to their optimal width. 
	varenvTreeview->columns_autosize();
	// all element are reordorable
	varenvTreeview->set_reorderable();
	varenvTreeview->set_rules_hint();
	varenvTreeview->show();
	EnvironmentScrolledVariable->add(*varenvTreeview);
	
	
	EnvironmentVariableOpenButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::on_add_env_var_clicked
			),
			"Add a new environment variable",
			varenvStore
		)
	);
	
}

void PackagerWindow::on_AutoPackagerMenuItemOpen_activate
(
	void
)
{
	// instanciate a new filechooser
	genericFilechooserWindow * FC = new genericFilechooserWindow
	(
		*this,
		"Open an AutoPackager project...",
		Gtk::FILE_CHOOSER_ACTION_OPEN,
		Glib::get_home_dir(),
		false
	);
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
		load_configuration(FC->getURIToFile().c_str());
		engine->setProjectPath(FC->getURIToFile());
		updatePage(1);
	}
	
	delete FC;
}

void PackagerWindow::load_configuration
(
	std::string configfile
)
{
	// prepare the input stream
	std::ifstream file(configfile);
	// read configuration file
	std::string content
	(
		std::istreambuf_iterator<char>(file), //start
		(std::istreambuf_iterator<char>()) //eof
	);
	// locate beginning of the string
	size_t nSearchOffset = 0;
	// locate the first carriage return
	size_t nSubstringOffset = content.find ("\n", 0);
	//
	std::string xmlheader("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
	bool validxmlheader = false;
	std::stack<std::string> tagStack;
	std::string tag[20] = {"autopackager", "projectname", "projectversion", "projectlanguage", "projecttarball", "projecturl", "projectbug", "projectdoxygen", "projectdirectory", "projectsources", "projectimages", "projectglade", "projectothers", "projectstaticlib", "projectdynamiclib", "projectsourcelib", "projectcompilerflags", "projectcompilerarguments", "projectvariables", "autopackager"};
	Gtk::Entry * Entries[18] = 
	{ 
		NULL, ProjectNameEntry, ProjectVersionEntry, NULL,
		ProjectTarballEntry, ProjectURLEntry, ProjectBugReportEntry, 
		ProjectDoxygenEntry, ProjectOutputEntry, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL,
		EnvironmentCompilerFlagsEntry, EnvironmentArgumentsEntry
	};
	Gtk::TreeView * trees[7] = 
	{
		sourceTreeview,
		imageTreeview,
		gladeTreeview,
		othersTreeview,
		staticTreeview,
		dynamicTreeview,
		includeTreeview
	};
	unsigned int tag_cpt = 0;
	// if not EOF, loop
	while (nSubstringOffset != std::string::npos)
	{
		// if next carriage return different of next beginning
		if (nSubstringOffset != nSearchOffset) 
		{
			// catch line
			std::string strline = content.substr(nSearchOffset,nSubstringOffset-nSearchOffset);// test if the xml is valid
			if (!validxmlheader and xmlheader == strline) 
			{
				validxmlheader = !validxmlheader;
			}
			else
			{
				if (strline.find("<"+tag[tag_cpt]+">")!=std::string::npos and strline.find("</"+tag[tag_cpt]+">")!=std::string::npos)
			 	{
			 		if (Entries[tag_cpt] != NULL) {
				 		Entries[tag_cpt]->set_text(strline.substr(tag[tag_cpt].size()+2, (strline.size()-(2*(tag[tag_cpt].size()+2)))-1));
				 	} else {
				 		if(tag[tag_cpt] == "projectlanguage") 
				 		{
				 			if (strline.substr(tag[tag_cpt].size()+2, (strline.size()-(2*(tag[tag_cpt].size()+2)))-1) == "C") {
				 				ProjectLanguageC->set_active(true);
				 			} else {
				 				ProjectLanguageCPP->set_active(true);
				 			}
				 		}
				 	}	 		
			 		tag_cpt++;
				}
				else if (strline.find("<"+tag[tag_cpt]+">")!=std::string::npos or strline.find("</"+tag[tag_cpt]+">")!=std::string::npos)
			 	{
			 		if (tagStack.empty()) {
			 			tagStack.push(tag[tag_cpt]);
			 			tag_cpt++;
			 		} else {
			 			if (tagStack.top() == tag[tag_cpt]) {
			 				 tagStack.pop();
			 				 tag_cpt++;
			 			} else {
			 				tagStack.push(tag[tag_cpt]);
			 			}
			 		}
				}
				else if (strline.find("</"+tagStack.top()+">")!=std::string::npos)
				{
					 tagStack.pop();
					 tag_cpt++;
				}
				else if (tagStack.top() == tag[tag_cpt])
				{
					 if (strline.find("<item>")!=std::string::npos and strline.find("</item>")!=std::string::npos) 
					 {
					 	Glib::RefPtr<Gtk::ListStore> store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(trees[tag_cpt-9]->get_model());
						Gtk::TreeModel::Row row = *(store->append());
						row[fColumns.fileidcol] = (store->children().size());
						row[fColumns.filepathcol] = strline.substr(6, (strline.size()-13));
						row[fColumns.filecellbgcolorcol] = (row[fColumns.fileidcol]%2==0)?COLOREVEN:COLORODD;
					 }
					 if (strline.find("<name>")!=std::string::npos and strline.find("</name>")!=std::string::npos) 
					 {
					 	Glib::RefPtr<Gtk::ListStore> store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(varenvTreeview->get_model());
						Gtk::TreeModel::Row row = *(store->append());
						row[eColumns.variableenvidcol] = (store->children().size());
						row[eColumns.variableenvnamecol] = strline.substr(6, (strline.size()-13));
						nSearchOffset = nSubstringOffset + 1;
						nSubstringOffset = content.find
						(
							"\n", 
							nSearchOffset
						);
						strline = content.substr(nSearchOffset,nSubstringOffset-nSearchOffset);
						row[eColumns.variableenvvaluecol] = strline.substr(7, (strline.size()-15));
						row[eColumns.variableenvcellbgcolorcol] = (row[eColumns.variableenvidcol]%2==0)?COLOREVEN:COLORODD;
					 }
				}
				else
				{
					std::cout<<"It's not an autopackager configuration file"<<std::endl;
					break;
				}
			}
				
				
		}
		// Make the 'find' function search the next character onwards
		nSearchOffset = nSubstringOffset + 1;
		nSubstringOffset = content.find
		(
			"\n", 
			nSearchOffset
		);
			
		if (!validxmlheader) 
		{
			std::cout<<"It's not a valid xml file"<<std::endl;
			break;
		}
	}
}

void PackagerWindow::on_AutoPackagerMenuItemNew_activate
(
	void
)
{
	// instanciate a new filechooser
	genericFilechooserWindow * FC = new genericFilechooserWindow
	(
		*this,
		"Create a new AutoPackager project...",
		Gtk::FILE_CHOOSER_ACTION_SAVE,
		Glib::get_home_dir(),
		false
	);
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
		engine->setProjectPath(FC->getPathToSave());
		updatePage(1);
	}
	
	delete FC;
}

bool PackagerWindow::on_AutoPackagerEventNew_press
(
	GdkEventButton* /*event*/
)
{
	// instanciate a new filechooser
	genericFilechooserWindow * FC = new genericFilechooserWindow
	(
		*this,
		"Create a new AutoPackager project...",
		Gtk::FILE_CHOOSER_ACTION_SAVE,
		Glib::get_home_dir(),
		false
	);
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
		engine->setProjectPath(FC->getPathToSave());
		updatePage(1);
	}
	
	delete FC;
	return true;
}

void PackagerWindow::on_AutoPackagerMenuItemSave_activate
(
	void
)
{
	std::ofstream myfile;
	myfile.open (engine->getProjectPath());
	myfile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<autopackager>\n";
	myfile << "<projectname>"<< ProjectNameEntry->get_text() <<"</projectname>\n";
	myfile << "<projectversion>"<< ProjectVersionEntry->get_text() <<"</projectversion>\n";
	myfile << "<projectlanguage>"<< ((ProjectLanguageC->get_active())? "C" : "C++" ) <<"</projectlanguage>\n";
	myfile << "<projecttarball>"<< ProjectTarballEntry->get_text() <<"</projecttarball>\n";
	myfile << "<projecturl>"<< ProjectURLEntry->get_text() <<"</projecturl>\n";
	myfile << "<projectbug>"<< ProjectBugReportEntry->get_text() <<"</projectbug>\n";
	myfile << "<projectdoxygen>"<< ProjectDoxygenEntry->get_text() <<"</projectdoxygen>\n";
	myfile << "<projectdirectory>"<< ProjectOutputEntry->get_text() <<"</projectdirectory>\n";
	// sources
	Glib::RefPtr<Gtk::TreeModel> model = sourceTreeview->get_model();
	Glib::RefPtr<Gtk::ListStore> store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectsources>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectsources>\n";
	// image
	model = imageTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectimages>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectimages>\n";
	// glade
	model = gladeTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectglade>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectglade>\n";
	// others
	model = othersTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
		myfile << "<projectothers>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectothers>\n";
	// static library
	model = staticTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectstaticlib>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectstaticlib>\n";
	// dynamic library
	model = dynamicTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectdynamiclib>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectdynamiclib>\n";
	// includes
	model = includeTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectsourcelib>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectsourcelib>\n";
	myfile << "<projectcompilerflags>"<< EnvironmentCompilerFlagsEntry->get_text() <<"</projectcompilerflags>\n";
	myfile << "<projectcompilerarguments>"<< EnvironmentArgumentsEntry->get_text() <<"</projectcompilerarguments>\n";
	// environment variable
	model = varenvTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectvariables>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<set>\n<name>"
		<<(std::string)((*row)[eColumns.variableenvnamecol]) 
		<<"</name>\n<value>"
		<< (std::string)((*row)[eColumns.variableenvvaluecol])
		<<"</value>\n</set>\n";
	}
	myfile << "</projectvariables>\n";
	
	myfile << "</autopackager>";
	myfile.close();
}

void PackagerWindow::on_AutoPackagerMenuItemSaveas_activate
(
	void
)
{
	// instanciate a new filechooser
	genericFilechooserWindow * FC = new genericFilechooserWindow
	(
		*this,
		"Save the current project as...",
		Gtk::FILE_CHOOSER_ACTION_SAVE,
		Glib::get_home_dir(),
		false
	);
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
		engine->setProjectPath(FC->getPathToSave());
	}
	
	delete FC;
}

void PackagerWindow::on_AutoPackagerMenuItemQuit_activate
(
	void
)
{
	hide();
}

void PackagerWindow::on_AutoPackagerMenuItemAbout_activate
(
	void
)
{
	std::cout<<"display about dialog"<<std::endl;
}

void PackagerWindow::updatePage
(
	unsigned int nextPage
)
{
		Gtk::Box * pageBox[10] = 
		{
			EmptyBox,  // central features
			ProjectBox,
			SourceBox,
			DependencyBox,
			EnvironmentBox,
			EmptyControllerBox, // bottom controllers
			ProjectControllerBox,
			SourceControllerBox,
			DependencyControllerBox,
			EnvironmentControllerBox
		};
		
		Gtk::Label * titleLabel[5] = 
		{
			EmptyTitleLabel,
			ProjectTitleLabel,
			SourceTitleLabel,
			DependencyTitleLabel,
			EnvironmentTitleLabel
		};
		unsigned int page = engine->getCurrentPage();
		// hide previous
		titleLabel[page]->hide();
		pageBox[page]->hide();
		pageBox[page+5]->hide();
		// show current
		titleLabel[nextPage]->show();
		pageBox[nextPage]->show();
		pageBox[nextPage+5]->show();
		// update
		engine->setCurrentPage(nextPage);
}

void PackagerWindow::changePage
(
	bool back
)
{
	updatePage(((back)?engine->getCurrentPage()-1:engine->getCurrentPage()+1));
}

void PackagerWindow::on_addfile_clicked
(
	std::string title,
	unsigned int mime,
	Glib::RefPtr<Gtk::ListStore> store
)
{
	// instanciate a new filechooser
	genericFilechooserWindow * FC = new genericFilechooserWindow
	(
		*this,
		title,
		Gtk::FILE_CHOOSER_ACTION_OPEN,
		Glib::get_home_dir(),
		true,
		mime
	);
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
		std::vector<Glib::ustring> files = FC->getURIToFiles();
		for (unsigned int i=0; i<files.size(); i++)
		{
			Gtk::TreeModel::Row row = *(store->append());
			row[fColumns.fileidcol] = (store->children().size());
			row[fColumns.filepathcol] = genericFeatures::removePrefix(files.at(i),"file://");
			row[fColumns.filecellbgcolorcol] = (row[fColumns.fileidcol]%2==0)?COLOREVEN:COLORODD;
		}
	}
	
	delete FC;
}


void PackagerWindow::on_add_env_var_clicked
(
	std::string title,
	Glib::RefPtr<Gtk::ListStore> store
)
{
	// instanciate a new assistant
	std::vector<std::string> tmpLabel;
	std::vector<std::string> tmpPlaceholder;
	tmpLabel.push_back(" Variable name :");
	tmpLabel.push_back("Variable value :");
	tmpPlaceholder.push_back("Set the variable's name");
	tmpPlaceholder.push_back("Set the variable's value");
	
	delete GA;
	GA = new GenericAssistant
	(
		title,
		tmpLabel,
		tmpPlaceholder,
		true
	);
	GA->show();
	GA->signal_apply().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this,
				&PackagerWindow::on_varenv_assistant_apply
			),
			varenvStore
		)
	);
	
	tmpLabel.clear();
	tmpPlaceholder.clear();
}

void PackagerWindow::on_remove_clicked
(
	Glib::RefPtr<Gtk::TreeSelection> selection
)
{
	selection->selected_foreach_iter
	(
		sigc::mem_fun
		(
			*this, 
			&PackagerWindow::selected_row_callback
		)
	);
}

void PackagerWindow::selected_row_callback
(
	const Gtk::TreeModel::iterator& iter
)
{
	Gtk::TreeModel::Row row = *iter;
}

void PackagerWindow::on_doxygen_open
(
	void
)
{
	// instanciate a new filechooser
	genericFilechooserWindow * FC = new genericFilechooserWindow
	(
		*this,
		"Select the Doxygen configuration file of the project",
		Gtk::FILE_CHOOSER_ACTION_OPEN,
		Glib::get_home_dir(),
		false,
		5
	);
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
		ProjectDoxygenEntry->set_text(FC->getURIToFile());
	}
	
	delete FC;
}

void PackagerWindow::on_output_select
(
	void
)
{
	// instanciate a new filechooser
	genericFilechooserWindow * FC = new genericFilechooserWindow
	(
		*this,
		"Select the output directory where the final project will be built",
		Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER,
		Glib::get_home_dir(),
		false,
		6
	);
	
	if (FC->getResponse() == Gtk::RESPONSE_OK) 
	{
		ProjectOutputEntry->set_text(FC->getURIToFile()+"/");
	}
	
	delete FC;
}

void PackagerWindow::on_build_project
(
	void
)
{
	std::string home(ProjectOutputEntry->get_text()+ProjectNameEntry->get_text());
	std::string folders[4] = 
	{
		home, home+"/m4", home+"/src", home+"/config"
	};
	std::string basicfiles[5] = 
	{
		"AUTHORS" ,"COPYING", "ChangeLog", "NEWS", "README"
	};
	Gtk::TreeView * trees[4] = 
	{
		sourceTreeview, imageTreeview, gladeTreeview, othersTreeview
	};
	mode_t umask = S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH;
	// create directories
	for (unsigned int i = 0; i<4; i++) 
	{
		#ifdef __linux__
			 mkdir(folders[i].c_str(), umask); 
		#else
			 _mkdir(folders[i].c_str());
		#endif
	}
	// create basic files
	for (unsigned int i = 0; i<5; i++)
	{
		std::ofstream myfile;
		myfile.open (home+"/"+basicfiles[i]);
		myfile.close();
	}
	std::string ac_config_srcdir;
	std::string compilable_src;
	// copy project files
	for (unsigned int i = 0;i<4;i++) 
	{
		Glib::RefPtr<Gtk::TreeModel> model = trees[i]->get_model();
		Glib::RefPtr<Gtk::ListStore> store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
		for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
				row != store->children().end(); row++)
		{
			genericFeatures::copyFile(
				(std::string)((*row)[fColumns.filepathcol]),
				folders[2]+"/"+genericFeatures::removeSuffix((std::string)((*row)[fColumns.filepathcol]),"/")
			); 
			ac_config_srcdir =  ac_config_srcdir+((ac_config_srcdir.size()>0)? " ":"")+"src/"+genericFeatures::removeSuffix((std::string)((*row)[fColumns.filepathcol]),"/");
			if (i == 0) 
			{
				compilable_src =  compilable_src+((compilable_src.size()>0)? " ":"")+genericFeatures::removeSuffix((std::string)((*row)[fColumns.filepathcol]),"/");
			}
		}
	}
	// root Makefile.am
	std::ofstream myfile;
	myfile.open (home+"/Makefile.am");
	myfile << "ACLOCAL_AMFLAGS = -I m4\n";
	myfile << "SUBDIRS = src\n";
	myfile << "EXTRA_DIST = autogen.sh\n";
	myfile << "CLEANFILES = *~";
	myfile.close();
	// autogen.sh
	myfile.open (home+"/autogen.sh");
	myfile << "#!/bin/sh\n";
	myfile << "autoreconf --force --install -I config -I m4";
	myfile.close();
	// configure.ac
	myfile.open (home+"/configure.ac");
	myfile << "AC_PREREQ(2.60)\n";
	if (ProjectNameEntry->get_text() != "") {
		myfile << ("AC_INIT("+((std::string)ProjectNameEntry->get_text()));
	}
	if (ProjectVersionEntry->get_text() != "") {
		myfile << (", "+((std::string)ProjectVersionEntry->get_text()));
	}
	if (ProjectBugReportEntry->get_text() != "") {
		myfile << (", "+((std::string)ProjectBugReportEntry->get_text()));
	}
	myfile << ")\n";
	myfile << "AC_CONFIG_AUX_DIR(config)\n";
	//myfile << "AC_CONFIG_SRCDIR("+ac_config_srcdir+")\n";
	myfile << "\n";
	myfile << "AM_INIT_AUTOMAKE([1.9.6 -W -Wall no-define foreign])\n";
	myfile << "\n";
	myfile << "AC_PROG_C"+((std::string)((ProjectLanguageC->get_active())?"C\n":"XX\n"));
	myfile << "AC_LANG_C"+((std::string)((ProjectLanguageC->get_active())?"\n":"PLUSPLUS\n"));
	myfile << "AC_PROG_MAKE_SET\n";
	myfile << "AC_PROG_INSTALL\n";
	myfile << "AC_PROG_LIBTOOL\n";
	myfile << "\n";
	myfile << "PKG_CHECK_MODULES(GTKMM, [gtkmm-3.0 >= 3.0.0])\n";
	myfile << "PKG_CHECK_MODULES(GDKMM, [gdkmm-3.0 >= 3.0.0])\n";
	myfile << "AC_HEADER_STDC\nAC_CHECK_HEADERS([ctime cstring cstdio cstdlib])";
	myfile << "\n";
	myfile << "AC_OUTPUT(Makefile src/Makefile)";
	myfile.close();
	// src Makefile.am
	myfile.open (folders[2]+"/Makefile.am");
	myfile << "bin_PROGRAMS ="+((std::string)ProjectNameEntry->get_text())+"\n";
	myfile << ((std::string)ProjectNameEntry->get_text())+"_SOURCES = "+compilable_src+"\n";
	myfile << "\n";
	myfile << ((std::string)ProjectNameEntry->get_text())+"_CPPFLAGS = @GTKMM_CFLAGS@ @GDKMM_CFLAGS@\n";
	myfile << ((std::string)ProjectNameEntry->get_text())+"_LDADD = @GTKMM_LIBS@ @GDKMM_CFLAGS@\n";
	myfile << ((std::string)ProjectNameEntry->get_text())+"_C"+((std::string)((ProjectLanguageC->get_active())?"":"XX"))+"FLAGS = " + ((std::string)EnvironmentCompilerFlagsEntry->get_text());
	myfile << "\n";
	myfile << "CLEANFILES = *~";
	myfile.close();
}

void PackagerWindow::on_varenv_assistant_apply
(
	Glib::RefPtr<Gtk::ListStore> store
)
{
	GA->hide();
	std::vector<std::string> tmp = GA->getResponse();
	Gtk::TreeModel::Row row = *(store->append());
	row[eColumns.variableenvidcol] = (store->children().size());
	row[eColumns.variableenvnamecol] = tmp.at(0);
	row[eColumns.variableenvvaluecol] = tmp.at(1);
	row[eColumns.variableenvcellbgcolorcol] = (row[eColumns.variableenvidcol]%2==0)?COLOREVEN:COLORODD;
}
