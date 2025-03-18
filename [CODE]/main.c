#include <avr/io.h>
#include <util/delay.h>
#define GREEN 4
#define BLUE 3
#define RED 2
#define IDLE 0
void turnOnALL(int8_t led){
  PORTB &= ~(1 << IDLE);
  PORTD |= (1 << led); 
}
void turnOffALL(int8_t led){
  PORTD &= ~(1 << led); 
}
void turnOff(){
  PORTB |= (1 << IDLE);
  PORTD &= ~(1 << RED);  
  PORTD &= ~(1 << GREEN); 
  PORTD &= ~(1 << BLUE); 
}

int main(void)
{
  uint16_t btn_i = 5000;
  uint16_t led_i = 0;
  uint16_t delay = 3000;
  uint16_t delayshort = 1500;
  uint16_t delayshortest = 600;

  DDRD |= (1 << 2); // 2 Output
  DDRD |= (1 << 3); // 3 Output
  DDRD |= (1 << 4); // 4 Output

  DDRB |= (1 << 0); // 8 Output
  DDRB &= ~(1 << 5); // PB5 Input
  PORTB |= (1 << 5); // PB5 Pull-Up
  
  turnOff();

  while (1)
  {// Button
    if(!(PINB & (1 << PB5))) {
      btn_i--;
      if(!btn_i) {
        btn_i = 5000;
        led_i++;
      }
    }
    else {
      btn_i = 50;
    }
    switch (led_i)
    {
      case 1:
        turnOnALL(RED);
        turnOnALL(GREEN);
        turnOnALL(BLUE);
        break;
      case 2:
        turnOnALL(RED);
        turnOffALL(BLUE);
        turnOffALL(GREEN);
        break;
      case 3:
        turnOffALL(RED);
        turnOnALL(BLUE);
        turnOffALL(GREEN);
        break;
      case 4:
        turnOffALL(RED);
        turnOffALL(BLUE);
        turnOnALL(GREEN);
        break;
      case 5:
        delay--;
        switch (delay)
        {
        case 2000:
          turnOff();
          turnOnALL(RED);
          break;
        case 1000:
          turnOff();
          turnOnALL(BLUE);
          break;
        case 0:
          turnOff();
          turnOnALL(GREEN);
          delay = 3000;
          break;
        default:
          break;
        }
        break;
      case 6:
        delayshort--;
        switch (delayshort)
        {
          case 1000:
            turnOff();
            turnOnALL(RED);
            break;
          case 500:
            turnOff();
            turnOnALL(BLUE);
            break;
          case 0:
            turnOff();
            turnOnALL(GREEN);
            delayshort = 1500;
            break;
          default:
            break;
        }
        break;
      case 7:
        delayshortest--;
        switch (delayshortest)
        {
          case 400:
            turnOff();
            turnOnALL(RED);
            break;
          case 200:
            turnOff();
            turnOnALL(BLUE);
            break;
          case 0:
            turnOff();
            turnOnALL(GREEN);
            delayshortest = 600;
            break;
          default:
            break;
        }
        break;    
      case 8:
        turnOff();
        led_i = 0;
        break;
      default:
        break;
    }
    _delay_ms(1);
  }
}
