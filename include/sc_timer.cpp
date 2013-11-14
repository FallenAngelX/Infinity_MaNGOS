/* Copyright (C) 2013 by boxa for ScriptDev2_R2 <http://github.com/mangosR2/scriptdev2/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#include "precompiled.h"

bool TTimer::Expired(const uint32 tickDiff)
{
    m_counter += tickDiff;
    if (m_counter >= m_period)
    {
        if (m_autoReset)
            m_counter = 0;
        return true;
    }
    return false;
}

void TTimer::Reset(const uint32 period)
{
    m_period  = period;
    m_counter = 0;
}

void TTimer::Reset(const uint32 periodMin, const uint32 periodMax)
{
    Reset(urand(periodMin, periodMax));
}

void TTimer::ResetAuto(const uint32 period)
{
    Reset(period);
    m_autoReset = true;
}
