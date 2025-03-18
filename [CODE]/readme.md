# ⭐ Kod - Dokumentacja

## 📚 Biblioteki

```c
#include <avr/io.h>
#include <util/delay.h>
```

Pierwsze **2** linie naszego kodu źródłowego mają za zadanie dołączyć poszczególnych i niezbędnych bibliotek do naszego projektu.

## ⚙ Optymalizacje

```c
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
```

Poniższa część kodu definiuje poszczególne numery **wyjść** na płytce jako odpowiednie im kolory, aby kod był bardziej czytelny. 

```c
#define GREEN 4
#define BLUE 3
#define RED 2
#define IDLE 0
```

💬 *Kolor IDLE jest kolorem testowym, który służył do sprawdzenia sprawności układu i nie jest wykorzystywany w finałowym produkcie.* 

Poniższa część kodu składa się z trzech funkcji.

```c
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
```
Funkcja **turnOnALL** bierze jedną wartość *(np. GREEN)* i włącza wszystkie diody na wyjściu *(np. GREEN (PORTD4))*.

💬 *Testowy kolor IDLE służył do sprawdzenia, czy program działa w momencie gdy wszystkie inne diody były wyłączone. W momencie*
*włączenia jednej lub więcej diód owy kolor był wyłączony.* 

Funkcja **turnOffALL** bierze jedną wartość *(np. GREEN)* i wyłącza wszystkie diody na wyjściu *(np. GREEN (PORTD4))*.

Funkcja **turnOff** wyłącza wszystkie diody.

💬 *Program w tym momencie wciąż był włączony i do sprawdzenia, czy wciąż działał służyło włączenie diody IDLE.* 

## 🧠 Main

Reszta kodu została przedstawiona poniżej.

```c
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
```

Pierwsza część tego kodu służy do deklaracji ważnych dla tego programu zmiennych i funkcji.

```c
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
.
.
.
```

Zmienne **btn_i** oraz **led_i** służą do obsługi przycisku.

Zmienne **delay**, **delayshort** oraz **delayshortest** służą do obsługi pewnych ustawień świateł. Te zmienne są zegarami.

Części z komentarzami typu **2 Output** deklarują wyjścia na diody, natomiast **PB5 Input** jest wyjściem obsługującym przycisk.

Funkcja **turnOff** jest zadeklarowana, aby upewnić się, że program zacznie z wyłączonymi diodami.

```c
.
.
.
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
.
.
.
```

Początek tej pentli obsługuje przycisk, funkcja ta zapobiega zbyt wielu kliknięciom. Kliknięcie przycisku powoduje zwiększenie

zmiennej **led_i** o `1`. Powoduje do zmiane ustawień na nowe instrukcje, których lista została podana poniżej:

```c
.
.
.
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
```
1️⃣ **Ustawienie**:

Wszystkie diody się palą.

🟢🔵🔴   IDLE ⚫

2️⃣ **Ustawienie**:

Wszystkie diody czerwone się palą, reszta jest wyłączona.

⚫⚫🔴   IDLE ⚫

3️⃣ **Ustawienie**:

Wszystkie diody niebieskie się palą, reszta jest wyłączona.

⚫🔵⚫   IDLE ⚫

4️⃣ **Ustawienie**:

Wszystkie diody niebieskie się palą, reszta jest wyłączona.

🟢⚫⚫   IDLE ⚫

5️⃣ **Ustawienie**:

Aktywny kolor zmienia się na każdy kolor w kolejności **ZIELONY → NIEBIESKI → CZERWONY**.

Kolory zmieniają się co **sekunde**.

⚫⚫🔴   IDLE ⚫  →  ⚫🔵⚫   IDLE ⚫  →  🟢⚫⚫   IDLE ⚫

6️⃣ **Ustawienie**:

Aktywny kolor zmienia się na każdy kolor w kolejności **ZIELONY → NIEBIESKI → CZERWONY**.

Kolory zmieniają się co **pół sekundy**.

⚫⚫🔴   IDLE ⚫  →  ⚫🔵⚫   IDLE ⚫  →  🟢⚫⚫   IDLE ⚫

7️⃣ **Ustawienie**:

Aktywny kolor zmienia się na każdy kolor w kolejności **ZIELONY → NIEBIESKI → CZERWONY**.

Kolory zmieniają się co **0,2 sekundy**.

⚫⚫🔴   IDLE ⚫  →  ⚫🔵⚫   IDLE ⚫  →  🟢⚫⚫   IDLE ⚫

8️⃣ **Ustawienie**:

Wszystkie kolory się wyłączają. Numer danego ustawienia zamienia się na 0️⃣.

⚫⚫⚫   IDLE 🟡


