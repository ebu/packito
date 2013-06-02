/*!
 * \project_name AutoPackager
 * \file PackagerEngine.cpp
 * \brief 
 * \details 
 * \authors Marco Dos Santos Oliveira
 * \version 0.1
 * \date 26 may 2013
 *
 * This software is published in MPLv2.0
 *
 */



#include "packagerEngine.hpp"

// class constructor and destructor

PackagerEngine::PackagerEngine
(
	void
)
{
	// init
	page = 0;
	project = "";
}

PackagerEngine::~PackagerEngine
(
	void
)
{
}

unsigned int PackagerEngine::getCurrentPage
(
	void
)
{
	return page;
}

void PackagerEngine::setCurrentPage
(
	unsigned int p
)
{
	page = p;
}

void PackagerEngine::setProjectPath
(
	std::string file
)
{
	project = file;
}

std::string PackagerEngine::getProjectPath
(
	void
)
{
	return project;
}

void PackagerEngine::setDescription
(
	std::vector<std::string> desc
)
{
	descriptions = desc;
}

void PackagerEngine::setSource
(
	std::vector<std::vector<std::string>> src
)
{
	sources = src;
}

void PackagerEngine::setDependency
(
	std::vector<std::vector<std::string>> dp
)
{
	dependencies = dp;
}

void PackagerEngine::setEnvironment
(
	std::vector<std::vector<std::string>> env
)
{
	environment = env;
}

std::vector<std::string> PackagerEngine::getDescription
(
	void
)
{
	return descriptions;
}

std::vector<std::vector<std::string>> PackagerEngine::getSource
(
	void
)
{
	return sources;
}

std::vector<std::vector<std::string>> PackagerEngine::getDependency
(
	void
)
{
	return dependencies;
}

std::vector<std::vector<std::string>> PackagerEngine::getEnvironment
(
	void
)
{
	return environment;
}
