# Enigma Numbers (AiSD 2020 P2)

Algorithms and Data Structures - project sem. 2 2020

## Enigma

### English

Your task is to implement a variant of an [Enigma machine](https://en.wikipedia.org/wiki/Enigma_machine) which encrypts messages in an alphabet consisting of *n* letters denoted by numbers *{1,2,...,n}*. Symbol *0* ends the message.

Rotors *Wx={wx, 0, wx, 1,...,wx, n}* and reflectors *Ry={ry, 0, ry, 1,...,ry, n}* are given as permutations of numbers *{1,2,...,n}* and simulate [mechanical parts](https://en.wikipedia.org/wiki/Enigma_rotor_details) that can be used by an operator. The internal "wiring" of these parts does not change.

Typing a letter into the input encrypts it by passing it through the rotors into reflector and back through the rotors in the inverse sequence, as seen [here](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6c/Enigma-action.svg/600px-Enigma-action.svg.png). A stationary sequence of rotors and a reflector represent a simple substitution cipher, it is their movement which makes the decoding chalenging.

Each rotor can move counterclockwise by at most one step during each encoding. The first rotor moves before every encoding; therefore if the initial position of this single rotor is denoted by the last letter of the alphabet (i.e. *n*, see example I) the first letter is encoded according to substitutions as stated in the rotor's definition.
Further rotors move according to rules outlined in scetion "Turnover notch positions" of this [link](https://en.wikipedia.org/wiki/Enigma_machine#Turnover) and [this section](https://en.wikipedia.org/wiki/Enigma_machine#Turnover). Additional information about double stepping can be found [here](http://www.intelligenia.org/downloads/rotors1.pdf).

In case there are more than 3 rotors only the first 3 rotate.

Input can be thought as divided into two parts: definitions of pieces of the machine and *p* instructions how to encode a given message using some of those parts. Before encoding a message the machine is assembled from *k* out of *m* rotors and a single reflector (out of *l*) and the rotors are set to some initial positions. Refer to the input section for details.

### Polish (Polska wersja)

Twoim zadaniem jest zaimplementowanie wariantu [maszyny Enigma](https://en.wikipedia.org/wiki/Enigma_machine) która koduje wiadomości w alfabecie składającym się z *n* liter oznaczonych numerami *{1,2,...,n}*. Symbol *0* kończy wiadomość.

Wirniki *Wx={wx, 0, wx, 1,...,wx, n}* i reflektory *Ry={ry, 0, ry, 1,...,ry, n}* podane są jako permutacje *{1,2,...,n}* i symulują [mechaniczne części](https://en.wikipedia.org/wiki/Enigma_rotor_details) które może używać operator. Wewnętrzne "okablowanie" tych części nie ulega zmianom.

Podanie na wejście litery szyfruje ją poprzez przesłanie jej przez wirniki do reflektora i z powrotem przez wirniki w odwrotnej kolejności, jak zobaczyć można [tutaj](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6c/Enigma-action.svg/600px-Enigma-action.svg.png). Nieruchoma sekwencja wirników i reflektora reprezentuje prosty szyfr podstawieniowy, to dzięki ich ruchomości odszyfrowanie wiadomości stanowi wyzwanie.

Każdy wirnik rusza się co najwyżej o jedną pozycję w kierunku przeciwnym do ruchu wskazówek zegara przy każdym kodowaniu. Pierwszy wirnik rusza się przed każdym kodowaniem; dlatego jeśli początkowa pozycja tego wirnika podana jest przy pomocy ostatniej litery alfabetu (tak jak w przykładzie) pierwsza litera kodowana jest przez podstawienie takie jak podano w definicji wirnika. Pozostałe wirniki obracają się wg. zasad podanych w sekcji "Turnover notch positions" tego [linku](https://en.wikipedia.org/wiki/Enigma_machine#Turnover) i [tej sekcji](https://en.wikipedia.org/wiki/Enigma_machine#Turnover). Dodatkowe informacje o podwójnym kroku ("double stepping") można znaleźć [tutaj](http://www.intelligenia.org/downloads/rotors1.pdf).

W przypadku gdy w maszynie są więcej niż 3 wirniki tylko pierwsze 3 się obracają.

O wejściu można myśleć jako podzielonym na dwie części: definicje elementów maszyny i *p* instrukcji jak zakodować daną wiadomość używając tych części tych elementów. Przed zakodowaniem wiadomości maszyna jest złożona z *k* z *m* wirników i jednego reflektora (z *l*) i wirniki ustawione są na podanych początkowych pozycjach (więcej informacji w sekcji o wejściu).

## Input:

#### Defintions of parts of the machine:

- *n*- number of letters (numbers) in the alphabet
- *m* - number of rotors, followed by their definitions *W0,...,Wm-1*
	- definition of rotor *Wi* - permutation of the alphabet
	- number of letters which cause turnover, followed by these letters as in ["Position of turnover notches" table](https://en.wikipedia.org/wiki/Enigma_machine#Turnover)
- *l* - number of reflectors
- definitions of reflectors *R0,...,Rl-1* - permutation of the alphabet

#### A set of *p* tasks to perform:

each task consists of 2 parts: machine setup and a message to encrypt.

- *p* number of tasks
- *k* - number of rotors in the machine
- *k* pairs *K0,...,Kk-1* - where *Ki=(j, t)*, where *j* is an index of a copy of rotor *Wj* and *t* is its initial position
	- rotors are given in order from fastest to slowest
	- initial position of a rotor - it is set as if it was rotated (no actual rotations occur) prior to encoding, e.g. 1 - rotor is set as stated in permutation, 2 - it is shifted by one letter, etc.
- *r* index of a reflector *Rr*
- a sequence of numbers separated by whitespaces to encrypt, ending with the 0 character

## Output:

encrypted sequences of numbers (without the 0 character)

## Wejście:

#### Definicja części maszyny:

- *n*- liczba liter (liczb) w alfabecie
- *m* - liczba wirników, a następnie ich definicje *W0,...,Wm-1*
	- definicja wirnika *Wi* - permutacja alfabetu
	- liczba liter powodujących obroty innych wirników, a następnie te litery, na wzór [tablicy "Position of turnover notches"](https://en.wikipedia.org/wiki/Enigma_machine#Turnover)
- *l* - liczba reflektorów
- definicja a *R0,...,Rl-1* - permutacja alfabetu

#### Zestaw *p* zadań do wykonania:

każde zadanie ma 2 części: ustawienie maszyny i wiadomość do zaszyfrowania.

- *p* liczba zadań
- *k* - liczba wirników w maszynie
- *k* par *K0,...,Kk-1* - gdzie *Ki=(j, t)*, *j* to indeks kopii rotora *Wj* i *t* to jego początkowa pozycja
	- wirniki podane są od najszybszego do najwolniejszego
	- początkowa pozycja - wirnik ustawiony jest tak jakby był wcześniej obrócony (nie trzeba wykonywać faktycznych obrotów), np. 1 - wirnik ustawiony jest jak w permutacji, 2 - jest przesunięty o jedną pozycję, etc.
- *r* indeks reflektora *Rr*
- sekwencja liczb oddzielona białymi znakami zakończona symbolem 0

## Wyjście:

zaszyfrowane sekwencje liczb (bez 0 na końcu)

## Exmple of input:
 

4
4
1 2 4 3
1 2  
3 2 1 4 
0
4 3 1 2
0
3 2 1 4
0
3
2 1 4 3
4 3 2 1
1 2 4 3

6
1 0 4 2
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0
1 0 4 0
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0
1 0 4 1
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0 
1 2 4 0
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0
1 3 4 0
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0
2 0 4 0 1 0
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 0


#### Output:
 
1 1 1 3 2 4 2 2 4 3 4 1 3 2 3 4
2 3 2 3 1 4 1 4 4 1 4 1 3 2 3 2
3 4 3 4 4 3 4 3 1 2 1 2 2 1 2 1
2 3 2 3 1 4 1 4 4 1 4 1 3 2 3 2
4 4 4 4 3 3 3 3 2 2 2 2 1 1 1 1
2 2 4 2 3 4 1 4 4 4 2 4 1 2 3 2 2 2 4 2 3 4 1 4 4 4 2 4 1 2 3 2 
