
const int OUT1 = PD2,
          OUT2 = PD3,
          OUT3 = PD4,
          OUT4 = PD5;

const int H = 2,
          L = 0;

const int DT = 1;   // min workable == 2 ms

//const int state[] = { B1001, B0011, B0110, B1100 };

const int state[] = { B0001, B0011, B0010, B0110, B0100, B1100, B1000, B1001 };

const int STATE_COUNT = sizeof(state) / sizeof(int);

void setup()
{
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
}

const int DIRECTION_RIGHT = 1,
          DIRECTION_LEFT = -1;

int direction = DIRECTION_RIGHT;
int step = 2;


void loop()
{
  int s = state[step];

  digitalWrite(OUT1, s & B0001);
  digitalWrite(OUT2, s & B0010);
  digitalWrite(OUT3, s & B0100);
  digitalWrite(OUT4, s & B1000);
  delay(DT);

  step += direction;

  if (step < 0)
  {
    step = STATE_COUNT - 1;
  }
  else
  {
    if (step >= STATE_COUNT)
    {
      step = 0;
    }
  }
}
