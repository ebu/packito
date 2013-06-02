#ifndef CPP_PACKAGERENGINE_CLASS_H
#define CPP_PACKAGERENGINE_CLASS_H

/*!
 * \project_name AutoPackager
 * \file packagerEngine.hpp
 * \brief 
 * \details 
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 26 may 2013
 *
 * This software is published in MPLv2.0
 *
 */


/*! \class PackagerEngine
 * \brief 
 */

#include <iostream>
#include <gtkmm/box.h>
#include <gtkmm/label.h>

class PackagerEngine
{
	public:
		PackagerEngine
		(
			void
		);
		virtual ~PackagerEngine
		(
			void
		);
				
		unsigned int getCurrentPage
		(
			void
		);
		
		void setCurrentPage
		(
			unsigned int p
		);

		void setProjectPath
		(
			std::string file
		);
		
		std::string getProjectPath
		(
			void
		);
		
		void setDescription
		(
			std::vector<std::string> desc
		);
		
		void setSource
		(
			std::vector<std::vector<std::string> > src
		);
		
		void setDependency
		(
			std::vector<std::vector<std::string> > dp
		);
		
		void setEnvironment
		(
			std::vector<std::vector<std::string> > env
		);
		
		std::vector<std::string> getDescription
		(
			void
		);
		
		std::vector<std::vector<std::string> > getSource
		(
			void
		);
		
		std::vector<std::vector<std::string> > getDependency
		(
			void
		);
		
		std::vector<std::vector<std::string> > getEnvironment
		(
			void
		);

	protected:

		unsigned int page;
		std::string project;
			
		std::vector<std::string> descriptions;
		std::vector<std::vector<std::string> > sources;
		std::vector<std::vector<std::string> > dependencies;
		std::vector<std::vector<std::string> > environment;

};

#endif
