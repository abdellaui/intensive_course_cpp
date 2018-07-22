#ifndef ROBOT_H_
#define ROBOT_H_

#include "target.h"
#include <string>
#include <iostream>
#include <cmath>

class robot
{
	public:
		robot();

		void moveHead(float degree);
		void openHand();
		void moveRobot(int newPosX, int newPosY);
		void moveRobot(float newPosX, float newPosY);
		void moveRobot(float degree, unsigned int speed = 1000);
		void moveRobot(int speed);
		void turnRobot(const float degree);
		bool locateTarget();

		void calibrateCamera();
		void addHand();
		void setTarget(target* newTarget);
		void printStatusCode() const;
		robot operator+(robot & rob);

		// added
		void setPosX(float);
		void setPosY(float);
		float getPosX();
		float getPosY();
		void moveFinger1();
		void moveFinger2();
		// added end

  private:

		float m_posX;
		float m_posY;
		float m_headDirection;      // in Grad (relativ zur x-Achse des Koordinatensystems)
		float m_bodyDirection;      // in Grad (relativ zur x-Achse des Koordinatensystems)
		unsigned int m_handCount;   // Anzahl der montierten H�nde
		target* m_currentTarget;    // Informationen zum (einzigen) aktuellen Zielobjekt
		bool m_cameraCalibrated;
		long int* m_status;
};

#endif /* ROBOT_H_ */
