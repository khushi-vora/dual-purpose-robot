int m1a = 3;
int m1b = 2;
int m2a = 5;
int m2b = 4;
int ir1 = 14;
int ir2 = 15;
int led1 = 16;
int led2 = 17;
char r;
int mode=0;

void forward()
{
digitalWrite(m1a,HIGH);
digitalWrite(m1b,LOW);
digitalWrite(m2a,HIGH);
digitalWrite(m2b,LOW);
}

void backward()
{
digitalWrite(m1a,LOW);
digitalWrite(m1b,HIGH);
digitalWrite(m2a,LOW);
digitalWrite(m2b,HIGH);
}

void left()
{
digitalWrite(m1a,HIGH);
digitalWrite(m1b,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2b,LOW);
}

void right()
{
digitalWrite(m1a,LOW);
digitalWrite(m1b,LOW);
digitalWrite(m2a,HIGH);
digitalWrite(m2b,LOW);  
}

void rotate_clk()
{
digitalWrite(m1a,LOW);
digitalWrite(m1b,HIGH);
digitalWrite(m2a,HIGH);
digitalWrite(m2b,LOW);
}

void rotate_anti()
{
digitalWrite(m1a,HIGH);
digitalWrite(m1b,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2b,HIGH);
}

void stp()
{
digitalWrite(m1a,LOW);
digitalWrite(m1b,LOW);
digitalWrite(m2a,LOW);
digitalWrite(m2b,LOW);
}

void setup() {
pinMode(m1a,OUTPUT);
pinMode(m1b,OUTPUT);
pinMode(m2a,OUTPUT);
pinMode(m2b,OUTPUT);
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
Serial.begin(9600);
}

void loop() {

while (mode==0)
{
r=Serial.read();
if (r=='F')
forward();

if (r=='B')
backward();

if (r=='L')
right();

if (r=='R')
left();

if (r=='S')
stp();

if (r=='W')
{
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
}

if (r=='w')
{
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
}

if (r=='X')
mode=1;
}

while(mode==1)
{
r=Serial.read();

if (((digitalRead(ir1)) == (LOW)) && (digitalRead(ir2) == (LOW)))
forward();

if((digitalRead(ir1) == (HIGH)) && (digitalRead(ir2) == (LOW)))
left();

if ((digitalRead(ir1) == (LOW)) && (digitalRead(ir2) == (HIGH)))
right(); 

if ((digitalRead(ir1) == (HIGH)) && (digitalRead(ir2) == (HIGH)))
stp();

if (r=='W')
{
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
}

if (r=='w')
{
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
}

if (r=='x')
mode=0;
}
}
