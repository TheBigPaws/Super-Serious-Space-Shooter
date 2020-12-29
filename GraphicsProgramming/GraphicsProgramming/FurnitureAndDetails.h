#pragma once
#include "ModelsLoader.h"

class FurnitureAndDetails
{
private:
	ModelsLoader rock;
	ModelsLoader tree;
	ModelsLoader log;
public:
	FurnitureAndDetails();
	void renderAll();
};

