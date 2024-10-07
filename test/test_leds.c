#include "leds.h"
#include "unity.h"

/** @todo
 * Prender todos los LEDs de una vez.
 * Apagar todos los LEDs de una vez.
 * Consultar el estado de un LED que está encendido.
 * Consultar el estado de un LED que esta apagado.
 * Revisar limites de los parametros.
 * Revisar parámetros fuera de los limites.
 */

static uint16_t puerto_virtual;

// Se ejecutan antes de cada prueba
void setUp(void){
    
    LedsCreate(&puerto_virtual);

}

// Se ejecutan luego de cada prueba
void tearDown(void){
}

// Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void){
    uint16_t puerto_virtual = 0xFFFF;

    LedsCreate(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prender un LED individual.
void test_prender_un_led_individual(void){

    LedsSetOn(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// Apagar un LED individual.
void test_prender_y_apagar_un_led_individual(void){

    LedsSetOn(3);
    LedsSetOff(3);

    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prender y apagar multiples LEDs.
void test_prender_y_apagar_varios_leds(void){

    LedsSetOn(5);
    LedsSetOff(2);
    LedsSetOn(7);
    LedsSetOff(7);

    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}