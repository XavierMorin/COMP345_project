#pragma once
#include "VGMap.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class VGMapLoader
{
private:
	VGMap * vgmap;
public:
	VGMapLoader();
	virtual ~VGMapLoader();
	virtual void readfromfile(string);
	void has_only_digits_err(const string, const string);
	void error_m();
	VGMap* getVGMap();
	void setVGMap(VGMap *vgmap);
};
