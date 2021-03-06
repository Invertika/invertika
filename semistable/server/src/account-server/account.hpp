/*
 *  The Mana Server
 *  Copyright (C) 2004-2010  The Mana World Development Team
 *
 *  This file is part of The Mana Server.
 *
 *  The Mana Server is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  The Mana Server is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Mana Server.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include <time.h>

#include "account-server/character.hpp"

/**
 * A player's account. Stores the account information as well as the
 * player characters available under this account.
 */
class Account
{
    public:
        /**
         * Constructor.
         */
        Account(int id = -1): mID(id)
        {}

        /**
         * Destructor.
         */
        ~Account();

        /**
         * Set the user name.
         *
         * @param name the user name.
         */
        void setName(const std::string &name)
        { mName = name; }

        /**
         * Get the user name.
         *
         * @return the user name.
         */
        const std::string &getName() const
        { return mName; }

        /**
         * Set the user password. The password is expected to be already
         * hashed with a salt.
         *
         * The hashing must be performed externally from this class or else
         * we would end up with the password being hashed many times
         * (e.g setPassword(getPassword()) would hash the password twice.
         *
         * @param password the user password (hashed with salt).
         */
        void setPassword(const std::string &password)
        { mPassword = password; }


        /**
         * Get the user password (hashed with salt).
         *
         * @return the user password (hashed with salt).
         */
        const std::string &getPassword() const
        { return mPassword; }


        /**
         * Set the user email address. The email address is expected to be
         * already hashed.
         *
         * @param email the user email address (hashed).
         */
        void setEmail(const std::string &email)
        { mEmail = email; }


        /**
         * Get the user email address (hashed).
         *
         * @return the user email address (hashed).
         */
        const std::string &getEmail() const
        { return mEmail; }


        /**
         * Set the account level.
         *
         * @param level the new level.
         */
        void setLevel(int level)
        { mLevel = level; }

        /**
         * Get the account level.
         *
         * @return the account level.
         */
        int getLevel() const
        { return mLevel; }

        /**
         * Set the characters.
         *
         * @param characters a list of characters.
         */
        void setCharacters(const Characters& characters);

        /**
         * Adds a new character.
         *
         * @param character the new character.
         */
        void addCharacter(Character *character);

        /**
         * Removes a character from the account.
         *
         * @param i index of the character.
         */
        void delCharacter(int i);

        /**
         * Get all the characters.
         *
         * @return all the characters.
         */
        Characters &getCharacters()
        { return mCharacters; }

        /**
         * Get all the characters.
         *
         * @return all the characters.
         */
        const Characters &getCharacters() const
        { return mCharacters; }

        /**
         * Get account ID.
         *
         * @return the unique ID of the account, a negative number if none yet.
         */
        int getID() const
        { return mID; }

        /**
         * Set account ID.
         * The account shall not have any ID yet.
         */
        void setID(int);

        /**
         * Get the time of the account registration.
         */
        time_t getRegistrationDate() const
        { return mRegistrationDate; }

        /**
         * Sets the time of the account registration.
         *
         * @param time of the account registration.
         */
        void setRegistrationDate(time_t time);

        /**
         * Get the time of the last login.
         */
        time_t getLastLogin() const
        { return mLastLogin; }

        /**
         * Sets the time of the last login.
         *
         * @param time of the last login.
         */
        void setLastLogin(time_t time);

    private:
        Account(const Account &rhs);
        Account &operator=(const Account &rhs);

        std::string mName;        /**< User name */
        std::string mPassword;    /**< User password (hashed with salt) */
        std::string mEmail;       /**< User email address (hashed) */
        Characters mCharacters;   /**< Character data */
        int mID;                  /**< Unique id */
        unsigned char mLevel;     /**< Account level */
        time_t mRegistrationDate; /**< Date and time of the account registration */
        time_t mLastLogin;        /**< Date and time of the last login */
};

typedef std::vector< Account * > Accounts;

#endif // ACCOUNT_H
