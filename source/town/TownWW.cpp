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

#include "saveUtils.hpp"
#include "stringUtils.hpp"
#include "TownWW.hpp"

u8 TownWW::grasstype() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return townPointer()[0x2200];
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
		case WWRegion::KOR_REV1:
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}

void TownWW::grasstype(u8 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			townPointer()[0x2200] = v;
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
		case WWRegion::KOR_REV1:
		case WWRegion::UNKNOWN:
			break;
	}
}

std::u16string TownWW::name() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadWWString(townPointer(), 0x0004, 8, this->region);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadWWString(townPointer(), 0x0004, 7, this->region);
		case WWRegion::KOR_REV1:
			return StringUtils::ReadNLString(townPointer(), 0x0004, 6, u'\uFFFF');
		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}
	return StringUtils::UTF8toUTF16("?");
}

std::unique_ptr<Acre> TownWW::acre(int Acre) {
	if (Acre > 35)	return nullptr;
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<AcreWW>(data, 0xC330 + Acre *1);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<AcreWW>(data, 0xA32C + Acre *1); // 0xA32C - 0xA34E
		case WWRegion::KOR_REV1:
			return std::make_unique<AcreWW>(data, 0xD303 + Acre *1); // Is it D303 or D304?
		case WWRegion::UNKNOWN:
			return nullptr;
	}
	return nullptr;
}

std::unique_ptr<Item> TownWW::item(u32 index) {
	if (index > 4095)	return nullptr;
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<ItemWW>(data, 0xC354 + index * 2);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<ItemWW>(data, 0x50D2 + index * 2);
		case WWRegion::KOR_REV1:
			return std::make_unique<ItemWW>(data, 0xD329 + index * 2);
		case WWRegion::UNKNOWN:
			return nullptr;
	}
	return nullptr;
}