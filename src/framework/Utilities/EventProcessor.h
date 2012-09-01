/*
 * Copyright (C) 2005-2012 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __EVENTPROCESSOR_H
#define __EVENTPROCESSOR_H

#include "Platform/Define.h"

#include <map>
#include <queue>

// Note. All times are in milliseconds here.

class BasicEvent
{
    public:
        BasicEvent(uint32 type)
            : to_Abort(false), m_type(type)
        {};

        virtual ~BasicEvent()                               // override destructor to perform some actions on event removal
        {};

        // this method executes when the event is triggered
        // return false if event does not want to be deleted
        // e_time is execution time, p_time is update interval
        virtual bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) { return true; }

        virtual bool IsDeletable() const { return true; }   // this event can be safely deleted

        virtual void Abort(uint64 /*e_time*/) {}            // this method executes when the event is aborted

        bool to_Abort;                                      // set by externals when the event is aborted, aborted events don't execute
                                                            // and get Abort call when deleted

        uint32 const& GetType()          { return m_type;}

        // these can be used for time offset control
        uint64 m_addTime;                                   // time when the event was added to queue, filled by event handler
        uint64 m_execTime;                                  // planned time of next execution, filled by event handler
        uint32 const m_type;                                // Event type (for use in some calculation)
};

typedef std::multimap<uint64, BasicEvent*> EventList;
typedef std::queue<std::pair<uint64, BasicEvent*> > EventNewQueue;

class MANGOS_DLL_SPEC EventProcessor
{
    public:

        EventProcessor();
        ~EventProcessor();

        void Update(uint32 p_time, bool force = false);
        void KillAllEvents(bool force);
        void CleanupEventList();
        void AddEvent(BasicEvent* Event, uint64 e_time, bool set_addtime = true);
        uint64 CalculateTime(uint64 t_offset);
        void RenewEvents();

    protected:
        void _AddEvents();
        uint64 m_time;
        EventList m_events;
        EventNewQueue m_queue;
        bool m_aborting;
};

#endif