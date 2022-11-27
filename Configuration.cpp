/*
 * Configuration.cpp
 *
 *  Created on: Nov 27, 2022
 *      Author: can
 */

#include "Configuration.h"

namespace DDSConfiguration {

Configuration* Configuration::instance_conf = nullptr;

Configuration::Configuration() {

	l_pRootElement = NULL;
	control_DDSParameters = NULL;
	control_DomainID = NULL;
	deger = NULL;


	document = TiXmlDocument();
	control_TopicName = NULL;
	parameters = NULL;
	decl = NULL;
	root = NULL;

	domain_ID_tmp = 42;
	topic_name_tmp = "TOPIC_NAME";

	file_path = "/home/can/workspace/configuration/conf_folder/configuration.xml";
}

Configuration::~Configuration() {
	// TODO Auto-generated destructor stub
}


bool Configuration::Write_XML_File()
{
	decl = new TiXmlDeclaration( "1.0", "", "" );
	document.LinkEndChild(decl);

	root = new TiXmlElement( "DDS_Parameters" );
	document.LinkEndChild(root);

//	TiXmlComment * comment = new TiXmlComment();				//yorum yapildi dosya hakkinda
//	comment->SetValue("Setting First Parameters for OpenDDS");
//	root->LinkEndChild(comment);								//comment rootun altinda tanimli olacak bu uzden bitis roout icersinde

	TiXmlElement *messages = new TiXmlElement("Parameters");
	root->LinkEndChild(messages);


	parameters = new TiXmlElement( "DomainID" );
	parameters->SetAttribute("DomainID",42);
	messages->LinkEndChild(parameters);


	parameters = new TiXmlElement( "TopicName" );
	parameters->SetAttribute("Topc1","Heartbeat");
	messages->LinkEndChild(parameters);


	document.SaveFile(file_path);

	return 1;

}



bool Configuration::Read_XML_File()
{

	TiXmlDocument doc( file_path );
	doc.LoadFile();

	l_pRootElement = doc.RootElement();

	if( NULL != l_pRootElement )

	    {
			control_DDSParameters = l_pRootElement->FirstChildElement("Parameters");

			while ( NULL != control_DDSParameters )
			{
				control_DomainID  = control_DDSParameters->FirstChildElement("DomainID");
				control_TopicName = control_DDSParameters->FirstChildElement("TopicName");
				if ( NULL != control_DomainID )
				{
					deger = control_DomainID->FirstAttribute();
					setDomainIdTmp(deger->IntValue());
					std::cout << deger->IntValue() << std::endl;
				}

				if ( NULL != control_TopicName )
				{
					deger = control_TopicName->FirstAttribute();
					std::string deger_tmp = deger->Value();
					setTopicNameTmp(deger_tmp);
					std::cout << deger_tmp << std::endl;
				}

				control_DDSParameters = control_DDSParameters->NextSiblingElement("Parameters");

			}

		}

	return 1;
}






} /* namespace DDSConfiguration */


