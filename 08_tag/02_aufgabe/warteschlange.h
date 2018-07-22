#include <string>
#include <iostream>
#include <atomic>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

template <typename T>
class Warteschlange
{
  public:
	Warteschlange()
	{
		m_maxElements = 1;
	}
	Warteschlange(const size_t &maxNumElements)
	{
		m_maxElements = maxNumElements;
	}

	bool enqueue(const T &item)
	{
		unique_lock<mutex> lock{m_mtx};
        // we want to work now, lock the resource
        
        
		while (m_warteschlange.size() >= m_maxElements)
		{
            // if our max size is reached, so let wait for consumer
            
			m_condEnq.wait(lock);
            
            // consumer overtake
			if (!m_isActive)
				return m_isActive;
		}
        if(!m_isActive) return m_isActive;
        
		m_warteschlange.push(item);
        
        // notify DEQ, that we are finished with this task ( wake up DEQ )
		m_condDeq.notify_all();
		return m_isActive;
	}

	bool dequeue(T &result)
	{
		unique_lock<mutex> lock{m_mtx};

		//result = nullptr;

		while (m_warteschlange.size() <= 0)
		{
            // if we dont have items, wait for produceer
			m_condDeq.wait(lock);
            
            // we got new task
			if (!m_isActive)
				return m_isActive;
		}
        if(!m_isActive) return m_isActive;
        
		result = m_warteschlange.front();
        m_warteschlange.pop();

        // notify ENQ that we dequeue successfull ( wake up ENQ )
		m_condEnq.notify_all();
		return m_isActive;
	}

	void stop()
	{
        
		m_isActive = false;
		m_condDeq.notify_all();
		m_condEnq.notify_all();
	}


  private:
	queue<T> m_warteschlange;

	condition_variable m_condEnq;
	condition_variable m_condDeq;

	mutex m_mtx;

	size_t m_maxElements;
	bool m_isActive = true;
};
