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

#include "PlayerHHD.hpp"
#include "saveUtils.hpp"
#include "stringUtils.hpp"

/*
	Get and Set for the HairStyle.
	(ranges from 0 to 0x1F).
*/
u8 PlayerHHD::hairstyle() const {
	return this->playerPointer()[0xC];
}
void PlayerHHD::hairstyle(u8 v) {
	if (v >= 0x0 && v <= 0x1F) this->playerPointer()[0xC] = v;
}

/*
	Get and Set for the Tan aka skin color.
	(ranges from 0 to 7).
*/
u8 PlayerHHD::tan() const {
	return this->playerPointer()[0xD];
}
void PlayerHHD::tan(u8 v) {
	if (v >= 0x0 && v <= 0x7) this->playerPointer()[0xD] = v;
}

/*
	Get and Set for the HairColor.
	(ranges from 0 to 0xF).
*/
u8 PlayerHHD::haircolor() const {
	return this->playerPointer()[0xE];
}
void PlayerHHD::haircolor(u8 v) {
	if (v >= 0x0 && v <= 0xF) this->playerPointer()[0xE] = v;
}

/*
	Get and Set for the Face.
	(ranges from 0 to 0xC).
*/
u8 PlayerHHD::face() const {
	return this->playerPointer()[0xF];
}
void PlayerHHD::face(u8 v) {
	if (v >= 0x0 && v <= 0xC) this->playerPointer()[0xF] = v;
}

/*
	Get and Set for the EyeColor.
	(ranges from 0 to 5).
*/
u8 PlayerHHD::eyecolor() const {
	return this->playerPointer()[0x10];
}
void PlayerHHD::eyecolor(u8 v) {
	if (v >= 0x0 && v <= 0x5) this->playerPointer()[0x10] = v;
}

/*
	Get and Set for the HeadWear.
	(ranges from 0x266A to 0x273E).
*/
u16 PlayerHHD::headwear() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x12);
}
void PlayerHHD::headwear(u16 v) {
	if (v >= 0x266A && v <= 0x273E) SaveUtils::Write<u16>(this->playerPointer(), 0x12, v);
}

/*
	Get and Set for the accessoires.
	(ranges from 0x273F to 0x2794).
*/
u16 PlayerHHD::accessories() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x16);
}
void PlayerHHD::accessories(u16 v) {
	if (v >= 0x273F && v <= 0x2794) SaveUtils::Write<u16>(this->playerPointer(), 0x16, v);
}

/*
	Get and Set for the Shirt.
	(ranges from 0x2324 to 0x2566).
*/
u16 PlayerHHD::shirt() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x1A);
}
void PlayerHHD::shirt(u16 v) {
	if (v >= 0x2324 && v <= 0x2566) SaveUtils::Write<u16>(this->playerPointer(), 0x1A, v);
}

/*
	Get and Set for the Pants.
	(ranges from 0x2567 to 0x25E2).
*/
u16 PlayerHHD::pants() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x1E);
}
void PlayerHHD::pants(u16 v) {
	if (v >= 0x2567 && v <= 0x25E2) SaveUtils::Write<u16>(this->playerPointer(), 0x1E, v);
}

/*
	Get and Set for the Socks.
	(ranges from 0x25E3 to 0x2606).
*/
u16 PlayerHHD::socks() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x22);
}
void PlayerHHD::socks(u16 v) {
	if (v >= 0x25E3 && v <= 0x2606) SaveUtils::Write<u16>(this->playerPointer(), 0x22, v);
}

/*
	Get and Set for the shoes.
	(ranges from 0x2607 to 0x2644).
*/
u16 PlayerHHD::shoes() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x26);
}
void PlayerHHD::shoes(u16 v) {
	if (v >= 0x2607 && v <= 0x2644) SaveUtils::Write<u16>(this->playerPointer(), 0x26, v);
}

/*
	Get and Set for the Tools.
	(ranges from 0x3221 to 0x3277).
*/
u16 PlayerHHD::tools() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x2A);
}
void PlayerHHD::tools(u16 v) {
	if (v >= 0x3221 && v <= 0x3277) SaveUtils::Write<u16>(this->playerPointer(), 0x2A, v);
}

/*
	Get and Set for the Player ID.
*/
u16 PlayerHHD::playerid() const {
	return SaveUtils::Read<u16>(this->playerPointer(), 0x3F528);
}
void PlayerHHD::playerid(u16 v) {
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F528, v);
}

/*
	Get and Set for the Player Name.
*/
std::u16string PlayerHHD::name() const {
	return StringUtils::ReadUTF16String(this->playerPointer(), 0x3F52A, 8);
}

void PlayerHHD::name(std::u16string v) {
	StringUtils::WriteUTF16String(this->playerPointer(), v, 0x3F52A, 8);
}

/*
	Return the Player Pattern.

	u32 slot: The slot of the Pattern.
*/
std::unique_ptr<Pattern> PlayerHHD::pattern(u32 slot) const {
	if (slot > 119) return nullptr;

	return std::make_unique<PatternHHD>(this->playerData, (0x1A0 + 0x1BFA88) + 0x30 + (0x870 * slot));
}

/*
	Lock & Unlock all misc stuff.
*/
void PlayerHHD::unlockHandbooks() {
	this->playerPointer()[0x3F541] = 0xFE;
	this->playerPointer()[0x3F542] = 0x0F;
	this->playerPointer()[0x3F543] = 0x3F;
	this->playerPointer()[0x3F544] = 0xFF;
	this->playerPointer()[0x3F547] = 0xFC;
	this->playerPointer()[0x3F54F] = 0x26;
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F6BA, 0xFFFD);
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F6BC, 0xEFFF);
	this->playerPointer()[0x3F548] = 0xFF;
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F549, 0xF8C3);
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F64A, 0xFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F64C, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F650, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F654, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F658, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F65C, 0x3FFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F660, 0xFFFFFE00);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F664, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F668, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F66C, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F670, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F674, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F678, 0xFFFFFFFF);
	this->playerPointer()[0x3F67C] = 7;
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F62C, 0xFFFFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F630, 0x03FFFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F7E8, 0x0001FFFD);
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F80A, 0xFFFF);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F80C, 0x007FFFFF);

	this->playerPointer()[0xFE908] = 1; // Ceiling Decor.
	this->playerPointer()[0xFE910] = 1; // Even More Designs.
	this->playerPointer()[0xFE914] = 1; // Windows and More.
	this->playerPointer()[0xFE91C] = 1; // Sound Scenery.
	this->playerPointer()[0xFE920] = 1; // Refurbishing.
	this->playerPointer()[0xFE918] = 1; // Happy Home Camera.
	this->playerPointer()[0xFE92C] = 1; // World Insects.
	this->playerPointer()[0xFE934] = 1; // World Fish.
	this->playerPointer()[0xFE93C] = 1; // Ancient Fossils.
	this->playerPointer()[0xFE944] = 1; // Gyroids.
	this->playerPointer()[0xFE94C] = 1; // Art Collection.
	this->playerPointer()[0xFE954] = 1; // Choosing a Layout.
	this->playerPointer()[0xFE924] = 1; // Styling Machine.
}
void PlayerHHD::lockHandbooks() {
	this->playerPointer()[0x3F541] = 0x7E;
	this->playerPointer()[0x3F542] = 0x08;
	this->playerPointer()[0x3F543] = 0x32;
	this->playerPointer()[0x3F544] = 0xF9;
	this->playerPointer()[0x3F547] = 0;
	this->playerPointer()[0x3F54F] = 0x20;
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F6BA, 0x0001);
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F6BC, 0);
	this->playerPointer()[0x3F548] = 0;
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F549, 0x6840);
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F64A, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F64C, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F650, 0x80000000);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F654, 0x06000000);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F658, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F65C, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F660, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F664, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F668, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F66C, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F670, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F674, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F678, 0x00700000);
	this->playerPointer()[0x3F67C] = 0;
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F62C, 0x00C00000);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F630, 0);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F7E8, 1);
	SaveUtils::Write<u16>(this->playerPointer(), 0x3F80A, 1);
	SaveUtils::Write<u32>(this->playerPointer(), 0x3F80C, 0x00600000);

	this->playerPointer()[0xFE908] = 0; // Ceiling Decor.
	this->playerPointer()[0xFE910] = 0; // Even More Designs.
	this->playerPointer()[0xFE914] = 0; // Windows and More.
	this->playerPointer()[0xFE91C] = 0; // Sound Scenery.
	this->playerPointer()[0xFE920] = 0; // Refurbishing.
	this->playerPointer()[0xFE918] = 0; // Happy Home Camera.
	this->playerPointer()[0xFE92C] = 0; // World Insects.
	this->playerPointer()[0xFE934] = 0; // World Fish.
	this->playerPointer()[0xFE93C] = 0; // Ancient Fossils.
	this->playerPointer()[0xFE944] = 0; // Gyroids.
	this->playerPointer()[0xFE94C] = 0; // Art Collection.
	this->playerPointer()[0xFE954] = 0; // Choosing a Layout.
	this->playerPointer()[0xFE924] = 0; // Styling Machine.
}

/*
	Lock & Unlock Emotions.
*/
void PlayerHHD::unlockEmotions() {
	static constexpr u8 Emotions[48] = {
		0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
		0x0C, 0x0D, 0x0E, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
		0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x20, 0x21, 0x24, 0x26,
		0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2E, 0x2F, 0x30, 0x31, 0x32,
		0x46, 0x47, 0x48, 0x4A
	};

	for(int i = 0; i < 48; i++) {
		this->playerPointer()[0x40D54 + i] = Emotions[i];
	}
}
void PlayerHHD::lockEmotions() {
	for(int i = 0; i < 48; i++) {
		this->playerPointer()[0x40D54 + i] = 0;
	}
}