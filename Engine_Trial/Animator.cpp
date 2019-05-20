#include "stdafx.h"
#include "Animator.h"


Animator::Animator()
{
	State = 0;
}


Animator::~Animator()
{
}

//Loads the sprite from a Package to be used, the size of the vector should be static hence the resize
void Animator::LoadPackage(std::vector<ALLEGRO_BITMAP*> Package){
	Sprite.resize(Package.size());
	Sprite = Package;
	State = 0;
}

void Animator::SetState(int Index) {
	State = Index;
}

ALLEGRO_BITMAP* Animator::Draw() {
	return(Sprite[State]);
}

ALLEGRO_BITMAP* Animator::DrawNext() {
	if (State < Sprite.size()) {
		State++;
	}

	return(Sprite[State]);
}

void Animator::Reset() {
	State = 0;
}

