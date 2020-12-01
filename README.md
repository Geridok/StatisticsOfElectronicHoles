# StatisticsOfElectronicHoles

Полезные ссылки:

Статистика электронов в полупроводниках: https://scask.ru/e_book_tpi.php?id=18

Параметры кремния для ввода в модель: http://www.ioffe.ru/SVA/NSM/Semicond/Si/electric.html#Basic
1) E_d - положение уровня донора (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
2) E_g - ширина запрещённой зоны (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
3) E_c - дно зоны проводимости   (от 1.0f * 1.60e-19 до 10.0f * 1.60e-19)
4) m - эффективная масса носителей заряда (от 1.0e-31 до 10.0e-31)
5) N_d0 - концентрация доноров (от 1e15 до 1e22)
6) T_0 - начальная температура (0 до 100)
7) T_1 - конечная температура (T_0 до 100)

TODO: solve main equation: F = E_g - E_d - k*T * ln(N_d0/n(F) - 1) (Vectozavr)

TODO: Программа переводит все в единицы СГС (или в СИ по желанию) (Vectozavr)

TODO: GUI (Geridok)


Теоретические наработки:

![Project demonstration](img/theory.jpg)

Задача:

![Project demonstration](img/problem.jpg)
