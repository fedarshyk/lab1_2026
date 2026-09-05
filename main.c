#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    // Проверяем, что переданы все 7 необходимых аргументов (плюс имя самой программы)
    if (argc != 8) {
        printf("Использование: %s <distance_km> <duration_minutes> <battery_capacity_kwh> "
               "<start_charge_percent> <finish_charge_percent> <tariff_byn_per_kwh> <passengers>\n", argv[0]);
        return 1;
    }

    // Считываем и конвертируем аргументы командной строки
    double distance_km = atof(argv[1]);
    double duration_minutes = atof(argv[2]);
    double battery_capacity_kwh = atof(argv[3]);
    double start_charge_percent = atof(argv[4]);
    double finish_charge_percent = atof(argv[5]);
    double tariff_byn_per_kwh = atof(argv[6]);
    int passengers = atoi(argv[7]);

    // Защита от деления на ноль
    if (duration_minutes <= 0 || distance_km <= 0 || passengers <= 0) {
        printf("Ошибка: Длительность, дистанция и количество пассажиров должны быть больше 0.\n");
        return 1;
    }

    // Расчеты
    double time_hours = duration_minutes / 60.0;
    double energy_used_kwh = battery_capacity_kwh * (start_charge_percent - finish_charge_percent) / 100.0;
    double average_speed_kmh = distance_km / time_hours;
    double consumption_kwh_per_100km = (energy_used_kwh / distance_km) * 100.0;
    double trip_cost_byn = energy_used_kwh * tariff_byn_per_kwh;
    double cost_per_passenger_byn = trip_cost_byn / passengers;

    // Вывод результатов
    printf("Energy used: %.2f kWh\n", energy_used_kwh);
    printf("Average speed: %.2f km/h\n", average_speed_kmh);
    printf("Consumption: %.2f kWh/100 km\n", consumption_kwh_per_100km);
    printf("Trip cost: %.2f BYN\n", trip_cost_byn);
    printf("Cost per passenger: %.2f BYN\n", cost_per_passenger_byn);

    return 0;
}