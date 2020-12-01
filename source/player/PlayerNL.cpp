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

#include "PlayerNL.hpp"
#include "saveUtils.hpp"
#include "stringUtils.hpp"

#include <cstring>
#include <unistd.h>

/*
	Get and Set for the Face.
*/
u8 PlayerNL::face() const { return this->playerPointer()[0x06]; };
void PlayerNL::face(u8 v) { SaveUtils::Write<u8>(this->playerPointer(), 0x06, v); };

/*
	Get and Set for the Tan aka skin color.
*/
u16 PlayerNL::tan() const { return SaveUtils::Read<u16>(this->playerPointer(), 0x08); };
void PlayerNL::tan(u16 v) { SaveUtils::Write<u16>(this->playerPointer(), 0x08, v); };

/*
	Get and Set for the Gender.
*/
u8 PlayerNL::gender() const { return this->playerPointer()[0x55BA]; };
void PlayerNL::gender(u8 v) { SaveUtils::Write<u8>(this->playerPointer(), 0x55BA, v); };

/*
	Get and Set for the HairStyle.
*/
u8 PlayerNL::hairstyle() const { return this->playerPointer()[0x04]; };
void PlayerNL::hairstyle(u8 v) { SaveUtils::Write<u8>(this->playerPointer(), 0x04, v); };

/*
	Get and Set for the HairColor.
*/
u8 PlayerNL::haircolor() const { return this->playerPointer()[0x05]; };
void PlayerNL::haircolor(u8 v) { SaveUtils::Write<u8>(this->playerPointer(), 0x05, v); };

/*
	Get and Set for the EyeColor.
*/
u8 PlayerNL::eyecolor() const { return this->playerPointer()[0x07]; };
void PlayerNL::eyecolor(u8 v) { SaveUtils::Write<u8>(this->playerPointer(), 0x07, v); };

/*
	Get and Set for the Player Badges.
*/
u8 PlayerNL::badge(int badge) const { return this->playerPointer()[0x569C + badge]; };
void PlayerNL::badge(int badge, u8 v) { SaveUtils::Write<u8>(this->playerPointer(), 0x569C + badge, v); };

/*
	Get and Set for the Player ID.
*/
u16 PlayerNL::playerid() const { return SaveUtils::Read<u16>(this->playerPointer(), 0x55A6); };
void PlayerNL::playerid(u16 v) { SaveUtils::Write<u16>(this->playerPointer(), 0x55A6, v); };

/*
	Get and Set for the Town ID.
*/
u16 PlayerNL::townid() const { return SaveUtils::Read<u16>(this->playerPointer(), 0x55BC); };
void PlayerNL::townid(u16 v) { SaveUtils::Write<u16>(this->playerPointer(), 0x55BC, v); };

/*
	Get and Set for the Town Name.
*/
std::u16string PlayerNL::townname() const { return StringUtils::UTF8toUTF16("?"); };
void PlayerNL::townname(std::u16string v) { };

/*
	Return if the Player exist.
*/
bool PlayerNL::exist() const { return SaveUtils::Read<u16>(this->playerPointer(), 0x55A6) != 0; };

/*
	Get and Set for the Player Name.
*/
std::u16string PlayerNL::name() const { return StringUtils::ReadUTF16String(this->playerPointer(), 0x55A8, 8); };
void PlayerNL::name(std::u16string v) { StringUtils::WriteUTF16String(this->playerPointer(), v, 0x55A8, 8); };

/*
	Get and Set for the Wallet Amount.
*/
u32 PlayerNL::wallet() const {
	this->WalletValue = EncryptedInt32(SaveUtils::Read<u64>(this->playerPointer(), 0x6E38));
	return this->WalletValue.value;
}
void PlayerNL::wallet(u32 v) {
	this->WalletValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->WalletValue.encrypt(encryptedInt, encryptionData);

	SaveUtils::Write<u32>(this->playerPointer(), 0x6E38, encryptedInt);
	SaveUtils::Write<u32>(this->playerPointer(), 0x6E3C, encryptionData);
}

/*
	Get and Set for the Bank Amount.
*/
u32 PlayerNL::bank() const {
	this->BankValue = EncryptedInt32(SaveUtils::Read<u64>(this->playerPointer(), 0x6B6C));
	return this->BankValue.value;
}
void PlayerNL::bank(u32 v) {
	this->BankValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->BankValue.encrypt(encryptedInt, encryptionData);

	SaveUtils::Write<u32>(this->playerPointer(), 0x6B6C, encryptedInt);
	SaveUtils::Write<u32>(this->playerPointer(), 0x6B70, encryptionData);
}

/*
	Get and Set for the Island Medal amount.
*/
u32 PlayerNL::islandmedals() const {
	this->IslandValue = EncryptedInt32(SaveUtils::Read<u64>(this->playerPointer(), 0x6B7C));
	return this->IslandValue.value;
}
void PlayerNL::islandmedals(u32 v) {
	this->IslandValue.value = v; // Set Value.
	u32 encryptedInt = 0, encryptionData = 0;
	this->IslandValue.encrypt(encryptedInt, encryptionData);

	SaveUtils::Write<u32>(this->playerPointer(), 0x6B7C, encryptedInt);
	SaveUtils::Write<u32>(this->playerPointer(), 0x6B80, encryptionData);
}

/*
	Return a Player Letter.

	u8 slot: The slot of the letter.
*/
std::unique_ptr<Letter> PlayerNL::letter(u8 slot) const {
	if (slot > 9) return nullptr;

	return std::make_unique<LetterNL>(this->PlayerData, this->Offset + 0x6F38 + (0x280 * slot));
}

/*
	Return an item of the Player Pocket.

	u8 slot: The slot of the Pocket.
*/
std::unique_ptr<Item> PlayerNL::pocket(u8 slot) const {
	if (slot > 15) return nullptr;

	return std::make_unique<ItemNL>(this->PlayerData, this->Offset + 0x6BB0 + slot * 4);
}

/*
	Return an item of the Player Dresser.

	u8 slot: The slot of the Dresser.
*/
std::unique_ptr<Item> PlayerNL::dresser(u8 slot) const {
	if (slot > 179) return nullptr;

	return std::make_unique<ItemNL>(this->PlayerData, this->Offset + 0x8E18 + slot * 4);
}

/*
	Return an item of the Player Islandbox.

	u8 slot: The slot of the islandbox.
*/
std::unique_ptr<Item> PlayerNL::islandbox(u8 slot) const {
	if (slot > 39) return nullptr;

	return std::make_unique<ItemNL>(this->PlayerData, this->Offset + 0x6E40 + slot * 4);
}

/*
	Return a Player Pattern.

	u8 slot: The slot of the pattern.
*/
std::unique_ptr<Pattern> PlayerNL::pattern(u8 slot) const {
	if (slot > 9) return nullptr;

	return std::make_unique<PatternNL>(this->PlayerData, this->Offset + 0x2C + slot * 0x870);
}

/*
	Return a TPC Image buffer pointer.
*/
u8 *PlayerNL::tpcImage() const {
	u8 *TPCBuffer = nullptr;

	if (SaveUtils::Read<u32>(this->playerPointer(), 0x5720) == 1) {
		if (SaveUtils::Read<u16>(this->playerPointer(), 0x5724) == 0xD8FF) { // 0xFFD8 = JPEG File Marker.
			TPCBuffer = new u8[0x1400];

			/* Put the data to buffer. */
			memcpy(TPCBuffer, this->playerPointer() + 0x5724, 0x1400);
		}
	}

	return TPCBuffer;
}

/*
	Dump a player to file.

	const std::string filename: The filename where the dump should be stored at.
*/
void PlayerNL::dumpPlayer(const std::string fileName) {
	/* Open File. */
	FILE* pl = fopen(fileName.c_str(), "w");

	if (pl) {
		/* Write to file and close. */
		fwrite(this->playerPointer(), 1, this->getPlayerSize(), pl);
		fclose(pl);
	}
}

/*
	Inject a Player from a file.

	const std::string fileName: The location of the file.
*/
bool PlayerNL::injectPlayer(const std::string fileName) {
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