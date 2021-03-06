#include <Wire.h>
#include <MMA8452.h>

#include <SoftwareSerial.h>

MMA8452 accelerometer;

SoftwareSerial serial(13, 12);

void setup()
{
	serial.begin(57600);
	serial.print(F("Initializing MMA8452Q: "));

	Wire.begin();

	bool initialized = accelerometer.init(); 
	
	if (initialized)
	{
		serial.println(F("ok"));

		accelerometer.setDataRate(MMA_100hz);
		accelerometer.setRange(MMA_RANGE_2G);
	}
	else
	{
		Serial.println(F("failed. Check connections."));
		while (true) {};
	}
}

void loop()
{
	float x;
	float y;
	float z;

	accelerometer.getAcceleration(&x, &y, &z);

	serial.print(x, 5);
	serial.print(F(" "));
	serial.print(y, 5);
	serial.print(F(" "));
	serial.print(z, 5);
	serial.println();

	delay(10);
}