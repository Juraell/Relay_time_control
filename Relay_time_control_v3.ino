/* Let's make it graphic, picture of tree, chain and gear (represents settings) - DONE
 * In settings: Set time, set display fade delay - DONE
 * For every circuit make timer and sleep function - DONE
 * Create timer functions also for turning sockets off
 * Create save/load timers to/from EEPROM memory function
 */
const unsigned char bitmapSetting [] PROGMEM = {
   0xf0, 0x01, 0x00, 0x7c, 0x00, 0xf8, 0x03, 0x00, 0xfe, 0x00, 0x7c, 0x07,
   0x00, 0xff, 0x01, 0x3e, 0x0e, 0x80, 0xff, 0x00, 0x7e, 0x1c, 0x80, 0x7f,
   0x00, 0xee, 0x38, 0xc0, 0x3f, 0x00, 0xc6, 0x71, 0xc0, 0x1f, 0x00, 0x8e,
   0xe3, 0xc0, 0x0f, 0x20, 0x1c, 0xc7, 0xc1, 0x07, 0x70, 0x38, 0x8e, 0xc3,
   0x0f, 0xf8, 0x70, 0x1c, 0xc7, 0x1f, 0xfc, 0xe0, 0x38, 0xe2, 0x3f, 0xfe,
   0xc0, 0x71, 0xf0, 0x7f, 0xff, 0x80, 0xe3, 0xf8, 0xff, 0xff, 0x00, 0x47,
   0xfc, 0xff, 0x7f, 0x00, 0x0e, 0xfe, 0xff, 0x3f, 0x00, 0x1c, 0xff, 0xff,
   0x1f, 0x00, 0x88, 0xff, 0xff, 0x07, 0x00, 0xc0, 0xff, 0x1f, 0x00, 0x00,
   0xe0, 0xff, 0x0f, 0x00, 0x00, 0xf0, 0xff, 0x07, 0x00, 0x00, 0xf8, 0xff,
   0x03, 0x00, 0x00, 0xfc, 0xff, 0x05, 0x00, 0x00, 0xfe, 0xff, 0x0e, 0x00,
   0x00, 0xff, 0x7f, 0x1f, 0x00, 0x80, 0xff, 0x3f, 0x3e, 0x00, 0xc0, 0xff,
   0x1f, 0x7c, 0x00, 0xe0, 0xff, 0x0f, 0xf8, 0x00, 0xf0, 0xff, 0x07, 0xf0,
   0x01, 0xf8, 0xff, 0x03, 0xe0, 0x03, 0xfc, 0xff, 0x01, 0xc0, 0x0f, 0x1e,
   0xff, 0x00, 0x80, 0x1f, 0x0e, 0x7e, 0x00, 0x00, 0x3f, 0x0e, 0x3e, 0x00,
   0x00, 0x7f, 0x0e, 0x1e, 0x00, 0x00, 0xfe, 0x1c, 0x0f, 0x00, 0x00, 0xfc,
   0xf8, 0x07, 0x00, 0x00, 0xf8, 0xf0, 0x03, 0x00, 0x00, 0xf0, 0xe0, 0x01,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const unsigned char bitmapSocket1 [] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0x70,
   0x00, 0x0e, 0x00, 0x00, 0x0c, 0x00, 0x30, 0x00, 0x00, 0x02, 0x00, 0x40,
   0x00, 0x00, 0x01, 0x00, 0x80, 0x00, 0x80, 0x00, 0x3c, 0x00, 0x01, 0x40,
   0x00, 0x7e, 0x00, 0x02, 0x20, 0x00, 0x7e, 0x00, 0x04, 0x10, 0x00, 0x7e,
   0x00, 0x08, 0x08, 0x00, 0x7e, 0x00, 0x10, 0x08, 0x00, 0x3c, 0x00, 0x10,
   0x04, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00,
   0x00, 0x00, 0x20, 0x02, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00,
   0x40, 0x02, 0x1e, 0x00, 0x78, 0x40, 0x02, 0x3f, 0x00, 0xfc, 0x40, 0x02,
   0x3f, 0x00, 0xfc, 0x40, 0x02, 0x3f, 0x00, 0xfc, 0x40, 0x02, 0x3f, 0x00,
   0xfc, 0x40, 0x02, 0x1e, 0x00, 0x78, 0x40, 0x02, 0x00, 0x00, 0x00, 0x40,
   0x02, 0x00, 0x00, 0x00, 0x40, 0x04, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00,
   0x10, 0x00, 0x20, 0x04, 0x00, 0x18, 0x00, 0x20, 0x08, 0x00, 0x14, 0x00,
   0x10, 0x08, 0x00, 0x10, 0x00, 0x10, 0x10, 0x00, 0x10, 0x00, 0x08, 0x20,
   0x00, 0x10, 0x00, 0x04, 0x40, 0x00, 0x10, 0x00, 0x02, 0x80, 0x00, 0x10,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x40, 0x00,
   0x00, 0x0c, 0x00, 0x30, 0x00, 0x00, 0x70, 0x00, 0x0e, 0x00, 0x00, 0x80,
   0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const unsigned char bitmapSocket2 [] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0x70,
   0x00, 0x0e, 0x00, 0x00, 0x0c, 0x00, 0x30, 0x00, 0x00, 0x02, 0x00, 0x40,
   0x00, 0x00, 0x01, 0x00, 0x80, 0x00, 0x80, 0x00, 0x3c, 0x00, 0x01, 0x40,
   0x00, 0x7e, 0x00, 0x02, 0x20, 0x00, 0x7e, 0x00, 0x04, 0x10, 0x00, 0x7e,
   0x00, 0x08, 0x08, 0x00, 0x7e, 0x00, 0x10, 0x08, 0x00, 0x3c, 0x00, 0x10,
   0x04, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00,
   0x00, 0x00, 0x20, 0x02, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00,
   0x40, 0x02, 0x1e, 0x00, 0x78, 0x40, 0x02, 0x3f, 0x00, 0xfc, 0x40, 0x02,
   0x3f, 0x00, 0xfc, 0x40, 0x02, 0x3f, 0x00, 0xfc, 0x40, 0x02, 0x3f, 0x00,
   0xfc, 0x40, 0x02, 0x1e, 0x00, 0x78, 0x40, 0x02, 0x00, 0x00, 0x00, 0x40,
   0x02, 0x00, 0x00, 0x00, 0x40, 0x04, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00,
   0x38, 0x00, 0x20, 0x04, 0x00, 0x44, 0x00, 0x20, 0x08, 0x00, 0x40, 0x00,
   0x10, 0x08, 0x00, 0x40, 0x00, 0x10, 0x10, 0x00, 0x20, 0x00, 0x08, 0x20,
   0x00, 0x10, 0x00, 0x04, 0x40, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x7c,
   0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x40, 0x00,
   0x00, 0x0c, 0x00, 0x30, 0x00, 0x00, 0x70, 0x00, 0x0e, 0x00, 0x00, 0x80,
   0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#include <EEPROM.h>
#include <Encoder.h>
#include <U8glib.h>
#include <DS3232RTC.h>
#include <Time.h>
#include <TimeLib.h>
#include <TimeAlarms.h>
#include <Wire.h>

Encoder encoder(2,3);
U8GLIB_SH1106_128X64 u8g(8, 9, 12, 11, 10); //D0=8, D1=9, RST=10, DC=11, CS=12

#define BUTTONPIN 4
#define SWITCHPIN 7
#define RELAYPIN1 5
#define RELAYPIN2 6
#define LEDPIN 13

#define TIMELENGTH 9
#define DATELENGTH 13
#define DEFAULT_TIME 1451638800 // 01/01/2016 @ 9:00am (GMT+1) //1450947600 // 12/24/2015 @ 9:00am (GMT+1)

#define NONE 0
#define NEXT 1
#define BACK 2
#define SELECT 3
#define HOME 4

/*---------------------------------VARIABLES----------------------------------*/
int oledWidth;
int oledHeight;
int fontHeight;
boolean redrawRequired = true;
unsigned long lastRedrawMillis = 0;
unsigned long lastAction = 0;
unsigned long lastTimeSync = 0;
boolean awake = true;
long timeout = 20000;
long newTimeout;

boolean status = true; //0 = OFF, 1 = ON

byte relay[2] = {RELAYPIN1, RELAYPIN2};
boolean state[2] = {false, false};    //State of relays

long pos = 0;

byte key = NONE;
byte displaySetting = 0; //Go straight to time setting (1) - NOT ANYMORE (timeSync from 3231)
boolean submenu = false;
byte menuID = 0;
byte currentSelection = 0;
char* title;   //Menu title
byte itemsCount; //Number of used items
char* menuItem[4]; //Item1, item2, item3, item4
byte recMenuPosX[4];    //Rectangle positioning for main menu
byte recMenuPosY = 20 - 1;
byte recMenuWidth[4];

byte recTimePosX[7];    //Rectagle positioning for time setting
byte recTimePosY[7];
byte recTimeWidth[7];
boolean settingInitNeeded = true;
unsigned long settingTime;
int setMinute, setHour, setDay, setMonth, setYear;

boolean sleep[3] = {false, false, false};   //Socket 1, Socket 2, Sockets 1&2
int sleepMinutes;
boolean timer[6] = {false, false, false, false, false, false};   //Socket 1, Socket 2, Sockets 1&2
boolean timerRep[6] = {false, false, false, false, false, false};    //Repeat of timer
byte ofset = 0;	//Ofset for alarm ID

byte recTimerPosX[4];
byte recTimerPosY[4];
byte recTimerWidth[4];
char setTimerChar[6];

char timeChar[TIMELENGTH];
char dateChar[DATELENGTH];
char setTimeChar[TIMELENGTH];
char setDateChar[DATELENGTH];

typedef struct timerStruct { boolean state; int minute; int hour; boolean repeat; };

boolean buttonHold;
/*---------------------------------DEBOUNCE WITH BUTTON HOLD FUNCTION----------------------------------*/
boolean debounce (int pin) {
	static byte last = 1;
  static unsigned long trigger;
  boolean switchState = false;
  buttonHold = false;
  if (last != digitalRead(pin)) {
    if (digitalRead(pin)==LOW) {
      trigger = millis();
    }
    if (digitalRead(pin)==HIGH) {
      lastAction = millis();
      if (millis()-trigger > 500) {
        buttonHold = true;
      } else switchState = true;
    }
  }
  last = digitalRead(pin);
  return switchState;
}
/*---------------------------------SETUP----------------------------------*/
void setup() {
  pinMode(BUTTONPIN, INPUT_PULLUP);
  pinMode(SWITCHPIN, INPUT);
  
  timerStruct ts;
  
  Serial.begin(57600);
  Serial.println("--------------RELAY TIME CONTROL--------------");
  
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus() != timeSet){
    Serial.println("Unable to sync with the RTC");
    setTime(DEFAULT_TIME);
	settingTime = DEFAULT_TIME;
  }
  else Serial.println("RTC has set the system time");

  oledHeight = u8g.getHeight();
  oledWidth = u8g.getWidth();
  Serial.print(oledWidth); Serial.println('x' + oledHeight);
  u8g_prepare();
  menuPrepare(menuID);

  Alarm.timerOnce(20, SleepMode0); Alarm.disable(0);
  Alarm.timerOnce(25, SleepMode1); Alarm.disable(1);
  Alarm.timerOnce(30, SleepMode2); Alarm.disable(2);
  Alarm.alarmOnce(9, 0, 5, TimerON0); Alarm.disable(3);
  Alarm.alarmOnce(23, 30, 10, TimerON1); Alarm.disable(4);
  Alarm.alarmOnce(23, 30 ,15, TimerON2); Alarm.disable(5);
  Alarm.alarmOnce(12, 0, 0, TimerOFF0); Alarm.disable(6);
  Alarm.alarmOnce(12, 0, 0, TimerOFF1); Alarm.disable(7);
  Alarm.alarmOnce(12, 0, 0, TimerOFF2); Alarm.disable(8);

  recMenuPosX[0] = 1;
  recMenuPosX[1] = 43;
  recMenuPosX[2] = 1;
  recMenuPosX[3] = 85;
  for (int i = 0; i <= 3; i++) recMenuWidth[i] = 40+2;
  recMenuWidth[2] = 2*40+2+2;
  recMenuWidth[3] += 1;

  recTimePosX[0] = (oledWidth-u8g.getStrWidth("00.00.0000"))/2+u8g.getStrWidth("00.00.")-2;
  recTimePosX[1] = recTimePosX[0]-u8g.getStrWidth("00.");
  recTimePosX[2] = recTimePosX[1]-u8g.getStrWidth("00.");
  recTimePosX[3] = (oledWidth-u8g.getStrWidth("00:00:00"))/2+u8g.getStrWidth("00:00:")-2;
  recTimePosX[4] = recTimePosX[3]-u8g.getStrWidth("00:");
  recTimePosX[5] = recTimePosX[4]-u8g.getStrWidth("00:");
  recTimePosX[6] = 90-2;
  for (int i = 0; i < 3; i++) recTimePosY[i] = fontHeight*2-1;
  for (int i = 3; i < 6; i++) recTimePosY[i] = fontHeight*3-1;
  recTimePosY[6] = fontHeight*4-1;
  recTimeWidth[0] = u8g.getStrWidth("0000")+3;
  for (int i = 1; i < 6; i++) recTimeWidth[i] = u8g.getStrWidth("00")+3;
  recTimeWidth[6] = u8g.getStrWidth("DONE")+3;

  recTimerPosX[0] = 40 + u8g.getStrWidth("Repeat: ")-2;   //Repeat
  recTimerPosX[1] = (oledWidth-u8g.getStrWidth("00:00"))/2-2;   //Hour
  recTimerPosX[2] = recTimerPosX[1]+u8g.getStrWidth("00:");   //Minute
  recTimerPosX[3] = 90-2;   //DONE
  recTimerPosY[0] = fontHeight*2;
  recTimerPosY[1] = fontHeight*3;
  recTimerPosY[2] = recTimerPosY[1];
  recTimerPosY[3] = fontHeight*4;
  recTimerWidth[0] = u8g.getStrWidth("OFF")+3;
  recTimerWidth[1] = u8g.getStrWidth("00")+3;
  recTimerWidth[2] = recTimerWidth[1];
  recTimerWidth[3] = u8g.getStrWidth("DONE")+3;
  
  
  delay(200);
  lastAction = millis();
  Serial.println("Setup complete!");
}

/*---------------------------------MAIN LOOP----------------------------------*/
void loop() {
	if (status != digitalRead(SWITCHPIN)) lastAction = millis();
	status = digitalRead(SWITCHPIN);
	key = NONE;
	if (status == 1) {
		digitalWrite(LEDPIN, HIGH);
		//if (pos != encoder.read()) awake = true;
		if (debounce(BUTTONPIN) && awake) key = SELECT;
		if (buttonHold && awake) key = HOME;
		if (pos < encoder.read() / 2) key = NEXT;
		else if (pos > encoder.read() / 2) key = BACK;
		pos = encoder.read() / 2;
	}
	else digitalWrite(LEDPIN, LOW);
  
  if (key != NONE) {
	  if (millis() - lastAction < timeout) {
		  lastAction = millis();
		  Serial.print("KEY: "); Serial.println(key);
		  updateScreen();
	  }
	  else {
		  key = NONE;
		  lastAction = millis();
	  }
  }
  if (millis() - lastTimeSync > 30000) {
    Serial.print("Syncronising time with RTC...");
    setSyncProvider(RTC.get);
    lastTimeSync = millis();
    Serial.println("DONE");
  }
  
  if ((millis() - lastAction < timeout) || (displaySetting == 1)) awake = true; else awake = false;
  
  if (awake) { //Timeout for display
    u8g.sleepOff();
    if (status == 1) { //Check for overdrive
      if (millis() - lastRedrawMillis >= 1000) { //Forced redraw roughly after a second
        redrawRequired = true;
      }
      if (redrawRequired) {
        u8g.firstPage();
        //Serial.println("REDRAWING...");
        do {
          draw();
        } while(u8g.nextPage());
        redrawRequired = false;
        lastRedrawMillis = millis();
      }
    } else {
        //Serial.println("Manual OVERRIDE!");
        state[0] = false;
        state[1] = false;
        displaySetting = 0;
        currentSelection = 0;
        menuID = 0;
        menuPrepare(menuID);
        u8g.firstPage();
        do {
          drawOverride();
        } while(u8g.nextPage());
    }
  } else {
    //Serial.println("TIMEOUT! Shuting down the display, loading main menu... DONE");
    displaySetting = 0;
    currentSelection = 0;
    menuID = 0;
    menuPrepare(menuID);
    u8g.sleepOn();
  }
  
  for (int i = 0; i <= 1; i++) {
    if (state[i]) analogWrite(relay[i], 0); else analogWrite(relay[i], 255);
  }
  Alarm.delay(1);
}

/*---------------------------------DRAW----------------------------------*/
void draw() {
  u8g_prepare();
  getNowStr();
  u8g.drawStr(oledWidth-u8g.getStrWidth(timeChar), 0, timeChar);
  u8g.drawLine(0, fontHeight-1, oledWidth, fontHeight-1);
  u8g.drawStr(1, 0, title);   //Draw title

  switch (displaySetting) {
    case 0:   //MENU
      for (int i = 0; i < 4; i++) {
        if (menuItem[i] != "") {
          u8g.setDefaultForegroundColor();
          if (i == currentSelection) {
            u8g.drawBox(0, (i+1)*fontHeight, oledWidth, fontHeight);
            u8g.setDefaultBackgroundColor();
          }
          u8g.drawStr((oledWidth-u8g.getStrWidth(menuItem[i]))/2, (i+1)*fontHeight, menuItem[i]);
        }
      }
      if (menuID == 0) {
        u8g.drawXBMP(2, 20, 40, 40, bitmapSocket1);
        u8g.drawXBMP(44, 20, 40, 40, bitmapSocket2);
        u8g.drawXBMP(86, 20, 40, 40, bitmapSetting);
        u8g.drawFrame(recMenuPosX[currentSelection], recMenuPosY, recMenuWidth[currentSelection], recMenuWidth[0]);
        char* tempStr[2];
        for (int i = 0; i <= 1; i++) {if (state[i]) tempStr[i] = "ON"; else tempStr[i] = "OFF";}
        u8g.drawStr(2, 60-fontHeight, tempStr[0]);
        u8g.drawStr(44, 60-fontHeight, tempStr[1]);
      }
      break;
      
    case 1:   //TIMESET
      if (settingInitNeeded) {
        settingTime = now();
        settingInit(settingTime);
        settingInitNeeded = false;
      }
      getSettingTimeStr();
      u8g.drawStr((oledWidth-u8g.getStrWidth(setDateChar))/2, fontHeight*2, setDateChar);
      u8g.drawStr((oledWidth-u8g.getStrWidth(setTimeChar))/2, fontHeight*3, setTimeChar);
      u8g.drawStr(90, fontHeight*4, "DONE");
      u8g.drawFrame(recTimePosX[currentSelection], recTimePosY[currentSelection], recTimeWidth[currentSelection], fontHeight+1);
      break;
      
    case 2:   //SLEEP
      if (sleep[menuID-1] == true) {
        u8g.drawStr((oledWidth-u8g.getStrWidth("Currently ACTIVE"))/2, fontHeight*2, "Currently ACTIVE");
        u8g.drawStr((oledWidth-u8g.getStrWidth("Press btn to turn OFF"))/2, fontHeight*3, "Press btn to turn OFF");
      } else {
        String tempStr = (String)sleepMinutes;
        char tempChar[tempStr.length()+1];
        tempStr.toCharArray(tempChar, tempStr.length()+1);
        u8g.drawStr((oledWidth-u8g.getStrWidth(tempChar))/2, fontHeight*2, tempChar);
        u8g.drawStr((oledWidth-u8g.getStrWidth("minutes to turn OFF"))/2, fontHeight*3, "minutes to turn OFF");
      }
      break;
      
    case 3:   //TIMER
      if (settingInitNeeded) {
		  settingTime = now() + 60;
		  settingInit(settingTime);
		  settingInitNeeded = false;
      }
      if (timer[menuID - 1 + ofset]) {
        u8g.drawStr((oledWidth-u8g.getStrWidth("Currently ACTIVE"))/2, fontHeight*2, "Currently ACTIVE");
        u8g.drawStr((oledWidth-u8g.getStrWidth("Press btn to turn OFF"))/2, fontHeight*3, "Press btn to turn OFF");
      } else {
        getTimerStr();
        u8g.drawStr(40, fontHeight*2, "Repeat:");
        if (timerRep[menuID - 1 + ofset]) u8g.drawStr(recTimerPosX[0]+2, fontHeight*2, "ON");
        else u8g.drawStr(recTimerPosX[0]+2, fontHeight*2, "OFF");
        u8g.drawStr((oledWidth-u8g.getStrWidth(setTimerChar))/2, fontHeight*3, setTimerChar);
        u8g.drawStr(90, fontHeight*4, "DONE");
        u8g.drawFrame(recTimerPosX[currentSelection], recTimerPosY[currentSelection], recTimerWidth[currentSelection], fontHeight+1);
      }
      break;
      
    case 4: //DISPLAY DELAY
      String tempStr = (String)(newTimeout/1000);
      char tempChar[tempStr.length()+1];
      tempStr.toCharArray(tempChar, tempStr.length()+1);
      u8g.drawStr((oledWidth-u8g.getStrWidth(tempChar))/2, fontHeight*2, tempChar);
      u8g.drawStr((oledWidth-u8g.getStrWidth("seconds"))/2, fontHeight*3, "seconds");
      break;
  }
}

/*---------------------------------DRAW OVERRIDE----------------------------------*/
void drawOverride() {
  u8g_prepare();
  int namePosX = (oledWidth-u8g.getStrWidth("MANUAL OFF"))/2;
  u8g.drawStr(namePosX, fontHeight*2, "MANUAL OFF");
}

/*---------------------------------PREPARATION----------------------------------*/
void u8g_prepare() {
/*  if (displaySetting == 1) u8g.setFont(u8g_font_8x13B);
  else */
  u8g.setFont(u8g_font_profont12);//lucasfont_alternater);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
  fontHeight = u8g.getFontAscent()-u8g.getFontDescent()+1;
}

/*---------------------------------MENU PREPARATION----------------------------------*/
void menuPrepare(int ID) {
  switch (ID) {
    case 0:
      title = "Main menu";   //Title
      itemsCount = 4;
      menuItem[0] = "";   //Item 1
      menuItem[1] = "";   //Item 2
	  menuItem[2] = "";   //Item 3
	  menuItem[3] = "";   //Item 4
	  break;
    case 1:
      title = "Socket 1";   //Title
      itemsCount = 4;
      if (state[0]) menuItem[0] = "Turn OFF"; else menuItem[0] = "Turn ON";   //Item 1
      menuItem[1] = "Sleep";   //Item 2
      menuItem[2] = "Turn on at..";   //Item 3
	  menuItem[3] = "Turn off at..";   //Item 4
	  break;
    case 2:
      title = "Socket 2";   //Title
      itemsCount = 4;
      if (state[1]) menuItem[0] = "Turn OFF"; else menuItem[0] = "Turn ON";   //Item 1
      menuItem[1] = "Sleep";   //Item 2
	  menuItem[2] = "Turn on at..";   //Item 3
	  menuItem[3] = "Turn off at..";   //Item 4
	  break;
    case 3:
      title = "Socket 1&2";   //Title
      itemsCount = 4;
      if (state[0] || state[1]) menuItem[0] = "Turn both OFF"; else menuItem[0] = "Turn both ON";   //Item 1
      menuItem[1] = "Sleep";   //Item 2
	  menuItem[2] = "Turn on at..";   //Item 3
	  menuItem[3] = "Turn off at..";   //Item 4
	  break;
    case 4:
      title = "Settings";   //Title
      itemsCount = 2;
      menuItem[0] = "Set time";   //Item 1
      menuItem[1] = "Set display timeout";   //Item 2
      menuItem[2] = "";   //Item 3
	  menuItem[3] = "";   //Item 4
	  break;
  }
}

/*---------------------------------UPDATE SCREEN----------------------------------*/
void updateScreen(void) {
  //if (key == NONE) {redrawRequired = false; return;}
  redrawRequired = true;
  switch (displaySetting) {
    case 0:   //MENU
      switch (key) {
        case NEXT:
          if (currentSelection == itemsCount-1) currentSelection = 0;
          else currentSelection++;
          break;
        case BACK:
          if (currentSelection == 0) currentSelection = itemsCount-1;
          else currentSelection--;
          break;
        case SELECT:
          if (!submenu) {
            menuID = currentSelection+1;
            menuPrepare(menuID);
            currentSelection = 0;
          } else {
            switch (currentSelection) {
              case 0:	//Turn ON/OFF or timeset
                if (menuID == 1 || menuID == 2) {
                  if (state[menuID-1]) {
                    state[menuID-1] = false;
                    menuItem[0] = "Turn ON";
                  } else {
                    state[menuID-1] = true;
                    menuItem[0] = "Turn OFF";
                  }
                }
                if (menuID == 3) {
                  if (state[0] || state[1]) {
                    state[0] = false; state[1] = false;
                    menuItem[0] = "Turn both ON";
                  } else {
                    state[0] = true; state[1] = true;
                    menuItem[0] = "Turn both OFF";
                  }
                }
                if (menuID == 4) {
                  displaySetting = 1;
                  currentSelection = 0;
                  menuID = 0;
                  settingInitNeeded = true;
                  title = "Set time";
                }
                break;
              case 1:	//Sleep or delay settings
                if (0 <= menuID < 4) {
                  displaySetting = 2;
                  currentSelection = 0;
                  sleepMinutes = 5;
                  title = "Sleep";
                }
                if (menuID == 4) {  //To display delay setting
                  displaySetting = 4;
                  newTimeout = timeout;
                  title = "Disp. delay";
                }
                break;
			  case 2:	//Timer ON
				  if (0 <= menuID < 4) {
					  displaySetting = 3;
					  ofset = 0;
					  currentSelection = 0;
					  settingInitNeeded = true;
					  title = "Timer";
				  }
				  break;
			  case 3:	//Timer OFF
				  if (0 <= menuID < 4) {
					  displaySetting = 3;
					  ofset = 3;
					  currentSelection = 0;
					  settingInitNeeded = true;
					  title = "Timer";
				  }
				  break;
			}
          }
          break;
        case HOME:
          currentSelection = 0;
          displaySetting = 0;
          menuID = 0;
          menuPrepare(menuID);
          break;
      }
      break;
      
    case 1:   //TIMESET
      switch (key) {
        case NEXT:
          switch (currentSelection) {
            case 0: setYear++; break;
            case 1: if (setMonth == 12) setMonth = 1; else setMonth++; break;
            case 2: if (setDay == 31) setDay = 1; else setDay++; break;
            case 3: setTime(now()+1); break;
            case 4: if (setMinute == 59) setMinute = 0; else setMinute++; break;
            case 5: if (setHour == 23) setHour = 0; else setHour++; break;
            case 6: currentSelection = 0; break;
          }
          break;
        case BACK:
          switch (currentSelection) {
            case 0: setYear--; break;
            case 1: if (setMonth == 1) setMonth = 12; else setMonth--; break;
            case 2: if (setDay == 1) setDay = 31; else setDay--; break;
            case 3: setTime(now()-1); break;
            case 4: if (setMinute == 0) setMinute = 59; else setMinute--; break;
            case 5: if (setHour == 0) setHour = 23; else setHour--; break;
            case 6: currentSelection = 5; break;
          }
          break;
        case SELECT:
          if (currentSelection == 6) {
            setTime(setHour, setMinute, second(), setDay, setMonth, setYear);
            RTC.set(now());     //Write set time to RTC module
            displaySetting = 0;
            currentSelection = 0;
            menuID = 0;
            menuPrepare(menuID);
          } else currentSelection++;
          break;
        case HOME:
          if (currentSelection == 0) currentSelection = 6;
          else currentSelection--;
          break;
      }
      break;
      
    case 2: //SLEEP
      switch (key) {
        case NEXT:
          if (sleepMinutes < 30) sleepMinutes += 5;
          else if (sleepMinutes < 60) sleepMinutes += 15;
          else sleepMinutes += 30;
          break;
        case BACK:
          if (sleepMinutes > 60) sleepMinutes -= 30;
          else if (sleepMinutes > 30) sleepMinutes -= 15;
          else if (sleepMinutes > 5) sleepMinutes -= 5;
          break;
        case SELECT:
          if (sleep[menuID-1]) {
            Alarm.disable(menuID-1);
            sleep[menuID-1] = false;
          }
          else {
            SetSleep(menuID-1, sleepMinutes*60);
            sleep[menuID-1] = true;
          }
        case HOME:
          displaySetting = 0;
          currentSelection = 0;
          menuID = 0;
          menuPrepare(menuID);
          break;
      }
      break;
      
    case 3: //TIMER
      switch (key) {
        case NEXT:
          switch (currentSelection) {
            case 0: 
				timerRep[menuID - 1 + ofset] = !timerRep[menuID - 1 + ofset]; break;
            case 1:
              if (setHour == 23) setHour = 0;
              else setHour++;
              break;
            case 2:
				if (setMinute == 59) {
					setMinute = 0;
					if (setHour == 23) setHour = 0;
					else setHour++;
				}
              else setMinute++;
              break;
            case 3: currentSelection = 0;
          }
          break;
        case BACK:
          switch (currentSelection) {
			case 0: timerRep[menuID - 1 + ofset] = !timerRep[menuID - 1 + ofset]; break;
            case 1:
              if (setHour == 0) setHour = 23;
              else setHour--;
              break;
            case 2:
				if (setMinute == 0) {
					setMinute = 59;
					if (setHour == 0) setHour = 23;
					else setHour--;
				}
              else setMinute--;
              break;
            case 3: currentSelection = 2;
          }
          break;
        case SELECT:
          if (timer[menuID - 1 + ofset]) {	//Is timer currently on? If so turn it off.
			Alarm.disable(menuID - 1 + 3 + ofset);
			timer[menuID - 1 + ofset] = false;
          } else {
            switch (currentSelection) {
              case 0: case 1: case 2:
                currentSelection++;
                break;
              case 3:
				  if(ofset == 0) SetTimer(true, menuID - 1, setHour, setMinute);
				  else SetTimer(false, menuID - 1, setHour, setMinute);
				  timer[menuID - 1 + ofset] = true;
                  displaySetting = 0;
                  currentSelection = 0;
                  menuID = 0;
                  menuPrepare(menuID);
                break;
            }
          }
          break;
        case HOME:
          displaySetting = 0;
          currentSelection = 0;
          menuID = 0;
          menuPrepare(menuID);
          break;
      }
      break;
      
    case 4: //DISPLAY DELAY
      switch (key) {
        case NEXT: newTimeout += 5000; break;
        case BACK: if (newTimeout > 5000) newTimeout -= 5000; break;
        case SELECT:
          timeout = newTimeout;
        case HOME:
          displaySetting = 0;
          currentSelection = 0;
          menuID = 0;
          menuPrepare(menuID);
          break;
      }
      break;
  }
  if (menuID != 0) submenu = true; else submenu = false;
}

/*---------------------------------SLEEP AND TIMER FUNCTIONS----------------------------------*/
void SetSleep(int relayID, int seconds) {   //ID 0 -> Socket 1; ID 1 -> Socket 2; ID 2 -> Socket 1&2
  byte alarmID;
  if (relayID == 0) alarmID = 0; else if (relayID == 1) alarmID = 1; else alarmID = 2;
  if (Alarm.isAllocated(alarmID)) Alarm.free(alarmID);
  if (alarmID == 0) Alarm.timerRepeat(seconds, SleepMode0);
  else if (alarmID == 1) Alarm.timerRepeat(seconds, SleepMode1);
  else Alarm.timerRepeat(seconds, SleepMode2);
}

void SetTimer(boolean turnOn,int relayID, int H, int M) {   //ID 0 -> Socket 1; ID 1 -> Socket 2; ID 2 -> Socket 1&2
	byte alarmID;
	if (relayID == 0) alarmID = 3; else if (relayID == 1) alarmID = 4; else alarmID = 5;
	if (turnOn == false) alarmID += 3;
	if (Alarm.isAllocated(alarmID)) Alarm.free(alarmID);
	if (alarmID == 3) Alarm.alarmRepeat(H, M, 0, TimerON0);
	if (alarmID == 4) Alarm.alarmRepeat(H, M, 0, TimerON1);
	if (alarmID == 5) Alarm.alarmRepeat(H, M, 0, TimerON2);
	if (alarmID == 6) Alarm.alarmRepeat(H, M, 0, TimerOFF0);
	if (alarmID == 7) Alarm.alarmRepeat(H, M, 0, TimerOFF1);
	if (alarmID == 8) Alarm.alarmRepeat(H, M, 0, TimerOFF2);
}

void SleepMode0() {
	Serial.println("Sleep mode 0 triggered.");
	state[0] = false;
	sleep[0] = false;
	Alarm.disable(0);
}
void SleepMode1() {
	Serial.println("Sleep mode 1 triggered.");
	state[1] = false;
	sleep[1] = false;
	Alarm.disable(1);
}
void SleepMode2() {
	Serial.println("Sleep mode 2 triggered.");
	state[0] = false;
	state[1] = false;
	sleep[2] = false;
	Alarm.disable(2);
}

void TimerON0() {
	Serial.println("Timer ON 0 triggered.");
	if (status == 1) {
		state[0] = true;
	}
	if (timerRep[0] == false) {
		timer[0] = false;
		Alarm.disable(3);
	}
}
void TimerON1() {
	Serial.println("Timer ON 1 triggered.");
	if (status == 1) {
		state[1] = true;
	}
	if (timerRep[1] == false) {
		timer[1] = false;
		Alarm.disable(4);
	}
}
void TimerON2() {
	Serial.println("Timer ON 2 triggered.");
	if (status == 1) {
		state[0] = true;
		state[1] = true;
	}
	if (timerRep[2] == false) {
		timer[2] = false;
		Alarm.disable(5);
	}
}

void TimerOFF0() {
	Serial.println("Timer OFF 0 triggered.");
	if (status == 1) {
		state[0] = false;
	}
	if (timerRep[3] == false) {
		timer[3] = false;
		Alarm.disable(6);
	}
}
void TimerOFF1() {
	Serial.println("Timer OFF 1 triggered.");
	if (status == 1) {
		state[1] = false;
	}
	if (timerRep[4] == false) {
		timer[4] = false;
		Alarm.disable(7);
	}
}
void TimerOFF2() {
	Serial.println("Timer OFF 2 triggered.");
	if (status == 1) {
		state[0] = false;
		state[1] = false;
	}
	if (timerRep[5] == false) {
		timer[5] = false;
		Alarm.disable(8);
	}
}

/*---------------------------------TIME SETTING INITIALIZE----------------------------------*/
void settingInit(unsigned long setT) {
  setMinute = minute(setT);
  setHour = hour(setT);
  setDay = day(setT);
  setMonth = month(setT);
  setYear = year(setT);
}

/*---------------------------------GET STRING OF CURRENT TIME AND DATE----------------------------------*/
void getNowStr() {
  unsigned long t = now();
  String leadingZero[5];
  String timeStr, dateStr;
  if (second(t)<10) leadingZero[0] = "0";
  if (minute(t)<10) leadingZero[1] = "0";
  if (hour(t)<10) leadingZero[2] = "0";
  timeStr = leadingZero[2] + (String)hour(t) + ":" + leadingZero[1] + (String)minute(t) + ":" + leadingZero[0] + (String)second(t);
  timeStr.toCharArray(timeChar, timeStr.length() + 1);
  if (day(t) < 10) leadingZero[3] = "0";
  if (month(t) < 10) leadingZero[4] = "0";
  dateStr = leadingZero[3] + (String)day() + "." + leadingZero[4] + (String)month() + "." + (String)year();
  dateStr.toCharArray(dateChar, dateStr.length() + 1);
}

/*---------------------------------GET STRING OF TIMER SETTINGS----------------------------------*/
void getTimerStr() {
	String leadingZero[2];
	String timeStr;
	if (setMinute < 10) leadingZero[0] = "0";
	if (setHour < 10) leadingZero[1] = "0";
	timeStr = leadingZero[1] + (String)setHour + ":" + leadingZero[0] + (String)setMinute;
	timeStr.toCharArray(setTimerChar, timeStr.length() + 1);
}

/*---------------------------------GET STRING OF SETTING TIME AND DATE----------------------------------*/
void getSettingTimeStr() {
	String leadingZero[5];
	String timeStr, dateStr;
	if (second() < 10) leadingZero[0] = "0";
	if (setMinute < 10) leadingZero[1] = "0";
	if (setHour < 10) leadingZero[2] = "0";
	timeStr = leadingZero[2] + (String)setHour + ":" + leadingZero[1] + (String)setMinute + ":" + leadingZero[0] + (String)second();
	timeStr.toCharArray(setTimeChar, timeStr.length() + 1);
	if (setDay < 10) leadingZero[3] = "0";
	if (setMonth < 10) leadingZero[4] = "0";
	dateStr = leadingZero[3] + (String)setDay + "." + leadingZero[4] + (String)setMonth + "." + (String)setYear;
	dateStr.toCharArray(setDateChar, dateStr.length() + 1);
}