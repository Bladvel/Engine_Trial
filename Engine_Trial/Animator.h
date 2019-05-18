#pragma once
#include "PackageManager.h"

class Animator{
public:
	std::vector<ALLEGRO_BITMAP*> Image_set;
	int State;

	Animator();

	~Animator();

	void LoadPackage();




};

