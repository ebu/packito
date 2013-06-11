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
		"DependencyIOpenButton", 
		DependencyIOpenButton
	);
	m_refGlade->get_widget
	(
		"DependencyLOpenButton", 
		DependencyLOpenButton
	);
	m_refGlade->get_widget
	(
		"DependencylOpenButton", 
		DependencylOpenButton
	);
	m_refGlade->get_widget
	(
		"EnvironmentPKGOpenButton", 
		EnvironmentPKGOpenButton
	);
	m_refGlade->get_widget
	(
		"DependencyRemoveIButton", 
		DependencyRemoveIButton
	);
	m_refGlade->get_widget
	(
		"DependencyRemoveLButton", 
		DependencyRemoveLButton
	);
	m_refGlade->get_widget
	(
		"DependencyRemovelButton", 
		DependencyRemovelButton
	);
	m_refGlade->get_widget
	(
		"EnvironmentRemovePKGButton", 
		EnvironmentRemovePKGButton
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
		"DependencyScrolledI",
		DependencyScrolledI
	);
	m_refGlade->get_widget
	(
		"DependencyScrolledL",
		DependencyScrolledL
	);
	m_refGlade->get_widget
	(
		"DependencyScrolledl",
		DependencyScrolledl
	);
	m_refGlade->get_widget
	(
		"EnvironmentScrolledPKG",
		EnvironmentScrolledPKG
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
	m_refGlade->get_widget
	(
		"ProjectMajorVersion",
		ProjectMajorVersion
	);
	m_refGlade->get_widget
	(
		"ProjectMinorVersion",
		ProjectMinorVersion
	);
	m_refGlade->get_widget
	(
		"ProjectMicroVersion",
		ProjectMicroVersion
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
		SourceOthersOpenButton, DependencyIOpenButton,
		DependencyLOpenButton, EnvironmentPKGOpenButton,
		SourceRemoveSrcButton, SourceRemoveImgButton, SourceRemoveGladeButton,
		SourceRemoveOthersButton, DependencyRemoveIButton,
		DependencyRemoveLButton, EnvironmentRemovePKGButton
	};
	
	Gtk::TreeView * trees[7] = 
	{
		sourceTreeview = manage(new Gtk::TreeView()),
		imageTreeview = manage(new Gtk::TreeView()),
		gladeTreeview = manage(new Gtk::TreeView()),
		othersTreeview = manage(new Gtk::TreeView()),
		ITreeview = manage(new Gtk::TreeView()),
		LTreeview = manage(new Gtk::TreeView()),
		PKGTreeview = manage(new Gtk::TreeView())
	};
	
	Glib::RefPtr<Gtk::ListStore> store[7] =
	{
		sourceStore, imageStore, gladeStore, othersStore,
		IStore, LStore, PKGStore
	};
	
	std::string filechooserTitle[7] =
	{
		"Select the project source files",
		"Select the images of the project",
		"Select the Glade files of the project",
		"Select the other files of the project",
		"Select the header directories",
		"Select the library directories",
		"Select the pkgconfig directories"
	};
	
	Gtk::FileChooserAction action[7] = 
	{
		Gtk::FILE_CHOOSER_ACTION_OPEN, Gtk::FILE_CHOOSER_ACTION_OPEN,
		Gtk::FILE_CHOOSER_ACTION_OPEN, Gtk::FILE_CHOOSER_ACTION_OPEN,
		Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER, Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER,
		Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER
	};
	
	unsigned int filechooserMimeType[7] = {1,2,3,4,4,4,4};
	
	Glib::RefPtr<Gtk::TreeSelection> selection[7] =
	{
		sourceSelection, imageSelection, gladeSelection, othersSelection,
		ISelection, LSelection, PKGSelection
	};
	
	Gtk::ScrolledWindow * scrolled[7] =
	{
		SourceScrolledSrc, SourceScrolledImg, SourceScrolledGlade,
		SourceScrolledOthers, DependencyScrolledI,	
		DependencyScrolledL, EnvironmentScrolledPKG
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
		selection[i]->set_mode(Gtk::SELECTION_BROWSE);
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
				store[i],
				action[i]
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
				selection[i],
				store[i]
			)
		);
		
	}
	////////////////////////////////////////////////////
	///////////////
	lTreeview = manage(new Gtk::TreeView());
	lStore = Gtk::ListStore::create(fColumns);
	// set the data model
	lTreeview->set_model(lStore);
	//Add the TreeView's view columns
	lTreeview->append_column
	(
		"ID", 
		fColumns.fileidcol
	);
	lTreeview->append_column
	(
		"Library name", 
		fColumns.filepathcol
	);
	lTreeview->append_column
	(
		"", 
		fColumns.filecellbgcolorcol
	);

	Gtk::TreeView::Column* pColumn;
	for(guint i = 2; i < 3; i++)
	{ 
		pColumn = lTreeview->get_column(i);
		Gtk::CellRenderer* cellRenderer = lTreeview->get_column_cell_renderer(i);
		pColumn->add_attribute
		(
			cellRenderer->property_cell_background(), 
			fColumns.filecellbgcolorcol
		);
		pColumn->set_reorderable();
	}
	// hide some columns
	pColumn = lTreeview->get_column(2);
	pColumn->set_visible(false);
	//All the items to be reordered with drag-and-drop
	// Set the visibility state of the headers. 
	lTreeview->set_headers_visible(true);
	// Allow the column title buttons to be clicked
	lTreeview->set_headers_clickable(true);
	// enable the hover effect
	lTreeview->set_hover_selection(true);
	// Resize all columns to their optimal width. 
	lTreeview->columns_autosize();
	// all element are reordorable
	lTreeview->set_reorderable();
	lTreeview->set_rules_hint();
	lTreeview->show();
	DependencyScrolledl->add(*lTreeview);
	
	lSelection = lTreeview->get_selection();
	lSelection->set_mode(Gtk::SELECTION_BROWSE);
	DependencylOpenButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::on_add_static_clicked
			),
			"Add a new library to the project",
			lStore
		)
	);
	
	DependencyRemovelButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this,
				&PackagerWindow::on_remove_clicked
			),
			lSelection,
			lStore
		)
	);
	
	////////////////////////////////////////////////////
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
		"Library name", 
		eColumns.variableenvnamecol
	);
	varenvTreeview->append_column
	(
		"Library version", 
		eColumns.variableenvvaluecol
	);
	varenvTreeview->append_column
	(
		"", 
		eColumns.variableenvcellbgcolorcol
	);

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
	
	varenvSelection = varenvTreeview->get_selection();
	varenvSelection->set_mode(Gtk::SELECTION_BROWSE);
	
	EnvironmentVariableOpenButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this, 
				&PackagerWindow::on_add_env_var_clicked
			),
			"Add a library from PKG",
			varenvStore
		)
	);
	
	EnvironmentRemoveVariableButton->signal_clicked().connect
	(
		sigc::bind
		(
			sigc::mem_fun
			(
				*this,
				&PackagerWindow::on_remove_clicked
			),
			varenvSelection,
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
	std::string tag[21] = {"autopackager", "projectname", "projectversion", "projectlanguage", "projecttarball", "projecturl", "projectbug", "projectdoxygen", "projectdirectory", "projectsources", "projectimages", "projectglade", "projectothers", "projectI", "projectL", "projectStaticLibs", "projectcompilerflags", "projectcompilerarguments", "projectPKG", "projectPKGLibs", "autopackager"};
	
	Gtk::Entry * Entries[19] = 
	{ 
		NULL, ProjectNameEntry, NULL, NULL, ProjectTarballEntry, 
		ProjectURLEntry, ProjectBugReportEntry, ProjectDoxygenEntry, 
		ProjectOutputEntry, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		EnvironmentCompilerFlagsEntry, EnvironmentArgumentsEntry,NULL
	};
	
	Gtk::TreeView * trees[9] = 
	{
		sourceTreeview,
		imageTreeview,
		gladeTreeview,
		othersTreeview,
		ITreeview,
		LTreeview,
		lTreeview,
		PKGTreeview,
		varenvTreeview
	};
	
	// reset treestore in case of reload
	for (unsigned int i=0;i<9;i++) {
		Glib::RefPtr<Gtk::ListStore> store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(trees[i]->get_model());
		store->clear();
	}
	
	unsigned int tag_cpt = 0;
	int tree_cpt = -1;
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
			 		if (Entries[tag_cpt] != NULL and strline.substr(tag[tag_cpt].size()+2, (strline.size()-(2*(tag[tag_cpt].size()+2)))-1) != "") 
			 		{
				 		Entries[tag_cpt]->set_text(strline.substr(tag[tag_cpt].size()+2, (strline.size()-(2*(tag[tag_cpt].size()+2)))-1));
				 	}  
				 	else if(tag[tag_cpt] == "projectlanguage") 
			 		{
			 			if (strline.substr(tag[tag_cpt].size()+2, (strline.size()-(2*(tag[tag_cpt].size()+2)))-1) == "C") {
			 				ProjectLanguageC->set_active(true);
			 				ProjectLanguageCPP->set_active(false);
			 			} else {
			 				ProjectLanguageC->set_active(false);
			 				ProjectLanguageCPP->set_active(true);
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
			 				tree_cpt++;
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
					 	Glib::RefPtr<Gtk::ListStore> store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(trees[tree_cpt]->get_model());
						Gtk::TreeModel::Row row = *(store->append());
						row[fColumns.fileidcol] = (store->children().size());
						row[fColumns.filepathcol] = strline.substr(6, (strline.size()-13));
						row[fColumns.filecellbgcolorcol] = (row[fColumns.fileidcol]%2==0)?COLOREVEN:COLORODD;
					 }
					 else if (strline.find("<name>")!=std::string::npos and strline.find("</name>")!=std::string::npos) 
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
					 else if (strline.find("<major>")!=std::string::npos and strline.find("</major>")!=std::string::npos) 
					 {
					 	ProjectMajorVersion->set_text(strline.substr(7, (strline.size()-15)));
					 }
					 else if (strline.find("<minor>")!=std::string::npos and strline.find("</minor>")!=std::string::npos) 
					 {
					 	ProjectMinorVersion->set_text(strline.substr(7, (strline.size()-15)));
					 }
					 else if (strline.find("<micro>")!=std::string::npos and strline.find("</micro>")!=std::string::npos) 
					 {
					 	ProjectMicroVersion->set_text(strline.substr(7, (strline.size()-15)));
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
	myfile << "<projectversion>\n";
	myfile << "<major>" << ProjectMajorVersion->get_text() << "</major>\n";
	myfile << "<minor>" << ProjectMinorVersion->get_text() << "</minor>\n";
	myfile << "<micro>" << ProjectMicroVersion->get_text() << "</micro>\n";
	myfile << "</projectversion>\n";
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
	model = ITreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectI>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectI>\n";
	// dynamic library
	model = LTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectL>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectL>\n";
	// static libs
	model = lTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectStaticLibs>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectStaticLibs>\n";
	myfile << "<projectcompilerflags>"<< EnvironmentCompilerFlagsEntry->get_text() <<"</projectcompilerflags>\n";
	myfile << "<projectcompilerarguments>"<< EnvironmentArgumentsEntry->get_text() <<"</projectcompilerarguments>\n";
	// path to PKG
	model = PKGTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectPKG>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<item>"<< (std::string)((*row)[fColumns.filepathcol]) <<"</item>\n";
	}
	myfile << "</projectPKG>\n";
	// libs from PKG
	model = varenvTreeview->get_model();
	store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	myfile << "<projectPKGLibs>\n";
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		myfile << "<set>\n<name>"
		<<(std::string)((*row)[eColumns.variableenvnamecol]) 
		<<"</name>\n<value>"
		<< (std::string)((*row)[eColumns.variableenvvaluecol])
		<<"</value>\n</set>\n";
	}
	myfile << "</projectPKGLibs>\n";
	
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
		on_AutoPackagerMenuItemSave_activate();
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
	Glib::RefPtr<Gtk::ListStore> store,
	Gtk::FileChooserAction action
)
{
	// instanciate a new filechooser
	genericFilechooserWindow * FC = new genericFilechooserWindow
	(
		*this,
		title,
		action,
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
	tmpLabel.push_back("  Library name :");
	tmpLabel.push_back("Library version:");
	tmpPlaceholder.push_back("Set the library's name");
	tmpPlaceholder.push_back("Set the library's version");
	
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

void PackagerWindow::on_add_static_clicked
(
	std::string title,
	Glib::RefPtr<Gtk::ListStore> store
)
{
	// instanciate a new assistant
	std::vector<std::string> tmpLabel;
	std::vector<std::string> tmpPlaceholder;
	tmpLabel.push_back("  Library name :");
	tmpPlaceholder.push_back("Set the library's name");
	
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
				&PackagerWindow::on_static_assistant_apply
			),
			lStore
		)
	);
	
	tmpLabel.clear();
	tmpPlaceholder.clear();
}

void PackagerWindow::on_remove_clicked
(
	Glib::RefPtr<Gtk::TreeSelection> selection,
	Glib::RefPtr<Gtk::ListStore> store
)
{
	Gtk::TreeModel::iterator iter = selection->get_selected();
	
	if (iter) 
	{
		store->erase(iter);
	}
        

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
			// copy files
			genericFeatures::copyFile(
				(std::string)((*row)[fColumns.filepathcol]),
				folders[2]+"/"+genericFeatures::removeSuffix((std::string)((*row)[fColumns.filepathcol]),"/")
			);
			// generate path to files
			ac_config_srcdir =  ac_config_srcdir+((ac_config_srcdir.size()>0)? " ":"")+"src/"+genericFeatures::removeSuffix((std::string)((*row)[fColumns.filepathcol]),"/");
			if (i == 0) 
			{
				// get list of files
				compilable_src =  compilable_src+((compilable_src.size()>0)? " ":"")+genericFeatures::removeSuffix((std::string)((*row)[fColumns.filepathcol]),"/");
			}
		}
	}
	
	Gtk::TreeView * PP[3] = 
	{
		ITreeview, LTreeview, lTreeview
	};
	std::string pPP[3] = 
	{
		" -I", " -L", " -l"
	};
	std::vector<std::string> listPP;
	for (unsigned int i =0;i<3;i++) 
	{
		Glib::RefPtr<Gtk::TreeModel> model = PP[i]->get_model();
		Glib::RefPtr<Gtk::ListStore> store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
		std::string tmp;
		for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
				row != store->children().end(); row++)
		{
			// get list of files
			tmp =  tmp+pPP[i]+((std::string)((*row)[fColumns.filepathcol]));
		}
		listPP.push_back(tmp);
	}
	
	std::string libsPKG;
	std::string flagsPKG;
	std::string pkgMODULE;
	Glib::RefPtr<Gtk::TreeModel> model = varenvTreeview->get_model();
	Glib::RefPtr<Gtk::ListStore> store = Glib::RefPtr<Gtk::ListStore>::cast_dynamic(model);
	for (Gtk::TreeNodeChildren::iterator row = store->children().begin(); 
			row != store->children().end(); row++)
	{
		// get list of files
		//libsADD = libsADD+" -l"+((std::string)((*row)[eColumns.variableenvnamecol]));
		pkgMODULE = pkgMODULE+"PKG_CHECK_MODULES("+genericFeatures::upperizeAlphaDigit(((std::string)((*row)[eColumns.variableenvnamecol])))+", ["+((std::string)((*row)[eColumns.variableenvnamecol]))+" >= "+((std::string)((*row)[eColumns.variableenvvaluecol]))+"])\nAC_SUBST("+genericFeatures::upperizeAlphaDigit(((std::string)((*row)[eColumns.variableenvnamecol])))+"_CFLAGS)\nAC_SUBST("+genericFeatures::upperizeAlphaDigit(((std::string)((*row)[eColumns.variableenvnamecol])))+"_LIBS)\n";
		libsPKG = libsPKG+" @"+genericFeatures::upperizeAlphaDigit(((std::string)((*row)[eColumns.variableenvnamecol])))+"_LIBS@";
		flagsPKG = flagsPKG+" @"+genericFeatures::upperizeAlphaDigit(((std::string)((*row)[eColumns.variableenvnamecol])))+"_CFLAGS@";
	}

	std::string projectname = ((std::string)ProjectNameEntry->get_text());
	std::string projectnamecapital = genericFeatures::upperize(((std::string)ProjectNameEntry->get_text()));
	std::string projectnamelower = genericFeatures::lowerize(((std::string)ProjectNameEntry->get_text()));
	// root Makefile.am
	std::ofstream myfile;
	myfile.open (home+"/Makefile.am");
	myfile << "AUTOMAKE_OPTIONS = foreign\n";
	myfile << "ACLOCAL_AMFLAGS = -I m4 --install \n";
	myfile << "SUBDIRS = src\n";
	myfile << "EXTRA_DIST = autogen.sh\n";
	myfile << "CLEANFILES = *~\n";
	myfile << "pkgconfig_DATA = "<< projectname <<".pc\n";
	myfile << projectname <<".pc: "<< projectname <<".pc.in\n";
	myfile << "	cp "<< projectname <<".pc.in "<< projectname <<".pc\n";
	myfile.close();
	// project.pc.in
	myfile.open (home+"/"+projectname+".pc.in");
	myfile << "prefix=@prefix@\n";
	myfile << "exec_prefix=@exec_prefix@\n";
	myfile << "libdir=@libdir@\n";
	myfile << "includedir=@includedir@\n";
	myfile << "\n";
	myfile << "Name: "<<projectname<<"\n";
	myfile << "Description: EBU Library and utilities to read and write broadcasting media files and their metadata\n";
	myfile << "Version: @VERSION@\n";
	myfile << "Requires: \n";
	myfile << "Libs: -L${libdir} @PC_ADD_LIBS@\n";
	myfile << "Libs.private: @PC_ADD_PRIVATE_LIBS@\n";
	myfile << "Cflags: -I${includedir}/"<<projectname<<"\n";
	myfile.close();
	// autogen.sh
	myfile.open (home+"/autogen.sh");
	myfile << "#!/bin/sh\n";
	myfile << "\n";
	myfile << "# check for libtoolize on Linux and glibtoolize on Mac\n";
	myfile << "if command -v libtoolize >/dev/null 2>&1; then\n";
	myfile << "  lt=libtoolize\n";
	myfile << "elif command -v glibtoolize >/dev/null 2>&1; then\n";
	myfile << "  lt=glibtoolize\n";
	myfile << "else\n";
	myfile << "  echo \"ERROR: libtoolize or glibtoolize not found\"\n";
	myfile << "  exit 1\n";
	myfile << "fi\n";
	myfile << "\n";
	myfile << "set -x\n";
	myfile << "aclocal\n";
	myfile << "$lt\n";
	myfile << "autoheader -f\n";
	myfile << "automake --foreign --add-missing -c\n";
	myfile << "autoconf";
	//myfile << "autoreconf --force --install -I config -I m4";
	myfile.close();
	// version.h
	myfile.open (home+"/version.h");
	myfile << "#ifndef "<<projectnamecapital<<"_VERSION_H\n";
	myfile << "#define "<<projectnamecapital<<"_VERSION_H\n";
	myfile << "\n";
	myfile << "#define "<<projectnamecapital<<"_VERSION_MAJOR "<< ProjectMajorVersion->get_text() <<"\n";
	myfile << "#define "<<projectnamecapital<<"_VERSION_MINOR "<< ProjectMinorVersion->get_text() <<"\n";
	myfile << "#define "<<projectnamecapital<<"_VERSION_MICRO "<< ProjectMicroVersion->get_text() <<"\n";
	myfile << "\n";
	if (((std::string)ProjectBugReportEntry->get_text()) != "") 
	{
		myfile << "#define "<<projectnamecapital<<"_BUGREPORT \""<< ProjectBugReportEntry->get_text() <<"\"\n";
	}
	if (((std::string)ProjectTarballEntry->get_text()) != "")
	{
		myfile << "#define "<<projectnamecapital<<"_TARNAME \""<< ProjectTarballEntry->get_text() <<"\"\n";
	}
	if (((std::string)ProjectURLEntry->get_text()) != "")
	{
		myfile << "#define "<<projectnamecapital<<"_URL \""<< ProjectURLEntry->get_text() <<"\"\n";
	}
	myfile << "\n";
	myfile << "#define "<<projectnamecapital<<"_VERSION ("<<projectnamecapital<<"_VERSION_MAJOR << 16 | "<<projectnamecapital<<"_VERSION_MINOR << 8 | "<<projectnamecapital<<"_VERSION_MICRO)\n";
	myfile << "\n";
	myfile << "#define "<<projectnamecapital<<"_LIBRARY_NAME \""<< projectname <<"\"\n";
	myfile << "\n";
	myfile << "#endif";
	myfile.close();
	// configure.ac
	myfile.open (home+"/configure.ac");
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl -- Extract package info\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << "m4_define([m4_"<<projectnamecapital<<"_LIBRARY_NAME],\n";
	myfile << "m4_esyscmd([(sed -n 's/^.*"<<projectnamecapital<<"_LIBRARY_NAME[^\\\"]*\\\"\\([^\\\"]*\\)\\\"/\\1/p' version.h | tr -d '\\n')]))\n";
	myfile << "m4_define([m4_"<<projectnamecapital<<"_VERSION_MAJOR],\n";
	myfile << "m4_esyscmd([(sed -n 's/^.*"<<projectnamecapital<<"_VERSION_MAJOR\\ *\\([0-9][0-9]*\\)/\\1/p' version.h | tr -d '\\n')]))\n";
	myfile << "m4_define([m4_"<<projectnamecapital<<"_VERSION_MINOR],\n";
	myfile << "m4_esyscmd([(sed -n 's/^.*"<<projectnamecapital<<"_VERSION_MINOR\\ *\\([0-9][0-9]*\\)/\\1/p' version.h | tr -d '\\n')]))\n";
	myfile << "m4_define([m4_"<<projectnamecapital<<"_VERSION_MICRO],\n";
	myfile << "m4_esyscmd([(sed -n 's/^.*"<<projectnamecapital<<"_VERSION_MICRO\\ *\\([0-9][0-9]*\\)/\\1/p' version.h | tr -d '\\n')]))\n";
	if (ProjectBugReportEntry->get_text() != "") {
		myfile << "m4_define([m4_"<<projectnamecapital<<"_BUGREPORT],\n";
		myfile << "m4_esyscmd([(sed -n 's/^.*"<<projectnamecapital<<"_BUGREPORT[^\\\"]*\\\"\\([^\\\"]*\\)\\\"/\\1/p' version.h | tr -d '\\n')]))\n";
	}
	if (ProjectTarballEntry->get_text() != "") {
		myfile << "m4_define([m4_"<<projectnamecapital<<"_TARNAME],\n";
		myfile << "m4_esyscmd([(sed -n 's/^.*"<<projectnamecapital<<"_TARNAME[^\\\"]*\\\"\\([^\\\"]*\\)\\\"/\\1/p' version.h | tr -d '\\n')]))\n";
	}
	if (ProjectURLEntry->get_text() != "") {
		myfile << "m4_define([m4_"<<projectnamecapital<<"_URL],\n";
		myfile << "m4_esyscmd([(sed -n 's/^.*"<<projectnamecapital<<"_URL[^\\\"]*\\\"\\([^\\\"]*\\)\\\"/\\1/p' version.h | tr -d '\\n')]))\n";
	}
	myfile << "\n";
	myfile << "m4_define([m4_"<<projectnamecapital<<"_VERSION],\n";
	myfile << "m4_defn([m4_"<<projectnamecapital<<"_VERSION_MAJOR]).m4_defn([m4_"<<projectnamecapital<<"_VERSION_MINOR]).m4_defn([m4_"<<projectnamecapital<<"_VERSION_MICRO]))\n";
	myfile << "\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl -- Init\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << "AC_PREREQ(m4_defn([AC_AUTOCONF_VERSION]))\n";
	myfile << "\n";
	myfile << "AC_INIT(m4_defn([m4_"<< projectnamecapital <<"_LIBRARY_NAME])";
	myfile << ", m4_defn([m4_"<< projectnamecapital <<"_VERSION])";
	if (ProjectBugReportEntry->get_text() != "") {
		myfile << ", m4_defn([m4_"<< projectnamecapital <<"_BUGREPORT])";
	}
	if (ProjectTarballEntry->get_text() != "") {
		myfile << ", m4_defn([m4_"<< projectnamecapital <<"_TARNAME])";
	}
	if (ProjectURLEntry->get_text() != "") {
		myfile << ", m4_defn([m4_"<< projectnamecapital <<"_URL])";
	}
	myfile << ")\n";
	myfile << "\n";
	myfile << "AC_CONFIG_AUX_DIR(config)\n";
	myfile << "AC_CONFIG_HEADER(config.h)\n";
	myfile << "AC_CONFIG_MACRO_DIR(m4)\n";
	myfile << "\n";
	myfile << "AM_INIT_AUTOMAKE(-W -Wall -Wno-extra-portability)\n";
	myfile << "C"<<((std::string)((ProjectLanguageC->get_active())?"":"XX"))<<"FLAGS=\"-O3 -Wall -Wextra $C"<<((std::string)((ProjectLanguageC->get_active())?"":"XX"))<<"FLAGS\"\n";
	myfile << "\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl -- Version\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << projectnamecapital<<"_MAJORMINOR=m4_defn([m4_"<< projectnamecapital <<"_VERSION_MAJOR]).m4_defn([m4_"<<projectnamecapital <<"_VERSION_MINOR])\n";
	myfile << "AC_SUBST("<<projectnamecapital<<"_MAJORMINOR)\n";
	myfile << "\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl -- Checks for programs \n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << "AC_PROG_C"+((std::string)((ProjectLanguageC->get_active())?"C\n":"XX\n"));
	myfile << "AC_LANG_C"+((std::string)((ProjectLanguageC->get_active())?"\n":"PLUSPLUS\n"));
	myfile << "AC_PROG_MAKE_SET\n";
	myfile << "AC_PROG_INSTALL\n";
	myfile << "AC_PROG_LIBTOOL\n";
	myfile << "AC_CHECK_PROGS(MD5TOOL, [md5sum md5])\n";
	myfile << "if test x\"$MD5TOOL\" = x\"\" ; then\n";
	myfile << "	AC_MSG_WARN(Missing md5sum/md5 tool. Cannot make check.)\n";
	myfile << "fi\n";
	myfile << "\n";
	myfile << pkgMODULE;
	myfile << "\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl -- Checks for header files\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << "AC_CHECK_HEADERS([ctime cstring cstdio cstdlib])\n";
	myfile << "\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl--Checks for typedefs, structures, compiler characteristics\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << "AC_HEADER_STDC\n";
	myfile << "AC_HEADER_STDBOOL\n";
	myfile << "AC_HEADER_TIME\n";
	myfile << "AC_TYPE_INT8_T\n";
	myfile << "AC_TYPE_INT16_T\n";
	myfile << "AC_TYPE_INT32_T\n";
	myfile << "AC_TYPE_INT64_T\n";
	myfile << "AC_TYPE_SIZE_T\n";
	myfile << "AC_TYPE_UINT8_T\n";
	myfile << "AC_TYPE_UINT16_T\n";
	myfile << "AC_TYPE_UINT32_T\n";
	myfile << "AC_TYPE_UINT64_T\n";
	myfile << "\n";
	myfile << "dnl -- mingw doesn't support the 'z' printf format length modifier for size_t\n";
	myfile << "case \"$host\" in\n";
	myfile << "	*-*-*mingw32) AC_DEFINE([PRIszt], [\"u\"], [Define printf size_t format specifier]) ;;\n";
	myfile << "			   *) AC_DEFINE([PRIszt], [\"zu\"], [Define printf size_t format specifier])\n";
	myfile << "esac\n";
	myfile << "\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl -- Checks for library functions\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << "AC_SYS_LARGEFILE\n";
	myfile << "AC_FUNC_FSEEKO\n";
	myfile << "AC_CHECK_FUNCS([getcwd gettimeofday memmove memset mkdir strerror])\n";
	myfile << "\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl -- Package Config\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << "pkgconfigdir=\"\\$(libdir)/pkgconfig\"\n";
	myfile << "AC_SUBST(pkgconfigdir)\n";
	myfile << "\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "dnl -- Config files\n";
	myfile << "dnl-----------------------------------------------------------\n";
	myfile << "\n";
	myfile << "AC_CONFIG_FILES([Makefile src/Makefile])\n";
	myfile << "\n";
	myfile << "AC_OUTPUT";
	myfile.close();
	// src Makefile.am
	myfile.open (folders[2]+"/Makefile.am");
	myfile << "bin_PROGRAMS ="<<projectname<<"\n";
	myfile << projectname<<"_SOURCES = "+compilable_src+"\n";
	myfile << "\n";
	myfile << projectname<<"_CPPFLAGS ="<<flagsPKG<<listPP[0]<<listPP[1]<<"\n";//listPP[0]<<"\n";
	myfile << projectname<<"_LDADD ="<<libsPKG<<listPP[2]<<"\n";//libsADD<<"\n";
	myfile << projectname+"_C"+((std::string)((ProjectLanguageC->get_active())?"":"XX"))+"FLAGS = " + ((std::string)EnvironmentCompilerFlagsEntry->get_text());
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

void PackagerWindow::on_static_assistant_apply
(
	Glib::RefPtr<Gtk::ListStore> store
)
{
	GA->hide();
	std::vector<std::string> tmp = GA->getResponse();
	Gtk::TreeModel::Row row = *(store->append());
	row[fColumns.fileidcol] = (store->children().size());
	row[fColumns.filepathcol] = tmp.at(0);
	row[fColumns.filecellbgcolorcol] = (row[fColumns.fileidcol]%2==0)?COLOREVEN:COLORODD;
}
