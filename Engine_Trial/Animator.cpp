#include "stdafx.h"
#include "Animator.h"


Animator::Animator(int TargetSpeed)
{
	State = 0;
	Speed = TargetSpeed;
	BuildUp = 0;
}


Animator::~Animator()
{
}

/*Loads the sprite from a Package to be used, the size of the 
vector should be already set hence the resize*/
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

ALLEGRO_BITMAP * Animator::Draw(int TargetState)
{
	return(Sprite[TargetState]);
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

void Animator::SetAnimationSpeed(int TargetSpeed){
	Speed = TargetSpeed;
}


/*About Animate to and AnimateLoop, since its kinda messy I've consedered 
splitting the core logic into sub functions, yet I also think it would be unnecessary*/


void Animator::AnimateTo(int TargetState, bool Backward) {
	int Direction;

	if (Backward) 
	{Direction = -1;}
	else 
	{Direction =  1;}

	if (BuildUp <= 10) {
		BuildUp += 1 * Speed;
	}
	else {
		if (State != TargetState) {
			State += Direction;
			BuildUp = 0;

			if (State < 0 && Direction < 0) {
				State = Sprite.size() - 1;
			}
			else if (State > Sprite.size() - 1 && Direction > 0) {
				Reset();
			}
		}

	}
}

void Animator::AnimateLoop(bool Backward) {
	int Direction;

	if (Backward)
	{Direction = -1;}
	else
	{Direction = 1;}

	if (BuildUp <= 10) {
		BuildUp += 1 * Speed;
	}
	else {
		State += Direction;
		BuildUp = 0;

		if (State < 0 && Direction < 0) {
			State = Sprite.size() - 1;
		}
		else if (State > Sprite.size() - 1 && Direction > 0) {
			Reset();
		}
	}
}


