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

Twoim zadaniem jest zaimplementowanie wariantu [maszyny Enigma](https://en.wikipedia.org/wiki/Enigma_machine) kt??ra koduje wiadomo??ci w alfabecie sk??adaj??cym si?? z *n* liter oznaczonych numerami *{1,2,...,n}*. Symbol *0* ko??czy wiadomo????.

Wirniki *Wx={wx, 0, wx, 1,...,wx, n}* i reflektory *Ry={ry, 0, ry, 1,...,ry, n}* podane s?? jako permutacje *{1,2,...,n}* i symuluj?? [mechaniczne cz????ci](https://en.wikipedia.org/wiki/Enigma_rotor_details) kt??re mo??e u??ywa?? operator. Wewn??trzne "okablowanie" tych cz????ci nie ulega zmianom.

Podanie na wej??cie litery szyfruje j?? poprzez przes??anie jej przez wirniki do reflektora i z powrotem przez wirniki w odwrotnej kolejno??ci, jak zobaczy?? mo??na [tutaj](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6c/Enigma-action.svg/600px-Enigma-action.svg.png). Nieruchoma sekwencja wirnik??w i reflektora reprezentuje prosty szyfr podstawieniowy, to dzi??ki ich ruchomo??ci odszyfrowanie wiadomo??ci stanowi wyzwanie.

Ka??dy wirnik rusza si?? co najwy??ej o jedn?? pozycj?? w kierunku przeciwnym do ruchu wskaz??wek zegara przy ka??dym kodowaniu. Pierwszy wirnik rusza si?? przed ka??dym kodowaniem; dlatego je??li pocz??tkowa pozycja tego wirnika podana jest przy pomocy ostatniej litery alfabetu (tak jak w przyk??adzie) pierwsza litera kodowana jest przez podstawienie takie jak podano w definicji wirnika. Pozosta??e wirniki obracaj?? si?? wg. zasad podanych w sekcji "Turnover notch positions" tego [linku](https://en.wikipedia.org/wiki/Enigma_machine#Turnover) i [tej sekcji](https://en.wikipedia.org/wiki/Enigma_machine#Turnover). Dodatkowe informacje o podw??jnym kroku ("double stepping") mo??na znale???? [tutaj](http://www.intelligenia.org/downloads/rotors1.pdf).

W przypadku gdy w maszynie s?? wi??cej ni?? 3 wirniki tylko pierwsze 3 si?? obracaj??.

O wej??ciu mo??na my??le?? jako podzielonym na dwie cz????ci: definicje element??w maszyny i *p* instrukcji jak zakodowa?? dan?? wiadomo???? u??ywaj??c tych cz????ci tych element??w. Przed zakodowaniem wiadomo??ci maszyna jest z??o??ona z *k* z *m* wirnik??w i jednego reflektora (z *l*) i wirniki ustawione s?? na podanych pocz??tkowych pozycjach (wi??cej informacji w sekcji o wej??ciu).

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

## Wej??cie:

#### Definicja cz????ci maszyny:

- *n*- liczba liter (liczb) w alfabecie
- *m* - liczba wirnik??w, a nast??pnie ich definicje *W0,...,Wm-1*
	- definicja wirnika *Wi* - permutacja alfabetu
	- liczba liter powoduj??cych obroty innych wirnik??w, a nast??pnie te litery, na wz??r [tablicy "Position of turnover notches"](https://en.wikipedia.org/wiki/Enigma_machine#Turnover)
- *l* - liczba reflektor??w
- definicja a *R0,...,Rl-1* - permutacja alfabetu

#### Zestaw *p* zada?? do wykonania:

ka??de zadanie ma 2 cz????ci: ustawienie maszyny i wiadomo???? do zaszyfrowania.

- *p* liczba zada??
- *k* - liczba wirnik??w w maszynie
- *k* par *K0,...,Kk-1* - gdzie *Ki=(j, t)*, *j* to indeks kopii rotora *Wj* i *t* to jego pocz??tkowa pozycja
	- wirniki podane s?? od najszybszego do najwolniejszego
	- pocz??tkowa pozycja - wirnik ustawiony jest tak jakby by?? wcze??niej obr??cony (nie trzeba wykonywa?? faktycznych obrot??w), np. 1 - wirnik ustawiony jest jak w permutacji, 2 - jest przesuni??ty o jedn?? pozycj??, etc.
- *r* indeks reflektora *Rr*
- sekwencja liczb oddzielona bia??ymi znakami zako??czona symbolem 0

## Wyj??cie:

zaszyfrowane sekwencje liczb (bez 0 na ko??cu)

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
