#pragma once
#include "Filter.h"
#include "FlagFilterEntry.h"
#include "DurationFilterEntry.h"

class RecipyFilter : public Filter
{
  private:
    DurationFilterEntry m_timeEntry;
    FlagFilterEntry m_flagEntry;

  public:
    RecipyFilter(const std::string &titleReg,
                               const std::string &contentReg,
                               const std::string &timeReg,
                               const std::string &flagReg)
    : Filter(titleReg, contentReg), m_timeEntry(DurationFilterEntry(timeReg)), m_flagEntry(0)
    {
        unsigned int flag = static_cast<unsigned int>(std::bitset<8>(flagReg).to_ulong());
        m_flagEntry = flag;
    }

    bool match(const Document & doc) override;
};
