# Khor R12 firmware - AppKeypad

> 2025 Ivan (itarozzi - ivan.tarozzi@fablabromagna.org)

Firmware QMK basato sul lavoro di [Khor](https://github.com/MoltenKhor/R12).

Implementa un keypad per la gestione di applicazioni multiple.

## L'idea di keypad per applicazioni

Questa implementazione nasce con l'obiettivo di creare un tastierino per inviare shortcuts (tasti singoli o sequenze di tasti) a varie applicazioni (FreeCAD, Inkscape, OBS).  
Implementa inoltre anche un controller **MIDI**, per eventuali applicazioni che favoriscano l'integrazione con questo protocollo.  

E' possibile configurare diverse applicazioni, selezionabili con l'encoder:
- con la pressione prolungata si entra in modalità di _selezione applicazione_
- ruotando l'encoder si seleziona l'applicazione
- con una nuova pressione prolungata si esce dalla modalità di _selezione applicazione_


Ogni applicazione può disporre di più modalità operative (Mode default = 0). In questo modo è possibile creare dei layout diversi per le differenti modalità operative.  
Ad esempio per l'uso con FreeCAD sarà possibile definire un layout per la modalità _Part Design_, uno per la modalità _Sketch_ e così via.  

Al momento sono previste un massimo di 4 modalità per ogni applicazione, ma potrebbero essere ampliate.  


Per ogni modalità viene mostrato sul display un layout mnemonico con una stringa (max 3 caratteri) per ognuno dei 12 tasti.  

In ogni modalità, per ognuno dei 12 tasti, è possibile associare l'invio di shortcuts abbinati a vari eventi:  
- pressione singola
- pressione doppia 
- pressione prolungata

> E' possibile definire altre tipologie di eventi, sulla base della gestione del modulo **Tap Dance** di **QMK**: vedi [documentazione](https://docs.qmk.fm/features/tap_dance).


Solitamente, nei layout implmentati, la pressione prolungata dei tasti 9 - 12 permette di accedere alle 4 modalità (ove previste).  
E' possibile ridefinire questo comportamento, avendo cura di prevedere sempre un modo per tornare alla modalità iniziale o precedente.



Un file **.ods** allegato al presente progetto contiene un elenco delle varie modalità per ogni applicazione, con le funzioni associate ad ogni evento dei tasti. 

> Al momento solo un sottoinsieme dei layout contenuti nel file ods sono stati implementati


## Applicazioni e modi implementati

### Default

> descrizione da completare

### FreeCAD 

> descrizione da completare

### MIDI

Questa applicazione prevede per ora una sola modalità.   
La pressione sul tasto encoder permette di selezionare il canale MIDI. Ruotare per selezionare il canale. Premere nuovamente per confermare.

Le pressioni singole sui tasti 1-12 inviano un messaggio MIDI Program Change (PC) con valore da 1 a 12.

Le pressioni doppie sui tasti 1-12 selezionano il Control Change attivo (da 1 a 12).  

Ruotando l'encoder viene inviato un messaggio MIDI Control Change sul Control selezionato, con valore da 0 a 127.  

Canale e CC selezionati sono mostrati sul display.

> Nota: esiste al momento un offset indesiderato tra il canale MIDI selezionato/visualizzato e quello utilizzato in fase di invio del messaggio. Da verificare. 





## Aggiungere una nuova applicazione

> descrizione da completare








> Work in progress...


