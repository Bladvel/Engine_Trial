#pragma once
#include <vector>
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class Package {
public:
	std::string Type;
	std::string Name;
	std::vector<std::string> Directory;


	Package(std::string Name, std::string Type, int Archive_Number, std::vector<std::string> Data);

	~Package();
};


class PackageManager {
public:

	std::vector<Package> Wrapped;

	PackageManager() {};

	~PackageManager() {};

	void AddPackage(std::string Name, std::string Type, int Package_Qtty, std::vector<std::string> Data);

	std::vector<ALLEGRO_BITMAP*> UnpackImage(std::string PackageName);

};