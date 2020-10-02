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

#include "LetterWA.hpp"
#include "saveUtils.hpp"

/*
	Get and Set the Player ID.

	bool sender: If sender (true) or receiver (false).
*/
u16 LetterWA::playerid(bool sender) const {
	return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x34 : 0x0);
}
void LetterWA::playerid(u16 v, bool sender) {
	SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x34 : 0x0, v);
}

/*
	Get and Set the Player Name.

	bool sender: If sender (true) or receiver (false).
*/
std::u16string LetterWA::playername(bool sender) const {
	return StringUtils::ReadUTF16String(this->letterPointer(), sender ? 0x36 : 0x2, 8);
}
void LetterWA::playername(std::u16string v, bool sender) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, sender ? 0x36 : 0x2, 8);
}

/*
	Get and Set the Town ID.

	bool sender: If sender (true) or receiver (false).
*/
u16 LetterWA::townid(bool sender) const {
	return SaveUtils::Read<u16>(this->letterPointer(), sender ? 0x4A : 0x16);
}
void LetterWA::townid(u16 v, bool sender) {
	SaveUtils::Write<u16>(this->letterPointer(), sender ? 0x4A : 0x16, v);
}

/*
	Get and Set the Town Name.

	bool sender: If sender (true) or receiver (false).
*/
std::u16string LetterWA::townname(bool sender) const {
	return StringUtils::ReadUTF16String(this->letterPointer(), sender ? 0x4C : 0x18, 8);
}
void LetterWA::townname(std::u16string v, bool sender) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, sender ? 0x4C : 0x18, 8);
}

/*
	Get and Set the Player Index.
*/
u8 LetterWA::playerindex() const {
	return this->letterPointer()[0x30];
}
void LetterWA::playerindex(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x30, v);
}

/*
	Get and Set the Letter's intro part.
*/
std::u16string LetterWA::intro() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0x68, 32);
}
void LetterWA::intro(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0x68, 32);
}

/*
	Get and Set the Letter's body part.
*/
std::u16string LetterWA::body() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0xAA, 192);
}
void LetterWA::body(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0xAA, 192);
}

/*
	Get and Set the Letter's ending part.
*/
std::u16string LetterWA::end() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0x22C, 32);
}
void LetterWA::end(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0x22C, 32);
}

/*
	Get and Set the Name index.
*/
u8 LetterWA::nameindex() const {
	return this->letterPointer()[0x26E];
}
void LetterWA::nameindex(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x26E, v);
}

/*
	Get and Set the Letter's Paper ID.
*/
u8 LetterWA::paperid() const {
	return this->letterPointer()[0x26F];
}
void LetterWA::paperid(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x26F, v);
}

/*
	Get and Set the Letter's flags.
*/
u8 LetterWA::flag() const {
	return this->letterPointer()[0x270];
}
void LetterWA::flag(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x270, v);
}

/*
	Get and Set the Sender ID.
*/
u8 LetterWA::senderid() const {
	return this->letterPointer()[0x271];
}
void LetterWA::senderid(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x271, v);
}

/*
	Get and Set the Letter's type.
*/
u8 LetterWA::lettertype() const {
	return this->letterPointer()[0x272];
}
void LetterWA::lettertype(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x272, v);
}

/*
	Return the Letter's Attachment item.
*/
std::unique_ptr<Item> LetterWA::item() const {
	return std::make_unique<ItemWA>(this->data, this->Offset + 0x274);
}