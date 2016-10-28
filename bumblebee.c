// Plays flight of the bumblebee on the nxt brick in a seperate task (thread)
void playSemitone(int toneAwayFromA, int ms10)
{
	const float num = 1.05946309436;
	const float base = 440;

	if (toneAwayFromA == 0)
	{
		PlayTone((int)base, ms10);
	}
	else if (toneAwayFromA > 0)
	{
		float mult = 1;
		for (int x = 0; x < toneAwayFromA; ++x)
			mult *= num;
		PlayTone((int)(base * mult), ms10);
	}
	else // negative
	{
		float mult = 1;
		for (int x = 0; x < abs(toneAwayFromA); ++x)
			mult *= num;
		PlayTone((int)(base * (1 / mult)), ms10);
	}
}

void p(int tone, int t10)
{
	playSemitone(tone, t10);
	wait10Msec(t10);
}

void p4(int t1, int t2, int t3, int t4, int ms10)
{
	p(t1, ms10);
	p(t2, ms10);
	p(t3, ms10);
	p(t4, ms10);
}

task playDuringEndgame()
{
	nVolume = 3;
	int s = 10;

	wait1Msec(90000);

	// NEW MEASURE
	p4(31, 30, 29, 28, s);

	p4(29, 28, 27, 26, s);

	p4(27, 26, 25, 24, s);

	p4(23, 22, 21, 20, s);

	// NEW MEASURE
	p4(19, 18, 17, 16, s);

	p4(17, 16, 15, 14, s);

	p4(15, 14, 13, 12, s);

	p4(11, 10, 9, 8, s);

	// NEW MEASURE
	p4(7, 6, 5, 4, s);

	p4(5, 4, 3, 2, s);

	p4(7, 6, 5, 4, s);

	p4(5, 4, 3, 2, s);

	// NEW MEASURE
	p4(7, 6, 5, 4, s);

	p4(3, 8, 7, 6, s);

	p4(7, 6, 5, 4, s);

	p4(3, 4, 5, 6, s);

	// NEW MEASURE
	p4(7, 6, 5, 4, s);

	p4(3, 8, 7, 6, s);

	p4(7, 6, 5, 4, s);

	p4(3, 4, 5, 6, s);

	// NEW MEASURE
	p4(7, 6, 5, 4, s);

	p4(5, 4, 3, 2, s);

	p4(3, 4, 5, 6, s);

	p4(7, 8, 7, 6, s);

	// NEW MEASURE
	p4(7, 6, 5, 4, s);

	p4(5, 4, 3, 2, s);

	p4(3, 4, 5, 6, s);

	p4(7, 8, 9, 10, s);

	// NEW MEASURE
	p4(12, 11, 10, 9, s);

	p4(8, 13, 12, 11, s);

	p4(12, 11, 10, 9, s);

	p4(8, 9, 10, 11, s);

	// NEW MEASURE
	p4(12, 11, 10, 9, s);

	p4(8, 13, 12, 11, s);

	p4(12, 11, 10, 9, s);

	p4(8, 9, 10, 11, s);

	// NEW MEASURE
	p4(12, 11, 10, 9, s);

	p4(10, 9, 8, 7, s);

	p4(8, 9, 10, 11, s);

	p4(12, 13, 12, 11, s);

	// NEW MEASURE
	p4(12, 11, 10, 9, s);

	p4(10, 9, 8, 7, s);

	p4(8, 9, 10, 11, s);

	p4(12, 13, 12, 11, s);

	// NEW MEASURE
	p4(0, -1, 0, -1, s);

	p4(0, -1, 0, -1, s);

	p4(1, -1, 1, -1, s);

	p4(1, -1, 1, -1, s);

	// NEW MEASURE
	p4(12, 11, 12, 11, s);

	p4(12, 11, 12, 11, s);

	p4(13, 11, 13, 11, s);

	p4(13, 11, 13, 11, s);

	// NEW MEASURE
	p4(12, 13, 12, 11, s);

	p4(12, 13, 12, 11, s);

	p4(12, 13, 12, 11, s);

	p4(12, 13, 12, 11, s);

	// NEW MEASURE
	p4(12, 13, 12, 11, s);

	p4(12, 13, 14, 15, s);

	p4(16, 15, 14, 13, s);

	p4(12, 11, 12, 13, s);

	// NEW MEASURE
	p4(5, 4, 5, 4, s);

	p4(5, 4, 5, 4, s);

	p4(6, 4, 6, 4, s);

	p4(6, 4, 6, 4, s);

	// NEW MEASURE
	p4(17, 16, 17, 16, s);

	p4(17, 16, 17, 16, s);

	p4(18, 16, 18, 16, s);

	p4(18, 16, 18, 16, s);

	// NEW MEASURE
	p4(17, 18, 17, 16, s);

	p4(17, 18, 17, 16, s);

	p4(17, 18, 17, 16, s);

	p4(17, 16, 17, 16, s);

	// NEW MEASURE
	p4(17, 18, 19, 20, s);

	p4(21, 20, 19, 18, s);

	p4(17, 18, 19, 20, s);

	p4(21, 20, 19, 18, s);

	// NEW MEASURE
	p4(17, 16, 15, 14, s);

	p4(13, 18, 17, 16, s);

	p4(17, 16, 15, 14, s);

	p4(13, 14, 15, 16, s);

	// NEW MEASURE
	p4(17, 16, 15, 14, s);

	p4(15, 14, 13, 12, s);

	p4(13, 14, 15, 16, s);

	p4(15, 16, 17, 18, s);

	// NEW MEASURE
	p4(31, 30, 29, 28, s);

	p4(29, 28, 27, 26, s);

	p4(27, 26, 25, 24, s);

	p4(23, 22, 21, 20, s);

	// NEW MEASURE
	p4(19, 20, 19, 18, s);

	p4(7, 20, 3, 18, s);

	p4(0, 20, -4, 18, s);

	p4(0, 20, 3, 18, s);

	// NEW MEASURE
	p4(7, 20, 19, 18, s);

	p4(7, 20, 3, 18, s);

	p4(0, 20, -4, 18, s);

	p4(0, 20, 3, 18, s);

	// NEW MEASURE
	p4(7, 20, 19, 18, s);

	p4(19, 20, 19, 18, s);

	p4(19, 20, 19, 18, s);

	p4(19, 20, 19, 18, s);

	// NEW MEASURE
	/*p4(36, 36, 36, 36, s);

	p4(36, 36, 36, 36, s);

	p4(36, 36, 36, 36, s);

	p4(36, 36, 36, 36, s);

	// NEW MEASURE
	p4(7, 6, 5, 4, s);

	p4(5, 4, 3, 2, s);

	p4(3, 2, 1, 0, s);

	p4(-1, -2, -3, -4, s);

	// NEW MEASURE
	p4(-5, -4, -5, -6, s);

	p4(7, -4, 3, -6, s);

	p4(0, -4, -4, -6, s);

	p4(0, -4, 3, -6, s);*/
}
