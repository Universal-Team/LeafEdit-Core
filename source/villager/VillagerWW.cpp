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

#include "VillagerWW.hpp"

// ID, It's a u8, TODO.
u16 VillagerWW::id() {
	switch(this->region) {
		case WWRegion::EUR:
		case WWRegion::JPN:
		case WWRegion::KOR:
			return 0;
	}
	return 0;
}

void VillagerWW::id(u16 v) {
	switch(this->region) {
		case WWRegion::EUR:
		case WWRegion::JPN:
		case WWRegion::KOR:
			break;
	}
}

u8 VillagerWW::personality() {
	switch(this->region) {
		case WWRegion::EUR:
			return villagerPointer()[0x6CA];
		case WWRegion::JPN:
		case WWRegion::KOR:
			return 0;
	}
	return 0;
}

void VillagerWW::personality(u8 v) {
	switch(this->region) {
		case WWRegion::EUR:
			villagerPointer()[0x6CA] = v;
			break;
		case WWRegion::JPN:
		case WWRegion::KOR:
			break;
	}
}