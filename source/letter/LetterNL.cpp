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

/* Player ID. */
u16 LetterNL::playerid() const {
	return SaveUtils::Read<u16>(this->letterPointer(), 0x0);
}
void LetterNL::playerid(u16 v) {
	SaveUtils::Write<u16>(this->letterPointer(), 0x0, v);
}

/* Player Name. */
std::u16string LetterNL::playername() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0x2, 8);
}
void LetterNL::playername(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0x2, 8);
}

/* Town ID. */
u16 LetterNL::townid() const {
	return SaveUtils::Read<u16>(this->letterPointer(), 0x16);
}
void LetterNL::townid(u16 v) {
	SaveUtils::Write<u16>(this->letterPointer(), 0x16, v);
}

/* Town Name. */
std::u16string LetterNL::townname() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0x18, 8);
}
void LetterNL::townname(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0x18, 8);
}

/* Player Index. */
u8 LetterNL::playerindex() const {
	return this->letterPointer()[0x30];
}
void LetterNL::playerindex(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x30, v);
}

/* Letter intro part. */
std::u16string LetterNL::intro() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0x68, 31);
}
void LetterNL::intro(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0x68, 31);
}

/* Letter body part. */
std::u16string LetterNL::body() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0xAA, 191);
}
void LetterNL::body(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0xAA, 191);
}

/* Letter end part. */
std::u16string LetterNL::end() const {
	return StringUtils::ReadUTF16String(this->letterPointer(), 0x22C, 31);
}
void LetterNL::end(std::u16string v) {
	StringUtils::WriteUTF16String(this->letterPointer(), v, 0x22C, 31);
}

/* Name index. */
u8 LetterNL::nameindex() const {
	return this->letterPointer()[0x26E];
}
void LetterNL::nameindex(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x26E, v);
}

/* Paper ID. */
u8 LetterNL::paperid() const {
	return this->letterPointer()[0x26F];
}
void LetterNL::paperid(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x26F, v);
}

/* Letter flags. */
u8 LetterNL::flag() const {
	return this->letterPointer()[0x270];
}
void LetterNL::flag(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x270, v);
}

/* Sender ID. */
u8 LetterNL::senderid() const {
	return this->letterPointer()[0x271];
}
void LetterNL::senderid(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x271, v);
}

/* Letter type. */
u8 LetterNL::lettertype() const {
	return this->letterPointer()[0x272];
}
void LetterNL::lettertype(u8 v) {
	SaveUtils::Write<u8>(this->letterPointer(), 0x272, v);
}

/* Attachment item. */
std::unique_ptr<Item> LetterNL::item() const {
	return std::make_unique<ItemNL>(this->data, this->Offset + 0x274);
}