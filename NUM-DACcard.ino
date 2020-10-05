//This is some code I quickly put  to test two  parallel DAC813 whis two 74h273 buffer in digital inputs.
// this is card  EM08P970695 from NUM driver MDLU1034Q00B
// used Arduino Mega 2560
// Author Gennady Nesterenko
// Date   10 2020

//#include<avr/io.h>





void setup() {

  // put your setup code here, to run once:
  DDRA=0xFF; // Port A Output
  DDRC=0xFF; // Port C Output
  DDRB=0xFF; // Port B Output
  DDRL=0xFF; // Port L Output
  DDRD=0xFF; // Port D Output
  DDRG=0xFF; // Port G Output
 
  PORTA = 0;
  PORTB = 0;
  PORTC = 0;
  PORTL = 0;
  PORTD = 0;
  PORTG = 0;
 
  Serial.begin(115200);
 }

  void Loop1024 ()
   {
    static int addr;
    static int clrw;
    static int  TH = 0;
  for(addr=0;addr<1024;addr++)  //first 8 bits 
 {   
  
clrw= 1;                        // clock signal
 PORTC= uint8_t(clrw);
 clrw= 0;
  delay(TH);
 PORTC= uint8_t(clrw);
 
 PORTA= uint8_t(addr);

  Serial.print(addr);
Serial.print("\n\r");
 }

  }


void loop() {
 static int addh;
for(addh=0;addh<15;addh++)          //last 4 bits
 {
 PORTB= uint8_t(addh);
  Loop1024(); 
 }
  
  } 
  
