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
#include "stringUtils.hpp"

// Face. TODO
u8 PlayerWW::face() {
	return 0;
}
void PlayerWW::face(u8 v) { }

// Tan. TODO
u16 PlayerWW::tan() {
	return 0;
}

void PlayerWW::tan(u16 v) { }

// Gender.
u8 PlayerWW::gender() {
	return playerPointer()[0x228A];
}
void PlayerWW::gender(u8 v) {
	playerPointer()[0x228A] = v;
}

// HairStyle. TODO
u8 PlayerWW::hairstyle() {
	return 0;
}
void PlayerWW::hairstyle(u8 v) { }

// HairColor. TODO
u8 PlayerWW::haircolor() {
	return 0;
}
void PlayerWW::haircolor(u8 v) { }

// EyeColor. TODO
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
	return playerPointer()[0x2280];
}
void PlayerWW::playerid(u16 v) {
	playerPointer()[0x2280] = v;
}

// Town ID. Is that right? Check that!
u16 PlayerWW::townid() {
	return playerPointer()[0x2276];
}
void PlayerWW::townid(u16 v) {
	playerPointer()[0x2276] = v;
}

bool PlayerWW::exist() {
	return (u16)playerPointer()[0x2280] != 0;
}

std::u16string PlayerWW::name() {
	return StringUtils::ReadWWString(playerPointer(), 0x2282, 7, this->isJapanese);
}
// TODO.
void PlayerWW::name(std::u16string v) { }

u32 PlayerWW::wallet() {
	return *(u32 *)(playerPointer() + 0x1B40);
}
void PlayerWW::wallet(u32 v) {
	*reinterpret_cast<u32*>(playerPointer() + 0x1B40) = v;
}

u32 PlayerWW::bank() {
	return *(u32 *)(playerPointer() + 0x21E4);
}
void PlayerWW::bank(u32 v) {
	*reinterpret_cast<u32*>(playerPointer() + 0x21E4) = v;
}