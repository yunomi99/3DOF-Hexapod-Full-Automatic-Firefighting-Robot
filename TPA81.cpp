#include "Arduino.h"
#include "Wire.h"
#include "TPA81.h"

TPA81::TPA81()
{
	address = 0xD4 >> 1;
}

TPA81::TPA81(uint8_t addr)
{
	setup(addr);
}

void TPA81::setup(uint8_t addr)
{
	// Check if address is valid
	if (((addr & 0xF0) == 0xD0) && ((addr & 0x0F) % 2 == 0)) {
		address = addr >> 1;
	} else {
		// Fallback to default address
		address = 0xD0 >> 1;
	}
}

void TPA81::sendCommand(uint8_t cmd)
{
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.endTransmission();
}

int TPA81::receiveData()
{
	Wire.requestFrom(address, 1);

	long start = millis();
	while (Wire.available() < 1) {
		if (millis() - start > 5)
			return 0;
	}

	return Wire.read();
}

void TPA81::changeAddress(uint8_t addr)
{
	Wire.beginTransmission(address);
	Wire.write(0);
	Wire.write(0xA0);
	Wire.endTransmission();

	Wire.beginTransmission(address);
	Wire.write(0);
	Wire.write(0xAA);
	Wire.endTransmission();

	Wire.beginTransmission(address);
	Wire.write(0);
	Wire.write(0xA5);
	Wire.endTransmission();

	Wire.beginTransmission(address);
	Wire.write(0);
	Wire.write(addr);
	Wire.endTransmission();

	address = addr >> 1;
}

int TPA81::getAmbient()
{
	sendCommand(AMBIENT);
	return receiveData();
}

int TPA81::getPoint(uint8_t point)
{
	if (point < 1 && point > 8) {
		return 0;
	}

	sendCommand(POINT_BASE + point - 1);
	return receiveData();
}

int TPA81::getAll(int points[])
{
	sendCommand(AMBIENT);

	Wire.requestFrom(address, (int) 9);

	long start = millis();
	while (Wire.available() < 9) {
		if (millis() - start > 10)
			return 0;
	}

	int ambient = Wire.read();
	for (int i = 0; i < 8; i++)
	{
		points[i] = Wire.read();
	}

	return ambient;
}
