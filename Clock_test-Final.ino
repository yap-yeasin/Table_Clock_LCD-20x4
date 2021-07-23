#include <Wire.h>  
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // SET I2C Address My case it's 0x3F , test your then change it
DS3231  rtc(SDA, SCL);
Time  t;

int h, m, s;

void setup()
{
  rtc.begin();
  lcd.begin(20, 4);
//   The following lines can be uncommented to set the date and time
//   rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
//   rtc.setTime(14, 31,55);     // Set the time to 12:00:00 (24hr format) than it will be 12 hour format
//   rtc.setDate(8, 5, 2021);   // Set the date to 

}

void loop()
{
  TIME();
  // Send time
  lcd.setCursor(0, 0);
  lcd.print("   Time:");
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);

  h = t.hour, DEC;
  if (h >= 12)
  {
    lcd.print(" PM");
  }
  if (h < 12)
  {
    lcd.print(" AM");
  }

  //Date_Section
  lcd.setCursor(0, 1);
  lcd.print("   Date:");
  lcd.print(rtc.getDateStr());

  // Day_Section
  lcd.setCursor(0,2);
  lcd.print("    Day: ");
  lcd.print(rtc.getDOWStr());

  //Temperature_Section
  lcd.setCursor(0, 3);
  lcd.print("   Temp: ");
  lcd.print(rtc.getTemp());
  lcd.write(223);
  lcd.print("C");
}
void TIME()
{
  t = rtc.getTime();
  h = t.hour, DEC;
  m = t.min, DEC;
  s = t.sec, DEC;
  if (h > 12)
  {
    h = h - 12;
  }
  else if (h == 0) h = 12;
}
