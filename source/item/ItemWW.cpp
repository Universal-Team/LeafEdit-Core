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

#include "ItemWW.hpp"
#include "saveUtils.hpp"

u16 ItemWW::id() { return SaveUtils::Read<u16>(itemPointer(), 0); }

void ItemWW::id(u16 v) { SaveUtils::Write<u16>(itemPointer(), 0, v); }

u16 ItemWW::flags() { return 0; }

void ItemWW::flags(u16 v) { }

std::string ItemWW::name(bool fromClass, u16 ID) {
	if (ItemDatabase.empty())	return "???";
	for (auto const& entry : ItemDatabase) {
		if (fromClass) {
			if (entry.first == this->id()) {
				return entry.second;
			}
		} else {
			if (entry.first == ID) {
				return entry.second;
			}
		}
	}
	return std::string("???");
}