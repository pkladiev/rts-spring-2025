# Задание №2

## Задача
Hеализовать прием/передачу между двумя платами Arduino, позволяющий в консоли увидеть мат.ожидание и среднеквадратичное отклонение длины импульсов за определенное период(рассчитываем метрики например для 100 подряд импульсов).

## Результаты

| Длительность | Uno R3 (digitalWrite) | Uno R3 (оптимиз.) | Uno R4 | 
|:------------:| :------------: | :------------: | :------------: |
|10 мс| ![10 мс](../R3_10000.png) | ![10 мс](../R3_10000_opt.png) | ![10 мс](../R4_10000.png) |
|1 мс| ![1 мс](../R3_1000.png) | ![1 мс](../R3_1000_opt.png) | ![1 мс](../R4_1000.png) |
|500 мкс| ![500 мкс](../R3_500.png) | ![500 мкс](../R3_500_opt.png) | ![500 мкс](../R4_500.png) |
|100 мкс| ![100 мкс](../R3_100.png) | ![100 мкс](../R3_100_opt.png) | ![100 мкс](../R4_100.png) |
|50 мкс| ![50 мкс](../R3_50.png) | ![50 мкс](../R3_50_opt.png) | ![50 мкс](../R4_50.png) |