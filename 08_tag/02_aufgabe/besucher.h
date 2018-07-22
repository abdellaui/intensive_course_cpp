
class Besucher
{
public:
	Besucher(unsigned int timeNeed, unsigned int uId)
	{
		m_neededTime = timeNeed;
		m_uId = uId;
	}

	void serve()
	{
		this_thread::sleep_for(chrono::milliseconds{m_neededTime});
		m_neededTime = 0;
	}

	const bool served() const
	{
		return (m_neededTime == 0 ? true : false);
	}

	const unsigned int getUID() const
	{
		return m_uId;
	}

private:
	unsigned int m_neededTime;
	unsigned int m_uId;
};
