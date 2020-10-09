# pandemic-simulator

- dodac parametry main
- dodac zapamietywanie liczby zakazonych w kolejnych iteracjach - list<int> + pushBack() bedzie legitne
- wydzielic klasy odpowiedzialne za rysowanie po konsoli
- wydzielic jakos ladnie do metod/klas te petle z maina
- chyba cos sie zepsulo i nie bylo slychac, ale trzeba ogarnac te warunki - chory 7 iteracji - zdrowy 4 iteracje - cos nie pykło


- optymalizacja czasowa bo ta ssie
	- dodac do klasy Person liste sasiadow tj. wyliczyc sasiadow (1 raz) przed nieskonczonym while - to mocno skroci czas obslugi tych petli w main
	- klasa Person musi wystawic metode, ktora zwroci sasiadow do zarazenia - wszystko co do tego potrzebne jest juz zaimplementowane

- w zaleznosci od wymagan trzeba bedzie cos dodac 
	- jezeli chodzi o jakies magiczne dziedziczenie to jest to slaby projekt na ten case, ale w ostatecznosci da sie to lekko przerobic
	- jezeli chodzi o wiecej klas no to juz trzeba bedzie pokminic nad struktura projektu