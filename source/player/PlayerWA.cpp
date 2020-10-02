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

#include "PlayerWA.hpp"
#include "saveUtils.hpp"
#include "stringUtils.hpp"

#include <cstring>
#include <unistd.h>

/*
	Get and Set for the Face.
*/
u8 PlayerWA::face() const {
	return this->playerPointer()[0x06];
}
void PlayerWA::face(u8 v) {
	SaveUtils::Write<u8>(this->playerPointer(), 0x06, v);
}

/*
	Get and Set for the Tan aka skin color.
*/
u16 PlayerWA::tan() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x08);
}
void PlayerWA::tan(u16 v) {
	SaveUtils::Write<u16>(this->playerPointer(), 0x08, v);
}

/*
	Get and Set for the Gender.
*/
u8 PlayerWA::gender() const {
	return this->playerPointer()[0x55BA];
}
void PlayerWA::gender(u8 v) {
	SaveUtils::Write<u8>(this->playerPointer(), 0x55BA, v);
}

/*
	Get and Set for the HairStyle.
*/
u8 PlayerWA::hairstyle() const {
	return this->playerPointer()[0x04];
}
void PlayerWA::hairstyle(u8 v) {
	SaveUtils::Write<u8>(this->playerPointer(), 0x04, v);
}

/*
	Get and Set for the HairColor.
*/
u8 PlayerWA::haircolor() const {
	return this->playerPointer()[0x05];
}
void PlayerWA::haircolor(u8 v) {
	SaveUtils::Write<u8>(this->playerPointer(), 0x05, v);
}

/*
	Get and Set for the EyeColor.
*/
u8 PlayerWA::eyecolor() const {
	return this->playerPointer()[0x07];
}
void PlayerWA::eyecolor(u8 v) {
	SaveUtils::Write<u8>(this->playerPointer(), 0x07, v);
}

/*
	Get and Set for the Player Badges.
*/
u8 PlayerWA::badge(int badge) const {
	return this->playerPointer()[0x569C + badge];
}
void PlayerWA::badge(int badge, u8 v) {
	SaveUtils::Write<u8>(this->playerPointer(), 0x569C + badge, v);
}

/*
	Get and Set for the Player ID.
*/
u16 PlayerWA::playerid() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x55A6);
}
void PlayerWA::playerid(u16 v) {
	SaveUtils::Write<u16>(this->playerPointer(), 0x55A6, v);
}

/*
	Get and Set for the Town ID.
*/
u16 PlayerWA::townid() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x55BC);
}
void PlayerWA::townid(u16 v) {
	SaveUtils::Write<u16>(this->playerPointer(), 0x55BC, v);
}

/*
	Get and Set for the Town Name.
*/
std::u16string PlayerWA::townname() const {
	return StringUtils::UTF8toUTF16("?");
}
void PlayerWA::townname(std::u16string v) { }

/*
	Return if the Player exist.
*/
bool PlayerWA::exist() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x55A6) != 0;
}

/*
	Get and Set for the Player Name.
*/
std::u16string PlayerWA::name() const {
	return StringUtils::ReadUTF16String(this->playerPointer(), 0x55A8, 8);
}
void PlayerWA::name(std::u16string v) {
	StringUtils::WriteUTF16String(this->playerPointer(), v, 0x55A8, 8);
}

/*
	Get and Set for the Wallet Amount.
*/
u32 PlayerWA::wallet() const {
	this->walletValue = EncryptedInt32(SaveUtils::Read<u64>(this->playerPointer(), 0x6F08));
	return walletValue.value;
}
void PlayerWA::wallet(u32 v) {
	this->walletValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->walletValue.encrypt(encryptedInt, encryptionData);

	SaveUtils::Write<u32>(this->playerPointer(), 0x6F08, encryptedInt);
	SaveUtils::Write<u32>(this->playerPointer(), 0x6F0C, encryptionData);
}

/*
	Get and Set for the Bank Amount.
*/
u32 PlayerWA::bank() const {
	this->bankValue = EncryptedInt32(SaveUtils::Read<u64>(this->playerPointer(), 0x6B8C));
	return bankValue.value;
}
void PlayerWA::bank(u32 v) {
	this->bankValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->bankValue.encrypt(encryptedInt, encryptionData);

	SaveUtils::Write<u32>(this->playerPointer(), 0x6B8C, encryptedInt);
	SaveUtils::Write<u32>(this->playerPointer(), 0x6B90, encryptionData);
}

/*
	Get and Set for the Island Medal amount.
*/
u32 PlayerWA::islandmedals() const {
	this->islandValue = EncryptedInt32(SaveUtils::Read<u64>(this->playerPointer(), 0x6B9C));
	return islandValue.value;
}
void PlayerWA::islandmedals(u32 v) {
	this->islandValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->islandValue.encrypt(encryptedInt, encryptionData);

	SaveUtils::Write<u32>(this->playerPointer(), 0x6B9C, encryptedInt);
	SaveUtils::Write<u32>(this->playerPointer(), 0x6BA0, encryptionData);
}

/*
	Get and Set for the Meow-Coupon amount.
*/
u32 PlayerWA::coupons() const {
	this->couponValue = EncryptedInt32(SaveUtils::Read<u64>(this->playerPointer(), 0x8D1C));
	return couponValue.value;
}
void PlayerWA::coupons(u32 v) {
	this->couponValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->couponValue.encrypt(encryptedInt, encryptionData);

	SaveUtils::Write<u32>(this->playerPointer(), 0x8D1C, encryptedInt);
	SaveUtils::Write<u32>(this->playerPointer(), 0x8D20, encryptionData);
}

/*
	Return a Player Letter.

	int slot: The slot of the letter.
*/
std::unique_ptr<Letter> PlayerWA::letter(int slot) const {
	if (slot > 9) return nullptr;

	return std::make_unique<LetterWA>(this->data, this->offset + 0x7008 + (0x280 * slot));
}

/*
	Return an item of the Player Pocket.

	int slot: The slot of the Pocket.
*/
std::unique_ptr<Item> PlayerWA::pocket(int slot) const {
	if (slot > 15) return nullptr;

	return std::make_unique<ItemWA>(this->data, this->offset + 0x6BD0 + slot * 4);
}

/*
	Return an item of the Player Dresser.

	int slot: The slot of the Dresser.
*/
std::unique_ptr<Item> PlayerWA::dresser(int slot) const {
	if (slot > 179) return nullptr;

	return std::make_unique<ItemWA>(this->data, this->offset + 0x92F0 + slot * 4);
}

/*
	Return an item of the Player Islandbox.

	int slot: The slot of the islandbox.
*/
std::unique_ptr<Item> PlayerWA::islandbox(int slot) const {
	if (slot > 39) return nullptr;

	return std::make_unique<ItemWA>(this->data, this->offset + 0x6F10 + slot * 4);
}

/*
	Return an item of the Player Storage.

	int slot: The slot of the storage.
*/
std::unique_ptr<Item> PlayerWA::storage(int slot) const {
	if (slot > 359) return nullptr;

	return std::make_unique<ItemWA>(this->data, (this->Index * 360) + 0x07A778 + slot * 4);
}

/*
	Return a Player Pattern.

	int slot: The slot of the pattern.
*/
std::unique_ptr<Pattern> PlayerWA::pattern(int slot) const {
	if (slot > 9) return nullptr;

	return std::make_unique<PatternWA>(this->data, this->offset + 0x2C + slot * 0x870);
}

/*
	Return a TPC Image buffer pointer.
*/
u8* PlayerWA::tpcImage() const {
	u8 *TPCBuffer = nullptr;

	if (SaveUtils::Read<u32>(this->playerPointer(), 0x5734) == 1) {
		if (SaveUtils::Read<u16>(this->playerPointer(), 0x5738) == 0xD8FF) { // 0xFFD8 = JPEG File Marker.
			TPCBuffer = new u8[0x1400];

			/* Put the data to buffer. */
			memcpy(TPCBuffer, this->playerPointer() + 0x5738, 0x1400);
		}
	}

	return TPCBuffer;
}

/*
	Dump a player to file.

	const std::string filename: The filename where the dump should be stored at.
*/
void PlayerWA::dumpPlayer(const std::string fileName) {
	/* Open File. */
	FILE* pl = fopen(fileName.c_str(), "w");

	if (pl) {
		// Write to file and close. */
		fwrite(this->playerPointer(), 1, this->getPlayerSize(), pl);
		fclose(pl);
	}
}

/*
	Inject a Player from a file.

	const std::string fileName: The location of the file.
*/
bool PlayerWA::injectPlayer(const std::string fileName) {
	bool isGood = false;
	if ((access(fileName.c_str(), F_OK) != 0)) return isGood; // File not found. Do NOTHING.

	/* Open file and get size. */
	FILE* pl = fopen(fileName.c_str(), "rb");

	if (pl) {
		fseek(pl, 0, SEEK_END);
		u32 size = ftell(pl);
		fseek(pl, 0, SEEK_SET);

		/* Check for size. */
		if (size == this->getPlayerSize()) {
			/* Create Buffer with the size and read the file. */
			u8 *playerData = new u8[size];
			fread(playerData, 1, size, pl);

			/* Set Buffer data to save. */
			for(int i = 0; i < (int)size; i++){
				SaveUtils::Write<u8>(this->playerPointer(), i, playerData[i]);
			}

			/* Free Buffer. */
			delete[] playerData;
			isGood = true;
		}

		/* Close File, cause we don't need it. */
		fclose(pl);
	}

	return isGood;
}