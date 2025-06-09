# Khor R12 firmware 

> 2025 Ivan (itarozzi - ivan.tarozzi@fablabromagna.org)

Firmware QMK basato sul lavoro di [Khor](https://github.com/MoltenKhor/R12).

Rispetto al firmware Khor sono state apportate le seguenti modifiche:

- aggiunto pulsante dell'encoder nel file `keyboard.json`
- aggiunta la gestione dell'encoder (rotazione)
- aggiunta la gestione del display OLED 
- creato una serie di keymaps per diversi ambiti operativi

I vari keymaps sono disponibili nella cartella [keymaps](./keymaps/) :


### Oled

Integrazione base del display OLED con la semplice visualizzazione del logo QMK.


### Encoder

Integrazione base dell'encoder e del relativo pulsante (come tredicesimo switch).

Inoltre questo esempio implementa la gestione di 2 layer. L'accesso al layer 2 viene eseguito con la pressione del pulsante dell'encoder.

Il layer attivo viene visualizzato sul display.

### App_Keypad

Questo keymap ha lo scopo di realizzare un keypad per l'invio di  shortcut funzionanti con diverse applicazioni.

Per ogni applicazione é possibile definire diversi shortcut, corrispondenti a diversi eventi sui 12 pulsanti e sull'encoder.

Ogni applicazione puó inoltre disporre di vare sotto-modalitá di lavoro, ognuna con i propri shortcut specifici.

Un OLED di dimensioni maggiori rispetto a quello previsto da Khor viene usato per mostrare l'applicazione selezionata e un reminder per le funzioni legate ai 12 tasti.

Maggiori informazioni nel [file readme](./keymaps/app_keypad/readme.md) relativo.




## Come compilare il firmware QMK

1. installare e configurare l'ambiente di compilazione del firmware QMK per il proprio sistema operativo, seguendo le istruzioni indicate qui: [https://docs.qmk.fm/newbs_getting_started](https://docs.qmk.fm/newbs_getting_started)
2. copiare il contenuto della directory `khor_r12/firmware/keyboards/fablabromagna` all'interno del ramo del progetto QMK, nella directory `<qmk_firmware>/keyboards`
3. compilare il firmware specificando il nome della keyboard `fablabromagna/r12_it` e il keymap desiderato tra quelli presenti (corrisponde al nome della directory sotto `keymapa`)

Esempi:

```
qmk compile -kb fablabromagna/r12_it  -km oled

qmk compile -kb fablabromagna/r12_it  -km encoder

qmk compile -kb fablabromagna/r12_it  -km app_keypad 
```



