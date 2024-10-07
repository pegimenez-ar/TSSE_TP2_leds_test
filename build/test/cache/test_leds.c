#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/leds.h"
static uint16_t puerto_virtual;





void setUp(void){



    LedsCreate(&puerto_virtual);



}





void tearDown(void){

}





void test_todos_los_leds_inician_apagados(void){

    uint16_t puerto_virtual = 0xFFFF;



    LedsCreate(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_un_led_individual(void){



    do {if ((LedsSetOn(3))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(52)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 2)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_un_led_individual(void){



    do {if ((LedsSetOn(3))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(59)));}} while(0);

    do {if ((LedsSetOff(3))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(60)));}} while(0);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_varios_leds(void){



    do {if ((LedsSetOn(5))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(68)));}} while(0);

    do {if ((LedsSetOff(2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));}} while(0);

    do {if ((LedsSetOn(7))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(70)));}} while(0);

    do {if ((LedsSetOff(7))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(71)));}} while(0);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todos_LEDs(void){



    LedsSetAllOn();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX16);

}





void test_perder_todos_LEDs(void){



    LedsSetAllOff();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_HEX16);

}





 void test_consultar_estado_encendido(void){



    do {if ((LedsSetOn(9))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(95)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((IsLedOn(9))), (

   ((void *)0)

   ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

 }





 void test_consultar_estado_apagado(void){



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((IsLedOn(9))), (

   ((void *)0)

   ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);

 }





void test_verificar_limites_parametros(void){



    do {if ((LedsSetOn(1))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(108)));}} while(0);

    do {if ((LedsSetOn(16))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(109)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 0 | 1 << 15)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_HEX16);

}





void test_verificar_parametros_fuera_limites(void){



    do {if (!(LedsSetOn(0))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(116)));}} while(0);

    do {if (!(LedsSetOn(17))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(117)));}} while(0);

    do {if (!(LedsSetOn(-100))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(118)));}} while(0);



    do {if (!(LedsSetOff(0))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(120)));}} while(0);

    do {if (!(LedsSetOff(17))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(121)));}} while(0);

    do {if (!(LedsSetOff(-100))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(122)));}} while(0);



    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((IsLedOn(19))), (

   ((void *)0)

   ), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

}





void test_verificar_puntero_nulo(void){

    uint16_t *puntero_nulo = 

                            ((void *)0)

                                ;



    do {if (!(LedsCreate(puntero_nulo))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(131)));}} while(0);

}
