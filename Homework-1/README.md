# Задача: МultiSet
Напишете клас МultiSet, който съдържа мултимножество от числа в диапазона от 0 до n, където n е подадено в конструктора. В конструктора се подават 2 числа: n (най-голямото число в множеството) и k - колко най-много бита са необходими за запазването на броя срещания на едно число (1 <= k <= 8). 
Това означава, че всяко число може да се среща в множеството най-много 2^k-1  пъти.

**!!!** Класът ви трябва да е **максимално оптимален откъм памет.**

Трябва да поддържате следните функционалности:

- Добавяне на число

- Проверка колко пъти се съдържа число

- Принтиране на всички числа, които се съдържат в мултимножеството

- Принтиране на това как мултимножеството е представено в паметта

- Сериализация/десериализация в/от двоичен файл

- Сечение/Разлика на две мултимножества

- Допълнение на мултимножество  (ако x се е срещал p пъти, то в допълнението се среща 2^k - 1 - p пъти)
