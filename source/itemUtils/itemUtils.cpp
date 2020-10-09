/*
*   This file is part of LeafEdit-Core
*   Copyright (C) 2020 LeafEdit-Core-Contributors
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#include "itemUtils.hpp"
#include "stringDB.hpp"
#include <string>
#include <tuple>
#include <vector>

extern std::vector<std::tuple<u16, std::string, std::string>> itemDB;
extern std::vector<std::string> itemCategories;

/*
	Get an Item's name.

	u16 ID: The Item ID.
*/
std::string ItemUtils::getName(u16 ID) {
	if (itemDB.empty()) return "???"; // Database empty.

	for (auto const& entry : itemDB) {
		if (std::get<0>(entry) == ID) return std::get<1>(entry);
	}

	return std::string("???");
}

/*
	Get an Animal Crossing: Wild World's index Item's name.

	int category: The item category.
	u8 index: The index.
*/
std::string ItemUtils::getWWName(int category, u8 index) {
	std::vector<std::tuple<u16, std::string, std::string>> temp = StringDB::searchTuple("", {itemCategories[category]}, itemDB, true);

	if (temp.empty()) return "???"; // Database empty.

	if (temp.size() >= index) return std::get<1>(temp[index]);

	return std::string("???");
}