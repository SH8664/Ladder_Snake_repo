#pragma once
#include"Action.h"

class OpenGridAction : public Action
{
	string filename;
public:
	OpenGridAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); // Reads OpenGridAction action parameters (filename)

	virtual void Execute(); 

	virtual ~OpenGridAction();
};

