   /*===============================================================GAZA ROBOTIK TEAM UNP============================================================================//
                                                             Bismillah KRPAI Berkaki 2019
                                                            BASITUNGKIN LABORATORY PROJECT
                                                                  
                                                                    This Version:
                                                                  Al - Ankabut V2.0
                                                                
                                                                    Next Version:
                                                                  BASITUNGKIN V 3.0
                                                                    
                                                      Gaza Robotic TEAM Universitas Negeri Padang
                                                         BERKAKI !!! API PADAM PUNTUANG ANYUIK
                                                          Code by Aldova Guswantri / 16130035
//===============================================================GAZA ROBOTIK TEAM UNP============================================================================*/
const int in1 = 0;
const int in2 = 1;
const int in3 = 2;
const int in4 = 3;
const int in5 = 4;

#define suruahtagak                   100
#define suruahmaju1                   101
#define suruahmaju2                   102
#define suruahbelokkakida1            103
#define suruahbelokkakida2            104
#define suruahbelokkasuok1            105
#define suruahbelokkasuok2            106
#define suruahputaCW                  109
#define suruahputaCCW                 110
#define suruahmundur1                 111
#define suruahmundur2                 112
#define suruahputaCWslow              113
#define suruahputaCCWslow             114
#define suruahgeser1                  115
#define suruahgeser2                  116
#define suruahbukak                   117
#define suruahtutuik                  118
#define suruahtembak                  119

#define iku    200
#define badan  201
#define kuduak 202
#define suok   203
#define kida   204

float L1=0.00, L2=0.00, L3=0.00, L4=0.00, teta1=0.00, teta2=0.00, teta3=0.00, teta4=0.00, teta5=0.00;
float alpha=0.00, beta=0.00, gama=0.00;
int alphaR, alphaL, betaR, betaL, gamaR, gamaL, alphamove, betamove, gamamove;
unsigned int logic1, logic2, logic3, logic4, logic5 ;
unsigned int kancang, tunggu=0;
float cx=27.00, fm=40.00, tb=70.00, Z_off=53.00;
unsigned int command;

const int servo1 = 1; const int servo2 = 2; const int servo3 = 3;
const int servo4 = 4; const int servo5 = 5; const int servo6 = 6;
const int servo7 = 7; const int servo8 = 8; const int servo9 = 9;
const int servo10 = 10; const int servo11 = 11; const int servo12 = 12;
const int servo13 = 13; const int servo14 = 14; const int servo15 = 15;
const int servo16 = 17; const int servo17 = 16; const int servo18 = 18;
const int wheel = 100;
#define AX_BUS_SERIAL1 1

Dynamixel AX(AX_BUS_SERIAL1);

void setup(){
 
  pinMode(in1, INPUT_ANALOG);
  pinMode(in2, INPUT_ANALOG);
  pinMode(in3, INPUT_ANALOG);
  pinMode(in4, INPUT_ANALOG);
  pinMode(in5, INPUT_ANALOG);
  AX.begin(3);
  AX.jointMode(servo1); AX.jointMode(servo2); AX.jointMode(servo3);
  AX.jointMode(servo4); AX.jointMode(servo5); AX.jointMode(servo6);
  AX.jointMode(servo7); AX.jointMode(servo8); AX.jointMode(servo9);
  AX.jointMode(servo10); AX.jointMode(servo11); AX.jointMode(servo12);
  AX.jointMode(servo13); AX.jointMode(servo14); AX.jointMode(servo15);
  AX.jointMode(servo16); AX.jointMode(servo17); AX.jointMode(servo18);
  tagak(1023, 500);
  AX.wheelMode(wheel);
  AX.goalSpeed(wheel, 0);
}

void loop(){
  maju1(1023, 200);
  
//  bacoperintah();
//  if(command == suruahtagak){tagak(1023, 50);}
//  else if(command == suruahmaju1){maju1(1023, 50);}
//  else if(command == suruahmaju2){maju2(1023, 50);}
//  else if(command == suruahbelokkakida1){belokkakida1(1023, 50);}
//  else if(command == suruahbelokkakida2){belokkakida2(1023, 50);}
//  else if(command == suruahbelokkasuok1){belokkasuok1(1023, 50);}
//  else if(command == suruahbelokkasuok2){belokkasuok2(1023, 50);}
//  else if(command == suruahputaCW){putaCW(1023, 50);}
//  else if(command == suruahputaCCW){putaCCW(1023, 50);}
//  else if(command == suruahmundur1){maju2(1023, 50);}
//  else if(command == suruahmundur2){maju1(1023, 50);}
//  else if(command == suruahputaCWslow){putaCWslow(1023, 50);}
//  else if(command == suruahputaCCWslow){putaCCWslow(1023, 50);}
//  else if(command == suruahgeser1){geser1(1023, 50);}
//  else if(command == suruahgeser2){geser2(1023, 50);}
//  else {tagak(1023, 0);}
//  
//  if(command == suruahbukak){AX.goalSpeed(wheel, 1023 | 0x400);}
//  else if(command == suruahtutuik){AX.goalSpeed(wheel, 1023);}
//  else {AX.goalSpeed(wheel, 0);}
}

void IK(int ID1, int ID2, int ID3, int latakkaki, int spd, float x, float y, float z){
  double L1 = sqrt(sq(x)+sq(y));
  double teta1 = asin(y/L1)*180/PI;
  double L2 = L1-cx;
  double L3 = Z_off-z;
  double L4 = sqrt(sq(L2)+sq(L3));
  double teta2 = acos((sq(fm)+sq(L4)-sq(tb))/(2*fm*L4))*180/PI;
  double teta3 = acos((sq(fm)+sq(tb)-sq(L4))/(2*fm*tb))*180/PI;
  double teta4 = asin(L2/L4)*180/PI;
  double gama = teta1;
  double alpha = teta2+teta4-90;
  double beta = teta3;

  if(latakkaki==kida){alphamove=512+(alpha*3.41);
                      betamove=512+((180.00-beta)*3.41);
                      gamamove=512+(gama*3.41);}
  else{alphamove=512-(alpha*3.41);
       betamove=512-((180.00-beta)*3.41);
       gamamove=512-(gama*3.41);}     
    
  AX.setPosition (ID1, gamamove, spd);
  AX.setPosition (ID2, alphamove, spd);
  AX.setPosition (ID3, betamove, spd);
}

void maju1(const unsigned int kancang, const unsigned int tunggu){  
  IK(servo8, servo7, servo9, kida, kancang, 65, 10, 15);      IK(servo2, servo1, servo3, kida, kancang, 65, 10, 15);      IK(servo14, servo13, servo15, suok, kancang, 65, 10, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, -10, 0);   IK(servo11, servo10, servo12, suok, kancang, 65, -10, 0);   IK(servo5, servo4, servo6, kida, kancang, 65, -10, 0);
  delay (tunggu); 
  IK(servo8, servo7, servo9, kida, kancang, 65, 10, 0);       IK(servo2, servo1, servo3, kida, kancang, 65, 10, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, 10, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -10,15);   IK(servo11, servo10, servo12, suok, kancang, 65, -10, 15);  IK(servo5, servo4, servo6, kida, kancang, 65, -10, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -10, 0);      IK(servo2, servo1, servo3, kida, kancang, 65, -10, 0);      IK(servo14, servo13, servo15, suok, kancang, 65, -10, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 10, 15);   IK(servo11, servo10, servo12, suok, kancang, 65, 10, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, 10, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, 10, 0);    IK(servo11, servo10, servo12, suok, kancang, 65, 10, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, 10, 0);
  IK(servo8, servo7, servo9, kida, kancang, 65, -10, 15);     IK(servo2, servo1, servo3, kida, kancang, 65,  -10, 15);    IK(servo14, servo13, servo15, suok, kancang, 65, -10, 15);
  delay (tunggu);
  
}

void maju2(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 65, -11, 15);     IK(servo2, servo1, servo3, kida, kancang, 65, -11, 15);     IK(servo14, servo13, servo15, suok, kancang, 65, -11, 15);  
  IK(servo16, servo17, servo18, suok, kancang, 65, 11, 0);    IK(servo11, servo10, servo12, suok, kancang, 65, 11, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, 11, 0);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -11, 0);      IK(servo2, servo1, servo3, kida, kancang, 65, -11, 0);      IK(servo14, servo13, servo15, suok, kancang, 65, -11, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 11, 15);    IK(servo11, servo10, servo12, suok, kancang, 65, 11, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, 11, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, 11, 0);       IK(servo2, servo1, servo3, kida, kancang, 65, 11, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, 11, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -11, 15);  IK(servo11, servo10, servo12, suok, kancang, 65, -11, 15);  IK(servo5, servo4, servo6, kida, kancang, 65, -11, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, -11, 0);   IK(servo11, servo10, servo12, suok, kancang, 65, -11, 0);   IK(servo5, servo4, servo6, kida, kancang, 65, -11, 0);
  IK(servo8, servo7, servo9, kida, kancang, 65, 11, 15);      IK(servo2, servo1, servo3, kida, kancang, 65,  11, 15);     IK(servo14, servo13, servo15, suok, kancang, 65, 11, 15);
  delay (tunggu);
}

void putaCCW(const unsigned int kancang, const unsigned int tunggu){ 
  IK(servo8, servo7, servo9, kida, kancang, 65, -5, 15);     IK(servo2, servo1, servo3, kida, kancang, 65, -5, 15);     IK(servo14, servo13, servo15, suok, kancang, 65, 5, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, -5, 0);   IK(servo11, servo10, servo12, suok, kancang, 65, -5, 0);   IK(servo5, servo4, servo6, kida, kancang, 65, 5, 0);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -5, 0);      IK(servo2, servo1, servo3, kida, kancang, 65, -5, 0);      IK(servo14, servo15, servo15, suok, kancang, 65, 5, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -5,15);   IK(servo11, servo10, servo12, suok, kancang, 65, -5, 15);  IK(servo5, servo4, servo6, kida, kancang, 65, 5, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, 5, 0);       IK(servo2, servo1, servo3, kida, kancang, 65, 5, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, -5, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 5, 15);   IK(servo11, servo10, servo12, suok, kancang, 65, 5, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, -5, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, 5, 0);    IK(servo11, servo10, servo12, suok, kancang, 65, 5, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, -5, 0);
  IK(servo8, servo7, servo9, kida, kancang, 65, 5, 15);      IK(servo2, servo1, servo3, kida, kancang, 65,  5, 15);     IK(servo14, servo13, servo15, suok, kancang, 65, -5, 15);
  delay (tunggu);
}

void putaCW(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 65, 5, 15);      IK(servo2, servo1, servo3, kida, kancang, 65, 5, 15);      IK(servo14, servo13, servo15, suok, kancang, 65, -5, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, 5, 0);    IK(servo11, servo10, servo12, suok, kancang, 65, 5, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, -5, 0);
  delay (tunggu); 
  IK(servo8, servo7, servo9, kida, kancang, 65, 5, 0);       IK(servo2, servo1, servo3, kida, kancang, 65, 5, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, -5, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 5,15);    IK(servo11, servo10, servo12, suok, kancang, 65, 5, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, -5, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -5, 0);      IK(servo2, servo1, servo3, kida, kancang, 65, -5, 0);      IK(servo14, servo13, servo15, suok, kancang, 65, 5, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -5, 15);  IK(servo11, servo10, servo12, suok, kancang, 65, -5, 15);  IK(servo5, servo4, servo6, kida, kancang, 65, 5, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, -5, 0);   IK(servo11, servo10, servo12, suok, kancang, 65, -5, 0);   IK(servo5, servo4, servo6, kida, kancang, 65, 5, 0);
  IK(servo8, servo7, servo9, kida, kancang, 65, -5, 15);     IK(servo2, servo1, servo3, kida, kancang, 65, -5, 15);     IK(servo14, servo13, servo15, suok, kancang, 65, 5, 15);
  delay (tunggu);
}

void belokkasuok1(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 65, 10, 15);      IK(servo2, servo1, servo3, kida, kancang, 65, 10, 15);      IK(servo14, servo13, servo15, suok, kancang, 65, 0, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, -0, 0);    IK(servo11, servo10, servo12, suok, kancang, 65, -0, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, -10, 0);
  delay (tunggu); 
  IK(servo8, servo7, servo9, kida, kancang, 65, 10, 0);       IK(servo2, servo1, servo3, kida, kancang, 65, 10, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, 0, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -0,15);    IK(servo11, servo10, servo12, suok, kancang, 65, -0, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, -10, 15);
  delay (tunggu);  
  IK(servo8, servo7, servo9, kida, kancang, 65, -10, 0);      IK(servo2, servo1, servo3, kida, kancang, 65, -10, 0);      IK(servo14, servo13, servo15, suok, kancang, 65, -0, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 0, 15);    IK(servo11, servo10, servo12, suok, kancang, 65, 0, 15);    IK(servo5, servo4, servo6, kida, kancang, 65, 10, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, 0, 0);     IK(servo11, servo10, servo12, suok, kancang, 65, 0, 0);     IK(servo5, servo4, servo6, kida, kancang, 65, 10, 0);
  IK(servo8, servo7, servo9, kida, kancang, 65, -10, 15);     IK(servo2, servo1, servo3, kida, kancang, 65, -10, 15);     IK(servo14, servo13, servo15, suok, kancang, 65, -2, 15);
  delay (tunggu); 
}

void belokkasuok2(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 65, -2, 15);      IK(servo2, servo1, servo3, kida, kancang, 65, -2, 15);      IK(servo14, servo13, servo15, suok, kancang, 65, -11, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, 11, 0);    IK(servo11, servo10, servo12, suok, kancang, 65, 11, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, 2, 0);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -2, 0);       IK(servo2, servo1, servo3, kida, kancang, 65, -2, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, -11, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 11, 15);   IK(servo11, servo10, servo12, suok, kancang, 65, 11, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, 2, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, 2, 0);        IK(servo2, servo1, servo3, kida, kancang, 65, 2, 0);        IK(servo14, servo13, servo15, suok, kancang, 65, 11, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -11, 15);  IK(servo11, servo10, servo12, suok, kancang, 65, -11, 15);  IK(servo5, servo4, servo6, kida, kancang, 65, -2, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, -11, 0);   IK(servo11, servo10, servo12, suok, kancang, 65, -11, 0);   IK(servo5, servo4, servo6, kida, kancang, 65, -2, 0);
  IK(servo8, servo7, servo9, kida, kancang, 65, 2, 15);       IK(servo2, servo1, servo3, kida, kancang, 65, 2, 15);       IK(servo14, servo13, servo15, suok, kancang, 65, 11, 15);
  delay (tunggu);
}

void belokkakida1(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 65, 0, 15);       IK(servo2, servo1, servo3, kida, kancang, 65, 0, 15);       IK(servo14, servo13, servo15, suok, kancang, 65, 9, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, -9, 0);   IK(servo11, servo10, servo12, suok, kancang, 65, -9, 0);   IK(servo5, servo4, servo6, kida, kancang, 65, -0, 0);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, 0, 0);        IK(servo2, servo1, servo3, kida, kancang, 65, 0, 0);        IK(servo14, servo13, servo15, suok, kancang, 65, 9, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -9, 15);  IK(servo11, servo10, servo12, suok, kancang, 65, -9, 15);  IK(servo5, servo4, servo6, kida, kancang, 65, -0, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -0, 0);       IK(servo2, servo1, servo3, kida, kancang, 65, -0, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, -9, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 9, 15);   IK(servo11, servo10, servo12, suok, kancang, 65, 9, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, 0, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, 9, 0);    IK(servo11, servo10, servo12, suok, kancang, 65, 0, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, 0, 0);
  IK(servo8, servo7, servo9, kida, kancang, 65, -0, 15);      IK(servo2, servo1, servo3, kida, kancang, 65, -9, 15);      IK(servo14, servo13, servo15, suok, kancang, 65, -9, 15);
  delay (tunggu);
}

void belokkakida2(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 65, -11, 15);     IK(servo2, servo1, servo3, kida, kancang, 65, -11, 15);     IK(servo14, servo13, servo15, suok, kancang, 65, -2, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, 2, 0);     IK(servo11, servo10, servo12, suok, kancang, 65, 2, 0);     IK(servo5, servo4, servo6, kida, kancang, 65, 11, 0);
  delay (tunggu); 
  IK(servo8, servo7, servo9, kida, kancang, 65, -11, 0);      IK(servo2, servo1, servo3, kida, kancang, 65, -11, 0);      IK(servo14, servo13, servo15, suok, kancang, 65, -2, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 2, 15);    IK(servo11, servo10, servo12, suok, kancang, 65, 2, 15);    IK(servo5, servo4, servo6, kida, kancang, 65, 11, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, 11, 0);       IK(servo2, servo1, servo3, kida, kancang, 65, 11, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, 2, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -2, 15);   IK(servo11, servo10, servo12, suok, kancang, 65, -2, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, -11, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, -2, 0);    IK(servo11, servo10, servo12, suok, kancang, 65, -2, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, -11, 0);
  IK(servo8, servo7, servo9, kida, kancang, 65, 11, 15);      IK(servo2, servo1, servo3, kida, kancang, 65, 11, 15);      IK(servo14, servo13, servo15, suok, kancang, 65, 2, 15);
  delay (tunggu);
}

void geser1(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 70, 0, 15);      IK(servo2, servo1, servo3, kida, kancang, 70, 0, 15);        IK(servo14, servo13, servo15, suok, kancang, 60, 0, 15);
  IK(servo16, servo17, servo18, suok, kancang, 70, 0, 0);    IK(servo11, servo10, servo12, suok, kancang, 70, 0, 0);      IK(servo5, servo4, servo6, kida, kancang, 60, 0, 0);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 70, 0, 0);       IK(servo2, servo1, servo3, kida, kancang, 70, 0, 0);         IK(servo14, servo13, servo15, suok, kancang, 60, 0, 0);
  IK(servo16, servo17, servo18, suok, kancang, 70, 0,15);    IK(servo11, servo10, servo12, suok, kancang, 70, 0, 15);     IK(servo5, servo4, servo6, kida, kancang, 60, 0, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 60, 0, 0);       IK(servo2, servo1, servo3, kida, kancang, 60, 0, 0);         IK(servo14, servo13, servo15, suok, kancang, 70, 0, 0);
  IK(servo16, servo17, servo18, suok, kancang, 60, 0, 15);   IK(servo11, servo10, servo12, suok, kancang, 60, 0, 15);     IK(servo5, servo4, servo6, kida, kancang, 70, 0, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 60, 0, 0);    IK(servo11, servo10, servo12, suok, kancang, 60, 0, 0);      IK(servo5, servo4, servo6, kida, kancang, 70, 0, 0);
  IK(servo8, servo7, servo9, kida, kancang, 60, 0, 15);      IK(servo2, servo1, servo3, kida, kancang, 60,  0, 15);       IK(servo14, servo13, servo15, suok, kancang, 70, 0, 15);
  delay (tunggu);
}

void geser2(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 60, 0, 15);      IK(servo2, servo1, servo3, kida, kancang, 60, 0, 15);        IK(servo14, servo13, servo15, suok, kancang, 70, 0, 15);
  IK(servo16, servo17, servo18, suok, kancang, 60, 0, 0);    IK(servo11, servo10, servo12, suok, kancang, 60, 0, 0);      IK(servo5, servo4, servo6, kida, kancang, 70, 0, 0);
  delay (tunggu); 
  IK(servo8, servo7, servo9, kida, kancang, 60, 0, 0);       IK(servo2, servo1, servo3, kida, kancang, 60, 0, 0);         IK(servo14, servo13, servo15, suok, kancang, 70, 0, 0);
  IK(servo16, servo17, servo18, suok, kancang, 60, 0,15);    IK(servo11, servo10, servo12, suok, kancang, 60, 0, 15);     IK(servo5, servo4, servo6, kida, kancang, 70, 0, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 70, 0, 0);       IK(servo2, servo1, servo3, kida, kancang, 70, 0, 0);         IK(servo14, servo13, servo15, suok, kancang, 60, 0, 0);
  IK(servo16, servo17, servo18, suok, kancang, 70, 0, 15);   IK(servo11, servo10, servo12, suok, kancang, 70, 0, 15);     IK(servo5, servo4, servo6, kida, kancang, 60, 0, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 70, 0, 0);    IK(servo11, servo10, servo12, suok, kancang, 70, 0, 0);      IK(servo5, servo4, servo6, kida, kancang, 60, 0, 0);
  IK(servo8, servo7, servo9, kida, kancang, 70, 0, 15);      IK(servo2, servo1, servo3, kida, kancang, 70,  0, 15);       IK(servo14, servo13, servo15, suok, kancang, 60, 0, 15);
  delay(tunggu);
}

void putaCCWslow(const unsigned int kancang, const unsigned int tunggu){ 
  IK(servo8, servo7, servo9, kida, kancang, 65, 4, 15);      IK(servo2, servo1, servo3, kida, kancang, 65, 4, 15);       IK(servo14, servo13, servo15, suok, kancang, 65, -4, 15);
  delay(tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -4, 15);     IK(servo2, servo1, servo3, kida, kancang, 65, -4, 15);      IK(servo14, servo13, servo15, suok, kancang, 65, 4, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, -4, 0);  IK(servo11, servo10, servo12, suok, kancang, 65, -4, 0);   IK(servo5, servo4, servo6, kida, kancang, 65, 4, 0);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -4, 0);     IK(servo2, servo1, servo3, kida, kancang, 65, -4, 0);      IK(servo14, servo13, servo15, suok, kancang, 65, 4, 0);
  delay(tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, -4, 15);  IK(servo11, servo10, servo12, suok, kancang, 65, -4, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, 4, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, 4, 0);      IK(servo2, servo1, servo3, kida, kancang, 65, 4, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, -4, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, 4, 15);   IK(servo11, servo10, servo12, suok, kancang, 65, 4, 15);    IK(servo5, servo4, servo6, kida, kancang, 65, -4, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, 4, 0);   IK(servo11, servo10, servo12, suok, kancang, 65, 4, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, -4, 0);
  delay (tunggu);
}

void putaCWslow(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 65, -4, 15);     IK(servo2, servo1, servo3, kida, kancang, 65, -4, 15);      IK(servo14, servo13, servo15, suok, kancang, 65, 4, 15);
  delay(tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, 4, 15);      IK(servo2, servo1, servo3, kida, kancang, 65, 4, 15);       IK(servo14, servo13, servo15, suok, kancang, 65, -4, 15);
  IK(servo16, servo17, servo18, suok, kancang, 65, 4, 0);   IK(servo11, servo10, servo12, suok, kancang, 65, 4, 0);    IK(servo5, servo4, servo6, kida, kancang, 65, -4, 0);
  delay (tunggu); 
  IK(servo8, servo7, servo9, kida, kancang, 65, 4, 0);      IK(servo2, servo1, servo3, kida, kancang, 65, 4, 0);       IK(servo14, servo13, servo15, suok, kancang, 65, -4, 0);
  delay(tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, 4, 15);   IK(servo11, servo10, servo12, suok, kancang, 65, 4, 15);    IK(servo5, servo4, servo6, kida, kancang, 65, -4, 15);
  delay (tunggu);
  IK(servo8, servo7, servo9, kida, kancang, 65, -4, 0);     IK(servo2, servo1, servo3, kida, kancang, 65, -4, 0);      IK(servo14, servo13, servo15, suok, kancang, 65, 4, 0);
  IK(servo16, servo17, servo18, suok, kancang, 65, -4, 15);  IK(servo11, servo10, servo12, suok, kancang, 65, -4, 15);   IK(servo5, servo4, servo6, kida, kancang, 65, 4, 15);
  delay (tunggu);
  IK(servo16, servo17, servo18, suok, kancang, 65, -4, 0);  IK(servo11, servo10, servo12, suok, kancang, 65, -4, 0);   IK(servo5, servo4, servo6, kida, kancang, 65, 4, 0);
  delay (tunggu);
}

void tagak(const unsigned int kancang, const unsigned int tunggu){
  IK(servo8, servo7, servo9, kida, kancang, 70, 0, 0);       IK(servo2, servo1, servo3, kida, kancang, 70, 0, 0);         IK(servo5, servo4, servo6, kida, kancang, 70, 0, 0);
  IK(servo16, servo17, servo18, suok, kancang, 70, 0, 0);    IK(servo11, servo10, servo12, suok, kancang, 70, 0, 0);      IK(servo14, servo13, servo15, suok, kancang, 70, 0, 0);
  delay(tunggu);
}

void hello(){
  SerialUSB.println("hello world! by: KARAPAI UNP :)");
}

void bacoperintah(){
  logic1 = analogRead(in1);
  logic2 = analogRead(in2);
  logic3 = analogRead(in3);
  logic4 = analogRead(in4);
  logic5 = analogRead(in5);
  
  if(logic1 < 4000 && logic2 < 4000 && logic3 < 4000 && logic4 < 4000 && logic5 < 4000){command = suruahtagak;}
  else if(logic1 < 4000 && logic2 < 4000 && logic3 < 4000 && logic4 < 4000 && logic5 > 4000){command = suruahmaju1;}
  else if(logic1 < 4000 && logic2 < 4000 && logic3 < 4000 && logic4 > 4000 && logic5 < 4000){command = suruahmaju2;}
  else if(logic1 < 4000 && logic2 < 4000 && logic3 < 4000 && logic4 > 4000 && logic5 > 4000){command = suruahbelokkakida1;}
  else if(logic1 < 4000 && logic2 < 4000 && logic3 > 4000 && logic4 < 4000 && logic5 < 4000){command = suruahbelokkakida2;}
  else if(logic1 < 4000 && logic2 < 4000 && logic3 > 4000 && logic4 < 4000 && logic5 > 4000){command = suruahbelokkasuok1;}
  else if(logic1 < 4000 && logic2 < 4000 && logic3 > 4000 && logic4 > 4000 && logic5 < 4000){command = suruahbelokkasuok2;}
  else if(logic1 < 4000 && logic2 < 4000 && logic3 > 4000 && logic4 > 4000 && logic5 > 4000){command = suruahputaCW;}
  else if(logic1 < 4000 && logic2 > 4000 && logic3 < 4000 && logic4 < 4000 && logic5 < 4000){command = suruahputaCCW;}
  else if(logic1 < 4000 && logic2 > 4000 && logic3 < 4000 && logic4 < 4000 && logic5 > 4000){command = suruahmundur1;}
  else if(logic1 < 4000 && logic2 > 4000 && logic3 < 4000 && logic4 > 4000 && logic5 < 4000){command = suruahmundur2;}
  else if(logic1 < 4000 && logic2 > 4000 && logic3 < 4000 && logic4 > 4000 && logic5 > 4000){command = suruahputaCWslow;}
  else if(logic1 < 4000 && logic2 > 4000 && logic3 > 4000 && logic4 < 4000 && logic5 < 4000){command = suruahputaCCWslow;}
  else if(logic1 < 4000 && logic2 > 4000 && logic3 > 4000 && logic4 < 4000 && logic5 > 4000){command = suruahgeser1;}
  else if(logic1 < 4000 && logic2 > 4000 && logic3 > 4000 && logic4 > 4000 && logic5 < 4000){command = suruahgeser2;}
  else if(logic1 < 4000 && logic2 > 4000 && logic3 > 4000 && logic4 > 4000 && logic5 > 4000){command = suruahbukak;}
  else if(logic1 > 4000 && logic2 < 4000 && logic3 < 4000 && logic4 < 4000 && logic5 < 4000){command = suruahtutuik;}
  }
  
  /*==========================================================================================================================================================

                                    KONFIGURASI ID , POSISI SERIAL, DAN LETAK KAKI BASITUNGKIN V 2.0
  
          KAKI A                                      _____                            _____   KAKI D
          AX.setPosition (servo8, gamaL, spd);             \                          /        AX.setPosition (servo17, gamaR, spd);
          AX.setPosition (servo7, alphaL, spd);             \                        /         AX.setPosition (servo16, alphaR, spd);
          AX.setPosition (servo9, betaL, spd);               \==========/\==========/          AX.setPosition (servo18, betaR, spd);
                                                             I                      I  
                                                             I   Kuduak / Pinggang1 I
                                                             I                      I
                                                             I                      I
    KAKI B                                                   I----------------------I               KAKI E
    AX.setPosition (servo5, gamaL,spd);                      I                      I               AX.setPosition (servo14, gamaR, spd);
    AX.setPosition (servo4, alphaL, spd);       _____________I   Badan / Pinggang2  I_____________  AX.setPosition (servo13, alphaR, spd);
    AX.setPosition (servo6, betaL, spd);                     I                      I               AX.setPosition (servo15, betaR, spd);
                                                             I                      I 
                                                             I----------------------I
                                                             I                      I
                                                             I    Iku / Pinggang3   I
                                                             I                      I  
           KAKI C                                            I                      I          KAKI F
           AX.setPosition (servo2, gamaL, spd);              /======================\          AX.setPosition (servo11, gamaR, spd);
           AX.setPosition (servo1, alphaL, spd);            /                        \         AX.setPosition (servo10, alphaR, spd);
           AX.setPosition (servo3, betaL, spd);       _____/                          \_____   AX.setPosition (servo12, betaR, spd);

  ==========================================================================================================================================================*/
