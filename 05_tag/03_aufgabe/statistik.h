#pragma once

template <typename T>
class Statistik
{
public:
	Statistik<T>(){
		m_maximum = 0;
		m_minimum = 0;
		m_countvalues = 0;
		m_sumvalues = 0;
		m_quadsumvalues = 0;
	}

	~Statistik<T>(){};

	bool nextValue(T const & val)
	{
		m_sumvalues += val;
		m_countvalues++;
		m_quadsumvalues += (val * val);

		if (m_maximum < val) m_maximum = val;
		if (m_minimum > val) m_minimum = val;

		return true;
	}

	T getMaximum() const
	{
		return m_maximum;
	}
	T getMinimum() const
	{
		return m_minimum;
	}
    //y
	T getAverage() const
	{
		return(m_sumvalues / m_countvalues);
	}
    //S^2
	T getVariance() const
    {
		return ((m_quadsumvalues / m_countvalues) - getAverage()*getAverage());
        /*
        sigma^2 = sum((x-average)^2) / n
        =>  sum((x^2 - 2average*x + average2)) / n
        =>  sum(x^2)/n - 2average*sum(x)/n + n*average^2/n
        =>  sum(x^2)/n - 2average^2 - avergage^2
        =>  sum(x^2)/n - average^2;
        */
	}

private:
	T m_maximum;
	T m_minimum;

	T m_sumvalues;
	T m_quadsumvalues;
	T m_countvalues;
};
