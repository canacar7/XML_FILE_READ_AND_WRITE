/*
 * Configuration.h
 *
 *  Created on: Nov 27, 2022
 *      Author: can
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "tinyxml.h"
#include <string>
#include <iostream>

namespace DDSConfiguration
{

class Configuration
{

private:
	//singleton design paern

	static Configuration *instance_conf;
	Configuration();

	//PARAMETERS FOR READ FILE
	TiXmlElement *l_pRootElement;
	TiXmlElement *control_DDSParameters;
	TiXmlElement *control_DomainID;
	TiXmlElement *control_TopicName;
	TiXmlAttribute *deger;

	//PARAMETERS FOR WRITE FILE
	TiXmlDocument document;
	TiXmlElement *parameters;
	TiXmlDeclaration *decl;
	TiXmlElement *root;


	int domain_ID_tmp;
	std::string topic_name_tmp;
	const char * file_path;


public:

	static Configuration* GetInstance()
	{
		return (!instance_conf) ?
				instance_conf = new Configuration :
				instance_conf;
	}


	virtual ~Configuration();

	bool Read_XML_File();
	bool Write_XML_File();

	int getDomainIdTmp() const
	{
		return domain_ID_tmp;
	}

	void setDomainIdTmp(int domainIdTmp)
	{
		domain_ID_tmp = domainIdTmp;
	}

	const std::string& getTopicNameTmp() const
	{
		return topic_name_tmp;
	}

	void setTopicNameTmp(const std::string &topicNameTmp)
	{
		topic_name_tmp = topicNameTmp;
	}

	const char* getFilePath() const
	{
		return file_path;
	}

	void setFilePath(const char *filePath)
	{
		file_path = filePath;
	}






};

} /* namespace DDSConfiguration */

#endif /* CONFIGURATION_H_ */
