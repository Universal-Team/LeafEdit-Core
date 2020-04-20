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

#include "PlayerWW.hpp"
#include "saveUtils.hpp"
#include "stringUtils.hpp"

// Face.
u8 PlayerWW::face() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return playerPointer()[0x223C] & 0xF;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return playerPointer()[0x1CC6] & 0xF;
		case WWRegion::KOR_REV1:
			return playerPointer()[0x243C] & 0xF;
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}
void PlayerWW::face(u8 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			playerPointer()[0x223C] = (playerPointer()[0x223C] & 0xF0) | (v & 0xF);
			return;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			playerPointer()[0x1CC6] = (playerPointer()[0x1CC6] & 0xF0) | (v & 0xF);
			return;
		case WWRegion::KOR_REV1:
			playerPointer()[0x243C] = (playerPointer()[0x243C] & 0xF0) | (v & 0xF);
		case WWRegion::UNKNOWN:
			break;
	}
}

// Tan. TODO U8!
u16 PlayerWW::tan() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return playerPointer()[0x223D] & 0xF;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return playerPointer()[0x1CC7] & 0xF;
		case WWRegion::KOR_REV1:
			return playerPointer()[0x243D] & 0xF;
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}

void PlayerWW::tan(u16 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			playerPointer()[0x223D] = (playerPointer()[0x223D] & 0xF0) | (v & 0xF);
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			playerPointer()[0x1CC7] = (playerPointer()[0x1CC7] & 0xF0) | (v & 0xF);
			break;
		case WWRegion::KOR_REV1:
			playerPointer()[0x243D] = (playerPointer()[0x243D] & 0xF0) | (v & 0xF);
			break;
		case WWRegion::UNKNOWN:
			break;
	}
}

// Gender.
u8 PlayerWW::gender() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return playerPointer()[0x228A];
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return playerPointer()[0x1CFB];
		case WWRegion::KOR_REV1:
			return playerPointer()[0x249A];
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}
void PlayerWW::gender(u8 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			playerPointer()[0x228A] = v;
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			playerPointer()[0x1CFB] = v;
			break;
		case WWRegion::KOR_REV1:
			playerPointer()[0x249A] = v;
		case WWRegion::UNKNOWN:
			break;
	}
}

// HairStyle. TODO
u8 PlayerWW::hairstyle() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return playerPointer()[0x223C] >> 4;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return playerPointer()[0x1CC6] >> 4;
		case WWRegion::KOR_REV1:
			return playerPointer()[0x243C] >> 4;;
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}
void PlayerWW::hairstyle(u8 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			playerPointer()[0x223C] = (playerPointer()[0x1CC6] & 0xF0) | (v << 4);
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			playerPointer()[0x1CC6] = (playerPointer()[0x1CC6] & 0xF0) | (v << 4);
			break;
		case WWRegion::KOR_REV1:
			playerPointer()[0x243C] = (playerPointer()[0x1CC6] & 0xF0) | (v << 4);
		case WWRegion::UNKNOWN:
			break;
	}
}

// HairColor.
u8 PlayerWW::haircolor() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return playerPointer()[0x223D] >> 4;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return playerPointer()[0x1CC7] >> 4;
		case WWRegion::KOR_REV1:
			return playerPointer()[0x243D] >> 4;
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}
void PlayerWW::haircolor(u8 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			playerPointer()[0x223D] = (playerPointer()[0x223D] & 0xF) | (v << 4);
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			playerPointer()[0x1CC7] = (playerPointer()[0x1CC7] & 0xF) | (v << 4);
			break;
		case WWRegion::KOR_REV1:
			playerPointer()[0x243D] = (playerPointer()[0x243D] & 0xF) | (v << 4);
			break;
		case WWRegion::UNKNOWN:
			break;
	}
}

// Does not exist.
u8 PlayerWW::eyecolor() {
	return 0;
}
void PlayerWW::eyecolor(u8 v) { }

// Badges. Does not exist.
u8 PlayerWW::badge(int badge) {
	return 0;
}
void PlayerWW::badge(int badge, u8 v) { }

// Player ID. Is that right? Check that!
u16 PlayerWW::playerid() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x2280);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x1D10);
		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x248C);
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}
void PlayerWW::playerid(u16 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u16>(playerPointer(), 0x2280, v);
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u16>(playerPointer(), 0x1D10, v);
			break;
		case WWRegion::KOR_REV1:
			SaveUtils::Write<u16>(playerPointer(), 0x248C, v);
			break;
		case WWRegion::UNKNOWN:
			break;
	}
}

// Town ID. Is that right? Check that!
u16 PlayerWW::townid() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x2276);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x1D06);
		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x247E);
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}
void PlayerWW::townid(u16 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u16>(playerPointer(), 0x2276, v);
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u16>(playerPointer(), 0x1D06, v);
			break;
		case WWRegion::KOR_REV1:
			SaveUtils::Write<u16>(playerPointer(), 0x247E, v);
			break;
		case WWRegion::UNKNOWN:
			break;
	}
}

bool PlayerWW::exist() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x2280) != 0;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x1D10) != 0; // Seems right?
		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u16>(playerPointer(), 0x248C) != 0; // Seems right?
		case WWRegion::UNKNOWN:
			return false;
	}
	return false;
}

std::u16string PlayerWW::name() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadWWString(playerPointer(), 0x2282, 7, this->region);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadWWString(playerPointer(), 0x1D06, 7, this->region);
		case WWRegion::KOR_REV1:
			return StringUtils::ReadNLString(playerPointer(), 0x248E, 6, u'\uFFFF');
		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}
	return StringUtils::UTF8toUTF16("?");
}

// TODO.
void PlayerWW::name(std::u16string v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
		case WWRegion::KOR_REV1:
		case WWRegion::UNKNOWN:
			break;
	}
}

u32 PlayerWW::wallet() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u32>(playerPointer(), 0x1B40);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u32>(playerPointer(), 0x16C4);
		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u32>(playerPointer(), 0x1C10); // Right.
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}

void PlayerWW::wallet(u32 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u32>(playerPointer(), 0x1B40, v);
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u32>(playerPointer(), 0x16C4, v);
			break;
		case WWRegion::KOR_REV1:
			SaveUtils::Write<u32>(playerPointer(), 0x1C10, v);
			break;
		case WWRegion::UNKNOWN:
			break;
	}
}

u32 PlayerWW::bank() {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u32>(playerPointer(), 0x21E4);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u32>(playerPointer(), 0x1C70);
		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u32>(playerPointer(), 0x23E0);
		case WWRegion::UNKNOWN:
			return 0;
	}
	return 0;
}
void PlayerWW::bank(u32 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u32>(playerPointer(), 0x21E4, v);
			break;
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u32>(playerPointer(), 0x1C70, v);
			break;
		case WWRegion::KOR_REV1:
			SaveUtils::Write<u32>(playerPointer(), 0x23E0, v);
			break;
		case WWRegion::UNKNOWN:
			break;
	}
}

u32 PlayerWW::islandmedals() {
	return 0; // Does not exist here.
}
void PlayerWW::islandmedals(u32 v) { }

u32 PlayerWW::coupons() {
	return 0; // Does not exist here.
}
void PlayerWW::coupons(u32 v) { }

std::unique_ptr<Item> PlayerWW::pocket(int slot) {
	if (slot > 14)	return nullptr;
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<ItemWW>(data, offset + 0x1B22 + slot * 2);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<ItemWW>(data, offset + 0x16B2 + slot * 2);
		case WWRegion::KOR_REV1:
			return std::make_unique<ItemWW>(data, offset + 0x1BF2 + slot * 2);
		case WWRegion::UNKNOWN:
			return nullptr;
	}
	return nullptr;
}

std::unique_ptr<Item> PlayerWW::dresser(int slot) {
	if (slot > 89)	return nullptr;
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<ItemWW>(data, 0x15430 + 0xB4 * Index + slot * 2);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<ItemWW>(data, 0x11764 + 0xB4 * Index + slot * 2);
		case WWRegion::KOR_REV1:
			return std::make_unique<ItemWW>(data, 0x16800 + 0xB4 * Index + slot * 2);
		case WWRegion::UNKNOWN:
			return nullptr;
	}
	return nullptr;
}

std::unique_ptr<Pattern> PlayerWW::pattern(int slot) {
	if (slot > 9)	return nullptr;
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<PatternWW>(data, offset + 0 + slot * 0x228, this->region);
		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<PatternWW>(data, offset + 0xA94 + slot * 0x228, this->region);
		case WWRegion::KOR_REV1:
			return std::make_unique<PatternWW>(data, offset + 0x8CF + slot * 0x234, this->region);
		case WWRegion::UNKNOWN:
			return nullptr;
	}
	return nullptr;
	
}

// TPC.
u8* PlayerWW::tpcImage() {
	return nullptr; // Does not exist!
}

/* Other Offsets:
Player Bed: playerPointer()[0x1C9E] // JPN.
*/