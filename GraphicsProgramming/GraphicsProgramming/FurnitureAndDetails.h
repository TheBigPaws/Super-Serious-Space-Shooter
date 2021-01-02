#pragma once
#include "ModelsLoader.h"

class FurnitureAndDetails
{
private:
	ModelsLoader rock;
	ModelsLoader tree;
	ModelsLoader log;
	ModelsLoader shelf;
public:
	FurnitureAndDetails();
	void renderAll();
};

