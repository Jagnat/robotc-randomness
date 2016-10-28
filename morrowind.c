
void playSemitone(int toneAwayFromA, int ms10)
{
	const float num = 1.05946309436;
	const float base = 432;
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

void PlayAndDelay(int tone, int t10)
{
	playSemitone(tone, t10 - 2);
	wait10Msec(t10);
}

void nPlayAndDelay(int tone, int t10)
{
	wait10Msec(t10);
}

task main()
{
	nVolume = 1;
	int s = 12;

	/*PlayAndDelay(0, s + s);
	PlayAndDelay(2, s + s);
	PlayAndDelay(3, s + s);

	PlayAndDelay(3, s);
	PlayAndDelay(3, s);
	PlayAndDelay(3, s + s);
	PlayAndDelay(3, s);
	PlayAndDelay(3, s);

	PlayAndDelay(3, s + s);
	PlayAndDelay(5, s + s);
	PlayAndDelay(7, s + s);

	PlayAndDelay(7, s);
	PlayAndDelay(7, s);
	PlayAndDelay(7, s + s);
	PlayAndDelay(7, s);
	PlayAndDelay(7, s);

	PlayAndDelay(7, s + s);
	PlayAndDelay(10, s + s);
	PlayAndDelay(5, s + s);

	PlayAndDelay(5, s);
	PlayAndDelay(5, s);
	PlayAndDelay(5, s + s);
	PlayAndDelay(7, s);
	PlayAndDelay(5, s);

	PlayAndDelay(3, s + s);
	PlayAndDelay(2, s + s);
	PlayAndDelay(0, s + s);

	PlayAndDelay(0, s);
	PlayAndDelay(0, s);
	PlayAndDelay(0, s + s);
	PlayAndDelay(0, s);
	PlayAndDelay(0, s);

	PlayAndDelay(0, s + s);
	PlayAndDelay(2, s + s);
	PlayAndDelay(3, s + s);

	PlayAndDelay(3, s);
	PlayAndDelay(3, s);
	PlayAndDelay(3, s + s);
	PlayAndDelay(3, s);
	PlayAndDelay(3, s);

	PlayAndDelay(3, s + s);
	PlayAndDelay(5, s + s);
	PlayAndDelay(7, s + s);

	PlayAndDelay(7, s);
	PlayAndDelay(7, s);
	PlayAndDelay(7, s + s);
	PlayAndDelay(7, s);
	PlayAndDelay(7, s);

	PlayAndDelay(7, s + s);
	PlayAndDelay(10, s + s);
	PlayAndDelay(12, s + s);

	PlayAndDelay(12, s);
	PlayAndDelay(12, s);
	PlayAndDelay(12, s + s);
	PlayAndDelay(12, s);
	PlayAndDelay(12, s);

	PlayAndDelay(10, s + s + s);
	PlayAndDelay(14, s);
	PlayAndDelay(12, s + s);

	PlayAndDelay(12, s);
	PlayAndDelay(12, s);
	PlayAndDelay(12, s + s);
	PlayAndDelay(12, s);
	PlayAndDelay(12, s);*/

	PlayAndDelay(12, s + s);
	PlayAndDelay(14, s + s);
	PlayAndDelay(15, s);

	PlayAndDelay(12, s);
	PlayAndDelay(12, s);
	PlayAndDelay(12, s);

	PlayAndDelay(14, s);

	PlayAndDelay(12, s);
	PlayAndDelay(12, s);
	PlayAndDelay(12, s);

	PlayAndDelay(12, 4 * s);
	PlayAndDelay(10, 4 * s);
	PlayAndDelay(8, 4 * s);
	PlayAndDelay(7, 4 * s);
	PlayAndDelay(5, 4 * s);

	PlayAndDelay(3, s);
	PlayAndDelay(7, s);
	PlayAndDelay(5, s);

	PlayAndDelay(3, s);
	PlayAndDelay(2, s);
	PlayAndDelay(0, s);
}
