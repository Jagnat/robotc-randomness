#define M_PORT motorA

void handleDelta();
void updatePaddle();
void drawPaddle();
void spawnBall();
void updateBall();
void drawBall();
void drawScore();
void playWallBounce();
void playPaddleBounce();


typedef struct
{
	int x;
	int y;
	int width;
	int height;
} Paddle;

typedef struct
{
	float x;
	float y;
	int size;
	float xVel;
	float yVel;
} Ball;

Paddle paddle;
Ball ball;
int motorRotation = 0;
int delta = 0;

int score = 0;

task main()
{
	nVolume = 2;
	paddle.width = 17;
	paddle.height = 2;
	paddle.x = 45;
	paddle.y = 6;
	ball.size = 5;
	spawnBall();
	bFloatDuringInactiveMotorPWM = true;
	motorRotation = nMotorEncoder[M_PORT] = 0;
	while (true)
	{
		handleDelta();
		updatePaddle();
		updateBall();

		eraseDisplay();
		drawPaddle();
		drawBall();
		drawScore();
		//nxtDisplayBigTextLine(0, "%d", delta);
		wait1Msec(17);
	}
}

void handleDelta()
{
		delta = nMotorEncoder[M_PORT] - motorRotation;
		if (delta > 20)
			delta = 20;
		if (delta < -20)
			delta = -20;

		float f = (float)delta * 1;
		delta = (int)f;
		motorRotation = nMotorEncoder[M_PORT];
}

void updatePaddle()
{
	if (delta > 0)
	{
		if ((paddle.x + paddle.width + delta) > 99)
			paddle.x = 99 - paddle.width;
		else
			paddle.x += delta;
	}
	else if (delta < 0)
	{
		if (paddle.x + delta < 0)
			paddle.x = 0;
		else
			paddle.x += delta;
	}
}

void drawPaddle()
{
	nxtDrawRect(paddle.x+1, paddle.y + paddle.height, paddle.x-1 + paddle.width, paddle.y);
}

void spawnBall()
{
	ball.x = random(100);
	ball.y = random(40) + 24;
	ball.xVel = 0.25;
	ball.yVel = 0.25;
}

int ctr = 0;
void updateBall()
{
	if (ball.xVel == 0 && ball.yVel == 0)
		return;
	if (ball.x + ball.size + ball.xVel > 99)
	{
		ball.x = 99 - ball.size;
		ball.xVel = -ball.xVel;
		playWallBounce();
	}
	else if (ball.x + ball.xVel < 0)
	{
		ball.x = 0;
		ball.xVel = -ball.xVel;
		playWallBounce();
	}
	else
		ball.x += ball.xVel;
	int xpv = ball.x + ball.xVel;
	if (ball.y + ball.size + ball.yVel > 63)
	{
		ball.y = 63 - ball.size;
		ball.yVel = -ball.yVel;
		playWallBounce();
	}
	else if (ball.y + ball.yVel < paddle.y + paddle.height &&
		ball.y + ball.yVel > paddle.y - 3 &&
		xpv >= paddle.x &&
		xpv <= paddle.x + paddle.width &&
		ctr > 20)
	{
		playPaddleBounce();
		ball.yVel = abs(ball.yVel);
		if (ball.yVel < 0)
			ball.yVel += -.2;
		else
			ball.yVel += .2;
		if (ball.xVel < 0)
			ball.xVel += -.2;
		else
			ball.xVel += .2;
		int cap = 2;
		if (ball.yVel > cap)
			ball.yVel = cap;
		if (ball.xVel > cap)
			ball.xVel = cap;
		ctr = 0;
	}
	else
		ball.y += ball.yVel;
	if (ball.y < 0)
	{
		PlayTone(305, 75);
		wait10Msec(75);
		spawnBall();
	}
	ctr++;
}

void drawBall()
{
	nxtDrawCircle(ball.x, ball.y + ball.size, ball.size);
}

void drawScore()
{
	nxtDisplayBigTextLine(0, "%d", score);
}

void playWallBounce()
{
	PlayTone(1222, 10);
}

void playPaddleBounce()
{
	PlayTone(611, 10);
}
