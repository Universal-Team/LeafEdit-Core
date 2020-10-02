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

#include "PlayerWW.hpp"
#include "saveUtils.hpp"
#include "stringUtils.hpp"

#include <unistd.h>

/*
	Get and Set for the Face.
*/
u8 PlayerWW::face() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->playerPointer()[0x223C] & 0xF;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return this->playerPointer()[0x1CC6] & 0xF;

		case WWRegion::KOR_REV1:
			return this->playerPointer()[0x243C] & 0xF;

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
			SaveUtils::Write<u8>(this->playerPointer(), 0x223C, (this->playerPointer()[0x223C] & 0xF0) | (v & 0xF));
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x1CC6, (this->playerPointer()[0x1CC6] & 0xF0) | (v & 0xF));
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x243C, (this->playerPointer()[0x243C] & 0xF0) | (v & 0xF));
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the Tan aka skin color.
*/
u16 PlayerWW::tan() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->playerPointer()[0x223D] >> 4;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return this->playerPointer()[0x1CC7] >> 4;

		case WWRegion::KOR_REV1:
			return this->playerPointer()[0x243D] >> 4;

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
			SaveUtils::Write<u8>(this->playerPointer(), 0x223D, (this->playerPointer()[0x223D] & 0x0F) | (v << 4));
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x1CC7, (this->playerPointer()[0x1CC7] & 0x0F) | (v << 4));
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x243D, (this->playerPointer()[0x243D] & 0x0F) | (v << 4));
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the Gender.
*/
u8 PlayerWW::gender() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->playerPointer()[0x228A];

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return this->playerPointer()[0x1CFB];

		case WWRegion::KOR_REV1:
			return this->playerPointer()[0x249A];

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
			SaveUtils::Write<u8>(this->playerPointer(), 0x228A, v);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x1CFB, v);
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x249A, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the HairStyle.
*/
u8 PlayerWW::hairstyle() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->playerPointer()[0x223C] >> 4;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return this->playerPointer()[0x1CC6] >> 4;

		case WWRegion::KOR_REV1:
			return this->playerPointer()[0x243C] >> 4;

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
			SaveUtils::Write<u8>(this->playerPointer(), 0x223C, (this->playerPointer()[0x223C] & 0x0F) | (v << 4));
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x1CC6, (this->playerPointer()[0x1CC6] & 0x0F) | (v << 4));
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x243C, (this->playerPointer()[0x243C] & 0x0F) | (v << 4));
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the HairColor.
*/
u8 PlayerWW::haircolor() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->playerPointer()[0x223D] & 0xF;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return this->playerPointer()[0x1CC7] & 0xF;

		case WWRegion::KOR_REV1:
			return this->playerPointer()[0x243D] & 0xF;

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
			SaveUtils::Write<u8>(this->playerPointer(), 0x223D, (this->playerPointer()[0x223D] & 0xF0) | (v & 0xF));
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x1CC7, (this->playerPointer()[0x1CC7] & 0xF0) | (v & 0xF));
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u8>(this->playerPointer(), 0x243D, (this->playerPointer()[0x243D] & 0xF0) | (v & 0xF));
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the EyeColor.
	EyeColor is handled on facetype for Wild World.
*/
u8 PlayerWW::eyecolor() const {
	return 0;
}
void PlayerWW::eyecolor(u8 v) { }

/*
	Get and Set for the Player Badges.
	Does not exist on Wild World.
*/
u8 PlayerWW::badge(int badge) const {
	return 0;
}
void PlayerWW::badge(int badge, u8 v) { }

/*
	Get and Set for the Player ID.
*/
u16 PlayerWW::playerid() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x2280);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x1D04);

		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x248C);

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
			SaveUtils::Write<u16>(this->playerPointer(), 0x2280, v);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u16>(this->playerPointer(), 0x1D04, v);
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u16>(this->playerPointer(), 0x248C, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the Town ID.
*/
u16 PlayerWW::townid() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x2276);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x1CFC);

		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x247E);

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
			SaveUtils::Write<u16>(this->playerPointer(), 0x2276, v);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u16>(this->playerPointer(), 0x1CFC, v);
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u16>(this->playerPointer(), 0x247E, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the Town Name.
*/
std::u16string PlayerWW::townname() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadUTF8String(this->playerPointer(), 0x2278, 8, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadUTF8String(this->playerPointer(), 0x1CFE, 6, this->region); // Correct?

		case WWRegion::KOR_REV1:
			return StringUtils::ReadUTF16String(this->playerPointer(), 0x2480, 6); // Correct?

		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}

	return StringUtils::UTF8toUTF16("?");
}

void PlayerWW::townname(std::u16string v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			StringUtils::WriteUTF8String(this->playerPointer(), v, 0x2278, 8, this->region);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			StringUtils::WriteUTF8String(this->playerPointer(), v, 0x1CFE, 6, this->region); // Correct?
			break;

		case WWRegion::KOR_REV1:
			StringUtils::WriteUTF16String(this->playerPointer(), v, 0x2480, 6); // Correct?
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Return if the Player exist.
*/
bool PlayerWW::exist() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x2280) != 0;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x1D04) != 0; // Seems right?

		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u16>(this->playerPointer(), 0x248C) != 0; // Seems right?

		case WWRegion::UNKNOWN:
			return false;
	}

	return false;
}

/*
	Get and Set for the Player Name.
*/
std::u16string PlayerWW::name() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadUTF8String(this->playerPointer(), 0x2282, 8, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadUTF8String(this->playerPointer(), 0x1D06, 6, this->region);

		case WWRegion::KOR_REV1:
			return StringUtils::ReadUTF16String(this->playerPointer(), 0x248E, 6);

		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}

	return StringUtils::UTF8toUTF16("?");
}
void PlayerWW::name(std::u16string v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			StringUtils::WriteUTF8String(this->playerPointer(), v, 0x2282, 8, this->region);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			StringUtils::WriteUTF8String(this->playerPointer(), v, 0x1D06, 6, this->region);
			break;

		case WWRegion::KOR_REV1:
			StringUtils::WriteUTF16String(this->playerPointer(), v, 0x248E, 6);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the Wallet Amount.
*/
u32 PlayerWW::wallet() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u32>(this->playerPointer(), 0x1B40);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u32>(this->playerPointer(), 0x16C4);

		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u32>(this->playerPointer(), 0x1C10);

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
			SaveUtils::Write<u32>(this->playerPointer(), 0x1B40, v);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u32>(this->playerPointer(), 0x16C4, v);
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u32>(this->playerPointer(), 0x1C10, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the Bank Amount.
*/
u32 PlayerWW::bank() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u32>(this->playerPointer(), 0x21E4);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u32>(this->playerPointer(), 0x1C70);

		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u32>(this->playerPointer(), 0x23E0);

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
			SaveUtils::Write<u32>(this->playerPointer(), 0x21E4, v);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u32>(this->playerPointer(), 0x1C70, v);
			break;

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u32>(this->playerPointer(), 0x23E0, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/*
	Get and Set for the Meow-Coupon amount.
	Does not exist on Wild World.
*/
u32 PlayerWW::islandmedals() const {
	return 0;
}
void PlayerWW::islandmedals(u32 v) { }

/*
	Get and Set for the Meow-Coupon amount.
	Does not exist on Wild World.
*/
u32 PlayerWW::coupons() const {
	return 0;
}
void PlayerWW::coupons(u32 v) { }

/*
	Return a Player Letter.

	int slot: The slot of the letter.
*/
std::unique_ptr<Letter> PlayerWW::letter(int slot) const {
	if (slot > 9) return nullptr;

	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<LetterWW>(this->data, this->offset + 0x114C + slot * 0xF4, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<LetterWW>(this->data, this->offset + 0x110C + slot * 0x8C, this->region);

		case WWRegion::KOR_REV1:
			return std::make_unique<LetterWW>(this->data, this->offset + 0x11AC + slot * 0x100, this->region);

		case WWRegion::UNKNOWN:
			return nullptr;
	}

	return nullptr;
}

/*
	Return an item of the Player Pocket.

	int slot: The slot of the Pocket.
*/
std::unique_ptr<Item> PlayerWW::pocket(int slot) const {
	if (slot > 14) return nullptr;

	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<ItemWW>(this->data, this->offset + 0x1B22 + slot * 2);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<ItemWW>(this->data, this->offset + 0x16A6 + slot * 2);

		case WWRegion::KOR_REV1:
			return std::make_unique<ItemWW>(this->data, this->offset + 0x1BF2 + slot * 2);

		case WWRegion::UNKNOWN:
			return nullptr;
	}

	return nullptr;
}

/*
	Return an item of the Player Dresser.

	int slot: The slot of the Dresser.
*/
std::unique_ptr<Item> PlayerWW::dresser(int slot) const {
	if (slot > 89) return nullptr;

	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<ItemWW>(this->data, 0x15430 + 0xB4 * Index + slot * 2);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<ItemWW>(this->data, 0x11764 + 0xB4 * Index + slot * 2);

		case WWRegion::KOR_REV1:
			return std::make_unique<ItemWW>(this->data, 0x16800 + 0xB4 * Index + slot * 2);

		case WWRegion::UNKNOWN:
			return nullptr;
	}

	return nullptr;
}

/*
	Return a Player Pattern.

	int slot: The slot of the pattern.
*/
std::unique_ptr<Pattern> PlayerWW::pattern(int slot) const {
	if (slot > 7) return nullptr;

	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<PatternWW>(data, offset + 0 + slot * 0x228, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<PatternWW>(data, offset + 0 + slot * 0x220, this->region);

		case WWRegion::KOR_REV1:
			return std::make_unique<PatternWW>(data, offset + 0 + slot * 0x234, this->region);

		case WWRegion::UNKNOWN:
			return nullptr;
	}

	return nullptr;

}

/*
	Return a TPC Image buffer pointer.
	Does not exist on Wild World.
*/
u8* PlayerWW::tpcImage() const { return nullptr; }

/*
	Dump a player to file.

	const std::string filename: The filename where the dump should be stored at.
*/
void PlayerWW::dumpPlayer(const std::string fileName) {
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
bool PlayerWW::injectPlayer(const std::string fileName) {
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

/*
	Other Offsets:
	Player Bed: this->playerPointer()[0x1C9E] // JPN.
*/