# 🔴🟢🔵 Sterowanie Lampkami Choinkowymi

Projekt ma sterować serią diod LED, poprzez zmienianie ustawień diód na jedno z wielu ustawień, z których użytkownik może wybrać przystosowane dla niego oświetlenie. Projekt zaweria różne rodzaje oświetlenia, miedzy innymi:

- [ ] Oscylacja światełek czerwonych, zielonych lub niebieskich.
- [ ] Włączenie bądź wyłączenie poszczególnych kolorów.
- [ ] Inne niestandardowe ustawienia oświetlenia.

Można rozszerzyć ilość używanych diod, poprzez dodanie więcej gałęzi po 3 diody:
 - Zamiast 1 gałęzi z 3 diodami, tworzysz np. 7 równoległych gałęzi po 3 diody w szeregu.
 - Każda gałąź dostaje swój rezystor, np. 7 rezystorów po 120Ω dla zielonych LED-ów.
 - MOSFET steruje wszystkimi 7 gałęziami naraz.
 
👉 Zalety: Nie zmienia się napięcie, MOSFET łatwo steruje większą ilością diod.


## 📝 Dokumentacja

ℹ Kod → [**Dokumentacja**](https://github.com/blazejo774/sterowanie-lampkami/blob/d19fd1ce32649a07414ba25e057f50cffe792c03/%5BCODE%5D/main.c)

ℹ Wykaz elementów → [**Dokumentacja**](https://github.com/blazejo774/sterowanie-lampkami/blob/d19fd1ce32649a07414ba25e057f50cffe792c03/%5BELECTRONICS%5D/readme.md)


## ⭐ Software

💾 Kod → [**main.c**](https://github.com/blazejo774/sterowanie-lampkami/blob/d19fd1ce32649a07414ba25e057f50cffe792c03/%5BCODE%5D/main.c)

## 💡 Hardware

💾 Schemat Elektryczny → [**Schemat Elektryczny**](https://github.com/blazejo774/sterowanie-lampkami/blob/d19fd1ce32649a07414ba25e057f50cffe792c03/%5BELECTRONICS%5D/scheme.pdf)

💾 Schemat Płytki PCB TOP → [**Płytka-TOP**](https://github.com/blazejo774/sterowanie-lampkami/blob/d19fd1ce32649a07414ba25e057f50cffe792c03/%5BBOARD%5D/Board_TOP.pdf)

💾 Schemat Płytki PCB BOTTOM → [**Płytka-BOTTOM**](https://github.com/blazejo774/sterowanie-lampkami/blob/d19fd1ce32649a07414ba25e057f50cffe792c03/%5BBOARD%5D/Board_BOTTOM.pdf)

💾 Schemat Płytki PCB(IMAGE) → [**Płytka**](https://github.com/blazejo774/sterowanie-lampkami/blob/d19fd1ce32649a07414ba25e057f50cffe792c03/%5BBOARD%5D/BOARD.png)
