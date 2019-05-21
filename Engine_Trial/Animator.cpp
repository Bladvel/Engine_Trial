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

/*The two Higlighted section in Animate are meant to fix the problem when it is going
backwards and State = 0, in the code that would leave State = -1 and that would not be fixed
until the next call. As I couldn't think of an elegant solution here it is. 
fell free to fix it*/

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
		if (State < Sprite.size() && State >= 0) {
			State += Direction;
			BuildUp = 0;
		}
		else if (State != TargetState) {
			Reset();
			BuildUp = 0;
		}
	}
/*********************************************/
	if (State > Sprite.size()) {
		State = Sprite.size();
	}

	if (State < 0) {
		State = 0;
	}
/*********************************************/
}

void Animator::AnimateLoop(int From, int TargetState, bool Backward) {
	int Direction;

	if (Backward)
	{Direction = -1;}
	else
	{Direction = 1;}

	if (BuildUp <= 10) {
		BuildUp += 1 * Speed;
	}
	else {
		if (State < Sprite.size() && State >= 0) {
			State += Direction;
			BuildUp = 0;
		}
		else{
			Reset();
			BuildUp = 0;
		}
	}

/*********************************************/
	if (State > Sprite.size()) {
		State = Sprite.size();
	}

	if (State < 0) {
		State = 0;
	}
/*********************************************/
}


