
#include "music.c"

void p(int f, int ms)
{
	PlaySemitone(f, ms - 2);
	wait10Msec(ms);
}

void w(int ms)
{
	wait10Msec(ms);
}

void p1(int endTone);
void p2();
void p3();
void p4();
void p5();
void p6();

const int t = 12;

task main()
{
	nVolume = 2;
	while (true) {
	p1(M_C6);
	p1(M_C5);
	p2();
	p2();
	p3();
	p4();
	p5();
	p6(); }
}

void p6()
{
	p(M_A5, t);
	p(M_A5, t);
	w(t);
	p(M_D5, t);
	w(t);
	p(M_D5, t);
	p(M_C5, t);
	w(t);
	p(M_D5, t);
	w(t);
	p(M_D5, t);
	p(M_D5, t);
	p(M_D5, t);
	w(t * 3);
	p(M_As4, t);
	w(t);
	p(M_As4, t);
	w(t);
	p(M_D5, t);
	p(M_F5, t * 3);
	p(M_C5, t);
	w(t);
	p(M_C5, t);
	w(t);
	p(M_A4, t);
	p(M_C5, t * 3);
}

void p5()
{
	p(M_D6, t);
	p(M_D6, t);
	w(t);
	p(M_D5, t);
	w(t);
	p(M_D5, t);
	p(M_C5, t);
	w(t);
	p(M_D5, t);
	w(t);
	p(M_D5, t);
	p(M_D5, t);
	p(M_D5, t);
	w(t * 3);
	p(M_As4, t);
	w(t);
	p(M_As4, t);
	w(t);
	p(M_D5, t);
	p(M_F5, t * 3);
	p(M_C5, t);
	w(t);
	p(M_C5, t);
	w(t);
	p(M_E5, t);
	p(M_G5, t * 3);
}

void p4()
{
	p(M_Cs5, t * 3);
	p(M_E5, t * 3);
	p(M_As5, t * 2);
	p(M_A5, t * 3);
	p(M_F5, t * 3);
	p(M_D5, t * 2);
	p(M_E5, t * 3);
	p(M_G5, t * 3);
	p(M_As5, t * 2);
	p(M_A5, t * 3);
	p(M_B5, t * 3);
	p(M_Cs6, t * 2);
}

void p3()
{
	p(M_Cs5, t * 3);
	p(M_E5, t * 3);
	p(M_As5, t * 2);
	p(M_A5, t * 3);
	p(M_F5, t * 3);
	p(M_D5, t * 2);
	p(M_Cs5, t * 3);
	p(M_E5, t * 3);
	p(M_As5, t * 2);
	p(M_A5, t * 3);
	p(M_D5, t * 2);
	w(t * 3);
}

void p2()
{
	w(t * 2);
	p(M_D5, t);
	w(t * 2);
	p(M_A5, t);
	w(t * 2);
	p(M_Gs5, t);
	p(M_A5, t);
	p(M_Gs5, t);
	p(M_F5, t);
	w(t * 4);
	p(M_A5, t);
	w(t);
	p(M_F5, t);
	p(M_D5, t);
	w(t);
	p(M_Gs5, t);
	p(M_G5, t);
	p(M_F5, t);

	p(M_A5, t);
	p(M_F5, t);
	p(M_D5, t);
	p(M_F5, t);
	p(M_D5, t);
	p(M_F5, t);
	p(M_D5, t);
	p(M_F5, t);
}

void p1(int endTone)
{
	p(M_D6, t);
	p(M_D6, t);
	w(t);
	p(M_C6, t);

	w(t);
	p(M_B5, t * 5);

	w(t);
	p(M_D5, t * 2);
	p(M_E5, t);
	p(M_F5, t);
	p(M_G5, t);
	p(M_A5, t * 3);
	p(M_D5, t * 3);
	p(M_A5, t * 2);
	p(M_G5, t);
	p(endTone, t * 4);
	w(t * 3);
}
