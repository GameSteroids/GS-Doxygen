#pragma once
#include <Windows.h>
#include "General.h"
#include "Unit.h"
#pragma once

class StrifeHelper {
public:
	string username;
	std::vector<Unit> entities;
	std::vector<Unit> players;
};