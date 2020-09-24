/*
*   This file is part of LeafEdit-Core
*   Copyright (C) 2020 Universal-Team
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

/* Grasstype. */
u8 TownWW::grasstype() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->townPointer()[0x2200];

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
			SaveUtils::Write<u8>(this->townPointer(), 0x2200, v);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
		case WWRegion::KOR_REV1:
		case WWRegion::UNKNOWN:
			break;
	}
}

/* Town Name. */
std::u16string TownWW::name() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadUTF8String(this->townPointer(), 0x0004, 8, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadUTF8String(this->townPointer(), 0x0004, 6, this->region);

		case WWRegion::KOR_REV1:
			return StringUtils::ReadUTF16String(this->townPointer(), 0x0004, 6);
			
		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}

	return StringUtils::UTF8toUTF16("?");
}
void TownWW::name(std::u16string v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			StringUtils::WriteUTF8String(this->townPointer(), v, 0x0004, 8, this->region);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			StringUtils::WriteUTF8String(this->townPointer(), v, 0x0004, 6, this->region);
			break;

		case WWRegion::KOR_REV1:
			StringUtils::WriteUTF16String(this->townPointer(), v, 0x0004, 6);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Town Acre. */
std::unique_ptr<Acre> TownWW::acre(int Acre) const {
	if (Acre > 35) return nullptr; // Acre Index goes out of scope.

	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<AcreWW>(this->data, 0xC330 + Acre * 1);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<AcreWW>(this->data, 0xA32C + Acre * 1);

		case WWRegion::KOR_REV1:
			return std::make_unique<AcreWW>(this->data, 0xD304 + Acre * 1);

		case WWRegion::UNKNOWN:
			return nullptr;
	}

	return nullptr;
}

/* Town Item. */
std::unique_ptr<Item> TownWW::item(u32 index) const {
	if (index > 4095) return nullptr; // Item Index goes out of scope.

	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<ItemWW>(this->data, 0xC354 + index * 2);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<ItemWW>(this->data, 0xA350 + index * 2);

		case WWRegion::KOR_REV1:
			return std::make_unique<ItemWW>(this->data, 0xD328 + index * 2);

		case WWRegion::UNKNOWN:
			return nullptr;
	}

	return nullptr;
}

/* Return if Town exist. */
bool TownWW::exist() const {
	if (SaveUtils::Read<u16>(this->townPointer(), 0x2) == 0x0 || SaveUtils::Read<u16>(this->townPointer(), 0x2) == 0xFFFF)	return false;
	return true;
}

/* Turnip prices. In AC:WW, they seem to be only *one* price. */
u32 TownWW::turnipPrices(bool isAM, int day) const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->townPointer()[0x15F5D];

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return this->townPointer()[0x121A3];

		case WWRegion::KOR_REV1:
			return this->townPointer()[0x17370];

		case WWRegion::UNKNOWN:
			return 0;
	}

	return 0;
}
void TownWW::turnipPrices(bool isAM, int day, u32 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u8>(this->townPointer(), 0x15F5D, (u8)v);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u8>(this->townPointer(), 0x121A3, (u8)v);
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u8>(this->townPointer(), 0x17370, (u8)v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Town flag. */
std::unique_ptr<Pattern> TownWW::townflag() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<PatternWW>(this->data, 0x15930, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<PatternWW>(this->data, 0x11C5C, this->region);

		case WWRegion::KOR_REV1:
			return std::make_unique<PatternWW>(this->data, 0x16D0C, this->region);

		case WWRegion::UNKNOWN:
			return nullptr;
	}

	return nullptr;
}

/* Item buried. */
bool TownWW::itemBuried(int index) const {
	if (index > 4095) return false;

	u32 offset = 0;
	switch(this->region) {
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			offset = 0xC350 + ((index / 256) * 256 + (index % 256)) / 8;
			break;

		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			offset = 0xE354 + ((index / 256) * 256 + (index % 256)) / 8;
			break;

		case WWRegion::KOR_REV1:
			offset = 0xF328 + ((index / 256) * 256 + (index % 256)) / 8;
			break;

		case WWRegion::UNKNOWN:
			return false;
	}

	return SaveUtils::GetBit(this->townPointer(), offset, (index % 256) % 8);
}
void TownWW::itemBuried(int index, bool buried) {
	if (index > 4095) return;

	/* Check, if already buried or not. */
	if (this->itemBuried(index) == buried) return; // No need to set again.

	u32 offset = 0;
	switch(this->region) {
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			offset = 0xC350 + ((index / 256) * 256 + (index % 256)) / 8;
			break;

		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			offset = 0xE354 + ((index / 256) * 256 + (index % 256)) / 8;
			break;

		case WWRegion::KOR_REV1:
			offset = 0xF328 + ((index / 256) * 256 + (index % 256)) / 8;
			break;
			
		case WWRegion::UNKNOWN:
			return;
	}

	std::unique_ptr<Item> item = this->item(index);

	if (item->itemtype() == ItemType::Empty) return; // Do not allow buried on empty spots.

	/* Write buried state. */
	SaveUtils::SetBit(this->townPointer(), offset, (index % 256) % 8, buried);
}

/* Recycle bin (or whatever you would call that box inside the Townhall there) Items. */
std::unique_ptr<Item> TownWW::recycleItem(int slot) const {
    if (slot > 14) return nullptr; // Item Index goes out of scope.

    switch(this->region) {
        case WWRegion::USA_REV0:
        case WWRegion::USA_REV1:
        case WWRegion::EUR_REV1:
            return std::make_unique<ItemWW>(this->data, 0x15EDE + slot * 2);

        case WWRegion::JPN_REV0:
        case WWRegion::JPN_REV1:
            return std::make_unique<ItemWW>(this->data, 0x12132 + slot * 2);

        case WWRegion::KOR_REV1:
            return std::make_unique<ItemWW>(this->data, 0x172DE + slot * 2);

        case WWRegion::UNKNOWN:
            return nullptr;
    }

    return nullptr;
}

/* Lost and Found Items. */
std::unique_ptr<Item> TownWW::lostFoundItem(int slot) const {
    if (slot > 14) return nullptr; // Item Index goes out of scope.

    switch(this->region) {
        case WWRegion::USA_REV0:
        case WWRegion::USA_REV1:
        case WWRegion::EUR_REV1:
            return std::make_unique<ItemWW>(this->data, 0x15EC0 + slot * 2);

        case WWRegion::JPN_REV0:
        case WWRegion::JPN_REV1:
            return std::make_unique<ItemWW>(this->data, 0x12114 + slot * 2);

        case WWRegion::KOR_REV1:
            return std::make_unique<ItemWW>(this->data, 0x172C0 + slot * 2);

        case WWRegion::UNKNOWN:
            return nullptr;
    }

    return nullptr;
}