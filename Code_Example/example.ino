#include "variant.h"
#include <due_can.h>

#define Serial SerialUSB
//VARIABLES TO MAINTAIN COMPATIBILITY WITH THE ARDUINO DUE
const byte profet1 = 9, profet2 = 8, profet3 = 7, profet4 = 6, mosfet5 = 5, mosfet6 = 4; //DIGITAL OUTPUTS
int AV1 = A5, AV2 = A4, AV3 = A3, AV4 = A2, AV5 = A1, AV6 = A0; //ANALOG INPUTS
int D1 = 25, D2 = 26, D3 = 27, D4 = 28; //DIGITAL INPUTS

//VARIABLES TO READ PULSES FROM AN HALL SENSOR
volatile uint32_t times0, times1; 
volatile boolean Flags; 

byte rpmL = 0;
byte rpmH = 0;
short tempRPM = 0;
int motor_rpm = 0, old_motor_rpm = 0, motor_aux = 0;


void rpm_measument();
void clusterCAN();


void setup() {
	Serial.begin(9600);
	pinMode(D1, INPUT);
	attachInterrupt(D1, rpm_measument, RISING);//Sensor attached to arduino Due pin 2
	times0 = millis(); // Choose between millis() or micros() depending on the dril speed !

	Can0.begin(CAN_BPS_500K); //CAN BAUDRATE FOR MOST VW CARS
	delay(200);
}


void loop() {

	if (Flags) {
		motor_rpm = (int) 60000 / times1;
		old_motor_rpm = motor_rpm;
		Serial.println(motor_rpm);
		Flags = false;
	}

	tempRPM = (motor_rpm * 4);
	rpmL = (tempRPM&0xFF);      //calculate the LOW-byte for the cluster
	rpmH = tempRPM>>8;  		//calculate the HIGH-byte for the cluster

	clusterCAN();

}

void rpm_measument(){

	  times1 = millis() - times0;
	  times0 = millis();
	  Flags = true;

}

//CAN FUNCTION TO COMMUNICATE WITH AN TEST INSTRUMENT PANEL FROM A VW GOLF V
void clusterCAN(){
	CAN_FRAME cluster;

	//if(motor_rpm > (old_motor_rpm + 50)){
	/*******MOTOR SPEED ID******/
	cluster.id = 0x280;
	cluster.length = 8;
	cluster.data.byte[0] = 0x49;
	cluster.data.byte[1] = 0x0E;
	cluster.data.byte[2] = rpmL;
	cluster.data.byte[3] = rpmH;
	cluster.data.byte[4] = 0x0E;
	cluster.data.byte[5] = 0x00;
	cluster.data.byte[6] = 0x1B;
	cluster.data.byte[7] = 0x0E;
	Can0.sendFrame(cluster);
	//}
}
