/*===============================================================GAZA ROBOTIK TEAM UNP============================================================================//
                                                              Bismillah KRPAI Berkaki 2018
                                                            BASITUNGKIN LABORATORY PROJECT
                                                                  
                                                                    This Version:
                                                                  Al - Ankabut V2.0
                                                                
                                                                    Next Version:
                                                                  BASITUNGKIN V 3.0
                                                                    
                                                      Gaza Robotic TEAM Universitas Negeri Padang
                                                         BERKAKI !!! API PADAM PUNTUANG ANYUIK
                                                          Code by Aldova Guswantri / 16130035
//===============================================================GAZA ROBOTIK TEAM UNP============================================================================*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "TPA81.h"

LiquidCrystal_I2C lcd(0x3F, 16, 2);
TPA81 tpa;

#define address_cmps12 0x60

#define kapalo_1             112
#define kapalo_2             113

#define ada_api              114
#define tiada_api            115

#define bukak                116
#define tutuik               117
#define tagak                118    
#define maju_2               119
#define maju_1               120
#define belok_kakida_1       121
#define belok_kakida_2       122
#define belok_kasuok_1       123
#define belok_kasuok_2       124
#define puta_CW              125
#define puta_CCW             126
#define mundur_1             127
#define mundur_2             128
#define puta_CW_slow         129
#define puta_CCW_slow        130
#define geser_kiri_1         132
#define geser_kanan_1        131
#define geser_kiri_2         163
#define geser_kanan_2        162

#define kom_atas    133
#define kom_kanan   134
#define kom_bawah   135
#define kom_kiri    136

#define ada_boneka       142
#define tiada_boneka     143

#define tunggu_perintah  144
#define mulai_algoritma  145
#define masuk            160
#define keluar           161
#define kebakaran        171
#define pulang           172
#define dirumah          173

#define layer_1        146
#define layer_2        147
#define layer_3_1      148
#define layer_3_2      149
#define layer_3_3      150
#define layer_3_4      151
#define layer_3_5      152
#define layer_3_6      153
#define layer_3_7      162
#define layer_3_8      170

#define entah_dimana     154
#define didepan_api      155

#define ada_garis     156
#define tiada_garis   157

#define dinding_kiri   158
#define dinding_kanan  159

#define room_1    163
#define room_2    164
#define room_3    165
#define room_4    166

#define door_1    167
#define door_2    168
#define door_3    169
//===============================================================SET VALUE CONFIGURATION==============================================================================//

unsigned int SV_kompas = 0;
unsigned int SV_garis  = 1002;
unsigned int SV_MIC    = 100;
unsigned int SV_suhu   = 38;
 
//===============================================================SET VALUE CONFIGURATION==============================================================================//

const byte echo_jam_2       = 22;
const byte trig_jam_2       = 24;
const byte jam_3            = 34; 
const byte echo_jam_4       = 26; 
const byte trig_jam_4       = 28;
const byte echo_jam_6       = 47;
const byte trig_jam_6       = 49;
const byte echo_jam_8       = 40;
const byte trig_jam_8       = 38;
const byte jam_9            = 36;
const byte echo_jam_10      = 44;
const byte trig_jam_10      = 42;
const byte echo_jam_12      = 51;
const byte trig_jam_12      = 53;
const byte SA_OK           = 32;
const byte tabaka          = 30;
const byte tembak          = 39;
 
const byte butt_1 = 37;
const byte butt_2 = 35;
const byte butt_3 = 33;
const byte butt_4 = 31;
const byte butt_5 = 29;

const byte pin_MIC = A8;
unsigned int MIC;

unsigned int jarak_depan, jarak_belakang, jarak_serdepka, jarak_serdepki, jarak_serbelki, jarak_serbelka;
long lamobunyi, jarak;

unsigned int data_tiada_boneka = 0, data_ada_boneka = 0;
unsigned int sharp;

bool logic_1 = 0, logic_2 = 0, logic_3 = 0, logic_4 = 0, logic_5 = 0;
unsigned int command = 0, gerak = 0;
unsigned int kapalo_state = kapalo_2, telusur = dinding_kanan;

unsigned int data_garis = tiada_garis;
bool line_1, line_2, line_3;

unsigned char high_byte, low_byte, angle8;
char pitch, roll;
int angle16, sudut_kompas, sudut_kompas_mentah, arah = 0;

unsigned int UV;
unsigned int status_api = tiada_api, posisi_api = entah_dimana;
unsigned int p[]= {0};
float tpa_averenge;

bool _DEC = 0, _INC = 0, _ENT = 0, _CAN = 0, recstate = 0;
int menu_1 = 0, menu_2 = 0, menu_3_1 = 0, layer_state = layer_1, status_lisa = mulai_algoritma;

bool SA_OK_state = HIGH, tabaka_state = HIGH;

unsigned int state_ruangan_masuk = 0, state_pintu_masuk = 0, state_ruangan_keluar = 0, state_pintu_keluar = 0;
unsigned int rumah = 0;

void setup() {
  Wire.begin();
  inisialisasi_pin();
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ROBOTIKA&OTOMASI");
      lcd.setCursor(0,1);
      lcd.print("    MENGABDI    ");
      delay(1000);  
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

void loop(){ 

    baco_jarak();

    if(status_lisa == mulai_algoritma){    
      get_menu();
      display_menu();}
    else {
      lcd.setCursor(0,0);
      lcd.print("ROBOTIKA&OTOMASI");
      lcd.setCursor(0,1);
      lcd.print("    MENGABDI    ");
      telusur_kiri();      
    }

  
//  if(status_lisa == mulai_algoritma){
//    baco_MIC();
//    baco_kompas();
//    get_menu();
//    display_menu();
//    
//}
//  else if(status_lisa == masuk){masuk_ruangan();}
//  else if(status_lisa == keluar){keluar_ruangan();}
//  else if(status_lisa == kebakaran){padamkan_lisa();}
//  else if(status_lisa == pulang){pulang_lisa();}
//  else if(status_lisa == dirumah){kirim(tagak);}
//  display_indikator();
  }

void pulang_lisa(){
  baco_garis();
  if(data_garis == ada_garis){
    baco_ruangan_masuk();
    if(state_ruangan_masuk == rumah){
        if(kapalo_state == kapalo_1){kirim(maju_1);}
        else{kirim(maju_2);}
        delay(600);
        status_lisa = dirumah;
       } 
     else{
        if(kapalo_state == kapalo_1){kapalo_state =kapalo_2;} else kapalo_state = kapalo_1;
        if(kapalo_state == kapalo_1){kirim(geser_kanan_1); delay(500);} else {kirim(geser_kanan_2); delay(500);}
        if(kapalo_state == kapalo_1){kirim(maju_1); delay(500);} else {kirim(maju_2); delay(500);}  
      }  
    }
 else telusur_kanan();
  }

void padamkan_lisa(){
  if(state_ruangan_masuk == room_1 && state_pintu_masuk == door_1){
    for(int i=0; i<2000; i++){
      baco_suhu();
      if(posisi_api == didepan_api){
        kirim(tagak);
        tembak_lisa();
        status_lisa = keluar;
        break;
        }
      else {kirim(puta_CCW_slow);}
      delay(1);  
           
      }
    for(int i=0; i<200; i++){
      baco_suhu();
      if(posisi_api == didepan_api){
        kirim(tagak);
        tembak_lisa();
        status_lisa = keluar;
        break;
        }
      else{
        if(kapalo_state == kapalo_1){kirim(geser_kiri_1);}
        else {kirim(geser_kiri_2);}
        }
      delay(1);      
      }
    }
    for(int i=0; i<2000; i++){
      baco_suhu();
      if(posisi_api == didepan_api){
        kirim(tagak);
        tembak_lisa();
        status_lisa = keluar;
        break;
        }
      else {kirim(puta_CW_slow);}
      delay(1);      
      }
    for(int i=0; i<200; i++){
      baco_suhu();
      if(posisi_api == didepan_api){
        kirim(tagak);
        tembak_lisa();
        status_lisa = keluar;
        break;
        }
      else{
        if(kapalo_state == kapalo_1){kirim(geser_kiri_1);}
        else {kirim(geser_kiri_2);}
      } 
      delay(1);          
      }
  }

void masuk_ruangan(){
    cek_boneka();
    baco_garis();
    
    if(data_garis == ada_garis){
        baco_ruangan_masuk();
        
        if(kapalo_state == kapalo_1){kirim(maju_1); delay(600);} 
        else if(kapalo_state == kapalo_2){kirim(maju_2); delay(600);}

        if(state_ruangan_masuk == room_1 && state_pintu_masuk == door_1){
            telusur = dinding_kiri; 
            for(int i=0; i<700; i++){
              baco_api();
              if(status_api == ada_api){status_lisa = kebakaran; if(kapalo_state == kapalo_1){kirim(geser_kiri_1);} else{kirim(geser_kiri_2);} delay(300); break;}
              else kirim(puta_CCW);
              delay(1);
              }
            delay(700); 
            if(kapalo_state == kapalo_1){kirim(geser_kiri_1); delay(400);} else {kirim(geser_kiri_2); delay(400);}      
            if(status_api != ada_api){status_lisa = keluar;}    
          }
        else{
            telusur = dinding_kanan;
            for(int i=0; i<700; i++){
              baco_api();
              if(status_api == ada_api){status_lisa = kebakaran; if(kapalo_state == kapalo_1){kirim(geser_kanan_1);} else{kirim(geser_kanan_2);} delay(300); break;}
              else kirim(puta_CW);
              delay(1);
              }
            delay(700);
            if(kapalo_state == kapalo_1){kirim(geser_kanan_1); delay(400);} else {kirim(geser_kanan_2); delay(400);}
            if(status_api != ada_api){status_lisa = keluar;}
          }
        }
    else telusur_kiri();
  }

void keluar_ruangan(){
      cek_boneka();
      baco_garis();
      if(data_garis == ada_garis){

        if(rumah == 0){
          delay(500);
          baco_ruangan_keluar();
          rumah = state_ruangan_keluar;
          }
          
        if(state_ruangan_keluar == room_1 && state_pintu_keluar == door_1){
            if(status_api == ada_api){
              if(kapalo_state == kapalo_1){kirim(geser_kanan_1);}
              else{kirim(geser_kanan_2);}
              delay(400);
              if(kapalo_state == kapalo_1){kirim(belok_kasuok_1);}
              else{kirim(belok_kasuok_2);}
              delay(400);
              status_lisa = pulang;
              }
            else {
              if(kapalo_state == kapalo_1){kirim(maju_1);}
              else{kirim(maju_2);}
              delay(200);
              status_lisa = masuk;
              }
          }
        else{
            if(status_api == ada_api){
              status_lisa = pulang;
              if(kapalo_state == kapalo_1){kirim(geser_kanan_1);}
              else{kirim(geser_kanan_2);}
              delay(400);
              }
            else {
              if(kapalo_state == kapalo_1){kirim(geser_kiri_1);}
              else{kirim(geser_kiri_2);}
              delay(400);
              if(kapalo_state == kapalo_1){kirim(belok_kakida_1);}
              else{kirim(belok_kakida_2);}
              delay(400);
              status_lisa = masuk;
              }          
            }
      }       
      else{
      if(telusur == dinding_kanan){telusur_kanan();}
      else if(telusur == dinding_kiri){telusur_kiri();}  
      }
   }


void telusur_kiri(){
      baco_jarak();
      telusur = dinding_kiri;
      
      //if(jarak_serdepki < 6){if(kapalo_state == kapalo_1){gerak = geser_kanan_1;} else gerak = geser_kanan_2;}
      if(jarak_depan < 22 && jarak_serdepki < 25){gerak = puta_CW;}
      else if(jarak_serdepki > 22){if(kapalo_state == kapalo_1){gerak = belok_kakida_1;} else gerak = belok_kakida_2;}
      //else if(jarak_serbelki> 15  && jarak_serdepki > 15){if(kapalo_state == kapalo_1){gerak = geser_kiri_1;} else gerak = geser_kiri_2;}
      else if(jarak_serdepki < 12){if(kapalo_state == kapalo_1){gerak = belok_kasuok_1;} else gerak = belok_kasuok_2;}
      else if(jarak_serdepki >= 12 && jarak_serdepki <= 20){if(kapalo_state == kapalo_1){gerak = maju_1;} else gerak = maju_2;}
      else{if(kapalo_state == kapalo_1){gerak = geser_kiri_1;} else gerak = geser_kiri_2;}

      kirim(gerak);
  }

void telusur_kanan(){
      baco_jarak();
      telusur = dinding_kanan;

      if(jarak_serdepka < 6){if(kapalo_state == kapalo_1){gerak = geser_kiri_1;} else gerak = geser_kiri_2;}
      else if(jarak_depan < 22 && jarak_serdepka < 25){gerak = puta_CCW;}
      else if(jarak_serdepka > 22){if(kapalo_state == kapalo_1){gerak = belok_kasuok_1;} else gerak = belok_kasuok_2;}
      else if(jarak_serbelka > 15  && jarak_serdepka > 15){if(kapalo_state == kapalo_1){gerak = geser_kanan_1;} else gerak = geser_kanan_2;}
      else if(jarak_serdepka < 12){if(kapalo_state == kapalo_1){gerak = belok_kakida_1;} else gerak = belok_kakida_2;}
      else if(jarak_serdepka >= 12 && jarak_serdepka <= 20){if(kapalo_state == kapalo_1){gerak = maju_1;} else gerak = maju_2;}
      else{if(kapalo_state == kapalo_1){gerak = geser_kanan_1;} else gerak = geser_kanan_2;}

      kirim(gerak);
  }


void inisialisasi_pin(){
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(trig_jam_2, OUTPUT);  pinMode(echo_jam_2, INPUT);
  pinMode(trig_jam_4, OUTPUT);  pinMode(echo_jam_4, INPUT);
  pinMode(trig_jam_6, OUTPUT);  pinMode(echo_jam_6, INPUT);
  pinMode(trig_jam_8, OUTPUT);  pinMode(echo_jam_8, INPUT);
  pinMode(trig_jam_10, OUTPUT);  pinMode(echo_jam_10, INPUT);
  pinMode(trig_jam_12, OUTPUT); pinMode(echo_jam_12, INPUT);
  
  pinMode(SA_OK, OUTPUT);
  pinMode(tabaka, OUTPUT);
  digitalWrite(SA_OK,HIGH);
  digitalWrite(tabaka, HIGH);

  pinMode(butt_1, INPUT);
  pinMode(butt_2, INPUT);
  pinMode(butt_3, INPUT);
  pinMode(butt_4, INPUT);
  pinMode(butt_5, INPUT);
}

void baco_jarak() {
  if(kapalo_state == kapalo_2){
      srf04(trig_jam_12, echo_jam_12);  jarak_depan = jarak;
      srf04(trig_jam_2, echo_jam_2);    jarak_serdepka = jarak;
      srf04(trig_jam_10, echo_jam_10);  jarak_serdepki = jarak;
      srf04(trig_jam_6, echo_jam_6);    jarak_belakang = jarak;
      srf04(trig_jam_8, echo_jam_8);    jarak_serbelki = jarak;
      srf04(trig_jam_4, echo_jam_4);    jarak_serbelka = jarak;
      //ping(jam_3);                      jarak_kanan = jarak;
      //ping(jam_9);                      jarak_kiri = jarak;
    }
  else if(kapalo_state == kapalo_1){
      srf04(trig_jam_6, echo_jam_6);    jarak_depan = jarak;
      srf04(trig_jam_8, echo_jam_8);    jarak_serdepka = jarak;
      srf04(trig_jam_4, echo_jam_4);    jarak_serdepki = jarak;
      srf04(trig_jam_12, echo_jam_12);  jarak_belakang = jarak;
      srf04(trig_jam_2, echo_jam_2);    jarak_serbelki = jarak;
      srf04(trig_jam_10, echo_jam_10);  jarak_serbelka = jarak;
      //ping(jam_3);                      jarak_kiri = jarak;
      //ping(jam_9);                      jarak_kanan = jarak;
    }
}

void baco_sharp(){
  if(kapalo_state == kapalo_1){
      float sv1 = analogRead(A14) * 0.0048828125;
      sharp = 13 * pow(sv1, -1);
    }
    
  else{
      float sv2 = analogRead(A15) * 0.0048828125;
      sharp = 13 * pow(sv2, -1);
    }
       }

void baco_api(){
  if(kapalo_state == kapalo_1){UV = analogRead(A12);}
  else if(kapalo_state == kapalo_2){UV = analogRead(A13);}
  
  if(UV == 0){status_api = ada_api; tabaka_state = LOW;}
  }

void baco_MIC(){
  MIC = analogRead(pin_MIC);
  if (MIC > SV_MIC){
    baco_jarak();
    if((jarak_serdepki + jarak_serbelki) > (jarak_serdepka + jarak_serbelka)){kapalo_state = kapalo_1;}
    else {kapalo_state = kapalo_2;}
    SA_OK_state = LOW;
    status_lisa = keluar;         
  }
}

void baco_garis(){
  if(analogRead(A5) > SV_garis){line_1 = 1;} else{line_1 = 0;}
  if(analogRead(A6) > SV_garis){line_2 = 1;} else{line_2 = 0;}
  if(analogRead(A7) > SV_garis){line_3 = 1;} else{line_3 = 0;}

  if((line_1 == 1 && line_2 == 1)||(line_1 ==1 && line_3 == 1)||(line_2 == 1 && line_3 == 1) || (line_1 == 1 && line_2 == 1 && line_3 == 1)){
      data_garis = ada_garis;
    }
  else {data_garis = tiada_garis;}
  }

void baco_kompas(){
  Wire.beginTransmission(address_cmps12);  //starts communication with CMPS11
  Wire.write(1);                       //Sends the register we wish to start reading from
  Wire.endTransmission();
  Wire.requestFrom(address_cmps12, 5);       
  
  while(Wire.available() < 5);     // Wait for all bytes to come back
  
  angle8 = Wire.read();            // Read back the 5 bytes
  high_byte = Wire.read();
  low_byte = Wire.read();
  pitch = Wire.read();
  roll = Wire.read();
  
  angle16 = high_byte;            // Calculate 16 bit angle
  angle16 <<= 8;
  angle16 += low_byte;

  sudut_kompas_mentah = angle16/10;
  
  if(kapalo_state == kapalo_2){SV_kompas = SV_kompas + 180;}
  
  if(sudut_kompas_mentah < SV_kompas){sudut_kompas = sudut_kompas_mentah - SV_kompas + 360;}
  else{sudut_kompas = sudut_kompas_mentah - SV_kompas;}

  if(kapalo_state == kapalo_2){SV_kompas = SV_kompas - 180;}
  
  if(sudut_kompas <= 30 || sudut_kompas >= 330){arah = kom_atas;}
  else if(sudut_kompas >= 60 && sudut_kompas <= 120){arah = kom_kanan;}
  else if(sudut_kompas >= 150 && sudut_kompas <= 210){arah = kom_bawah;}
  else if(sudut_kompas >= 240 && sudut_kompas <= 300){arah = kom_kiri;}
  else arah = 0;
  }

void srf04(const unsigned int trig_pin, const unsigned int echo_pin){
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig_pin, LOW);
  long lamo_bunyi = pulseIn(echo_pin, HIGH);
  jarak = lamo_bunyi/29/2;
}

//void ping(const unsigned int SIG_pin){
//  pinMode(SIG_pin, OUTPUT);
//  digitalWrite(SIG_pin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(SIG_pin, HIGH);
//  delayMicroseconds(5);
//  digitalWrite(SIG_pin, LOW);
//  pinMode(SIG_pin, INPUT);
//  long lamo_bunyi = pulseIn(SIG_pin, HIGH);
//  jarak = lamo_bunyi/29/2;
//}

void baco_suhu(){
  for (int i = 2; i <= 7; i++){
    if(tpa.getPoint(i) > SV_suhu){posisi_api = didepan_api; break;}    
  }

  for (int j = 1; j <= 8; j++){
    p[j] = tpa.getPoint(j);     
  }

  tpa_averenge = (p[1] + p[2] + p[3] + p[4] + p[5]+ p[6]+ p[7] + p[8])/8.00;
}

void cek_boneka(){
  baco_jarak();
  baco_sharp();
  if(telusur == dinding_kanan){
        if(sharp > 0 && sharp <= 13){
          if(jarak_depan > 40){data_ada_boneka++;}
          else {data_ada_boneka = 0;}

          if(data_ada_boneka >= 3){
            if(kapalo_state == kapalo_1){kapalo_state = kapalo_2; data_ada_boneka = 0; kirim (geser_kanan_2); delay(500);} 
            else {kapalo_state = kapalo_1; data_ada_boneka = 0; kirim(geser_kanan_1); delay(500);}
            }
          }
        }
  else{if(sharp > 0 && sharp <= 13){
          if(jarak_depan > 40){data_ada_boneka++;}
          else {data_ada_boneka = 0;}

          if(data_ada_boneka >= 3){
            if(kapalo_state == kapalo_1){kapalo_state = kapalo_2; data_ada_boneka = 0; kirim (geser_kiri_2); delay(500);} 
            else {kapalo_state = kapalo_1; data_ada_boneka = 0; kirim(geser_kiri_1); delay(500);}
            }
        }
     }
  }

void baco_ruangan_masuk(){
  baco_kompas();
  baco_jarak();

  if(arah == kom_atas){
    if(jarak_depan < 45){state_ruangan_masuk = room_4; state_pintu_masuk = door_2;}
    else {state_ruangan_masuk = room_3;}
    }
  else if(arah == kom_kanan){
    state_ruangan_masuk = room_1;
    if((jarak_serdepki + jarak_serbelki) > (jarak_serdepka + jarak_serbelki)){state_pintu_masuk = door_1;}
    else{state_pintu_masuk = door_2;}
    }
  else if(arah == kom_bawah){
    if(jarak_depan < 45){state_ruangan_masuk = room_4; state_pintu_masuk = door_1;}
    else{state_ruangan_masuk = room_1; state_pintu_masuk = door_3;}
    }
  else if(arah == kom_kiri){
    state_ruangan_masuk = room_2;
    }
  }

  void baco_ruangan_keluar(){
  baco_kompas();
  baco_jarak();
  if(arah == kom_kanan){
    state_ruangan_keluar = room_2;
    }
  else if(arah == kom_atas){
    if(jarak_belakang < 45){state_ruangan_keluar = room_4; state_pintu_keluar = door_1;}
    else{state_ruangan_keluar = room_1; state_pintu_keluar = door_3;}
    }
  else if(arah == kom_kiri){
    state_ruangan_keluar = room_1;
    if((jarak_serdepki + jarak_serbelki) < (jarak_serdepka + jarak_serbelki)){state_pintu_keluar = door_1;}
    else{state_pintu_keluar = door_2;}
    }
  else if(arah == kom_bawah){
    if(jarak_belakang < 45){state_ruangan_keluar = room_4; state_pintu_keluar = door_2;}
    else {state_ruangan_keluar = room_3;}
    }          
  }

void kirim(const byte suruah){
  if(suruah == tagak)                     {logic_1 = 0; logic_2 = 0; logic_3 = 0; logic_4 = 0; logic_5 = 0;}
  else if(suruah == maju_1)               {logic_1 = 0; logic_2 = 0; logic_3 = 0; logic_4 = 0; logic_5 = 1;}
  else if(suruah == maju_2)               {logic_1 = 0; logic_2 = 0; logic_3 = 0; logic_4 = 1; logic_5 = 0;}
  else if(suruah == belok_kakida_1)       {logic_1 = 0; logic_2 = 0; logic_3 = 0; logic_4 = 1; logic_5 = 1;}
  else if(suruah == belok_kakida_2)       {logic_1 = 0; logic_2 = 0; logic_3 = 1; logic_4 = 0; logic_5 = 0;}
  else if(suruah == belok_kasuok_1)       {logic_1 = 0; logic_2 = 0; logic_3 = 1; logic_4 = 0; logic_5 = 1;}
  else if(suruah == belok_kasuok_2)       {logic_1 = 0; logic_2 = 0; logic_3 = 1; logic_4 = 1; logic_5 = 0;}
  else if(suruah == puta_CW)              {logic_1 = 0; logic_2 = 0; logic_3 = 1; logic_4 = 1; logic_5 = 1;}
  else if(suruah == puta_CCW)             {logic_1 = 0; logic_2 = 1; logic_3 = 0; logic_4 = 0; logic_5 = 0;}
  else if(suruah == mundur_1)             {logic_1 = 0; logic_2 = 1; logic_3 = 0; logic_4 = 0; logic_5 = 1;}
  else if(suruah == mundur_2)             {logic_1 = 0; logic_2 = 1; logic_3 = 0; logic_4 = 1; logic_5 = 0;}
  else if(suruah == puta_CW_slow)         {logic_1 = 0; logic_2 = 1; logic_3 = 0; logic_4 = 1; logic_5 = 1;}
  else if(suruah == puta_CCW_slow)        {logic_1 = 0; logic_2 = 1; logic_3 = 1; logic_4 = 0; logic_5 = 0;}
  else if(suruah == geser_kiri_1)         {logic_1 = 0; logic_2 = 1; logic_3 = 1; logic_4 = 0; logic_5 = 1;}
  else if(suruah == geser_kanan_1)        {logic_1 = 0; logic_2 = 1; logic_3 = 1; logic_4 = 1; logic_5 = 0;}
  else if(suruah == bukak)                {logic_1 = 0; logic_2 = 1; logic_3 = 1; logic_4 = 1; logic_5 = 1;}
  else if(suruah == tutuik)               {logic_1 = 1; logic_2 = 0; logic_3 = 0; logic_4 = 0; logic_5 = 0;}
  else if(suruah == geser_kiri_2)         {logic_1 = 0; logic_2 = 1; logic_3 = 1; logic_4 = 1; logic_5 = 0;}
  else if(suruah == geser_kanan_2)        {logic_1 = 0; logic_2 = 1; logic_3 = 1; logic_4 = 0; logic_5 = 1;}
  
  digitalWrite(2, logic_1);
  digitalWrite(3, logic_2);
  digitalWrite(4, logic_3);
  digitalWrite(5, logic_4);
  digitalWrite(6, logic_5);
  }

void get_menu(){
  _DEC = digitalRead(butt_1);
  _INC = digitalRead(butt_2);
  _ENT = digitalRead(butt_3);
  _CAN = digitalRead(butt_4);

if(layer_state == layer_1){
  if(_ENT == 1){while(_ENT == 1){_ENT = digitalRead(butt_3);}
    if(menu_1 == 0){status_lisa = masuk_ruangan;}
    else if(menu_1 == 1){layer_state = layer_2;}
    }
  else if(_INC == 1){while(_INC == 1){ _INC = digitalRead(butt_2);}
    menu_1 +=1; if(menu_1 > 1){menu_1 = 0;}
    }
  else if(_DEC == 1){while(_DEC == 1){_DEC = digitalRead(butt_1);}
    menu_1 -=1; if(menu_1 < 0){menu_1 = 1;}
    }
  }

else if(layer_state == layer_2){
  if(_ENT == 1){while(_ENT == 1){_ENT = digitalRead(butt_3);}
    if(menu_2 == 0){layer_state = layer_3_1;}
    else if(menu_2 == 1){layer_state = layer_3_2;}
    else if(menu_2 == 2){layer_state = layer_3_3;}
    else if(menu_2 == 3){layer_state = layer_3_4;}
    else if(menu_2 == 4){layer_state = layer_3_5;}
    else if(menu_2 == 5){layer_state = layer_3_6;}
    else if(menu_2 == 6){layer_state = layer_3_7;}
    else if(menu_2 == 7){layer_state = layer_3_8; lcd.clear();}
    }
  else if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_1;
    }
  else if(_INC == 1){while(_INC == 1){ _INC = digitalRead(butt_2);}
    menu_2 +=1; if(menu_2 > 7){menu_2 = 0;}
    }
  else if(_DEC == 1){while(_DEC == 1){_DEC = digitalRead(butt_1);}
    menu_2 -=1; if(menu_2 < 0){menu_2 = 7;}
    }
   } 

else if(layer_state == layer_3_1){
  if(_INC == 1){while(_INC == 1){ _INC = digitalRead(butt_2);}
    menu_3_1 +=1; if(menu_3_1 > 1){menu_3_1 = 0;}
    }
  else if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_2;
    }
  }

else if(layer_state == layer_3_2){
  if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_2;
    }  
  }

else if(layer_state == layer_3_3){
  if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_2;
      }
    }

else if(layer_state == layer_3_4){
   if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_2;
    }
  }

else if(layer_state == layer_3_5){
   if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_2;
    }
  }
  
else if(layer_state == layer_3_6){
   if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_2;
    }
  }
else if(layer_state == layer_3_7){
   if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_2;
    }
  }
else if(layer_state == layer_3_8){
   if(_CAN == 1){while(_CAN == 1){_CAN = digitalRead(butt_4);} 
    layer_state = layer_2;
    }
  }
}


void display_menu(){

if(layer_state == layer_1){
  lcd.setCursor(0,0); 
  lcd.print("AL-ANKABUT V 3.0");
  if(menu_1 == 0){
    lcd.setCursor(0,1);
    lcd.print("     Run Me     ");
    }
  else if(menu_1 == 1){
    lcd.setCursor(0,1);
    lcd.print("  Display Data  ");   
    }
  }

else if(layer_state == layer_2){ 
  lcd.setCursor(0,0);
  lcd.print("   PILIH DATA   ");
  if(menu_2 == 0){
    lcd.setCursor(0,1);
    lcd.print("Data: Ultasonik ");
    }
  else if(menu_2 == 1){
    lcd.setCursor(0,1);
    lcd.print("Data: UVTron    ");
    }
  else if(menu_2 == 2){
    lcd.setCursor(0,1);
    lcd.print("Data: Compass   ");
    }
  else if(menu_2 == 3){
    lcd.setCursor(0,1);
    lcd.print("Data: MIC       ");
    }
  else if(menu_2 == 4){
    lcd.setCursor(0,1);
    lcd.print("Data: Posisi Api");
    }
  else if(menu_2 == 5){
    lcd.setCursor(0,1);
    lcd.print("Data: Garis     ");
    }
  else if(menu_2 == 6){
    lcd.setCursor(0,1);
    lcd.print("Data: Sharp     ");
    }
  else if(menu_2 == 7){
    lcd.setCursor(0,1);
    lcd.print("Data: Ruangan   ");
    }
  }

else if(layer_state == layer_3_1){
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print(jarak_serdepki);
    lcd.setCursor(7,0);
    lcd.print(jarak_depan);
    lcd.setCursor(12,0);
    lcd.print(jarak_serdepka);
    lcd.setCursor(2,1);
    lcd.print(jarak_serbelki);
    lcd.setCursor(7,1);
    lcd.print(jarak_belakang);
    lcd.setCursor(12,1);
    lcd.print(jarak_serbelka);
  }

else if(layer_state == layer_3_2){
    lcd.setCursor(0, 0);
    lcd.print("  ADAKAH API?   ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(UV);
    lcd.setCursor(8, 1);
    if(UV == 0){lcd.print("ADA API");}
    else {lcd.print("AMAN..");}     
  }

else if(layer_state == layer_3_3){
    lcd.setCursor(0, 0);
    lcd.print("arah  =      ");
    lcd.setCursor(0, 1);
    lcd.print("Nilai =");    
    lcd.setCursor(7, 0);
    lcd.print("             ");
    lcd.setCursor(7, 1);
    lcd.print("             ");
    lcd.setCursor(9, 0);
    if(arah == kom_atas){lcd.print("ATAS");}
    else if(arah == kom_kanan){lcd.print("KANAN");}
    else if(arah == kom_bawah){lcd.print("BAWAH");}
    else if(arah == kom_kiri){lcd.print("KIRI");}
    else lcd.print("NONE");
    lcd.setCursor(9, 1);
    lcd.print(sudut_kompas);
    lcd.setCursor(13, 1);
    lcd.print(sudut_kompas_mentah);
  }
  
else if(layer_state == layer_3_4){
    lcd.setCursor(0, 0);
    lcd.print("SOUND ACTIVATION");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(6, 1);
    lcd.print(MIC);
  }
  
else if(layer_state == layer_3_5){
    lcd.setCursor(0, 0);
    lcd.print("  DIMANA API?   ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(tpa_averenge);
    for (int i = 1; i <= 8; i++){
    if(tpa.getPoint(i) > SV_suhu){lcd.setCursor(8, 1); lcd.print("DIDEPAN"); break;}
    else {lcd.setCursor(8, 1); lcd.print("MENCARI..");}     
    }
   }
else if(layer_state == layer_3_6){
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print(analogRead(A5));
    lcd.setCursor(7,0);
    lcd.print(analogRead(A6));
    lcd.setCursor(12,0);
    lcd.print(analogRead(A7));
    lcd.setCursor(0,1);
    lcd.print("  ");
    lcd.setCursor(2,1);
    lcd.print(line_1);
    lcd.setCursor(3,1);
    lcd.print("    ");
    lcd.setCursor(7,1);
    lcd.print(line_2);
    lcd.setCursor(8,1);
    lcd.print("    ");
    lcd.setCursor(12,1);
    lcd.print(line_3);
    lcd.setCursor(13,1);
    lcd.print("    ");
  }
else if(layer_state == layer_3_7){
    lcd.setCursor(8, 0);
    lcd.print("         ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("Sharp: ");
    lcd.setCursor(7, 0);
    lcd.print(sharp);    
  }
else if(layer_state == layer_3_8){
  if(state_ruangan_masuk == room_1){lcd.setCursor(0, 0);       lcd.print("Ruang: ROOM 1   ");}
  else if (state_ruangan_masuk == room_2){lcd.setCursor(0, 0); lcd.print("Ruang: ROOM 2   ");}
  else if (state_ruangan_masuk == room_3){lcd.setCursor(0, 0); lcd.print("Ruang: ROOM 3   ");}
  else if (state_ruangan_masuk == room_4){lcd.setCursor(0, 0); lcd.print("Ruang: ROOM 4   ");}  

  if(state_pintu_masuk == door_1){lcd.setCursor(0, 1);         lcd.print("Pintu: DOOR 1   ");}
  else if (state_pintu_masuk == door_2){lcd.setCursor(0, 1);   lcd.print("Pintu: DOOR 2   ");}
  else if (state_pintu_masuk == door_3){lcd.setCursor(0, 1);   lcd.print("Pintu: DOOR 3   ");}
  }
}

void display_indikator(){
digitalWrite(SA_OK, SA_OK_state);
digitalWrite(tabaka, tabaka_state);
}

void tembak_lisa(){
    kirim(bukak);
    delay(4500);
    kirim(tagak);
  }

void tutuik_lisa(){
    if(digitalRead(butt_5) == 1){
      kirim(tutuik);
      }
    else{kirim(tagak);}
  }
