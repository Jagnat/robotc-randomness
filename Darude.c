// Plays darude - sandstorm
task DarudeStorm();

// test
/*task main()
{
	nVolume = 4;
	StartTask(DarudeStorm);
	bool choosing = true;
	while (choosing)
	{

	}
}*/

const int step = 10;

void PlayStep(int freq)
{
	PlayTone(freq, step - 2);
	wait10Msec(step);
	PlayTone(freq, step - 2);
	wait10Msec(step);
	PlayTone(freq, step - 2);
	wait10Msec(step);
	PlayTone(freq, step - 2);
	wait10Msec(step);
	PlayTone(freq, step * 2 - 2);
	wait10Msec(step * 2);
}

void PlayT(int freq)
{
	PlayTone(freq, step - 2);
	wait10Msec(step);
	PlayTone(freq, step - 2);
	wait10Msec(step);
}

task DarudeStorm()
{
	while (true) {
	PlayStep(242);
	PlayT(242);
	PlayStep(242);
	PlayT(324);
	PlayStep(324);
	PlayT(288);
	PlayStep(288);
	PlayT(216);
	PlayStep(242);
	PlayT(242);
	PlayStep(242);
	PlayT(324);
	PlayStep(242);
	PlayT(242);
	PlayStep(242);
	PlayT(288);
	}
}
