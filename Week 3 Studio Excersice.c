#define green ledGreenFlash
#define red ledRedFlash
#define second 1000

//VARIABLES
const float distance = 10; // Distance from car ahead
const bool leftSafe = 0;   // State of Left Safety sensor
const bool rightSafe = 1;  // State of Right Safety sensor

//FORWARD DECLARATION
void laneChange (bool ls, bool rs);

task main()
{
	if (distance < 12){
		setLEDColor(red); // Set color to red
		laneChange(leftSafe,rightSafe);
	}
	else{
		displayTextLine(1, "Lane Change not required");
		setLEDColor(green); // Set color to green
	}
	
	wait1Msec(10*second);
}

//FUNCTION
void laneChange (bool ls, bool rs){
	if(ls){
		displayTextLine(1, "Changing to LEFT lane");
	}
	else if (rs){
		displayTextLine(1, "Changing to RIGHT lane");
	}
	else {
		displayTextLine(1, "Lane-change unsafe");
	}
}