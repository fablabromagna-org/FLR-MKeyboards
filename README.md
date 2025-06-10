# FLR-MKeyboards

Progetti di tastiere meccaniche FablabRomagna


## Tastiere

- [Khor R12](khor_r12/) - Keypad 4x3 + Encoder +  I²C Oled Display 
## Organizzazione del repository

Questo repository contiene informazioni, documentazione e progetti di tastiere meccaniche (complete o keypad) utilizzate da FablabRomagna nell'ambito delle attività laboratoriali e di corsi.

Queste tastiere meccaniche, basate su microcontrollori di vario genere e firmware open source (es. QMK ma non solo) utilizzano tasti meccanici e schemi elettrici tipicamente gestiti a matrice.

Il repository è organizzato con un'area comune, contenente informazioni e risorse generiche e comuni alla costruzione e gestione di varie tastiere meccaniche, e di una serie di sottodirectory, una per ogni tipologia di tastiera.

Ogni sottodirectory contiene un file README che ne descrive le caratterisctiche e tutte le informazioni e i files per tale tastiera. Ed eventualmente una directory "firmware" contente le customizzazioni QMK (o altri) e relative istruzioni.

```
README.md
docs/
images/
<keyboardXYZ>/
    README.md
    docs/
    images/
    pcb/
    3Dfiles/
    firmware/

```





## Partecipazione al repository

> regole in via di definizione (soggette a possibili integrazioni)

E' possibile partecipare al progetto del presente repository in 2 modi:

1. eseguendo il fork del repository con il proprio account GitHub, eseguendo le modifiche su un branch separato, e poi eseguendo una pull request per integrare le proprie modifiche in questo repository (è il workflow classico promosso da GitHub - [istruzioni](https://docs.github.com/en/get-started/exploring-projects-on-github/contributing-to-a-project))
2. se sei un membro attivo di FablabRomagna puoi richiedere l'accesso al presente repository comunicando il tuo account GitHub a github@fablabromagna.org o tramite il canale Telegram dell'associazione

In quest'ultimo caso sarai abilitato ad eseguire push direttamente in questo repository, senza necessità di creare un fork.

Dovrai però seguire queste regole, per evitare conflitti sulle parti condivise:
- lavora sempre su un branch separato, e non in `main`. Sarebbe opportuno nominare i propri branch con un prefisso che indichi il nome del proprietario
- ove possibile, evita di modificare files o directory giá creati da altri; salvo concordarne le modifiche sul gruppo. Ad esempio, piuttosto che editare un keymap giá presente, creane uno tuo con un nome diverso
- mantieni le tue modifiche il piú possibile circoscritte ad una funzionalitá specifica. Se necessario crea piú branch personali (_questo perché i merge nel ramo `main` vengono eseguiti in toto sull'intero branch personale, e non per singoli files_)
- una volta completate le tue modifiche, richiedi agli amministratori del repository di integrarle (merge nel branch `main`)

> queste sono regole di massima per permetterci di tenere ordinato il repository lavorandoci a piú mani, ma possono ovviamente essere migliorate e cercheremo di gestire i contributi con flessibilitá
