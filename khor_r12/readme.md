# Khor R12 

Keypad 4x3 con Encoder e Oled fornita da  [Khor](https://github.com/MoltenKhor/R12) ed utilizzata per la prima volta nel corso sulle tastiere meccaniche presso SanLab (maker space Santarcangelo di Romagna) del 22/05/2025, tenuto da  Giulio e Andrea.


## Descrizione HW

Il  **Keypad R12** é costituito da:
- 4x3 Matrix Switch 
- Encoder con pulsante
- I²C Oled Display

Utilizza una board  **Helios** basata su microcontrollore **RP2040**.
 

La matrice 4x3 e il pulsante dell'encoder utilizzano i pins descritti nel file `keyboard.json`.

```
/*
      * Matrix Layout and Pinout *
     
            GP22 GP26 GP27 GP28    GP29
           ┌────┬────┬────┬────┬──────────────┐
      GP7  │  0 │  1 │  2 │  3 │ EncoderSwitch│
           ├────┼────┼────┼────┼──────────────┤ 
      GP8  │  4 │  5 │  6 │  7 │    n.c.
           ├────┼────┼────┼────┤
      GP9  │  8 │  9 │ 10 │ 11 │    n.c.
           └────┴────┴────┴────┘
           
*/
``` 

> Il pulsante dell'encoder usa i pin GP29 e GP7, quindi puó essere usato nel controller della matrice come un normale switch della tastiera


L'encoder é collegato direttamente ai pins GP6 and GP5.

Il display OLED I²C é collegato ai pins SDA/SCL (GP6, GP5).


## Firmware

Al momento i test e le personalizzazioni sono state fatte con il firmware [QMK](https://github.com/qmk/qmk_firmware).

Le diverse implementazioni e le istruzioni per la compilazione sono sono disponibili nella sezione `firmware`, all'interno della cartella [fablabromagna](firmware/keyboards/fablabromagna/r12_it)

