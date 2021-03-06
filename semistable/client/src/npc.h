/*
 *  The Mana Client
 *  Copyright (C) 2004-2009  The Mana World Development Team
 *  Copyright (C) 2009-2010  The Mana Developers
 *
 *  This file is part of The Mana Client.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NPC_H
#define NPC_H

#include "being.h"

class Graphics;
class Text;

class NPC : public Being
{
    public:
        NPC(int id, int subtype, Map *map);

        void setName(const std::string &name);

        virtual Type getType() const { return Being::NPC; }

        virtual void setSubtype(Uint16 subtype);

        void talk();

        /**
         * Gets the way an NPC is blocked by other things on the map
         */
        virtual unsigned char getWalkMask() const
        {
            return Map::BLOCKMASK_WALL
                    | Map::BLOCKMASK_CHARACTER
                    | Map::BLOCKMASK_MONSTER;
        }

        /** We consider NPCs (at least for now) to be one layer-sprites */
        virtual int getNumberOfLayers() const
        { return 1; }

        static bool isTalking();

    protected:
        /**
         * Gets the way a monster blocks pathfinding for other objects
         */
        virtual Map::BlockType getBlockType() const
        { return Map::BLOCKTYPE_CHARACTER; } //blocks like a player character
};

#endif
