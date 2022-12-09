#ifndef _TPA81_H_
#define _TPA81_H_

#define 	AMBIENT		0x01
#define		POINT_BASE	0x02

class TPA81
{
private:
	int address;
	void sendCommand(uint8_t cmd);
	int receiveData();

public:
	TPA81();
	TPA81(uint8_t addr);
	void setup(uint8_t addr);
	void changeAddress(uint8_t addr);
	int getAmbient();
	int getPoint(uint8_t point);
	int getAll(int points[]);
};

#endif
