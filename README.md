Zadaniem poniższej aplikacji jest wykonanie czterech typów sortowania. Użytkownik po uruchomieniu programu jest proszony o manualne wprowadzenie liczb, które dodawane są do konteneru, który dynamicznie zwiększa tablicę. Oznacza to, że użytkownik do sortowania może dodać tyle liczb ile chcę. 

Użytkownik przy prośbie o podanie pierwszej liczby może wcisnąć 0 aby otworzyć plik liczby.txt znajdujący się w tym samym folderze roboczym co program aby załadować liczby z pliku. Używana jest do tego biblioteka fstream Jeśli przy pierwszej liczbie poda coś innego niż 0, ta liczba zostanie wpisana do pamięci. 
Jeśli przy wpisywaniu drugiej i kolejnej liczby lub po załadowaniu liczb z pliku liczby.txt użytkownik wpisze 0 to zakończy to proces wpisywania liczb.
Użytkownik potem zostaje zapytany o wybranie metody sortowania.

Poniższe metody są dostępne:
•	Sortowanie bąbelkowe,
•	Sortowanie przez wybór,
•	Sortowanie przez wstawianie,
•	Sortowanie szybkie.

Jeżeli użytkownik poda niewłaściwą liczbę to program kończy swoje działanie z kodem wyjścia 1.

Po wybraniu metody sortowania program przechodzi do wybranej klasy. Używana jest biblioteka chrono w celu umożliwienia pomiaru czasu procesora potrzebnego aby ukończyć sortowanie. Na mojej konfiguracji sprzętowej sortowanie 10,000 liczb z użyciem sortowania bąbelkowego zajmuje około 543ms.
