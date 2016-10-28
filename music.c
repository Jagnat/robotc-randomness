
#define M_A2 -24
#define M_As2 -23
#define M_B2 -22
#define M_C3 -21
#define M_Cs3 -20
#define M_D3 -19
#define M_Ds3 -18
#define M_E3 -17
#define M_F3 -16
#define M_Fs3 -15
#define M_G3 -14
#define M_Gs3 -13
#define M_A3 -12
#define M_As3 -11
#define M_B3 -10
#define M_C4 -9
#define M_Cs4 -8
#define M_D4 -7
#define M_Ds4 -6
#define M_E4 -5
#define M_F4 -4
#define M_Fs4 -3
#define M_G4 -2
#define M_Gs4 -1
#define M_A4 0
#define M_As4 1
#define M_B4 2
#define M_C5 3
#define M_Cs5 4
#define M_D5 5
#define M_Ds5 6
#define M_E5 7
#define M_F5 8
#define M_Fs5 9
#define M_G5 10
#define M_Gs5 11
#define M_A5 12
#define M_As5 13
#define M_B5 14
#define M_C6 15
#define M_Cs6 16
#define M_D6 17
#define M_Ds6 18
#define M_E6 19
#define M_F6 20
#define M_Fs6 21
#define M_G6 22
#define M_Gs6 23
#define M_A6 24

void PlaySemitone(int toneAwayFromA, int ms10)
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
	else
	{
		float mult = 1;
		for (int x = 0; x < abs(toneAwayFromA); ++x)
			mult *= num;
		PlayTone((int)(base * (1 / mult)), ms10);
	}
}
