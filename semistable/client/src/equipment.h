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

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#define EQUIPMENT_SIZE 11

class Item;

class Equipment
{
    public:
        /**
         * Constructor.
         */
        Equipment(): mBackend(0) {}

        /**
         * Destructor.
         */
        ~Equipment() { mBackend = 0; }

        enum Slot
        {
            EQUIP_TORSO_SLOT = 0,
            EQUIP_GLOVES_SLOT = 1,
            EQUIP_HEAD_SLOT = 2,
            EQUIP_LEGS_SLOT = 3,
            EQUIP_FEET_SLOT = 4,
            EQUIP_RING1_SLOT = 5,
            EQUIP_RING2_SLOT = 6,
            EQUIP_NECK_SLOT = 7,
            EQUIP_FIGHT1_SLOT = 8,
            EQUIP_FIGHT2_SLOT = 9,
            EQUIP_PROJECTILE_SLOT = 10,
            EQUIP_VECTOREND
        };

        class Backend {
            public:
                virtual Item *getEquipment(int index) const = 0;
                virtual void clear() = 0;
                virtual ~Backend() { }
        };

        /**
         * Get equipment at the given slot.
         */
        Item *getEquipment(int index) const
        { return mBackend ? mBackend->getEquipment(index) : 0; }

        /**
         * Clears equipment.
         */
        void clear()
        { if (mBackend) mBackend->clear(); }

        /**
         * Set equipment at the given slot.
         */
        void setEquipment(int index, int id, int quantity = 0);

        void setBackend(Backend *backend)
        { mBackend = backend; }

    private:
        Backend *mBackend;
};

#endif
