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

#include "PatternWW.hpp"
#include "saveUtils.hpp"
#include "stringUtils.hpp"

#include <cstring>
#include <unistd.h>

/*
	Get and Set for the Pattern Name.
*/
std::u16string PatternWW::name() const {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			return StringUtils::ReadUTF8String(this->patternPointer(), 0x216, 15, this->SaveRegion);

		case WWRegion::JPN:
			return StringUtils::ReadUTF8String(this->patternPointer(), 0x212, 10, this->SaveRegion);

		case WWRegion::KOR:
			return StringUtils::ReadUTF16String(this->patternPointer(), 0x21E, 10);
	}

	return StringUtils::UTF8toUTF16("?");
}
void PatternWW::name(std::u16string v) {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			StringUtils::WriteUTF8String(this->patternPointer(), v, 0x216, 15, this->SaveRegion);
			break;

		case WWRegion::JPN:
			StringUtils::WriteUTF8String(this->patternPointer(), v, 0x212, 10, this->SaveRegion);
			break;

		case WWRegion::KOR:
			StringUtils::WriteUTF16String(this->patternPointer(), v, 0x21E, 10);
			break;
	}
}

/*
	Get and Set for the Creator ID.
*/
u16 PatternWW::creatorid() const {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			return SaveUtils::Read<u16>(this->patternPointer(), 0x20A);

		case WWRegion::JPN:
			return SaveUtils::Read<u16>(this->patternPointer(), 0x208);

		case WWRegion::KOR:
			return SaveUtils::Read<u16>(this->patternPointer(), 0x20E);
	}

	return 0;
}
void PatternWW::creatorid(u16 v) {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			SaveUtils::Write<u16>(this->patternPointer(), 0x20A, v);
			break;

		case WWRegion::JPN:
			SaveUtils::Write<u16>(this->patternPointer(), 0x208, v);
			break;

		case WWRegion::KOR:
			SaveUtils::Write<u16>(this->patternPointer(), 0x20E, v);
			break;
	}
}

/*
	Get and Set for the Creator Name.
*/
std::u16string PatternWW::creatorname() const {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			return StringUtils::ReadUTF8String(this->patternPointer(), 0x20C, 8, this->SaveRegion);

		case WWRegion::JPN:
			return StringUtils::ReadUTF8String(this->patternPointer(), 0x20A, 6, this->SaveRegion);

		case WWRegion::KOR:
			return StringUtils::ReadUTF16String(this->patternPointer(), 0x210, 6);
	}

	return StringUtils::UTF8toUTF16("?");
}
void PatternWW::creatorname(std::u16string v) {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			StringUtils::WriteUTF8String(this->patternPointer(), v, 0x20C, 8, this->SaveRegion);
			break;

		case WWRegion::JPN:
			StringUtils::WriteUTF8String(this->patternPointer(), v, 0x20A, 6, this->SaveRegion);
			break;

		case WWRegion::KOR:
			StringUtils::WriteUTF16String(this->patternPointer(), v, 0x210, 6);
			break;
	}
}

/*
	Get and Set for the Creator Gender.
*/
u8 PatternWW::creatorGender() const {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			return this->patternPointer()[0x214];

		case WWRegion::JPN:
			return this->patternPointer()[0x210];

		case WWRegion::KOR:
			return this->patternPointer()[0x21C];
	}

	return 0;
}
void PatternWW::creatorGender(u8 v) {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			SaveUtils::Write<u8>(this->patternPointer(), 0x214, v);
			break;

		case WWRegion::JPN:
			SaveUtils::Write<u8>(this->patternPointer(), 0x210, v);
			break;

		case WWRegion::KOR:
			SaveUtils::Write<u8>(this->patternPointer(), 0x21C, v);
			break;
	}
}

/*
	Get and Set for the Town ID.
*/
u16 PatternWW::origtownid() const {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
		case WWRegion::JPN:
		case WWRegion::KOR:
			return SaveUtils::Read<u16>(this->patternPointer(), 0x200);
	}

	return 0;
}
void PatternWW::origtownid(u16 v) {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
		case WWRegion::JPN:
		case WWRegion::KOR:
			SaveUtils::Write<u16>(this->patternPointer(), 0x200, v);
			break;
	}
}

/*
	Get and Set for the Town Name.
*/
std::u16string PatternWW::origtownname() const {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			return StringUtils::ReadUTF8String(this->patternPointer(), 0x202, 8, this->SaveRegion);

		case WWRegion::JPN:
			return StringUtils::ReadUTF8String(this->patternPointer(), 0x202, 6, this->SaveRegion);

		case WWRegion::KOR:
			return StringUtils::ReadUTF16String(this->patternPointer(), 0x202, 6);
	}

	return StringUtils::UTF8toUTF16("?");
}
void PatternWW::origtownname(std::u16string v) {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			StringUtils::WriteUTF8String(this->patternPointer(), v, 0x202, 8, this->SaveRegion);
			break;

		case WWRegion::JPN:
			StringUtils::WriteUTF8String(this->patternPointer(), v, 0x202, 6, this->SaveRegion);
			break;

		case WWRegion::KOR:
			StringUtils::WriteUTF16String(this->patternPointer(), v, 0x202, 6);
			break;
	}
}

/*
	Overwrite player info to the pattern.

	std::unique_ptr<Player> player: A pointer to the player.
*/
void PatternWW::ownPattern(std::unique_ptr<Player> player) {
	/* Only set if player is not nullptr. */
	if (player) {
		this->creatorGender(player->gender());
		this->creatorid(player->playerid());
		this->creatorname(player->name());
		this->origtownid(player->townid());
		this->origtownname(player->townname());
	}
}

/*
	Get and Set for the Design type.
*/
u8 PatternWW::designtype() const {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			return reinterpret_cast<Byte *>(this->patternPointer() + 0x226)->Nibble1;

		case WWRegion::JPN:
			return reinterpret_cast<Byte *>(this->patternPointer() + 0x21C)->Nibble1;

		case WWRegion::KOR:
			return reinterpret_cast<Byte *>(this->patternPointer() + 0x232)->Nibble1;
	}

	return 0;
}
void PatternWW::designtype(u8 v) {
	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			SaveUtils::WriteNibble(this->patternPointer(), 0x226, true, v);
			break;

		case WWRegion::JPN:
			SaveUtils::WriteNibble(this->patternPointer(), 0x21C, true, v);
			break;

		case WWRegion::KOR:
			SaveUtils::WriteNibble(this->patternPointer(), 0x232, true, v);
			break;
	}
}

/*
	Dump a Pattern to file.

	const std::string fileName: Where to place the dump at.
*/
void PatternWW::dumpPattern(const std::string fileName) {
	/* Open File. */
	FILE* ptrn = fopen(fileName.c_str(), "wb");

	if (ptrn) {
		/* Write to file and close. */
		fwrite(this->patternPointer(), 1, this->getPatternSize(), ptrn);
		fclose(ptrn);
	}
}

/*
	Inject a Pattern from a file.

	const std::string fileName: The location of the file.
*/
void PatternWW::injectPattern(const std::string fileName) {
	if ((access(fileName.c_str(), F_OK) != 0)) return; // File not found. Do NOTHING.

	/* Open file and get size. */
	FILE* ptrn = fopen(fileName.c_str(), "rb");

	if (ptrn) {
		fseek(ptrn, 0, SEEK_END);
		u32 size = ftell(ptrn);
		fseek(ptrn, 0, SEEK_SET);

		if (size == this->getPatternSize()) {
			u8 *patternData = new u8[size];
			fread(patternData, 1, size, ptrn);

			/* Set Buffer data to save. */
			for(int i = 0; i < (int)size; i++) {
				SaveUtils::Write<u8>(this->patternPointer(), i, patternData[i]);
			}

			/* Delete Buffer. */
			delete[] patternData;

		}

		/* Close File, cause we don't need it. */
		fclose(ptrn);
	}
}

/*
	Return a Pattern Image of the pattern.

	u8 pattern: The Pattern index. Unused for Wild World.
*/
std::unique_ptr<PatternImage> PatternWW::image(u8 pattern) const {
	u32 patternOffset = this->Offset, pltOffset = this->Offset;

	switch(this->SaveRegion) {
		case WWRegion::EUR:
		case WWRegion::USA:
			patternOffset = this->Offset;
			pltOffset = this->Offset + 0x226;
			break;

		case WWRegion::JPN:
			patternOffset = this->Offset;
			pltOffset = this->Offset + 0x21C;
			break;

		case WWRegion::KOR:
			patternOffset = this->Offset;
			pltOffset = this->Offset + 0x232;
			break;
	}

	return std::make_unique<PatternImageWW>(this->PatternData, patternOffset, pltOffset);
}