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

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_un_led_individual(void){



    LedsSetOn(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 2)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_un_led_individual(void){



    LedsSetOn(3);

    LedsSetOff(3);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_varios_leds(void){



    LedsSetOn(5);

    LedsSetOff(2);

    LedsSetOn(7);

    LedsSetOff(7);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);

}
