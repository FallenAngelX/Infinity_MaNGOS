/* Copyright (C) 2013 by boxa for ScriptDev2_R2 <http://github.com/mangosR2/scriptdev2/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_TIMER_H
#define SC_TIMER_H

class TTimer
{
    public:
        TTimer() : m_period(1000), m_counter(0), m_autoReset(false) {}

        void Reset() { m_counter = 0; }
        void Reset(uint32 const period);
        void Reset(uint32 const periodMin, uint32 const periodMax);
        void ResetAuto(uint32 const period);

        bool Expired(uint32 const tickDiff);

        void Update(uint32 const tickDiff) { m_counter += tickDiff; }
        bool IsExpired() const { return m_counter >= m_period; }
        bool IsSet() const { return m_period > 0; }

        void SetAutoReset(bool const autoReset) { m_autoReset = autoReset; }
        uint32 GetAutoReset() const { return m_autoReset; }

        uint32 GetPeriod() const { return m_period; }
        uint32 GetCounter() const { return m_counter; }

    private:
        uint32 m_period;
        uint32 m_counter;
        bool   m_autoReset;
};

#endif
