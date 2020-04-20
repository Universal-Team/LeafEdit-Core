/*
*   This file is part of LeafEdit-Core
*   Copyright (C) 2020 DeadPhoenix8091, Epicpkmn11, Flame, RocketRobz, StackZ, TotallyNotGuy
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
#include "types.hpp"

#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <unistd.h>

std::map<u16, std::string> ItemDatabase;
// TODO!
std::string itemLanguages[] = {"de", "en", "es", "fr", "it", "jp", "lt", "pt"};
const std::string LANG_FOLDER = "romfs:/lang/";
const std::string WW_ITEM_FILE = "/wwItems.txt";
const std::string NL_ITEM_FILE = "/items.txt";

// String to U16. Useful for the Item ID & Name at one. TODO: Maybe move to StringUtils?
u16 strToU16(const std::string str) {
	u16 out;
	std::stringstream ss;
	ss << std::hex << str;
	ss >> out;

	return out;
}

// TODO!
void ItemUtils::LoadDatabase(int lang, SaveType save) {
	ItemDatabase.clear();

	std::string path; // Path.
	// If SaveType is Wild World -> Check.
	if (save == SaveType::WW) {
		if (WW_ITEM_FILE != "")	path = LANG_FOLDER + itemLanguages[lang] + WW_ITEM_FILE;
		else					return;
	// If SaveType is New Leaf or Welcome amiibo -> Check.
	} else if (save == SaveType::NL || save == SaveType::WA) {
		if (NL_ITEM_FILE != "")	path = LANG_FOLDER + itemLanguages[lang] + NL_ITEM_FILE;
		else					return;
	// Nope sorry. Invalid SaveType.
	} else { return; }
	// Check if File even exist!
	if((access(path.c_str(), F_OK) != 0)) {
		return;
		// Item File is found, load!
	} else {
		std::string currentLine;
		std::ifstream itemDatabase(path.c_str(), std::ifstream::in);

		std::string itemIdStr;
		std::string itemName;

		while (std::getline(itemDatabase, currentLine))
		{
			if (currentLine.size() > 8 && currentLine.find("//") == std::string::npos)
			{											// confirm we don't have any comments
				itemIdStr = currentLine.substr(2, 4); 	// skip the 0x hex specifier
				itemName = currentLine.substr(8, currentLine.size());

				// Convert itemIdStr to a u16
				u16 itemId = strToU16(itemIdStr);

				// Add item to the database
				ItemDatabase.insert(std::make_pair(itemId, itemName));
			}
		}
		itemDatabase.close();
	}
}

// Get an Item's name.
std::string ItemUtils::getName(u16 ID) {
	if (ItemDatabase.empty())	return "???";
	for (auto const& entry : ItemDatabase) {
		if (entry.first == ID) {
			return entry.second;
		}
	}
	return std::string("???");
}