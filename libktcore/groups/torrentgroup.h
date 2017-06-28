/***************************************************************************
 *   Copyright (C) 2007 by Joris Guisson                                   *
 *   joris.guisson@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#ifndef KTTORRENTGROUP_H
#define KTTORRENTGROUP_H

#include <set>
#include <groups/group.h>
#include <util/sha1hash.h>


namespace kt
{

    class QueueManager;

    /**
        @author Joris Guisson <joris.guisson@gmail.com>
    */
    class KTCORE_EXPORT TorrentGroup : public Group
    {
        Q_OBJECT
    public:
        TorrentGroup(const QString& name);
        virtual ~TorrentGroup();

        virtual bool isMember(TorrentInterface* tor);
        virtual void save(bt::BEncoder* enc);
        virtual void load(bt::BDictNode* n);
        virtual void torrentRemoved(TorrentInterface* tor);
        virtual void removeTorrent(TorrentInterface* tor);
        virtual void addTorrent(TorrentInterface* tor, bool new_torrent);
        virtual void policyChanged();

        void add(TorrentInterface* tor);
        void remove(TorrentInterface* tor);
        void loadTorrents(QueueManager* qman);

    signals:
        /// Emitted when a torrent has been added
        void torrentAdded(Group* g);

        /// Emittend when a torrent has been removed
        void torrentRemoved(Group* g);

    private:
        std::set<TorrentInterface*> torrents;
        std::set<bt::SHA1Hash> hashes;
    };

}

#endif
