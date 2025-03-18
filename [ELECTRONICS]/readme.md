# Wykaz elementów użytych w układzie


🔴Diody LED 5mm czerwone - **JUS-19995**.

🟢Diody LED 5mm zielone - **JUS-19994**. 

🔵Diody LED 5mm niebieske - **JUS-19991**.


◾️ Tranzystory MOSFET typu N - **BUZ10**

◾️ Rezystory 470 Ω (podłączone do bramek tranzystorów MOSFET) - **TE Connectivity / Neohm - 6-2176611-5**

◾️ Rezystory 90 Ω (dla diod koloru niebieskiego 🔵  **Vishay / BC Components - MBA0204VC9009FCT00**

◾️ Rezystory 300 Ω (dla diod koloru czerwonego 🔴) **YAGEO- CFR-25JB-52-300R**

◾️ Rezystory 120 Ω (dla diod koloru 🟢) **TE Connectivity / Neohm - EP1WSS120RJ**

◾️ Mikrokontroler AVR - **ATMEL - ATmega328P-AU**


# ⚡ Obliczenia poboru mocy (3 diody w każdej gałęzi)

Rezystory ograniczające prąd dla LED

    🔴Czerwone diody (2V x 3 = 6V)

        Rezystor: 300Ω

    🔵Niebieskie diody (3.4V x 3 = 10.2V)

        Rezystor: 90Ω

    🟢Zielone diody (3.2V x 3 = 9.6V)

        Rezystor: 120Ω

Moc tracona na rezystorach

    🔴Czerwone diody → 0.36 W

    🔵Niebieskie diody → 0.108 W

    🟢Zielone diody → 0.144 W

Całkowity pobór mocy układu

    🚀Moc pobierana przez LED-y: 0.72 W

    🚀Moc pobierana przez mikrokontroler: 0.1 W

    🚀Łączna moc pobierana przez cały układ: 0.82 W

✅ Użyty zasilacz to → 12V, 500mA oraz 5V, 100mA
