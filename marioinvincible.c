
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

void p(int tone, int t10, int v)
{
	nVolume = v;
	playSemitone(tone, t10);
	wait10Msec(t10);
}

void p4(int t1, int t2, int t3, int t4, int ms10)
{
	playSemitone(t1, ms10);
	wait10Msec(ms10);
	playSemitone(t2, ms10);
	wait10Msec(ms10);
	playSemitone(t3, ms10);
	wait10Msec(ms10);
	playSemitone(t4, ms10);
	wait10Msec(ms10);
}

task main()
{
	int t = 12;
	int mV = 2;
	int bV = 2;
	while (true)
	{
		p(3, t, mV);
		p(-7, t, bV);
		p(3, t, mV);
		p(-7, t, bV);
		p(3, t, mV);
		p(-7, t, bV);
		p(-4, t, bV);
		p(3, t, mV);

		p(-7, t, bV);
		p(3, t, mV);
		p(-7, t, bV);
		p(-4, t, bV);
		p(3, t, mV);
		p(-4, t, bV);
		p(3, t, mV);
		p(-7, t, bV);

		p(2, t, mV);
		p(-9, t, bV);
		p(2, t, mV);
		p(-9, t, bV);
		p(2, t, mV);
		p(-9, t, bV);
		p(-5, t, bV);
		p(2, t, mV);

		p(-9, t, bV);
		p(2, t, mV);
		p(-9, t, bV);
		p(-5, t, bV);
		p(2, t, mV);
		p(-5, t, bV);
		p(2, t, mV);
		p(-9, t, bV);
	}
}
