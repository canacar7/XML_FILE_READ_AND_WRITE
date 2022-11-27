/*
 * Application.cpp
 *
 *  Created on: Nov 27, 2022
 *      Author: can
 */


#include <string>
#include <iostream>
#include "Configuration.h"

using namespace std;
using namespace DDSConfiguration;
int main(void)
{

	Configuration *conf;
	conf = conf->GetInstance();


	if(conf->Write_XML_File())
	{
		cout << "Writing is done " << endl;
	}
	else
	{
		cout << "Writing is not done" << endl;
	}

	if(conf->Read_XML_File())
	{
		cout << "reading is done " << endl;
	}
	else
	{
		cout << "reading is not done" << endl;
	}







	return 0;
}
