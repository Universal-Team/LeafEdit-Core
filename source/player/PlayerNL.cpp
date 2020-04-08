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

#include "PlayerNL.hpp"
#include "saveUtils.hpp"
#include "stringUtils.hpp"

// Face.
u8 PlayerNL::face() {
	return playerPointer()[0x06];
}
void PlayerNL::face(u8 v) {
	playerPointer()[0x06] = v;
}

// Tan.
u16 PlayerNL::tan() {
	return SaveUtils::Read<u16>(playerPointer(), 0x08);
}
void PlayerNL::tan(u16 v) {
	SaveUtils::Write<u16>(playerPointer(), 0x08, v);
}

// Gender.
u8 PlayerNL::gender() {
	return playerPointer()[0x55BA];
}
void PlayerNL::gender(u8 v) {
	playerPointer()[0x55BA] = v;
}

// HairStyle.
u8 PlayerNL::hairstyle() {
	return playerPointer()[0x04];
}
void PlayerNL::hairstyle(u8 v) {
	playerPointer()[0x04] = v;
}

// HairColor.
u8 PlayerNL::haircolor() {
	return playerPointer()[0x05];
}
void PlayerNL::haircolor(u8 v) {
	playerPointer()[0x05] = v;
}

// EyeColor.
u8 PlayerNL::eyecolor() {
	return playerPointer()[0x07];
}
void PlayerNL::eyecolor(u8 v) {
	playerPointer()[0x07] = v;
}

// Badges. 
u8 PlayerNL::badge(int badge) {
	return playerPointer()[0x569C + badge];
}
void PlayerNL::badge(int badge, u8 v) {
	playerPointer()[0x569C + badge] = v;
}

// Player ID. 
u16 PlayerNL::playerid() {
	return SaveUtils::Read<u16>(playerPointer(), 0x55A6);
}
void PlayerNL::playerid(u16 v) {
	SaveUtils::Write<u16>(playerPointer(), 0x55A6, v);
}

// Town ID. 
u16 PlayerNL::townid() {
	return SaveUtils::Read<u16>(playerPointer(), 0x55BC);
}
void PlayerNL::townid(u16 v) {
	SaveUtils::Write<u16>(playerPointer(), 0x55BC, v);
}

bool PlayerNL::exist() {
	return SaveUtils::Read<u16>(playerPointer(), 0x55A6) != 0;
}

std::u16string PlayerNL::name() {
	return StringUtils::ReadNLString(playerPointer(), 0x55A8, 8, u'\uFFFF');
}
// TODO.
void PlayerNL::name(std::u16string v) { }

u32 PlayerNL::wallet() {
	this->walletValue = EncryptedInt32(SaveUtils::Read<u64>(playerPointer(), 0x6E38));
	return walletValue.value;
}
void PlayerNL::wallet(u32 v) {
	this->walletValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->walletValue.encrypt(encryptedInt, encryptionData);
	SaveUtils::Write<u32>(playerPointer(), 0x6E38, encryptedInt);
	SaveUtils::Write<u32>(playerPointer(), 0x6E3C, encryptionData);
}


u32 PlayerNL::bank() {
	this->bankValue = EncryptedInt32(SaveUtils::Read<u64>(playerPointer(), 0x6B6C));
	return bankValue.value;
}
void PlayerNL::bank(u32 v) {
	this->bankValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->walletValue.encrypt(encryptedInt, encryptionData);
	SaveUtils::Write<u32>(playerPointer(), 0x6B6C, encryptedInt);
	SaveUtils::Write<u32>(playerPointer(), 0x6B70, encryptionData);
}

u32 PlayerNL::islandmedals() {
	this->islandValue = EncryptedInt32(SaveUtils::Read<u64>(playerPointer(), 0x6B7C));
	return islandValue.value;
}
void PlayerNL::islandmedals(u32 v) {
	this->islandValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->islandValue.encrypt(encryptedInt, encryptionData);
	SaveUtils::Write<u32>(playerPointer(), 0x6B7C, encryptedInt);
	SaveUtils::Write<u32>(playerPointer(), 0x6B80, encryptionData);
}

u32 PlayerNL::coupons() {
	return 0; // Does not exist here.
}
void PlayerNL::coupons(u32 v) { }

std::unique_ptr<Item> PlayerNL::pocket(int slot) {
	if (slot > 15)	return nullptr;
	return std::make_unique<ItemNL>(data, offset + 0x6BB0 + slot * 4);
}

std::unique_ptr<Item> PlayerNL::dresser(int slot) {
	if (slot > 179)	return nullptr;
	return std::make_unique<ItemNL>(data, offset + 0x8E18 + slot * 4);
}

std::unique_ptr<Item> PlayerNL::islandbox(int slot) {
	if (slot > 39)	return nullptr;
	return std::make_unique<ItemNL>(data, offset + 0x6E40 + slot * 4);
}

// TPC.
u8* PlayerNL::tpcImage() {
	return nullptr;
}