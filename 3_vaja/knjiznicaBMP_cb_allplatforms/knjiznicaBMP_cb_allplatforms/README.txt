Knji�nica za pretvorbo 2D arraya v BMP datoteko (slika). 
Deluje na platformah Windows, Linux, Mac.

CodeBlocks:
1. Knji�nico bitmap.c in header datoteko bitmap.h skopiraj v mapo svojega projekta. 
2. bitmap.cpp vklju�i v svoj projekt. (desni klik na ime projekta -> Add files -> izberete datoteke -> Open files -> v oknu Multiple Decision izberete OK)
3. Na vrhu svojega projekta to knji�nico tudi vklju�i z vrstico #include "bitmap.h"
4. Uporabljaj funkcijo na na�in:

shraniBMP(ime_dvodimenzionalnega_arraya_s_podatki_tipa_unsigned_char, DIMx, DIMy, "imeslike.bmp");

Datoteka .bmp se shrani v mapo projekta. �e je ni, poglejte �e pod mapo Debug.