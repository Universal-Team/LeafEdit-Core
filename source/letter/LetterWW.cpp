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

#include "LetterWW.hpp"
#include "saveUtils.hpp"

/* Player ID. */
u16 LetterWW::playerid(bool sender) const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x22 : 0xA);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x1C : 0x8);

		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x2E : 0xE);

		case WWRegion::UNKNOWN:
			return 0;
	}

	return 0;
}
void LetterWW::playerid(u16 v, bool sender) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x22 : 0xA, v);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x1C : 0x8, v);

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x2E : 0xE, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Player Name. */
std::u16string LetterWW::playername(bool sender) const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), sender ? 0x24 : 0xC, 8, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), sender ? 0x1E : 0xA, 6, this->region);

		case WWRegion::KOR_REV1:
			return StringUtils::ReadUTF16String(this->letterPointer(), sender ? 0x30 : 0x10, 6);

		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}

	return StringUtils::UTF8toUTF16("?");
}
void LetterWW::playername(std::u16string v, bool sender) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, sender ? 0x24 : 0xC, 8, this->region);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, sender ? 0x1E : 0xA, 6, this->region);
			break;

		case WWRegion::KOR_REV1:
			StringUtils::WriteUTF16String(this->letterPointer(), v, sender ? 0x30 : 0x10, 6);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Town ID. */
u16 LetterWW::townid(bool sender) const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x18 : 0x0);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x14 : 0x0);

		case WWRegion::KOR_REV1:
			return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x20 : 0x0);

		case WWRegion::UNKNOWN:
			return 0;
	}

	return 0;
}
void LetterWW::townid(u16 v, bool sender) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x18 : 0x0, v);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x14 : 0x0, v);

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x20 : 0x0, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Town Name. */
std::u16string LetterWW::townname(bool sender) const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), sender ? 0x1A : 0x2, 8, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), sender ? 0x16 : 0x2, 6, this->region);

		case WWRegion::KOR_REV1:
			return StringUtils::ReadUTF16String(this->letterPointer(), sender ? 0x22 : 0x2, 6);

		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}

	return StringUtils::UTF8toUTF16("?");
}
void LetterWW::townname(std::u16string v, bool sender) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, sender ? 0x1A : 0x2, 8, this->region);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, sender ? 0x16 : 0x2, 6, this->region);
			break;

		case WWRegion::KOR_REV1:
			StringUtils::WriteUTF16String(this->letterPointer(), v, sender ? 0x22 : 0x2, 6);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Player Index. TODO? */
u8 LetterWW::playerindex() const {
	return 0;
}
void LetterWW::playerindex(u8 v) { }

/* Letter intro part. */
std::u16string LetterWW::intro() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), 0x30, 24, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), 0x28, 10, this->region);

		case WWRegion::KOR_REV1:
			return StringUtils::ReadUTF16String(this->letterPointer(), 0x40, 10);

		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}

	return StringUtils::UTF8toUTF16("?");
}
void LetterWW::intro(std::u16string v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, 0x30, 24, this->region);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, 0x28, 10, this->region);
			break;

		case WWRegion::KOR_REV1:
			StringUtils::WriteUTF16String(this->letterPointer(), v, 0x40, 10);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Letter body part. */
std::u16string LetterWW::body() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), 0x48, 128, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), 0x32, 64, this->region);

		case WWRegion::KOR_REV1:
			return StringUtils::ReadUTF16String(this->letterPointer(), 0x54, 64);

		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}

	return StringUtils::UTF8toUTF16("?");
}
void LetterWW::body(std::u16string v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, 0x48, 128, this->region);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, 0x32, 64, this->region);
			break;

		case WWRegion::KOR_REV1:
			StringUtils::WriteUTF16String(this->letterPointer(), v, 0x54, 64);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Letter end part. */
std::u16string LetterWW::end() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), 0xC8, 32, this->region);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return StringUtils::ReadUTF8String(this->letterPointer(), 0x72, 16, this->region);

		case WWRegion::KOR_REV1:
			return StringUtils::ReadUTF16String(this->letterPointer(), 0xD4, 16);

		case WWRegion::UNKNOWN:
			return StringUtils::UTF8toUTF16("?");
	}

	return StringUtils::UTF8toUTF16("?");
}
void LetterWW::end(std::u16string v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, 0xC8, 32, this->region);
			break;

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			StringUtils::WriteUTF8String(this->letterPointer(), v, 0x72, 16, this->region);
			break;

		case WWRegion::KOR_REV1:
			StringUtils::WriteUTF16String(this->letterPointer(), v, 0xD4, 16);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Name index. TODO? */
u8 LetterWW::nameindex() const {
	return 0;
}
void LetterWW::nameindex(u8 v) { }

/* Paper ID. */
u8 LetterWW::paperid() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->letterPointer()[0xE9];

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return this->letterPointer()[0x83];

		case WWRegion::KOR_REV1:
			return this->letterPointer()[0xF5];

		case WWRegion::UNKNOWN:
			return 0;
	}

	return 0;
}
void LetterWW::paperid(u8 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u8>(this->letterPointer(), 0xE9, v);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u8>(this->letterPointer(), 0x83, v);

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u8>(this->letterPointer(), 0xF5, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Letter flags. */
u8 LetterWW::flag() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return this->letterPointer()[0xEA];

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return this->letterPointer()[0x84];

		case WWRegion::KOR_REV1:
			return this->letterPointer()[0xF6];

		case WWRegion::UNKNOWN:
			return 0;
	}

	return 0;
}
void LetterWW::flag(u8 v) {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			SaveUtils::Write<u8>(this->letterPointer(), 0xEA, v);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			SaveUtils::Write<u8>(this->letterPointer(), 0x84, v);

		case WWRegion::KOR_REV1:
			SaveUtils::Write<u8>(this->letterPointer(), 0xF6, v);
			break;

		case WWRegion::UNKNOWN:
			break;
	}
}

/* Sender ID. AC:WW handles it different. */
u8 LetterWW::senderid() const {
	return 0;
}
void LetterWW::senderid(u8 v) { }

/* Letter type. TODO? */
u8 LetterWW::lettertype() const {
	return 0;
}
void LetterWW::lettertype(u8 v) { }

/* Attachment item. */
std::unique_ptr<Item> LetterWW::item() const {
	switch(this->region) {
		case WWRegion::USA_REV0:
		case WWRegion::USA_REV1:
		case WWRegion::EUR_REV1:
			return std::make_unique<ItemWW>(this->data, this->Offset + 0xEC);

		case WWRegion::JPN_REV0:
		case WWRegion::JPN_REV1:
			return std::make_unique<ItemWW>(this->data, this->Offset + 0x86);

		case WWRegion::KOR_REV1:
			return std::make_unique<ItemWW>(this->data, this->Offset + 0xF8);

		case WWRegion::UNKNOWN:
			return nullptr;
	}

	return nullptr;
}