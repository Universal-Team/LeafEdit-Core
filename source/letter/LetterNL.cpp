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

#include "LetterNL.hpp"
#include "saveUtils.hpp"

/*
	Get and Set the Player ID.

	bool sender: If sender (true) or receiver (false).
*/
u16 LetterNL::playerid(bool sender) const {
	return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x34 : 0x0);
}
void LetterNL::playerid(u16 v, bool sender) {
	SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x34 : 0x0, v);
}

/*
	Get and Set the Player Name.

	bool sender: If sender (true) or receiver (false).
*/
std::u16string LetterNL::playername(bool sender) const {
	return StringUtils::ReadUTF16String(this->letterPointer(), sender ? 0x36 : 0x2, 8);
}
void LetterNL::playername(std::u16string v, bool sender) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, sender ? 0x36 : 0x2, 8);
}

/*
	Get and Set the Town ID.

	bool sender: If sender (true) or receiver (false).
*/
u16 LetterNL::townid(bool sender) const {
	return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x4A : 0x16);
}
void LetterNL::townid(u16 v, bool sender) {
	SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x4A : 0x16, v);
}

/*
	Get and Set the Town Name.

	bool sender: If sender (true) or receiver (false).
*/
std::u16string LetterNL::townname(bool sender) const {
	return StringUtils::ReadUTF16String(this->letterPointer(), sender ? 0x4C : 0x18, 8);
}
void LetterNL::townname(std::u16string v, bool sender) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, sender ? 0x4C : 0x18, 8);
}

/*
	Get and Set the Player Index.
*/
u8 LetterNL::playerindex() const {
	return this->letterPointer()[0x30];
}
void LetterNL::playerindex(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x30, v);
}

/*
	Get and Set the Letter's intro part.
*/
std::u16string LetterNL::intro() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0x68, 32);
}
void LetterNL::intro(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0x68, 32);
}

/*
	Get and Set the Letter's body part.
*/
std::u16string LetterNL::body() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0xAA, 192);
}
void LetterNL::body(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0xAA, 192);
}

/*
	Get and Set the Letter's ending part.
*/
std::u16string LetterNL::end() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0x22C, 32);
}
void LetterNL::end(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0x22C, 32);
}

/*
	Get and Set the Name index.
*/
u8 LetterNL::nameindex() const {
	return this->letterPointer()[0x26E];
}
void LetterNL::nameindex(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x26E, v);
}

/*
	Get and Set the Letter's Paper ID.
*/
u8 LetterNL::paperid() const {
	return this->letterPointer()[0x26F];
}
void LetterNL::paperid(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x26F, v);
}

/*
	Get and Set the Letter's flags.
*/
u8 LetterNL::flag() const {
	return this->letterPointer()[0x270];
}
void LetterNL::flag(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x270, v);
}

/*
	Get and Set the Sender ID.
*/
u8 LetterNL::senderid() const {
	return this->letterPointer()[0x271];
}
void LetterNL::senderid(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x271, v);
}

/*
	Get and Set the Letter's type.
*/
u8 LetterNL::lettertype() const {
	return this->letterPointer()[0x272];
}
void LetterNL::lettertype(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x272, v);
}

/*
	Return the Letter's Attachment item.
*/
std::unique_ptr<Item> LetterNL::item() const {
	return std::make_unique<ItemNL>(this->data, this->Offset + 0x274);
}