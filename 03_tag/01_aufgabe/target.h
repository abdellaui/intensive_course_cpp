#ifndef TARGET_H_
#define TARGET_H_

#include <string>

class target
{
	public:
		target(float posX, float posY);
		~target();

		const float getPosX() const;
		const float getPosY() const;

	private:
		const float m_posX;
		const float m_posY;
};

#endif /* TARGET_H_ */
