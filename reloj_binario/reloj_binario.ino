




//Definimos ctes
int segs[] = {2, 3, 4, 5, 6, 7};
int mins[] = {8, 9, 10, 11, 12, 13};
int hours[] = {A0, A1, A2, A3, A4};
int segsElements =  sizeof(segs) / 2;
int minsElements =  sizeof(mins) / 2;
int hoursElements =  sizeof(hours) / 2;

int segundos = 0;
int minutos = 59;
int horas = 19;
//Vamos a definir los leds, como salidas
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < segsElements; i++)
  {
    pinMode(segs[i], OUTPUT);
  }
  for (int i = 0; i < minsElements; i++)
  {
    pinMode(mins[i], OUTPUT);
  }
    for (int i = 0; i < hoursElements; i++)
  {
    pinMode(hours[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  segundos++;
  if (segundos > 59){
    segundos = 0;
    minutos++;
    if (minutos > 59){
      minutos = 0;
      horas++;
      if (horas > 24){
        horas = 0;
      }
     } 
    }
  //00 00 00
  //Serial.println((char) seconds);
    Serial.print("Hours: ");
    Serial.print(horas);
    Serial.print(" Minutes: ");
    Serial.print(minutos);
    Serial.print(" Seconds: ");
    Serial.println(segundos);
    DisplaySegundos();
    DisplayMinutos();
    DisplayHoras();
    delay(1000);
}
void DisplaySegundos() {
  for (int i = 0; i<segsElements; i++)
  {
    int currentSecond = bitRead(segundos, i);
    digitalWrite(segs[i], currentSecond);
  }
}
void DisplayMinutos() {
  for (int i = 0; i<minsElements; i++)
  {
    int currentMinute = bitRead(minutos, i);
    digitalWrite(mins[i], currentMinute);
  }
}
void DisplayHoras() {
  for (int i = 0; i<hoursElements; i++)
  {
    int currentHour = bitRead(horas, i);
    digitalWrite(hours[i], currentHour);
  }
}
