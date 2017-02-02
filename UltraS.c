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

float distance;
float error = 0.5;
int desiredDistance;
float k = 0.03; //Proportionality Constant

task main()
{
	while(true){
		distance = getUSDistance(ULTRA_PORT);
		
		if((distance - error) >  desiredDistance){
			speed = speed + 1;
			if (speed > MOTOR_MAX){ 
				motor[LEFT_MOTOR_PORT] = MOTOR_MAX;
				motor[LEFT_MOTOR_PORT] = MOTOR_MAX;
			}
			else{
				motor[LEFT_MOTOR_PORT] = speed;
				motor[LEFT_MOTOR_PORT] = speed;
			}
			delay(10);
		}
		else if((distance + error) < desiredDistance){
			speed = speed - 5;
			if (speed < MOTOR_MIN){ 
				motor[LEFT_MOTOR_PORT] = MOTOR_MIN;
				motor[LEFT_MOTOR_PORT] = MOTOR_MIN;
			}
			else{
				motor[LEFT_MOTOR_PORT] = speed;
				motor[LEFT_MOTOR_PORT] = speed;
			}
			delay(10);
		}
		else{
			speed = 0;
			motor[LEFT_MOTOR_PORT] = speed;
			motor[LEFT_MOTOR_PORT] = speed;
			delay(10);
		}
		
	}
}
