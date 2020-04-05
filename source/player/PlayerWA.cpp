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

#include "PlayerWA.hpp"
#include "stringUtils.hpp"

// Face.
u8 PlayerWA::face() {
	return playerPointer()[0x06];
}
void PlayerWA::face(u8 v) {
	playerPointer()[0x06] = v;
}

// Tan.
u16 PlayerWA::tan() {
	return playerPointer()[0x08];
}
void PlayerWA::tan(u16 v) {
	playerPointer()[0x08] = v;
}

// Gender.
u8 PlayerWA::gender() {
	return playerPointer()[0x55BA];
}
void PlayerWA::gender(u8 v) {
	playerPointer()[0x55BA] = v;
}

// HairStyle.
u8 PlayerWA::hairstyle() {
	return playerPointer()[0x04];
}
void PlayerWA::hairstyle(u8 v) {
	playerPointer()[0x04] = v;
}

// HairColor.
u8 PlayerWA::haircolor() {
	return playerPointer()[0x05];
}
void PlayerWA::haircolor(u8 v) {
	playerPointer()[0x05] = v;
}

// EyeColor.
u8 PlayerWA::eyecolor() {
	return playerPointer()[0x07];
}
void PlayerWA::eyecolor(u8 v) {
	playerPointer()[0x07] = v;
}

// Badges.
u8 PlayerWA::badge(int badge) {
	return playerPointer()[0x569C + badge];
}
void PlayerWA::badge(int badge, u8 v) {
	playerPointer()[0x569C + badge] = v;
}

// Player ID.
u16 PlayerWA::playerid() {
	return playerPointer()[0x55A6];
}
void PlayerWA::playerid(u16 v) {
	playerPointer()[0x55A6] = v;
}

// Town ID.
u16 PlayerWA::townid() {
	return playerPointer()[0x55BC];
}
void PlayerWA::townid(u16 v) {
	playerPointer()[0x55BC] = v;
}

bool PlayerWA::exist() {
	return (u16)playerPointer()[0x55A6] != 0;
}

std::u16string PlayerWA::name() {
	return StringUtils::ReadNLString(playerPointer(), 0x55A8, 8, u'\uFFFF');
}
// TODO.
void PlayerWA::name(std::u16string v) { }

u32 PlayerWA::wallet() {
	this->walletValue = EncryptedInt32(*(u64 *)(playerPointer() + 0x6F08));
	return walletValue.value;
}
void PlayerWA::wallet(u32 v) {
	this->walletValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->walletValue.encrypt(encryptedInt, encryptionData);
	*reinterpret_cast<u32*>(playerPointer() + 0x6F08) = encryptedInt;
	*reinterpret_cast<u32*>(playerPointer() + 0x6F0C) = encryptionData;
}

u32 PlayerWA::bank() {
	this->bankValue = EncryptedInt32(*(u64 *)(playerPointer() + 0x6B8C));
	return bankValue.value;
}
void PlayerWA::bank(u32 v) {
	this->bankValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->walletValue.encrypt(encryptedInt, encryptionData);
	*reinterpret_cast<u32*>(playerPointer() + 0x6B8C) = encryptedInt;
	*reinterpret_cast<u32*>(playerPointer() + 0x6B90) = encryptionData;
}