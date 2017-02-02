#define LEFT_MOTOR_PORT 1
#define RIGHT_MOTOR_PORT 2
#define LEFT_BUMPER_PORT S2
#define RIGHT_BUMPER_PORT S3
#define ULTRA_PORT S4

#define MOTOR_MAX 100
#define MOTOR_MIN -100

bool leftBumperState = 0;
bool rightBumperState = 0;

int speed = 0;

task main()
{
	while(true){
		leftBumperState = getTouchValue(LEFT_BUMPER_PORT);
		rightBumperState = getTouchValue(RIGHT_BUMPER_PORT);
		
		if(leftBumperState || rightBumperState){
			speed = 0;
			motor[LEFT_MOTOR_PORT] = speed;
			motor[LEFT_MOTOR_PORT] = speed;
			
			setLEDColor(ledRed);
			delay(1000);
		}
		else{
			speed = speed + 1;
			if(speed > MOTOR_MAX){
				motor[LEFT_MOTOR_PORT] = MOTOR_MAX;
				motor[LEFT_MOTOR_PORT] = MOTOR_MAX;
			}
			else(
				motor[LEFT_MOTOR_PORT] = speed;
			motor[LEFT_MOTOR_PORT] = speed;
		}
		setLEDColor(ledGreen);
		delay(10);
	}
	
}
}
