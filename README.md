[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/EFFc3I5v)
# Labor 4: Szalkezeles es Memoriakezeles

## Bevezetes

Ez a labor ket fo temakort olel fel:
- **Szalkezeles (Multithreading)**: Parhuzamos vegrehajtasi problemak es megoldasok
- **Memoriakezeles**: Dinamikus memoria helyes hasznalata es hibakereseEs

## Elokovetelmények

A feladatok megoldasahoz szukseg van:
- GCC fordito pthread tamogatassal
- Valgrind memoria ellenorzo eszkoz
- GDB debugger (opcionalis, de ajanlott)

### Telepites Ubuntu/Debian rendszeren:

```bash
sudo apt-get update
sudo apt-get install build-essential valgrind gdb
```

## Labor feladatok

### Szalkezeles feladatok

**Feladat 01: Race Condition Demonstralas**
- Tema: A parahuzamos iras veszelyei
- Konyvtar: `feladat_01/`
- Cel: Megerteni, hogy mi tortenik, ha tobb szal egyidoben ir ugyanarra a valtozora

**Feladat 02: Mutex Vedelem**
- Tema: A problema megoldasa zarakkal
- Konyvtar: `feladat_02/`
- Cel: A race condition kijavitasa mutex hasznalataval

**Feladat 03: Parhuzamos Kereses**
- Tema: Szalak kozotti koordinacio
- Konyvtar: `feladat_03/`
- Cel: Nagy adathalmaz parhuzamos feldolgozasa, szalak leallitasa talalat eseten

### Memoriakezeles feladatok

**Feladat 04: Valgrind es Memory Leaks**
- Tema: Memoria szivargas felderitese
- Konyvtar: `feladat_04/`
- Cel: Hibas kod javitasa valgrind segitsegevel

**Feladat 05: Dinamikus Tomb Realloc**
- Tema: Memoria ujrafoglalas helyes kezelese
- Konyvtar: `feladat_06/`
- Cel: A realloc fuggveny helyes hasznalata es hibakezelese

**Feladat 06: Segmentation Fault Debugging**
- Tema: Memoria hozzaferesi hibak
- Konyvtar: `feladat_06/`
- Cel: Memoria hibak okozasa es felderitese debuggerrel

## Forditasi utmutato

### Alapveto forditas:

```bash
# Feladat 01 - Race condition
gcc -Wall -Wextra -pthread -g feladat_01/starter.c -o feladat_01

# Feladat 02 - Mutex
gcc -Wall -Wextra -pthread -g feladat_02/starter.c -o feladat_02

# Feladat 03 - Parhuzamos kereses
gcc -Wall -Wextra -pthread -g feladat_03/starter.c -o feladat_03

# Feladat 04 - Memory leak (buggy verzio)
gcc -Wall -Wextra -g feladat_04/buggy.c -o feladat_04

# Feladat 05 - Realloc
gcc -Wall -Wextra -g feladat_05/starter.c -o feladat_05

# Feladat 06 - Segfault (buggy verzio)
gcc -Wall -Wextra -g feladat_06/buggy.c -o feladat_06
```

### Futtatás:

```bash
./feladat_01
./feladat_04
# stb.
```

### Valgrind futtatasa:

```bash
valgrind --leak-check=full ./feladat_04
valgrind --leak-check=full ./feladat_05
valgrind ./feladat_06
```

## Altalanos tanacsok

1. **Mindig forditsd `-Wall -Wextra` flagekkel** - Sok hibat mar forditas kozben elkap
2. **Hasznald a `-g` flaget** - Debug informaciokat ad a binarishoz
3. **Thread programoknal `-pthread` kell** - Feladat 01, 02, 03
4. **Valgrind legyen a baratod** - Futtasd le minden memoriat hasznalo programon
5. **Race condition-ok nehezen reprodukalhatoak** - Ha egyszer jo az eredmeny, az meg nem jelenti, hogy helyes a kod
6. **Olvass el minden valgrind hibauzenetet** - Pontosan megmondja, hol van a problema

## Hasznos parancsok

### Program futtatasa valgrind-dal (memory leak kereses):

```bash
valgrind --leak-check=full ./feladat_04
```

### Program futtatasa GDB-vel (segfault debug):

```bash
gdb ./feladat_06
(gdb) run
(gdb) backtrace
(gdb) quit
```

### Thread hibak kereses (race condition):

```bash
valgrind --tool=helgrind ./feladat_01
```

### Binaris torlese:

```bash
rm feladat_01 feladat_02 feladat_03 feladat_04 feladat_05 feladat_06
```

## Tovbbi dokumentacio

- `docs/pthread_referencia.txt` - POSIX thread fuggvenyek gyorsreferencia
- `docs/valgrind_hasznalat.txt` - Valgrind parancsok es kimenet ertelmezese

## Megjegyzesek

A feladatok progressziv nehezseguek. Ajanlott a megadott sorrendben megoldani oket.
Egyes feladatok szandekosan hibas kodot tartalmaznak - ez reszed a tanulasi folyamatnak.
