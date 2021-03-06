/*
 *  The Mana Client
 *  Copyright (C) 2010  The Mana Developers
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

#include "gui/beingpopup.h"

#include "being.h"
#include "graphics.h"
#include "units.h"

#include "gui/gui.h"
#include "gui/palette.h"

#include "gui/widgets/label.h"

#include "utils/gettext.h"
#include "utils/stringutils.h"

#include <guichan/font.hpp>


BeingPopup::BeingPopup():
    Popup("BeingPopup")
{
    // Being Name
    mBeingName = new Label("A");
    mBeingName->setFont(boldFont);
    mBeingName->setPosition(getPadding(), getPadding());

    const int fontHeight = mBeingName->getHeight() + getPadding();

    // Being's party
    mBeingParty = new Label("A");
    mBeingParty->setPosition(getPadding(), fontHeight);

    add(mBeingName);
    add(mBeingParty);
}

BeingPopup::~BeingPopup()
{
}

void BeingPopup::show(int x, int y, Being *b)
{
    if (!b)
    {
        setVisible(false);
        return;
    }

    if (!(b->getPartyName().empty()))
    {
        mBeingName->setCaption(b->getName());
        mBeingName->adjustSize();

        mBeingParty->setCaption(strprintf(_("Party: %s"),
                                          b->getPartyName().c_str()));
        mBeingParty->adjustSize();

        int minWidth = std::max(mBeingName->getWidth(),
                                mBeingParty->getWidth());

        const int height = getFont()->getHeight();

        setContentSize(minWidth + 10, (height * 2) + 10);

        position(x, y);
        return;
    }

    setVisible(false);
}
