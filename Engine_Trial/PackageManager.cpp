#include "stdafx.h"
#include "PackageManager.h"


void PackageManager::AddPackage(std::string Name, std::string Type, int Package_Qtty, std::vector<std::string> ArchiveName) {
		
		Wrapped.push_back (Package(Name, Type, Package_Qtty, ArchiveName));
		//std::cout << Wrapped[0].Directory[1] << std::endl;
}

std::vector<ALLEGRO_BITMAP*> PackageManager::UnpackImage(std::string PackageName) {

	std::vector<ALLEGRO_BITMAP*> Data;

	for (size_t i = 0; i < Wrapped.size(); i++)
	{

		if (Wrapped[i].Name == PackageName) {
			Data.resize(Wrapped[i].Directory.size());

			for (size_t j = 0; j < Wrapped[i].Directory.size(); j++)
			{
				Data[j] = (al_load_bitmap(Wrapped[i].Directory[j].c_str()));
			}
			return(Data);
		}
	}
	return(Data);
}

Package::Package(std::string Name, std::string Type, int Archive_Number, std::vector<std::string> Data)
{
	Directory.resize(Archive_Number);
	Directory = Data;
	this->Type = Type;
	this->Name = Name;

	
}

Package::~Package(){}



