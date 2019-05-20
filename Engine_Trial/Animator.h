#pragma once
#include "PackageManager.h"

/*All things concerning the sprite animation should be handled here
This will be reconsidered if it gets too messy*/
class Animator{
public:
	std::vector<ALLEGRO_BITMAP*> Sprite;
	int State;
	int Speed;

	Animator();

	~Animator();

	void LoadPackage(std::vector<ALLEGRO_BITMAP*> Package);

	void SetState(int Index);

	ALLEGRO_BITMAP* Draw();

	ALLEGRO_BITMAP* DrawNext();

	void Reset();
};

